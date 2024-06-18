#pragma once
#include<iostream>
#include<cstddef>
#include <iomanip>
#include <chrono>
#include <thread>
#include "Design.h"

using namespace std;

Design rem;  //Loading Bar

//=======================================================Agent Usage===============================================
class Node {
public:
    string fName;
    string lName;
    string crime;
    string location;
    string contact;
    Node* next;

    Node( string fName, string lName, string crime, string location, string contact)
        :   fName(fName), lName(lName), crime(crime), location(location), contact(contact), next(nullptr) {}
};

class Capabilities 
{
public:
    Node* head;
    int size;

    Capabilities() {
        head = NULL;
        size = 0;
    }

    void addCrminal(string fName, string lName, string crime, string location, string contact) {
        Node* newNode = new Node(fName, lName, crime, location, contact);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    void displayCriminal() {
        tempadmin:
        Node* current = head;
        int count = 1;

        cout << "List of all Criminals:\n\n";
        cout << "\033[34m";
        cout << "==========================================================================================================" << endl;cout << "\033[33m";
        cout << left << setw(4) << "No." << setw(15) << "First Name" << setw(15) << "Last Name" << setw(40) << "Crime" << setw(25) << "Location" << setw(15) << "Contact" << setw(18) <<"\033[37m"<<endl;
        
        while (current != nullptr) {
            cout << left << setw(4) << count << setw(15) << current->fName << setw(15) << current->lName << setw(40) << current->crime << setw(25) << current->location << setw(18) << current->contact << setw(15) << endl;
            current = current->next;
            count++;
        }
        cout << "\033[34m";
        cout << "\n\n==========================================================================================================\n\n" << endl;cout << "\033[33m";
        cout << "\033[33m";
        cout << endl;
        system("pause");
        system("cls");
    }
    void findCriminal() {
        cout << "\033[31m";
        cout << "FBI Criminal Data Base" << endl;
        cout << "\n>> Last Updated 3 12 2023\n" << endl;
        cout << "Enter the First name of the Accused Person to be identified : ";
        string nameFCrminal;
        cin >> nameFCrminal;
        Node* temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->fName == nameFCrminal) {
                cout << "\033[34m";
                cout << "\n=============================================================="<<endl;
                cout << "\033[32m";
                cout << "\nPerson Identified !\n\nYour Request will be executed shortly........" << endl;
                cout << "\033[34m";
                cout << "\n==============================================================\n" << endl;
                cout << "\033[33m";
                system("pause");
            here:
                system("cls");
                cout << "\033[31m";
                cout << "Are you sure want to Acess Criminal " << temp->fName << " details [Y,N]?" << endl;cout << "\033[33m";
                string ans;
                cin >> ans;
                if ((ans == "Y") or (ans == "y")) {
                    system("cls");
                    cout << "Processing...." << endl;
                    rem.disbar();
                    system("cls");
                    cout << "\033[34m";
                    cout << ("================================================\n") << endl;cout << "\033[33m";
                    cout << "Criminal first Name    : " << temp->fName << endl;
                    cout << "Criminal last Name     : " << temp->lName << endl;
                    cout << "Crime history          : " << temp->crime << endl;
                    cout << "Current Location       : " << temp->location << endl;
                    cout << "Contact                : " << temp->contact << endl;cout << endl;
                    cout << "\033[34m";
                    cout << ("================================================\n") << endl;
                    cout << "\033[33m";
                    system("pause");
                    goto end;

                }
                else {
                    cout << "Input Invalid !" << endl;
                    goto here;
                }
                system("cls");
            }
            temp = temp->next;
        }
        cout << "There is no Agent in the name you entered....\Try Again\n" << endl;
        system("pause");
    end:
        cout << "\033[33m";
        system("cls");
        
    }

    void contactAgent() {
        int towncode;
        cout << "\033[37m";
        cout << "Choose the location you want to communicate...... " << endl;cout << "\033[31m";
        cout << "\n       ============================================       \n" << endl;cout << "\033[33m";
        cout << "1 . New York City         [1]" << endl;
        cout << "2 . Portland              [2]" << endl;
        cout << "3 . San Fransisco         [3]" << endl;
        cout << "4 . Brooklyn              [4]" << endl;
        cout << "5 . Boston                [5]" << endl;cout << "\033[31m";
        cout << "\n       ============================================       " << endl;
        cout << "\033[37m";
        cout << "\nEnter the key for the location (As bracketed above) : " << endl;
        cout << "\033[33m";
        cin >> towncode;

        switch (towncode)
        {
        case 1:
            system("cls");
          cout << "\n     =================================================       \n" << endl;
            cout << "       Welcome to NYC city Emergency Contact Center" << endl;
            cout << "         Seal Team           => 91-321323123123" << endl;
            cout << "         Intelligence Unit   => 91-321323342233" << endl;
            cout << "         Defence Academy     => 91-356323342233" << endl;
          cout << "\n     =================================================       \n" << endl;
          break;

        case 2:
            system("cls");
            cout << "\n     =================================================       \n" << endl;
            cout << "       Welcome to PTC city Emergency Contact Center" << endl;
            cout << "         Seal Team           => 91-321323123189" << endl;
            cout << "         Intelligence Unit   => 91-321323342209" << endl;
            cout << "         Defence Academy     => 91-345323345633" << endl;
            cout << "\n     =================================================       \n" << endl;
            break;

        case 3:
            system("cls");
            cout << "\n     =================================================       \n" << endl;
            cout << "       Welcome to SFC city Emergency Contact Center" << endl;
            cout << "         Seal Team           => 91-321123123123" << endl;
            cout << "         Intelligence Unit   => 91-341323342233" << endl;
            cout << "         Defence Academy     => 91-986323342233" << endl;
            cout << "\n     =================================================       \n" << endl;
            break;

        case 4:
            system("cls");
            cout << "\n     =================================================       \n" << endl;
            cout << "       Welcome to BRK city Emergency Contact Center" << endl;
            cout << "         Seal Team           => 91-325623123123" << endl;
            cout << "         Intelligence Unit   => 91-326783342233" << endl;
            cout << "         Defence Academy     => 91-356389342233" << endl;
            cout << "\n     =================================================       \n" << endl;
            break;

        case 5:
            system("cls");
            cout << "\n     =================================================       \n" << endl;
            cout << "       Welcome to BOS city Emergency Contact Center" << endl;
            cout << "         Seal Team           => 91-451323123123" << endl;
            cout << "         Intelligence Unit   => 91-334323342233" << endl;
            cout << "         Defence Academy     => 91-896323342233" << endl;
            cout << "\n     =================================================       \n" << endl;
            break;


        default:
            break;
        }
    }

};

