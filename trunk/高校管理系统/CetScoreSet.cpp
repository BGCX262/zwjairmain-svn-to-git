// CetScoreSet.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "CetScoreSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCetScoreSet

IMPLEMENT_DYNAMIC(CCetScoreSet, CRecordset)

CCetScoreSet::CCetScoreSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCetScoreSet)
	m_STU_ID = _T("");
	m_STU_NAME = _T("");
	m_PERSON_ID = _T("");
	m_CET4_STATE = 0;
	m_CET6_STATE = 0;
	m_TEST_PLACE = _T("");
	m_CET4_SCORE = 0;
	m_CET6_SCORE = 0;
	m_DIRECTION = _T("");
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCetScoreSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=高校管理系统");
}

CString CCetScoreSet::GetDefaultSQL()
{
	return _T("[dbo].[CET_SCORE]");
}

void CCetScoreSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCetScoreSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[STU_ID]"), m_STU_ID);
	RFX_Text(pFX, _T("[STU_NAME]"), m_STU_NAME);
	RFX_Text(pFX, _T("[PERSON_ID]"), m_PERSON_ID);
	RFX_Long(pFX, _T("[CET4_STATE]"), m_CET4_STATE);
	RFX_Long(pFX, _T("[CET6_STATE]"), m_CET6_STATE);
	RFX_Text(pFX, _T("[TEST_PLACE]"), m_TEST_PLACE);
	RFX_Date(pFX, _T("[TEST_DATE]"), m_TEST_DATE);
	RFX_Long(pFX, _T("[CET4_SCORE]"), m_CET4_SCORE);
	RFX_Long(pFX, _T("[CET6_SCORE]"), m_CET6_SCORE);
	RFX_Text(pFX, _T("[DIRECTION]"), m_DIRECTION);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCetScoreSet diagnostics

#ifdef _DEBUG
void CCetScoreSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCetScoreSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
