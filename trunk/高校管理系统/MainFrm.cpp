// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "高校管理系统.h"
#include "StudentInfo.h"
#include "LoginDlg.h"
#include "ChoiceCourse.h"
#include "CourseList.h"
#include "CourseScore.h"
#include "CmpLevScore.h"
#include "CetScore.h"
#include "UserChange.h"
#include "DelCourse.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_SYSTEM_CONNECT, OnUpdateSystemConnect)
	ON_UPDATE_COMMAND_UI(ID_SYSTEM_DISCONNECT, OnUpdateSystemDisconnect)
	ON_UPDATE_COMMAND_UI(ID_STUDENT_INFO, OnUpdateStudentInfo)
	ON_UPDATE_COMMAND_UI(ID_CHOICE_COURSE, OnUpdateChoiceCourse)
	ON_UPDATE_COMMAND_UI(ID_DEL_COURSE, OnUpdateDelCourse)
	ON_UPDATE_COMMAND_UI(ID_COURSE_LIST, OnUpdateCourseList)
	ON_UPDATE_COMMAND_UI(ID_COURSE_SCORE, OnUpdateCourseScore)
	ON_UPDATE_COMMAND_UI(ID_COMPUTER_LEVER_SCORE, OnUpdateComputerLeverScore)
	ON_UPDATE_COMMAND_UI(ID_CET_SCORE, OnUpdateCetScore)
	ON_UPDATE_COMMAND_UI(ID_USER_CHANGE, OnUpdateUserChange)
	ON_COMMAND(ID_SYSTEM_CONNECT, OnSystemConnect)
	ON_COMMAND(ID_SYSTEM_DISCONNECT, OnSystemDisconnect)
	ON_COMMAND(ID_STUDENT_INFO, OnStudentInfo)
	ON_COMMAND(ID_CHOICE_COURSE, OnChoiceCourse)
	ON_COMMAND(ID_DEL_COURSE, OnDelCourse)
	ON_COMMAND(ID_COURSE_LIST, OnCourseList)
	ON_COMMAND(ID_COURSE_SCORE, OnCourseScore)
	ON_COMMAND(ID_CET_SCORE, OnCetScore)
	ON_COMMAND(ID_COMPUTER_LEVER_SCORE, OnComputerLeverScore)
	ON_COMMAND(ID_USER_CHANGE, OnUserChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_bLogin=FALSE;
	m_bItemStudentInfo=FALSE;
	m_bItemChioceCourse=FALSE;
	m_bItemDelCourse=FALSE;
	m_bItemCourseList=FALSE;
	m_bItemCourseScore=FALSE;
	m_bItemCETScore=FALSE;
	m_bItemCmpLevScore=FALSE;
	m_bItemUserChange=FALSE;

	m_pStudentInfo=NULL;
	m_pChoiceCourse=NULL;
	m_pDelCourse=NULL;
	m_pCourseScore=NULL;
	m_pCourseList=NULL;
	m_pCETScore=NULL;
	m_pCmpLevScore=NULL;
	m_pUserChange=NULL;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	
	ShowWindow(SW_SHOWMAXIMIZED);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnUpdateSystemConnect(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(!m_bLogin);	// TODO: Add your command update UI handler code here
}

void CMainFrame::OnUpdateSystemDisconnect(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_bLogin);	// TODO: Add your command update UI handler code here
	
}

void CMainFrame::OnUpdateStudentInfo(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_bItemStudentInfo);	// TODO: Add your command update UI handler code here
}

void CMainFrame::OnUpdateChoiceCourse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bItemChioceCourse);	
}

void CMainFrame::OnUpdateDelCourse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bItemDelCourse);	
}

void CMainFrame::OnUpdateCourseList(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bItemCourseList);	
}

void CMainFrame::OnUpdateCourseScore(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bItemCourseScore);	
}

void CMainFrame::OnUpdateComputerLeverScore(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bItemCmpLevScore);	
}

void CMainFrame::OnUpdateCetScore(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bItemCETScore);	
}

void CMainFrame::OnUpdateUserChange(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_bItemUserChange);	
}

void CMainFrame::OnSystemConnect() 
{
	// TODO: Add your command handler code here
	CLoginDlg dlg;
	if (dlg.DoModal()==IDOK)
	{
		m_bLogin=TRUE;
		m_bItemStudentInfo=TRUE;
		m_bItemDelCourse=TRUE;
		m_bItemCourseList=TRUE;
		m_bItemChioceCourse=TRUE;
		m_bItemCourseScore=TRUE;
		m_bItemCETScore=TRUE;
		m_bItemCmpLevScore=TRUE;
		m_bItemUserChange=TRUE;
	}
}

