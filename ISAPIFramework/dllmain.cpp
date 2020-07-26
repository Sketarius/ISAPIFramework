// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "HttpExt.h"
#include "CgiRequest.h"
#include "HTML.h"

BOOL WINAPI GetExtensionVersion(HSE_VERSION_INFO* pVer) {
	pVer->dwExtensionVersion = HSE_VERSION;
	strncpy_s(pVer->lpszExtensionDesc,
		HSE_MAX_EXT_DLL_NAME_LEN,
		"Hello ISAPI Extension", _TRUNCATE);
	return TRUE;
}

DWORD WINAPI HttpExtensionProc(EXTENSION_CONTROL_BLOCK* pECB) {
	CgiRequest cgiRequest(pECB->lpszQueryString);
	HTML html;
	html.print(pECB,
		"<!DOCTYPE html>\n"
		"	<head> \n"
		"		<title>ISAPI IIS CGI</title>\n"
		"	</head>\n"
		"	<body>\n"
		"		<h1>This is the entry point for your ISAPI CGI program.</h1>\n");

	html.print(pECB, "This method prints to the browser! <br />");

	html.print(pECB, "	</body>\n"
		"</html>");

	return HSE_STATUS_SUCCESS;
}

BOOL WINAPI TerminateExtension(DWORD dwFlags) {
	return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    return TRUE;
}
