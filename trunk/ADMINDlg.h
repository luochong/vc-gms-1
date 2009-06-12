#include "afxcmn.h"
#include "afxwin.h"
#if !defined(AFX_ADMINDLG_H__B0A35DB4_0A52_493A_B42B_3CE8108B3E57__INCLUDED_)
#define AFX_ADMINDLG_H__B0A35DB4_0A52_493A_B42B_3CE8108B3E57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ADMINDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CADMINDlg dialog

class CADMINDlg : public CDialog
{
// Construction
public:
	CADMINDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CADMINDlg)
	enum { IDD = IDD_DIALOG_ADMIN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADMINDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CADMINDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CString m_acode;
	CString m_aname;
	CString m_apassword;
	CString m_arepassword;
	CString m_accode;
	CListCtrl m_listctrl;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	CComboBox m_combobox;
	afx_msg void OnBnClickedButton2();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADMINDLG_H__B0A35DB4_0A52_493A_B42B_3CE8108B3E57__INCLUDED_)
