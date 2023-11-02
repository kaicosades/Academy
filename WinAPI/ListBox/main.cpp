#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "resource.h"
#include <cstdio>


CONST CHAR* G_SZ_VALUES[] = { "This", "is", "my", "first", "Combo", "Box" };

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);//Вызов окна


INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc, 0); // DlgProc нужно либо явно преобразовывать либо ставить архитектуру х86

	return 0;

}


BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//HWND - handler to window (Обработчик онка);
	//uMsg - unsigned Message // Сообщение, месседж - беззнаковая переменная
	//wParam , lParam - параметры сообщения;
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HWND hList = GetDlgItem(hwnd, IDC_LIST1);
		for (int i = 0; i < sizeof(G_SZ_VALUES) / sizeof(G_SZ_VALUES[0]); i++)
			SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)G_SZ_VALUES[i]);//CB_ADDSTRING - второй параметр
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hList = GetDlgItem(hwnd, IDC_LIST1);
			int i = SendMessage(hList, LB_GETCURSEL, 0, 0); // Второй аргумент - CB_GETLBTEXT
			SendMessage(hList, LB_GETTEXT, i, (LPARAM)sz_buffer); // Второй аргумент - CB_GETLBTEXT

			CHAR sz_message[SIZE]{};
			sprintf(sz_message, "Вы выбрали элемент № %i со значением \"%s\"", i, sz_buffer);
			//i - интовое значение, s - стриноговое. В конце функции параметры для вывода.
			MessageBox(hwnd, sz_message, "Info", MB_OK | MB_ICONINFORMATION);
		}
		break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;



}