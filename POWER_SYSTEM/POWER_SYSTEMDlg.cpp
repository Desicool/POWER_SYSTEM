
// POWER_SYSTEMDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "POWER_SYSTEM.h"
#include "POWER_SYSTEMDlg.h"
#include "afxdialogex.h"
#include "POWER_SYSTEM_MAINFRAME.h"
#include "Connection.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//extern User* user;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPOWER_SYSTEMDlg �Ի���



CPOWER_SYSTEMDlg::CPOWER_SYSTEMDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_POWER_SYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPOWER_SYSTEMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOGIN_NAME_INPUT, username_input);
	DDX_Control(pDX, IDC_PWD_INPUT, password_input);
}

BEGIN_MESSAGE_MAP(CPOWER_SYSTEMDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPOWER_SYSTEMDlg::Login)
	ON_BN_CLICKED(IDC_BUTTON2, &CPOWER_SYSTEMDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CPOWER_SYSTEMDlg ��Ϣ�������

BOOL CPOWER_SYSTEMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	m_Font = new CFont();
	/*m_Font->
		CreateFont(20, 25, 0, 0, 100, FALSE, FALSE, 0, ANSI_CHARSET, 
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
			FF_SWISS, LPCTSTR("Arial"));*/
	//����߶ȣ������ȣ���������İ�����...,���������
	m_Font->
		CreatePointFont(180, LPCTSTR("Arial"), NULL);
	GetDlgItem(IDC_LOGINNAME)->SetFont(m_Font, FALSE);
	GetDlgItem(IDC_LOGIN_NAME_INPUT)->SetFont(m_Font, NULL);
	GetDlgItem(IDC_PASSWORD)->SetFont(m_Font, FALSE);
	GetDlgItem(IDC_PWD_INPUT)->SetFont(m_Font, FALSE);
	((CEdit*)GetDlgItem(IDC_PWD_INPUT))->SetPasswordChar(L'*');
	//m_Edit->SetFont(m_Font);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPOWER_SYSTEMDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPOWER_SYSTEMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPOWER_SYSTEMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPOWER_SYSTEMDlg::Login()
{
	CString x, y;
	username_input.GetWindowText(x);
	password_input.GetWindowText(y);
	user = new User((LPCSTR)(CStringA)(x), (LPCSTR)(CStringA)(y));
	if (user->login() == OK)
	{
		character = new Character();
		character->init(user->getID());
		this->ShowWindow(SW_HIDE);
		POWER_SYSTEM_MAINFRAME tmp;
		tmp.DoModal();
		//tmp.setUser(user);
		this->ShowWindow(SW_SHOW);
	}
	SendMessage(WM_DESTROY);
}


void CPOWER_SYSTEMDlg::OnBnClickedButton2()
{
	OnCancel();
}

