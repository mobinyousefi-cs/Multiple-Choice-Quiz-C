/*
 * ===========================================================
 * Project:    Multiple Choice Quiz (Console)
 * File:       main.c
 * Author:     Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:    2025-11-28
 * License:    MIT License (see LICENSE file for details)
 * ===========================================================
 *
 * Description:
 *    Entry point for the Multiple Choice Quiz application.
 *    Defines a static bank of questions (computer science
 *    and general programming) and invokes the quiz engine.
 *
 * Usage:
 *    make
 *    ./bin/quiz
 *
 * Notes:
 *    - All Question/Option strings are UTF-8 string literals.
 *    - To extend the quiz, simply append more QuizQuestion
 *      entries to the questions[] array.
 * ===========================================================
 */

#include "quiz.h"

#include <stdio.h>

/* ------------------------ Question bank ------------------------ */

static const QuizQuestion questions[] = {
    {
        "Which of the following is NOT a programming paradigm?",
        {
            "Object-oriented",
            "Functional",
            "Relational",
            "Procedural"
        },
        2 /* "Relational" is a data model, not a paradigm */
    },
    {
        "What is the time complexity of binary search on a sorted array?",
        {
            "O(n)",
            "O(log n)",
            "O(n log n)",
            "O(1)"
        },
        1
    },
    {
        "Which data structure operates in a First-In, First-Out (FIFO) manner?",
        {
            "Stack",
            "Queue",
            "Binary tree",
            "Hash table"
        },
        1
    },
    {
        "Which keyword in C is used to define a constant variable?",
        {
            "static",
            "define",
            "const",
            "final"
        },
        2
    },
    {
        "In C, which operator is used to access a member of a struct via a pointer?",
        {
            ". (dot)",
            "-> (arrow)",
            "& (ampersand)",
            "* (asterisk)"
        },
        1
    },
    {
        "Which of the following best describes a 'pointer' in C?",
        {
            "A variable that stores data directly",
            "A variable that stores the address of another variable",
            "A variable that stores only integers",
            "A variable that stores function return values"
        },
        1
    },
    {
        "Which of the following is TRUE about arrays in C?",
        {
            "Array indices start from 1",
            "The size of an array must be a constant expression",
            "Arrays can automatically resize at runtime",
            "Arrays can contain elements of different types"
        },
        1
    },
    {
        "What does 'RAM' stand for?",
        {
            "Random Access Memory",
            "Read Access Memory",
            "Rapid Action Memory",
            "Random Allocation Memory"
        },
        0
    },
    {
        "Which layer of the OSI model is responsible for routing?",
        {
            "Application layer",
            "Transport layer",
            "Network layer",
            "Data link layer"
        },
        2
    },
    {
        "Which of the following is a primary advantage of using modularity in software design?",
        {
            "Increased code duplication",
            "Decreased reusability",
            "Improved maintainability and readability",
            "Slower compilation times"
        },
        2
    }
};

static const Quiz quiz = {
    questions,
    sizeof(questions) / sizeof(questions[0]),
    "Computer Science & Programming Basics"
};

/* ------------------------ Entry point ------------------------ */

int main(void) {
    puts("============================================================");
    puts("                Multiple Choice Quiz (Console)               ");
    puts("============================================================");
    printf("Quiz Title: %s\n\n", quiz.title);
    puts("Instructions:");
    puts("  - You will be asked a series of multiple choice questions.");
    puts("  - For each question, type A, B, C, or D and press Enter.");
    puts("  - Type Q at any time to quit the quiz early.\n");

    int score = 0;
    size_t answered = 0;

    quiz_run(&quiz, &score, &answered);
    quiz_print_summary(score, answered);

    puts("Thank you for playing!");
    return 0;
}
