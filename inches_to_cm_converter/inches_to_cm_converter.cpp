//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>

using namespace std;

const float magic_number = 2.54;

int main() {

    char token;

    int user_choice;

    float user_input;

    cout << "*** Benvenuto nel programma di conversione pollici <---> cm ***" << endl;

    do {

        cout << "Le scelte disponibili per la conversione sono:" << endl;
        cout << "1. per la conversione pollici ---> cm" << endl;
        cout << "2. per la conversione cm ---> pollici" << endl;
        cout << "Gentile utente, digitare la scelta: ";
        cin >> user_choice;

        if(user_choice == 1) {

            cout << "Gentile utente, fornire il numero in pollici: ";
            cin >> user_input;
            cout << user_input << " pollici equivalgono a " << user_input * magic_number << " cm" << endl;

        } else if(user_choice == 2) {

            cout << "Gentile utente, fornire il numero in cm: ";
            cin >> user_input;
            cout << user_input << " cm equivalgono a " << user_input / magic_number << " pollici" << endl;

        } else {

            cout << "Scelta NON valida!" << endl;

        }

        cout << "Gentile utente, vuoi ripetere il test da capo? (s per si', n per no): ";
        cin >> token;

    } while(token == 's');

    cout << "*** Programma terminato ***";

    return 0;

}
