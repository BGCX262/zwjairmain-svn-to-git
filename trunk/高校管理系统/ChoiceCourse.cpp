// ChoiceCourse.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "ChoiceCourse.h"
#include "CourseSet.h"
#include "CourseScoreSet.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChoiceCourse

IMPLEMENT_DYNCREATE(CChoiceCourse, CFormView)

extern CDatabase m_database;
extern CString m_ID;

CChoiceCourse::CChoiceCourse()
	: CFormView(CChoiceCourse::IDD)
{
	//{{AFX_DATA_INIT(CChoiceCourse)
	m_teacher = _T("");
	m_start = _T("");
	m_require = _T("");
	m_instruction = _T("");
	m_end = _T("");
	m_course_time = _T("");
	m_course_name = _T("");
	m_courseID = _T("");
	m_cent = _T("");
	//}}AFX_DATA_INIT
}

CChoiceCourse::~CChoiceCourse()
{
}

void CChoiceCourse::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChoiceCourse)
	DDX_Control(pDX, IDC_LIST_COURSE, m_course);
	DDX_Text(pDX, IDC_EDIT_TEACHER, m_teacher);
	DDX_Text(pDX, IDC_EDIT_START, m_start);
	DDX_Text(pDX, IDC_EDIT_REQUIRE, m_require);
	DDX_Text(pDX, IDC_EDIT_INSTRUCTION, m_instruction);
	DDX_Text(pDX, IDC_EDIT_END, m_end);
	DDX_Text(pDX, IDC_EDIT_COURSE_TIME, m_course_time);
	DDX_Text(pDX, IDC_EDIT_COURSE_NAME, m_course_name);
	DDX_Text(pDX, IDC_EDIT_COURSE_ID, m_courseID);
	DDX_Text(pDX, IDC_EDIT_CENT, m_cent);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChoiceCourse, CFormView)
	//{{AFX_MSG_MAP(CChoiceCourse)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChoiceCourse diagnostics

#ifdef _DEBUG
void CChoiceCourse::AssertValid() const
{
	CFormView::AssertValid();
}

void CChoiceCourse::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChoiceCourse message handlers

void CChoiceCourse::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(FALSE);
	GetParentFrame()->SetWindowText("学生选课子系统");
	LOGFONT LogFont;
	GetFont()->GetLogFont(&LogFont);
	LogFont.lfHeight+=LogFont.lfHeight/2;
	LogFont.lfWidth+=LogFont.lfHeight/2;
	Font.CreateFontIndirect(&LogFont);
	GetDlgItem(IDC_STATIC_CHOICE_COURSE)->SetFont(&Font);

	m_course.InsertColumn(0,"课程编号");
	m_course.InsertColumn(1,"课程名称");
	m_course.InsertColumn(2,"上课时间");
	m_course.InsertColumn(3,"开课日期");
	m_course.InsertColumn(4,"结课日期");
	m_course.InsertColumn(5,"课程学分");
	m_course.InsertColumn(6,"授课老师");
	m_course.InsertColumn(7,"报选要求");
	m_course.InsertColumn(8,"课程简介");
	RECT rect;
	m_course.GetWindowRect(&rect);
	int width=rect.right-rect.left;
	m_course.SetColumnWidth(0,width/7);
	m_course.SetColumnWidth(1,width/7);
	m_course.SetColumnWidth(2,width/7);
	m_course.SetColumnWidth(3,width/7);
	m_course.SetColumnWidth(4,width/7);
	m_course.SetColumnWidth(5,width/7);
	m_course.SetColumnWidth(6,width/7);
	m_course.SetColumnWidth(7,width/7);
	m_course.SetColumnWidth(8,width/7);
	m_course.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	initial();
}

void CChoiceCourse::initial()
{
	CDBVariant varValue;
	char buf[20];
	int i=0;
	m_course.DeleteAllItems();
	CRecordset m_recordset(&m_database);
	CString strSQL;
	strSQL.Format("select * from COURSE");
	m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
	if(m_recordset.GetRecordCount()!=0)
		m_recordset.MoveFirst();
	while (!m_recordset.IsEOF())
	{
		int temp=0;
		m_recordset.GetFieldValue(temp,varValue);
		m_course.InsertItem(i,varValue.m_pstring->GetBuffer(1));
		m_recordset.GetFieldValue(1,varValue);
		m_course.SetItemText(i,1,varValue.m_pstring->GetBuffer(1));
		m_recordset.GetFieldValue(2,varValue);
		m_course.SetItemText(i,2,varValue.m_pstring->GetBuffer(1));
		m_recordset.GetFieldValue(3,varValue);
		sprintf(buf,"%d-%d-%d",varValue.m_pdate->year,varValue.m_pdate->month,varValue.m_pdate->day);
		m_course.SetItemText(i,3,buf);
		m_recordset.GetFieldValue(4,varValue);
		sprintf(buf,"%d-%d-%d",varValue.m_pdate->year,varValue.m_pdate->month,varValue.m_pdate->day);
		m_course.SetItemText(i,4,buf);
		m_recordset.GetFieldValue(5,varValue);
		sprintf(buf,"%d",varValue.m_iVal);
		m_course.SetItemText(i,5,buf);
		m_recordset.GetFieldValue(6,varValue);
		m_course.SetItemText(i,6,varValue.m_pstring->GetBuffer(1));
		m_recordset.GetFieldValue(7,varValue);
		m_course.SetItemText(i,7,varValue.m_pstring->GetBuffer(1));
		m_recordset.GetFieldValue(8,varValue);
		m_course.SetItemText(i,8,varValue.m_pstring->GetBuffer(1));
		m_recordset.MoveNext();
		i++;
	}
	m_recordset.Close();
	
	i=0;
	settext(0);
	UpdateData(FALSE);
}

void CChoiceCourse::settext(int index)
{
	m_courseID=m_course.GetItemText(index,0);
	m_course_name=m_course.GetItemText(index,1);
	m_courseID=m_course.GetItemText(index,2);
	m_start=m_course.GetItemText(index,3);
	m_end=m_course.GetItemText(index,4);
	m_cent=m_course.GetItemText(index,5);
	m_teacher=m_course.GetItemText(index,6);
	m_require=m_course.GetItemText(index,7);
	m_instruction=m_course.GetItemText(index,8);
	
	UpdateData(FALSE);
}
