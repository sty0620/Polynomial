#include"head.h"

int main()
{
    Poly P, Q, R,S;
    CreatePoly(P);
    CreatePoly(Q);
    PrintPoly(P);
    PrintPoly(Q);
    SortPoly(P);
    SortPoly(Q);
    MergePoly(P);
    MergePoly(Q);
    PrintPoly(P);
    PrintPoly(Q);
    printf("-------\n");
    DivPloy(P, Q, R, S);
    PrintPoly(R);
    PrintPoly(S);
    //DiffPloy(P,R);
    //IntrgralPloy(P, R);
    //PrintPoly(R);
    //AddPoly(P, Q, R);
    //SubPoly(P, Q, R);
   // MulPoly(P, Q, R);
    //PrintPoly(R);
    printf("Success");
}