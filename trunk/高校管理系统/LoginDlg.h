#if !defined(AFX_LOGINDLG_H__B747BE60_3569_4DA5_84F9_4042F1788AEB__INCLUDED_)
#define AFX_LOGINDLG_H__B747BE60_3569_4DA5_84F9_4042F1788AEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog

class CLoginDlg : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	CLoginDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginDlg)
	enum { IDD = IDD_DIALOG };
	int count;
	CString	m_userID;
	CString	m_userpassword;
	CString	m_usertype;
	//}}AFX_DATA

private:
	CFont LoginFont;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__B747BE60_3569_4DA5_84F9_4042F1788AEB__INCLUDED_)
