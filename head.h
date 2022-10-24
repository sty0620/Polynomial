#pragma once
#ifndef  HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h>
#include<time.h>
#include <conio.h>
#include<Windows.h>
typedef enum Status {
	Error,
	Success
} Status;
typedef struct Term {
	double xishu;//系数
	int zhishu;//指数
}Term;
typedef struct Poly {
	Term* elem;
	int length;
}Poly;
Status InitPoly(Poly& P);
Status CreatePoly(Poly& P);//从键盘输入创建
Status CreatAndMerge(Poly& P);
Status CreatePolyFromArrey(Poly& P, int MaxZhishu,double Xishu[]);//从数组中创建
int PolyLength(double xishu[], int MaxZhishu);//从数组中找到系数不为0的个数，用于创建Poly,其中＜0.001的舍去
Status DestoryPloy(Poly& P);//销毁
Status PrintPoly(Poly P);//遍历
Status PrintPolyOfIntrgral(Poly P);
Status AddPoly(Poly P1, Poly P2, Poly& ResultP);//相加
Status SubPoly(Poly P1, Poly P2, Poly& ResultP);//相减
Status MulPoly(Poly P1, Poly P2, Poly& ResultP);//相乘
Status DivPloy(Poly P1, Poly P2, Poly& ResultP, Poly& RemainderP);//相除
Status DiffPloy(Poly P, Poly& ResultP);//微分
Status IntrgralPloy(Poly P, Poly& ResultP);//积分
void SortPoly(Poly& P);//排序
void Qsort(Poly& P, int left, int right);
void MergePoly(Poly& P);
#endif // 
