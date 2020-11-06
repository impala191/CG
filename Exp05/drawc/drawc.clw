; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDrawcView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "drawc.h"
LastPage=0

ClassCount=5
Class1=CDrawcApp
Class2=CDrawcDoc
Class3=CDrawcView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CDrawcApp]
Type=0
HeaderFile=drawc.h
ImplementationFile=drawc.cpp
Filter=N

[CLS:CDrawcDoc]
Type=0
HeaderFile=drawcDoc.h
ImplementationFile=drawcDoc.cpp
Filter=N

[CLS:CDrawcView]
Type=0
HeaderFile=drawcView.h
ImplementationFile=drawcView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CDrawcView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDM_SEEDFILL




[CLS:CAboutDlg]
Type=0
HeaderFile=drawc.cpp
ImplementationFile=drawc.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=IDM_RECTANGLE
Command18=IDM_POLYGON
Command19=IDM_SEEDFILL
CommandCount=19

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

