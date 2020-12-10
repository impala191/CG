// DrawView.cpp : implementation of the CDrawView class
//

#include "stdafx.h"
#include "Draw.h"
#include <math.h>

#include "DrawDoc.h"
#include "DrawView.h"
#define ROUND(a) int(a+0.5)

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
	ON_COMMAND(IDM_DDALINE, OnDdaline)
	ON_COMMAND(IDM_CHOICE, OnChoice)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
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

float CDrawView::CalDist(float x1, float y1, float x2, float y2)
{//点与点之间的距离
	return (float)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

}

float CDrawView::PointLineDis(float xx, float yy, float x1, float y1, float x2,float y2)
{
	//计算点到直线的距离
	//（xx,yy）为线外一点；（x1，y1）和（x2，y2）则是线的端点
	float a,b,c,ang1,ang2,ang;
	//a，b，c是线外一点连接线端点构成的三角形的三条边
	//计算a,b,c三条边的长度
	a=CalDist(x1,y1,xx,yy);
	if(0.0==a)
	{//容错机制——点在直线上则返回 0
		return 0.0;
	}

	b=CalDist(x2,y2,xx,yy);
	if(0.0==b)
	{
		return 0.0;
	}

	c=CalDist(x1,y1,x2,y2);
	//如果（x1,y1）和（x2,y2）的坐标相同，即线段是一个点，退出函数并返回距离。
	if(0.0==c)
	{
		return a;
	}
	
	if(a<b)
    //如果点（xx,yy）到点（x1,y1）这条边的比较短,求该连线到扫面线（也就是水平线）的角度
	{
		if(fabs(y1-y2)<=0.001)//如果AB是水平线，得到直线AB的弧度。
			//若判断为0，则过于苛刻，受机器硬件限制，小于一个较小的数即可
		{
			if(x1<x2)
				ang1=0;
			else
				ang1=(float)PI;
		}
		else//如果直线AB不是水平线段，得到直线AB与x轴的正向夹角的弧度
		{
			ang1=(float)acos((x2-x1)/c);
			if(y1>y2)
			ang1=(float)PI*2-ang1;//直线AB的正向夹角弧度
		}
		ang2=(float)acos((xx-x1)/a);
		if(y1>yy)//即超过180°
		    ang2=(float)PI*2-ang2;
		ang=ang2-ang1;
		if(ang<0)
			ang=-ang;
		if(ang>PI)
			ang=(float)PI*2-ang;
		if(ang>PI/2)
			return a;//如果为钝角，直接返回距离
		else
			return (a*(float)sin(ang));//否则返回垂边

	}	
	else//b<a的情况
	{
		if((y1-y2)<=0.001)
		{
			if(x1<x2)
				ang1=(float)PI;
			else
				ang1=0;
		}
		else
		{
			ang1=(float)acos((x1-x2)/c);
			if(y2>y1)	
			ang1=(float)PI*2-ang1;
		}
		ang2=(float)acos((xx-x2)/b);
		if(y2>yy)
			ang2=(float)PI*2-ang2;
		ang=ang2-ang1;
		if(ang<0)
			ang=-ang;
		if(ang>PI)
    		ang=(float)PI*2-ang;
		if(ang>PI/2)
			return ang;
		else
			return(b*(float)sin(ang));
	}		
	
}

void CDrawView::OnDdaline() 
{
	// TODO: Add your command handler code here
	m_nMode=1;
	
}

void CDrawView::OnChoice() 
{
	// TODO: Add your command handler code here
	m_nMode=2;
	
}

void CDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	switch(m_nMode)
	{
	case 1://绘线段
		{
			m_ptStart.x=point.x;
			m_ptStart.y=point.y;
			m_ptArray.Add(m_ptStart);
		}
		break;
	case 2://选择
		{
			_myPoint selectPoint,p1,p2;
			selectPoint.x=point.x;
			selectPoint.y=point.y;
			//long dist=0.0;
			float dist =0.0;
			CDC *pDC =GetDC();
            for(int i=0;i<m_ptArray.GetSize()-1;i=i+2)
			{
				p1=m_ptArray.GetAt(i);
				p2=m_ptArray.GetAt(i+1);
				dist=PointLineDis(selectPoint.x,selectPoint.y,p1.x,p1.y,p2.x,p2.y);
				if(dist<1.8)
					DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(255,0,0));
				else	
					DDALine(pDC,p1.x,p1.y,p2.x,p2.y,RGB(0,0,0));	
				
			}
			ReleaseDC(pDC);


		}
		break;
	default:
		{

		}
		break;
	}
	
	CView::OnLButtonDown(nFlags, point);
}

void CDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	switch(m_nMode)
	{
	case 1:
		{
			m_ptEnd.x=point.x;
			m_ptEnd.y=point.y;
			m_ptArray.Add(m_ptEnd);

			CDC *pDC=GetDC();
			DDALine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,RGB(0,0,0));

			ReleaseDC(pDC);

		}
		break;
	case 2:
		{

		}
		break;
	default:
		{

		}
		break;
	}
	
	CView::OnLButtonUp(nFlags, point);
}
