// DrawView.h : interface of the CDrawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWVIEW_H__AF34D684_DB8F_4BAA_9E50_03FBB2E5BBCE__INCLUDED_)
#define AFX_DRAWVIEW_H__AF34D684_DB8F_4BAA_9E50_03FBB2E5BBCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>
#include "P2D.h"
#include "DialogStyle.h"


class CDrawView : public CView
{
protected: // create from serialization only
	CDrawView();
	DECLARE_DYNCREATE(CDrawView)

// Attributes
public:
	CDrawDoc* GetDocument();

// Operations
public:
	COLORREF m_color;//绘线色
	COLORREF m_fcolor;//填充色
	UINT m_mode;//控制绘图的模态
	UINT m_Style;// 1-实线；2-虚线
	BOOL m_flag;//  true-实现橡皮筋
	CPoint m_ptStart, m_ptEnd;////绘画的起始点和终止点
	CPoint m_ptCenter,m_ptRadius;
	CArray <CPoint,CPoint> m_ptArray;//一个动态数组
	void GetMaxX();
	void GetMaxY();
protected:
	int MaxX,MaxY;
	P2D P[50];
	double n,r;
	


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawView)
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
	void Diamond();
	void Rectangle(CDC *pDC,CPoint P1,CPoint P2,COLORREF color,UINT Style);
	void Square(CDC *pDC,CPoint p1, CPoint p2,COLORREF color,UINT Style);
	void ScanSeedfill(CDC *pDC, int x, int y, COLORREF boundaryvalue, COLORREF newvalue);
	void BHCircle(CDC *pDC, int x0, int y0, int R, COLORREF color);
	void BHLine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color);
	void DashLine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color);
	void MIDLine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color);
	void DDALine(CDC*pDC,int x1,int y1,int x2,int y2,COLORREF color);
	
	virtual ~CDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawView)
	afx_msg void OnColor();
	afx_msg void OnMidline();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDdaline();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPolyline();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPolygon();
	afx_msg void OnDashline();
	afx_msg void OnBhcircle();
	afx_msg void OnRectangle();
	afx_msg void OnStyle();
	afx_msg void OnSeedfiil();
	afx_msg void OnFcolor();
	afx_msg void OnBhline();
	afx_msg void OnSquare();
	afx_msg void OnDcircle();
	afx_msg void OnDpolygon();
	afx_msg void OnDrectangle();
	afx_msg void OnDsquare();
	afx_msg void OnMENUDiamond();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DrawView.cpp
inline CDrawDoc* CDrawView::GetDocument()
   { return (CDrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWVIEW_H__AF34D684_DB8F_4BAA_9E50_03FBB2E5BBCE__INCLUDED_)
