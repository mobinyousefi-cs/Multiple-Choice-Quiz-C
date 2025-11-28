/*
 * ===========================================================
 * Project:    Multiple Choice Quiz (Console)
 * File:       quiz.c
 * Author:     Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
 * Created:    2025-11-28
 * License:    MIT License (see LICENSE file for details)
 * ===========================================================
 *
 * Description:
 *    Implementation of the quiz engine: presents questions,
 *    reads user answers, and tracks scores. All I/O is done
 *    via standard input and output (stdio).
 *
 * Usage:
 *    - See main.c for an example of how to construct a Quiz
 *      and call quiz_run and quiz_print_summary.
 *
 * Notes:
 *    - No dynamic memory allocation is used.
 *    - Input is validated and robust against simple user errors.
 * ===========================================================
 */

#include "quiz.h"

#include <ctype.h>
#include <stdio.h>

/* ------------------------ Internal helpers ------------------------ */

static int read_answer_index(void) {
    char buffer[64];

    for (;;) {
        printf("Your answer (A-D, or Q to quit): ");

        if (fgets(buffer, sizeof buffer, stdin) == NULL) {
            /* EOF or input error: treat as quit */
            return -1;
        }

        char c = '\0';
        if (sscanf(buffer, " %c", &c) != 1) {
            puts("Invalid input. Please enter A, B, C, D or Q.");
            continue;
        }

        c = (char)toupper((unsigned char)c);

        if (c == 'Q') {
            return -1;
        }

        if (c >= 'A' && c <= 'D') {
            return (int)(c - 'A');
        }

        puts("Please enter A, B, C or D (or Q to quit).");
    }
}

/* ------------------------ Public API ------------------------ */

void quiz_run(const Quiz *quiz, int *out_score, size_t *out_asked) {
    if (!quiz || !quiz->questions || quiz->question_count == 0 ||
        !out_score || !out_asked) {
        return;
    }

    int score = 0;
    size_t asked = 0;

    for (size_t i = 0; i < quiz->question_count; ++i) {
        const QuizQuestion *q = &quiz->questions[i];

        puts("------------------------------------------------------------");
        printf("Question %zu: %s\n", i + 1, q->text);

        for (int opt = 0; opt < QUIZ_MAX_OPTIONS; ++opt) {
            if (q->options[opt] != NULL) {
                printf("  %c) %s\n", 'A' + opt, q->options[opt]);
            }
        }

        int answer_index = read_answer_index();
        if (answer_index < 0) {
            puts("\nYou chose to end the quiz early.");
            break;
        }

        ++asked;

        if (answer_index == q->correct_index) {
            puts("Correct!\n");
            ++score;
        } else {
            printf("Incorrect. The correct answer was %c.\n\n",
                   'A' + q->correct_index);
        }
    }

    *out_score = score;
    *out_asked = asked;
}

void quiz_print_summary(int score, size_t asked) {
    puts("============================================================");
    puts("                       Quiz Summary                         ");
    puts("============================================================");

    if (asked == 0U) {
        puts("No questions were answered. No score to report.\n");
        return;
    }

    double percentage = 100.0 * (double)score / (double)asked;

    printf("Questions answered : %zu\n", asked);
    printf("Correct answers    : %d\n", score);
    printf("Score              : %.2f%%\n", percentage);

    const char *grade;
    if (percentage >= 90.0) {
        grade = "Excellent";
    } else if (percentage >= 75.0) {
        grade = "Good";
    } else if (percentage >= 60.0) {
        grade = "Satisfactory";
    } else if (percentage >= 40.0) {
        grade = "Needs Improvement";
    } else {
        grade = "Poor";
    }

    printf("Performance        : %s\n\n", grade);
}
