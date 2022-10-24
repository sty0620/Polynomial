#include "head.h"

Status InitPoly(Poly& P)
{
    P.elem = NULL;
    P.length = 0;
    return Success;
}

Status CreatePoly(Poly& P)
{
    int n;
    printf("请输入非零项数的个数 ");
    scanf("%d", &n);
    P.elem = (Term*)calloc(n, sizeof(Term));
    if (NULL == P.elem) {
        printf("error:faild to allocate memory\n");
        return Error;
    }
    for (int i = 0; i < n; i++) {
        printf("您目前输入的为第%d组：请输入2个数字，中间用空格隔开，第一个数表示系数(不可为0)，第二个数表示对应指数(非负数) \n", i + 1);
        scanf("%lf %d", &P.elem[i].xishu, &P.elem[i].zhishu);
    }
    P.length = n;
    return Success;
}

Status CreatAndMerge(Poly& P)
{
    CreatePoly(P);
    SortPoly(P);
    MergePoly(P);
    printf("您创建的多项式为：");
    PrintPoly(P);
    return Status();
}

Status CreatePolyFromArrey(Poly& P, int MaxZhishu, double Xishu[])
{
    int len = PolyLength(Xishu, MaxZhishu);
    if (len == 0) {
        if ((P.elem = (Term*)calloc(1, sizeof(Term))) == NULL) {
            printf("error:faild to allocate memory\n");
            return Error;
        }
        P.elem[0].xishu = P.elem[0].zhishu = 0;
        P.length = 1;
        return Success;
    }
    P.elem = (Term*)calloc(len, sizeof(Term));
    for (int i = 0,j = 0; i <= MaxZhishu; i++) {
        if (fabs(Xishu[i]) + 0.005 >= 0.01) {
            P.elem[j].xishu = Xishu[i];
            P.elem[j].zhishu = i;
            j++;
        }
    }
    P.length = len;
    return Success;
}

int PolyLength(double Xishu[], int MaxZhishu)
{
    int len = 0;
    for (int i = 0; i <= MaxZhishu; i++) {
        if ((fabs(Xishu[i]) + 0.005)>=0.01) {//小于0.005的直接舍去
            len++;
        }
    }
    return len;
}

Status DestoryPloy(Poly& P)
{
    P.length = 0;
    if (NULL == P.elem) {
        printf("无数据，无需删除\n");
        return Error;
    }
    free(P.elem);
    return Success;
}

Status PrintPoly(Poly P)
{
    if (P.length == 0 || NULL == P.elem) {
        printf("无数据或者尚未初始化\n");
        return Error;
    }
    printf("%.2fx^%d", P.elem[0].xishu, P.elem[0].zhishu);
    for(int i = 1; i < P.length; i++) {
        if (P.elem[i].xishu < 0) {
            printf("%.2fx^%d", P.elem[i].xishu, P.elem[i].zhishu);
        }
        else {
            printf("+%.2fx^%d", P.elem[i].xishu, P.elem[i].zhishu);
        } 
    }
    printf("\n");
    return Success;
}

Status PrintPolyOfIntrgral(Poly P)
{
    if (P.length == 0 || NULL == P.elem) {
        printf("无数据或者尚未初始化\n");
        return Error;
    }
    printf("λ+%.2fx^%d", P.elem[0].xishu, P.elem[0].zhishu);
    for (int i = 1; i < P.length; i++) {
        if (P.elem[i].xishu < 0) {
            printf("%.2fx^%d", P.elem[i].xishu, P.elem[i].zhishu);
        }
        else {
            printf("+%.2fx^%d", P.elem[i].xishu, P.elem[i].zhishu);
        }
    }
    printf(" (λ表示常数)\n");
    return Success;
}

Status AddPoly(Poly P1, Poly P2, Poly& ResultP)
{
    if (P1.length == 0 || NULL == P1.elem || P2.length == 0 || NULL == P2.elem) {
        printf("无数据或者尚未初始化\n");
        return Error;
    }
    int P1_Pos = 0, P2_Pos = 0, Len_ResultP = 0;
    double XishuResultP;
    ResultP.elem = (Term*)calloc(P1.length + P2.length, sizeof(Term));
    if (NULL == ResultP.elem) {
        printf("error:faild to allocate memory\n");
        return Error;
    }
    while (P1_Pos < P1.length && P2_Pos < P2.length) {
        if (P1.elem[P1_Pos].zhishu < P2.elem[P2_Pos].zhishu) {
            ResultP.elem[Len_ResultP++] = P1.elem[P1_Pos++];
        }
        else if (P1.elem[P1_Pos].zhishu > P2.elem[P2_Pos].zhishu) {
            ResultP.elem[Len_ResultP++] = P2.elem[P2_Pos++];
        }
        else {
            XishuResultP = P1.elem[P1_Pos].xishu + P2.elem[P2_Pos].xishu;
            if (XishuResultP != 0) {
                ResultP.elem[Len_ResultP].xishu = XishuResultP;
                ResultP.elem[Len_ResultP].zhishu = P1.elem[P1_Pos].zhishu;
                Len_ResultP++;
            }
            P1_Pos++;
            P2_Pos++;
        }
    }
    if (P1_Pos == P1.length) {
        while (P2_Pos < P2.length) {
            ResultP.elem[Len_ResultP++] = P2.elem[P2_Pos++];
        }
    }
    if (P2_Pos == P2.length) {
        while (P1_Pos < P1.length) {
            ResultP.elem[Len_ResultP++] = P1.elem[P1_Pos++];
        }
    }
    ResultP.length = Len_ResultP;
    ResultP.elem = (Term*)realloc(ResultP.elem, Len_ResultP * sizeof(Term));
    return Success;
}

