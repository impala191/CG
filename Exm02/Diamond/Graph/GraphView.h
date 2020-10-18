// GraphView.h : interface of the CGraphView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHVIEW_H__241D3BDD_4DB1_486C_AE41_2E7C21DF111F__INCLUDED_)
#define AFX_GRAPHVIEW_H__241D3BDD_4DB1_486C_AE41_2E7C21DF111F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P2D.h"



class CGraphView : public CView
{
protected: // create from serialization only
	CGraphView();
	DECLARE_DYNCREATE(CGraphView)

// Attributes
public:
	CGraphDoc* GetDocument();
public:
	void GetMaxX();
	void GetMaxY();
	void Diamond();
// Operations
public:
	CPoint m_ptStart,m_ptEnd;
    UINT drawType;
	int m_Red,m_Green,m_Blue;
	
    int MaxX,MaxY;
	P2D p[50];
	double n,r;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphView)
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
	void Dimond(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color);
	void DDALine(CDC*pDC,int x1,int y1,int x2,int y2,COLORREF color);
	virtual ~CGraphView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraphView)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnColor();
	afx_msg void OnDdaline();
	afx_msg void OnDIMOND();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GraphView.cpp
inline CGraphDoc* CGraphView::GetDocument()
   { return (CGraphDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHVIEW_H__241D3BDD_4DB1_486C_AE41_2E7C21DF111F__INCLUDED_)
