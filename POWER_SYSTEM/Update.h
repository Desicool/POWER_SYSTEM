#pragma once


// CUpdate �Ի���

class CUpdate : public CDialog
{
	DECLARE_DYNAMIC(CUpdate)

public:
	CUpdate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUpdate();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
