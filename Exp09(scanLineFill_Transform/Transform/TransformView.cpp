// TransformView.cpp : implementation of the CTransformView class
//

#include "stdafx.h"
#include "Transform.h"

#include "TransformDoc.h"
#include "TransformView.h"
#include"Dlg_SCALE.h"
#include"Dlg_ROTATE.h"
#include<math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CTransformView

IMPLEMENT_DYNCREATE(CTransformView, CView)

BEGIN_MESSAGE_MAP(CTransformView, CView)
	//{{AFX_MSG_MAP(CTransformView)
	ON_COMMAND(IDM_TRANSLATE, OnTranslate)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_COMMAND(IDM_SCALE, OnScale)
	ON_COMMAND(IDM_ROTATE, OnRotate)
	ON_COMMAND(IDM_SMMETRY_Y, OnSmmetryY)
	ON_COMMAND(IDM_SHEARY, OnSheary)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransformView construction/destruction

CTransformView::CTransformView()
{
	// TODO: add construction code here
	m_type_transform=TRF_NONE;
   
    m_LT=CPoint(100,300);
    m_LB=CPoint(100,100);
    m_RT=CPoint(300,300);
    m_RB=CPoint(300,100);
    
    m_prevPoint=0;
    m_bLBDown=FALSE;
    m_bRBDown=FALSE;
   
    m_xStep=1.5;
    m_yStep=1.5;
    
    m_delta=0;

}

CTransformView::~CTransformView()
{
}

BOOL CTransformView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTransformView drawing

void CTransformView::OnDraw(CDC* pDC)
{
	CTransformDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTransformView printing

BOOL CTransformView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTransformView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTransformView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTransformView diagnostics

#ifdef _DEBUG
void CTransformView::AssertValid() const
{
	CView::AssertValid();
}

void CTransformView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTransformDoc* CTransformView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTransformDoc)));
	return (CTransformDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTransformView message handlers

void CTransformView::OnTranslate() 
{
	// TODO: Add your command handler code here
	ClearScreen();
	m_type_transform=TRF_TRANSLATE;
	m_LT=CPoint(100,300);
	m_LB=CPoint(100,100);
	m_RT=CPoint(300,300);
	m_RB=CPoint(300,100);

    DrawRect();
	
}

void CTransformView::ClearScreen()
{
	CClientDC dc(this);
	CRect window;//定义一个矩形的范围
	GetClientRect(window);//把当前客户区大小传给window。

	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Rectangle(window);

}

void CTransformView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bLBDown=TRUE;
    m_prevPoint=point;
	CView::OnLButtonDown(nFlags, point);
}

void CTransformView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bLBDown=FALSE;
    m_prevPoint=point;
	CView::OnLButtonUp(nFlags, point);
}

