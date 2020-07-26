#include "pch.h"
#include "Application.h"
#include "HTML.h"
Application::Application(EXTENSION_CONTROL_BLOCK *pECB) {
	this->pECB = pECB;
	this->html = new HTML(pECB);
	this->cgiRequest = new CgiRequest(pECB);
}

Application::~Application() {
	delete this->html;
	delete this->cgiRequest;
}

HTML * Application::getHTML() {
	return this->html;
}

CgiRequest * Application::getCGI() {
	return this->cgiRequest;
}

