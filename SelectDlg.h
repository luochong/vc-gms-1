#pragma once
#include "afxwin.h"


// CSelectDlg 对话框

class CSelectDlg : public CDialog
{
	DECLARE_DYNAMIC(CSelectDlg)

public:
	CSelectDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelectDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_gname;
	CString m_gcode;
	CListBox m_listbox;
	CString m_gnameEx;

	bool isgoods;
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	CString m_title;
};
