#pragma once
#include "afxwin.h"
#include "User.h"
#include "POWER_SYSTEMDlg.h"
#include <vector>
// CUpdate �Ի���

class CUpdate : public CDialog
{
	DECLARE_DYNAMIC(CUpdate)

public:
	CUpdate(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUpdate();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UPDATE };
#endif
private:
	CRect rc;
	User* user;
	vector<CWnd*> item_list;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox user_list;
	CButton ban_button;
	CButton free_button;
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedBanButton();
};
