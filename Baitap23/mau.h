#pragma once
#include "hinh.h"
class mau :public hinh
{
public:
	void maunen(int n, CClientDC *pDC);
	void mauvien(int m, int n, CClientDC *pDC);
	mau();
	~mau();
};

