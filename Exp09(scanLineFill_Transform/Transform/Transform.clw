; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTransformView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Transform.h"
LastPage=0

ClassCount=7
Class1=CTransformApp
Class2=CTransformDoc
Class3=CTransformView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_DIALOG1
Class6=Dlg_SCALE
Resource3=IDD_ABOUTBOX
Class7=Dlg_ROTATE
Resource4=IDD_DIALOG2

[CLS:CTransformApp]
Type=0
HeaderFile=Transform.h
ImplementationFile=Transform.cpp
Filter=N

[CLS:CTransformDoc]
Type=0
HeaderFile=TransformDoc.h
ImplementationFile=TransformDoc.cpp
Filter=N

[CLS:CTransformView]
Type=0
HeaderFile=TransformView.h
ImplementationFile=TransformView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDM_ROTATE


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDM_SHEARY




[CLS:CAboutDlg]
Type=0
HeaderFile=Transform.cpp
ImplementationFile=Transform.cpp
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
Command17=IDM_TRANSLATE
Command18=IDM_SCALE
Command19=IDM_ROTATE
Command20=IDM_SMMETRY_Y
Command21=IDM_SHEARY
Command22=ID_MENUITEM32776
CommandCount=22

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

[DLG:IDD_DIALOG1]
Type=1
Class=Dlg_SCALE
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:Dlg_SCALE]
Type=0
HeaderFile=Dlg_SCALE.h
ImplementationFile=Dlg_SCALE.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=Dlg_SCALE

[DLG:IDD_DIALOG2]
Type=1
Class=Dlg_ROTATE
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:Dlg_ROTATE]
Type=0
HeaderFile=Dlg_ROTATE.h
ImplementationFile=Dlg_ROTATE.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=Dlg_ROTATE