void CTransformView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	int delta; 
	int x;
    int y;
	CPoint m_LT1=(100,300);
	CPoint m_LB1=(100,100);
	CPoint m_RT1=(300,300);
	CPoint m_RB1=(300,100);
    double b;
    double d;
    switch(m_type_transform)
    {
        case TRF_TRANSLATE:
            if(m_bLBDown)
            {
                ClearScreen();
                delta=point.x-m_prevPoint.x;
                m_prevPoint=point;
                m_LT+=CPoint(delta*(int)m_xStep,0);
                m_LB+=CPoint(delta*(int)m_xStep,0);
                m_RT+=CPoint(delta*(int)m_xStep,0);
                m_RB+=CPoint(delta*(int)m_xStep,0);
                DrawRect();
				CPen* oldPen;
			    CPen newPen(PS_DASH,1,RGB(0,0,0));
                oldPen=dc.SelectObject(&newPen);
				dc.MoveTo(m_RT1);dc.LineTo(m_LT);
				dc.MoveTo(m_RT1);dc.LineTo(m_LB);
				dc.MoveTo(m_RT1);dc.LineTo(m_RT);
				dc.MoveTo(m_RT1);dc.LineTo(m_RB);
				

            }
            if(m_bRBDown)
            {
                ClearScreen();
                delta=point.y-m_prevPoint.y;
                m_prevPoint=point;
                m_LT+=CPoint(0,delta* (int)m_yStep);
                m_LB+=CPoint(0,delta* (int)m_yStep);
                m_RT+=CPoint(0,delta* (int)m_yStep);
                m_RB+=CPoint(0,delta* (int)m_yStep);
                DrawRect();
            }
            break;
		case TRF_SHEAR_Y:
            if(m_bRBDown)
            {
                 ClearScreen();
                 CClientDC dc(this);
                 dc.MoveTo(0,300);
                 dc.LineTo(800,300);
                 dc.MoveTo(400,0);
                 dc.LineTo(400,600);
                 delta=point.x-m_prevPoint.x;
                 m_prevPoint=point;
                 b=0.01;
                 d=0;
                 x=m_LT.x-400;
                 y=m_LT.y-300;
                 m_LT.x=x+y*b*delta+400;
                 m_LT.y=x*d+delta+y+300;
                 x=m_LB.x-400;
                 y=m_LB.y-300;
                 m_LB.x=x+y*b*delta+400;
                 m_LB.y=x*d*delta+300;
                 x=m_RT.x-400;
                 y=m_RT.y-300;
                 m_RT.x=x+y*b*delta+400;
                 m_RT.y=x*d*delta+y+300;
                 x=m_RB.x-400;
                 y=m_RB.y-300;
                 m_RB.x=x+y*b*delta+400;
                 m_RB.y=x*d*delta+y+300;
                 DrawRect();
            }
            break;
        case TRF_NONE:
            break;
    }

	CView::OnMouseMove(nFlags, point);
}

void CTransformView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    m_bRBDown=TRUE;
    m_prevPoint=point;
	
	CView::OnRButtonDown(nFlags, point);
}

void CTransformView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bRBDown=FALSE;
    m_prevPoint=point;
	CView::OnRButtonUp(nFlags, point);
}

void CTransformView::DrawRect()
{
	CClientDC dc(this);
	dc.MoveTo(m_LB);
	dc.LineTo(m_LT);
	dc.LineTo(m_RT);	
	dc.LineTo(m_RB);
	dc.LineTo(m_LB);
}

void CTransformView::OnScale() 
{
	// TODO: Add your command handler code here

	ClearScreen();
    m_type_transform=TRF_SCALE;
    m_LT=CPoint(100,300);
    m_LB=CPoint(100,100);
    m_RT=CPoint(300,300);
    m_RB=CPoint(300,100);
    DrawRect();
    CClientDC dc(this);
    CPen *oldPen;
    CPen newPen(PS_DASH,1,RGB(0,0,0));
    oldPen=dc.SelectObject(&newPen);
    dc.MoveTo(0,0);
    dc.LineTo(m_LT);
    dc.MoveTo(0,0);
    dc.LineTo(m_RB);
    dc.SelectObject(oldPen);
    double Sx=1;
    double Sy=1;
    Dlg_SCALE dlgScale;
    if(dlgScale.DoModal()==IDOK)
    {
        Sx=dlgScale.m_Sx;
        Sy=dlgScale.m_Sy;
    }
    m_LT.x*=Sx;
    m_LB.x*=Sx;
    m_RT.x*=Sx;
    m_RB.x*=Sx;
    m_LT.y*=Sy;
    m_LB.y*=Sy;
    m_RT.y*=Sy;
    m_RB.y*=Sy;
    DrawRect();
    oldPen=dc.SelectObject(&newPen);
    dc.MoveTo(0,0);
    dc.LineTo(m_LT);
    dc.MoveTo(0,0);
    dc.LineTo(m_RB);
    dc.SelectObject(oldPen);

}



