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
	m_n = 0.0;
	m_r = 0.0;
	//}}AFX_DATA_INIT
}


void CDialogStyle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogStyle)
	DDX_Text(pDX, IDC_EDIT1, m_n);
	DDX_Text(pDX, IDC_EDIT2, m_r);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogStyle, CDialog)
	//{{AFX_MSG_MAP(CDialogStyle)
	//ON_BN_CLICKED(IDC_DASH, OnDash)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogStyle message handlers

