// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "HttpExt.h"
#include "CgiRequest.h"
#include "HTML.h"
#include "Application.h"

BOOL WINAPI GetExtensionVersion(HSE_VERSION_INFO* pVer) {
	pVer->dwExtensionVersion = HSE_VERSION;
	strncpy_s(pVer->lpszExtensionDesc,
		HSE_MAX_EXT_DLL_NAME_LEN,
		"Hello ISAPI Extension", _TRUNCATE);
	return TRUE;
}

DWORD WINAPI HttpExtensionProc(EXTENSION_CONTROL_BLOCK* pECB) {
	Application *app = new Application(pECB);
	CgiRequest* cgiRequest = app->getCGI();
	HTML* html = app->getHTML();

	html->SetPageTitle("ISAPI Framework v1.0");
	html->BeginPage();

	html->print("<h1>This is the entry point for your ISAPI CGI program.</h1>\n");

	html->print("This method prints to the browser! test and stuff <br />");
	html->print("s=" + cgiRequest->CgiGetVal("s"));

	html->print("<form action=\"ISAPIFramework.dll\" method=\"POST\">\n"
					 "	<input type=\"hidden\" name=\"f\" value=\"chart\">\n"
					 "	<input type=\"hidden\" name=\"s\" value=\"pat_thing\">\n"
					 "	<input type=\"submit\" value=\"Submit\">\n"
					 "</form>\n");

	html->EndPage();

	delete app;
	return HSE_STATUS_SUCCESS;
}

BOOL WINAPI TerminateExtension(DWORD dwFlags) {
	return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    return TRUE;
}
