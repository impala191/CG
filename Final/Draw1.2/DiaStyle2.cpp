// DiaStyle2.cpp : implementation file
//

#include "stdafx.h"
#include "Draw.h"
#include "DiaStyle2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaStyle2 dialog


DiaStyle2::DiaStyle2(CWnd* pParent /*=NULL*/)
	: CDialog(DiaStyle2::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaStyle2)
	m_DStyle2 = 0;
	//}}AFX_DATA_INIT
}


void DiaStyle2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaStyle2)
	DDX_Text(pDX, IDC_EDIT1, m_DStyle2);
	DDV_MinMaxUInt(pDX, m_DStyle2, 0, 3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaStyle2, CDialog)
	//{{AFX_MSG_MAP(DiaStyle2)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaStyle2 message handlers

