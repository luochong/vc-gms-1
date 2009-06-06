// GMSRole.h: interface for the CGMSRole class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GMSROLE_H__632811DE_11CF_492D_949B_0D1B2F076198__INCLUDED_)
#define AFX_GMSROLE_H__632811DE_11CF_492D_949B_0D1B2F076198__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#define 






class CGMSRole  
{
public:
	CGMSRole();
	virtual ~CGMSRole();

	CString Admin_name;
	CString Admin_code;
private:
	CString Admin_role; 

public:
	bool Login(CString Admin_name, CString Admin_password);
	
	
};

#endif // !defined(AFX_GMSROLE_H__632811DE_11CF_492D_949B_0D1B2F076198__INCLUDED_)
