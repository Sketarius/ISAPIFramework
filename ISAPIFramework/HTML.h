#pragma once
#include <string>
#include <HttpExt.h>
class HTML
{	private:
		EXTENSION_CONTROL_BLOCK* pECB;
	public:
		HTML(EXTENSION_CONTROL_BLOCK* pECB);
		void print(std::string content);
};

