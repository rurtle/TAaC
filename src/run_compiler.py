#!/usr/bin/env python3

import sys
import io

## Variable declarations
look = ''  # Lookahead character
input_stream = ''  # Input stream

def get_char():
    """Read new character from input stream"""
    global look, input_stream
    pass

def report_error(s):
    """Report an error"""
    pass

def report_abort(s):
    """Report error and halt"""
    pass

def report_expected(s):
    """Report what was expected"""
    pass

def match_char(x):
    """Match a specific input character"""
    pass

def is_alpha_char(c):
    """Recognize an alpha character"""
    pass

def is_digit_char(c):
    """Recognize a decimal digit"""
    pass

def get_identifier():
    """Get an identifier"""
    pass

def get_number():
    """Get a number"""
    pass

def emit(s):
    """Output a string with tab"""
    pass

def emit_ln(s):
    """Output a string with tab and CRLF"""
    pass

def initialize():
    """Initialize"""
    pass

def main():
    """Main program"""
    initialize()
    print("Hello, World!")

if __name__ == "__main__":
    main()