// DrawbDoc.cpp : implementation of the CDrawbDoc class
//

#include "stdafx.h"
#include "Drawb.h"

#include "DrawbDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawbDoc

IMPLEMENT_DYNCREATE(CDrawbDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawbDoc, CDocument)
	//{{AFX_MSG_MAP(CDrawbDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawbDoc construction/destruction

CDrawbDoc::CDrawbDoc()
{
	// TODO: add one-time construction code here

}

CDrawbDoc::~CDrawbDoc()
{
}

BOOL CDrawbDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDrawbDoc serialization

void CDrawbDoc::Serialize(CArchive& ar)
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
// CDrawbDoc diagnostics

#ifdef _DEBUG
void CDrawbDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawbDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawbDoc commands
