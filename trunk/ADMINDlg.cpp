// ADMINDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "ADMINDlg.h"
#include ".\admindlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CADMINDlg dialog


CADMINDlg::CADMINDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADMINDlg::IDD, pParent)
	, m_acode(_T(""))
	, m_aname(_T(""))
	, m_apassword(_T(""))
	, m_arepassword(_T(""))
	, m_accode(_T(""))
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
	DDX_Text(pDX, IDC_EDIT1, m_acode);
	DDX_Text(pDX, IDC_EDIT7, m_aname);
	DDX_Text(pDX, IDC_EDIT9, m_apassword);
	DDX_Text(pDX, IDC_EDIT10, m_arepassword);
	DDX_Text(pDX, IDC_EDIT6, m_accode);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_COMBO1, m_combobox);
}


BEGIN_MESSAGE_MAP(CADMINDlg, CDialog)
	//{{AFX_MSG_MAP(CADMINDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CADMINDlg message handlers

void CADMINDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	
	if(m_apassword.IsEmpty() || m_acode.IsEmpty() || m_aname.IsEmpty()){
		MessageBox("请输入完整！");
		return ;
	}
	if(m_apassword != m_arepassword){
		MessageBox("两次密码不一致,请重新输入！");
		return ;
	}
	int m_role;
	m_role = m_combobox.GetCurSel();
	
	CString strQuery;
	strQuery.Format("insert into admin(Admin_code,Admin_name,Admin_passwd,Admin_role) values('%s','%s','%s','%d')",m_acode,m_aname,m_apassword,m_role+1);
	_variant_t strquery(strQuery);
	
	if(theApp.ADOExecute(theApp.m_pRs, strquery)){
	
			theApp.m_log.AddLog("添加管理员，用户名为"+m_aname);
			MessageBox("添加成功！");
			this->OnInitDialog();
	
	}
	
	
	
	m_acode=m_aname=m_apassword="";
	UpdateData(0);
	
}

BOOL CADMINDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	for (int i=0;i<m_listctrl.GetItemCount() ;i++)
	{
		m_listctrl.DeleteColumn(0);
	}
	m_listctrl.DeleteAllItems();
	// TODO:  在此添加额外的初始化
	m_listctrl.InsertColumn(1,"管理员编号",LVCFMT_LEFT,100);  //G_code
	m_listctrl.InsertColumn(2,"管理员姓名",LVCFMT_CENTER,150);//	Category_name
	m_listctrl.InsertColumn(3,"管理员角色",LVCFMT_CENTER,150);//G_name	

	
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES);
	_variant_t strQuery;
	
	strQuery ="SELECT * FROM admin";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	while(!theApp.m_pRs->adoEOF){
		
		_variant_t holder;
		
		holder = theApp.m_pRs->GetCollect("Admin_code");
		
		m_listctrl.InsertItem(0,(char*)(_bstr_t)holder);
		
		holder = theApp.m_pRs->GetCollect("Admin_name");
		m_listctrl.SetItemText(0,1,(char*)(_bstr_t)holder);		
		
		holder = theApp.m_pRs->GetCollect("Admin_role");
		

		CString strrole;
		
		switch(holder.intVal){
			case SUPER_ADMIN: strrole = "系统管理员"; break;
			case IN_ADMIN : strrole = "采购管理员"; break;
			case OUT_ADMIN :strrole = "销售管理员"; break;

		}
		
		m_listctrl.SetItemText(0,2,strrole);
		theApp.m_pRs->MoveNext();
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CADMINDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData();
	if(this->m_accode.IsEmpty()){


		MessageBox("请输入编号！");
		return;
	}
	CString strQuery;
	
	strQuery.Format("DELETE FROM admin WHERE Admin_code = '%s' ",m_accode);

	_variant_t strquery(strQuery);
	if(theApp.ADOExecute(theApp.m_pRs, strquery)){
	
		theApp.m_log.AddLog("删除管理员，编号为"+m_accode);
		MessageBox("删除成功！");
		this->OnInitDialog();
	}

	m_accode = "";
	UpdateData(0);
}
