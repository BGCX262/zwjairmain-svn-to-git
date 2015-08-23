// CourseScoreSet.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "CourseScoreSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourseScoreSet

IMPLEMENT_DYNAMIC(CCourseScoreSet, CRecordset)

CCourseScoreSet::CCourseScoreSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCourseScoreSet)
	m_STU_ID = _T("");
	m_COURSE_ID = _T("");
	m_COURSE_NAME = _T("");
	m_SCORE = 0;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCourseScoreSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=高校管理系统");
}

CString CCourseScoreSet::GetDefaultSQL()
{
	return _T("[dbo].[COURSE_SCORE]");
}

void CCourseScoreSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCourseScoreSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[STU_ID]"), m_STU_ID);
	RFX_Text(pFX, _T("[COURSE_ID]"), m_COURSE_ID);
	RFX_Text(pFX, _T("[COURSE_NAME]"), m_COURSE_NAME);
	RFX_Long(pFX, _T("[SCORE]"), m_SCORE);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCourseScoreSet diagnostics

#ifdef _DEBUG
void CCourseScoreSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCourseScoreSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
