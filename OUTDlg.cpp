// OUTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "OUTDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COUTDlg dialog


COUTDlg::COUTDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COUTDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COUTDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COUTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COUTDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COUTDlg, CDialog)
	//{{AFX_MSG_MAP(COUTDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COUTDlg message handlers
