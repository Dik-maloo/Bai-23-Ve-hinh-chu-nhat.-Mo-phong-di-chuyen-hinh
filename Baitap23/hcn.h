#pragma once
#include "hinh.h"
#include "mau.h"
class hcn :public hinh
{
public:
	int x1, x2, y1, y2;
	hcn(CPoint p1, CPoint p2);
	mau mau;
	void thietlap(int mx1, int my1, int mx2, int my2);
	void vehinh(CClientDC *pDC);
	int chonhinh(CPoint p);
	void tomau(CClientDC *pDC, int n, int t, int m);

	void keovehinh(CClientDC *pDC, CPoint p1, CPoint p2);
	void phongto();
	void phongtovavehinh(CClientDC *pDC);
	void thunho();
	void thunhovavehinh(CClientDC *pDC);

	void dichuyen(CClientDC *pDC, CPoint p1, CPoint p2);
	void dichuyenxuong(CClientDC *pDC);
	void dichuyenlen(CClientDC *pDC);
	void dichuyentrai(CClientDC *pDC);
	void dichuyenphai(CClientDC *pDC);
	hcn();
	~hcn();
};

