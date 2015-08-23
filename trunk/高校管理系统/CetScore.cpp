// CetScore.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "CetScore.h"
#include "MainFrm.h"
#include "CetScoreSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCetScore

IMPLEMENT_DYNCREATE(CCetScore, CFormView)

extern CDatabase m_database;
extern CString m_ID;

CCetScore::CCetScore()
	: CFormView(CCetScore::IDD)
{
	//{{AFX_DATA_INIT(CCetScore)
	m_type = _T("");
	m_cet4_score = _T("");
	m_cet4_state = _T("");
	m_cet6_score = _T("");
	m_cet6_state = _T("");
	m_date = _T("");
	m_direction = _T("");
	m_personID = _T("");
	m_place = _T("");
	m_stuID = _T("");
	m_stu_name = _T("");
	//}}AFX_DATA_INIT
}

CCetScore::~CCetScore()
{
}

void CCetScore::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCetScore)
	DDX_CBString(pDX, IDC_COMBO_TYPE, m_type);
	DDX_Text(pDX, IDC_EDIT_CET4_SCORE, m_cet4_score);
	DDX_Text(pDX, IDC_EDIT_CET4_STATE, m_cet4_state);
	DDX_Text(pDX, IDC_EDIT_CET6_SCORE, m_cet6_score);
	DDX_Text(pDX, IDC_EDIT_CET6_STATE, m_cet6_state);
	DDX_Text(pDX, IDC_EDIT_DATE, m_date);
	DDX_Text(pDX, IDC_EDIT_DIRECTION, m_direction);
	DDX_Text(pDX, IDC_EDIT_PERSON_ID, m_personID);
	DDX_Text(pDX, IDC_EDIT_PLACE, m_place);
	DDX_Text(pDX, IDC_EDIT_STU_ID, m_stuID);
	DDX_Text(pDX, IDC_EDIT_STU_NAME, m_stu_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCetScore, CFormView)
	//{{AFX_MSG_MAP(CCetScore)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCetScore diagnostics

#ifdef _DEBUG
void CCetScore::AssertValid() const
{
	CFormView::AssertValid();
}

void CCetScore::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCetScore message handlers

void CCetScore::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(FALSE);
	GetParentFrame()->SetWindowText("四六级成绩");
	LOGFONT LogFont;
	GetFont()->GetLogFont(&LogFont);
	LogFont.lfHeight+=LogFont.lfHeight/2;
	LogFont.lfWidth+=LogFont.lfHeight/2;
	Font.CreateFontIndirect(&LogFont);
	GetDlgItem(IDC_STATIC_CHOICE_COURSE)->SetFont(&Font);

	initial();
}

void CCetScore::initial()
{
	CDBVariant varValue;
	char buf[20];
	CCetScoreSet m_recordset(&m_database);
	CString strSQL;
	strSQL.Format("select * from CET_SCORE where STU_ID='%s')",m_ID);
	m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
	if(m_recordset.GetRecordCount()!=0)
		m_recordset.MoveFirst();
	if (!m_recordset.IsEOF())
	{
		int temp=0;
		m_recordset.GetFieldValue(temp,varValue);
		m_stuID=varValue.m_pstring->GetBuffer(1);
		m_recordset.GetFieldValue(1,varValue);
		m_stu_name=varValue.m_pstring->GetBuffer(1);
		m_recordset.GetFieldValue(3,varValue);
		if(varValue.m_iVal==0)
			m_cet4_state="未报名";
		else if (varValue.m_iVal==1)
			m_cet4_state="已报名";
		else if (varValue.m_iVal==2)
			m_cet4_state="已通过";
		
		
		m_recordset.GetFieldValue(4,varValue);
		if(varValue.m_iVal==0)
			m_cet6_state="未报名";
		else if (varValue.m_iVal==1)
			m_cet6_state="已报名";
		else if (varValue.m_iVal==2)
			m_cet6_state="已通过";
		
		m_recordset.GetFieldValue(5,varValue);
		m_place=varValue.m_pstring->GetBuffer(1);
		m_recordset.GetFieldValue(6,varValue);
		sprintf(buf,"%d-%d-%d",varValue.m_pdate->year,varValue.m_pdate->month,varValue.m_pdate->day);
		m_date=buf;
		m_recordset.GetFieldValue(7,varValue);
		if(varValue.m_iVal==0)
			m_cet6_score="无";
		else 
		{
			sprintf(buf,"%d",varValue.m_iVal);
			m_cet6_score=buf;
		}

		m_recordset.GetFieldValue(8,varValue);
		if(varValue.m_iVal==0)
			m_cet6_score="无";
		else 
		{
			sprintf(buf,"%d",varValue.m_iVal);
			m_cet6_score=buf;
		}

		m_recordset.GetFieldValue(9,varValue);
		m_direction=varValue.m_pstring->GetBuffer(1);
	}
	m_recordset.Close();
	UpdateData(FALSE);
}
