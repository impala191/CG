// DLDimond.cpp : implementation file
//

#include "stdafx.h"
#include "Graph.h"
#include "DLDimond.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DLDimond dialog


DLDimond::DLDimond(CWnd* pParent /*=NULL*/)
	: CDialog(DLDimond::IDD, pParent)
{
	//{{AFX_DATA_INIT(DLDimond)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DLDimond::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DLDimond)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DLDimond, CDialog)
	//{{AFX_MSG_MAP(DLDimond)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLDimond message handlers
