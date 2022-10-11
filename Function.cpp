#include "head.h"

Status CreatePoly(Poly& P)
{
    int n;
    printf("��������������ĸ��� ");
    scanf("%d", &n);
    P.elem = (Term*)calloc(n, sizeof(Term));
    if (NULL == P.elem) {
        printf("error:faild to allocate memory\n");
        return Error;
    }
    for (int i = 0; i < n; i++) {
        printf("��Ŀǰ�����Ϊ��%d�飺������2�����֣��м��ÿո��������һ������ʾϵ�����ڶ�������ʾ��Ӧָ��(����Ϊ0) \n", i + 1);
        scanf("%lf %d", &P.elem[i].xishu, &P.elem[i].zhishu);
    }
    P.length = n;
    return Success;
}

Status DestoryPloy(Poly& P)
{
    P.length = 0;
    if (NULL == P.elem) {
        printf("�����ݣ�����ɾ��\n");
        return Error;
    }
    free(P.elem);
    printf("����ɾ���ɹ�\n");
    return Success;
}

Status PrintPoly(Poly P)
{
    if (P.length == 0 || NULL == P.elem) {
        printf("������\n");
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

Status AddPoly(Poly P1, Poly P2, Poly& ResultP)
{
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
            XishuResultP = P1.elem[P1_Pos].zhishu + P2.elem[P2_Pos].zhishu;
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
            XishuResultP = P1.elem[P1_Pos].zhishu - P2.elem[P2_Pos].zhishu;
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

Status MulPoly(Poly P1, Poly P2, Poly& ResultP)
{
    return Success;
}

Status DivPloy(Poly P1, Poly P2, Poly& ResultP, Poly& RemainderP)
{
    return Success;
}

Status DiffPloy(Poly P, Poly& ResultP)
{
    return Success;
}

Status IntrgralPloy(Poly P, Poly& ResultP)
{
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
void swop(Term* a, Term* b) {
    Term* temp;
    temp = a;
    a = b;
    b = temp;
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
    }
}