// CATEDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "CATEDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCATEDlg dialog


CCATEDlg::CCATEDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCATEDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCATEDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCATEDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCATEDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCATEDlg, CDialog)
	//{{AFX_MSG_MAP(CCATEDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCATEDlg message handlers
