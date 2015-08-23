// CStudentInfo.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "StudentInfo.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentInfo

IMPLEMENT_DYNCREATE(CStudentInfo, CFormView)

extern CDatabase m_database;
extern CString m_ID;

CStudentInfo::CStudentInfo()
	: CFormView(CStudentInfo::IDD)
{
	//{{AFX_DATA_INIT(StudentInfo)
	m_party = -1;
	m_sex = -1;
	m_address = _T("");
	m_department = _T("");
	m_hometown = _T("");
	m_number = _T("");
	m_major = _T("");
	m_name = _T("");
	m_other = _T("");
	m_phone = _T("");
	m_race = _T("");

	b_address = FALSE;
	b_birthday = FALSE;
	b_department = FALSE;
	b_hometown = FALSE;
	b_major = FALSE;
	b_other = FALSE;
	b_party = FALSE;
	b_phone = FALSE;
	b_race = FALSE;
	b_sex = FALSE;
	b_starttime = FALSE;
	//}}AFX_DATA_INIT
}

CStudentInfo::~CStudentInfo()
{
}

void CStudentInfo::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(StudentInfo)
	DDX_Control(pDX, IDC_COMBO_SEX, m_c_sex);
	DDX_Control(pDX, IDC_COMBO_PARTY, m_c_party);
	DDX_CBString(pDX, IDC_COMBO_PARTY, m_party);
	DDX_CBString(pDX, IDC_COMBO_SEX, m_sex);
//	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_BIRTHDAY, m_birthday);
//	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_START, m_starttime);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_address);
	DDX_Text(pDX, IDC_EDIT_DEPARTMENT, m_department);
	DDX_Text(pDX, IDC_EDIT_HOMETOWN, m_hometown);
	DDX_Text(pDX, IDC_EDIT_ID, m_number);
	DDX_Text(pDX, IDC_EDIT_MAJOR, m_major);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_OTHER, m_other);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_phone);
	DDX_Text(pDX, IDC_EDIT_RACE, m_race);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStudentInfo, CFormView)
	//{{AFX_MSG_MAP(StudentInfo)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// StudentInfo diagnostics

#ifdef _DEBUG
void CStudentInfo::AssertValid() const
{
	CFormView::AssertValid();
}

void CStudentInfo::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// StudentInfo message handlers

void CStudentInfo::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(FALSE);
	GetParentFrame()->SetWindowText("学籍管理");
	LOGFONT LogFont;
	GetFont()->GetLogFont(&LogFont);
	LogFont.lfHeight+=LogFont.lfHeight/2;
	LogFont.lfWidth+=LogFont.lfHeight/2;
	Font.CreateFontIndirect(&LogFont);
	GetDlgItem(IDC_STATIC_USER_CHANGE)->SetFont(&Font);
	initial();
}

void CStudentInfo::initial()
{
	CDBVariant varValue;
	CRecordset m_recordset(&m_database);
	CString strSQL;
	strSQL.Format("select BIRTHDAY from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("BIRTHDAY",varValue);
	m_birthday.SetTime(COleDateTime(
		varValue.m_pdate->year,varValue.m_pdate->month,varValue.m_pdate->day,0,0,0));
	m_recordset.Close();
	
	strSQL.Format("select ENROLLMENT_TIME \
		from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("ENROLLMENT",varValue);
	m_starttime.SetTime(COleDateTime(
		varValue.m_pdate->year,varValue.m_pdate->month,varValue.m_pdate->day,0,0,0));
	m_recordset.Close();
	
	strSQL.Format("select ADDRESS \
		from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("ADDRESS",m_address);
	m_recordset.Close();
	
	strSQL.Format("select DEPARTMENT \
		from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("DEPARTMENT",m_department);
	m_recordset.Close();
	
	strSQL.Format("select HOMETOWN \
		from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("HOMETOWN",m_hometown);
	m_recordset.Close();
	
	strSQL.Format("select MAJOR \
		from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("MAJOR",m_major);
	m_recordset.Close();
	
	strSQL.Format("select STU_NAME \
		from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("STU_NAME",m_name);
	m_recordset.Close();
	
	strSQL.Format("select STU_ID \
		from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("STU_ID",m_number);
	m_recordset.Close();
	
	strSQL.Format("select DIRECTION \
		from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("DIRECTION",m_other);
	m_recordset.Close();
	
	strSQL.Format("select PHONE \
		from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("PHONE",m_phone);
	m_recordset.Close();
	
	strSQL.Format("select RACE \
		from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("RACE",m_race);
	m_recordset.Close();
	
	strSQL.Format("select SEX \
		from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("SEX",varValue);
	m_sex=varValue.m_iVal;
	m_recordset.Close();
	
	strSQL.Format("select PARTY \
		from STUDENT_INFO where STU_ID='%s'",m_ID);
		m_recordset.Open(CRecordset::forwardOnly,strSQL);
	m_recordset.GetFieldValue("PARTY",varValue);
	m_party=varValue.m_iVal;
	m_recordset.Close();
	
	UpdateData(FALSE);
}


