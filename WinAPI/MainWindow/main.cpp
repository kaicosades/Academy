#include <Windows.h>
#include "resource.h"

CONST CHAR g_sz_WINDOW_CLASS[] = "My Window Class"; //��� ������ ����

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc)); //��������� ������

	wc.cbSize = sizeof(wc); //cb - count bytes
	wc.cbWndExtra = 0;		//�������������� ����� ����
	wc.cbClsExtra = 0;		//�������������� ����� ������ ����
	wc.style = 0;			//����� ����

	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_SVARSHIK)); // ������ �������� �� ��������� NULL, �� ��� �������� ��� �������
	wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_MASK)); //sm - small; IDI_APPLICATION - ������ �������� �� ���������
	
	//wc.hIcon = (HICON)LoadImage(hInstance, "nazvanie_cartinki.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);//�� ���� ������
	//wc.hIconSm = (HICON)LoadImage(hInstance, "nazvanie_cartinki.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);//�� ���� ������

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = HBRUSH(COLOR_WINDOW + 1);

	wc.hInstance = hInstance; //hInstance - ��� ��������� ������������ ����� ��������� � ������
	//������� WinMain() ��������� hInstace ��� ��������, � ������� � ���� ���� ������ ������,
	//� ����� ������ ������� 'hInstance' ��� ����� �������� ��� ������ ������� GetModuleHandle(NULL)
	wc.lpfnWndProc = WndProc; //��������� �� ��������� ����
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_sz_WINDOW_CLASS;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class Registration Failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	HWND hwnd = CreateWindowEx
	(
		NULL,					//ExStyle
		g_sz_WINDOW_CLASS,		//class name
		g_sz_WINDOW_CLASS,		//window name
		WS_OVERLAPPEDWINDOW,	//� �������� ���� ������ ����� ����� �����

		CW_USEDEFAULT, CW_USEDEFAULT,	//Position - ��������� ���� �� ������
		CW_USEDEFAULT, CW_USEDEFAULT,	//Size - ������ ����

		NULL,					//Parent Window
		NULL,					//hMenu - ��� �������� ���� ���� �������� �������� ID_������� ����
								//��� ��������� ����, ������� �������� ��������� ������� ����, � hMenu ���������� ID_������� ����� �������� 
		hInstance,
		NULL					//������ NULL

	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)>0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}
	return msg.wParam;

	return 0;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		break;
	case WM_COMMAND:
		break;
	case WM_DESTROY: PostQuitMessage(0); break;
	case WM_CLOSE: DestroyWindow(hwnd); break;
	default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return NULL;
}