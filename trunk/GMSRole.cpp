// GMSRole.cpp: implementation of the CGMSRole class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GMS.h"
#include "GMSRole.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGMSRole::CGMSRole()
{

}

CGMSRole::~CGMSRole()
{

}

/**

¹ÜÀíÔ±µÇÂ¼

**/
bool CGMSRole::Login(CString Admin_name,CString Admin_password){
	CString strSql;
	_variant_t strQuery;
	UpdateData(TRUE);
	strQuery = "SELECT * FROM admin WHERE Admin_name='"+m_strName+ "' AND Admin_passwd='" + m_strPasswd+ "'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	if ( 0==iCount ) 
	{
		return false;
		
	}
	else
	{
		return true;
	}
}