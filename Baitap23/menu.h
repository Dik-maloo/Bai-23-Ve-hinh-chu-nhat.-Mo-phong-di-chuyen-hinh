#pragma once
#include "hcn.h"
#include "mau.h"
class menu
{
private:
	int x1, x2, y1, y2;
public:
	hcn hcn;
	void thietlap(int mx1, int my1, int mx2, int my2);
	void vemenu(CClientDC *pDC, int n, int t, int m);
	menu();
	~menu();
};

