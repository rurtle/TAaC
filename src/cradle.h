/**
 * @file        cradle.h
 * @brief       Header file for the Cradle program
 * @date        November 13, 2025   
 */

#ifndef _CRADLE_H_
#define _CRADLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Macro declarations
#define MAX_TOKEN_LENGTH 100

// Global variables
static char token[MAX_TOKEN_LENGTH];
static char look;

// Function declarations
void get_char(void);
void report_error(const char *message);
void report_abort(const char *message);
void report_expected(const char *message);
void match_char(char c);
bool is_alpha_char(char c);
bool is_digit_char(char c);
bool is_addop_char(char c);
char get_name(void);
char get_num(void);
void emit(const char *s);
void emit_ln(const char *s);
void initialize(void);

#endif  /* _CRADLE_H_ */
