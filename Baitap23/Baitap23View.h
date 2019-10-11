
// Baitap23View.h : interface of the CBaitap23View class
//

#pragma once
#include "hinh.h"
#include "hcn.h"
#include "mau.h"
#include "menu.h"
#include "nutbam.h"

class CBaitap23View : public CView
{
protected: // create from serialization only
	CBaitap23View() noexcept;
	DECLARE_DYNCREATE(CBaitap23View)

// Attributes
public:
	CBaitap23Doc* GetDocument() const;

// Operations
public:
	CPoint p1, p2;
	int dk, dk1, kt, keydown;				//cac bien dieu kien
	menu b1, b2;					//khai bao cac bien khung menu
	nutbam nut1, nut2, nut3, nut5, nut6, nut7, nut8;		//khai bao cac bien nut bam
	hinh *A[100];				//khai bao mang ve hinh
	int n = 0;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CBaitap23View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in Baitap23View.cpp
inline CBaitap23Doc* CBaitap23View::GetDocument() const
   { return reinterpret_cast<CBaitap23Doc*>(m_pDocument); }
#endif

