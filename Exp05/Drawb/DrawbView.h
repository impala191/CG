// DrawbView.h : interface of the CDrawbView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWBVIEW_H__38542425_588D_4561_B4CB_84556273A13E__INCLUDED_)
#define AFX_DRAWBVIEW_H__38542425_588D_4561_B4CB_84556273A13E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


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
	CPoint m_ptCenter;
	CPoint m_ptRadius;

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
	void BHCircle(CDC *pDC,int x0,int y0,int R,COLORREF color);
	virtual ~CDrawbView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawbView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
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

#endif // !defined(AFX_DRAWBVIEW_H__38542425_588D_4561_B4CB_84556273A13E__INCLUDED_)
