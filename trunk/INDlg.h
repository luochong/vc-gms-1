#include "afxcmn.h"
#if !defined(AFX_INDLG_H__5F187D80_3485_4C8C_8566_2BCEE8720656__INCLUDED_)
#define AFX_INDLG_H__5F187D80_3485_4C8C_8566_2BCEE8720656__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// INDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CINDlg dialog

class CINDlg : public CDialog
{
// Construction
public:
	CINDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CINDlg)
	enum { IDD = IDD_DIALOG_IN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CINDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CINDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listctrl;
	afx_msg void OnBnClickedButtonSelect();
	CString m_gcode;
	int m_gno;
	float m_price;
	CString m_pcode;
	CString m_gname;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	CListCtrl m_glistctrl;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INDLG_H__5F187D80_3485_4C8C_8566_2BCEE8720656__INCLUDED_)
