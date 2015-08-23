#if !defined(AFX_CETSCORESET_H__20A365DF_A876_487A_AE1A_BF5183C4A7EB__INCLUDED_)
#define AFX_CETSCORESET_H__20A365DF_A876_487A_AE1A_BF5183C4A7EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CetScoreSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCetScoreSet recordset

class CCetScoreSet : public CRecordset
{
public:
	CCetScoreSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCetScoreSet)

// Field/Param Data
	//{{AFX_FIELD(CCetScoreSet, CRecordset)
	CString	m_STU_ID;
	CString	m_STU_NAME;
	CString	m_PERSON_ID;
	long	m_CET4_STATE;
	long	m_CET6_STATE;
	CString	m_TEST_PLACE;
	CTime	m_TEST_DATE;
	long	m_CET4_SCORE;
	long	m_CET6_SCORE;
	CString	m_DIRECTION;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCetScoreSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CETSCORESET_H__20A365DF_A876_487A_AE1A_BF5183C4A7EB__INCLUDED_)
