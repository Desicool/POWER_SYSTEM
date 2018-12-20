#pragma once
#include "User.h"

// InfoDlg 对话框
class InfoDlg : public CDialog
{
	DECLARE_DYNAMIC(InfoDlg)

public:
	InfoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~InfoDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PERSONAL_INFO };
#endif
private:
	CRect rc;
	User* user;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedQuitButton();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
