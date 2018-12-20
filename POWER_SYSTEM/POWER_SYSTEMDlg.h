
// POWER_SYSTEMDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "User.h"
#include "Character.h"
// CPOWER_SYSTEMDlg 对话框
class CPOWER_SYSTEMDlg : public CDialogEx
{
// 构造
public:
	CFont* m_Font;
	CPOWER_SYSTEMDlg(CWnd* pParent = NULL);	// 标准构造函数
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POWER_SYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	User* user;
	Character* character;
public:
	afx_msg void Login();
	afx_msg void OnBnClickedButton2();
	User* getUser()
	{
		return user;
	}
	CEdit username_input;
	CEdit password_input;
};
