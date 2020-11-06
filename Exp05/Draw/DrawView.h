// DrawView.h : interface of the CDrawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWVIEW_H__F9C3F947_26DA_4133_B276_2098E4FE4795__INCLUDED_)
#define AFX_DRAWVIEW_H__F9C3F947_26DA_4133_B276_2098E4FE4795__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>

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
	CPoint m_ptStart;
	CPoint m_ptEnd;
public:
	CArray<CPoint,CPoint>m_ptArray;


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
	void BHline(CDC *pDC, int x1, int y1, int x2, int y2, COLORREF color);
	virtual ~CDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
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

#endif // !defined(AFX_DRAWVIEW_H__F9C3F947_26DA_4133_B276_2098E4FE4795__INCLUDED_)
