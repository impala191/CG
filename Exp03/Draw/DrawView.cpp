// DrawView.cpp : implementation of the CDrawView class
//

#include "stdafx.h"
#include "Draw.h"

#include "DrawDoc.h"
#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "math.h"
#define ROUND(a) int (a+0.5)

/////////////////////////////////////////////////////////////////////////////
// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	//{{AFX_MSG_MAP(CDrawView)
	ON_COMMAND(IDM_COLOR, OnColor)
	ON_COMMAND(IDM_MIDLINE, OnMidline)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
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
	m_model=0;
	m_color=(255,255,255);
	m_ptStart=m_ptEnd=(0,0);


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
	/*
	if(0==m_model)
	{
		DDALine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);
	}
	Invalidate(FALSE);
	*/
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

void CDrawView::OnColor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if(IDOK==dlg.DoModal())
	{
		m_color=dlg.GetColor();
	}
}

void CDrawView::OnMidline() 
{
	// TODO: Add your command handler code here
	m_model=2;
	
}

void CDrawView::OnDdaline() 
{
	// TODO: Add your command handler code here
	m_model=1;
	
}

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
	
	CView::OnLButtonDown(nFlags, point);
	m_ptStart=point;
}

void CDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonUp(nFlags, point);
	m_ptEnd=point;
    CDC *pDC=GetDC();
	switch(m_model)
	{
		case 1:	DDALine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);break;
		case 2: MIDLine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);break;
		default:	MessageBox("选择画线类型");
	}
			
    ReleaseDC(pDC);
	/*if(0==m_model)
	{
		CDC *pDC=GetDC();
		DDALine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);
		ReleaseDC(pDC);
	}
	*/
}



void CDrawView::MIDLine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	int a,b,delta1,delta2,d,x,y;
	if(x1==x2)
	{
		if(y1<y2)
		{
			for(int i=y1;i<=y2;i++)
				pDC->SetPixel(x1,i,color);
		}
		else 
		{
			for(int i=y2;i<=y1;i++)
				pDC->SetPixel(x1,i,color);
		}
		return;
	}
	BOOL m=(fabs(y2-y1)<=(x2-x1));
	//将角度的大小比较转为边的比较，来确定是x自增还是y自增的情况
	if(x1>x2)
	{
		d=x1;x1=x2;x2=d;
		d=y1;y1=y2;y2=d;
	}
    a=y1-y2;
	b=x2-x1;
	x=x1;
	y=y1;
	pDC->SetPixel(x,y,color);
    if(m) 
	//m=1,即deltaY<deltaX,斜率小于1以x为自增量（始终步长+1）
	{
		if(y1<y2)//从下往上画，斜率大于0
		{
			d=2*a-b;
			delta1=2*a;
			delta2=2*(a+b);
			while(x<x2)
			{
				if(d<0)
				{
					x++;
					y++;
					d+=delta1;
				}
				else
				{
					x++;
					d+=delta2;
				}
				pDC->SetPixel(x,y,color);
			}
		}
		else
		{
			d=2*a-b;
			delta1=2*a;
			delta2=2*a*(a-b);
			while(x<x2)
			{
				if(d<0)
				{
					x++;
					d+=delta1;
				}
				else
				{
					x++;
					y--;
					d+=delta2;
				}
				pDC->SetPixel(x,y,color);
			}
		}
	}
	else//斜率大于1
	{
		if(y1<y2)
		{
			d=a+2*b;
			delta1=2*b;
			delta2=2*(a+b);
			while(y<y2)
			{
				if(d<0)
				{
					y++;
					d+=delta1;
				}
				else
				{
					y++;
					x++;
					d+=delta2;
				}
				pDC->SetPixel(x,y,color);
			}
		}
		else
		{
			d=a-2*b;
			delta1=(-2)*b;
			delta2=2*(a-b);
			while(y>y2)
			{
				if(d<0)
				{
					y--;
					x++;
					d+=delta2;
				}
				else
				{
					y--;
					d+=delta1;
				}
			}
			pDC->SetPixel(x,y,color);
		}
	}

}
