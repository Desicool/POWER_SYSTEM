#pragma once
#include "User.h"

// InfoDlg �Ի���
class InfoDlg : public CDialog
{
	DECLARE_DYNAMIC(InfoDlg)

public:
	InfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~InfoDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PERSONAL_INFO };
#endif
private:
	CRect rc;
	User* user;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedQuitButton();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
