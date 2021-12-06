
// MY_FIRST_WAIGUADlg.h : 头文件
//

#pragma once


// CMY_FIRST_WAIGUADlg 对话框
class CMY_FIRST_WAIGUADlg : public CDialogEx
{
// 构造
public:
	CMY_FIRST_WAIGUADlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_FIRST_WAIGUA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	DWORD FindGameProcessIdByWndTitle(CString strTitle);
	
	HANDLE GetProcessHandle(int nID);
		  //FindGameProcessIdByWndTitle

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	DWORD Value1;
	BOOL no_cd;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	BOOL dabusi;
};
