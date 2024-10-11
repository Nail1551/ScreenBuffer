#include <iostream>
#include <Windows.h>
int main()
{
	COORD coord; 
	HANDLE hStd0ut; 
	
	hStd0ut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	std::cout << "Enter new screen buffer size." << std::endl;
	std::cout << "A number of columns: ";
	std::cin >> coord.X;
	std::cout << "A number of rows: ";
	std::cin >> coord.Y;
	
	if (!SetConsoleScreenBufferSize(hStd0ut, coord))
		std::cout << "Set console screen buffer size failed." << std::endl; return GetLastError();
	return 0;
}