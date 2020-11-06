// drawcDoc.h : interface of the CDrawcDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWCDOC_H__CFDCFD03_27A4_4A05_9AFB_E1B94A409FAB__INCLUDED_)
#define AFX_DRAWCDOC_H__CFDCFD03_27A4_4A05_9AFB_E1B94A409FAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDrawcDoc : public CDocument
{
protected: // create from serialization only
	CDrawcDoc();
	DECLARE_DYNCREATE(CDrawcDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawcDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDrawcDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDrawcDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWCDOC_H__CFDCFD03_27A4_4A05_9AFB_E1B94A409FAB__INCLUDED_)
