#pragma once
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <HttpExt.h>
class CgiRequest
{
	public:
		CgiRequest(EXTENSION_CONTROL_BLOCK* pECB);
		std::string CgiGetVal(std::string variable);
		std::string CgiGetRequestToString();
	private:
		std::map<std::string, std::string> requestMap;
		void ParseRequestString(std::string requestString);
		std::vector<std::string> SplitVariable(std::string variableString);
};

