// SelectDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "mygms.h"
#include "SelectDlg.h"
#include ".\selectdlg.h"


// CSelectDlg 对话框

IMPLEMENT_DYNAMIC(CSelectDlg, CDialog)
CSelectDlg::CSelectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectDlg::IDD, pParent)
	, m_gname(_T(""))
	, m_title(_T(""))
{
}

CSelectDlg::~CSelectDlg()
{
}

void CSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_gname);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
	DDX_Text(pDX, IDC_STATIC_TITLE, m_title);
}


BEGIN_MESSAGE_MAP(CSelectDlg, CDialog)
	ON_LBN_SELCHANGE(IDC_LIST1, OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
END_MESSAGE_MAP()


// CSelectDlg 消息处理程序

BOOL CSelectDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化


	//do noting

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CSelectDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码


	int nIndex = m_listbox.GetCurSel();

	if(nIndex != LB_ERR){
		if(this->isgoods){
			m_gcode.Format("G%.8d",m_listbox.GetItemData(nIndex));
			 m_listbox.GetText(nIndex,m_gnameEx);
		}
		else{
			m_gcode.Format("P%.8d",m_listbox.GetItemData(nIndex));
			m_listbox.GetText(nIndex,m_gnameEx);
		}
	}

}

void CSelectDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	m_listbox.ResetContent( );
	
	
	UpdateData(1);
	
	CString tempstrSQL;
	int i = 0;
	
	if(this->isgoods){
	
		
		tempstrSQL.Format("select G_code,G_name from goods where G_name like '%%%s%%'",m_gname);
		//MessageBox(tempstrSQL);
		_variant_t strSQL((_bstr_t)tempstrSQL.GetBuffer(tempstrSQL.GetLength()));
		theApp.ADOExecute(theApp.m_pRs,strSQL);
		
		while(!theApp.m_pRs->adoEOF){

			_variant_t hold;

			hold = theApp.m_pRs->GetCollect("G_name");

			m_listbox.InsertString(i,(char *)(_bstr_t)hold);
			
			hold = theApp.m_pRs->GetCollect("G_code");
			CString tempcode;
			tempcode = (char *)(_bstr_t)hold;
			tempcode = tempcode.Right(tempcode.GetLength()-1);//去掉前面的G
			
			m_listbox.SetItemData(i,atoi(tempcode));		
			
			i++;
			theApp.m_pRs->MoveNext();
		}
	}else{
		tempstrSQL.Format("select Provider_code,Provider_name from provider where Provider_name like '%%%s%%'",m_gname);
		_variant_t strSQL((_bstr_t)tempstrSQL.GetBuffer(tempstrSQL.GetLength()));
		theApp.ADOExecute(theApp.m_pRs,strSQL);
		i = 0;
		while(!theApp.m_pRs->adoEOF){

			_variant_t hold;

			hold = theApp.m_pRs->GetCollect("Provider_name");

			m_listbox.InsertString(i,(char *)(_bstr_t)hold);
			
			hold = theApp.m_pRs->GetCollect("Provider_code");
			CString tempcode;
			tempcode = (char *)(_bstr_t)hold;
			tempcode = tempcode.Right(tempcode.GetLength()-1);//去掉前面的P
			
			m_listbox.SetItemData(i,atoi(tempcode));		
			
			i++;
			theApp.m_pRs->MoveNext();
		}


	
	
	
	}
}
