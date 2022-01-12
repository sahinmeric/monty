#include "monty.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 * Return: EXIT_SUCCESS if no errors are passed
 * EXIT_FAIlURE otherwise
 */
int main(int argc, char **argv)
{
    /*TODO: check if the argc == 2*/
    if (argc != 2)
    {
        dprintf(2, "USAGE: monty file\n");
        exit (EXIT_FAILURE);
    }
}