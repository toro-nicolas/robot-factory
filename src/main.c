/*
** EPITECH PROJECT, 2023
** robotfactory
** File description:
** The main file of the project
*/

#include "../include/myrobot.h"

int show_help(void)
{
    my_printf("USAGE\n\t./asm file_name[.s]\nDESCRIPTION\n");
    my_printf("\tfile_name file in assembly language to be converted into ");
    my_printf("file_name.cor, an executable in the Virtual Machine.\n");
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        my_fprintf(2, "Error: Invalid number of arguments\n");
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0)
        return show_help();
    else
        return create_robot(argv[1]);
}
