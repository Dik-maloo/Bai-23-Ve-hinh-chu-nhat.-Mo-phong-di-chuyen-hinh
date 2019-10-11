#include "stdafx.h"
#include "mau.h"


mau::mau()
{
}
void mau::maunen(int n, CClientDC *pDC)
{
	CBrush *oldB, *b0, *b1, *b2, *b3, *b4;
	b0 = new CBrush(RGB(255, 255, 255));
	b1 = new CBrush(RGB(0, 0, 0));
	b2 = new CBrush(RGB(90, 90, 90));
	b3 = new CBrush(RGB(54, 54, 54));
	b4 = new CBrush(RGB(162, 0, 124));
	if (n == 0)
		oldB = pDC->SelectObject(b0);
	if (n == 1)
		oldB = pDC->SelectObject(b1);
	if (n == 2)
		oldB = pDC->SelectObject(b2);
	if (n == 3)
		oldB = pDC->SelectObject(b3);
	if (n == 4)
		oldB = pDC->SelectObject(b4);

}
void mau::mauvien(int m, int n, CClientDC *pDC)
{
	CPen *oldP, *p1, *p2, *p3, *p4;
	p1 = new CPen(PS_SOLID, m, RGB(0, 0, 0));
	p2 = new CPen(PS_SOLID, m, RGB(255, 255, 255));
	p3 = new CPen(PS_SOLID, m, RGB(54, 54, 54));
	p4 = new CPen(PS_SOLID, m, RGB(162, 0, 124));
	if (n == 1)
		oldP = pDC->SelectObject(p1);
	if (n == 2)
		oldP = pDC->SelectObject(p2);
	if (n == 3)
		oldP = pDC->SelectObject(p3);
	if (n == 4)
		oldP = pDC->SelectObject(p4);
}
mau::~mau()
{
}
