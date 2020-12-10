// CutView.h : interface of the CCutView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUTVIEW_H__2564908D_7F73_446F_AFCD_095C8566DBA2__INCLUDED_)
#define AFX_CUTVIEW_H__2564908D_7F73_446F_AFCD_095C8566DBA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//定义一个枚举的类型
typedef enum{TC_STRAIGHTLINE_COHEN,TC_STAIGHTLINE_MIDDLEPOINT,
             TC_STRAIGHTLINE_LB,TCPOLYGON,TC_NONE}Type_Cut;


class CCutView : public CView
{
protected: // create from serialization only
	CCutView();
	DECLARE_DYNCREATE(CCutView)

// Attributes
public:
	CCutDoc* GetDocument();

// Operations
public:
private:
	Type_Cut m_type_cut;
private:
	BOOL m_LBDown;//左键被按下与否
    BOOL m_RBDown;//右键被按下与否
	CPoint m_LTPoint;//左上角
	CPoint m_RBPoint;//右下角
	CPoint m_BPoint;//起始点
	CPoint m_EPoint;//初始点

	CPoint m_Polygon[512];
	int m_Num_Ply;
	CPoint m_ClipedPly[512];
	int m_NumCliped_Ply;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCutView)
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
	void Cohen_Sutherland(CPoint &BPoint,CPoint &EPoint);
	void Makecode(CPoint point, int &Code);
	void ShowLineSeg(CPoint BPoint,CPoint EPoint);
	void CorrectWindow();
	void ClearScreen();
	virtual ~CCutView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCutView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnCohen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CutView.cpp
inline CCutDoc* CCutView::GetDocument()
   { return (CCutDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUTVIEW_H__2564908D_7F73_446F_AFCD_095C8566DBA2__INCLUDED_)
