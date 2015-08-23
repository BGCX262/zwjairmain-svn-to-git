// CmpLevScore.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "CmpLevScore.h"
#include "CmpLevScoreSet.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCmpLevScore

IMPLEMENT_DYNCREATE(CCmpLevScore, CFormView)

extern CDatabase m_database;
extern CString m_ID;

CCmpLevScore::CCmpLevScore()
	: CFormView(CCmpLevScore::IDD)
{
	//{{AFX_DATA_INIT(CCmpLevScore)
	m_date = _T("");
	m_direction = _T("");
	m_lev1_score = _T("");
	m_lev1_state = _T("");
	m_lev2_score = _T("");
	m_lev2_state = _T("");
	m_personID = _T("");
	m_place = _T("");
	m_stuID = _T("");
	m_stu_name = _T("");
	//}}AFX_DATA_INIT
}

CCmpLevScore::~CCmpLevScore()
{
}

void CCmpLevScore::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCmpLevScore)
	DDX_Text(pDX, IDC_EDIT_DATE, m_date);
	DDX_Text(pDX, IDC_EDIT_DIRECTION, m_direction);
	DDX_Text(pDX, IDC_EDIT_LEVEL1_SCORE, m_lev1_score);
	DDX_Text(pDX, IDC_EDIT_LEVEL1_STATE, m_lev1_state);
	DDX_Text(pDX, IDC_EDIT_LEVEL2_SCORE, m_lev2_score);
	DDX_Text(pDX, IDC_EDIT_LEVEL2_STATE, m_lev2_state);
	DDX_Text(pDX, IDC_EDIT_PERSON_ID, m_personID);
	DDX_Text(pDX, IDC_EDIT_PLACE, m_place);
	DDX_Text(pDX, IDC_EDIT_STUID, m_stuID);
	DDX_Text(pDX, IDC_EDIT_STUNAME, m_stu_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCmpLevScore, CFormView)
	//{{AFX_MSG_MAP(CCmpLevScore)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCmpLevScore diagnostics

#ifdef _DEBUG
void CCmpLevScore::AssertValid() const
{
	CFormView::AssertValid();
}

void CCmpLevScore::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCmpLevScore message handlers

void CCmpLevScore::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(FALSE);
	GetParentFrame()->SetWindowText("计算机等级考试成绩");
	LOGFONT LogFont;
	GetFont()->GetLogFont(&LogFont);
	LogFont.lfHeight+=LogFont.lfHeight/2;
	LogFont.lfWidth+=LogFont.lfHeight/2;
	Font.CreateFontIndirect(&LogFont);
	GetDlgItem(IDC_STATIC_CHOICE_COURSE)->SetFont(&Font);
	
	initial();
}

void CCmpLevScore::initial()
{
	CDBVariant varValue;
	char buf[20];
	CCmpLevScoreSet m_recordset(&m_database);
	CString strSQL;
	strSQL.Format("select * from CMPLEV_SCORE where STU_ID='%s')",m_ID);
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
			m_lev1_state="未报名";
		else if (varValue.m_iVal==1)
			m_lev1_state="已报名";
		else if (varValue.m_iVal==2)
			m_lev1_state="已通过";

		m_recordset.GetFieldValue(4,varValue);
		if(varValue.m_iVal==0)
			m_lev1_score="无";
		else 
		{
			sprintf(buf,"%d",varValue.m_iVal);
			m_lev1_score=buf;
		}

		m_recordset.GetFieldValue(5,varValue);
		if(varValue.m_iVal==0)
			m_lev2_state="未报名";
		else if (varValue.m_iVal==1)
			m_lev2_state="已报名";
		else if (varValue.m_iVal==2)
			m_lev2_state="已通过";
		
		m_recordset.GetFieldValue(6,varValue);
		if(varValue.m_iVal==0)
			m_lev2_score="无";
		else 
		{
			sprintf(buf,"%d",varValue.m_iVal);
			m_lev2_score=buf;
		}
		m_recordset.GetFieldValue(7,varValue);
		m_place=varValue.m_pstring->GetBuffer(1);
		m_recordset.GetFieldValue(8,varValue);
		sprintf(buf,"%d-%d-%d",varValue.m_pdate->year,varValue.m_pdate->month,varValue.m_pdate->day);
		m_date=buf;
		m_recordset.GetFieldValue(9,varValue);
		m_direction=varValue.m_pstring->GetBuffer(1);
	}
	m_recordset.Close();
	UpdateData(FALSE);
}
