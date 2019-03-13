#include <vcl.h>
#include <windows.h>

#pragma hdrstop
#pragma argsused

#include <tchar.h>

#include <stdio.h>
#include <iostream>
#include <windows.h>

using namespace std;

typedef int (__stdcall* PMyName)();

int _tmain(int argc, _TCHAR* argv[])
{
	HINSTANCE hDll;
	hDll = LoadLibrary(L"DaniilDLL.dll");
	if(hDll == NULL) {
		cout << "Error!";
		system("pause");
		return 1;
	}
    if (hDll != NULL)
    {
		cout << "Library was loaded\n";
	}
	PMyName MyName = (PMyName)GetProcAddress(hDll, "MyName");
	if (MyName == NULL) {
		cout << "NEuspeh\n";
	}
	(*MyName)();
	system("pause");
	return 0;
}
