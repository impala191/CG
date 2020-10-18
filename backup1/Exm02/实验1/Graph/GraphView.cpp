// GraphView.cpp : implementation of the CGraphView class
//

#include "stdafx.h"
#include "Graph.h"

#include "GraphDoc.h"
#include "GraphView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "math.h"
#include "DIgColor.h"

/////////////////////////////////////////////////////////////////////////////
// CGraphView

IMPLEMENT_DYNCREATE(CGraphView, CView)

BEGIN_MESSAGE_MAP(CGraphView, CView)
	//{{AFX_MSG_MAP(CGraphView)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_COLOR, OnColor)
	ON_COMMAND(IDM_DDALINE, OnDdaline)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphView construction/destruction

CGraphView::CGraphView()
{
	// TODO: add construction code here

}

CGraphView::~CGraphView()
{
	m_ptStart=m_ptEnd=(0,0);
	drawType=0;
	m_Red=m_Green=m_Blue=0;
}

BOOL CGraphView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGraphView drawing

void CGraphView::OnDraw(CDC* pDC)
{
	pDC->TextOut(490,450,"Sicuan Normal University!");
	
	CGraphDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//正方形：
 /* DDALine(pDC,50,50,50,150,RGB(0,0,255));
    DDALine(pDC,50,150,150,150,RGB(255,0,255));
	DDALine(pDC,150,150,150,50,RGB(255,255,0));
	DDALine(pDC,150,50,50,50,RGB(0,255,0));
*/
   
    DDALine(pDC,50,50,350,60,RGB(0,0,255));
	DDALine(pDC,350,60,350,160,RGB(0,0,255));
	DDALine(pDC,350,160,60,150,RGB(0,0,255));
	DDALine(pDC,60,150,60,450,RGB(0,0,255));
	DDALine(pDC,145,153,145,450,RGB(0,0,255));
	DDALine(pDC,180,200,180,450,RGB(0,0,255));
	DDALine(pDC,180,200,350,160,RGB(0,0,255));

	DDALine(pDC,800,60,1100,50,RGB(0,0,255));
	DDALine(pDC,1100,50,1100,450,RGB(0,0,255));
    DDALine(pDC,800,60,800,160,RGB(0,0,255));
	DDALine(pDC,800,160,1090,150,RGB(0,0,255));
	//DDALine(pDC,1090,150,1090,450,RGB(0,0,255));
	DDALine(pDC,1000,153,1000,450,RGB(0,0,255));
    DDALine(pDC,970,200,800,160,RGB(0,0,255));
	DDALine(pDC,970,200,970,450,RGB(0,0,255));

	DDALine(pDC,300,450,850,450,RGB(0,0,255));
	DDALine(pDC,300,450,320,400,RGB(0,0,255));
	DDALine(pDC,850,450,830,400,RGB(0,0,255));
	DDALine(pDC,320,400,830,400,RGB(0,0,255));
	DDALine(pDC,280,450,280,300,RGB(0,255,0));
	DDALine(pDC,870,450,870,300,RGB(0,255,0));


/*	DDALine(pDC,250,50,250,150,RGB(0,0,255));
	DDALine(pDC,250,150,240,150,RGB(0,0,255));
	DDALine(pDC,240,150,240,60,RGB(0,0,255));
	DDALine(pDC,240,60,230,50,RGB(0,0,255));
	DDALine(pDC,230,50,250,50,RGB(0,0,255));

	DDALine(pDC,70,50,230,50,RGB(0,0,255));
*/

}

/////////////////////////////////////////////////////////////////////////////
// CGraphView printing

BOOL CGraphView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraphView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGraphView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGraphView diagnostics

#ifdef _DEBUG
void CGraphView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphDoc* CGraphView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphDoc)));
	return (CGraphDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraphView message handlers

void CGraphView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    
	MessageBox("Hello The World!");
	CView::OnLButtonDblClk(nFlags, point);
}

void CGraphView::DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	double dx,dy,e,x,y;
	dx=x2-x1;
	dy=y2-y1;
	e=(fabs(dx)>fabs(dy))?fabs(dx):fabs(dy);
	dx/=e;
	dy/=e;
	x=x1;
	y=y1;
	for(int i=1;i<=e;i++)
	{
		pDC->SetPixel((int)(x+0.5),(int)(y+0.5),color);
		x+=dx;
		y+=dy;

	}
}

void CGraphView::OnLButtonDown(UINT nFlags, CPoint point) 
{    
	//整形的标记；nflags是地点；cPoint point是事件
	// TODO: Add your message handler code here and/or call default
	m_ptStart=point;
	CView::OnLButtonDown(nFlags, point);
}

void CGraphView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptEnd=point;
	if(1==drawType)
	{
		CDC *pDC=GetDC();
	
		
	//CDC *pDC=GetDC(this);
	DDALine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,RGB(m_Red,m_Green,m_Blue));
    //DDALine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,RGB(255,0,0));
	//RGB设置了255，0，0即用红色的线画图
	ReleaseDC(pDC);
	}
	CView::OnLButtonUp(nFlags, point);
	
}

void CGraphView::OnColor() 
{
	// TODO: Add your command handler code here
   CDIgColor dlg;
   if(IDOK==dlg.DoModal())
   {
	   m_Red=dlg.m_DlgRed;
	   m_Green=dlg.m_DlgGreen;
	   m_Blue=dlg.m_DlgBlue;
	   UpdateData();
   }
	
}

void CGraphView::OnDdaline() 
{
	// TODO: Add your command handler code here
	drawType=1;
	
}
