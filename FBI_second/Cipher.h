#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

//Caeser cipher

class Cipher {

private:
    string message;
    int key = 1;  // just one letter shift this can be done as prefered
public:
    void ceaser()
    {
        cout << "\033[34m";
        cout << "              Welcome to the Cipher X Messenger" << endl;
        cout << "\033[33m";
        cout << "\n=================================================================" << endl;
        cout << "\033[37m";
        cout << "Enter the messege :\n" << endl;cout << "\033[32m";cin.ignore();
        getline(cin ,message); 
        cout << endl;
  
        for (int i = 0; i < message.length(); i++)

        {
            if (isalpha(message[i]))
            {
                if (isupper(message[i]))
                {
                    char c = message[i]; cout << "\033[31m";
                    cout << (char)((c - 'A' + key) % 26 + 'A');
                }

                if (islower(message[i]))
                {
                    char c = message[i]; cout << "\033[31m";
                    cout << char((c - 'a' + key) % 26 + 'a');
                }
            }

            else
            {
                cout << "\033[31m";
                cout << message[i];
                cout << "\033[31m";
            }

        }

        cout << "\n\n";
    
        cout << "\033[33m";
      cout << "=================================================================\n\n" << endl;
    
    }


};