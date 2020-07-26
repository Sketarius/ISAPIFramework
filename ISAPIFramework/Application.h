#pragma once
#include "HTML.h"
#include "CgiRequest.h"
class Application
{
	private:
		HTML *html;
		CgiRequest *cgiRequest;
		EXTENSION_CONTROL_BLOCK* pECB;
	public:
		Application(EXTENSION_CONTROL_BLOCK *pECB);
		HTML * getHTML();
		CgiRequest * getCGI();
};

