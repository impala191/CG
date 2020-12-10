// DrawView.h : interface of the CDrawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWVIEW_H__4143F346_5B9D_42BD_A003_6A55DC1DED29__INCLUDED_)
#define AFX_DRAWVIEW_H__4143F346_5B9D_42BD_A003_6A55DC1DED29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<afxtempl.h>

typedef enum{TC_STRAIGHTLINE_COHEN,TC_STAIGHTLINE_MIDDLEPOINT,
             TC_STRAIGHTLINE_LB,TCPOLYGON,TC_NONE}Type_Cut;
struct EDGE{//边表结构，内含吊桶，
	int ymin;//最小y值，边表的索引
	int ymax;//吊桶值，最大的y值
	double xmin;//吊桶值，最小的y对应的x
	double fm;//吊桶值，斜率
	EDGE* next;//指向下一条边的指针
	EDGE* last;//指向上一条边的指针
};

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
private: 
	Type_Cut m_type_cut;
private:
	/*BOOL m_LBDown;//左键被按下与否
    BOOL m_RBDown;//右键被按下与否
	CPoint m_LTPoint;//左上角
	CPoint m_RBPoint;//右下角
	CPoint m_BPoint;//起始点
	CPoint m_EPoint;//初始点
	*/
	UINT m_drawType;

	CPoint m_Polygon[512];
	//int m_Num_Ply;
	//CPoint m_ClipedPly[512];
	//int m_NumCliped_Ply;
	CPoint m_ptStart,m_ptEnd;
	

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
	void ScanSeedfill(CDC *pDC, int x, int y, COLORREF boundaryvalue, COLORREF newvalue);
	void Polygonfill(CDC* pDC,CArray<CPoint,CPoint>* m_ptArray,COLORREF color);
	void SortAET(EDGE* pEDGE);
	void SortET(EDGE* pEDGE);
	EDGE* GetET(CArray<CPoint,CPoint>* m_ptArray);
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
	afx_msg void OnSeedfill();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnPolygon();
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

#endif // !defined(AFX_DRAWVIEW_H__4143F346_5B9D_42BD_A003_6A55DC1DED29__INCLUDED_)
