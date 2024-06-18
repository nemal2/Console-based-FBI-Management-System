#pragma once
#include "Capabilities.h"
#include "root.h"
#include "hash.h"
#include "Cipher.h"
#include <iostream>
#include<cstddef>
#include <iomanip>
#include <chrono>
#include <thread>
#include<string>

using namespace std;
Capabilities cap;
AdminCapabilities Acap;
RootCapabilities Rcap;
Cipher csr;



class Mainmenu
{
public:
	int choice;
	int verify;
	string react;

	Mainmenu() {
		choice = 0;
	}

	int AgentMainMenu() {
		try {				//exception handled using try catch 
			cout << "\033[36m";
			cout << "|||-------------<< Agent Menu Panel >>-------------|||\n" << endl; cout << "\033[31m";
			cout << "======================================================\n" << endl; cout << "\033[33m";
			cout << "Please Enter Your Selection : " << endl; cout << "\033[37m";
			cout << "\n\t\t 1. Add Criminal Detail \n\t\t 2. Show Criminal Detail\n\t\t 3. Find Criminal Detail\n\t\t 4. Add Secret Message\n\t\t 5. Contact Agents\n\t\t 6. Quit" << endl;
			cout << "\033[31m";
			cout << "\n======================================================\n" << endl;cout << "\033[33m";
			cout << "\n\n\t\t Your selection : "; cout << "\033[37m";
			cin >> choice;
			cout << "\033[33m";
			if (choice == 1 or choice == 6 or choice == 2 or choice == 3 or choice == 4 or choice == 5) {
				switch (choice) {
				case 1:
					system("cls");
					addnode();
					break;
				case 2:
					system("cls");
					cap.displayCriminal();
					AgentMainMenu();
					break;
				case 3:
					system("cls");
					cap.findCriminal();
					AgentMainMenu();
					break;
				case 4:
					system("cls");
					csr.ceaser();
					system("pause");
					system("cls");
					AgentMainMenu();
					break;

				case 5:
					system("cls");
					cap.contactAgent();
					system("pause");
					system("cls");
					AgentMainMenu();
					break;

				case 6:
					system("cls");
					cout << "Are you sure want to exit[Y/N] ?" << endl;
					cin >> react;
					if (react == "Y" or react == "y") {
						cout << endl;
						cout << "\033[33m" << endl;
						cout << "===================================================\n" << endl;
						cout << "\033[31m" << endl;
						cout << "Program Ended Succesfully....\nLogging Out......." << endl;
						cout << "\033[33m" << endl;
						cout << "\n===================================================\n\n" << endl;
						system("pause");
						system("cls");
						return 2;
						break;
					}
					else if (react == "N" or react == "n") {
						system("cls");
						AgentMainMenu();
						
					}
					break;
				}
				
			}

			else {
				system("cls");
				cout << "\033[31m" << endl;
				cout << "Your Input is Invalid..........\nTry Again..........." << endl;
				cout << "cls";
				cout << "\033[33m" << endl;
				return 1;
			}

		}
		catch (...) {
			cout << "exception Threw\nProgramme will be terminated....." << endl;
			exit;
		}
	}

	void addnode() {
        string fName, lName, location, contact;
		string crime;
		cout << "\033[33m";
		cout << "				Agent Report of Crime Case\n" << endl;
		cout << "\033[34m";
		cout << "===========================================================================================" << endl;
		cout << "\033[33m" << endl;
        cout << "Please enter first name of the suspect: ";
		cout << "\033[37m";
        cin >> fName;
		cout << "\033[33m";
        cout << "Please enter last name of the suspect: ";
		cout << "\033[37m";
        cin >> lName;cin.ignore();
		cout << "\033[33m";
        cout << "Please enter detail about crime scene: "<<endl;
		cout << "\033[37m";
        getline(cin,crime);
		cout << "\033[33m";
        cout << "Please enter last location of the suspect: ";
		cout << "\033[37m";
        cin >> location;
		cout << "\033[33m";
        cout << "Please enter any contact detail of the suspect: ";
		cout << "\033[37m";
        cin >> contact;

		cout << "\033[34m";
		cout << "\n===========================================================================================" << endl;
		cout << "\033[32m" << endl;
		cap.addCrminal(fName, lName, crime, location, contact);
		cout << "\033[32m" << endl;
		cout << endl << "Crime Details Added Successfully!!!" << endl;
		cout << "\033[33m" << endl;
		cout << "\033[31m";
        system("pause");
		cout << "\033[33m";
        system("cls");
        AgentMainMenu();
    
	}

