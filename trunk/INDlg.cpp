// INDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "INDlg.h"
#include ".\indlg.h"
#include "SelectDlg.h"
#include "GMDB.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CINDlg dialog


CINDlg::CINDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CINDlg::IDD, pParent)
	, m_gcode(_T(""))
	, m_gno(0)
	, m_price(0)
	, m_pcode(_T(""))
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
	DDX_Control(pDX, IDC_LIST3, m_listctrl);
	DDX_Text(pDX, IDC_EDIT_GCODE, m_gcode);
	DDX_Text(pDX, IDC_EDIT_NO, m_gno);
	DDX_Text(pDX, IDC_EDIT_P, m_price);
	DDX_Text(pDX, IDC_EDIT_PRO, m_pcode);
}


BEGIN_MESSAGE_MAP(CINDlg, CDialog)
	//{{AFX_MSG_MAP(CINDlg)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_SELECT, OnBnClickedButtonSelect)
	ON_BN_CLICKED(IDC_BUTTON6, OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CINDlg message handlers

BOOL CINDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	for (int i=0;i<10;i++)
	{
		m_listctrl.DeleteColumn(0);
	}
	m_listctrl.DeleteAllItems();

	m_listctrl.InsertColumn(1,"商品编号",LVCFMT_LEFT,100);  //G_code
	m_listctrl.InsertColumn(2,"商品名称",LVCFMT_CENTER,150);//	Category_name
	m_listctrl.InsertColumn(3,"供应商",LVCFMT_CENTER,150);//G_name	
	m_listctrl.InsertColumn(4,"进货单价",LVCFMT_CENTER,70);//Sale_price
	m_listctrl.InsertColumn(5,"添加数目",LVCFMT_CENTER,70);//Current_number
	m_listctrl.InsertColumn(6,"添加者用户名",LVCFMT_CENTER,100);//Max_number
	m_listctrl.InsertColumn(7,"时间",LVCFMT_CENTER,110);//Min_number	
	
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES);
	
		/*列表显示*/
	_variant_t strQuery,Holder;
	
	strQuery ="SELECT inlib.Goods_code, goods.G_name, provider.Provider_name, Admin_name ,inlib.In_Price,inlib.In_number, inlib.In_date FROM inlib LEFT OUTER JOIN goods ON inlib.Goods_code = goods.G_code LEFT OUTER JOIN  provider ON inlib.Provider_code = provider.Provider_code";
	
	theApp.ADOExecute(theApp.m_pRs, strQuery);	
	
	while(!theApp.m_pRs->adoEOF){
		
		Holder = theApp.m_pRs->GetCollect("Goods_code");		
		m_listctrl.InsertItem(0,(char*)(_bstr_t)Holder);		
				
		Holder = theApp.m_pRs->GetCollect("G_name");		
		m_listctrl.SetItemText(0,1,(char*)(_bstr_t)Holder);

		Holder = theApp.m_pRs->GetCollect("Provider_name");		
		m_listctrl.SetItemText(0,2,(char*)(_bstr_t)Holder);		

		Holder = theApp.m_pRs->GetCollect("In_Price");		
		m_listctrl.SetItemText(0,3,(char*)(_bstr_t)Holder);		

		Holder = theApp.m_pRs->GetCollect("In_number");		
		m_listctrl.SetItemText(0,4,(char*)(_bstr_t)Holder);		
	
		Holder = theApp.m_pRs->GetCollect("Admin_name");		
		m_listctrl.SetItemText(0,5,(char*)(_bstr_t)Holder);	
		
		
		Holder = theApp.m_pRs->GetCollect("In_date");		
		m_listctrl.SetItemText(0,6,(char*)(_bstr_t)Holder);			
		
		theApp.m_pRs->MoveNext();
	
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CINDlg::OnBnClickedButtonSelect()
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

void CINDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(1);
	CSelectDlg selectDlg;
	selectDlg.isgoods = false;
	selectDlg.m_title = "供应商名称(模糊查询)";
	
	if(selectDlg.DoModal()==IDOK){
		m_pcode = selectDlg.m_gcode;
		

	}
	UpdateData(0);

}

void CINDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	//重置按钮
	this->m_pcode = "";
	this->m_price = 0.0;
	this->m_gno = 0;
	this->m_gcode ="";
	UpdateData(0);
}

void CINDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//添加按钮
	UpdateData(1);
	if(m_gno == 0 || m_price == 0 || m_pcode.IsEmpty() || m_gcode.IsEmpty() ){

			MessageBox("不能为空，请输入完整！");
			return ;


	}
	
	
	CTime tm = CTime::GetCurrentTime();	
	CString strSql;
	strSql.Format("INSERT  INTO inlib(Goods_code,Provider_code,Admin_name,In_number,In_Price,In_date) VALUES('%s','%s','%s',%d ,%.2f ,'%d-%d-%d %d:%d:%d')",this->m_gcode,
		this->m_pcode,
		CGMSRole::Instance()->m_admin_name,
		this->m_gno,
		this->m_price,
		tm.GetYear(), tm.GetMonth(), tm.GetDay(),
		tm.GetHour(), tm.GetMinute(), tm.GetSecond());
	_variant_t  vtQuery(strSql); 
	
	
	theApp.ADOExecute(theApp.m_pRs, vtQuery);
	
	CString errmsg = "";
	
	CGMDB gmdb;
	if(gmdb.UpdateGoods(m_gno,'+',m_gcode,errmsg)){

		CString tempstr;
		tempstr.Format("进货入库，%s数量%d",m_gname,m_gno);		
		theApp.m_log.AddLog(tempstr);
		this->OnInitDialog();
	}
	MessageBox(errmsg);


}
