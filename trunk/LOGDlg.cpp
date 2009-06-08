// LOGDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "LOGDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLOGDlg dialog


CLOGDlg::CLOGDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLOGDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLOGDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLOGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLOGDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLOGDlg, CDialog)
	//{{AFX_MSG_MAP(CLOGDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLOGDlg message handlers
