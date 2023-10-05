
// rotateCalcApp.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CrotateCalcAppApp:
// Сведения о реализации этого класса: rotateCalcApp.cpp
//

class CrotateCalcAppApp : public CWinApp
{
public:
	CrotateCalcAppApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CrotateCalcAppApp theApp;