//=======================================================Admin Panel==============================================

class NodeAdmin {
public:
    string fName;
    string lName;
    string service;
    string location;
    string contact;
    NodeAdmin* next;

    NodeAdmin(string fName, string lName, string service, string location, string contact)
        : fName(fName), lName(lName), service(service), location(location), contact(contact), next(nullptr) {}
};

class AdminCapabilities
{
public:
    NodeAdmin* head;
    int size;

    AdminCapabilities() {
        head = NULL;
        size = 0;
    }

    void addAdmin(string fName, string lName, string service, string location, string contact) {
        NodeAdmin* newAdminNode = new NodeAdmin(fName, lName, service, location, contact);
        if (head == nullptr) {
            head = newAdminNode;
        }
        else {
            NodeAdmin* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newAdminNode;
        }
        size++;
    }

    void displayAgent() {
        NodeAdmin* current = head;
        int count = 1;
        cout << "\033[36m";cout << endl;
        cout << "                               List of all Agents\n"<<endl;
        cout << "\033[31m";
        cout << "=====================================================================================================================\n"<<endl;
        cout << "\033[33m";
        cout << left << setw(4) << "No." << setw(15) << "First Name" << setw(15) << "Last Name" << setw(40) << "Service" << setw(25) << "Location" << setw(15) << "Contact" << setw(18) << endl;
        cout << "\033[37m" << endl;
        if (head == NULL) {
            cout << "\033[31m";
            cout << "\nNo Agent Detail to show" << endl;
            cout << "\033[33m";
        }
        else {
            
 while (current != nullptr) {
            
            cout << left << setw(4) << count << setw(15) << current->fName << setw(15) << current->lName << setw(40) << current->service << setw(25) << current->location << setw(15) << current->contact << setw(18) << endl;
            current = current->next;
            count++;
        }
        }
        cout << "\033[31m";
        cout << endl;
        system("pause");
        system("cls");
    }

    void removeAgent() {
        system("cls");
        cout << "\033[31m" << endl;
        cout << "!!!!!!!!!! This Process can not be redo after Finished !!!!!!!!!!" << endl;
        cout << "Entering Priviledged Secure Area.........." << endl;cout << "\033[32m" << endl;
        cout << "Authenthicating.........." << endl;
        cout << "Admin Priviledged Granted...........\n" << endl;cout << "\033[31m" << endl;
        system("pause");
        system("cls");cout << "\033[37m";
        cout << "Enter the First name of the Agent to be removed : ";
        string nameRmAg;cout << "\033[31m";
        cin >> nameRmAg;
        NodeAdmin* temp = head;
        NodeAdmin* back = temp;
        for (int i = 0; i < size; i++) {
            if (temp->fName == nameRmAg) {
            here:
                cout << "\033[34m";
                cout << "\n\n===================================================================" << endl;cout << "\033[32m";
                cout << "\nPerson Identified\nYour Request will be executed shortly" << endl;
                cout << "\033[34m";
                cout << "\n===================================================================" << endl;
                cout << "\033[31m" << endl;system("pause");system("cls");
                cout << "   Are you sure want to remove Agent < " << temp->fName << " > [Y,N] : ";
                string ans;    
                cin >> ans;
                cout << "\033[33m" << endl;
                if (ans == "Y" or ans =="y") {
                    system("cls");
                    cout << "\033[32m";
                    cout << "Processing....\n" << endl;
                    rem.disbar();
                    cout << "\033[31m";
                    system("pause");
                    system("cls");
                    cout << "\033[33m";

                    if (size == 1) {
                        head = NULL;
                    }
                    else {
                        back->next = temp->next; //removing a node from linked list (admin privileged)
                        system("cls");
                    }
                    system("cls");
                    cout << "\033[31m";
                    cout << "=======================================================" << endl;
                    cout << "\033[32m" << endl;
                    cout << "Agent Details Removed Succesfully....\nSystem Updated." << endl;
                    cout << "\033[31m" << endl;
                    cout << "=======================================================\n" << endl;
                    cout << "\033[37m" << endl;
                    system("Pause");cout << "\033[33m";
                }
                else {
                    cout << "\033[31m" << endl;
                    cout << "Error code 203........." << endl;
                    cout << "Input Invalid !!!! .............." << endl;
                    cout << "\033[33m" << endl;
                    goto here;
                }
                system("cls");
            }
            back = temp;
            temp = temp->next;
        }
        cout << "\033[31m" << endl;
        cout << "There is no Agent in the name you entered....\nTry Again....." << endl;
        cout << "\033[33m" << endl;
        system("cls");
    }

