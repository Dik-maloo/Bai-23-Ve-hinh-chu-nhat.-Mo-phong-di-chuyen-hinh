#pragma once
class hinh
{
public:
	virtual void vehinh(CClientDC *pDC);
	virtual void tomau(CClientDC *pDC, int n, int t, int m);
	virtual int chonhinh(CPoint p);
	virtual void keovehinh(CClientDC *pDC, CPoint p1, CPoint p2);

	virtual void dichuyen(CClientDC *pDC, CPoint p1, CPoint p2);
	virtual void dichuyenxuong(CClientDC *pDC);
	virtual void dichuyenlen(CClientDC *pDC);
	virtual void dichuyentrai(CClientDC *pDC);
	virtual void dichuyenphai(CClientDC *pDC);

	virtual void phongtovavehinh(CClientDC *pDC);
	virtual void thunhovavehinh(CClientDC *pDC);
	hinh();
	~hinh();
};