Status SubPoly(Poly P1, Poly P2, Poly& ResultP)
{
    if (P1.length == 0 || NULL == P1.elem || P2.length == 0 || NULL == P2.elem) {
        printf("无数据或者尚未初始化\n");
        return Error;
    }
    int P1_Pos = 0, P2_Pos = 0, Len_ResultP = 0;
    double XishuResultP;
    ResultP.elem = (Term*)calloc(P1.length + P2.length, sizeof(Term));
    if (NULL == ResultP.elem) {
        printf("error:faild to allocate memory\n");
        return Error;
    }
    while (P1_Pos < P1.length && P2_Pos < P2.length) {
        if (P1.elem[P1_Pos].zhishu < P2.elem[P2_Pos].zhishu) {
            ResultP.elem[Len_ResultP++] = P1.elem[P1_Pos++];
        }
        else if (P1.elem[P1_Pos].zhishu > P2.elem[P2_Pos].zhishu) {
            ResultP.elem[Len_ResultP].xishu = P2.elem[P2_Pos].xishu * -1;
            ResultP.elem[Len_ResultP].zhishu = P2.elem[P2_Pos].zhishu;
            Len_ResultP++;
            P2_Pos++;
        }
        else {
            XishuResultP = P1.elem[P1_Pos].xishu - P2.elem[P2_Pos].xishu;
            if (XishuResultP != 0) {
                ResultP.elem[Len_ResultP].xishu = XishuResultP;
                ResultP.elem[Len_ResultP].zhishu = P1.elem[P1_Pos].zhishu;
                Len_ResultP++;
            }
            P1_Pos++;
            P2_Pos++;
        }
    }
    if (P1_Pos == P1.length) {
        while (P2_Pos < P2.length) {
            ResultP.elem[Len_ResultP].zhishu = P2.elem[P2_Pos].zhishu;
            ResultP.elem[Len_ResultP].xishu = P2.elem[P2_Pos].xishu*-1;
            Len_ResultP++;
            P2_Pos++;
        }
    }
    if (P2_Pos == P2.length) {
        while (P1_Pos < P1.length) {
            ResultP.elem[Len_ResultP].xishu = P1.elem[P1_Pos].xishu;
            ResultP.elem[Len_ResultP].zhishu = P1.elem[P1_Pos].zhishu;
            Len_ResultP++;
            P1_Pos++;
        }
    }
    ResultP.length = Len_ResultP;
    ResultP.elem = (Term*)realloc(ResultP.elem, Len_ResultP * sizeof(Term));
    return Success;
}

Status MulPoly(Poly P1, Poly P2, Poly& ResultP)
{
    if (P1.length == 0 || NULL == P1.elem || P2.length == 0 || NULL == P2.elem) {
        printf("无数据或者尚未初始化\n");
        return Error;
    }
    int P1_Pos, P2_Pos, Len_ResultP = 0;
    ResultP.elem = (Term*)calloc(P1.length * P2.length, sizeof(Term));
    if (NULL == ResultP.elem) {
        printf("error:faild to allocate memory\n");
        return Error;
    }
    for (P1_Pos = 0; P1_Pos < P1.length; P1_Pos++) {
        for (P2_Pos = 0; P2_Pos < P2.length; P2_Pos++) {
            ResultP.elem[Len_ResultP].xishu = P1.elem[P1_Pos].xishu * P2.elem[P2_Pos].xishu;
            ResultP.elem[Len_ResultP].zhishu = P1.elem[P1_Pos].zhishu + P2.elem[P2_Pos].zhishu;
            Len_ResultP++;
        }
    }
    ResultP.length = Len_ResultP;
    SortPoly(ResultP);
    MergePoly(ResultP);
    ResultP.elem = (Term*)realloc(ResultP.elem, ResultP.length * sizeof(Term));
    return Success;
}

