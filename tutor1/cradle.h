/**
 * @file        cradle.h
 * @brief       Header file for the Cradle program
 * @date        November 13, 2025   
 */

#ifndef _CRADLE_H_
#define _CRADLE_H_

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
void is_alpha_char(char c);
void is_digit_char(char c);
void is_addop_char(char c);
void get_identifier(void);
void get_number(void);
void emit(const char *s);
void emit_ln(const char *s);
void initialize(void);
void main(void);

#endif  /* _CRADLE_H_ */
