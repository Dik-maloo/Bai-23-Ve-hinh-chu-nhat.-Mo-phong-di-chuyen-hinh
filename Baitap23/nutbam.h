#pragma once
#include "hinh.h"
#include "mau.h"
#include "hcn.h"

class nutbam :public hinh
{
private:
	int x1, x2, y1, y2;
public:
	hcn hcn;
	void thietlap(int mx1, int my1, int mx2, int my2);
	void vehinh(CClientDC *pDC, int n, int t, int m);
	int chonhinh(CPoint p);
	void venutPT(CClientDC *pDC, int n, int t, int m);
	void venutTN(CClientDC *pDC, int n, int t, int m);
	void venutlen(CClientDC *pDC, int n, int t, int m);
	void venutxuong(CClientDC *pDC, int n, int t, int m);
	void venuttrai(CClientDC *pDC, int n, int t, int m);
	void venutphai(CClientDC *pDC, int n, int t, int m);
	nutbam();
	~nutbam();
};

