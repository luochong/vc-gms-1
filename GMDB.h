#pragma once

class CGMDB
{
public:
	CGMDB(void);
	~CGMDB(void);
	bool UpdateGoods(int num,char operation,CString g_code,CString &Errmsg);
};
