// GMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "GMDlg.h"
#include ".\gmdlg.h"
#include "CATEDlg.h"
#include "AddGoodsDlg.h"
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
	DDX_Control(pDX, IDC_LIST1, m_listctrl);
	DDX_Control(pDX, IDC_LIST2, m_wlistctrl);
	DDX_Control(pDX, IDC_TREE1, m_treectrl);
}


BEGIN_MESSAGE_MAP(CGMDlg, CDialog)
	//{{AFX_MSG_MAP(CGMDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
	ON_NOTIFY(NM_CLICK, IDC_TREE1, OnNMClickTree1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, OnTvnSelchangedTree1)
	ON_NOTIFY(NM_RCLICK, IDC_TREE1, OnNMRclickTree1)
	ON_COMMAND(IDR_MENU_ADD, OnMenuAdd)
	ON_COMMAND(ID_32777, On32777)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGMDlg message handlers

BOOL CGMDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_listctrl.InsertColumn(1,"商品编号",LVCFMT_LEFT,100);  //G_code
	m_listctrl.InsertColumn(2,"商品类型",LVCFMT_CENTER,150);//	Category_name
	m_listctrl.InsertColumn(3,"商品名称",LVCFMT_CENTER,150);//G_name	
	m_listctrl.InsertColumn(4,"商品价格",LVCFMT_CENTER,80);//Sale_price
	m_listctrl.InsertColumn(5,"库存量",LVCFMT_CENTER,80);//Current_number
	m_listctrl.InsertColumn(6,"最大库存量",LVCFMT_CENTER,80);//Max_number
	m_listctrl.InsertColumn(7,"最小库存量",LVCFMT_CENTER,80);//Min_number	
	
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES);

	
	m_wlistctrl.InsertColumn(1,"商品编号",LVCFMT_LEFT,100);  //G_code
	m_wlistctrl.InsertColumn(2,"商品类型",LVCFMT_CENTER,150);//	Category_name
	m_wlistctrl.InsertColumn(3,"商品名称",LVCFMT_CENTER,150);//G_name	
	m_wlistctrl.InsertColumn(4,"商品价格",LVCFMT_CENTER,80);//Sale_price
	m_wlistctrl.InsertColumn(5,"库存量",LVCFMT_CENTER,80);//Current_number
	m_wlistctrl.InsertColumn(6,"最大库存量",LVCFMT_CENTER,80);//Max_number
	m_wlistctrl.InsertColumn(7,"最小库存量",LVCFMT_CENTER,80);//Min_number
	

	m_wlistctrl.SetExtendedStyle(LVS_EX_GRIDLINES);


	/*列表显示*/
	_variant_t strQuery;
	
	strQuery ="SELECT * FROM goods,category where goods.Cate_ID = category.ID ";
	theApp.ADOExecute(theApp.m_pRs, strQuery);	
	ShowList(theApp.m_pRs,m_listctrl);
		
	strQuery ="SELECT * FROM goods,category where goods.Cate_ID = category.ID AND goods.Min_number >= goods.Current_number ";
	theApp.ADOExecute(theApp.m_pRs, strQuery);	
	ShowList(theApp.m_pRs,m_wlistctrl);
		

		
		
		
	/*建立树控件*/	
	HTREEITEM hRoot = m_treectrl.InsertItem("物品类别");
	BuildTree(hRoot,0);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CGMDlg::BuildTree(HTREEITEM fhtr, int fid)
{
/*递归建树*/
	_RecordsetPtr m_pr;	
	m_pr.CreateInstance(__uuidof(Recordset));
	
	
	CString strtemp;
	strtemp.Format("SELECT * FROM category where F_ID = %d",fid);

	_variant_t strQuery((_bstr_t)strtemp.GetBuffer(strtemp.GetLength()));
	theApp.ADOExecute(m_pr, strQuery);	
	
	_variant_t ado_name,ado_id;	
	HTREEITEM subhtr;	
	
	while(!m_pr->adoEOF){	
		 ado_name = m_pr->GetCollect("Category_name");		
		 ado_id = m_pr->GetCollect("ID");		
		 subhtr = 	m_treectrl.InsertItem((char*)(_bstr_t)ado_name,fhtr);		 
		 if(subhtr != NULL){
			 
			 m_treectrl.SetItemData(subhtr, (DWORD) ado_id.intVal);

		 
		 }	 
		 
		 BuildTree(subhtr,ado_id.intVal);

		 m_pr->MoveNext();
	}
	
}

void CGMDlg::OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码

	
	*pResult = 0;
}

void CGMDlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	
	HTREEITEM hItem = pNMTreeView->itemNew.hItem;

	_variant_t strQuery;
	
	int id = 0;
	/*故意 = */
	if(id = m_treectrl.GetItemData(hItem)){
	
		CString strtemp;
		
		strtemp.Format("SELECT * FROM goods,category where goods.Cate_ID = category.ID AND Cate_ID = %d",id);	
	
		strQuery = (_bstr_t)strtemp.GetBuffer(strtemp.GetLength());
			
		theApp.ADOExecute(theApp.m_pRs, strQuery);	

	}else{

		strQuery ="SELECT * FROM goods,category where goods.Cate_ID = category.ID ";
		theApp.ADOExecute(theApp.m_pRs, strQuery);		

	}

		ShowList(theApp.m_pRs,m_listctrl);
	

	
	*pResult = 0;
}

void CGMDlg::ShowList(_RecordsetPtr &pset, CListCtrl &m_list)
{
	_variant_t Holder;

	m_list.DeleteAllItems();	
			
	while(!theApp.m_pRs->adoEOF){
		Holder = pset->GetCollect("G_code");		
		m_list.InsertItem(0,(char*)(_bstr_t)Holder);		
				
		Holder = pset->GetCollect("Category_name");		
		m_list.SetItemText(0,1,(char*)(_bstr_t)Holder);		
				
		Holder = pset->GetCollect("G_name");		
		m_list.SetItemText(0,2,(char*)(_bstr_t)Holder);	
				
		Holder = pset->GetCollect("Sale_price");		
		m_list.SetItemText(0,3,(char*)(_bstr_t)Holder);	
				
		Holder = pset->GetCollect("Current_number");		
		m_list.SetItemText(0,4,(char*)(_bstr_t)Holder);	

		Holder = pset->GetCollect("Max_number");		
		m_list.SetItemText(0,5,(char*)(_bstr_t)Holder);	
				
		Holder = pset->GetCollect("Min_number");		
		m_list.SetItemText(0,6,(char*)(_bstr_t)Holder);

		theApp.m_pRs->MoveNext();		
	}

		
}


void CGMDlg::OnNMRclickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{

  /*树 右键菜单*/
	CPoint   pt1,pt2;   
	GetCursorPos(&pt1);   
	pt2   =   pt1;   
	ScreenToClient(&pt1);     
	   
	HTREEITEM   RClickItem   =   NULL;   
	RClickItem   =   m_treectrl.HitTest(pt1);     
	    
	if(RClickItem   ==   NULL)
		return;   
	    
	m_treectrl.Select(RClickItem,TVGN_CARET);   
	   
	  
	f_id   =   m_treectrl.GetItemData(RClickItem); 

	CMenu   m_Rmenu;
	m_Rmenu.LoadMenu(IDR_MENU_POP);

	m_Rmenu.GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTBUTTON,pt2.x,pt2.y,this);


	*pResult = 0;
}

void CGMDlg::OnMenuAdd()
{
	// TODO: 在此添加命令处理程序代码
	/*添加商品*/
	CAddGoodsDlg addgdlg;
	if(addgdlg.DoModal() == IDOK ){
		UpdateData();

		CString strSql;

		strSql.Format("INSERT INTO goods (G_code,G_name,Current_number,Max_number,Min_number,Sale_price,Cate_ID) VALUES('%s','%s',%d,%d,%d,%.2f,%d)",
			addgdlg.m_gcode, addgdlg.m_gname,0,addgdlg.m_maxn,addgdlg.m_minn,addgdlg.m_price,f_id);
		_variant_t  vtQuery(strSql);  
		theApp.ADOExecute(theApp.m_pRs, vtQuery);		
		
		
		theApp.m_log.AddLog("添加商品信息,"+ addgdlg.m_gname);
        


	}

	
}

void CGMDlg::On32777()
{
	// TODO: 在此添加命令处理程序代码
	/*添加类别菜单*/
	CCATEDlg catedlg;	
	if(catedlg.DoModal() == IDOK){		
		UpdateData(1);
		CString strtemp;		
		strtemp.Format("insert into category(Category_name , F_id) VALUES('%s',%d) ",catedlg.m_catename,f_id);	
		
		_variant_t strQuery = (_bstr_t)strtemp.GetBuffer(strtemp.GetLength());			
		if(theApp.ADOExecute(theApp.m_pRs, strQuery)){
			theApp.m_log.AddLog("添加商品类别："+catedlg.m_catename);
			
		}
	}
	

}
