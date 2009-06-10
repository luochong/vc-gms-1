#include "afxcmn.h"
#if !defined(AFX_LOGDLG_H__5F746F12_20B4_41DC_AD7B_AB91CA834475__INCLUDED_)
#define AFX_LOGDLG_H__5F746F12_20B4_41DC_AD7B_AB91CA834475__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LOGDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLOGDlg dialog

class CLOGDlg : public CDialog
{
// Construction
public:
	CLOGDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLOGDlg)
	enum { IDD = IDD_DIALOG_LOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLOGDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLOGDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listctrl;
	virtual BOOL OnInitDialog();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGDLG_H__5F746F12_20B4_41DC_AD7B_AB91CA834475__INCLUDED_)
