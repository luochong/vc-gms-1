#pragma once


// CAddGoodsDlg �Ի���

class CAddGoodsDlg : public CDialog
{
	DECLARE_DYNAMIC(CAddGoodsDlg)

public:
	CAddGoodsDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddGoodsDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_gname;
	int m_maxn;
	int m_minn;
	float m_price;


	CString m_gcode;
};
