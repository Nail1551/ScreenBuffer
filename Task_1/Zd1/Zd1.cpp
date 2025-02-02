﻿#include <windows.h>
#include <conio.h> 
int main() {
	HANDLE hStd0ut0ld, hStd0utNew; 
	DWORD dwWritten; 
	hStd0utNew = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE, 
		0, 
		NULL, 
		CONSOLE_TEXTMODE_BUFFER, 
		NULL); 
	if (hStd0utNew == INVALID_HANDLE_VALUE) {
		_cputs("Create console screen buffer failed.\n");
		return GetLastError();
	}
	 
	hStd0ut0ld = GetStdHandle(STD_OUTPUT_HANDLE);
	
	_cputs("Press any key to set new screen buffer active.\n");
	_getch();
	
	if (!SetConsoleActiveScreenBuffer(hStd0utNew))
	{
		_cputs("Set new console active screen buffer failed.\n");
		return GetLastError();
	}

	char text[] = "This is a new screen buffer.";
	if (!WriteConsole(
		hStd0utNew, 
		text, 
		sizeof(text), 
		&dwWritten, 
		NULL)) 
		_cputs("Write console output character failed.\n");
	
	char str[] = "\nPress any key to set old screen buffer.";
	if (!WriteConsole(
		hStd0utNew, 
		str, 
		sizeof(str), 
		&dwWritten, 
		NULL)) 
		_cputs("Write console output character failed.\n");
	_getch(); 
	if (!SetConsoleActiveScreenBuffer(hStd0ut0ld))
	{
		_cputs("Set old console active screen buffer failed.\n");
		return GetLastError();
	}
	
	_cputs("This is an old console screen buffer.\n"); 
	CloseHandle(hStd0utNew);
	
	_cputs("Press any key to finish.\n");
	_getch();
	return 0;

}