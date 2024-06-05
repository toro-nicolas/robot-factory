/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The set_instructions.c
*/

#include "../include/myrobot.h"

void set_register(char *line, int **variables, int **content)
{
    content[0][*(variables[1])] = get_register(line + *(variables[0]));
    content[1][*(variables[1])] = REG_CODE;
    *(variables[0]) += *(variables[2]);
    (*(variables[1]))++;
}

void set_direct(robot_t *robot, char *line, int **variables, int **content)
{
    content[0][*(variables[1])] = swap_uint32(
        get_direct(robot, line + *(variables[0])));
    content[1][*(variables[1])] = DIR_CODE;
    *(variables[0]) += *(variables[2]);
    (*(variables[1]))++;
}

void set_direct_indirect(robot_t *robot, char *line,
    int **variables, int **content)
{
    content[0][*(variables[1])] = swap_uint16(
        get_direct(robot, line + *(variables[0])));
    content[1][*(variables[1])] = DIR_IND_CODE;
    *(variables[0]) += *(variables[2]);
    (*(variables[1]))++;
}

void set_indirect(robot_t *robot, char *line, int **variables, int **content)
{
    content[0][*(variables[1])] = swap_uint16(
        get_indirect(robot, line + *(variables[0])));
    content[1][*(variables[1])] = IND_CODE;
    *(variables[0]) += *(variables[2]);
    (*(variables[1]))++;
}