	int AdminMainMenu() {

		cout << "\033[36m";
		cout << "|||-------------<< Admin Menu Panel >>-------------|||\n" << endl; cout << "\033[34m";
		cout << "======================================================\n" << endl; cout << "\033[33m";
		cout << "Please Enter Your Selection : " << endl; cout << "\033[37m";
		cout << "\n\t\t 1. Add a new Agent \n\t\t 2. Get Agent List\n\t\t 3. Find an Agent\n\t\t 4. Remove an Agent\n\t\t 5. Access crime Informations\n\t\t 6. Quit" << endl;
		cout << "\033[34m";
		cout << "\n======================================================\n" << endl;cout << "\033[33m";
		cout << "\n\n\t\t Your selection :"; cout << "\033[37m";
		cin >> choice;
		cout << "\033[33m";

		if (choice == 1 or choice == 6 or choice == 2 or choice == 3 or choice == 4 or choice == 5) {
			switch (choice) {
			case 1:
				system("cls");
				addAgentnode();
				break;
			case 2:
				system("cls");
				Acap.displayAgent();
				AdminMainMenu();
				break;

			case 3:
				system("cls");
				Acap.findAgent();
				AdminMainMenu();
				break;

			case 4:     
				system("cls");
				Acap.removeAgent();
				AdminMainMenu();
				break;

			case 5:
				system("cls");
				int temp;
				temp=Acap.accessCrime();
				if (temp == 30) {
					return 5;
				}
				else{
					AdminMainMenu();
				}
				
				break;

			case 6:
				system("cls");
				cout << "\033[31m";
				cout << "Are you sure want to exit[Y] ? " << endl;
				cin >> react;
				if (react == "Y" or react == "y") {
					cout << endl;
					cout << "\033[33m" << endl;
					cout << "===================================================\n" << endl;
					cout << "\033[32m" << endl;
					cout << "Program Ended Succesfully....\nLogging Out......." << endl;
					cout << "\033[33m" << endl;
					cout << "\n===================================================\n\n" << endl;
					system("pause");
					system("cls");
					return 2;
				}
				break;

			}
		}
		else {
			system("cls");
			cout << "\033[31m" << endl;
			cout << "Your Input is Invalid.........." << endl;
			cout << "\033[33m" << endl;
			return 1;
		}
		
		


	}

	void addAgentnode() {
		string fName, lName, service, location, contact;
		cout << "\033[36m";
		cout << "				Profile of the New FBI Agent\n" << endl;
		cout << "\033[34m";
		cout << "===========================================================================================" << endl;
		cout << "\033[33m" << endl;
		cout << "Please enter first name of the Agent			: ";
		cout << "\033[37m" ;
		cin  >> fName;
		cout << "\033[33m" << endl;
		cout << "Please enter last name of the Agent			: ";
		cout << "\033[37m";
		cin  >> lName;cin.ignore();
		cout << "\033[33m"<<endl;
		cout << "Please enter service details of the Agent		: ";
		cout << "\033[37m";
		getline(cin,service);
		cout << "\033[33m"<<endl;
		cout << "Please enter last location of the Agent			: ";
		cout << "\033[37m"; 
		cin >> location;
		cout << "\033[33m" << endl;cin.ignore();
		cout << "Please enter any contact detail of the Agent		: ";
		cout << "\033[37m";
		cin >> contact;
		cout << "\033[34m";
		cout << "\n===========================================================================================" << endl;
		cout << "\033[32m" << endl;
		Acap.addAdmin(fName, lName, service, location, contact);
		cout << endl << "\nAgent Details Added Successfully!!!\n\n";
		cout << "\033[31m";
		system("pause");
		cout << "\033[33m";
		system("cls");
		AdminMainMenu();

	}

	int RootMainMenu() {
	hereroot:

		cout << "\033[31m";
		cout << "|||-------------<< Root Menu Panel >>-------------|||\n" << endl; cout << "\033[36m";
		cout << "======================================================\n" << endl; cout << "\033[33m";
		cout << "Please Enter Your Selection : " << endl; cout << "\033[37m";
		cout << "\n\t\t 1. Get Agent View \n\t\t 2. Get Admin View\n\t\t 3. Secret Operation Codes\n\t\t 4. Inter-Agency Data Tranmission\n\t\t 5. Temperory System Termination\n\t\t 6. Quit" << endl;
		cout << "\033[36m";
		cout << "\n======================================================\n" << endl;cout << "\033[33m";
		cout << "\n\n\t\t Your selection : "; cout << "\033[37m";
		int ch;
		string react;
		cin >> ch;
		//cin >> choice;
		cout << "\033[33m";

		
		if (ch == 1 or ch== 2 or ch == 3 or ch== 4 or ch == 5 or ch == 6) {
			choice = ch;
		}
		else {
			cout << "\033[31m" << endl;
			cout << "Input is not identified try Again" << endl;
			system("cls");
			cout << "\033[33m" << endl;
			goto hereroot;
		}
		

		switch (choice) {
		case 1:
			system("cls");
			return 11;
			break;
		case 2:
			system("cls");
			return 12;
			break;

		case 3:
			system("cls");
			//Thsese things should be gained from secure data bases for model that we use arrays
			Rcap.readsecurecodes();
			system("pause");
			system("cls");
			RootMainMenu();
			break;

		case 4:
			system("cls");
			Rcap.interAgency();
			RootMainMenu();
			break;

		case 5:
			system("cls");
			RootMainMenu();
			break;

		case 6:
			system("cls");
			cout << "\033[31m" << endl;
			cout << "Are you sure want to exit[Y/N] ?" << endl;
			cout << "\033[33m" << endl;
			cin >> react;
			if (react == "Y" or react == "y") {
				exit;
			}
			else {
				system("cls");
				RootMainMenu();
			}
			break;

	}
		
		return 0;
	}

};



