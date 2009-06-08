// mygms.h : main header file for the MYGMS application
//

#if !defined(AFX_MYGMS_H__1D4A8C61_26CF_4C1A_823D_7C8916C6692F__INCLUDED_)
#define AFX_MYGMS_H__1D4A8C61_26CF_4C1A_823D_7C8916C6692F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMygmsApp:
// See mygms.cpp for the implementation of this class
//

class CMygmsApp : public CWinApp
{
public:
	CMygmsApp();
	~CMygmsApp();
	_RecordsetPtr m_pRs;
	bool ADOExecute(_RecordsetPtr &ADOSet, _variant_t &strSQL);
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMygmsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMygmsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	// Define ADO Database Connnection
	_ConnectionPtr m_pConn;
};

extern CMygmsApp theApp;
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYGMS_H__1D4A8C61_26CF_4C1A_823D_7C8916C6692F__INCLUDED_)
