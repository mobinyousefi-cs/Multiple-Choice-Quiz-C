# ===========================================================
# Project:    Multiple Choice Quiz (Console)
# File:       Makefile
# Author:     Mobin Yousefi (GitHub: github.com/mobinyousefi-cs)
# Created:    2025-11-28
# License:    MIT License (see LICENSE file for details)
# ===========================================================

CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -pedantic -Iinclude
SRCDIR  := src
INCDIR  := include
OBJDIR  := obj
BINDIR  := bin

TARGET  := $(BINDIR)/quiz
OBJECTS := $(OBJDIR)/main.o $(OBJDIR)/quiz.o

.PHONY: all clean dirs

all: dirs $(TARGET)

dirs:
	mkdir -p $(OBJDIR) $(BINDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/quiz.h
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)
