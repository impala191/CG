// CutDoc.h : interface of the CCutDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUTDOC_H__62724A58_2D13_47AD_9EF8_3FB265E262FC__INCLUDED_)
#define AFX_CUTDOC_H__62724A58_2D13_47AD_9EF8_3FB265E262FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCutDoc : public CDocument
{
protected: // create from serialization only
	CCutDoc();
	DECLARE_DYNCREATE(CCutDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCutDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCutDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCutDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUTDOC_H__62724A58_2D13_47AD_9EF8_3FB265E262FC__INCLUDED_)
