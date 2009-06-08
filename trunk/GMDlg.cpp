// GMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "GMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGMDlg dialog


CGMDlg::CGMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGMDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGMDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGMDlg, CDialog)
	//{{AFX_MSG_MAP(CGMDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGMDlg message handlers
