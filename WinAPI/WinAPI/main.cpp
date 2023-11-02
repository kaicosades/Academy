//������ ������ �����������. ����� ������� � DialogBox

#include<Windows.h>
#include "Resource.h"

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
			break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK: MessageBox(hwnd, "���� ������ ������ ��", "Info", MB_OK | MB_ICONINFORMATION); break;
		}
		break;
	case WM_CLOSE: EndDialog(hwnd, 0);
	}
	return FALSE;

}
