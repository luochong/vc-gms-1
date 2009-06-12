// AddGoodsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "mygms.h"
#include "AddGoodsDlg.h"


// CAddGoodsDlg 对话框

IMPLEMENT_DYNAMIC(CAddGoodsDlg, CDialog)
CAddGoodsDlg::CAddGoodsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddGoodsDlg::IDD, pParent)
	, m_gname(_T(""))
	, m_maxn(0)
	, m_minn(0)
	, m_price(0)
	, m_gcode(_T("G"))
{
}

CAddGoodsDlg::~CAddGoodsDlg()
{
}

void CAddGoodsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, m_gname);
	DDX_Text(pDX, IDC_EDIT2, m_maxn);
	DDX_Text(pDX, IDC_EDIT1, m_minn);
	DDX_Text(pDX, IDC_EDIT4, m_price);
	DDX_Text(pDX, IDC_EDIT3, m_gcode);
}


BEGIN_MESSAGE_MAP(CAddGoodsDlg, CDialog)
END_MESSAGE_MAP()


// CAddGoodsDlg 消息处理程序
