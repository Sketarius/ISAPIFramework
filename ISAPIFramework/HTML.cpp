#include "pch.h"
#include "HTML.h"

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

void HTML::print(std::string content) {
	DWORD size = static_cast<DWORD>(strlen(content.c_str()));
	pECB->WriteClient(this->pECB->ConnID, (LPVOID) content.c_str(), &size, 0);
}
