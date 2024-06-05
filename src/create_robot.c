/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The create_robot.c
*/

#include "../include/myrobot.h"

static void set_robot(robot_t *robot, char *path, char *content)
{
    header_t *header = my_malloc(sizeof(header_t), 1);

    robot->input = path;
    robot->output = NULL;
    robot->content = content;
    robot->lines = my_str_to_word_array_select(content, "\n");
    robot->header = header;
    robot->header->magic = swap_uint32(COREWAR_EXEC_MAGIC);
    my_memset(robot->header->prog_name, 0, PROG_NAME_LENGTH + 1);
    my_memset(robot->header->comment, 0, COMMENT_LENGTH + 1);
    robot->header->prog_size = 0;
    robot->bytes_index = 0;
    robot->labels = NULL;
    robot->found_labels = NULL;
}

static robot_t *init_robot(char *path)
{
    FILE *file = fopen(path, "r");
    struct stat file_info;
    char *content;
    robot_t *robot = my_malloc(sizeof(robot_t), 1);

    if (file == NULL || stat(path, &file_info) == -1 || file_info.st_size == 0)
        return NULL;
    content = my_calloc(sizeof(char), (file_info.st_size + 1), 1);
    if (fread(content, sizeof(char), file_info.st_size, file)
    != (size_t)file_info.st_size)
        return NULL;
    content[file_info.st_size] = '\0';
    set_robot(robot, path, content);
    fclose(file);
    return robot;
}

void delete_robot(robot_t *robot)
{
    if (robot != NULL) {
        if (robot->output != NULL)
            fclose(robot->output);
        if (robot->lines != NULL)
            my_free_word_array(robot->lines);
    }
    my_free();
}

int print_label(robot_t *robot)
{
    for (label_t *label = robot->labels; label != NULL; label = label->next) {
        my_printf("%s:%d\n", label->name, label->address);
    }
    return 0;
}

int create_robot(char *path)
{
    robot_t *robot = init_robot(path);

    if (robot == NULL || robot->lines == NULL) {
        if (errno == 0)
            my_fprintf(2, "Error: Can't read file\n");
        else
            my_fprintf(2, "Error: %s\n", my_strerror(errno));
        delete_robot(robot);
        return 84;
    }
    if (set_header(robot) == 84 || set_body(robot) == 84) {
        my_fprintf(2, "Error: Invalid instruction.\n");
        delete_robot(robot);
        return 84;
    }
    delete_robot(robot);
    return 0;
}
