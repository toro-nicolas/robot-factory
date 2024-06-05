/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The op.c
*/

#include "../include/myrobot.h"

op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
        "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
        "ou (or  r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
        "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
        "load index"},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
        "store index"},
    {"fork", 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
        "long load index"},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 1, {T_REG}, 16, 2, "aff"},
    {0, 0, {0}, 0, 0, 0}
};

int (*instruction_check[16])(robot_t *robot, char *line, int index) = {
    &check_live,
    &check_ld,
    &check_st,
    &check_add,
    &check_sub,
    &check_and,
    &check_or,
    &check_xor,
    &check_zjmp,
    &check_ldi,
    &check_sti,
    &check_fork,
    &check_lld,
    &check_lldi,
    &check_lfork,
    &check_aff
};

int (*instruction_write[16])(robot_t *robot, char *line, int index) = {
    &write_live,
    &write_ld,
    &write_st,
    &write_add,
    &write_sub,
    &write_and,
    &write_or,
    &write_xor,
    &write_zjmp,
    &write_ldi,
    &write_sti,
    &write_fork,
    &write_lld,
    &write_lldi,
    &write_lfork,
    &write_aff
};
