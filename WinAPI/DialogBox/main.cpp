#include<Windows.h>
#include "Resource.h"

CONST CHAR G_SZ_LOGIN_INVITATION[] = "������� ��� ������������";

BOOL CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//MessageBox(NULL, "Hello Windows! ������...", "Header" /*����� ����*/, MB_YESNOCANCEL /*������*/ | MB_ICONINFORMATION| MB_HELP/*������*/);
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
		//SetFocus(hLogin); // � ��������� ����� ����� ������� GetDlgItem. ���� ������� �������� ���� � �������� ����� �� ������ 
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
		case IDOK: MessageBox(hwnd, "���� ������ ������ ��", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL: EndDialog(hwnd, 0);
		case IDC_BUTTON_COPY:
		{
			//1) ������� ����� ������:
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			//2) �������� ���������� ��������� �����:
			HWND hLogin = GetDlgItem(hwnd, IDC_EDIT_LOGIN); //������� GetDlgItem() �� ID-������� ��������� ���� ���������� HWND ��������� ����
			HWND hPassword = GetDlgItem(hwnd, IDC_EDIT_PASSWORD);
			//3) ������ ����� �� ���������� ���� 'Login':
			SendMessage(hLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			//4) ��������� ���������� ���������� ������ � ���� 'Pasword':
			SendMessage(hPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)sz_buffer); // ������ ��������� ����
			SendMessage(hPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer); // ����� �������� � ������� ������ �������  ��������
			//break;
		}
		}
		break;
	case WM_CLOSE: EndDialog(hwnd, 0);
	}
	return FALSE;

}
