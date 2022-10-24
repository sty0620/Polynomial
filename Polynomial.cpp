#include"head.h"
#include"User.h"
char* menu[] = {
        "更改初始多项式","  遍历多项式  ","  多项式相加  ","  多项式相减  ","  多项式相乘  ","  多项式相除  ","  多项式积分  ","  多项式微分  ","     退出     "
};
int main() {
    int cnt = 0,ret,index = 0;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hOut, &cci);
    puts("请创建您的初始的第一个多项式(用于减法中被减数/除法中被除数，积分和微分)：");
    Poly P,Q,Result;
    InitPoly(P);
    InitPoly(Q);
    CreatAndMerge(P);
    printf("\n请输入你的第二个多项式(用于减法中减数 / 除法中除数)：\n");
    CreatAndMerge(Q);
    Clean(hOut);
    cci.dwSize = 1; 
    cci.bVisible = 0;
    SetConsoleCursorInfo(hOut, &cci);
    while (1) {
        print_head();
        showmenu(hOut, menu, NR(menu), index);
        printf("\n");
        ret = get_userinput(&index, NR(menu));
        if (ret == ESC)
            break;
        if (ret == ENTER) {
            switch (index) {
            case 0: {
                puts("您要修改的是第一个多项式还是第二个多项式？（请输入对应的数字，只能输入1或者2）");
                while (true) {
                    int flag;
                    scanf("%d", &flag);
                    if (flag == 1) {
                        DestoryPloy(P);
                        cciVisiable(hOut);
                        CreatAndMerge(P);
                        break;
                    }
                    else if (flag == 2) {
                        DestoryPloy(Q);
                        cciVisiable(hOut);
                        CreatAndMerge(Q);
                        break;
                    }
                    else {
                        puts("你输入的数字有误，请重新输入");
                    }
                } 
                Clean(hOut);
                break;
            }
            case 1: {
                PrintPoly(P);
                Clean(hOut);
                break;
            }
            case 2: {
                printf("初始两个多项式：");
                PrintPoly(P);
                PrintPoly(Q);
                AddPoly(P, Q, Result); 
                printf("相加的结果为：");
                PrintPoly(Result);
                DestoryPloy(Result);
                Clean(hOut);
                break;
            }
            case 3: {
                printf("被减数：");
                PrintPoly(P);
                printf("减数：");
                PrintPoly(Q);
                SubPoly(P, Q, Result);
                printf("相减的结果为：");
                PrintPoly(Result);
                DestoryPloy(Result);
                Clean(hOut);
                break;
            }
            case 4: {
                printf("初始两个多项式：");
                PrintPoly(P);
                PrintPoly(Q);
                MulPoly(P, Q, Result);
                printf("相乘的结果为：");
                PrintPoly(Result);
                DestoryPloy(Result);
                Clean(hOut);
                break;
            }
            case 5: {
                Poly Remainder;
                InitPoly(Remainder);
                printf("被除数：");
                PrintPoly(P);
                printf("除数：");
                PrintPoly(Q);
                DivPloy(P, Q, Result, Remainder);
                printf("商为：");
                PrintPoly(Result);
                printf("余数：");
                PrintPoly(Remainder);
                DestoryPloy(Result);
                DestoryPloy(Remainder);
                Clean(hOut);
                break;
            }
            case 6: {
                printf("原多项式：");
                PrintPoly(P);
                DiffPloy(P, Result);
                printf("求导后得到多项式：");
                PrintPoly(Result);
                DestoryPloy(Result);
                Clean(hOut);
                break;
            }
            case 7: {
                printf("原多项式：");
                PrintPoly(P);
                IntrgralPloy(P, Result);
                printf("微分后得到多项式：");
                PrintPolyOfIntrgral(Result);
                DestoryPloy(Result);
                Clean(hOut);
                break;
            }
            case 8: {
                Clean(hOut);
                SetConsoleTextAttribute(hOut, 0x7);
                return 0;
            }
            }
        }
    }
    return 0;
}
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