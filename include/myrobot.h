/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The myrobot.h
*/

#include "mymemory.h"
#include "myop.h"

#ifndef MYROBOT_H_
    #define MYROBOT_H_

typedef struct found_label_s {
    char *name;
    struct found_label_s *next;
} found_label_t;

typedef struct label_s {
    char *name;
    int address;
    struct label_s *next;
} label_t;

typedef struct robot_s {
    char *input;
    FILE *output;
    char *content;
    char **lines;
    header_t *header;
    int bytes_index;
    label_t *labels;
    found_label_t *found_labels;
} robot_t;

extern int (*instruction_check[16])(robot_t *robot, char *line, int index);
extern int (*instruction_write[16])(robot_t *robot, char *line, int index);

/* Swap little endian to big endian */
uint swap_uint32(uint number);
signed short swap_uint16(signed short number);

/* Coding bytes */
unsigned char get_coding_byte(unsigned char arg1, unsigned char arg2,
    unsigned char arg3, unsigned char arg4);
unsigned char get_size(unsigned char arg);

/* Files */
char *get_file_name(char *path);
FILE *get_output_file(char *path);

/* Checker instructions */
int check_add(robot_t *robot, char *line, int index);
int check_aff(robot_t *robot, char *line, int index);
int check_and(robot_t *robot, char *line, int index);
int check_fork(robot_t *robot, char *line, int index);
int check_ld(robot_t *robot, char *line, int index);
int check_ldi(robot_t *robot, char *line, int index);
int check_lfork(robot_t *robot, char *line, int index);
int check_live(robot_t *robot, char *line, int index);
int check_lld(robot_t *robot, char *line, int index);
int check_lldi(robot_t *robot, char *line, int index);
int check_or(robot_t *robot, char *line, int index);
int check_st(robot_t *robot, char *line, int index);
int check_sti(robot_t *robot, char *line, int index);
int check_sub(robot_t *robot, char *line, int index);
int check_xor(robot_t *robot, char *line, int index);
int check_zjmp(robot_t *robot, char *line, int index);

/* Checker */
int find_instruction(char *line);
int check_not_separator(char c);
int check_end_of_line(const char *line, int index);
int check_register(char *str);
int check_direct(robot_t *robot, char *str);
int check_indirect(robot_t *robot, char *str);

/* Get / Set arguments */
char get_register(char *str);
int get_direct(robot_t *robot, char *str);
short int get_indirect(robot_t *robot, char *str);
void set_register(char *line, int **variables, int **content);
void set_direct(robot_t *robot, char *line, int **variables, int **content);
void set_direct_indirect(robot_t *robot, char *line,
    int **variables, int **content);
void set_indirect(robot_t *robot, char *line, int **variables, int **content);

/* Write instructions */
int write_add(robot_t *robot, char *line, int index);
int write_aff(robot_t *robot, char *line, int index);
int write_and(robot_t *robot, char *line, int index);
int write_fork(robot_t *robot, char *line, int index);
int write_ld(robot_t *robot, char *line, int index);
int write_ldi(robot_t *robot, char *line, int index);
int write_lfork(robot_t *robot, char *line, int index);
int write_live(robot_t *robot, char *line, int index);
int write_lld(robot_t *robot, char *line, int index);
int write_lldi(robot_t *robot, char *line, int index);
int write_or(robot_t *robot, char *line, int index);
int write_st(robot_t *robot, char *line, int index);
int write_sti(robot_t *robot, char *line, int index);
int write_sub(robot_t *robot, char *line, int index);
int write_xor(robot_t *robot, char *line, int index);
int write_zjmp(robot_t *robot, char *line, int index);

/* Labels */
int add_label(robot_t *robot, char *name, int address);
void add_found_label(robot_t *robot, char *name);
int check_valid_label(char *str);
int find_label(robot_t *robot, char *line, char add);
int compare_label(robot_t *robot);

/* Create robot */
int create_robot(char *path);
int check_instruction(robot_t *robot, char *line);
int set_header(robot_t *robot);
int set_body(robot_t *robot);

#endif /* MYROBOT_H_ */
