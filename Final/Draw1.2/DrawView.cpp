// DrawView.cpp : implementation of the CDrawView class
//

//#include "stdafx.h"
#include "Draw.h"

#include "DrawDoc.h"
#include "DrawView.h"
#include "DialogStyle.h"
#include "DiaStyle2.h"
#include <stack>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "math.h"
#define ROUND(a) int (a+0.5)
#define PI 3.1415926

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
	ON_COMMAND(IDM_BHCIRCLE, OnBhcircle)
	ON_COMMAND(IDM_RECTANGLE, OnRectangle)
	ON_COMMAND(IDM_SEEDFIIL, OnSeedfiil)
	ON_COMMAND(IDM_FCOLOR, OnFcolor)
	ON_COMMAND(IDM_BHLINE, OnBhline)
	ON_COMMAND(IDM_SQUARE, OnSquare)
	ON_COMMAND(IDM_DCIRCLE, OnDcircle)
	ON_COMMAND(IDM_DPOLYGON, OnDpolygon)
	ON_COMMAND(IDM_DRECTANGLE, OnDrectangle)
	ON_COMMAND(IDM_DSQUARE, OnDsquare)
	ON_COMMAND(IDM_MENUDiamond, OnMENUDiamond)
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
	m_mode=0;
	m_Style=0;
	m_color=(255,255,255);
	m_ptStart=m_ptEnd=(0,0);
	m_flag=false;


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
	if(0==m_mode)
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
void CDrawView::OnFcolor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	if(IDOK==dlg.DoModal())
	{
		m_fcolor=dlg.GetColor();
	}
	
	
}

// void CDrawView::OnStyle() 
// {
// 	// TODO: Add your command handler code here
// 	CDialogStyle  dlg;
// 	if(IDC_DASH==dlg.DoModal())
// 	{
// 		
// 		UpdateData();
// 	}
// 	
// 	
// }

void CDrawView::OnDdaline() 
{
	// TODO: Add your command handler code here
	//m_mode=1;
	m_Style=1;//ʵ��
	m_mode=1;
	
}

void CDrawView::OnDashline() 
{
	// TODO: Add your command handler code here
	m_Style=2;
	//m_mode=5;
	m_mode=2;

	
}

void CDrawView::OnMidline() 
{
	// TODO: Add your command handler code here
	m_mode=4;
	m_Style=1;//ʵ��
	
}



void CDrawView::OnBhline() 
{
	// TODO: Add your command handler code here
	m_Style=1;//ʵ��
	m_mode=9;
	
}

void CDrawView::OnPolygon() 
{
	// TODO: Add your command handler code here
	m_Style=1;
	m_mode=3;
	
}

void CDrawView::OnDpolygon() 
{
	// TODO: Add your command handler code here
	m_Style=2;
	m_mode=3;
		
}

void CDrawView::OnPolyline() 
{
	// TODO: Add your command handler code here
	//����
	m_mode=2;
	m_Style=1;
	
}  

void CDrawView::OnBhcircle() 
{
	// TODO: Add your command handler code here
	m_mode=6;
	
}

void CDrawView::OnRectangle() 
{
	// TODO: Add your command handler code here
	m_Style=1;
	m_mode=7;
		
}

void CDrawView::OnDrectangle() 
{
	// TODO: Add your command handler code here
	m_Style=2;
	m_mode=7;
		
}

void CDrawView::OnDcircle() 
{
	// TODO: Add your command handler code here
	m_Style=2;
	m_mode=6;
	
}

void CDrawView::OnSquare() 
{
	// TODO: Add your command handler code here
	m_Style=1;
	m_mode=10;
	
}

void CDrawView::OnDsquare() 
{
	// TODO: Add your command handler code here
	m_Style=2;
	m_mode=10;
	
}

