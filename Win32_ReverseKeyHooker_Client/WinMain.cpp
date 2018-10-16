#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include "../EchoClient.h"
#include "../vkCodeLisk.h"


//int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
//	, LPSTR lpszCmdParam, int nCmdShow)
//{
//	for (int i = 0; i < 10; i++)
//	{
//		keybd_event(reverseVkCodeList["0"], 0, 0, 0);
//		keybd_event(reverseVkCodeList["0"], 0, KEYEVENTF_KEYUP, 0);
//		Sleep(100);
//	}
//}

int main()
{
	while (true)
	{
		keybd_event(0x51, 0, 0, 0);								//Q
		keybd_event(0x51, 0, KEYEVENTF_KEYUP, 0);
		Sleep(200);
		keybd_event(0x57, 0, 0, 0);								//W
		keybd_event(0x57, 0, KEYEVENTF_KEYUP, 0);
		Sleep(200);
		keybd_event(0x52, 0, 0, 0);								//R
		keybd_event(0x52, 0, KEYEVENTF_KEYUP, 0);
		Sleep(700);
	}
}