// drawcView.h : interface of the CDrawcView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWCVIEW_H__D3365D4D_E65F_4EC8_B0E0_B7E6FB6AF576__INCLUDED_)
#define AFX_DRAWCVIEW_H__D3365D4D_E65F_4EC8_B0E0_B7E6FB6AF576__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<afxtempl.h>



class CDrawcView : public CView
{
protected: // create from serialization only
	CDrawcView();
	DECLARE_DYNCREATE(CDrawcView)

// Attributes
public:
	CDrawcDoc* GetDocument();

// Operations
public:
private:
	CPoint m_ptStart;
	CPoint m_ptEnd;
	CArray<CPoint,CPoint>m_ptArray;
	UINT m_drawType;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawcView)
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
	void ScanSeedfill(CDC *pDC,int x,int y,COLORREF boundaryvalue,COLORREF newvalue);
	virtual ~CDrawcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawcView)
	afx_msg void OnPolygon();
	afx_msg void OnRectangle();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSeedfill();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in drawcView.cpp
inline CDrawcDoc* CDrawcView::GetDocument()
   { return (CDrawcDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWCVIEW_H__D3365D4D_E65F_4EC8_B0E0_B7E6FB6AF576__INCLUDED_)