void CDrawView::OnSeedfiil() 
{
	// TODO: Add your command handler code here
	
	m_mode=8;
	
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
	//���ǶȵĴ�С�Ƚ�תΪ�ߵıȽϣ���ȷ����x��������y���������
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
    if(m) //m=1,��deltaY<deltaX,б��С��1��xΪ��������ʼ�ղ���+1��
	{
		if(y1<y2)//�������ϻ���б�ʴ���0��С��1
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
		else//б��С��0����-1
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
	else//б�ʴ���1
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

void CDrawView::BHLine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color)
{
	int x,y,dx,dy,p;
	
	//����˵�����xֵ��ȣ�ƽ��y���ֱ��
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
	
	//б��
	BOOL m=(fabs(y2-y1)<=fabs(x2-x1));
	
	//���x1����x2����������ֵ
	
	if(x1>x2)
	{
		p=x1;x1=x2;x2=p;
		p=y1;y1=y2;y2=p;
	}
	//����ֵ
	x=x1;
	y=y1;
	dx=x2-x1;
	dy=y2-y1;
    
	//б�ʾ���ֵС��1
	if(m)
	{
		//��һ�������y����
		if(y1<=y2)
		{
			p=(dy<<1)-dx;//dy��y2-y1(һ������)������һλ���ڳ��Զ������Ƴ��Զ�
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
		//��������� y�ݼ�
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
	//б�ʴ���1
	else
	{
		//�ڶ��������y����
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
		//�����������y�ݼ�
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






void CDrawView::BHCircle(CDC *pDC, int x0, int y0, int R, COLORREF color)
{
	int x,y,p;
	//pΪ������
	x=0;y=R;p=3-(R<<1);
	
	for(;x<=y;x++)//�˷�֮һ��Բ����
	{
		//����x��Գ�
		pDC->SetPixel(x+x0,y+y0,color);
		pDC->SetPixel(-x+x0,y+y0,color);
		pDC->SetPixel(x+x0,-y+y0,color);
		pDC->SetPixel(-x+x0,-y+y0,color);
		//����y��ѳ�
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

void CDrawView::Rectangle(CDC *pDC, CPoint P1, CPoint P2, COLORREF color, UINT Style)
{
	
/*	CPoint p1,p2,p3,p4;*/
// 	p1=P1; p2=P2;
// 	p3.x=p1.x;
//     p3.y=p2.y;
//     p4.x=p2.x;
//     p4.y=p1.y;
	if(Style==1)
	{
		DDALine(pDC,P1.x,P1.y,P1.x,P2.y,m_color);
		DDALine(pDC,P1.x,P2.y,P2.x,P2.y,m_color);
		DDALine(pDC,P2.x,P2.y,P2.x,P1.y,m_color);
		DDALine(pDC,P2.x,P1.y,P1.x,P1.y,m_color);
		
	}
	if(Style==2)
	{
		DashLine(pDC,P1.x,P1.y,P1.x,P2.y,m_color);
		DashLine(pDC,P1.x,P2.y,P2.x,P2.y,m_color);
		DashLine(pDC,P2.x,P2.y,P2.x,P1.y,m_color);
		DashLine(pDC,P2.x,P1.y,P1.x,P1.y,m_color);
		
	}
	
}

void CDrawView::Square(CDC *pDC, CPoint P1,CPoint P2, COLORREF color,UINT Style)
{
	int e,dx,dy;
	CPoint p1,p2,p3,p4;
	p1=p3=P1; p2=P2;
	dx=p1.x-p2.x;dy=p1.y-p2.y;
	e=(fabs(dx)<fabs(dy))?fabs(dx):fabs(dy);
	p2=P1;
    
	if(P1.x<P2.x)
	{
		if(P1.y<P2.y)
		{
			p3.y=p3.y+e;
			p2.x=p2.x+e;
			p4.x=p2.x;
			p4.y=p2.y+e;
		}
		else
		{
			p2.x=p1.x+e;
			p3.y=p1.y-e;
			p4.x=p2.x;
			p4.y=p2.y-e;
		}		
	}
	else//P1.x>P2.x
	{
		if(P1.y>P2.y)
		{
			p2.y=p1.y-e;
			p3.x=p1.x-e;
			p4.x=p3.x;
			p4.y=p3.y-e;
		}
		else
		{
			p2.x=p1.x-e;
			p3.y=p1.y+e;
			p4.x=p2.x;
			p4.y=p2.y+e;
		}	
	}
	if(Style==1) 
		//CDC *pDC=GetDC();
	{
		DDALine(pDC,p1.x,p1.y,p2.x,p2.y,m_color);
		DDALine(pDC,p2.x,p2.y,p4.x,p4.y,m_color);
		DDALine(pDC,p4.x,p4.y,p3.x,p3.y,m_color);
		DDALine(pDC,p3.x,p3.y,p1.x,p1.y,m_color);
	}
	if(Style==2)
	{
		DashLine(pDC,p1.x,p1.y,p2.x,p2.y,m_color);
		DashLine(pDC,p2.x,p2.y,p4.x,p4.y,m_color);
		DashLine(pDC,p4.x,p4.y,p3.x,p3.y,m_color);
		DashLine(pDC,p3.x,p3.y,p1.x,p1.y,m_color);
		
	}
	ReleaseDC(pDC);
	
	
	
}

void CDrawView::ScanSeedfill(CDC *pDC, int x, int y, COLORREF boundaryvalue, COLORREF newvalue)
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
	
	


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
	m_ptStart=point;
	m_ptEnd=point;
	m_ptArray.Add(point);	
    m_ptCenter =point;
	m_flag=true;
	

	
}

void CDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonUp(nFlags, point);
	m_ptEnd=point;
    CDC *pDC=GetDC();
/*	if(m_Style==1)*/
/*	{*/
	if((m_mode==7||m_mode==10)&&m_Style==0)
	{
		DiaStyle2 dlg;
		if(IDOK==dlg.DoModal())
		{
			m_Style=dlg.m_DStyle2;
		}
	}
     m_flag=false;

		switch(m_mode)
		{
		    case 1:	DDALine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);m_ptArray.RemoveAll();break;      
	     	case 4: MIDLine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);m_ptArray.RemoveAll();break;
			case 9: BHLine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);m_ptArray.RemoveAll();break;
	    	case 2: break;
		    case 3: break;
	    	case 5: break;
	    	case 6://��Բ
				{
				    m_ptRadius=point;
				    double r=sqrt((m_ptRadius.x-m_ptCenter.x)*(m_ptRadius.x-m_ptCenter.x)+(m_ptRadius.y-m_ptCenter.y)*(m_ptRadius.y-m_ptCenter.y));
			    	BHCircle(pDC,m_ptCenter.x,m_ptCenter.y,int(r),m_color);
				}

			//	m_ptCenter=(0.0);
		
		    	m_ptArray.RemoveAll();
			    break;
		    case 7://����
				{
				    /*pDC->Rectangle(m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y);*/
					Rectangle(pDC,m_ptStart,m_ptEnd, m_color,m_Style);	
				//	m_ptStart=(0,0);
				
				    m_ptArray.RemoveAll();
				    
				}
				break;
		    case 8://�����ɫ
			ScanSeedfill(pDC,point.x,point.y,m_color,m_fcolor);break;
			case 10://������
				{ 					
					Square(pDC,m_ptStart,m_ptEnd, m_color,m_Style);
					m_ptArray.RemoveAll();
				}
				break;

        	default:MessageBox("ѡ���߷�ʽ��");break;

		}
		
/*	}*/
		
	
    ReleaseDC(pDC);
}



void CDrawView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//m_ptEnd=point;
	m_ptArray.Add(point);
	CDC *pDC=GetDC();
	if(m_Style==0)
	{
		DiaStyle2 dlg;
		if(IDOK==dlg.DoModal())
		{
			m_Style=dlg.m_DStyle2;
		} 
	}
	CPoint p1,p2;
	switch(m_mode)
	{
	
	case 2://����
		{
			for(int i=0;i<m_ptArray.GetSize()-1;i++)
			{
				p1=(CPoint)m_ptArray.GetAt(i);
				p2=(CPoint)m_ptArray.GetAt(i+1);
				if(m_Style==1)
				DDALine(pDC,p1.x,p1.y,p2.x,p2.y,m_color);
				else
				DashLine(pDC,p1.x,p1.y,p2.x,p2.y,m_color);
				
			}  
			m_ptArray.RemoveAll();
			//m_ptStart=(0,0);//���ã�Ϊ��������ͼ����׼����
		}	
		break;
	case 3://�����
		{
			if(m_ptArray.GetSize()<=2)
			{	
			    MessageBox("����");
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

                if(m_Style!=0)
				switch (m_Style)
				{
				    case 1:	DDALine(pDC,p1.x,p1.y,p2.x,p2.y,m_color);break;
				    case 2: DashLine(pDC,p1.x,p1.y,p2.x,p2.y,m_color);break;
		
				}
				
			}
 						
		}
		break;

	case 5:
// 		{
// 			
// 			for(int i=0;i<m_ptArray.GetSize()-1;i++)
// 			{
// 				p1=(CPoint)m_ptArray.GetAt(i);
// 			    p2=(CPoint)m_ptArray.GetAt(i+1);
// 				DashLine(pDC,p1.x,p1.y,p2.x,p2.y,m_color);			
// 			}  
// 
// 		}
		break;
		
	 case 6:break;
	 case 7:break;
	 case 8:break;

     default:MessageBox("ѡ��������");break;
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
		m_mode=1;//DDALine
	}
	if(VK_F3==nChar)
	{
		m_mode=9;//BHLine
	}
	if(VK_F4==nChar)
	{
		m_mode=7;//Rectangle
	}
	if(VK_F5==nChar)
	{
		m_mode=6;//Circle
	}
	if(VK_F6==nChar)
	{
		m_mode=2;	//Polyline
	}
	if(VK_F7==nChar)
	{
		m_mode=3;//Polygon
	}


	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
      CDC *pDC =GetDC();
      pDC->SetROP2(R2_NOT);//����ͼģʽ
	  double r;

      switch (m_mode)
	  {
	      case 1: break;
	      case 5: //����
	      case 2: //Polyline
	      case 3: //Polygon
			  {
				 
				  if(m_ptArray.GetSize()>0)
				  
				  {
		              DDALine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);
		              m_ptEnd=point;
	                  DDALine(pDC,m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y,m_color);
				  }
     	          ReleaseDC(pDC);
			  }break;
	      case 4: break;
	      case 6: //Բ
			  
			  {   
				  //r=sqrt((m_ptRadius.x-m_ptCenter.x)*(m_ptRadius.x-m_ptCenter.x)+(m_ptRadius.y-m_ptCenter.y)*(m_ptRadius.y-m_ptCenter.y));
				  //if(m_ptCenter.x!=0)
				  if(m_flag==TRUE)
				  {
		               //m_ptRadius=point;		  
			           
			           //BHCircle(pDC,m_ptCenter.x,m_ptCenter.y,int(r),m_color);
		               
			           r=sqrt((m_ptRadius.x-m_ptCenter.x)*(m_ptRadius.x-m_ptCenter.x)+(m_ptRadius.y-m_ptCenter.y)*(m_ptRadius.y-m_ptCenter.y));
			           BHCircle(pDC,m_ptCenter.x,m_ptCenter.y,int(r),m_color);
					   m_ptRadius=point;
					   BHCircle(pDC,m_ptCenter.x,m_ptCenter.y,int(r),m_color);
				  }
			  }
			  break;
		  case 7://����

			  {    
				  /*if(m_ptStart.x!=0)*/
				  if(m_flag==TRUE)
				  {
					  Rectangle(pDC,m_ptStart,m_ptEnd, m_color,m_Style);
					  m_ptEnd=point;
					  Rectangle(pDC,m_ptStart,m_ptEnd, m_color,m_Style);
				  }
				   
//�������������
// 			       pDC->Rectangle(m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y);
// 				   m_ptEnd=point;
// 				   pDC->Rectangle(m_ptStart.x,m_ptStart.y,m_ptEnd.x,m_ptEnd.y);
			  }

			  
		           ReleaseDC(pDC);
			  
			  break;
		  case 10://������
// 			  { 
// 				  if(m_flag==TRUE)
// 				  {
// 					  Square(pDC,m_ptStart,m_ptEnd,RGB(192,192,192),m_Style);
// 					  m_ptEnd=point;
// 					  Square(pDC,m_ptStart,m_ptEnd,RGB(192,192,192),m_Style);	
// 					 
// 				  }
// 				  
// 
// 			  }
// 			  ReleaseDC(pDC);
	          break;
	  }
			 
	CView::OnMouseMove(nFlags, point);
}

