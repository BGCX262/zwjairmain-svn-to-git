// CUserChange.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "UserChange.h"
#include "LoginSet.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserChange

IMPLEMENT_DYNCREATE(CUserChange, CFormView)

extern CDatabase m_database;
extern CString m_ID;

CUserChange::CUserChange()
	: CFormView(CUserChange::IDD)
{
	//{{AFX_DATA_INIT(UserChange)
	m_old = _T("");
	m_new = _T("");
	m_new_sure = _T("");
	//}}AFX_DATA_INIT
}

CUserChange::~CUserChange()
{
}

void CUserChange::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserChange)
	DDX_Text(pDX, IDC_EDIT_OLD, m_old);
	DDX_Text(pDX, IDC_EDIT_NEW, m_new);
	DDX_Text(pDX, IDC_EDIT_NEW_SURE, m_new_sure);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserChange, CFormView)
	//{{AFX_MSG_MAP(UserChange)
	ON_BN_CLICKED(ID_BUTTON_CHANGE, OnButtonChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserChange diagnostics

#ifdef _DEBUG
void CUserChange::AssertValid() const
{
	CFormView::AssertValid();
}

void CUserChange::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// UserChange message handlers

void CUserChange::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(FALSE);
	GetParentFrame()->SetWindowText("修改密码");
	LOGFONT LogFont;
	GetFont()->GetLogFont(&LogFont);
	LogFont.lfHeight+=LogFont.lfHeight/2;
	LogFont.lfWidth+=LogFont.lfHeight/2;
	Font.CreateFontIndirect(&LogFont);
	GetDlgItem(IDC_STATIC_USER_CHANGE)->SetFont(&Font);
}

void CUserChange::OnButtonChange() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CLoginSet m_recordset(&m_database);
	CString strSQL;
	strSQL.Format("select * from USERS \
		where USER_ID='%s' AND USER_PASSWORD='%s'",m_ID,m_old);
		m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
	if (m_recordset.GetRecordCount()==0)
	{
		MessageBox("旧密码不正确，请重新输入!");
		m_old="";
		UpdateData(FALSE);
	}
	else
		if (strcmp(m_new,m_new_sure)==0)
		{ 
			strSQL.Format("update USERS set USER_PASSWORD='%s' \
				where USER_ID='%s'",m_new,m_ID);
				m_database.ExecuteSQL(strSQL);
			MessageBox("密码修改成功");
			(((CMainFrame *)AfxGetMainWnd())->m_pUserChange->DestroyWindow());
		} 
		else
		{
			MessageBox("两次输入密码不相等，请重新输入！");
			m_new="";
			m_new_sure="";
			UpdateData(FALSE);
		}
}

void CUserChange::OnDestroy()
{
	CFormView:OnDestroy();
	((CMainFrame *)AfxGetMainWnd())->m_bItemUserChange=TRUE;
	((CMainFrame *)AfxGetMainWnd())->m_pUserChange=NULL;
}

