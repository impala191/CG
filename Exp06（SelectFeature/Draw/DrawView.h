// DrawView.h : interface of the CDrawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWVIEW_H__E519B200_DB10_47F0_9F4E_E4402C3C30D3__INCLUDED_)
#define AFX_DRAWVIEW_H__E519B200_DB10_47F0_9F4E_E4402C3C30D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<afxtempl.h>
const double PI=3.1415926;//比define好，直接定一个double型的变量，且不能更改（const）
//#define PI 3.1415926;//定义一个文本，在计算时要转换

struct _myPoint
{
	long x;
	long y;
};//计算点到直线的距离，开方会有浮点，所有自定义一个点的结构



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
	_myPoint m_ptStart,m_ptEnd;
	CArray<_myPoint,_myPoint>m_ptArray;
	UINT m_nMode;

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
	float PointLineDis(float xx,float yy,float x1,float y1,float x2,float y2);
	float CalDist(float x1,float y1,float x2,float y2);
	void DDALine(CDC *pDC,int x1,int y1,int x2,int y2,COLORREF color);
	virtual ~CDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawView)
	afx_msg void OnDdaline();
	afx_msg void OnChoice();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
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

#endif // !defined(AFX_DRAWVIEW_H__E519B200_DB10_47F0_9F4E_E4402C3C30D3__INCLUDED_)
