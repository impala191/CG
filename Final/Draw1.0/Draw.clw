; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDrawView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Draw.h"
LastPage=0

ClassCount=7
Class1=CDrawApp
Class2=CDrawDoc
Class3=CDrawView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=CDialogStyle
Resource3=IDD_STYLEDIALOG
Class7=DiaStyle2
Resource4=IDD_DIALOG1

[CLS:CDrawApp]
Type=0
HeaderFile=Draw.h
ImplementationFile=Draw.cpp
Filter=N
LastObject=CDrawApp

[CLS:CDrawDoc]
Type=0
HeaderFile=DrawDoc.h
ImplementationFile=DrawDoc.cpp
Filter=N
LastObject=CDrawDoc

[CLS:CDrawView]
Type=0
HeaderFile=DrawView.h
ImplementationFile=DrawView.cpp
Filter=C
LastObject=IDM_SEEDFIIL
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDM_FCOLOR
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Draw.cpp
ImplementationFile=Draw.cpp
Filter=D
LastObject=CAboutDlg

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
Command17=IDM_POLYGON
Command18=IDM_BHCIRCLE
Command19=IDM_RECTANGLE
Command20=IDM_MIDLINE
Command21=IDM_DDALINE
Command22=IDM_DASHLINE
Command23=IDM_POLYLINE
Command24=IDM_SEEDFIIL
Command25=IDM_COLOR
Command26=IDM_FCOLOR
CommandCount=26

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

[DLG:IDD_STYLEDIALOG]
Type=1
Class=CDialogStyle
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_DASH,button,1342242816
Control4=IDC_SOLID,button,1342242816

[CLS:CDialogStyle]
Type=0
HeaderFile=DialogStyle.h
ImplementationFile=DialogStyle.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialogStyle
VirtualFilter=dWC

[DLG:IDD_DIALOG1]
Type=1
Class=DiaStyle2
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:DiaStyle2]
Type=0
HeaderFile=DiaStyle2.h
ImplementationFile=DiaStyle2.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

