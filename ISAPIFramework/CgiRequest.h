#pragma once
#include <string>
#include <map>
#include <iostream>
#include <vector>
class CgiRequest
{
	public:
		CgiRequest(std::string requestString);
		std::string CgiGetVal(std::string variable);
		std::string CgiGetRequestToString();
	private:
		std::map<std::string, std::string> requestMap;
		void ParseRequestString(std::string requestString);
		std::vector<std::string> SplitVariable(std::string variableString);
};

