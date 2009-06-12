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
            Errmsg = "库存已经满了！";
			return false;
		}
		Errmsg = "入库成功！";

	}else if(operation == '-'){
		cn = cn - num;
		if(cn < 0 ){
			Errmsg = "库中没有这么多商品，请及时补充！";
			return false;
		
		}		
		Errmsg  = "取货成功！";		
		if(cn < minn){
			Errmsg += "\n提示 ：库存不足，请及时补充！";			

		}	
	}
    strSql.Format("UPDATE goods set Current_number = %d WHERE G_code = '%s'",cn ,g_code);
	
	
	
	vtQuery = (_bstr_t)strSql;


	return theApp.ADOExecute(theApp.m_pRs,vtQuery);
}