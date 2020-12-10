// CutDoc.cpp : implementation of the CCutDoc class
//

#include "stdafx.h"
#include "Cut.h"

#include "CutDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCutDoc

IMPLEMENT_DYNCREATE(CCutDoc, CDocument)

BEGIN_MESSAGE_MAP(CCutDoc, CDocument)
	//{{AFX_MSG_MAP(CCutDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCutDoc construction/destruction

CCutDoc::CCutDoc()
{
	// TODO: add one-time construction code here

}

CCutDoc::~CCutDoc()
{
}

BOOL CCutDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCutDoc serialization

void CCutDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCutDoc diagnostics

#ifdef _DEBUG
void CCutDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCutDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCutDoc commands
