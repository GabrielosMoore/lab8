#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

/**
 * @file util.h
 * @brief Utility functions for memory management simulation.
 */

/**
 * @brief Parses the input file and populates the allocation and deallocation commands.
 *
 * This function reads the input file line by line. It extracts the initial
 * partition size from lines starting with `--` and populates the allocation
 * and deallocation commands from the subsequent lines.
 *
 * @param fp     Pointer to the input file.
 * @param input  2D array to store PID and blocksize pairs.
 * @param n      Pointer to an integer to store the number of commands.
 * @param size   Pointer to an integer to store the initial partition size.
 *
 * @example
 * ```c
 * FILE *file = fopen("input.txt", "r");
 * int commands[200][2];
 * int num_commands = 0;
 * int partition_size = 0;
 * parse_file(file, commands, &num_commands, &partition_size);
 * fclose(file);
 * ```
 */
void parse_file(FILE *fp, int input[][2], int *n, int *size);

#endif // UTIL_H
