#if !defined(AFX_LOGINSET_H__59D12DB4_6E91_40A9_9BD0_71256D2ECB0C__INCLUDED_)
#define AFX_LOGINSET_H__59D12DB4_6E91_40A9_9BD0_71256D2ECB0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginSet recordset

class CLoginSet : public CRecordset
{
public:
	CLoginSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CLoginSet)

// Field/Param Data
	//{{AFX_FIELD(CLoginSet, CRecordset)
	CString	m_USER_ID;
	CString	m_USER_PASSWORD;
	long	m_USER_TYPE;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginSet)
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

#endif // !defined(AFX_LOGINSET_H__59D12DB4_6E91_40A9_9BD0_71256D2ECB0C__INCLUDED_)
