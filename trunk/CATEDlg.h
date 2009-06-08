#if !defined(AFX_CATEDLG_H__C9D216A1_7588_4F5B_962E_81813DFBDB26__INCLUDED_)
#define AFX_CATEDLG_H__C9D216A1_7588_4F5B_962E_81813DFBDB26__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CATEDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCATEDlg dialog

class CCATEDlg : public CDialog
{
// Construction
public:
	CCATEDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCATEDlg)
	enum { IDD = IDD_DIALOG_CATE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCATEDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCATEDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CATEDLG_H__C9D216A1_7588_4F5B_962E_81813DFBDB26__INCLUDED_)
