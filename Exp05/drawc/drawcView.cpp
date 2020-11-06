// drawcView.cpp : implementation of the CDrawcView class
//

#include "stdafx.h"
#include "drawc.h"

#include "drawcDoc.h"
#include "drawcView.h"
// 
// #ifdef _DEBUG
// #define new DEBUG_NEW
// #undef THIS_FILE
// static char THIS_FILE[] = __FILE__;
// #endif

#include <stack>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// CDrawcView

IMPLEMENT_DYNCREATE(CDrawcView, CView)

BEGIN_MESSAGE_MAP(CDrawcView, CView)
	//{{AFX_MSG_MAP(CDrawcView)
	ON_COMMAND(IDM_POLYGON, OnPolygon)
	ON_COMMAND(IDM_RECTANGLE, OnRectangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(IDM_SEEDFILL, OnSeedfill)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawcView construction/destruction

CDrawcView::CDrawcView()
{
	// TODO: add construction code here

}

CDrawcView::~CDrawcView()
{
}

BOOL CDrawcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDrawcView drawing

void CDrawcView::OnDraw(CDC* pDC)
{
	CDrawcDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDrawcView printing

BOOL CDrawcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDrawcView diagnostics

#ifdef _DEBUG
void CDrawcView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawcView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawcDoc* CDrawcView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawcDoc)));
	return (CDrawcDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawcView message handlers

void CDrawcView::ScanSeedfill(CDC *pDC, int x, int y, COLORREF boundaryvalue, COLORREF newvalue)
{
	//0:seed;xl:��߽��;xr:�ұ߽�
	int x0,xl,xr,y0,xid;
	int flag,xnextspan;//�������

	stack<CPoint>s;
	CPoint p;
	s.push(CPoint(x,y));//ʰȡ�㣬��һ��������ջ�������洫��
	while(!s.empty())//�ж�ջ��Ϊ�գ���ִ�����²���
	{
		p=s.top();//ȡ��ջ������
		s.pop();//��Ȼ�󵯳�
		pDC->SetPixel(p.x,p.y,newvalue);//ջ������ʼΪʰȡ�㣩����ָ����ɫ��
		x=p.x;
		y=p.y;

		x0=x+1;//��������Ų�����������
		while(pDC->GetPixel(x0,y)!=boundaryvalue)
		{
			pDC->SetPixel(x0,y,newvalue);
			x0++;
		}
		xr=x0-1;//���ұ�Ԫ��

		x0=x-1;//���������ƶ�,�������
		while(pDC->GetPixel(x0,y)!=boundaryvalue)
		{
			pDC->SetPixel(x0,y,newvalue);
			x0--;
		}
		xl=x0+1;//����߽߱磨��Ϊ����x0�����ݼ�ѭ�����жϵ����Ե��ɫ�����˳���ѭ��������+1�����������߽�����ɫ������߽硣
		
        y0=y;
		for(int i=1;i>=-1;i-=2)//��һ�к���һ�д������д����
		{
			x0=xr;
			y=y0+i;
			while(x0>=xl)
			{
				flag=0;
				while((pDC->GetPixel(x0,y)!=boundaryvalue)
					&&(pDC->GetPixel(x0,y)!=newvalue)
					&&(x0>xl))
				{
					if(flag==0)//Ϊ�������ұ�һ������Ϊ�µ�����
					{
						flag=1;
						xid=x0;
					}
					x0--;
				}
				if(flag==1)
				{
					s.push(CPoint(xid,y));
					flag=0;
				}
				xnextspan=x0;//xnextspan�����ضγ���
				while((pDC->GetPixel(x0,y)==boundaryvalue)
				    ||(pDC->GetPixel(x0,y)==newvalue)&&(x0>=xl))
				{
					x0--;//����һ��x0--һ����������ѭ����
				}
				if(xnextspan==x0)x0--;
			}		
		}
	}	
}
	

void CDrawcView::OnRectangle() 
{
	// TODO: Add your command handler code here
	m_drawType=1;
}

void CDrawcView::OnPolygon() 
{
	// TODO: Add your command handler code here
	m_drawType=2;
	
}

void CDrawcView::OnSeedfill() 
{
	// TODO: Add your command handler code here
	m_drawType=3;
	
}


void CDrawcView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptStart=point;
	m_ptArray.Add(point);

	
	CView::OnLButtonDown(nFlags, point);
}


void CDrawcView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptEnd=point;
	CDC *pDC=GetDC();
	if(m_drawType==1)
	{
		pDC->Rectangle(m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y);
	}
	if(m_drawType==3)
	{
		ScanSeedfill(pDC,point.x,point.y,RGB(0,0,0),RGB(0,0,192));
		
	}
	ReleaseDC(pDC);

	
	
	CView::OnLButtonUp(nFlags, point);
}


void CDrawcView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_ptEnd=point;
	CDC *pDC=GetDC();
	if(m_drawType=2&&m_ptArray.GetSize()>2)
	{
		CPoint p1,p2;
		for(int i=0;i<=m_ptArray.GetSize()-1;i++)
		{
			p1=(CPoint)m_ptArray.GetAt(i);
			if(i==m_ptArray.GetSize()-1)
			{
				p2=(CPoint)m_ptArray.GetAt(0);
			}
			else
			{
				p2=(CPoint)m_ptArray.GetAt(i+1);
			}
			pDC->MoveTo(p1);
			pDC->LineTo(p2);
		}
	}

	ReleaseDC(pDC);
	m_ptArray.RemoveAll();
	
	CView::OnLButtonDblClk(nFlags, point);
}
