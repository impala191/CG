// DrawbView.cpp : implementation of the CDrawbView class
//

#include "stdafx.h"
#include "Drawb.h"

#include "DrawbDoc.h"
#include "DrawbView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include <math.h>

/////////////////////////////////////////////////////////////////////////////
// CDrawbView

IMPLEMENT_DYNCREATE(CDrawbView, CView)

BEGIN_MESSAGE_MAP(CDrawbView, CView)
	//{{AFX_MSG_MAP(CDrawbView)
	ON_WM_LBUTTONDOWN()
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

void CDrawbView::BHCircle(CDC *pDC, int x0, int y0, int R, COLORREF color)
{
	int x,y,p;
	x=0;y=R;p=3-(R<<1);

	for(;x<=y;x++)//八分之一的圆弧中
	{
		//关于x轴对称
		pDC->SetPixel(x+x0,y+y0,color);
		pDC->SetPixel(-x+x0,y+y0,color);
		pDC->SetPixel(x+x0,-y+y0,color);
		pDC->SetPixel(-x+x0,-y+y0,color);
		//关于y轴堆成
		pDC->SetPixel(y+x0,x+y0,color);
		pDC->SetPixel(-y+x0,x+y0,color);
		pDC->SetPixel(y+x0,-x+y0,color);
		pDC->SetPixel(-y+x0,-x+y0,color);

		if(p<0)
		{
			p+=((x<<2)+6);
		}
		else
		{
			p+=(((x-y)<<2)+10);
			y--;
		}
	}


}

void CDrawbView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptCenter =point;
	CView::OnLButtonDown(nFlags, point);
}

void CDrawbView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	m_ptRadius=point;
	double r=sqrt((m_ptRadius.x-m_ptCenter.x)*(m_ptRadius.x-m_ptCenter.x)+(m_ptRadius.y-m_ptCenter.y)*(m_ptRadius.y-m_ptCenter.y));
     BHCircle(&dc,m_ptCenter.x,m_ptCenter.y,int(r),RGB(255,0,0));

	ReleaseDC(&dc);

	
	CView::OnLButtonUp(nFlags, point);
}
