#pragma once
#include "afxcmn.h"
#include "QueryDlg.h"
#include "InfoDlg.h"
#include "AddUserDlg.h"
#include "Update.h"
#include "DistributeDlg.h"
#include "AddCharacterDlg.h"
// POWER_SYSTEM_MAINFRAME 对话框
#include "POWER_SYSTEMDlg.h"
#include "User.h"
class POWER_SYSTEM_MAINFRAME : public CDialogEx
{
	DECLARE_DYNAMIC(POWER_SYSTEM_MAINFRAME)

public:
	POWER_SYSTEM_MAINFRAME(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~POWER_SYSTEM_MAINFRAME();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAINFRAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CFont* m_Font;
	User* user;
	Character* character;
	CQueryDlg query_page;
	InfoDlg info_page;
	CAddUserDlg add_user_page;
	CUpdate update_page;
	CDistributeDlg d_characterDlg;
	CAddCharacterDlg add_character_page;
public:
	int m_CurSelTab;
	CDialog* pDlgPage[20];
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	// 用于实现功能页面的切换
	CTabCtrl func_tab;
	afx_msg void OnTcnSelchangeFuncTab(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	User* getUser();
	void setUser(User* us);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnClose();
};
