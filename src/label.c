/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The label.c
*/

#include "../include/myrobot.h"

int add_label(robot_t *robot, char *name, int address)
{
    label_t *new_label;

    for (label_t *tmp = robot->labels; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(tmp->name, name) == 0)
            return 84;
    }
    new_label = my_malloc(sizeof(label_t), 1);
    new_label->name = my_malloc_strdup(name);
    new_label->address = address;
    new_label->next = robot->labels;
    robot->labels = new_label;
    return 0;
}

void add_found_label(robot_t *robot, char *name)
{
    found_label_t *new_label;

    for (label_t *tmp = robot->labels; tmp != NULL; tmp = tmp->next) {
        if (my_strcmp(tmp->name, name) == 0)
            return;
    }
    new_label = my_malloc(sizeof(found_label_t), 1);
    new_label->name = my_malloc_strdup(name);
    new_label->next = robot->found_labels;
    robot->found_labels = new_label;
}

int check_valid_label(char *str)
{
    int index = 0;
    int find_letter = 0;

    for (index = 0; str[index] != '\0'; index++) {
        if (str[index] >= 'a' && str[index] <= 'z' ||
        str[index] >= '0' && str[index] <= '9' || str[index] == '_') {
            find_letter = 1;
            continue;
        }
        if (str[index] == ':')
            continue;
        if (str[index] == '#' || !check_not_separator(str[index]))
            return index;
        return -1;
    }
    if (find_letter == 0)
        return -1;
    return index;
}

int find_label(robot_t *robot, char *line, char add)
{
    int len = check_valid_label(line);
    char *name;

    if (len <= 0)
        return -1;
    if (line[len - 1] != ':')
        return 0;
    if (add == 0)
        return len;
    name = my_calloc(len, sizeof(char), 1);
    for (int index = 0; index < len - 1; index++)
        name[index] = line[index];
    if (add_label(robot, name, robot->header->prog_size) == 84)
        return -1;
    return len;
}

static int compare_label_name(robot_t *robot, char *name)
{
    for (label_t *label = robot->labels; label != NULL; label = label->next) {
        if (my_strcmp(label->name, name) == 0) {
            return 0;
        }
    }
    return 1;
}

int compare_label(robot_t *robot)
{
    for (found_label_t *tmp = robot->found_labels; tmp != NULL;
    tmp = tmp->next) {
        if (compare_label_name(robot, tmp->name))
            return 84;
    }
    return 0;
}
