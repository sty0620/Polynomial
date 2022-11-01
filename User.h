//自定义User.h 内含有涉及对于用户操作页面操作的
#pragma once
#ifndef  USER_H_INCLUDED
#define USER_H_INCLUDED
#include"head.h"
#define   NR(x)   (sizeof(x)/sizeof(x[0]+0))
enum {
    UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ENTER = 13, ESC = 27,
};
void print_head();
int  get_userinput(int* index, int size);
void showmenu(HANDLE hOut, char** menu, int size, int index);
void Clean(HANDLE hOut, CONSOLE_CURSOR_INFO &cci);//用于清理当前页面
void cciNotVisiable(HANDLE hOut, CONSOLE_CURSOR_INFO& cci);//关闭光标显示
void cciVisiable(HANDLE hOut, CONSOLE_CURSOR_INFO& cci);//打开光标显示
#endif