Status DivPloy(Poly P1, Poly P2, Poly& ResultP, Poly& RemainderP)
{
    if (P1.length == 0 || NULL == P1.elem|| P2.length == 0 || NULL == P2.elem) {
        printf("无数据或者尚未初始化\n");
        return Error;
    }
    if (P1.elem[P1.length - 1].zhishu < P2.elem[P2.length - 1].zhishu) {
        printf("被除数多项式最大系数小于除数多项式系数\n");
        ResultP.elem = (Term*)calloc(1, sizeof(Term));
        if (NULL == ResultP.elem) {
            printf("error:faild to allocate memory\n");
            return Error;
        }
        ResultP.elem[0].xishu = ResultP.elem[0].zhishu = 0;
        ResultP.length = 1;
        RemainderP = P1;
        return Success;
    }
    int Max_ZhishuP1 = -1, Max_ZhishuP2 = -1;
    double P1_Xishu[1000]={0}, P2_Xishu[1000] = { 0 }, Quotient[1000] = { 0 };
    for (int i = 0; i < P1.length; i++) {
        P1_Xishu[P1.elem[i].zhishu] = P1.elem[i].xishu;
        Max_ZhishuP1 = Max_ZhishuP1 > P1.elem[i].zhishu ? Max_ZhishuP1 : P1.elem[i].zhishu;
    }
    for (int i = 0; i < P2.length; i++) {
        P2_Xishu[P2.elem[i].zhishu] = P2.elem[i].xishu;
        Max_ZhishuP2 = Max_ZhishuP2 > P2.elem[i].zhishu ? Max_ZhishuP2 : P2.elem[i].zhishu;
    }
    int t1 = Max_ZhishuP1, t2 = Max_ZhishuP2;
    while (t1 >= t2) {
        double result = P1_Xishu[t1] / P2_Xishu[t2];
        Quotient[t1 - t2] = result;
        for (int i = t1, j = t2; j >= 0; j--, i--) {
            P1_Xishu[i] -= P2_Xishu[j] * result;
        }
        t1--;
    }
    CreatePolyFromArrey(ResultP, Max_ZhishuP1 - Max_ZhishuP2, Quotient);
    CreatePolyFromArrey(RemainderP, Max_ZhishuP2, P1_Xishu);
    return Success;
}

Status DiffPloy(Poly P, Poly& ResultP)//微分
{
    if (P.length == 0 || NULL == P.elem) {
        printf("无数据或者尚未初始化\n");
        return Error;
    }
    ResultP.elem = (Term*)calloc(P.length, sizeof(Term));
    if (NULL == ResultP.elem) {
        printf("error:faild to allocate memory\n");
        return Error;
    }
    int len = 0;
    for (int i = 0; i < P.length;i++) {
        if (P.elem[i].zhishu == 0) {
            continue;
        }
        else {
            ResultP.elem[len].xishu = P.elem[i].xishu * P.elem[i].zhishu;
            ResultP.elem[len].zhishu = P.elem[i].zhishu - 1;
            len++;
        }
    }
    ResultP.length = len;
    return Success;
}

Status IntrgralPloy(Poly P, Poly& ResultP)//积分 此时默认常数项等于0
{
    if (P.length == 0 || NULL == P.elem) {
        printf("无数据或者尚未初始化\n");
        return Error;
    }
    ResultP.elem = (Term*)calloc(P.length, sizeof(Term));
    if (NULL == ResultP.elem) {
        printf("error:faild to allocate memory\n");
        return Error;
    }
    for (int i = 0; i < P.length; i++) {
        ResultP.elem[i].xishu = P.elem[i].xishu / (P.elem[i].zhishu+1);
        ResultP.elem[i].zhishu = P.elem[i].zhishu + 1;
    }
    ResultP.length = P.length;
    return Success;
}

void SortPoly(Poly& P)
{
    Qsort(P, 0, P.length - 1);
}

void Qsort(Poly& P, int left, int right) {
    int low, high,TempNum;
    Term TempTerm;
    if (left > right) {
        return;
    }
    TempNum = P.elem[left].zhishu;
    TempTerm = P.elem[left];
    low = left;
    high = right;
    while (low != high) {
        while (P.elem[high].zhishu >= TempNum && low < high)high--;
        P.elem[low] = P.elem[high];
        while (P.elem[low].zhishu <= TempNum && low < high)low++;
        P.elem[high] = P.elem[low];
    }
    P.elem[low] = TempTerm;
    Qsort(P, left, low - 1);
    Qsort(P, low + 1, right);
}
void MergePoly(Poly& P) {
    for (int i = 0; i < P.length; i++) {
        for (int j = i+1; j < P.length&&P.elem[i].zhishu==P.elem[j].zhishu; ) {
            P.elem[i].xishu += P.elem[j].xishu;
            for (int k = j + 1; k < P.length; k++) {
                P.elem[k - 1] = P.elem[k];
            }
            P.length--;
        }
        if (P.elem[i].xishu == 0) {
            for (int k = i + 1; k < P.length; k++) {
                P.elem[k - 1] = P.elem[k];
            }
            P.length--;
        }
    }
}