void CMainFrame::OnSystemDisconnect() 
{
	// TODO: Add your command handler code here
	if(m_pStudentInfo)	
		m_pStudentInfo->DestroyWindow();
	if(m_pChoiceCourse)
		m_pChoiceCourse->DestroyWindow();
	if(m_pCourseList)
		m_pCourseList->DestroyWindow();
	if(m_pDelCourse)
		m_pDelCourse->DestroyWindow();
	if(m_pCourseScore)
		m_pCourseScore->DestroyWindow();
	if(m_pCETScore)
		m_pCETScore->DestroyWindow();
	if(m_pCmpLevScore)
		m_pCmpLevScore->DestroyWindow();
	if(m_pUserChange)
		m_pUserChange->DestroyWindow();

	m_bLogin=FALSE;
	m_bItemStudentInfo=FALSE;
	m_bItemCourseList=FALSE;
	m_bItemDelCourse=FALSE;
	m_bItemCourseScore=FALSE;
	m_bItemCETScore=FALSE;
	m_bItemCmpLevScore=FALSE;
	m_bItemUserChange=FALSE;
}

void CMainFrame::OnStudentInfo() 
{
	// TODO: Add your command handler code here
	m_pStudentInfo=new CMyChildFrame();
	CCreateContext context;
	context.m_pNewViewClass=RUNTIME_CLASS(CStudentInfo);
	if(!m_pStudentInfo->LoadFrame(IDR_MAINFRAME,
		WS_OVERLAPPEDWINDOW|FWS_PREFIXTITLE,this, &context ))return;
	m_pStudentInfo->InitialUpdateFrame(NULL,TRUE);
	m_bItemStudentInfo=FALSE;
}

void CMainFrame::OnChoiceCourse() 
{
	// TODO: Add your command handler code here
	m_pChoiceCourse=new CMyChildFrame();
	CCreateContext context;
	context.m_pNewViewClass=RUNTIME_CLASS(CChoiceCourse);
	if(!m_pChoiceCourse->LoadFrame(IDR_MAINFRAME,WS_OVERLAPPEDWINDOW|FWS_PREFIXTITLE,this,&context))
		return;
	m_pChoiceCourse->InitialUpdateFrame(NULL,TRUE);
	m_bItemChioceCourse=FALSE;
}

void CMainFrame::OnDelCourse()
{
	m_pDelCourse=new CMyChildFrame();
	CCreateContext context;
	context.m_pNewViewClass=RUNTIME_CLASS(CDelCourse);
	if(!m_pDelCourse->LoadFrame(IDR_MAINFRAME,WS_OVERLAPPEDWINDOW|FWS_PREFIXTITLE,this,&context))
		return;
	m_pDelCourse->InitialUpdateFrame(NULL,TRUE);
	m_bItemDelCourse=FALSE;
}


void CMainFrame::OnCourseList() 
{
	// TODO: Add your command handler code here
	m_pCourseList=new CMyChildFrame();
	CCreateContext context;
	context.m_pNewViewClass=RUNTIME_CLASS(CCourseList);
	if(!m_pCourseList->LoadFrame(IDR_MAINFRAME,WS_OVERLAPPEDWINDOW|FWS_PREFIXTITLE,this,&context))
		return;
	m_pCourseList->InitialUpdateFrame(NULL,TRUE);
	m_bItemCourseList=FALSE;	
}

void CMainFrame::OnCourseScore() 
{
	// TODO: Add your command handler code here
	m_pCourseScore=new CMyChildFrame();
	CCreateContext context;
	context.m_pNewViewClass=RUNTIME_CLASS(CCourseScore);
	if(!m_pCourseScore->LoadFrame(IDR_MAINFRAME,WS_OVERLAPPEDWINDOW|FWS_PREFIXTITLE,this,&context))
		return;
	m_pCourseScore->InitialUpdateFrame(NULL,TRUE);
	m_bItemCourseScore=FALSE;
}

void CMainFrame::OnCetScore() 
{
	// TODO: Add your command handler code here
	m_pCETScore=new CMyChildFrame();
	CCreateContext context;
	context.m_pNewViewClass=RUNTIME_CLASS(CCetScore);
	if(!m_pCETScore->LoadFrame(IDR_MAINFRAME,WS_OVERLAPPEDWINDOW|FWS_PREFIXTITLE,this,&context))
		return;
	m_pCETScore->InitialUpdateFrame(NULL,TRUE);
	m_bItemCETScore=FALSE;
}

void CMainFrame::OnComputerLeverScore() 
{
	// TODO: Add your command handler code here
	m_pCmpLevScore=new CMyChildFrame();
	CCreateContext context;
	context.m_pNewViewClass=RUNTIME_CLASS(CCmpLevScore);
	if(!m_pCmpLevScore->LoadFrame(IDR_MAINFRAME,WS_OVERLAPPEDWINDOW|FWS_PREFIXTITLE,this,&context))
		return;
	m_pCmpLevScore->InitialUpdateFrame(NULL,TRUE);
	m_bItemCmpLevScore=FALSE;
}

void CMainFrame::OnUserChange() 
{
	// TODO: Add your command handler code here
	m_pUserChange=new CMyChildFrame();
	CCreateContext context;
	context.m_pNewViewClass=RUNTIME_CLASS(CUserChange);
	if(!m_pUserChange->LoadFrame(IDR_MAINFRAME,WS_OVERLAPPEDWINDOW|FWS_PREFIXTITLE,this,&context))
		return;
	m_pUserChange->InitialUpdateFrame(NULL,TRUE);
	m_bItemUserChange=FALSE;
}
