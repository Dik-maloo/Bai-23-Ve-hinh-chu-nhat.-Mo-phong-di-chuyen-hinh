#include "stdafx.h"
#include "hcn.h"


hcn::hcn()
{
}
hcn::hcn(CPoint p1, CPoint p2)
{
	x1 = p1.x;
	y1 = p1.y;
	x2 = p2.x;
	y2 = p2.y;
}
void hcn::thietlap(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}
void hcn::vehinh(CClientDC *pDC)
{
	pDC->Rectangle(x1, y1, x2, y2);
}
int hcn::chonhinh(CPoint p)
{
	int kt = 0;
	if (p.x > x1&&p.x<x2&&p.y>y1&&p.y < y2)
		kt = 1;
	return kt;
}
//---------------------------------------------------------------
//--------- thay doi kich thuoc hinh khi keo canh -----------
void hcn::keovehinh(CClientDC *pDC, CPoint p1, CPoint p2)
{

	mau.mauvien(1, 2, pDC);
	pDC->Rectangle(x1, y1, x2, y2);
	//keo canh ben phai
	if (p1.x > x2 - 10 && p1.x < x2 + 7)
		if (p2.x > x2)
		{
			thietlap(x1, y1, x2 + (p2.x - x2), y2);

		}
		else
		{
			thietlap(x1, y1, x2 - (x2 - p2.x), y2);
		}
	//keo canh ben duoi
	if (p1.y > y2 - 10 && p1.y < y2 + 7)
		if (p2.y > y2)
		{
			thietlap(x1, y1, x2, y2 + (p2.y - y2));
		}
		else
		{
			thietlap(x1, y1, x2, y2 - (y2 - p2.y));
		}
	//keo canh ben tren 

	if (p1.y > y1 - 7 && p1.y < y1 + 10)
		if (p2.y > y1)
		{
			thietlap(x1, y1 + (p2.y - y1), x2, y2);
		}
		else
		{
			if (p2.y > 60)
				thietlap(x1, y1 - (y1 - p2.y), x2, y2);
		}
	//keo canh ben trai
	if (p1.x > x1 - 7 && p1.x < x1 + 10)
		if (p2.x > x1)
		{
			thietlap(x1 + (p2.x - x1), y1, x2, y2);

		}
		else
		{
			thietlap(x1 - (x1 - p2.x), y1, x2, y2);
		}
	tomau(pDC, 4, 1, 4);
	vehinh(pDC);

}
//-----------------------------------------------------------------
//------------ phong to hinh --------------
void hcn::phongto()
{
	x1 -= 10; y1 -= 10; x2 += 10; y2 += 10;

}
void hcn::phongtovavehinh(CClientDC *pDC)
{
	if (y1 > 67)
	{
		tomau(pDC, 0, 1, 2);
		vehinh(pDC);
		phongto();
		thietlap(x1, y1, x2, y2);
		tomau(pDC, 4, 1, 4);
		vehinh(pDC);
	}

}
//------------- thu nho hinh ---------------
void hcn::thunho()
{
	x1 += 10; y1 += 10; x2 -= 10; y2 -= 10;
}
void hcn::thunhovavehinh(CClientDC *pDC)
{
	if (x2 - x1 > 0 && y2 - y1 > 0)
	{
		tomau(pDC, 0, 1, 2);
		vehinh(pDC);
		thunho();
		thietlap(x1, y1, x2, y2);
		tomau(pDC, 4, 1, 4);
		vehinh(pDC);
	}

}
//-----------------------------------------------------------------------
void hcn::tomau(CClientDC *pDC, int n, int t, int m)
{
	mau.maunen(n, pDC);
	mau.mauvien(t, m, pDC);
}
//------------------------------------------------------------------------
//---------- di chuyen khi keo tha chuot ---------
void hcn::dichuyen(CClientDC *pDC, CPoint p1, CPoint p2)
{
	if (p1.x > x1 + 15 && p1.x < x2 - 15 && p1.y>y1 + 15 && p1.y < y2 - 15&&p2.y>60)
	{
		tomau(pDC, 0, 1, 2);
		vehinh(pDC);

		x1 = p2.x - (p1.x - x1);
		y1 = p2.y - (p1.y - y1);
		x2 = p2.x + (x2 - p1.x);
		y2 = p2.y + (y2 - p1.y);

		thietlap(x1, y1, x2, y2);
		tomau(pDC, 4, 1, 4);
		vehinh(pDC);
	}
}
//---------- di chuyen sang phai --------------
void hcn::dichuyenphai(CClientDC *pDC)
{
	int i = 0;
	while (i < 3)
	{
		tomau(pDC, 0, 1, 2);
		vehinh(pDC);
		thietlap(x1 + 5, y1, x2 + 5, y2);
		tomau(pDC, 4, 1, 4);
		vehinh(pDC);
		Sleep(100);
		i++;
	}
}
//----------- di chuyen xuong ------------------
void hcn::dichuyenxuong(CClientDC *pDC)
{
	int i = 0;
	while (i < 3)
	{
		tomau(pDC, 0, 1, 2);
		vehinh(pDC);
		thietlap(x1, y1 + 5, x2, y2 + 5);
		tomau(pDC, 4, 1, 4);
		vehinh(pDC);
		Sleep(100);
		i++;
	}
}
//----------- di chuyen trai -------------------
void hcn::dichuyentrai(CClientDC *pDC)
{
	int i = 0;
	while (i < 3)
	{
		tomau(pDC, 0, 1, 2);
		vehinh(pDC);
		thietlap(x1 - 5, y1, x2 - 5, y2);
		tomau(pDC, 4, 1, 4);
		vehinh(pDC);
		Sleep(100);
		i++;
	}
}
//------------ di chuyen len --------------------
void hcn::dichuyenlen(CClientDC *pDC)
{
	int i = 0;

	if (y1 > 80)
		while (i < 3)
		{
			tomau(pDC, 0, 1, 2);
			vehinh(pDC);
			thietlap(x1, y1 - 5, x2, y2 - 5);
			tomau(pDC, 4, 1, 4);
			vehinh(pDC);
			Sleep(100);
			i++;
		}
}
hcn::~hcn()
{
}
