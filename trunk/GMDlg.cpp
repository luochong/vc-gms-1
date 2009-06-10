// GMDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mygms.h"
#include "GMDlg.h"
#include ".\gmdlg.h"

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
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGMDlg message handlers

BOOL CGMDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_listctrl.InsertColumn(1,"��Ʒ���",LVCFMT_LEFT,100);  //G_code
	m_listctrl.InsertColumn(2,"��Ʒ����",LVCFMT_CENTER,150);//	Category_name
	m_listctrl.InsertColumn(3,"��Ʒ����",LVCFMT_CENTER,150);//G_name	
	m_listctrl.InsertColumn(4,"��Ʒ�۸�",LVCFMT_CENTER,80);//Sale_price
	m_listctrl.InsertColumn(5,"�����",LVCFMT_CENTER,80);//Current_number
	m_listctrl.InsertColumn(6,"�������",LVCFMT_CENTER,80);//Max_number
	m_listctrl.InsertColumn(7,"��С�����",LVCFMT_CENTER,80);//Min_number	
	
	m_listctrl.SetExtendedStyle(LVS_EX_GRIDLINES);

	
	m_wlistctrl.InsertColumn(1,"��Ʒ���",LVCFMT_LEFT,100);  //G_code
	m_wlistctrl.InsertColumn(2,"��Ʒ����",LVCFMT_CENTER,150);//	Category_name
	m_wlistctrl.InsertColumn(3,"��Ʒ����",LVCFMT_CENTER,150);//G_name	
	m_wlistctrl.InsertColumn(4,"��Ʒ�۸�",LVCFMT_CENTER,80);//Sale_price
	m_wlistctrl.InsertColumn(5,"�����",LVCFMT_CENTER,80);//Current_number
	m_wlistctrl.InsertColumn(6,"�������",LVCFMT_CENTER,80);//Max_number
	m_wlistctrl.InsertColumn(7,"��С�����",LVCFMT_CENTER,80);//Min_number
	

	m_wlistctrl.SetExtendedStyle(LVS_EX_GRIDLINES);


	
	_variant_t strQuery;	
	
	strQuery ="SELECT * FROM goods,category where goods.Cate_ID = category.ID ";
	theApp.ADOExecute(theApp.m_pRs, strQuery);

	_variant_t Holder,nowNo,minNo;
	
	while(!theApp.m_pRs->adoEOF){	
		
		Holder = theApp.m_pRs->GetCollect("G_code");		
		m_listctrl.InsertItem(0,(char*)(_bstr_t)Holder);		
		
		Holder = theApp.m_pRs->GetCollect("Category_name");		
		m_listctrl.SetItemText(0,1,(char*)(_bstr_t)Holder);		
		
		Holder = theApp.m_pRs->GetCollect("G_name");		
		m_listctrl.SetItemText(0,2,(char*)(_bstr_t)Holder);	
		
		Holder = theApp.m_pRs->GetCollect("Sale_price");		
		m_listctrl.SetItemText(0,3,(char*)(_bstr_t)Holder);	
		
		nowNo = Holder = theApp.m_pRs->GetCollect("Current_number");		
		m_listctrl.SetItemText(0,4,(char*)(_bstr_t)Holder);	

		 Holder = theApp.m_pRs->GetCollect("Max_number");		
		m_listctrl.SetItemText(0,5,(char*)(_bstr_t)Holder);	
		
		minNo =Holder = theApp.m_pRs->GetCollect("Min_number");		
		m_listctrl.SetItemText(0,6,(char*)(_bstr_t)Holder);			
		
		
		if(nowNo.intVal<=minNo.intVal){
			Holder = theApp.m_pRs->GetCollect("G_code");		
			m_wlistctrl.InsertItem(0,(char*)(_bstr_t)Holder);		
			
			Holder = theApp.m_pRs->GetCollect("Category_name");		
			m_wlistctrl.SetItemText(0,1,(char*)(_bstr_t)Holder);		
			
			Holder = theApp.m_pRs->GetCollect("G_name");		
			m_wlistctrl.SetItemText(0,2,(char*)(_bstr_t)Holder);	
			
			Holder = theApp.m_pRs->GetCollect("Sale_price");		
			m_wlistctrl.SetItemText(0,3,(char*)(_bstr_t)Holder);	
			
			Holder = theApp.m_pRs->GetCollect("Current_number");		
			m_wlistctrl.SetItemText(0,4,(char*)(_bstr_t)Holder);	

			Holder = theApp.m_pRs->GetCollect("Max_number");		
			m_wlistctrl.SetItemText(0,5,(char*)(_bstr_t)Holder);	
			
			Holder = theApp.m_pRs->GetCollect("Min_number");		
			m_wlistctrl.SetItemText(0,6,(char*)(_bstr_t)Holder);

		}
		
		
		theApp.m_pRs->MoveNext();
		
	}		
		
	/*�������ؼ�*/	
	HTREEITEM hRoot = m_treectrl.InsertItem("��Ʒ���");
	BuildTree(hRoot,0);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CGMDlg::BuildTree(HTREEITEM fhtr, int fid)
{
/*�ݹ齨��*/
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
		
		 BuildTree(subhtr,ado_id.intVal);

		 m_pr->MoveNext();
	}
	
}

void CGMDlg::OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	
	*pResult = 0;
}
