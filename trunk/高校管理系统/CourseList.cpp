// CourseList.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "CourseList.h"
#include "CourseListSet.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourseList

IMPLEMENT_DYNCREATE(CCourseList, CFormView)

extern CDatabase m_database;
extern CString m_ID;

CCourseList::CCourseList()
	: CFormView(CCourseList::IDD)
{
	//{{AFX_DATA_INIT(CCourseList)
	m_key = _T("");
	m_weekday = _T("");
	m_building = _T("");
	m_class = _T("");
	m_cost = _T("");
	m_courseID = _T("");
	m_course_name = _T("");
	m_dayhour = _T("");
	m_room = _T("");
	m_teacher = _T("");
	//}}AFX_DATA_INIT
}

CCourseList::~CCourseList()
{
}

void CCourseList::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCourseList)
	DDX_CBString(pDX, IDC_COMBO_KEYWORD, m_key);
	DDX_CBString(pDX, IDC_COMBO_WEEKDAY, m_weekday);
	DDX_Text(pDX, IDC_EDIT_BUILDING, m_building);
	DDX_Text(pDX, IDC_EDIT_CLASS_ID, m_class);
	DDX_Text(pDX, IDC_EDIT_COST, m_cost);
	DDX_Text(pDX, IDC_EDIT_COURSE_ID, m_courseID);
	DDX_Text(pDX, IDC_EDIT_COURSE_NAME, m_course_name);
	DDX_Text(pDX, IDC_EDIT_DAYHOUR, m_dayhour);
	DDX_Text(pDX, IDC_EDIT_ROOM, m_room);
	DDX_Text(pDX, IDC_EDIT_TEACHER, m_teacher);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCourseList, CFormView)
	//{{AFX_MSG_MAP(CCourseList)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCourseList diagnostics

#ifdef _DEBUG
void CCourseList::AssertValid() const
{
	CFormView::AssertValid();
}

void CCourseList::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCourseList message handlers

void CCourseList::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit(FALSE);
	GetParentFrame()->SetWindowText("课表查询");
	LOGFONT LogFont;
	GetFont()->GetLogFont(&LogFont);
	LogFont.lfHeight+=LogFont.lfHeight/2;
	LogFont.lfWidth+=LogFont.lfHeight/2;
	Font.CreateFontIndirect(&LogFont);
	GetDlgItem(IDC_STATIC_CHOICE_COURSE)->SetFont(&Font);
}

void CCourseList::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	CString strSQL;
	CDBVariant varValue;
	UpdateData(TRUE);
	if (m_key.Compare("课程号")==0)
	{
		strSQL.Format(" select * from COURSE_LIST where COURSE_ID='%s' ",m_cost);
	}
	else
		strSQL.Format(" select * from COURSE_LIST \
						where COURSE_NAME='%s' ",m_cost);
	CCourseListSet m_recordset(&m_database);
	m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL);
	if(m_recordset.GetRecordCount()!=0)
	{
		MessageBox("对不起，没有您所需要的结果，请核对后重新输入！","无此结果");
	}
	else
	{
		
		int temp=0;
		m_recordset.GetFieldValue(temp,varValue);
		m_courseID=varValue.m_pstring->GetBuffer(1);
		m_recordset.GetFieldValue(1,varValue);
		m_course_name=varValue.m_pstring->GetBuffer(1);
		m_recordset.GetFieldValue(2,varValue);
		m_class=varValue.m_pstring->GetBuffer(1);
		m_recordset.GetFieldValue(3,varValue);
		m_teacher=varValue.m_pstring->GetBuffer(1);
		m_recordset.GetFieldValue(4,varValue);
		//sprintf(buf,"%d",varValue.m_iVal);
		m_weekday=varValue.m_iVal-1;
		//m_recordset.GetFieldValue(5,varValue);
		//sprintf(buf,"%d",varValue.m_iVal);
		m_recordset.GetFieldValue(temp,varValue);
		m_dayhour=varValue.m_pstring->GetBuffer(1);
		m_recordset.GetFieldValue(temp,varValue);
		m_building=varValue.m_pstring->GetBuffer(1);
		m_recordset.GetFieldValue(temp,varValue);
		m_room=varValue.m_pstring->GetBuffer(1);
	}
	m_recordset.Close();
	UpdateData(FALSE);
}

//DEL BOOL CCourseList::DestroyWindow() 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	
//DEL 	return CFormView::DestroyWindow();
//DEL }

void CCourseList::OnDestroy()
{
	CFormView::OnDestroy();
	((CMainFrame *)AfxGetMainWnd())->m_bItemCourseList=TRUE;
	((CMainFrame *)AfxGetMainWnd())->m_pCourseList=NULL;
}