void CDrawView::GetMaxX()
{
	CRect Rect;
	GetClientRect(&Rect);
	MaxX=Rect.right;
}

void CDrawView::GetMaxY()
{
	CRect Rect;
	GetClientRect(&Rect);
	MaxY=Rect.bottom;
}

void CDrawView::Diamond()
{
	// TODO: Add your command handler code here
	CClientDC dc(this);
	CPen MyPen,*OldPen;
	MyPen.CreatePen(PS_SOLID,1,RGB(0,0,255));
	OldPen=dc.SelectObject(&MyPen);
    double Theta;
	Theta=2*PI/n;
	
	for (int i=0; i < n; i++)
	{
		// ������ϵתΪֱ������ϵ
		P[i].x = r * cos(i*Theta)+MaxX/2;
		P[i].y = r * sin(i*Theta)+MaxY/2;
	}
	for (i=0; i<=n-2; i++)
	{
		for (int j =i+1; j<=n-1;j++)
		{
			dc.MoveTo(ROUND(P[i].x),ROUND(P[i].y)); // MoveTo() �������
			dc.LineTo(ROUND(P[j].x), ROUND(P[j].y)); // LineTo() �����յ㣬������
		}
	}
	
	dc.SelectObject(OldPen);
    MyPen.DeleteObject();

}

void CDrawView::OnMENUDiamond() 
{
	// TODO: Add your command handler code here
	CDialogStyle dlg;
	if (dlg.DoModal() == IDOK) //�ж��Ƿ���ȷ�ϼ�
	{
        // ��ȡ����Ĳ������ֵ���n���뾶r��
		n = dlg.m_n; 
		r = dlg.m_r;
	}
	RedrawWindow();
	GetMaxX();
	GetMaxY();
    Diamond();

	
}
