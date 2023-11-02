#include <Windows.h>
#include "resource.h"

CONST CHAR g_sz_WINDOW_CLASS[] = "My Window Class"; //Имя класса окна

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc)); //обнуление класса

	wc.cbSize = sizeof(wc); //cb - count bytes
	wc.cbWndExtra = 0;		//Дополнительные байты окна
	wc.cbClsExtra = 0;		//Дополнительные байты класса окна
	wc.style = 0;			//Стиль окна

	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_SVARSHIK)); // первый параметр по умолчанию NULL, но его поменяли для значков
	wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_MASK)); //sm - small; IDI_APPLICATION - второй параметр по умолчанию
	
	//wc.hIcon = (HICON)LoadImage(hInstance, "nazvanie_cartinki.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);//на паре делали
	//wc.hIconSm = (HICON)LoadImage(hInstance, "nazvanie_cartinki.ico", IMAGE_ICON, LR_DEFAULTSIZE, LR_DEFAULTSIZE, LR_LOADFROMFILE);//на паре делали

	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = HBRUSH(COLOR_WINDOW + 1);

	wc.hInstance = hInstance; //hInstance - это экземпляр исполняемого файла программы в памяти
	//Функция WinMain() принимает hInstace как параметр, и поэтому к нему есть прямой доступ,
	//В любой другой функции 'hInstance' все можно получить при помощи функции GetModuleHandle(NULL)
	wc.lpfnWndProc = WndProc; //указатель на процедуру окна
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
		WS_OVERLAPPEDWINDOW,	//У главного окна всегда будет такой стиль

		CW_USEDEFAULT, CW_USEDEFAULT,	//Position - положение окна на экране
		CW_USEDEFAULT, CW_USEDEFAULT,	//Size - Размер окна

		NULL,					//Parent Window
		NULL,					//hMenu - для главного окна этот параметр содержит ID_ресурса меню
								//Для дочернего окна, которое является элементом другого окна, в hMenu передается ID_ресурса этого элемента 
		hInstance,
		NULL					//Всегда NULL

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