#pragma once
#include <string>
#include <HttpExt.h>
class HTML
{
	public:
		HTML();
		void print(EXTENSION_CONTROL_BLOCK* pECB, std::string content);
};

