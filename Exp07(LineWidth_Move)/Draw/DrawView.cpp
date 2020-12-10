// DrawView.cpp : implementation of the CDrawView class
//


#include "stdafx.h"
#include "Draw.h"
#include <math.h>

#include "DrawDoc.h"
#include "DrawView.h"
#define ROUND(a) int(a+0.5)
#include "WidthDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	//{{AFX_MSG_MAP(CDrawView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_LINEWIDTH, OnLinewidth)
	ON_COMMAND(IDM_DDALINE, OnDdaline)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawView construction/destruction

CDrawView::CDrawView()
{
	// TODO: add construction code here
	m_lineWidth=1;

}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView drawing

void CDrawView::OnDraw(CDC* pDC)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView printing

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawView diagnostics

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawView message handlers

void CDrawView::DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
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

void CDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptStart=point;
	m_ptArray.Add(m_ptStart);
	
	CView::OnLButtonDown(nFlags, point);
}

void CDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	
}

void CDrawView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default


	
	CDC *pDC=GetDC();
	for(int i=0;i<m_ptArray.GetSize()-1;i++)
	{
		CPoint p1=(CPoint)m_ptArray.GetAt(i);
		CPoint p2=(CPoint)m_ptArray.GetAt(i+1);
        DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(0,0,255));
		switch(m_mode)
		{
		    case 1:	DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(0,0,255));break;
		    case 2: DDAWidthLine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(0,0,255));break;
		    default:break;
		}
	
	}

	m_ptArray.RemoveAll();
	ReleaseDC(pDC);
	CView::OnLButtonUp(nFlags, point);
	
	CView::OnLButtonDblClk(nFlags, point);
}



void CDrawView::OnLinewidth() 
{
	// TODO: Add your command handler code here
	m_mode=2;
    CWidthDlg dlg;
	if(IDOK==dlg.DoModal())
	{
		m_lineWidth=dlg.m_widthDlg;
	}
	
}

void CDrawView::DDAWidthLine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
// 	double x,y,e,dx,dy;
// 	dx=x2-x1;
// 	dy=y2-y1;
// 	e=(fabs(dx)>fabs(dy))?fabs(dx):fabs(dy);
// 	dx=dx/e;dy=dy/e;
// 	x=x1;y=y1;
// 	for(int i=0;i<e;i++)
// 	{
// 		//pDC->SetPixel(ROUND(x),ROUND(y),color);
// 		for(int j=(int)(1-m_lineWidth)/2;j<=(int)(m_lineWidth/2);j++)//线宽，一半放在线上，一半在线下
// 		{
// 			for(int k=(int)((1-m_lineWidth)/2);k<=(int)(m_lineWidth/2);k++)
// 			{
// 				pDC->SetPixel(ROUND(x)+j,ROUND(y)+k,color);
// 
// 			}
// 		}
// 		x+=dx;
// 		y+=dy;
// 	}
	//基于DDALine
	double dx, dy, e, x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	e = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= e; 
	dy /= e;
	x = x1;
	y = y1;
	for (int i = 1; i <= e; i++)
	{
		//pDC->SetPixel(int(x + 0.5), int(y + 0.5), color);
		for(int j = (int)(1-m_lineWidth)/2;j <= (int)(m_lineWidth)/2;j++)//输入奇数时取整
		{
			for (int k = (int)(1-m_lineWidth)/2;k <= (int)(m_lineWidth)/2;k++)
			{
				pDC->SetPixel(int(x + 0.5) + j, int(y + 0.5) + k, color);//包含进j、k值
			}
		}
		x += dx;
		y += dy;
	}


}

void CDrawView::OnDdaline() 
{
	// TODO: Add your command handler code here
	m_mode=1;
}
