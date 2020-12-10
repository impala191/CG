// TransformView.h : interface of the CTransformView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSFORMVIEW_H__6451C06D_872A_408E_9D39_F3E9F814F86E__INCLUDED_)
#define AFX_TRANSFORMVIEW_H__6451C06D_872A_408E_9D39_F3E9F814F86E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef enum{TRF_TRANSLATE,TRF_NONE,TRF_SCALE,TRF_ROTATE,TRF_SYMMETRY_Y,TRF_SHEAR_Y}Type_Transform;
class Point_3D
{
public:
	double x;
	double y;
	double z;
public:
	Point_3D(){};
	Point_3D(int xCood,int yCood,int zCood){x=xCood;y=yCood;z=zCood;};
	~Point_3D(){};
};


class CTransformView : public CView
{
protected: // create from serialization only
	CTransformView();
	DECLARE_DYNCREATE(CTransformView) 

// Attributes
public:
	CTransformDoc* GetDocument();

// Operations
public:
	double m_Proj_Matri[4][4];
private:
	BOOL m_bLBDown;//左键被按下与否
    BOOL m_bRBDown;//右键被按下与否
	
	CPoint m_LT;//左上角
	CPoint m_LB;
	CPoint m_RB;//右下角
	CPoint m_RT;
	CPoint m_prevPoint;
	double m_yStep,m_xStep;//平移的x和y？
	double m_delta;
//	double m_SCALE_Sx,m_SCALE_Sy;//比例变换的x和y
    Point_3D mLBB;
	CPoint m_2dLbb;
	Point_3D m_LBT;
	CPoint m_2dLbt;
	Point_3D m_LFB;
	Point_3D m_LFT;
	Point_3D m_RBB;
	Point_3D m_RBT;
	Point_3D m_RFB;
	Point_3D m_RFT;
	CPoint m_2dLfb;
	CPoint m_2dLft;
	CPoint m_2dRbb;
	CPoint m_2dRbt;
	CPoint m_2dRfb;
	CPoint m_2dRft;

	
private:Type_Transform m_type_transform;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransformView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawRect2(CPoint p1,CPoint p2,CPoint p3,CPoint p4);
	void DrawCubic();
	void DrawTriangle();
	void DrawRect();
	void ClearScreen();
	virtual ~CTransformView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTransformView)
	afx_msg void OnTranslate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnScale();
	afx_msg void OnRotate();
	afx_msg void OnSmmetryY();
	afx_msg void OnSheary();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TransformView.cpp
inline CTransformDoc* CTransformView::GetDocument()
   { return (CTransformDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSFORMVIEW_H__6451C06D_872A_408E_9D39_F3E9F814F86E__INCLUDED_)
