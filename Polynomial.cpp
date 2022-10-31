#include"User.h"
CONSOLE_CURSOR_INFO Cci;
COORD Pos = { 0, 0 };
char* menu[] = {
        "更改初始多项式","  遍历多项式  ","  多项式相加  ","  多项式相减  ","  多项式相乘  ","  多项式相除  ","  多项式积分  ","  多项式微分  ","     退出     "
};
int main() {
    int cnt = 0,ret,index = 0;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hOut, &Cci);
    puts("请创建您的初始的第一个多项式(用于减法中被减数/除法中被除数，积分和微分)：");
    Poly P,Q,Result;
    InitPoly(P);
    InitPoly(Q);
    CreatAndMerge(P);
    printf("\n请输入你的第二个多项式(用于减法中减数 / 除法中除数)：\n");
    CreatAndMerge(Q);
    Clean(hOut,Cci);
    Cci.dwSize = 1; 
    Cci.bVisible = 0;
    SetConsoleCursorInfo(hOut, &Cci);
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
                cciVisiable(hOut, Cci);
                puts("您要修改的是第一个多项式还是第二个多项式？（请输入对应的数字，只能输入1或者2）");
                while (true) {
                    int flag;
                    scanf("%d", &flag);
                    if (flag == 1) {
                        DestoryPloy(P);    
                        CreatAndMerge(P);
                        break;
                    }
                    else if (flag == 2) {
                        DestoryPloy(Q);
                        CreatAndMerge(Q);
                        break;
                    }
                    else {
                        puts("你输入的数字有误，请重新输入");
                    }
                } 
                Clean(hOut, Cci);
                break;
            }
            case 1: {
                printf("当前第一个多项式： ");
                PrintPoly(P);
                printf("当前第二个多项式： ");
                PrintPoly(Q);
                Clean(hOut, Cci);
                break;
            }
            case 2: {
                printf("当前第一个多项式： ");
                PrintPoly(P);
                printf("当前第二个多项式： ");
                PrintPoly(Q);
                AddPoly(P, Q, Result); 
                printf("相加的结果为：");
                PrintPoly(Result);
                DestoryPloy(Result);
                Clean(hOut, Cci);
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
                Clean(hOut, Cci);
                break;
            }
            case 4: {
                printf("当前第一个多项式： ");
                PrintPoly(P);
                printf("当前第二个多项式： ");
                PrintPoly(Q);
                MulPoly(P, Q, Result);
                printf("相乘的结果为：");
                PrintPoly(Result);
                DestoryPloy(Result);
                Clean(hOut, Cci);
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
                Clean(hOut, Cci);
                break;
            }
            case 6: {
                printf("原多项式：");
                PrintPoly(P);
                DiffPloy(P, Result);
                printf("求导后得到多项式：");
                PrintPoly(Result);
                DestoryPloy(Result);
                Clean(hOut, Cci);
                break;
            }
            case 7: {
                printf("原多项式：");
                PrintPoly(P);
                IntrgralPloy(P, Result);
                printf("微分后得到多项式：");
                PrintPolyOfIntrgral(Result);
                DestoryPloy(Result);
                Clean(hOut, Cci);
                break;
            }
            case 8: {
                SetConsoleTextAttribute(hOut, 0x7);
                return 0;
            }
            }
        }
    }
    return 0;
}

