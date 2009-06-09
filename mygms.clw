; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mygms.h"

ClassCount=10
Class1=CMygmsApp
Class2=CMygmsDlg
Class3=CAboutDlg

ResourceCount=10
Resource1=IDD_DIALOG_MAIN
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG_OUT
Resource4=IDD_ABOUTBOX
Resource5=IDD_DIALOG_CATE
Resource6=IDD_DIALOG_IN
Resource7=IDD_MYGMS_DIALOG
Resource8=IDD_DIALOG_GM
Resource9=IDD_DIALOG_ADMIN
Class4=CMainDlg
Class5=CINDlg
Class6=CGMDlg
Class7=CCATEDlg
Class8=CADMINDlg
Class9=CLOGDlg
Class10=COUTDlg
Resource10=IDD_DIALOG_LOG

[CLS:CMygmsApp]
Type=0
HeaderFile=mygms.h
ImplementationFile=mygms.cpp
Filter=N

[CLS:CMygmsDlg]
Type=0
HeaderFile=mygmsDlg.h
ImplementationFile=mygmsDlg.cpp
Filter=D
LastObject=IDC_EDIT_USER
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=mygmsDlg.h
ImplementationFile=mygmsDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYGMS_DIALOG]
Type=1
Class=CMygmsDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342177287
Control4=IDC_EDIT_USER,edit,1350631552
Control5=IDC_EDIT_PASSWORD,edit,1350631584
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_MAIN]
Type=1
Class=CMainDlg
ControlCount=3
Control1=IDOK,button,1342177281
Control2=IDCANCEL,button,1342242816
Control3=IDC_TAB_MAIN,SysTabControl32,1342242816

[DLG:IDD_DIALOG_GM]
Type=1
Class=CGMDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_DIALOG_IN]
Type=1
Class=CINDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_OUT]
Type=1
Class=COUTDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_DIALOG_ADMIN]
Type=1
Class=CADMINDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_DIALOG_CATE]
Type=1
Class=CCATEDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_DIALOG_LOG]
Type=1
Class=CLOGDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CMainDlg]
Type=0
HeaderFile=MainDlg.h
ImplementationFile=MainDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMainDlg

[CLS:CINDlg]
Type=0
HeaderFile=INDlg.h
ImplementationFile=INDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CINDlg

[CLS:CGMDlg]
Type=0
HeaderFile=GMDlg.h
ImplementationFile=GMDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CGMDlg

[CLS:CCATEDlg]
Type=0
HeaderFile=CATEDlg.h
ImplementationFile=CATEDlg.cpp
BaseClass=CDialog
Filter=D

[CLS:CADMINDlg]
Type=0
HeaderFile=ADMINDlg.h
ImplementationFile=ADMINDlg.cpp
BaseClass=CDialog
Filter=D

[CLS:CLOGDlg]
Type=0
HeaderFile=LOGDlg.h
ImplementationFile=LOGDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLOGDlg

[CLS:COUTDlg]
Type=0
HeaderFile=OUTDlg.h
ImplementationFile=OUTDlg.cpp
BaseClass=CDialog
Filter=D

