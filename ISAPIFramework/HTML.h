#pragma once
#include <string>
#include <HttpExt.h>
#include <vector>
class HTML
{	private:
		EXTENSION_CONTROL_BLOCK* pECB;
		std::vector<std::string> styleSheets;
		std::string pageTitle;

	public:
		HTML(EXTENSION_CONTROL_BLOCK* pECB);
		void AddStyleSheet(std::string styleSheetLocation);
		void SetPageTitle(std::string pageTitle);
		void BeginPage();
		void EndPage();
		void print(std::string content);
		void print(TCHAR *content);
};

