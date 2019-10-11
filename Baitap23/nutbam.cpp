#include "stdafx.h"
#include "nutbam.h"


nutbam::nutbam()
{
}
void nutbam::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1; y1 = my1;
	x2 = mx2; y2 = my2;
}
void nutbam::vehinh(CClientDC *pDC, int n, int t, int m)
{
	hcn.tomau(pDC, n, t, m);

	hcn.thietlap(x1, y1, x2, y2);
	hcn.vehinh(pDC);
}
void nutbam::venutPT(CClientDC *pDC, int n, int t, int m)
{
	hcn.tomau(pDC, n, t, m);

	pDC->Ellipse(x1, y1, x2, y2);
	pDC->MoveTo(x1 + (x2 - x1) / 2, y1 + 6); pDC->LineTo(x1 + (x2 - x1) / 2, y2 - 6);
	pDC->MoveTo(x1 + 6, y1 + (y2 - y1) / 2); pDC->LineTo(x2 - 7, y1 + (y2 - y1) / 2);
}
void nutbam::venutTN(CClientDC *pDC, int n, int t, int m)
{
	hcn.tomau(pDC, n, t, m);

	pDC->Ellipse(x1, y1, x2, y2);
	pDC->MoveTo(x1 + 6, y1 + (y2 - y1) / 2); pDC->LineTo(x2 - 7, y1 + (y2 - y1) / 2);
}

int nutbam::chonhinh(CPoint p)
{
	int kt = 0;
	if (p.x > x1&&p.x<x2&&p.y>y1&&p.y < y2)
		kt = 1;
	return kt;
}
void nutbam::venutlen(CClientDC *pDC, int n, int t, int m)
{
	hcn.tomau(pDC, n, t, m);
	pDC->Rectangle(x1, y1, x2, y2);
	hcn.tomau(pDC, 0, 2, 2);
	pDC->MoveTo(x1 + 8, y2 - 8); pDC->LineTo(x1 + 15, y1 + 8);
	pDC->MoveTo(x2 - 8, y2 - 8); pDC->LineTo(x1 + 15, y1 + 8);
}
void nutbam::venutxuong(CClientDC *pDC, int n, int t, int m)
{
	hcn.tomau(pDC, n, t, m);
	pDC->Rectangle(x1, y1, x2, y2);
	hcn.tomau(pDC, 0, 2, 2);
	pDC->MoveTo(x1 + 8, y1 + 8); pDC->LineTo(x1 + 15, y2 - 8);
	pDC->MoveTo(x2 - 8, y1 + 8); pDC->LineTo(x1 + 15, y2 - 8);
}
void nutbam::venutphai(CClientDC *pDC, int n, int t, int m)
{
	hcn.tomau(pDC, n, t, m);
	pDC->Rectangle(x1, y1, x2, y2);
	hcn.tomau(pDC, 0, 2, 2);
	pDC->MoveTo(x1 + 8, y1 + 8); pDC->LineTo(x2 - 8, y1 + 15);
	pDC->MoveTo(x1 + 8, y2 - 8); pDC->LineTo(x2 - 8, y1 + 15);
}
void nutbam::venuttrai(CClientDC *pDC, int n, int t, int m)
{
	hcn.tomau(pDC, n, t, m);
	pDC->Rectangle(x1, y1, x2, y2);
	hcn.tomau(pDC, 0, 2, 2);
	pDC->MoveTo(x2 - 8, y1 + 8); pDC->LineTo(x1 + 8, y1 + 15);
	pDC->MoveTo(x2 - 8, y2 - 8); pDC->LineTo(x1 + 8, y1 + 15);
}
nutbam::~nutbam()
{
}
