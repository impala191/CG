// DrawbView.h : interface of the CDrawbView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWBVIEW_H__57FF63E3_EF75_4064_84A6_13E97D5225FA__INCLUDED_)
#define AFX_DRAWBVIEW_H__57FF63E3_EF75_4064_84A6_13E97D5225FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>


class CDrawbView : public CView
{
protected: // create from serialization only
	CDrawbView();
	DECLARE_DYNCREATE(CDrawbView)

// Attributes
public:
	CDrawbDoc* GetDocument();

// Operations
public:
private:
	CPoint m_ptStart;
	CPoint m_ptEnd;
	CArray<CPoint,CPoint>m_ptArray;
	UINT m_mode;
	int deltax;
	int deltay;
	BOOL m_flag;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawbView)
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
	void DDALine(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color);
	virtual ~CDrawbView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawbView)
	afx_msg void OnMove();
	afx_msg void OnDdaline();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DrawbView.cpp
inline CDrawbDoc* CDrawbView::GetDocument()
   { return (CDrawbDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWBVIEW_H__57FF63E3_EF75_4064_84A6_13E97D5225FA__INCLUDED_)
