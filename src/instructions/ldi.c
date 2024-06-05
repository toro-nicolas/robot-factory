/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The ldi.c
*/

#include "../../include/myrobot.h"

static int check_status(robot_t *robot, char *line, int *index_char, int arg)
{
    int status = check_register(line + *index_char);

    if (status > 0) {
        robot->header->prog_size += REG_SIZE;
        *index_char += status;
        return 1;
    }
    status = check_direct(robot, line + *index_char);
    if (arg != 2 && status > 0) {
        robot->header->prog_size += IND_SIZE;
        *index_char += status;
        return 1;
    }
    status = check_indirect(robot, line + *index_char);
    if (arg == 0 && status > 0) {
        robot->header->prog_size += IND_SIZE;
        *index_char += status;
        return 1;
    }
    return -1;
}

int check_ldi(robot_t *robot, char *line, int index)
{
    int status = 0;
    int index_char = index + 4;
    int nb_arg = 0;

    robot->header->prog_size += INSTRUCTION_ID_SIZE + CODING_BYTE_SIZE;
    for (; line[index_char] != '\0'; index_char++) {
        if (!check_not_separator(line[index_char]))
            continue;
        status = check_status(robot, line, &index_char, nb_arg);
        if (status == -1)
            return 84;
        nb_arg++;
        if (nb_arg == 3)
            break;
    }
    if (nb_arg != 3)
        return 84;
    return check_end_of_line(line, index_char);
}

static int get_values(robot_t *robot, char *line,
    int *index_char, int **content)
{
    static int state = 0;
    int status = check_register(line + *index_char);
    int *variables[3] = {index_char, &state, &status};

    state = (state == 3) ? 0 : state;
    if (status > 0) {
        set_register(line, variables, content);
        return 1;
    }
    status = check_direct(robot, line + *index_char);
    if (state != 2 && status > 0) {
        set_direct_indirect(robot, line, variables, content);
        return 1;
    }
    status = check_indirect(robot, line + *index_char);
    if (state == 0 && status > 0) {
        set_indirect(robot, line, variables, content);
        return 1;
    }
    return -1;
}

int write_ldi(robot_t *robot, char *line, int index)
{
    int index_char = index + 4;
    int values[3] = {0, 0, 0};
    int cb[4] = {0, 0, 0, 0};

    fwrite(&op_tab[9].code, sizeof(char), 1, robot->output);
    for (; line[index_char] != '\0' && cb[2] == 0; index_char++) {
        if (!check_not_separator(line[index_char]))
            continue;
        if (get_values(robot, line, &index_char, (int *[2]){values, cb}) == -1)
            return 84;
    }
    cb[3] = get_coding_byte(cb[0], cb[1], cb[2], cb[3]);
    fwrite(&cb[3], sizeof(char), 1, robot->output);
    fwrite(&values[0], get_size(cb[0]), 1, robot->output);
    fwrite(&values[1], get_size(cb[1]), 1, robot->output);
    fwrite(&values[2], get_size(cb[2]), 1, robot->output);
    robot->bytes_index += 2 + get_size(cb[0]) + get_size(cb[1]) +
        get_size(cb[2]) + get_size(cb[3]);
    return 0;
}
