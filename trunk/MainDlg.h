#if !defined(AFX_MAINDLG_H__9820EA0E_F2C9_4DC9_9A27_2EA4F0052CDD__INCLUDED_)
#define AFX_MAINDLG_H__9820EA0E_F2C9_4DC9_9A27_2EA4F0052CDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainDlg.h : header file
//
#include "INDlg.h"
#include "OUTDlg.h"
#include "LOGDlg.h"
#include "ADMINDlg.h"
#include "CATEDlg.h"
#include "GMDlg.h"


/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog

class CMainDlg : public CDialog
{
// Construction
public:
	CMainDlg(CWnd* pParent = NULL);   // standard constructor
	CINDlg indlg;
	COUTDlg outdlg;
	CLOGDlg logdlg;
	CADMINDlg admindlg;
	CCATEDlg catedlg;
	CGMDlg gmdlg;
// Dialog Data
	//{{AFX_DATA(CMainDlg)
	enum { IDD = IDD_DIALOG_MAIN };
	CTabCtrl	m_tabctrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMainDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDLG_H__9820EA0E_F2C9_4DC9_9A27_2EA4F0052CDD__INCLUDED_)
