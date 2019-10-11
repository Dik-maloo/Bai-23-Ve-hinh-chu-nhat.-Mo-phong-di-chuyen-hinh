
// Baitap23View.cpp : implementation of the CBaitap23View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Baitap23.h"
#endif

#include "Baitap23Doc.h"
#include "Baitap23View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBaitap23View

IMPLEMENT_DYNCREATE(CBaitap23View, CView)

BEGIN_MESSAGE_MAP(CBaitap23View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CBaitap23View construction/destruction

CBaitap23View::CBaitap23View() noexcept
{
	// TODO: add construction code here
	b1.thietlap(0, 0, 1400, 60);
	b2.thietlap(150, 10, 500, 50);

	nut1.thietlap(160, 20, 190, 40);		//thiet lap nut ve hinh
	nut2.thietlap(210, 20, 230, 40);		//thiet lap nut phong to
	nut3.thietlap(250, 20, 270, 40);		//thiet lap nut thu nho

	nut5.thietlap(290, 15, 320, 45);
	nut6.thietlap(340, 15, 370, 45);
	nut7.thietlap(390, 15, 420, 45);
	nut8.thietlap(440, 15, 470, 45);

	dk = 0;			//dieu kien cua nut ve hinh de ve hinh				
	dk1 = 0;		//dieu kien de phong to thu nho	
}

CBaitap23View::~CBaitap23View()
{
}

BOOL CBaitap23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CBaitap23View drawing

void CBaitap23View::OnDraw(CDC* /*pDC*/)
{
	CBaitap23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC pDC(this);
	//--  Ve khung menu -------
	b1.vemenu(&pDC, 3, 2, 1);
	b2.vemenu(&pDC, 2, 2, 1);

	nut1.vehinh(&pDC, 1, 1, 1);		//ve nut ve hinh
	nut2.venutPT(&pDC, 1, 2, 2);	//ve nut phong to
	nut3.venutTN(&pDC, 1, 2, 2);	//ve nut thu nho
	nut5.venuttrai(&pDC, 1, 1, 1);
	nut6.venutphai(&pDC, 1, 1, 1);
	nut7.venutlen(&pDC, 1, 1, 1);
	nut8.venutxuong(&pDC, 1, 1, 1);
	// TODO: add draw code for native data here
}


// CBaitap23View printing

BOOL CBaitap23View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaitap23View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaitap23View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CBaitap23View diagnostics

#ifdef _DEBUG
void CBaitap23View::AssertValid() const
{
	CView::AssertValid();
}

void CBaitap23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaitap23Doc* CBaitap23View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaitap23Doc)));
	return (CBaitap23Doc*)m_pDocument;
}
#endif //_DEBUG


// CBaitap23View message handlers


void CBaitap23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p1.x = point.x;
	p1.y = point.y;
	CClientDC pDC(this);

	//--- Tao dieu kien bam nut ve hinh ---
	if (nut1.chonhinh(p1) == 1)
	{
		if (dk == 0)			//chua bam nut ve hinh
		{
			dk = 1;
			nut1.vehinh(&pDC, 3, 2, 2);
		}
		else					//da bam nut ve hinh
		{
			dk = 0;
			nut1.vehinh(&pDC, 1, 2, 1);
			nut1.vehinh(&pDC, 1, 1, 1);
		}

	}

	//----- to mau khi bam nut -------
	if (nut2.chonhinh(p1) == 1)
	{
		nut2.venutPT(&pDC, 3, 2, 2);
	}
	if (nut3.chonhinh(p1) == 1)
	{
		nut3.venutTN(&pDC, 3, 2, 2);
	}
	if (nut5.chonhinh(p1) == 1)
	{
		nut5.venuttrai(&pDC, 3, 2, 2);
	}
	if (nut6.chonhinh(p1) == 1)
	{
		nut6.venutphai(&pDC, 3, 2, 2);
	}
	if (nut7.chonhinh(p1) == 1)
	{
		nut7.venutlen(&pDC, 3, 2, 2);
	}
	if (nut8.chonhinh(p1) == 1)
	{
		nut8.venutxuong(&pDC, 3, 2, 2);
	}
	CView::OnLButtonDown(nFlags, point);
}


