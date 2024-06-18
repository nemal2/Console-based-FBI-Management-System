#include <iostream>
#include "Mainmenu.h"
#include "Capabilities.h"
#include "root.h"
#include "Design.h"
#include<cstddef>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;
string loginName;
string loginPassword;
int loginAttempt = 0;

Mainmenu person;
Design bar;
Hash entry;

int main()
{
    start:
    while (loginAttempt < 6)
    {
        cout << "\033[33m";
        cout << "\t\t\t\t\t\t\t     National Security Department \t\t\t\n" << endl;
        cout << "\t\t\t\t\t\t\t       UNITED STATES OF AMERICA\t\t\t" << endl;
        cout << "\033[31m";
        cout << "\n\n\t\t\t\t\t\t\t FEDERAL BEAURAU OF CRIME INVESTIGATION";
        cout << "\033[34m";
        cout << "\n\n\t\t\t\t\t\tW E L C O M E  T O  T H E   I N F O R M T I O N  S Y S T E M !!\t\t\t";

        cout << "\n\t\t\t\t         ____________________________________________________________________________\t\t\t";

        cout << "\033[31m";
        cout << "\n\n\n\n";
 
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        system("pause");
        system("cls");

        cout << endl;
        cout << "\033[33m";
        cout << "                      =================================================================================================================\n" << endl;
        cout << "\033[31m";
        cout << "                                                               Enter login name   : " ;
        cout << "\033[37m";
        cin >> loginName;
        cout << "\033[31m";
        cout << endl;
        cout << "                                                               Enter password     : " ;
        cout << "\033[37m";
        cin >> loginPassword;
        cout << "\033[33m";

        //=========================================hash==================================================

        Hash myLogin;
        string password = "root";

        // this can create a random salt
        string salt = myLogin.addsalt(16);  //developer can change the length
        // cout << "Generated Salt: " << salt << endl;

         //Hashing the password + generated salt
        string hashedPassword = myLogin.hashcal(password, salt);

        //cout << "Input Password: " << password << endl;
        //cout << "Salted Password: " << password + salt << endl;
        //cout << "Hashed Password (with salt): " << hashedPassword << endl;

        //$$$$$$$$$  Hashed Password (with salt): 8a5abdf1a362fb3f7d8f45181e0885bd502b6016e356593daa832fa286de5294  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$4



     //=========================================agent===================================================
        int resultAg = 0;
        int resultAd = 0;
        if (loginName == "agent" && loginPassword == "agent")
        {
            if (resultAg == 2) {
                exit;
        }

        here11:    //a call from root
            system("cls");
            bar.disbar();
            system("cls");
            try{
                if (resultAg == 2) {
                    break;
                    exit;
                }
                int resultAg = 0;
                while (resultAg == 0 or resultAg==1) {
                    resultAg = person.AgentMainMenu();
                    if (resultAg == 1) {
                        cout << "Program will be terminted and restart......" << endl;
                        system("pause");
                        goto here11;
                    }
                    else if (resultAg == 2) {
                        system("pause");
                        cout << "\033[31m";
                        cout << "Logging out as Agent .........." << endl;
                        cout << "Program End .......... " << endl;
                        system("pause");
                        cout << "\033[33m";
                        system("cls");
                        exit;
                    }
                    else {
                        //goto here11;
                    }
                } 
            }
            catch (...) {
                cout << "Try Again" << endl;
                system("pause");
                system("cls");
                person.AgentMainMenu();
            }
            
        }




     //=========================================admin==================================================

        if (loginName == "admin" && loginPassword == "admin")
        {
            if (resultAd == 2) {
                exit;
            }

        here12:    //a call from root

            system("cls");
            bar.disbar();
           // cout << "\n\n" << endl;
            //system("pause");
            system("cls");
            try {
                int resultAd = 0;
                while (resultAd == 0 or resultAd==1) {
                    resultAd = person.AdminMainMenu();
                    if (resultAd == 1) {
                        cout << "Program will be terminted and restart......" << endl;
                        system("pause");
                        goto here12;
                    }
                    else if (resultAd == 2) {
                        cout << "\033[33m";
                        system("cls");
                        goto start;
                    }

                    else if (resultAd == 5) {
                        goto here11;
                        
                    }
                    else {
                        //goto here12;
                    }

                }
            }
            catch (...) {
                cout << "Try Again" << endl;
                system("pause");
                system("cls");
                person.AdminMainMenu();
            }
        }

    //=========================================root====================================================
        else if ((loginName == "root") and (loginPassword == hashedPassword))
        {
            system("cls");
            bar.disbar();
            system("cls");
            int resultroot = person.RootMainMenu();
            if (resultroot == 11) {
                goto here11;
            }
            else if (resultroot == 12) {
                goto here12;
            }
            system("cls");
            cout << "System is out of Root Level\n" << endl;
            system("pause");
            system("cls");
            exit;
        }

        else if (loginAttempt >= 5) //To overcome brutalforce attacks
        {
            system("cls");
            cout << "Too many login attempts! The program will now terminate." <<endl;
            system("pause");
            return 0;
        }

        else if(loginName != "root" and loginName != "1" and loginName != "2")
        {
            system("cls");
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            system("pause");
            system("cls");
            loginAttempt++;
        }

        else {
            system("cls");
        }



    }
}




