#include "pch.h"
#include "HTML.h"

HTML::HTML() {}

void HTML::print(EXTENSION_CONTROL_BLOCK* pECB, std::string content) {
	DWORD size = static_cast<DWORD>(strlen(content.c_str()));
	pECB->WriteClient(pECB->ConnID, (LPVOID) content.c_str(), &size, 0);
}
