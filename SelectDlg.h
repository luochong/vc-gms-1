#pragma once
#include "afxwin.h"


// CSelectDlg �Ի���

class CSelectDlg : public CDialog
{
	DECLARE_DYNAMIC(CSelectDlg)

public:
	CSelectDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelectDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
