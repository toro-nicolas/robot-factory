/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The header.c
*/

#include "../include/myrobot.h"

int search_name(robot_t *robot, char *line, int index)
{
    if (my_strncmp(line + index, NAME_CMD_STRING, 4) != 0)
        return 84;
    index += 5;
    if (check_not_separator(line[index]))
        return 84;
    for (; line[index] != '"'; index++) {
        if (check_not_separator(line[index]))
            return 84;
    }
    index++;
    for (int char_index = 0; line[index] != '"'; index++) {
        if (line[index] == '\0' || char_index + 1 > PROG_NAME_LENGTH)
            return 84;
        if (line[index] == '"')
            break;
        robot->header->prog_name[char_index] = line[index];
        char_index++;
    }
    robot->header->prog_size = 1;
    return check_end_of_line(line, index + 1);
}

int search_comment(robot_t *robot, char *line, int index)
{
    if (my_strncmp(line + index, COMMENT_CMD_STRING, 7) != 0)
        return 84;
    index += 8;
    if (check_not_separator(line[index]))
        return 84;
    for (; line[index] != '"'; index++) {
        if (check_not_separator(line[index]))
            return 84;
    }
    index++;
    for (int char_index = 0; line[index] != '"'; index++) {
        if (line[index] == '\0' || char_index + 1 > COMMENT_LENGTH)
            return 84;
        if (line[index] == '"')
            break;
        robot->header->comment[char_index] = line[index];
        char_index++;
    }
    robot->header->prog_size = 2;
    return check_end_of_line(line, index + 1);
}

int check_line(robot_t *robot, char *line)
{
    for (int index = 0; line[index] != '\0'; index++) {
        if (line[index] == '#')
            return 0;
        if (robot->header->prog_size == 2)
            return 1;
        if (line[index] == '.' && robot->header->prog_size == 0)
            return search_name(robot, line, index);
        if (line[index] == '.' && robot->header->prog_size != 0)
            return search_comment(robot, line, index);
        if (check_not_separator(line[index]))
            return 84;
    }
    return 0;
}

static int set_name_and_comment(robot_t *robot, int *index)
{
    int status = 0;

    for (; robot->lines[*index] != NULL; (*index)++) {
        status = check_line(robot, robot->lines[*index]);
        if (status == 1)
            break;
        if (status == 84)
            return 84;
    }
    robot->bytes_index = *index;
    return 0;
}

int set_header(robot_t *robot)
{
    int status = 0;
    int index = 0;

    if (set_name_and_comment(robot, &index) == 84)
        return 84;
    robot->header->prog_size = 0;
    for (; robot->lines[index] != NULL; index++) {
        status = check_instruction(robot, robot->lines[index]);
        if (status == 84)
            return 84;
    }
    if (compare_label(robot) == 84)
        return 84;
    robot->output = get_output_file(robot->input);
    if (robot->output == NULL)
        return 84;
    robot->header->prog_size = swap_uint32(robot->header->prog_size);
    fwrite(robot->header, sizeof(header_t), 1, robot->output);
    return 0;
}
