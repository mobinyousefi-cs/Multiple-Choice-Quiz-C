# Multiple Choice Quiz (C)

     __  __       _   _       _   _       _   _       ____        _     
    |  \/  | __ _| |_| |__   | | | |_ __ | |_(_) ___ |  _ \ _   _| |__  
    | |\/| |/ _` | __| '_ \  | | | | '_ \| __| |/ __|| |_) | | | | '_ \ 
    | |  | | (_| | |_| | | | | |_| | |_) | |_| | (__ |  __/| |_| | |_) |
    |_|  |_|\__,_|\__|_| |_|  \___/| .__/ \__|_|\___||_|    \__,_|_.__/ 
                                    |_|                                 

![Badge](https://img.shields.io/badge/Language-C-blue)
![Badge](https://img.shields.io/badge/Build-Makefile-green)
![Badge](https://img.shields.io/badge/License-MIT-yellow)
![Badge](https://img.shields.io/badge/Author-Mobin%20Yousefi-lightgrey)

------------------------------------------------------------------------

## Overview

This project implements a **Multiple Choice Quiz** game in the C
programming language.\
It demonstrates structured program design, modular architecture, input
validation, and console interaction.

The quiz uses:

-   A clean `struct`-based design\
-   Multi-file separation (`main.c`, `quiz.c`, `quiz.h`)\
-   A robust input parser\
-   A modular scoring & summary system\
-   A professional `Makefile`

------------------------------------------------------------------------

## Features

-   Fully interactive console quiz\
-   Graceful error handling\
-   Quit anytime with `Q`\
-   Automatic score calculation\
-   Percentage-based grading\
-   Easily extensible question bank

------------------------------------------------------------------------

## Project Structure

    multiple-choice-quiz/
    │
    ├── Makefile
    ├── README.md
    ├── include/
    │   └── quiz.h
    └── src/
        ├── main.c
        └── quiz.c

------------------------------------------------------------------------

## ASCII Flow Diagram

    +----------------------+
    |   Initialize Quiz    |
    +----------+-----------+
               |
               v
    +----------------------+
    | Display Question N   |
    +----------+-----------+
               |
               v
    +----------------------+
    |  User Input (A–D/Q)  |
    +----------+-----------+
               |
        +------+------+
        |             |
        v             v
     Correct?        Quit?
        |             |
        v             v
    Update Score    End Quiz
        |             |
        +------+------+
               |
               v
    +----------------------+
    | Next Question?       |
    +----------+-----------+
               |
               v
          End & Summary

------------------------------------------------------------------------

## Requirements

-   GCC or Clang compiler
-   Make
-   Standard C11 support

------------------------------------------------------------------------

## Build Instructions

To build the project:

    make

Executable will appear in:

    bin/quiz

To clean:

    make clean

------------------------------------------------------------------------

## Running the Quiz

    ./bin/quiz

On Windows (MinGW):

    bin\quiz.exe

------------------------------------------------------------------------

## How to Extend the Question Bank

In `main.c`, modify:

``` c
static const QuizQuestion questions[] = {
    {
        "Your new question here?",
        { "A", "B", "C", "D" },
        0
    }
};
```

Add more entries as needed.

------------------------------------------------------------------------

## License

MIT License\
Author: Mobin Yousefi\
GitHub: https://github.com/mobinyousefi-cs

------------------------------------------------------------------------

## Future Enhancements

-   JSON/CSV external question loader\
-   Randomization of question order\
-   Timer-based scoring\
-   Difficulty levels\
-   Localization (multi-language quiz)\
-   Saving results to a file
