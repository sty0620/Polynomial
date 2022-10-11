#include"head.h"

int main()
{
    Poly P, Q, R;
    CreatePoly(P);
    //CreatePoly(Q);
    PrintPoly(P);
    //PrintPoly(Q);
    SortPoly(P);
   // SortPoly(Q);
    MergePoly(P);
    //MergePoly(Q);
    PrintPoly(P);
    //PrintPoly(Q);
    printf("----\n");
    //DiffPloy(P,R);
    IntrgralPloy(P, R);
    PrintPoly(R);
    //AddPoly(P, Q, R);
    //SubPoly(P, Q, R);
   // MulPoly(P, Q, R);
    //PrintPoly(R);
    printf("Success");
}