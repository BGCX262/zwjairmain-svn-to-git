// CourseListSet.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "CourseListSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourseListSet

IMPLEMENT_DYNAMIC(CCourseListSet, CRecordset)

CCourseListSet::CCourseListSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCourseListSet)
	m_COURSE_ID = _T("");
	m_COURSE_NAME = _T("");
	m_CLASS_ID = _T("");
	m_COURSE_TEACHER = _T("");
	m_WEEKDAY = 0;
	m_DAYHOUR = _T("");
	m_BULDING = _T("");
	m_ROOM = _T("");
	m_nFields = 8;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCourseListSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=高校管理系统");
}

CString CCourseListSet::GetDefaultSQL()
{
	return _T("[dbo].[COURSE_LIST]");
}

void CCourseListSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCourseListSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[COURSE_ID]"), m_COURSE_ID);
	RFX_Text(pFX, _T("[COURSE_NAME]"), m_COURSE_NAME);
	RFX_Text(pFX, _T("[CLASS_ID]"), m_CLASS_ID);
	RFX_Text(pFX, _T("[COURSE_TEACHER]"), m_COURSE_TEACHER);
	RFX_Long(pFX, _T("[WEEKDAY]"), m_WEEKDAY);
	RFX_Text(pFX, _T("[DAYHOUR]"), m_DAYHOUR);
	RFX_Text(pFX, _T("[BULDING]"), m_BULDING);
	RFX_Text(pFX, _T("[ROOM]"), m_ROOM);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCourseListSet diagnostics

#ifdef _DEBUG
void CCourseListSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCourseListSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
