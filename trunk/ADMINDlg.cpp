// ADMINDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "ADMINDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADMINDlg dialog


CADMINDlg::CADMINDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADMINDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CADMINDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CADMINDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CADMINDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CADMINDlg, CDialog)
	//{{AFX_MSG_MAP(CADMINDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADMINDlg message handlers
