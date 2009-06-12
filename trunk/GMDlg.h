#include "afxcmn.h"
#if !defined(AFX_GMDLG_H__86579139_748F_4E47_A748_E23198E11B07__INCLUDED_)
#define AFX_GMDLG_H__86579139_748F_4E47_A748_E23198E11B07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GMDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGMDlg dialog

class CGMDlg : public CDialog
{
// Construction
public:
	CGMDlg(CWnd* pParent = NULL);   // standard constructor
	DWORD   f_id; 
// Dialog Data
	//{{AFX_DATA(CGMDlg)
	enum { IDD = IDD_DIALOG_GM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGMDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listctrl;
	virtual BOOL OnInitDialog();
	CListCtrl m_wlistctrl;
	CTreeCtrl m_treectrl;
	void BuildTree(HTREEITEM fhtr, int fid);
	afx_msg void OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	void ShowList(_RecordsetPtr &pset, CListCtrl &m_list);
	afx_msg void OnNMRclickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMenuAdd();
	


	afx_msg void On32777();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GMDLG_H__86579139_748F_4E47_A748_E23198E11B07__INCLUDED_)
