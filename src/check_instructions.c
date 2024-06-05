/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The check_instructions.c
*/

#include "../include/myrobot.h"

int find_instruction(char *line)
{
    for (int index = 0; index < 16; index++) {
        if (my_strncmp(line, op_tab[index].mnemonique,
        my_strlen(op_tab[index].mnemonique) - 1) == 0 &&
        (line[my_strlen(op_tab[index].mnemonique)] == ' ' ||
        line[my_strlen(op_tab[index].mnemonique)] == '\t' ||
        line[my_strlen(op_tab[index].mnemonique)] == ','))
            return index;
    }
    return -1;
}

int check_instruction(robot_t *robot, char *line)
{
    int instruction = -1;

    for (int index = 0; line[index] != '\0'; index++) {
        if (line[index] == '#')
            return 0;
        if (check_not_separator(line[index]) == 0)
            continue;
        instruction = find_label(robot, line + index, 1);
        if (instruction == -1)
            return 84;
        index += instruction;
        if (instruction != 0)
            continue;
        instruction = find_instruction(line + index);
        if (instruction != -1)
            return instruction_check[instruction](robot, line, index);
        return 84;
    }
    return 0;
}
