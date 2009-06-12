// LOGDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "LOGDlg.h"
#include ".\logdlg.h"

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
	DDX_Control(pDX, IDC_LIST_LOG, m_listctrl);
}


BEGIN_MESSAGE_MAP(CLOGDlg, CDialog)
	//{{AFX_MSG_MAP(CLOGDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLOGDlg message handlers

BOOL CLOGDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//m_listctrl.InsertItem();
	m_listctrl.InsertColumn(1,"时间",LVCFMT_LEFT,200);
	m_listctrl.InsertColumn(2,"事件",LVCFMT_LEFT,540);
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES);

	//theApp.ADOExecute(theApp.
	
	_variant_t strQuery;	
	
	strQuery ="SELECT * FROM log ORDER BY do_date ASC";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	_variant_t Holder;
	
	while(!theApp.m_pRs->adoEOF){
		Holder = theApp.m_pRs->GetCollect("do_date");		
		m_listctrl.InsertItem(0,(char*)(_bstr_t)Holder);		
		
		CString do_what;		
		Holder = theApp.m_pRs->GetCollect("Admin_name");		
		do_what = (char*)(_bstr_t)Holder;		
		Holder = theApp.m_pRs->GetCollect("do_what");		
		do_what += ":";
		do_what +=(char*)(_bstr_t)Holder;
		
		m_listctrl.SetItemText(0,1,do_what);
		

		theApp.m_pRs->MoveNext();
		
		
	}
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
