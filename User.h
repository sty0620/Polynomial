#pragma once
#ifndef  USER_H_INCLUDED
#define USER_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#define   NR(x)   (sizeof(x)/sizeof(x[0]+0))
CONSOLE_CURSOR_INFO cci;
COORD pos = { 0, 0 };
enum {
    UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ENTER = 13, ESC = 27,
};
void print_head();
int  get_userinput(int* index, int size);
void showmenu(HANDLE hOut, char** menu, int size, int index);
void Clean(HANDLE hOut);
void cciVisiable(HANDLE hOut);
void cciNotVisiable(HANDLE hOut);
#endif