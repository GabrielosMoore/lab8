// util/util.c

#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Parses the input file and populates the allocation/deallocation commands.
 * 
 * Parameters:
 * - fp: File pointer to the input file.
 * - input: 2D array to store PID and blocksize pairs.
 * - n: Pointer to an integer to store the number of commands.
 * - size: Pointer to an integer to store the initial partition size.
 */
void parse_file(FILE *fp, int input[][2], int *n, int *size) {
    char line[256];
    *n = 0;
    *size = 0;

    while (fgets(line, sizeof(line), fp)) {
        // Trim leading whitespace
        char *ptr = line;
        while (isspace(*ptr)) ptr++;

        // Skip empty lines
        if (*ptr == '\0' || *ptr == '\n') {
            continue;
        }

        // Check if the line is a comment
        if (strncmp(ptr, "--", 2) == 0) {
            // Attempt to read the partition size
            if (sscanf(ptr + 2, "%d", size) != 1) {
                fprintf(stderr, "Error: Invalid partition size in input file.\n");
                exit(1);
            }
            continue;
        }

        // Parse PID and blocksize
        int pid, blocksize;
        if (sscanf(ptr, "%d %d", &pid, &blocksize) == 2) {
            input[*n][0] = pid;
            input[*n][1] = blocksize;
            (*n)++;
        } else {
            fprintf(stderr, "Warning: Invalid line format skipped: %s", line);
        }
    }
}
