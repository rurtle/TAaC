#!/usr/bin/env python3

import sys
import io

## Variable declarations
look = ''  # Lookahead character


## Function declarations


def get_char():
    """Read new character from input stream"""
    global look
    look = sys.stdin.read(1)


def report_error(x):
    """Report an error"""
    print(f"Error: {x}")


def report_abort(x):
    """Report error and halt"""
    report_error(x)
    sys.exit(1)


def report_expected(x):
    """Report what was expected"""
    report_abort(f"{x} Expected")


def match_char(x):
    """Match a specific input character"""
    if look == x:
        get_char()
    else:
        report_expected(f"' {x} '")


def is_alpha_char(x):
    """Recognize an alpha character"""
    return x.isalpha()


def is_digit_char(x):
    """Recognize a decimal digit"""
    return x.isdigit()


def is_addop_char(x):
    """Recognize an addop character"""
    return x in ['+', '-']


def get_identifier():
    """Get an identifier"""
    if not is_alpha_char(look):
        report_expected("Name")
    token = ''
    while is_alpha_char(look) or is_digit_char(look):
        token += look
        get_char()
    return token.to_upper()


def get_number():
    """Get a number"""
    if not is_digit_char(look):
        report_expected("Number")
    token = ''
    while is_digit_char(look):
        token += look
        get_char()
    return token


def emit(s):
    """Output a string with tab"""
    print(f"\t{x}")


def emit_ln(s):
    """Output a string with tab and CRLF"""
    print(f"\t{x}\n")


def initialize():
    """Initialize"""
    get_char()


def main():
    """Main program"""
    initialize()
    print("Hello, World!")


if __name__ == "__main__":
    main()
