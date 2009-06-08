// INDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "INDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CINDlg dialog


CINDlg::CINDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CINDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CINDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CINDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CINDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CINDlg, CDialog)
	//{{AFX_MSG_MAP(CINDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CINDlg message handlers
