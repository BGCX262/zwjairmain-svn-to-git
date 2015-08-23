// CmpLevScoreSet.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "CmpLevScoreSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCmpLevScoreSet

IMPLEMENT_DYNAMIC(CCmpLevScoreSet, CRecordset)

CCmpLevScoreSet::CCmpLevScoreSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCmpLevScoreSet)
	m_STU_ID = _T("");
	m_STU_NAME = _T("");
	m_PERSON_ID = _T("");
	m_LEV1_STATE = 0;
	m_LEV1_SCORE = 0;
	m_LEV2_STATE = 0;
	m_LEV2_SCORE = 0;
	m_TEST_PLACE = _T("");
	m_DIRECTION = _T("");
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCmpLevScoreSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=高校管理系统");
}

CString CCmpLevScoreSet::GetDefaultSQL()
{
	return _T("[dbo].[CMPLEV_SCORE]");
}

void CCmpLevScoreSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCmpLevScoreSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[STU_ID]"), m_STU_ID);
	RFX_Text(pFX, _T("[STU_NAME]"), m_STU_NAME);
	RFX_Text(pFX, _T("[PERSON_ID]"), m_PERSON_ID);
	RFX_Long(pFX, _T("[LEV1_STATE]"), m_LEV1_STATE);
	RFX_Long(pFX, _T("[LEV1_SCORE]"), m_LEV1_SCORE);
	RFX_Long(pFX, _T("[LEV2_STATE]"), m_LEV2_STATE);
	RFX_Long(pFX, _T("[LEV2_SCORE]"), m_LEV2_SCORE);
	RFX_Text(pFX, _T("[TEST_PLACE]"), m_TEST_PLACE);
	RFX_Date(pFX, _T("[TESE_DATE]"), m_TESE_DATE);
	RFX_Text(pFX, _T("[DIRECTION]"), m_DIRECTION);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCmpLevScoreSet diagnostics

#ifdef _DEBUG
void CCmpLevScoreSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCmpLevScoreSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
