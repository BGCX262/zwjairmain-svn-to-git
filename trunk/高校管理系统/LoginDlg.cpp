// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "��У����ϵͳ.h"
#include "LoginDlg.h"
#include "LoginSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDatabase m_database;
CString m_ID;
/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_userID = _T("");
	m_userpassword = _T("");
	m_usertype = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Text(pDX, IDC_EDIT_USER_NAME, m_userID);
	DDX_Text(pDX, IDC_EDIT_USER_PASSWORD, m_userpassword);
	DDX_CBString(pDX, IDC_COMBO_TYPE, m_usertype);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

BOOL CLoginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	LOGFONT LogFont;
	GetFont()->GetLogFont(&LogFont);
	LogFont.lfHeight+=LogFont.lfHeight/2;
	LogFont.lfWidth+=LogFont.lfWidth/2;
	LoginFont.CreateFontIndirect(&LogFont);
	GetDlgItem(IDC_STATIC_LOGINTEXT)->SetFont(&LoginFont);
	return TRUE;
}

void CLoginDlg::OnOK() 
{
	// TODO: Add extra validation here
	BOOL bLogin=FALSE;
	CLoginSet *m_recordset=new CLoginSet(&m_database);
	CString strSQL;
	int type=0;
	UpdateData(TRUE);
	if (m_usertype.Compare("ѧ��")==0)
		type=1;
	else
	{
		if (m_usertype.Compare("��ʦ")==0)
		{
			type=2;
		} 
		else
		{
			if(m_usertype.Compare("����Ա")==0)
				type=3;
		}
	}
	strSQL.Format("select * from USERS \
		where USER_ID='%s' AND USER_PASSWORD='%s' \
		AND	USER_TYPE='%d'",m_userID,m_userpassword,type);
		m_recordset->Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
	if (m_recordset->GetRecordCount()==0)
	{
		if(count<3)
		{
			MessageBox("�û��������벻��ȷ");
			count++;
		}
		else
		{
			MessageBox("����������������ϣ�","�����ڼ����ر�");
			EndDialog(IDCANCEL);
		}
	} 
	else
	{
		m_recordset->GetFieldValue("USER_ID",m_ID);
		bLogin=TRUE;
	}
	if(bLogin)
	{
		//		MessageBox("��ӭ�����У�������ϵͳ��",m_username);
		EndDialog(IDOK)	;
	}
	else
		m_database.Close();
}
