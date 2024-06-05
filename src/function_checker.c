/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The function_checker.c
*/

#include "../include/myrobot.h"

int check_not_separator(char c)
{
    if (c != ' ' && c != '\t' && c != ',')
        return 1;
    return 0;
}

int check_end_of_line(const char *line, int index)
{
    for (; line[index] != '\0'; index++) {
        if (line[index] == '#')
            return 0;
        if (line[index] != ' ' && line[index] != '\t' && line[index] != ',')
            return 84;
    }
    return 0;
}

int check_register(char *str)
{
    int number;
    int sign = 0;

    if (str[0] != 'r')
        return -1;
    if (str[1] == '+')
        sign = 1;
    number = my_strict_find_nbr(str + 1 + sign);
    if (number == -1 || number > 16)
        return -1;
    return 1 + my_nbrlen(number) + sign;
}

static int my_arg_len(char *str)
{
    int len = 0;
    char **tab = my_str_to_word_array_select(str, " \t,\n\0");

    len = my_strlen(tab[0]);
    my_free_word_array(tab);
    return len;
}

static void set_new_found_label(robot_t *robot, char *line, int size)
{
    char *name = my_calloc(size + 1, sizeof(char), 1);

    for (int index = 0; index < size; index++)
        name[index] = line[index];
    add_found_label(robot, name);
}

int check_direct(robot_t *robot, char *str)
{
    int number;
    int label_status;
    int sign = 0;

    if (str[0] != '%')
        return -1;
    if (str[1] == ':') {
        label_status = check_valid_label(str + 2);
        if (label_status == -1)
            return -1;
        set_new_found_label(robot, str + 2, label_status);
        return 2 + label_status;
    }
    if (str[1] == '-' || str[1] == '+')
        sign = 1;
    number = my_find_nbr(str + 1 + sign);
    if (number == -1)
        return -1;
    return my_arg_len(str);
}

int check_indirect(robot_t *robot, char *str)
{
    int number;
    int label_status;
    int sign = 0;

    if (str[0] == ':') {
        label_status = check_valid_label(str + 1);
        if (label_status == -1)
            return -1;
        set_new_found_label(robot, str + 1, label_status);
        return 1 + label_status;
    }
    if (str[0] == '-' || str[0] == '+')
        sign = 1;
    number = my_find_nbr(str + sign);
    if (number == -1)
        return -1;
    return my_arg_len(str);
}
