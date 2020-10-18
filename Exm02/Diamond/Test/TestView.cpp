// TestView.cpp : implementation of the CTestView class
//

#include "stdafx.h"
#include "Test.h"

#include "TestDoc.h"
#include "TestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define ROUND(a) int (a+0.5)
#include "math.h"
#define PI 3.1415926

/////////////////////////////////////////////////////////////////////////////
// CTestView

IMPLEMENT_DYNCREATE(CTestView, CView)

BEGIN_MESSAGE_MAP(CTestView, CView)
	//{{AFX_MSG_MAP(CTestView)
	ON_COMMAND(ID_MENUDiamond, OnMENUDiamond)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestView construction/destruction

CTestView::CTestView()
{
	// TODO: add construction code here

}

CTestView::~CTestView()
{
}

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestView drawing

void CTestView::OnDraw(CDC* pDC)
{
	CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTestView printing

void CTestView::GetMaxX()
{
	CRect Rect;
	GetClientRect(&Rect);
	MaxX=Rect.right;
}

void CTestView::GetMaxY()
{
	CRect Rect;
	GetClientRect(&Rect);
	MaxY=Rect.bottom;
}

void CTestView::Diamond() 
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
		// 极坐标系转为直角坐标系
		P[i].x = r * cos(i*Theta)+MaxX/2;
		P[i].y = r * sin(i*Theta)+MaxY/2;
	}
	for (i=0; i<=n-2; i++)
	{
		for (int j =i+1; j<=n-1;j++)
		{
			dc.MoveTo(ROUND(P[i].x),ROUND(P[i].y)); // MoveTo() 设置起点
			dc.LineTo(ROUND(P[j].x), ROUND(P[j].y)); // LineTo() 设置终点，并画线
		}
	}

	dc.SelectObject(OldPen);
    MyPen.DeleteObject();

}

void CTestView::OnMENUDiamond()
{
  InputDlg dlg;
  if (dlg.DoModal() == IDOK) //判断是否点击确认键
	{
        // 获取输入的参数（分点数n，半径r）
		n = dlg.m_n; 
		r = dlg.m_r;
	}
   RedrawWindow();
   GetMaxX();
   GetMaxY();
   Diamond();
}

BOOL CTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestView diagnostics

#ifdef _DEBUG
void CTestView::AssertValid() const
{
	CView::AssertValid();
}

void CTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestDoc* CTestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestDoc)));
	return (CTestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestView message handlers

