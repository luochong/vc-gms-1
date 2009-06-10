// GMSRole.h: interface for the CGMSRole class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GMSROLE_H__632811DE_11CF_492D_949B_0D1B2F076198__INCLUDED_)
#define AFX_GMSROLE_H__632811DE_11CF_492D_949B_0D1B2F076198__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#define 


//role
#define SUPER_ADMIN 1
#define IN_ADMIN 2
#define OUT_ADMIN 3



#include "stdafx.h"
#define B 32
#define SHIFT 5
#define M 0x1F
#define N 32



//action

typedef int ACTION;
#define IN_ACTION       1
#define OUT_ACTION      2
#define GOODS_ACTION    3
#define CATE_ACTION     4
#define ADMIN_ACTION    5
class CGMSRole  
{



public:
	CGMSRole();
	virtual ~CGMSRole();
	static CGMSRole* Instance();
	static CGMSRole* _instance;

	static void freeInstance(){

		free(_instance);
	}


	bool Login(CString Admin_name, CString Admin_password);
	int HaveAction(ACTION i){ return a[i>>SHIFT] & (1<<(i & M));}

	CString m_admin_name;
	CString m_admin_code;


	


private:
	int m_admin_role;

	int a[1 + N/B];	
	void SetAction(ACTION i){ a[i>>SHIFT] |= (1<<(i & M)); }
	void ClrAction(ACTION i){ a[i>>SHIFT] &= ~(1<<(i & M)); }

	void SetRoleAction();

	
	
};

#endif // !defined(AFX_GMSROLE_H__632811DE_11CF_492D_949B_0D1B2F076198__INCLUDED_)
