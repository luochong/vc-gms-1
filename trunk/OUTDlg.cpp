// OUTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "OUTDlg.h"
#include ".\outdlg.h"
#include "selectDlg.h"
#include "GMDB.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COUTDlg dialog


COUTDlg::COUTDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COUTDlg::IDD, pParent)
	, m_gno(0)
	, m_gcode(_T(""))
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
	DDX_Text(pDX, IDC_EDIT_NO, m_gno);
	DDX_Text(pDX, IDC_EDIT_GCODE, m_gcode);
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
}


BEGIN_MESSAGE_MAP(COUTDlg, CDialog)
	//{{AFX_MSG_MAP(COUTDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_SELECT, OnBnClickedButtonSelect)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COUTDlg message handlers

void COUTDlg::OnBnClickedButtonSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	CSelectDlg selectDlg;
	selectDlg.isgoods = true;
	selectDlg.m_title = "商品名称(模糊查询)";
	if(selectDlg.DoModal()==IDOK){
		m_gcode = selectDlg.m_gcode;
		m_gname = selectDlg.m_gnameEx;
	}
	UpdateData(0);
	

	
}

void COUTDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

		//重置按钮


	this->m_gno = 0;
	this->m_gcode ="";
	UpdateData(0);
}

void COUTDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

		UpdateData(1);
	if(m_gno == 0 || m_gcode.IsEmpty() ){

			MessageBox("不能为空，请输入完整！");
			return ;


	}
	
	
	CTime tm = CTime::GetCurrentTime();	
	CString strSql;
	strSql.Format("INSERT  INTO outlib(Goods_code,Out_number,Admin_name,out_date) VALUES('%s',%d,'%s','%d-%d-%d %d:%d:%d')",this->m_gcode,
		this->m_gno,
		CGMSRole::Instance()->m_admin_name,		
		tm.GetYear(), tm.GetMonth(), tm.GetDay(),
		tm.GetHour(), tm.GetMinute(), tm.GetSecond());
	_variant_t  vtQuery(strSql); 
	
	
	theApp.ADOExecute(theApp.m_pRs, vtQuery);
	
	CString errmsg = "";
	
	CGMDB gmdb;
	if(gmdb.UpdateGoods(m_gno,'-',m_gcode,errmsg)){

		CString tempstr;
		tempstr.Format("商品出库，%s数量%d",m_gname,m_gno);
		theApp.m_log.AddLog(tempstr);
		this->OnInitDialog();
	}
	MessageBox(errmsg);

}

BOOL COUTDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	for (int i=0;i<10;i++)
	{
		m_listctrl.DeleteColumn(0);
	}
	m_listctrl.DeleteAllItems();

	// TODO:  在此添加额外的初始化
	m_listctrl.InsertColumn(1,"商品编号",LVCFMT_LEFT,100);  //G_code
	m_listctrl.InsertColumn(2,"商品名称",LVCFMT_CENTER,150);//	Category_name
	m_listctrl.InsertColumn(3,"出库数目",LVCFMT_CENTER,70);//Current_number
	m_listctrl.InsertColumn(4,"出库操作用户名",LVCFMT_CENTER,130);//Max_number
	m_listctrl.InsertColumn(5,"时间",LVCFMT_CENTER,170);//Min_number	
	
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES);
	
		/*列表显示*/
	_variant_t strQuery,Holder;
	
	strQuery ="SELECT Goods_code, G_name,Admin_name,Out_number,out_date FROM outlib LEFT OUTER JOIN goods ON outlib.Goods_code = goods.G_code";
	
	theApp.ADOExecute(theApp.m_pRs, strQuery);	
	
	while(!theApp.m_pRs->adoEOF){
		
		Holder = theApp.m_pRs->GetCollect("Goods_code");		
		m_listctrl.InsertItem(0,(char*)(_bstr_t)Holder);		
				
		Holder = theApp.m_pRs->GetCollect("G_name");		
		m_listctrl.SetItemText(0,1,(char*)(_bstr_t)Holder);
		

		Holder = theApp.m_pRs->GetCollect("Out_number");		
		m_listctrl.SetItemText(0,2,(char*)(_bstr_t)Holder);		

		Holder = theApp.m_pRs->GetCollect("Admin_name");		
		m_listctrl.SetItemText(0,3,(char*)(_bstr_t)Holder);		
	
		Holder = theApp.m_pRs->GetCollect("out_date");		
		m_listctrl.SetItemText(0,4,(char*)(_bstr_t)Holder);	
		
		
			
		
		theApp.m_pRs->MoveNext();
	
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
