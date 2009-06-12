// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "MainDlg.h"
#include ".\maindlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog


CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDlg)
	DDX_Control(pDX, IDC_TAB_MAIN, m_tabctrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	//{{AFX_MSG_MAP(CMainDlg)
	//}}AFX_MSG_MAP
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, OnTcnSelchangeTabMain)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg message handlers

BOOL CMainDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tabctrl.InsertItem(0,"运行日志");
	m_tabctrl.InsertItem(1,"商品库存");
if(CGMSRole::Instance()->HaveAction(IN_ACTION)) m_tabctrl.InsertItem(2,"入库管理");
if(CGMSRole::Instance()->HaveAction(OUT_ACTION)) m_tabctrl.InsertItem(3,"出库管理");
if(CGMSRole::Instance()->HaveAction(ADMIN_ACTION)) m_tabctrl.InsertItem(4,"管理员管理");

		
//	m_tabctrl.SetWindowPos();
if(CGMSRole::Instance()->HaveAction(IN_ACTION)) indlg.Create(IDD_DIALOG_IN,GetDlgItem(IDC_TAB_MAIN));
if(CGMSRole::Instance()->HaveAction(OUT_ACTION)) outdlg.Create(IDD_DIALOG_OUT,GetDlgItem(IDC_TAB_MAIN));

if(CGMSRole::Instance()->HaveAction(ADMIN_ACTION)) admindlg.Create(IDD_DIALOG_ADMIN,GetDlgItem(IDC_TAB_MAIN));
	logdlg.Create(IDD_DIALOG_LOG,GetDlgItem(IDC_TAB_MAIN));
	gmdlg.Create(IDD_DIALOG_GM,GetDlgItem(IDC_TAB_MAIN));
	
	
	CRect r;
	m_tabctrl.GetClientRect (&r);	
	
	if(CGMSRole::Instance()->HaveAction(IN_ACTION)) indlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
	if(CGMSRole::Instance()->HaveAction(OUT_ACTION)) outdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);

	if(CGMSRole::Instance()->HaveAction(ADMIN_ACTION)) admindlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
	logdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_SHOWWINDOW);
	gmdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
	/*CString str;
	str.Format("width:%d;height:%d",r.Width(),r.Height());
	MessageBox(str);*/

	m_tabctrl.SetCurSel(0);		
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMainDlg::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	
	CRect r;
	m_tabctrl.GetClientRect (&r);
/*
	m_tabctrl.InsertItem(0,"运行日志");
	m_tabctrl.InsertItem(1,"商品库存");
	m_tabctrl.InsertItem(2,"入库管理");
	m_tabctrl.InsertItem(3,"出库管理");
	m_tabctrl.InsertItem(4,"类别管理");
*/
	/**/
	
	switch(m_tabctrl.GetCurSel())
	{
		case 0:
			if(CGMSRole::Instance()->HaveAction(IN_ACTION)) indlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			if(CGMSRole::Instance()->HaveAction(OUT_ACTION)) outdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
		
			if(CGMSRole::Instance()->HaveAction(ADMIN_ACTION)) admindlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			logdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_SHOWWINDOW);
			gmdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			break;
		case 1:
			if(CGMSRole::Instance()->HaveAction(IN_ACTION)) indlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			if(CGMSRole::Instance()->HaveAction(OUT_ACTION)) outdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
		
			if(CGMSRole::Instance()->HaveAction(ADMIN_ACTION)) admindlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			logdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			gmdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_SHOWWINDOW);
			break;
		case 2:
			if(CGMSRole::Instance()->HaveAction(IN_ACTION)) indlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_SHOWWINDOW);
			if(CGMSRole::Instance()->HaveAction(OUT_ACTION)) outdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
		
			if(CGMSRole::Instance()->HaveAction(ADMIN_ACTION)) admindlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			logdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			gmdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			break;
		case 3:
			if(CGMSRole::Instance()->HaveAction(IN_ACTION)) indlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			if(CGMSRole::Instance()->HaveAction(OUT_ACTION)) outdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_SHOWWINDOW);
	
			if(CGMSRole::Instance()->HaveAction(ADMIN_ACTION)) admindlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			logdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			gmdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			break;
		case 4:		
			if(CGMSRole::Instance()->HaveAction(IN_ACTION)) indlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			if(CGMSRole::Instance()->HaveAction(OUT_ACTION))outdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);			
			if(CGMSRole::Instance()->HaveAction(ADMIN_ACTION)) admindlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_SHOWWINDOW);
			logdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			gmdlg.SetWindowPos(NULL,10,30,r.Width()-20,r.Height()-40,SWP_HIDEWINDOW);
			break;

	}
	
	
	*pResult = 0;
}
