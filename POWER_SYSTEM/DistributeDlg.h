#pragma once
#include "User.h"
#include "Character.h"
#include "afxwin.h"

// CDistributeDlg 对话框

class CDistributeDlg : public CDialog
{
	DECLARE_DYNAMIC(CDistributeDlg)

public:
	CDistributeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDistributeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DISTRIBUTE_CHARACTER };
#endif

private:
	CRect rc;
	User* user;
	Character* character;
	vector<CWnd*> item_list;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CListBox listA;
	CListBox listB;
	void setLists(bool is_character);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
