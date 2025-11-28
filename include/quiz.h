#ifndef QUIZ_H
#define QUIZ_H

/*
 * ===========================================================
 * Project:    Multiple Choice Quiz (Console)
 * File:       quiz.h
 * Author:     Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:    2025-11-28
 * License:    MIT License (see LICENSE file for details)
 * ===========================================================
 *
 * Description:
 *    Public interface for the quiz module. Provides data
 *    structures for quiz questions and quiz configuration,
 *    as well as functions to run a quiz and print a summary
 *    of the results.
 *
 * Notes:
 *    - Questions are stored as const data (string literals).
 *    - The quiz module does not allocate dynamic memory.
 * ===========================================================
 */

#include <stddef.h> /* for size_t */

/* Maximum number of options per question. Fixed at 4 for A–D. */
#define QUIZ_MAX_OPTIONS 4

typedef struct {
    const char *text;                           /* Question text */
    const char *options[QUIZ_MAX_OPTIONS];      /* Option strings */
    int         correct_index;                  /* Index of correct option (0–3) */
} QuizQuestion;

typedef struct {
    const QuizQuestion *questions;              /* Pointer to first question */
    size_t              question_count;         /* Total number of questions */
    const char         *title;                  /* Quiz title (for display) */
} Quiz;

/**
 * Runs the quiz interactively in the console.
 *
 * Parameters:
 *    quiz       - Pointer to initialized Quiz structure.
 *    out_score  - Pointer to int; will hold number of correct answers.
 *    out_asked  - Pointer to size_t; will hold number of questions asked.
 *
 * Behavior:
 *    - Iterates through all questions in order.
 *    - Prompts the user for answers (A–D, or Q to quit early).
 *    - Updates out_score and out_asked based on user responses.
 *    - Returns immediately if quiz or output pointers are NULL.
 */
void quiz_run(const Quiz *quiz, int *out_score, size_t *out_asked);

/**
 * Prints a summary of the quiz results.
 *
 * Parameters:
 *    score  - Number of correct answers.
 *    asked  - Number of questions asked.
 *
 * Behavior:
 *    - Prints raw score and percentage.
 *    - Prints a simple textual grade based on the result.
 */
void quiz_print_summary(int score, size_t asked);

#endif /* QUIZ_H */