void CBaitap23View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p2.x = point.x;
	p2.y = point.y;
	CClientDC pDC(this);

	//----- to mau khi bam nut -------
	if (nut2.chonhinh(p2) == 1)
	{
		nut2.venutPT(&pDC, 1, 2, 2);
	}
	if (nut3.chonhinh(p2) == 1)
	{
		nut3.venutTN(&pDC, 1, 2, 2);
	}
	if (nut5.chonhinh(p1) == 1)
	{
		nut5.venuttrai(&pDC, 1, 2, 1);
	}
	if (nut6.chonhinh(p1) == 1)
	{
		nut6.venutphai(&pDC, 1, 2, 1);
	}
	if (nut7.chonhinh(p1) == 1)
	{
		nut7.venutlen(&pDC, 1, 2, 1);
	}
	if (nut8.chonhinh(p1) == 1)
	{
		nut8.venutxuong(&pDC, 1, 2, 1);
	}
	//----------------------------------------------------------------------
	//---------- ve hinh --------------
	if (p1.y > 60 && p2.y > 60)
		if (dk == 1)					//khi bam vao nut ve hinh 
		{
			A[n] = new hcn(p1, p2);
			A[n]->tomau(&pDC, 4, 1, 4);
			A[n]->vehinh(&pDC);
			n++;
			dk1 = 1;					//dieu kien dung phong to thu nho
		}

	//thay doi kich thuoc hinh khi keo cac canh HCN
	if (dk == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (A[i]->chonhinh(p1) == 1)
			{
				A[i]->keovehinh(&pDC, p1, p2);
			}
		}
	}

	//---------- Chon hinh da ve ------------
	for (int i = 0; i < n; i++)
	{
		if (A[i]->chonhinh(p1) == 1)
		{
			kt = i;
		}
	}
	//--------------------------------------------------------------------
	//---------- Phong to hinh --------
	if (dk == 0)
	{
		if (dk1 == 1)
			if (nut2.chonhinh(p1) == 1)
			{
				A[kt]->phongtovavehinh(&pDC);
			}
	}
	//---------- Thu nho hinh ---------
	if (dk == 0)
	{
		if (dk1 == 1)
			if (nut3.chonhinh(p1) == 1)
			{
				A[kt]->thunhovavehinh(&pDC);
			}
	}

	//------------------------------------------------------------------
	//------- Di chuyen khi keo tha chuot -----
	if (dk == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (A[i]->chonhinh(p1) == 1)
			{
				A[i]->dichuyen(&pDC, p1, p2);
			}
		}
	}
	//----- di chuyen sang trai ----
	if (dk == 0)
	{
		if (dk1 == 1)
			if (nut5.chonhinh(p1) == 1)
			{
				A[kt]->dichuyentrai(&pDC);
			}
	}
	//------ di chuyen sang phai ---
	if (dk == 0)
	{
		if (dk1 == 1)
			if (nut6.chonhinh(p1) == 1)
			{
				A[kt]->dichuyenphai(&pDC);
			}
	}
	//------ di chuyen len -----------
	if (dk == 0)
	{
		if (dk1 == 1)
			if (nut7.chonhinh(p1) == 1)
			{
				A[kt]->dichuyenlen(&pDC);
			}
	}
	//------ di chuyen xuong ------
	if (dk == 0)
	{
		if (dk1 == 1)
			if (nut8.chonhinh(p1) == 1)
			{
				A[kt]->dichuyenxuong(&pDC);
			}
	}
	CView::OnLButtonUp(nFlags, point);
}


void CBaitap23View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	keydown = nChar;
	CClientDC pDC(this);
	//------- bam di chuyen sang trai -------
	if (keydown == 37)
		if (dk == 0)
		{
			if (dk1 == 1)
				A[kt]->dichuyentrai(&pDC);
		}
	//------- bam di chuyen sang phai -------
	if (keydown == 39)
		if (dk == 0)
		{
			if (dk1 == 1)
				A[kt]->dichuyenphai(&pDC);
		}
	//--------- bam di chuyen len ----------- 
	if (keydown == 38)
		if (dk == 0)
		{
			if (dk1 == 1)
				A[kt]->dichuyenlen(&pDC);
		}
	//-------- bam di chuyen xuong ----------
	if (keydown == 40)
		if (dk == 0)
		{
			if (dk1 == 1)
				A[kt]->dichuyenxuong(&pDC);
		}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
