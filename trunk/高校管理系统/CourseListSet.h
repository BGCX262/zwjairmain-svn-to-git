#if !defined(AFX_COURSELISTSET_H__D8E00A99_6B46_4DA8_AB59_977DFD39E3E8__INCLUDED_)
#define AFX_COURSELISTSET_H__D8E00A99_6B46_4DA8_AB59_977DFD39E3E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CourseListSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCourseListSet recordset

class CCourseListSet : public CRecordset
{
public:
	CCourseListSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCourseListSet)

// Field/Param Data
	//{{AFX_FIELD(CCourseListSet, CRecordset)
	CString	m_COURSE_ID;
	CString	m_COURSE_NAME;
	CString	m_CLASS_ID;
	CString	m_COURSE_TEACHER;
	long	m_WEEKDAY;
	CString	m_DAYHOUR;
	CString	m_BULDING;
	CString	m_ROOM;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseListSet)
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

#endif // !defined(AFX_COURSELISTSET_H__D8E00A99_6B46_4DA8_AB59_977DFD39E3E8__INCLUDED_)
