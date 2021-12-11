// Test_iniFile_01.cpp : définit le point d'entrée pour l'application console
#include <Windows.h>
#include <strsafe.h>
#include "stdafx.h"

void saveInt(char* name, int& value, char* fname)
{
	char buf[4];
	sprintf_s(buf, 20, "%d", value);
	DWORD n = WritePrivateProfileString("plage_de_temperature", name, buf, fname);
	DWORD m = WritePrivateProfileString("resolution_de_la_camera", name, buf, fname);
}

void lireInt(char* name, int& value, char* fname)
{
	char buf[4];
	DWORD n = GetPrivateProfileString("plage_de_temperature_a__detecter", name, 0, buf, sizeof(buf), fname);
	DWORD dw = GetLastError();
	DWORD m = GetPrivateProfileString("resolution_de_la_camera", name, 0, buf, sizeof(buf), fname);
	dw = GetLastError();

	LPTSTR lpszFunction = new char[200];  sprintf_s(lpszFunction, 200, "%s", TEXT("GetProcessId"));
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0, NULL);

	// Display the error message and exit the process

	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
		(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
	StringCchPrintf((LPTSTR)lpDisplayBuf,
			LocalSize(lpDisplayBuf) / sizeof(TCHAR),
			TEXT("%s failed with error %d: %s"),
			lpszFunction, dw, lpMsgBuf);
	MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
	ExitProcess(dw);


	value = atoi(buf);
}

int main(int argc, char* argv[])
{
	char* n = new char[20 ]; sprintf_s(n,20,"%s","degre");
	char* m = new char[20 ]; sprintf_s(m, 20, "%s", "résolution");
	int v =  5;
	char* f = new char[200 ]; sprintf_s(f, 200, "%s", "C:/Users/henry/Desktop/fichier de configuration/fichier.ini");
	
	FILE* pFile;
	pFile = fopen(f, "C:/Users/henry/Desktop/programme de surveillance version 2/Project2.sln" "rb");
	lireInt(n, v, f);
	printf("valeur = %d", v);
	return 0;
}

