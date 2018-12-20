
// POWER_SYSTEMDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "User.h"
#include "Character.h"
// CPOWER_SYSTEMDlg �Ի���
class CPOWER_SYSTEMDlg : public CDialogEx
{
// ����
public:
	CFont* m_Font;
	CPOWER_SYSTEMDlg(CWnd* pParent = NULL);	// ��׼���캯��
	
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POWER_SYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
