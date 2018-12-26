
// POWER_SYSTEMDlg.cpp : 实现文件
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
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CPOWER_SYSTEMDlg 对话框



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


// CPOWER_SYSTEMDlg 消息处理程序

BOOL CPOWER_SYSTEMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	m_Font = new CFont();
	/*m_Font->
		CreateFont(20, 25, 0, 0, 100, FALSE, FALSE, 0, ANSI_CHARSET, 
			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
			FF_SWISS, LPCTSTR("Arial"));*/
	//字体高度，字体宽度，，，字体的磅数，...,字体的名称
	m_Font->
		CreatePointFont(180, LPCTSTR("Arial"), NULL);
	GetDlgItem(IDC_LOGINNAME)->SetFont(m_Font, FALSE);
	GetDlgItem(IDC_LOGIN_NAME_INPUT)->SetFont(m_Font, NULL);
	GetDlgItem(IDC_PASSWORD)->SetFont(m_Font, FALSE);
	GetDlgItem(IDC_PWD_INPUT)->SetFont(m_Font, FALSE);
	((CEdit*)GetDlgItem(IDC_PWD_INPUT))->SetPasswordChar(L'*');
	//m_Edit->SetFont(m_Font);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPOWER_SYSTEMDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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

