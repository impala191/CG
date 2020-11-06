// DialogStyle.cpp : implementation file
//

#include "stdafx.h"
#include "Draw.h"
#include "DialogStyle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogStyle dialog


CDialogStyle::CDialogStyle(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogStyle::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogStyle)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialogStyle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogStyle)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogStyle, CDialog)
	//{{AFX_MSG_MAP(CDialogStyle)
	//ON_BN_CLICKED(IDC_DASH, OnDash)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogStyle message handlers

