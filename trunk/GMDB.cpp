#include "stdafx.h"
#include ".\gmdb.h"
#include "mygms.h"

CGMDB::CGMDB(void)
{
}

CGMDB::~CGMDB(void)
{
}
bool CGMDB::UpdateGoods(int num,char operation,CString g_code,CString &Errmsg)
{
	
	CString strSql;

	strSql.Format("SELECT Current_number,Min_number,Max_number FROM goods WHERE G_code = '%s'",g_code);
	_variant_t  vtQuery(strSql),holder;  
		
	theApp.ADOExecute(theApp.m_pRs,vtQuery);
	
	int cn,maxn,minn;
	
	holder = theApp.m_pRs->GetCollect("Current_number");
	cn = holder.intVal;
	
	holder = theApp.m_pRs->GetCollect("Min_number");
	minn = holder.intVal;
	
	holder = theApp.m_pRs->GetCollect("Max_number");
	maxn = holder.intVal; 
	
	if(operation == '+'){
		cn = cn + num;
		if(cn > maxn){
            Errmsg = "����Ѿ����ˣ�";
			return false;
		}
		Errmsg = "���ɹ���";

	}else if(operation == '-'){
		cn = cn - num;
		if(cn < 0 ){
			Errmsg = "����û����ô����Ʒ���뼰ʱ���䣡";
			return false;
		
		}		
		Errmsg  = "ȡ���ɹ���";		
		if(cn < minn){
			Errmsg += "\n��ʾ ����治�㣬�뼰ʱ���䣡";			

		}	
	}
    strSql.Format("UPDATE goods set Current_number = %d WHERE G_code = '%s'",cn ,g_code);
	
	
	
	vtQuery = (_bstr_t)strSql;


	return theApp.ADOExecute(theApp.m_pRs,vtQuery);
}