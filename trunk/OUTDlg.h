#if !defined(AFX_OUTDLG_H__39825128_FEDE_46F2_BD0E_1E9B31840272__INCLUDED_)
#define AFX_OUTDLG_H__39825128_FEDE_46F2_BD0E_1E9B31840272__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OUTDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COUTDlg dialog

class COUTDlg : public CDialog
{
// Construction
public:
	COUTDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COUTDlg)
	enum { IDD = IDD_DIALOG_OUT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COUTDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COUTDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTDLG_H__39825128_FEDE_46F2_BD0E_1E9B31840272__INCLUDED_)
