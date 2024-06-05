/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The body.c
*/

#include "../include/myrobot.h"

char get_register(char *str)
{
    return my_super_number(str + 1, (number_settings_t){0, 0, 1, 1});
}

static int get_label_address(robot_t *robot, char *line, int len)
{
    for (label_t *label = robot->labels; label != NULL; label = label->next) {
        if (my_strncmp(label->name, line, len - 1) == 0
        && label->name[len] == '\0')
            return label->address;
    }
    return 0;
}

int get_direct(robot_t *robot, char *str)
{
    int label_status;

    if (str[1] == ':') {
        label_status = check_valid_label(str + 2);
        return get_label_address(robot, str + 2, label_status) -
            robot->bytes_index;
    }
    return my_super_number(str + 1, (number_settings_t){0, 0, 1, 1});
}

short int get_indirect(robot_t *robot, char *str)
{
    int label_status;

    if (str[0] == ':') {
        label_status = check_valid_label(str + 1);
        return get_label_address(robot, str + 1, label_status) -
            robot->bytes_index;
    }
    return my_super_number(str, (number_settings_t){0, 0, 1, 1});
}

int write_instruction(robot_t *robot, char *line)
{
    int instruction = -1;

    for (int index = 0; line[index] != '\0'; index++) {
        if (line[index] == '#')
            return 0;
        if (check_not_separator(line[index]) == 0)
            continue;
        instruction = find_label(robot, line + index, 0);
        if (instruction == -1)
            return 84;
        index += instruction;
        if (instruction != 0)
            continue;
        instruction = find_instruction(line + index);
        if (instruction != -1)
            return instruction_write[instruction](robot, line, index);
        return 84;
    }
    return 0;
}

int set_body(robot_t *robot)
{
    int status = 0;
    int index = robot->bytes_index;

    robot->bytes_index = 0;
    for (; robot->lines[index] != NULL; index++) {
        status = write_instruction(robot, robot->lines[index]);
        if (status == 84)
            return 84;
    }
    return 0;
}
