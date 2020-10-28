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
	ON_WM_LBUTTONDBLCLK()
	ON_WM_KEYDOWN()
	ON_COMMAND(IDM_POLYLINE, OnPolyline)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(IDM_POLYGON, OnPolygon)
	ON_COMMAND(IDM_DASHLINE, OnDashline)
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
	m_model=4;
	
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
	m_ptEnd=point;
	m_ptArray.Add(point);
	
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
		case 4: MIDLine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);break;
		case 2: break;
		case 3: break;
		case 5:break;
		default:MessageBox("选择画线方式！");break;
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
    if(m) //m=1,即deltaY<deltaX,斜率小于1以x为自增量（始终步长+1）
	{
		if(y1<y2)//从下往上画，斜率大于0，小于1
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
					d+=delta2;
				}
				else
				{
					x++;
					d+=delta1;
				}
				pDC->SetPixel(x,y,color);
			}
		}
		else//斜率小于0大于-1
		{
			d=2*a-b;
			delta1=2*a;
			delta2=2*(a-b);
			while(x<x2)
			{
				if(d<0)
				{
					x++;
					d+=delta1;
				}
				else
				{
					y--;
					x++;
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
					x++;
					y--;
					d+=delta2;
				}
				else
				{
					y--;
					d+=delta1;
				}
			
				pDC->SetPixel(x,y,color);
			}
		}
	}

}

void CDrawView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//m_ptEnd=point;
	m_ptArray.Add(point);
	CDC *pDC=GetDC();
	//DDALine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);

	/*for(int i=0;i<m_ptArray.GetSize()-1;i++)
	{
		CPoint p1=m_ptArray.GetAt(i);
		CPoint p2=m_ptArray.GetAt(i+1);
		DDALine(pDC,p1.x,p1.y,p2.x,p2.y,m_color);
		
	}
	*/
	CPoint p1,p2;
	switch(m_model)
	{
	
	case 2:
		{
			for(int i=0;i<m_ptArray.GetSize()-1;i++)
			{
				CPoint p1=(CPoint)m_ptArray.GetAt(i);
				CPoint p2=(CPoint)m_ptArray.GetAt(i+1);
				DDALine(pDC,p1.x,p1.y,p2.x,p2.y,m_color);
				
			}  
		}	
		break;
	case 3:
		{
			if(m_ptArray.GetSize()<=2)
			{	
			    MessageBox("错误");
			    return;
			}
			for(int i=0;i<=m_ptArray.GetSize()-1;i++)
			{
				p1=m_ptArray.GetAt(i);
				if(i==(m_ptArray.GetSize()-1))
				{
					p2=(CPoint)m_ptArray.GetAt(0);
				}
				else
				p2=(CPoint)m_ptArray.GetAt(i+1);
				DDALine(pDC,p1.x,p1.y,p2.x,p2.y,m_color);
			}


		}
		break;

	case 5:
		{
			for(int i=0;i<m_ptArray.GetSize()-1;i++)
			{
				CPoint p1=(CPoint)m_ptArray.GetAt(i);
				CPoint p2=(CPoint)m_ptArray.GetAt(i+1);
				DashLine(pDC,p1.x,p1.y,p2.x,p2.y,m_color);			
			}  

		}
		break;
     default:MessageBox("选择画线类型");break;
	}


	ReleaseDC(pDC);
	m_ptArray.RemoveAll();

	CView::OnLButtonDblClk(nFlags, point);
}

void CDrawView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default

	if(VK_F2==nChar)
	{
		m_model=2;//折线
	}
	if(VK_F3==nChar)
	{
		m_model=3;//多边形
	}
	if(VK_F1==nChar)
	{
		m_model=1;	//DDAline画线
	}
	if(VK_F4==nChar)
	{
		m_model=4;//Midline画线
	}
	if(VK_F5==nChar)
	{
		m_model=5;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CDrawView::OnPolyline() 
{
	// TODO: Add your command handler code here
	//折线
	m_model=2;
	
}  
void CDrawView::OnPolygon() 
{
	// TODO: Add your command handler code here
	m_model=3;
	
}

void CDrawView::OnDashline() 
{
	// TODO: Add your command handler code here
	m_model=5;
	
}

void CDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    if(m_model!=0)
	{
        CDC *pDC =GetDC();
        pDC->SetROP2(R2_NOT);//异或绘图模式
        if(m_ptArray.GetSize()>0)
		{
		   DDALine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);
 		   m_ptEnd=point;
	       DDALine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);
		}
    	ReleaseDC(pDC);
	}
	

	CView::OnMouseMove(nFlags, point);
}

void CDrawView::DashLine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	double x,y,e,dx,dy;
	dx=x2-x1;
	dy=y2-y1;
	e=(fabs(dx)>fabs(dy))?fabs(dx):fabs(dy);
	dx=dx/e;dy=dy/e;
	x=x1;y=y1;
	for(int i=0;i<e;i++)
	{
		//pDC->SetPixel(ROUND(x),ROUND(y),color);
		if((i-1)%10<5)
        pDC->SetPixel(ROUND(x),ROUND(y),color);
		else if((i-1)%10<6)
		pDC->SetPixel(ROUND(x),ROUND(y),color);
		else
	   	pDC->SetPixel(ROUND(x),ROUND(y),pDC->GetBkColor());
		x+=dx;
		y+=dy;
	}

}

