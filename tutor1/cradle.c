/**
 * @file        cradle.c
 * @brief       Utility functions for the Cradle program
 * @date        November 13, 2025   
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cradle.h"

/**
 * Get a character from the input stream
 */
void get_char(void)
{
    look = getchar();
}

/**
 * Report an error
 */
void report_error(const char *message)
{
    printf("ERROR: %s\n", message);
}

/**
 * Report an abort and exit the program
 */
void report_abort(const char *message)
{
    printf("ABORT: %s\n", message);
    exit(1);
}

/**
 * Report an expected character
 */
void report_expected(const char *message)
{
    printf("EXPECTED: %s\n", message);
    exit(1);
}

/**
 * Match a character
 */
void match_char(char c)
{
    if (look != c) {
        report_expected(c);
    }
    // Otherwise, get the next character
    get_char();
}

/**
 * Check if a character is an alpha character
 */
void is_alpha_char(char c)
{
    if (!isalpha(c)) {
        report_error("Alpha character expected");
    }
    printf("Alpha character matched: %c\n", c);
}

/**
 * Check if a character is a digit character
 */
void is_digit_char(char c)
{
    if (!isdigit(c)) {
        report_error("Digit character expected");
    }
    printf("Digit character matched: %c\n", c);
}

/**
 * Get a name
 */
char get_name(void)
{
    char c = look;
    if (!isalpha(c)) {
        report_expected("Name expected");
    }
    get_char();
    printf("Name matched: %c\n", c);
    return toupper(c);
}

/**
 * Get a number
 */
char get_num(void)
{
    char c = look;
    if (!isdigit(c)) {
        report_expected("Number expected");
    }
    get_char();
    printf("Number matched: %c\n", c);
    return c;
}

/**
 * Emit a string to the console
 */
void emit(const char *s)
{
    printf("\t%s", s);
}

/**
 * Emit a string to the console with a newline
 */
void emit_ln(const char *s)
{
    emit(s);
    printf("\n");
}

/**
 * Initialize the Cradle
 */
void initialize(void)
{
    get_char();
}

/**
 * Main function
 */
void main(void)
{
    initialize();
}