    void findAgent() {
        cout << "\033[31m" << endl;
        cout << "             Welcome to FBI Agent Data Base\n" << endl;  cout << "\033[36m";
        cout << "===============================================================================" << endl; cout << "\033[37m";
        cout << "\n\tEnter the First name of the Agent : "; cout << "\033[37m";
        string nameFAg;
        cin >> nameFAg;
        NodeAdmin* temp = head;
        for (int i = 0; i < size; i++) {
            if (temp->fName == nameFAg) {
                system("cls");
                cout << "\033[32m";
                cout << "\n\nPerson Identified.....\n\n=====================================\n\nYour Request will be executed shortly" << endl;
            here:
                cout << "\033[31m" << endl;
                system("pause");
                system("cls");
                cout << "Are you sure want to Acess Agent << " << temp->fName << " >> details [Y,N]?" << endl;
                string ans;
                cin >> ans;
                if (ans == "Y" or "y") {
                    system("cls");
                    rem.disbar();
                    system("cls");
                    cout << "\033[31m";
                    cout << "Details of the Agent" << endl;
                    cout << "\033[36m" << endl;
                    cout << "\n=========================================================\n" << endl;cout << "\033[37m";
                    cout << "Agent first Name   : " << "\033[33m" << temp->fName    <<  "\033[37m"  << endl;
                    cout << "Agent last Name    : " << "\033[33m" << temp->lName    <<  "\033[37m"  << endl;
                    cout << "Agent Service      : " << "\033[33m" << temp->service  <<  "\033[37m"  << endl;
                    cout << "Current Location   : " << "\033[33m" << temp->location <<  "\033[37m"  << endl;
                    cout << "Agent Contact      : " << "\033[33m" << temp->contact  <<  "\033[37m"  << endl;
                    cout << "\033[36m" << endl;
                    cout << "=========================================================\n\n" << endl;
                    cout << "\033[31m" << endl;
                    system("pause");
                    cout << "\033[33m" << endl;
                }
                else {
                    cout << "\033[31m" << endl;
                    cout << "Input Invalid !" << endl;
                    cout << "\033[33m";
                    goto here;
                }
                system("cls");
            }
            temp = temp->next;
        }
        cout << "\033[31m" << endl;
        cout << "There is no Agent in the name you entered....\Try Again" << endl;cout << "\033[33m";
        system("cls");
    }

    int accessCrime() {
        nowback:
        cout << "\033[36m" << endl;
        cout << "              Acessing Current Crime Reports" << endl;cout << "\033[31m";
        cout << "=======================================================================" << endl;cout << "\033[37m";
        cout << "This is a monitor scope of Agent Level.........\n\n";cout << "\033[31m";
        cout << "This Process Will Lead you to be Out of Admin Privilledged........" << endl;
        cout << "You Have to Relog once after Process Done.........\n\n\n"<<endl;
        cout << "Are You sure want to continue ? [Y / N]" << endl;
        string ans;
        cin >> ans;
        if (ans == "y" or ans == "Y") {
            system("cls");
            cout << "\033[31m" << endl;
            cout << "You are out of Admin Privilledged........" << endl;cout << "\033[36m" << endl;
            cout << "\n=============================================== " << endl;
        
            cout << "\033[32m" << endl;
            cout << "Processing........" << endl;
            cout << "Successful Login as an Hybrid Agent........" << endl;cout << "\033[36m" << endl;
            cout << "===============================================" << endl;cout << "\033[33m" << endl;

            system("pause");
            system("cls");
            return 30;
        }

        else if (ans == "N" or ans == "n") {
            system("cls");
        }
        else {
            system("cls");
            cout << "\033[31m" << endl;
            cout << "Your Input is Invalid.........." << endl;
            cout << "Try Again" << endl;
            cout << "\033[37m" << endl;cout<<"\n\n\n";
            system("pause");
            //goto nowback;
            
        }
    }

};
