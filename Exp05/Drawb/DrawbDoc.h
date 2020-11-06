// DrawbDoc.h : interface of the CDrawbDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWBDOC_H__E96F0950_8312_4BAD_A679_E9D3854932B4__INCLUDED_)
#define AFX_DRAWBDOC_H__E96F0950_8312_4BAD_A679_E9D3854932B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawbDoc : public CDocument
{
protected: // create from serialization only
	CDrawbDoc();
	DECLARE_DYNCREATE(CDrawbDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawbDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawbDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawbDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWBDOC_H__E96F0950_8312_4BAD_A679_E9D3854932B4__INCLUDED_)
