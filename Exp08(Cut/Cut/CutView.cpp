// CutView.cpp : implementation of the CCutView class
//

#include "stdafx.h"
#include "Cut.h"

#include "CutDoc.h"
#include "CutView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCutView

IMPLEMENT_DYNCREATE(CCutView, CView)

BEGIN_MESSAGE_MAP(CCutView, CView)
	//{{AFX_MSG_MAP(CCutView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(IDM_COHEN, OnCohen)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCutView construction/destruction

CCutView::CCutView()
{
	// TODO: add construction code here
	m_LBDown=FALSE;
	m_RBDown=FALSE;
	m_type_cut=TC_NONE;
	m_LTPoint =m_RBPoint=CPoint(0,0);

	m_Num_Ply=0;
	m_NumCliped_Ply=0;

}

CCutView::~CCutView()
{
}

BOOL CCutView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCutView drawing

void CCutView::OnDraw(CDC* pDC)
{
	CCutDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CCutView printing

BOOL CCutView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCutView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCutView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCutView diagnostics

#ifdef _DEBUG
void CCutView::AssertValid() const
{
	CView::AssertValid();
}

void CCutView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCutDoc* CCutView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCutDoc)));
	return (CCutDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCutView message handlers

void CCutView::ClearScreen()
{
	CClientDC dc(this);
	CRect window;//定义一个矩形的范围
	GetClientRect(window);//把当前客户区大小传给window。

	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Rectangle(window);

}

void CCutView::CorrectWindow()
{
	//规范一切绘制矩形的方式
	int x,y;
	if(m_LTPoint.x>m_RBPoint.x)
	{
		x=m_LTPoint.x;
		m_LTPoint.x=m_RBPoint.x;
		m_RBPoint.x=x;
	}
	if(m_LTPoint.y<m_RBPoint.y)
	{
		y=m_LTPoint.y;
		m_LTPoint.y=m_RBPoint.y;
		m_RBPoint.y=y;
	}

}

void CCutView::ShowLineSeg(CPoint BPoint, CPoint EPoint)
{
	
	CClientDC dc(this);
	dc.SetROP2(R2_NOT);
	dc.MoveTo(BPoint);
	dc.LineTo(EPoint);
}

void CCutView::Makecode(CPoint point, int &Code)
{
	int x=point.x;
	int y=point.y;
	Code=0;
	if(x<m_LTPoint.x)
        Code=1;
	else if(x>m_RBPoint.x)
	    Code=2;
	if(y<m_RBPoint.y)
		Code+=4;//???
	else if(y>m_LTPoint.y)
		Code+=8;//???
	//这里code不返回，而是通过引用变量&Code直接传出

}

void CCutView::Cohen_Sutherland(CPoint &BPoint, CPoint &EPoint)
{
	/*
	CPoint bPoint=BPoint;
	CPoint ePoint=EPoint;
	int c,cb,ce;
	int x,y;
	Makecode(bPoint,cb);
	Makecode(ePoint,ce);
	while(cb!=0||ce!=0)
	{
		if((cb&ce)!=0)
		{
			//如果是同一个点
			BPoint=EPoint;
			return;
		}
		c=cb;
		if(c==0)
			c=ce;
		if(c&1)
		{
			y=bPoint.y+(ePoint.y-bPoint.y)*(m_LTPoint.x-bPoint.x)/(ePoint.x-bPoint.x);
			x=m_LTPoint.x;
		}
		else if(c&2)
		{
			y=bPoint.y+(ePoint.y-bPoint.y)*(m_RBPoint.x-bPoint.x)/(ePoint.x-bPoint.x);
			x=m_RBPoint.x;
		}
		else if(c&4)
		{
			x=bPoint.x+(ePoint.x-bPoint.x)*(m_RBPoint.y-bPoint.y)/(ePoint.x-bPoint.x);
			y=m_RBPoint.y;
		}
		if(c&8)
		{
			x=bPoint.x+(ePoint.x-bPoint.x)*(m_LTPoint.y-bPoint.y)/(ePoint.x-bPoint.x);
			y=m_LTPoint.y;
		}
		if(c==cb)
		{
			bPoint=CPoint(x,y);
			Makecode(bPoint,cb);
		}
		else
		{
			ePoint=CPoint(x,y);
			Makecode(ePoint,ce);
		}
     	BPoint=bPoint;
		EPoint=ePoint;
	}
	*/
	



    CPoint bPoint=BPoint;
	CPoint ePoint=EPoint;
	int c,cb,ce;
    int x,y;
	Makecode(bPoint,cb);
	Makecode(ePoint,ce);
	while(cb!=0||ce!=0)
	{
      if ((cb&ce)!=0)
      {
		  BPoint=EPoint;
		  return;
      }
	  c=cb;
	  if(c==0)
		  c=ce;
	  if (c&1)
	  {
		  y=bPoint.y+(ePoint.y-bPoint.y)*(m_LTPoint.x-bPoint.x)/(ePoint.x-bPoint.x);
		  x=m_LTPoint.x;
	  }
	  else if (c&2)
	  {
		  y=bPoint.y+(ePoint.y-bPoint.y)*(m_RBPoint.x-bPoint.x)/(ePoint.x-bPoint.x);
          x=m_RBPoint.x;
	  }
	  if (c&4)
	  {
		  x=bPoint.x+(ePoint.x-bPoint.x)*(m_RBPoint.y-bPoint.y)/(ePoint.x-bPoint.x);
		  y=m_RBPoint.y;
	  }
	  if (c&8)
	  {
		  x=bPoint.x+(ePoint.x-bPoint.x)*(m_LTPoint.y-bPoint.y)/(ePoint.y-bPoint.y);
		  y=m_LTPoint.y;
	  }
	  if (c==cb)
	  {
		  bPoint=CPoint(x,y);
		  Makecode(bPoint,cb);
	  }
	  else
	  {
		  ePoint=CPoint(x,y);
		  Makecode(ePoint,ce);
	  }
	  BPoint=bPoint;
	  EPoint=ePoint;
	}
	
}

void CCutView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	switch(m_type_cut)
	{
	case TC_STRAIGHTLINE_COHEN:
		ClearScreen();
		m_LBDown=true;
		m_LTPoint=point;
		break;
	case TC_NONE:
		break;
	}
	
	CView::OnLButtonDown(nFlags, point);
}

