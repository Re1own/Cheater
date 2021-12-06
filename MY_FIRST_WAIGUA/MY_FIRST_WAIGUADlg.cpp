
// MY_FIRST_WAIGUADlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MY_FIRST_WAIGUA.h"
#include "MY_FIRST_WAIGUADlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMY_FIRST_WAIGUADlg 对话框




CMY_FIRST_WAIGUADlg::CMY_FIRST_WAIGUADlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMY_FIRST_WAIGUADlg::IDD, pParent)
	, Value1(0)
	, no_cd(FALSE)
	, dabusi(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMY_FIRST_WAIGUADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Value1);
	DDX_Check(pDX, IDC_CHECK1, no_cd);
	DDX_Check(pDX, IDC_CHECK3, dabusi);
}

BEGIN_MESSAGE_MAP(CMY_FIRST_WAIGUADlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMY_FIRST_WAIGUADlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMY_FIRST_WAIGUADlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMY_FIRST_WAIGUADlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_CHECK1, &CMY_FIRST_WAIGUADlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CMY_FIRST_WAIGUADlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CMY_FIRST_WAIGUADlg::OnBnClickedCheck3)
END_MESSAGE_MAP()


// CMY_FIRST_WAIGUADlg 消息处理程序

BOOL CMY_FIRST_WAIGUADlg::OnInitDialog()
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMY_FIRST_WAIGUADlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMY_FIRST_WAIGUADlg::OnPaint()
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
HCURSOR CMY_FIRST_WAIGUADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

DWORD CMY_FIRST_WAIGUADlg::FindGameProcessIdByWndTitle(CString strTitle) {
	HWND hWnd = ::FindWindow(NULL, strTitle.GetBuffer());
	if (!hWnd) {
		MessageBox(_T("未找到指定游戏窗口"), NULL, 0);
		return 0;
	}
	DWORD dwPid = 0;
	GetWindowThreadProcessId(hWnd, &dwPid);
	return dwPid;
}

void CMY_FIRST_WAIGUADlg::OnBnClickedButton1()	//鬼泣血量地址:[[046DE2E0]+0x10]+0x8
{
	
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	
	DWORD dwPid = FindGameProcessIdByWndTitle(_T("Devil May Cry HD Collection"));
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,dwPid);
	if (!hProcess) {
		MessageBox(_T("游戏进程失败"), NULL, 0);
		return;
	}

	DWORD dwTemp = 0;
	if (!ReadProcessMemory(hProcess,
		(LPVOID)0x046DE2E0,
		(LPVOID)&dwTemp,
		sizeof(DWORD),
		&dwPid))
	{
		MessageBox(_T("读取游戏进程失败"), NULL, 0);
		CloseHandle(hProcess);
		return;
	}

	dwTemp += 0x10;
	if (!ReadProcessMemory(hProcess,
		(LPVOID)dwTemp,
		(LPVOID)&dwTemp,
		sizeof(DWORD),
		&dwPid))
	{
		MessageBox(_T("读取游戏进程失败"), NULL, 0);
		CloseHandle(hProcess);
		return;
	}

	DWORD dwSun = 1169915904;
	dwTemp += 0x8;
	DWORD dwlen = 0;
	if (!::WriteProcessMemory(hProcess, (LPVOID)(dwTemp), &dwSun, sizeof(DWORD), NULL)) {
		MessageBox(_T("写入失败"),NULL, 0);
		CloseHandle(hProcess);
		return;
	}
	CloseHandle(hProcess);

}



void CMY_FIRST_WAIGUADlg::OnBnClickedButton2()
{
		// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	
	DWORD dwPid = FindGameProcessIdByWndTitle(_T("Devil May Cry HD Collection"));
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,dwPid);
	if (!hProcess) {
		MessageBox(_T("游戏进程失败"), NULL, 0);
		return;
	}

	DWORD dwTemp = 0;
	if (!ReadProcessMemory(hProcess,
		(LPVOID)0x046DE2E0,
		(LPVOID)&dwTemp,
		sizeof(DWORD),
		&dwPid))
	{
		MessageBox(_T("读取游戏进程失败"), NULL, 0);
		CloseHandle(hProcess);
		return;
	}

	dwTemp += 0x10;
	if (!ReadProcessMemory(hProcess,
		(LPVOID)dwTemp,
		(LPVOID)&dwTemp,
		sizeof(DWORD),
		&dwPid))
	{
		MessageBox(_T("读取游戏进程失败"), NULL, 0);
		CloseHandle(hProcess);
		return;
	}

	DWORD dwSun = 1169915904;
	dwTemp += 0x8;
	if (!::WriteProcessMemory(hProcess, (LPVOID)(dwTemp), &dwSun, sizeof(DWORD), NULL)) {
		MessageBox(_T("写入失败"),NULL, 0);
		CloseHandle(hProcess);
		return;
	}
	CloseHandle(hProcess);
}


void CMY_FIRST_WAIGUADlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMY_FIRST_WAIGUADlg::OnBnClickedCheck1()	//植物大战僵尸冷却
{
	UpdateData(TRUE);
	
	DWORD dwPid = FindGameProcessIdByWndTitle(_T("Plants vs. Zombies"));
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,dwPid);
	if (!hProcess) {
		MessageBox(_T("游戏进程失败"), NULL, 0);
		return;
	}
	
	UCHAR buf[2] = {0};
	if (no_cd) {
		buf[0] =0x90;
		buf[1] = 0x90;
	}
	else {
		buf[0] = 0x7E;
		buf[1] = 0x16;
	}
	if (!::WriteProcessMemory(hProcess, (LPVOID)(0x0049CE02), buf, sizeof(buf), NULL)) {
		MessageBox(_T("写入失败"),NULL, 0);
		CloseHandle(hProcess);
		return;
	}
	CloseHandle(hProcess);
}


void CMY_FIRST_WAIGUADlg::OnBnClickedCheck2()
{

}


void CMY_FIRST_WAIGUADlg::OnBnClickedCheck3()
{
	UpdateData(TRUE);
	
	DWORD dwPid = FindGameProcessIdByWndTitle(_T("Devil May Cry HD Collection"));
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,dwPid);
	if (!hProcess) {
		MessageBox(_T("游戏进程失败"), NULL, 0);
		return;
	}
	
	BYTE buf[4] = {0};
	if (dabusi) {
		buf[0] = 0x90;
		buf[1] = 0x90;
		buf[2] = 0x90;
		buf[3] = 0x90;
	}
	else {
		buf[0] = 0x48;
		buf[1] = 0x8B;
		buf[2] = 0x43;
		buf[3] = 0x10;
	}
	if (!::WriteProcessMemory(hProcess, (LPVOID)(0x7FF71634851C), buf, sizeof(buf), NULL)) {
		MessageBox(_T("写入失败"),NULL, 0);
		CloseHandle(hProcess);
		return;
	}
	CloseHandle(hProcess);
}
