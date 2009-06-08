// GMSRole.cpp: implementation of the CGMSRole class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "mygms.h"
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
   for(int i = 0; i < N; i++)
   {
    ClrAction(i);
   }
   m_admin_code = "";
   m_admin_name = "";
   m_admin_role = 0;
   
}

CGMSRole::~CGMSRole()
{
 
   
}

/**

管理员登录

**/
bool CGMSRole::Login(CString Admin_name,CString Admin_password){	
	
	_variant_t strQuery;	
	strQuery = "SELECT * FROM admin WHERE Admin_name='"+Admin_name+ "' AND Admin_passwd='" + Admin_password+ "'";
	theApp.ADOExecute(theApp.m_pRs, strQuery);
    int iCount = theApp.m_pRs->GetRecordCount();
	_variant_t Holder;
	
	if ( 0==iCount ) 
	{
		return false;
		
	}
	else
	{
		
		Holder = theApp.m_pRs->GetCollect("Admin_code");		
		this->m_admin_code =  (char*)(_bstr_t)Holder;
		Holder = theApp.m_pRs->GetCollect("Admin_name");		
		this->m_admin_name = (char*)(_bstr_t)Holder;
		Holder = theApp.m_pRs->GetCollect("Admin_role");		
		this->m_admin_role = Holder.intVal;		
		return true;
	}
	SetRoleAction();

}
/**

管理员登录

**/
void CGMSRole::SetRoleAction(){		
	switch(m_admin_role){
			case SUPER_ADMIN: 
				SetAction(OUT_ACTION) ;
				SetAction(IN_ACTION) ;
				SetAction(GOODS_ACTION) ;
				SetAction(CATE_ACTION) ;
				break;
			case IN_ADMIN:
				
				SetAction(IN_ACTION);
				SetAction(CATE_ACTION);	
				break;
			case OUT_ADMIN:
				SetAction(OUT_ACTION);
				SetAction(CATE_ACTION);
				break;
	}

	
}

CGMSRole*     CGMSRole::_instance   =   0;
CGMSRole* CGMSRole::Instance(){ 

         if(!_instance)
         {

                     _instance = new CGMSRole();

         }
        return _instance;

}