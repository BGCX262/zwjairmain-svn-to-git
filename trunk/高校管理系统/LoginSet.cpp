// LoginSet.cpp : implementation file
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "LoginSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginSet

IMPLEMENT_DYNAMIC(CLoginSet, CRecordset)

CLoginSet::CLoginSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CLoginSet)
	m_USER_ID = _T("");
	m_USER_PASSWORD = _T("");
	m_USER_TYPE = 0;
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CLoginSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=高校管理系统");
}

CString CLoginSet::GetDefaultSQL()
{
	return _T("[dbo].[USERS]");
}

void CLoginSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CLoginSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[USER_ID]"), m_USER_ID);
	RFX_Text(pFX, _T("[USER_PASSWORD]"), m_USER_PASSWORD);
	RFX_Long(pFX, _T("[USER_TYPE]"), m_USER_TYPE);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CLoginSet diagnostics

#ifdef _DEBUG
void CLoginSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CLoginSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
