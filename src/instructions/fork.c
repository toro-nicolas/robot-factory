/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The fork.c
*/

#include "../../include/myrobot.h"

static int check_status(robot_t *robot, char *line, int *index_char)
{
    int status = check_direct(robot, line + *index_char);

    if (status > 0) {
        robot->header->prog_size += IND_SIZE;
        *index_char += status;
        return 1;
    }
    return -1;
}

int check_fork(robot_t *robot, char *line, int index)
{
    int status = 0;
    int index_char = index + 5;
    int nb_arg = 0;

    robot->header->prog_size += INSTRUCTION_ID_SIZE;
    for (; line[index_char] != '\0'; index_char++) {
        if (!check_not_separator(line[index_char]))
            continue;
        status = check_status(robot, line, &index_char);
        if (status == -1)
            return 84;
        nb_arg++;
        if (nb_arg == 1)
            break;
    }
    if (nb_arg != 1)
        return 84;
    return check_end_of_line(line, index_char);
}

int write_fork(robot_t *robot, char *line, int index)
{
    int index_char = index + 5;
    short int value = 0;

    fwrite(&op_tab[11].code, sizeof(char), 1, robot->output);
    for (; line[index_char] != '\0'; index_char++) {
        if (!check_not_separator(line[index_char]))
            continue;
        value = swap_uint16(get_direct(robot, line + index_char));
        fwrite(&value, sizeof(short int), 1, robot->output);
        break;
    }
    robot->bytes_index += 3;
    return 0;
}
