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
#include <math.h>

/////////////////////////////////////////////////////////////////////////////
// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	//{{AFX_MSG_MAP(CDrawView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
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

void CDrawView::BHline(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	int x,y,dx,dy,p;

	//传入端点坐标x值相等（平行y轴的直线
	if(x1==x2)
	{
		if(y1<y2)
		{
			for (int i=y1;i<=y2;i++)
			{
				pDC->SetPixel(x1,i,color);

			}
		}
		else
		{
			for (int i=y2;i<=y1;i++)
			{
				pDC->SetPixel(x1,i,color);
			}
		}
		return;
	}

	//斜率
	BOOL m=(fabs(y2-y1)<=fabs(x2-x1));

	//如果x1大于x2，交换坐标值

	if(x1>x2)
	{
		p=x1;x1=x2;x2=p;
		p=y1;y1=y2;y2=p;
	}
	//赋初值
	x=x1;
	y=y1;
	dx=x2-x1;
	dy=y2-y1;
    
	//斜率绝对值小于1
	if(m)
	{
		//第一种情况，y递增
		if(y1<=y2)
		{
			p=(dy<<1)-dx;//dy是y2-y1(一个整型)，左移一位等于乘以二；右移除以二
			while(x<=x2)
			{
				pDC->SetPixel(x,y,color);
				if(p<0)
				{
					x++;
					p=p+(dy<<1);

				}
				else
				{
					x++;
					y++;
					p=p+((dy-dx)<<1);
				}
			}
		}
		//第三种情况 y递减
		else
		{
			p=dx-(dy<<1);
			while(x<=x2)
			{
				pDC->SetPixel(x,y,color);
				if(p<0)
				{
					p++;
					p=p-(dy<<1);
				}
				else
				{
					x++;
					y--;
					p=p-((dy+dx)<<1);;
				}
			}
		}
	}
	//斜率大于1
	else
	{
		//第二种情况，y递增
		if(y1<=y2)
		{
			p=(dx<<1)-dy;
			while(y<=y2)
			{
				pDC->SetPixel(x,y,color);
				if(p<0)
				{
					y++;
					p=p+(dx<<1);
				}
				else
				{
					x++;
					y++;
					p=p+((dx-dy)<<1);
				}
			}
		}
		//第四种情况，y递减
		else
		{
			p=(dx<<1)+dy;
			while(y>=y2)
			{
				pDC->SetPixel(x,y,color);
				if(p<0)
				{
					y--;
					p=p+(dx<<1);
				}
				else
				{
					x++;
					y--;
					p=p+((dx+dy)<<1);
				}
			}

		}
	}
}

void CDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptStart=point;m_ptEnd=point;
	this->SetCapture();
	m_ptArray.Add(point);
	
	
	CView::OnLButtonDown(nFlags, point);
}

void CDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	
	CView::OnLButtonUp(nFlags, point);
}

void CDrawView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ReleaseCapture();
	CPoint p1,p2;

	if(m_ptArray.GetSize()>1)
	{	
		
		CDC *pDC=GetDC();
		for(int i=0;i<m_ptArray.GetSize()-1;i++)
		{
			p1=m_ptArray.GetAt(i);
		    p2=m_ptArray.GetAt(i+1);
			BHline(pDC,p1.x,p1.y,p2.x,p2.y,RGB(255,0,0));
		}
		ReleaseDC(pDC);
    	m_ptArray.RemoveAll();
	}
	
		//连接最后一个点，绘制矩形
// 		if(m_ptArray.GetSize()>2)
// 		{
// 			p1=m_ptArray.GetAt(0);
// 			p2=m_ptArray.GetAt(m_ptArray.GetSize()-1);
// 			BHline(pDC,p1.x,p1.y,p2.x,p2.y,RGB(0,0,255));
// 		}
// 	if(m_ptArray.GetSize()<=2)
// 	{	
// 		MessageBox("错误");
// 		return;
// 	}
// 	for(int i=0;i<=m_ptArray.GetSize()-1;i++)
// 	{
// 		p1=m_ptArray.GetAt(i);
// 		if(i==(m_ptArray.GetSize()-1))
// 		{
// 			p2=(CPoint)m_ptArray.GetAt(0);
// 		}
// 		else
// 		p2=(CPoint)m_ptArray.GetAt(i+1);
// 	    BHline(pDC,p1.x,p1.y,p2.x,p2.y,RGB(255,0,0));
// 	}
	

	CView::OnLButtonDblClk(nFlags, point);
}
