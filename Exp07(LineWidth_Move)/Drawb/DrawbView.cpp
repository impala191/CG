// DrawbView.cpp : implementation of the CDrawbView class
//

#include "stdafx.h"
#include "Drawb.h"

#include "DrawbDoc.h"
#include "DrawbView.h"
#define ROUND(a) int(a+0.5)
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawbView

IMPLEMENT_DYNCREATE(CDrawbView, CView)

BEGIN_MESSAGE_MAP(CDrawbView, CView)
	//{{AFX_MSG_MAP(CDrawbView)
	ON_COMMAND(IDM_MOVE, OnMove)
	ON_COMMAND(IDM_DDALINE, OnDdaline)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawbView construction/destruction

CDrawbView::CDrawbView()
{
	// TODO: add construction code here
	m_ptEnd=m_ptStart=(0,0);
	deltax=deltay=0;
	m_flag=true;

}

CDrawbView::~CDrawbView()
{
}

BOOL CDrawbView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawbView drawing

void CDrawbView::OnDraw(CDC* pDC)
{
	CDrawbDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//onDraw中系统会自动生成和销毁pDC

	CPoint p1,p2;
	for(int i=0;i<=m_ptArray.GetSize()-1;i++)
	{
		p1=(CPoint)m_ptArray.GetAt(i);
		if(i==m_ptArray.GetSize()-1)
		    p2=(CPoint)m_ptArray.GetAt(0);
		else
			p2=(CPoint)m_ptArray.GetAt(i+1);
		DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(255,0,0));
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDrawbView printing

BOOL CDrawbView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawbView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawbView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawbView diagnostics

#ifdef _DEBUG
void CDrawbView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawbView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawbDoc* CDrawbView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawbDoc)));
	return (CDrawbDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawbView message handlers

void CDrawbView::DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	double x,y,e,dx,dy;
	dx=x2-x1;
	dy=y2-y1;
	e=(fabs(dx)>fabs(dy))?fabs(dx):fabs(dy);
	dx=dx/e;dy=dy/e;
	x=x1;y=y1;
	for(int i=0;i<e;i++)
	{
		pDC->SetPixel(ROUND(x),ROUND(y),color);
		x+=dx;
		y+=dy;
	}
}

void CDrawbView::OnMove() 
{
	// TODO: Add your command handler code here
	m_mode=2;
	
}

void CDrawbView::OnDdaline() 
{
	// TODO: Add your command handler code here
	m_mode=1;
	
}

void CDrawbView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptStart=point;	
	//绘制多边形时才加点， mode=2时是移动图形，不记录点。
	if(1==m_mode)
	
	{
		if(m_flag==FALSE)
		{
			m_ptArray.RemoveAll();
			m_flag=true;
			m_ptArray.Add(m_ptStart);
		}
		else if(m_flag==TRUE)
        m_ptArray.Add(m_ptStart);
	}
	


	CView::OnLButtonDown(nFlags, point);
}

void CDrawbView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    m_flag=false;
	//m_ptArray.RemoveAll();
	CDC *pDC=GetDC();
	CPoint P1,P2;
	if(m_mode=1)
	{
		if(m_ptArray.GetSize()<=2)
		{
			return;
		}
        for(int i=0;i<=m_ptArray.GetSize()-1;i++)
		{
			P1=(CPoint)m_ptArray.GetAt(i);
			if(i==m_ptArray.GetSize()-1)
				P2=(CPoint)m_ptArray.GetAt(0);
			else
			    P2=(CPoint)m_ptArray.GetAt(i+1);
			DDALine(pDC,P1.x,P1.y,P2.x,P2.y,RGB(255,0,0));
		}
	}
//	m_ptArray.RemoveAll();
	
	ReleaseDC(pDC);
	
	CView::OnLButtonDblClk(nFlags, point);
}

void CDrawbView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptEnd=point;
	CPoint p1,p2;
	deltax=m_ptEnd.x-m_ptStart.x;
	deltay=m_ptEnd.y-m_ptStart.y;

	if(1==m_mode)
	{
		return;
	}
	if(2==m_mode)
	{
		for(int i=0;i<=m_ptArray.GetSize()-1;i++)
		{
			p1=(CPoint)m_ptArray.GetAt(i);
			p1.x+=deltax;
			p1.y+=deltay;
			m_ptArray.SetAt(i,p1);//setat，即放入，这里将p1刷新为添加了偏移量后的值。
			if(i==(m_ptArray.GetSize()-1))
			{
				p2=(CPoint)m_ptArray.GetAt(0);
				p2.x+=deltax;
				p2.y+=deltay;
				m_ptArray.SetAt(0,p2);
			}
			else
			{	
				p2=(CPoint)m_ptArray.GetAt(i+1);
				p2.x+=deltax;
				p2.y+=deltay;
				m_ptArray.SetAt(i+1,p2);
			}

		}
	}
	Invalidate();//重绘时系统自动调用onDraw这个函数
	
	CView::OnLButtonUp(nFlags, point);
}
