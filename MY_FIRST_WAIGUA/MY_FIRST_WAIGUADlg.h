
// MY_FIRST_WAIGUADlg.h : ͷ�ļ�
//

#pragma once


// CMY_FIRST_WAIGUADlg �Ի���
class CMY_FIRST_WAIGUADlg : public CDialogEx
{
// ����
public:
	CMY_FIRST_WAIGUADlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_FIRST_WAIGUA_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	DWORD FindGameProcessIdByWndTitle(CString strTitle);
	
	HANDLE GetProcessHandle(int nID);
		  //FindGameProcessIdByWndTitle

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