void CCutView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	switch(m_type_cut)
	{
	    case TC_STRAIGHTLINE_COHEN:
			
			m_LBDown=FALSE;
			CorrectWindow();
			break;
		case TC_NONE:
			break;
	}

	
	CView::OnLButtonUp(nFlags, point);
}

void CCutView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	switch(m_type_cut)
	{
	case TC_STRAIGHTLINE_COHEN:
		m_RBDown=TRUE;
		m_BPoint=m_EPoint=point;
		break;
	case TC_NONE:
		break;
	}
	CView::OnRButtonDown(nFlags, point);
}

void CCutView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	switch(m_type_cut)
	{
	case TC_STRAIGHTLINE_COHEN:
	    m_RBDown=FALSE;
		ShowLineSeg(m_BPoint,m_EPoint);
		Cohen_Sutherland(m_BPoint,m_EPoint);
		ShowLineSeg(m_BPoint,m_EPoint);
		break;
	case TC_NONE:
		break;
	}
	
	CView::OnRButtonUp(nFlags, point);
}

void CCutView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	switch(m_type_cut)
	{
	    case TC_STRAIGHTLINE_COHEN:
			if(m_LBDown)
			{
				ClearScreen();
				m_RBPoint=point;
				dc.Rectangle(m_LTPoint.x,m_LTPoint.y,m_RBPoint.x,m_RBPoint.y);
			}
			if(m_RBDown)
			{
				dc.SetROP2(R2_NOT);
				dc.MoveTo(m_BPoint);
				dc.LineTo(m_EPoint);
				m_EPoint=point;
				dc.MoveTo(m_BPoint);
				dc.LineTo(m_EPoint);
			}
			break;
		case TC_NONE:
			break;
	}
	
	CView::OnMouseMove(nFlags, point);
}

void CCutView::OnCohen() 
{
	// TODO: Add your command handler code here
	m_type_cut=TC_STRAIGHTLINE_COHEN;
	
}