void CTransformView::OnRotate() 
{
	// TODO: Add your command handler code here
	ClearScreen();
    m_type_transform=TRF_ROTATE;
    m_LT=CPoint(300,500);
    m_LB=CPoint(300,300);
    m_RT=CPoint(500,500);
    m_RB=CPoint(500,300);
    DrawRect();
    CClientDC dc(this);
    CPen* oldPen;
    CPen newPen(PS_DASH,1,RGB(0,0,0));
    oldPen=dc.SelectObject(&newPen);

    dc.MoveTo(0,0);
    dc.LineTo(m_LT);
	dc.MoveTo(0,0);
    dc.LineTo(m_RB);

    dc.SelectObject(oldPen);
    double angle=0;
    Dlg_ROTATE dlgRotate;
    if(dlgRotate.DoModal()==IDOK)
    {
        angle=dlgRotate.m_RotateAngle/180*3.1415926;
    }
    double c=cos(angle);
    double s=sin(angle);
    m_LT.x=m_LT.x*c-m_LT.y*s;
    m_LT.y=m_LT.x*s+m_LT.y*c;
    m_LB.x=m_LB.x*c-m_LB.y*s;
    m_LB.y=m_LB.x*s+m_LB.y*c;
    m_RT.x=m_RT.x*c-m_RT.y*s;
    m_RT.y=m_RT.x*s+m_RT.y*c;
    m_RB.x=m_RB.x*c-m_RB.y*s;
    m_RB.y=m_RB.x*s+m_RB.y*c;
    
    ClearScreen();
    DrawRect();
    oldPen=dc.SelectObject(&newPen);
    dc.MoveTo(0,0);
    dc.LineTo(m_LT);
	dc.MoveTo(0,0);
    dc.LineTo(m_RB);

    dc.SelectObject(oldPen);
}

void CTransformView::DrawTriangle()
{
	CClientDC dc(this);
    dc.MoveTo(m_LB);
    dc.LineTo(m_LT);
    dc.LineTo(m_RB);
    dc.LineTo(m_LB);
}


void CTransformView::OnSmmetryY() 
{
	// TODO: Add your command handler code here
     m_type_transform=TRF_SYMMETRY_Y;
    CClientDC dc(this);
    dc.MoveTo(0,300);
    dc.LineTo(800,300);
    dc.MoveTo(400,0);
    dc.LineTo(400,600);
    m_LT=CPoint(100,150);
    m_LB=CPoint(100,100);
    m_RB=CPoint(150,100);
    DrawTriangle();
    double a=-1;
    double b=0;
    double d=0;
    double e=1;
    int x=m_LT.x;
    int y=m_LT.y;
    m_LT.x=(x-400)*a+(y-300)*b+400;
    m_LT.y=(x-400)*d+(y-300)*e+300;
    x=m_LB.x;
    y=m_LB.y;
    m_LB.x=(x-400)*a+(y-300)*b+400;
    m_LB.y=(x-400)*d+(y-300)*e+300;
    x=m_RB.x;
    y=m_RB.y;
    m_RB.x=(x-400)*a+(y-300)*b+400;
    m_RB.y=(x-400)*d+(y-300)*e+300;
    DrawTriangle();
	
}



void CTransformView::OnSheary() 
{
	// TODO: Add your command handler code here
    ClearScreen();
    CClientDC dc(this);
    dc.MoveTo(0,300);
    dc.LineTo(800,300);
    dc.MoveTo(400,0);
    dc.LineTo(400,600);
    CPoint Origin=CPoint(400,300);
    CPoint LT=CPoint(-50,100);
    CPoint LB=CPoint(-50,-100);
    CPoint RT=CPoint(50,100);
    CPoint RB=CPoint(50,-100);
    m_LT=LT+Origin;
    m_LB=LB+Origin;
    m_RT=RT+Origin;
    m_RB=RB+Origin;
    DrawRect();	
}

void CTransformView::DrawCubic()
{
	DrawRect2(m_2dLbb,m_2dLbt,m_2dLft,m_2dLfb);
	DrawRect2(m_2dRbb,m_2dRbt,m_2dRft,m_2dRfb);
	DrawRect2(m_2dLbb,m_2dLbt,m_2dRbt,m_2dRbb);
	DrawRect2(m_2dLfb,m_2dLft,m_2dRft,m_2dRfb);
	DrawRect2(m_2dLbb,m_2dLfb,m_2dRfb,m_2dRbb);
	DrawRect2(m_2dLbt,m_2dLft,m_2dRft,m_2dRbt);
}

void CTransformView::DrawRect2(CPoint p1, CPoint p2, CPoint p3, CPoint p4)
{
	CClientDC dc(this);
	dc.MoveTo(p1);
	dc.LineTo(p2);
    dc.LineTo(p3);
	dc.LineTo(p4);
	dc.LineTo(p1);

}
