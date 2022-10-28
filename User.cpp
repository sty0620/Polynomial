#include "User.h"

CONSOLE_CURSOR_INFO cci;
COORD pos = { 0, 0 };

void print_head() {//打印出表头
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = 0;	pos.Y = 0;
    SetConsoleCursorPosition(hOut, pos);
    SetConsoleTextAttribute(hOut, 12);
    printf("计算机学院计科伏羲班21（1）-孙天一-3121005309-一元稀疏多项式.\n");
    pos.X = 0;	pos.Y = 1;
    SetConsoleCursorPosition(hOut, pos);
    printf("************************************************************\n");
    SetConsoleTextAttribute(hOut, 0x7);
}
void showmenu(HANDLE hOut, char** menu, int size, int index) {
    int i;
    for (i = 0; i < size; i++) {
        if (i == index) {
            pos.X = 18;	pos.Y = 2 + i;
            SetConsoleCursorPosition(hOut, pos);
            SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | 0x70);
            printf("%s", menu[i]);
        }
        else {
            pos.X = 18;	pos.Y = 2 + i;
            SetConsoleCursorPosition(hOut, pos);
            SetConsoleTextAttribute(hOut, 0x7);
            printf("%s", menu[i]);
        }
    }
}
void Clean(HANDLE hOut)
{
    system("pause");
    cciNotVisiable(hOut);
    system("cls");
}
void cciVisiable(HANDLE hOut)
{
    cci.bVisible = 1;
    SetConsoleCursorInfo(hOut, &cci);
}
void cciNotVisiable(HANDLE hOut)
{
    cci.bVisible = 0;
    SetConsoleCursorInfo(hOut, &cci);
}
int  get_userinput(int* index, int size) {
    int ch;
    ch = _getch();
    switch (ch) {
    case UP:
        if (*index > 0)
            *index -= 1;
        break;
    case DOWN:
        if (*index < size - 1)
            *index += 1;
        break;
    case LEFT:
        if (*index > 0)
            *index -= 1;
        break;
    case RIGHT:
        if (*index < size - 1)
            *index += 1;
        break;
    case ENTER:
        return ENTER;
    case ESC:
        return ESC;
    }
    return 0;
}