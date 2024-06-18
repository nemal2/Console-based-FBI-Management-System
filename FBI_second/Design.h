#pragma once
#include<conio.h>
#include <iostream>
#include<stdio.h>
#include<Windows.h>
#include <string>

using namespace std;
class Design
{
public:
	int bar1 = 177;int bar2 = 219;

	void disbar() {
		system("COLOR 0e");
		system("cls");
		//printf("\e[?251");

		SetConsoleCP(437);
		SetConsoleOutputCP(437);
		cout << "\033[33m";
		cout << "\n\n\n\t\t\tLoading Account Details....";
		cout << "\n\n\n\t\t\t";
		cout<<"\033[32m";
		for (int i = 0; i < 40; i++) {
			cout << (char)bar1;
		}
		cout << "\r";
		cout << "\t\t\t\t";
		for (int i = 0; i < 40;i++) {
			cout << (char)bar2;
			Sleep(30);
		}
		cout << "\n\n\t\t\t\tLoaded Sucessfully" << endl;
		cout << "\n\t\t\t\t" << (char)1 << " ";
		cout << "\033[31m";
		cout << endl;cout << endl;
		system("Pause");cout << "\033[33m";
	}

	void ascii() {
		printf("||========================================================================================|| \n");
		
			
}





};

