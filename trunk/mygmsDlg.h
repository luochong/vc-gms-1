// mygmsDlg.h : header file
//

#if !defined(AFX_MYGMSDLG_H__D4AE76C2_1569_4B95_9DCD_C97BF7DAC21F__INCLUDED_)
#define AFX_MYGMSDLG_H__D4AE76C2_1569_4B95_9DCD_C97BF7DAC21F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMygmsDlg dialog

class CMygmsDlg : public CDialog
{
// Construction
public:
	CMygmsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMygmsDlg)
	enum { IDD = IDD_MYGMS_DIALOG };
	CString	m_password;
	CString	m_user;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMygmsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMygmsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYGMSDLG_H__D4AE76C2_1569_4B95_9DCD_C97BF7DAC21F__INCLUDED_)
