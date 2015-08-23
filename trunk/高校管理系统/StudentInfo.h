#if !defined(AFX_STUDENTINFO_H__C5F7F287_8C23_46F5_92A9_1373147AF7F4__INCLUDED_)
#define AFX_STUDENTINFO_H__C5F7F287_8C23_46F5_92A9_1373147AF7F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// StudentInfo form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CStudentInfo : public CFormView
{
private:
	CFont Font;
protected:
	CStudentInfo();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CStudentInfo)

// Form Data
public:
	//{{AFX_DATA(StudentInfo)
	enum { IDD = IDD_DIALOG2 };
	CComboBox	m_c_sex;
	CComboBox	m_c_party;
	CString	m_party;
	CString	m_sex;
	CDateTimeCtrl	m_birthday;
	CDateTimeCtrl	m_starttime;
	CString	m_address;
	CString	m_department;
	CString	m_hometown;
	CString	m_number;
	CString	m_major;
	CString	m_name;
	CString	m_other;
	CString	m_phone;
	CString	m_race;
	BOOL b_starttime;
	BOOL b_birthday;
	BOOL b_major;
	BOOL b_other;
	BOOL b_race;
	BOOL b_hometown;
	BOOL b_department;
	BOOL b_address;
	BOOL b_phone;
	BOOL b_party;
	BOOL b_sex;
	//}}AFX_DATA
	
// Attributes
public:

// Operations
public:
	void initial();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(StudentInfo)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CStudentInfo();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(StudentInfo)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTINFO_H__C5F7F287_8C23_46F5_92A9_1373147AF7F4__INCLUDED_)
