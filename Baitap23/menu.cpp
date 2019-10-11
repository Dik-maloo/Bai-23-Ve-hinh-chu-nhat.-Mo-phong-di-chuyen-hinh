#include "stdafx.h"
#include "menu.h"


menu::menu()
{
}
void menu::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1; y1 = my1;
	x2 = mx2; y2 = my2;
}
void menu::vemenu(CClientDC *pDC, int n, int t, int m)
{
	hcn.tomau(pDC, n, t, m);

	hcn.thietlap(x1, y1, x2, y2);
	hcn.vehinh(pDC);
}

menu::~menu()
{
}
