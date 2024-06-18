#pragma once
#include "Design.h"
using namespace std;


class Noderoot// : public Capabilities, AdminCapabilities //inheritance is used to access Admin and Agent Attributes
{
public:
    string fName;
    string lName;
    string service;
    string location;
    string contact;
    Noderoot* next;

    Noderoot(string fName, string lName, string service, string location, string contact)
        : fName(fName), lName(lName), service(service), location(location), contact(contact), next(nullptr) {}
};

class RootCapabilities : Capabilities
{
    string arr[4][2] = { {"132132","Moscow"},{"232313","Pearl Harbour"},{"354325","New Delhi"},{"44212","Tokyo"} };
public:
    Noderoot* head;
    int size;

    RootCapabilities() {
        head = NULL;
        size = 0;
    }

    void readsecurecodes() {
        int j = 0;
        cout << "\033[34m";
        cout << "       Here are the current Secret Operation codecs \n" << endl;
        cout << "\033[31m";
        cout << "==========================================================" << endl;
        cout << "\033[33m";
        cout << "\n\nSecret Code\t\t\t\t\tLocation\n" << endl;
        
            while (j < 4) {
                cout << "\033[31m" <<arr[j][0] << "\t\t\t\t\t\t" <<"\033[33m"<< arr[j][1] << endl;
                j++;  
            }
            cout << "\033[31m";
            cout << "\n\n";
        }
    
    void interAgency() {
        system("cls");cout << "\033[31m" << endl;
        cout << "                Inter Agency Transmission Reports" << endl;cout << "\033[34m";
        cout << "===================================================================" << endl;cout << "\033[33m";cout << endl;
        cout << "       Mozad/ISR                               Alert 209" << endl;cout << "\033[37m";
        cout << "          >> Emergency ! ISR Army need more Armory support, Arab League is continously attacking us." << endl;
        cout << "          >> 2023/12/03  3.33pm" << endl;cout << "\033[31m";
        cout << "          >> Red Alerted\n" << endl;cout << "\033[33m";
        
        cout << "       RAW/IND                                 Alert 210" << endl;cout << "\033[37m";
        cout << "          >> Emergency ! We got an unofficial info of Hamas terroist with a plan of bomb blast," << endl;
        cout << "             on January 12 in WTC NYC. Reply ASAP" << endl;
        cout << "          >> 2023/12/02  2.30am" << endl;cout << "\033[31m";
        cout << "          >> Red Alerted" << endl;cout << "\033[33m";
        cout << endl;
        cout << "       CIA/PAK                                 Alert 245" << endl;cout << "\033[37m";
        cout << "          >> We have traced your Agent Macrov in Lahore found dead. Confirm dead." << endl;
        cout << "             Found FMC armory. Reply ASAP" << endl;
        cout << "          >> 2023/11/21  2.35pm" << endl;cout << "\033[31m";
        cout << endl;cout << "\033[33m";
        cout << "\n\n";
        system("pause");
        system("cls");
    }
};

