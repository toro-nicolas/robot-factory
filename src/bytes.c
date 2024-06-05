/*
** EPITECH PROJECT, 2024
** robotfactory
** File description:
** The bytes.c
*/

#include "../include/myrobot.h"

uint swap_uint32(uint number)
{
    return ((number & 0xFF000000) >> 24) | ((number & 0x00FF0000) >> 8) |
    ((number & 0x0000FF00) << 8) | ((number & 0x000000FF) << 24);
}

signed short swap_uint16(signed short number)
{
    return ((number & 0xFF00) >> 8) | ((number & 0x00FF) << 8);
}

unsigned char get_coding_byte(unsigned char arg1, unsigned char arg2,
    unsigned char arg3, unsigned char arg4)
{
    unsigned char coding_byte = 0;

    if (arg1 == DIR_IND_CODE)
        arg1 = DIR_CODE;
    if (arg2 == DIR_IND_CODE)
        arg2 = DIR_CODE;
    if (arg3 == DIR_IND_CODE)
        arg3 = DIR_CODE;
    if (arg4 == DIR_IND_CODE)
        arg4 = DIR_CODE;
    coding_byte = (arg1 << 6) | (arg2 << 4) | (arg3 << 2) | arg4;
    return coding_byte;
}

unsigned char get_size(unsigned char arg)
{
    if (arg == REG_CODE)
        return REG_SIZE;
    if (arg == DIR_CODE)
        return DIR_SIZE;
    if (arg == IND_CODE)
        return IND_SIZE;
    if (arg == DIR_IND_CODE)
        return IND_SIZE;
    return 0;
}
