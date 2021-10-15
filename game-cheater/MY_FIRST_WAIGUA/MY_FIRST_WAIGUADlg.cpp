
// MY_FIRST_WAIGUADlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MY_FIRST_WAIGUA.h"
#include "MY_FIRST_WAIGUADlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMY_FIRST_WAIGUADlg �Ի���




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


// CMY_FIRST_WAIGUADlg ��Ϣ�������

BOOL CMY_FIRST_WAIGUADlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMY_FIRST_WAIGUADlg::OnPaint()
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
HCURSOR CMY_FIRST_WAIGUADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

DWORD CMY_FIRST_WAIGUADlg::FindGameProcessIdByWndTitle(CString strTitle) {
	HWND hWnd = ::FindWindow(NULL, strTitle.GetBuffer());
	if (!hWnd) {
		MessageBox(_T("δ�ҵ�ָ����Ϸ����"), NULL, 0);
		return 0;
	}
	DWORD dwPid = 0;
	GetWindowThreadProcessId(hWnd, &dwPid);
	return dwPid;
}

void CMY_FIRST_WAIGUADlg::OnBnClickedButton1()	//����Ѫ����ַ:[[046DE2E0]+0x10]+0x8
{
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	
	DWORD dwPid = FindGameProcessIdByWndTitle(_T("Devil May Cry HD Collection"));
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,dwPid);
	if (!hProcess) {
		MessageBox(_T("��Ϸ����ʧ��"), NULL, 0);
		return;
	}

	DWORD dwTemp = 0;
	if (!ReadProcessMemory(hProcess,
		(LPVOID)0x046DE2E0,
		(LPVOID)&dwTemp,
		sizeof(DWORD),
		&dwPid))
	{
		MessageBox(_T("��ȡ��Ϸ����ʧ��"), NULL, 0);
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
		MessageBox(_T("��ȡ��Ϸ����ʧ��"), NULL, 0);
		CloseHandle(hProcess);
		return;
	}

	DWORD dwSun = 1169915904;
	dwTemp += 0x8;
	DWORD dwlen = 0;
	if (!::WriteProcessMemory(hProcess, (LPVOID)(dwTemp), &dwSun, sizeof(DWORD), NULL)) {
		MessageBox(_T("д��ʧ��"),NULL, 0);
		CloseHandle(hProcess);
		return;
	}
	CloseHandle(hProcess);

}



void CMY_FIRST_WAIGUADlg::OnBnClickedButton2()
{
		// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	
	DWORD dwPid = FindGameProcessIdByWndTitle(_T("Devil May Cry HD Collection"));
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,dwPid);
	if (!hProcess) {
		MessageBox(_T("��Ϸ����ʧ��"), NULL, 0);
		return;
	}

	DWORD dwTemp = 0;
	if (!ReadProcessMemory(hProcess,
		(LPVOID)0x046DE2E0,
		(LPVOID)&dwTemp,
		sizeof(DWORD),
		&dwPid))
	{
		MessageBox(_T("��ȡ��Ϸ����ʧ��"), NULL, 0);
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
		MessageBox(_T("��ȡ��Ϸ����ʧ��"), NULL, 0);
		CloseHandle(hProcess);
		return;
	}

	DWORD dwSun = 1169915904;
	dwTemp += 0x8;
	if (!::WriteProcessMemory(hProcess, (LPVOID)(dwTemp), &dwSun, sizeof(DWORD), NULL)) {
		MessageBox(_T("д��ʧ��"),NULL, 0);
		CloseHandle(hProcess);
		return;
	}
	CloseHandle(hProcess);
}


void CMY_FIRST_WAIGUADlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CMY_FIRST_WAIGUADlg::OnBnClickedCheck1()	//ֲ���ս��ʬ��ȴ
{
	UpdateData(TRUE);
	
	DWORD dwPid = FindGameProcessIdByWndTitle(_T("Plants vs. Zombies"));
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,dwPid);
	if (!hProcess) {
		MessageBox(_T("��Ϸ����ʧ��"), NULL, 0);
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
		MessageBox(_T("д��ʧ��"),NULL, 0);
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
		MessageBox(_T("��Ϸ����ʧ��"), NULL, 0);
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
		MessageBox(_T("д��ʧ��"),NULL, 0);
		CloseHandle(hProcess);
		return;
	}
	CloseHandle(hProcess);
}
