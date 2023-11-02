﻿#include<Windows.h>
#include "Resource.h"

CONST CHAR G_SZ_LOGIN_INVITATION[] = "Введите имя пользователя";

BOOL CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//MessageBox(NULL, "Hello Windows! Привет...", "Header" /*текст окна*/, MB_YESNOCANCEL /*кнопки*/ | MB_ICONINFORMATION| MB_HELP/*значек*/);
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;


}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 0, (LRESULT)hIcon);
		HWND hLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
		//SetFocus(hLogin); // В скобочках можно сразу вызвать GetDlgItem. Сама функция вызывает окно с активным полем на логине 
		//SetFocus(GetDlgItem(hwnd, IDC_EDIT_LOGIN));
		HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
		SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)G_SZ_LOGIN_INVITATION);
		
	}
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_EDIT_LOGIN:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE]{};
			HWND hEditLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN);
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			if (HIWORD(wParam) == EN_SETFOCUS && strcmp(sz_buffer, G_SZ_LOGIN_INVITATION) == 0)SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)"");
			if (HIWORD(wParam) == EN_KILLFOCUS && strcmp(sz_buffer, "") == 0)SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)G_SZ_LOGIN_INVITATION);
		}
			break;
		case IDOK: MessageBox(hwnd, "Была нажата кнопка ОК", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL: EndDialog(hwnd, 0);
		case IDC_BUTTON_COPY:
		{
			//1) Создаем буфер чтения:
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			//2) Получаем обработчки текстовых полей:
			HWND hLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN); //Функция GetDlgItem() по ID-ресурса дочернего окна возвращает HWND дочернего окна
			HWND hPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			//3) Читаем текст из текстового поля 'Login':
			SendMessage(hLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			//4) Загружаем содержимое текстового буфера в поле 'Pasword':
			SendMessage(hPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_buffer); // меняет заголовок окна
			SendMessage(hPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer); // нужно изменить с помощью кнопки надпись  пассворд
			//break;
		}
		}
		break;
	case WM_CLOSE: EndDialog(hwnd, 0);
	}
	return FALSE;

}
