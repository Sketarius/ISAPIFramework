#include <iostream>
#include "pch.h"
#include "CgiRequest.h"
#include <string>
#include <map>
#include <vector>
#include <sstream>


CgiRequest::CgiRequest(std::string requestString) {
	this->ParseRequestString(requestString);
}

std::string CgiRequest::CgiGetVal(std::string variable) {
	std::string value;
	try {
		value = requestMap.at(variable);
	} catch (const std::exception & e) {
		value = "";
	}
	return value;
}

std::vector<std::string> CgiRequest::SplitVariable(std::string variableString) {
	std::vector<std::string> ret;
	std::stringstream ss(variableString);

	std::string valueTokenString;

	while (std::getline(ss, valueTokenString, '=')) {
		ret.push_back(valueTokenString);
	}

	return ret;
}

void CgiRequest::ParseRequestString(std::string requestString) {
	std::vector<std::string> variableTokens;
	std::stringstream ss(requestString);

	std::string variableTokenString;	
	

	while (std::getline(ss, variableTokenString, '&')) {
		variableTokens = this->SplitVariable(variableTokenString);
		if (variableTokens.size() > 1) {
			requestMap.insert(std::make_pair(variableTokens[0], variableTokens[1]));
		}
	}
}

std::string CgiRequest::CgiGetRequestToString() {
	std::string returnString = "";
	std::map<std::string, std::string>::iterator it;
	for (it = requestMap.begin(); it != requestMap.end(); it++) {
		returnString += "<div>" + it->first + "=" + it->second + "</div>";
	}

	return returnString;
}
