// CourseSet.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "CourseSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourseSet

IMPLEMENT_DYNAMIC(CCourseSet, CRecordset)

CCourseSet::CCourseSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCourseSet)
	m_COURSE_ID = _T("");
	m_COURSE_NAME = _T("");
	m_COURSE_TIME = _T("");
	m_CENT = 0;
	m_COURSE_TEACHER = _T("");
	m_REQUIRE = _T("");
	m_INSTRUCTION = _T("");
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCourseSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=高校管理系统");
}

CString CCourseSet::GetDefaultSQL()
{
	return _T("[dbo].[COURSE]");
}

void CCourseSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCourseSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[COURSE_ID]"), m_COURSE_ID);
	RFX_Text(pFX, _T("[COURSE_NAME]"), m_COURSE_NAME);
	RFX_Text(pFX, _T("[COURSE_TIME]"), m_COURSE_TIME);
	RFX_Date(pFX, _T("[START_DATE]"), m_START_DATE);
	RFX_Date(pFX, _T("[END_DATE]"), m_END_DATE);
	RFX_Long(pFX, _T("[CENT]"), m_CENT);
	RFX_Text(pFX, _T("[COURSE_TEACHER]"), m_COURSE_TEACHER);
	RFX_Text(pFX, _T("[REQUIRE]"), m_REQUIRE);
	RFX_Text(pFX, _T("[INSTRUCTION]"), m_INSTRUCTION);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCourseSet diagnostics

#ifdef _DEBUG
void CCourseSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCourseSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
