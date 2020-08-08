#include "pch.h"
#include "HTML.h"
#include <tchar.h>

HTML::HTML(EXTENSION_CONTROL_BLOCK* pECB) {
	this->pECB = pECB;

	HSE_SEND_HEADER_EX_INFO HeaderExInfo;
	HeaderExInfo.pszStatus = "200OK";
	HeaderExInfo.cchStatus = strlen(HeaderExInfo.pszStatus);
	HeaderExInfo.pszHeader = "Content-type:text/html\r\n\r\n";
	HeaderExInfo.cchHeader = strlen(HeaderExInfo.pszHeader);
	HeaderExInfo.fKeepConn = FALSE;

	pECB->ServerSupportFunction(this->pECB->ConnID, HSE_REQ_SEND_RESPONSE_HEADER_EX, &HeaderExInfo, NULL, NULL);
}

void HTML::BeginPage() {
	this->print("<!DOCTYPE html>\n"
		"	<head> \n"
		"		<title>" + this->pageTitle + "</title>\n"
		"	</head>\n"
		"	<body>\n");
}

void HTML::EndPage() {
	this->print("	</body>\n"
				"</html>\n");
}

void HTML::AddStyleSheet(std::string styleSheetLocation) {
	styleSheets.push_back(styleSheetLocation);
}

void HTML::SetPageTitle(std::string pageTitle) {
	this->pageTitle = pageTitle;
}

void HTML::print(std::string content) {
	DWORD size = static_cast<DWORD>(strlen(content.c_str()));
	pECB->WriteClient(this->pECB->ConnID, (LPVOID) content.c_str(), &size, 0);
}

void HTML::print(TCHAR *content) {
	std::wstring wContent(&content[0]);
	std::string  sContent(wContent.begin(), wContent.end());
	DWORD size = static_cast<DWORD>(_tcslen(content));

	pECB->WriteClient(this->pECB->ConnID, (LPVOID)sContent.c_str(), &size, 0);
}
