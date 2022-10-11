#pragma once
#ifndef  HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#include <conio.h>
#include<Windows.h>
typedef enum Status {
	Error,
	Success
} Status;
typedef struct Term {
	double xishu;//ϵ��
	int zhishu;//ָ��
}Term;
typedef struct Poly {
	Term* elem;
	int length;
}Poly;
Status CreatePoly(Poly& P);//����
Status DestoryPloy(Poly& P);//����
Status PrintPoly(Poly P);//����
Status AddPoly(Poly P1, Poly P2, Poly& ResultP);//���
Status SubPoly(Poly P1, Poly P2, Poly& ResultP);//���
Status MulPoly(Poly P1, Poly P2, Poly& ResultP);//���
Status DivPloy(Poly P1, Poly P2, Poly& ResultP, Poly& RemainderP);//���
Status DiffPloy(Poly P, Poly& ResultP);//΢��
Status IntrgralPloy(Poly P, Poly& ResultP);//����
void SortPoly(Poly& P);//����
void Qsort(Poly& P, int left, int right);
void swop(Term* a, Term* b);
void MergePoly(Poly& P);
#endif // 