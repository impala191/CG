// drawcDoc.cpp : implementation of the CDrawcDoc class
//

#include "stdafx.h"
#include "drawc.h"

#include "drawcDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawcDoc

IMPLEMENT_DYNCREATE(CDrawcDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawcDoc, CDocument)
	//{{AFX_MSG_MAP(CDrawcDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDrawcDoc construction/destruction

CDrawcDoc::CDrawcDoc()
{
	// TODO: add one-time construction code here

}

CDrawcDoc::~CDrawcDoc()
{
}

BOOL CDrawcDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDrawcDoc serialization

void CDrawcDoc::Serialize(CArchive& ar)
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
// CDrawcDoc diagnostics

#ifdef _DEBUG
void CDrawcDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawcDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDrawcDoc commands
