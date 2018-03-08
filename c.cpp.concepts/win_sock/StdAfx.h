// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__D32CFDA7_DC44_4A68_A675_375228D24E96__INCLUDED_)
#define AFX_STDAFX_H__D32CFDA7_DC44_4A68_A675_375228D24E96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afx.h>
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <winsock2.h>
#include <conio.h>
#include <iostream>
#include <string.h>
#include "canopen/comm/inc/canopen_api.h"

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

UNSIGNED8 DisplayNodeState(VOID);
UINT  ServerThread(LPVOID pParam);
UINT  ServerThread(CString data);
UINT  ServerThread(char data[8]);

#endif // !defined(AFX_STDAFX_H__D32CFDA7_DC44_4A68_A675_375228D24E96__INCLUDED_)
