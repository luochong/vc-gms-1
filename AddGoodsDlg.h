#pragma once


// CAddGoodsDlg 对话框

class CAddGoodsDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddGoodsDlg)

public:
	CAddGoodsDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddGoodsDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_gname;
	int m_maxn;
	int m_minn;
	float m_price;


	CString m_gcode;
};
