/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The file.c
*/

#include "../include/myrobot.h"

char *get_file_name(char *path)
{
    for (int index = my_strlen(path) - 1; index >= 0; index--)
        if (path[index] == '/')
            return path + index + 1;
    return path;
}

FILE *get_output_file(char *path)
{
    char *file_name = get_file_name(path);
    char *output_path = my_calloc(sizeof(char), my_strlen(file_name) + 5, 1);
    int len = my_strlen(file_name);
    FILE *output;

    if (len < 2 || my_strcmp(file_name + len - 2, ".s") == 0)
        my_strncat(output_path, file_name, len - 2);
    else
        my_strcat(output_path, file_name);
    my_strcat(output_path, ".cor");
    output = fopen(output_path, "w");
    return output;
}
