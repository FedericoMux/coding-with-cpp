//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>
#include <cstring>

using namespace std;

int const max_c_string_length = 1000;
int const negative_ack = -1;

int search(char A[], int j, char Del[]) {

    for(int i = j - 1; i <= strlen(A); i++) {

        // cout << "Value: " << A[i] << endl; // debug

        for(int k = 0; k < strlen(Del); k++) {

            if(A[i] == Del[k]) {

                return i + 1;

            }

        }

    }

    return negative_ack;

}

int main() {

    char input_text[max_c_string_length];

    char token[] = {'s','n'}, special_chars[] = {'.',',',';',':','!','?','\0'};

    do {

        do { // check text length

            cout << "Gentile utente, inserisci un testo (frase, motto, poesia, etc.) terminato da a capo:" << endl;
            cin.getline(input_text,max_c_string_length,'\n');

            if(strlen(input_text) < max_c_string_length) {

                break;

            } else {

                cout << "Il testo inserito supera i " << max_c_string_length << " caratteri!" << endl;

            }

        } while(true);

        int pivot = 0;
    
        do { // stream test and check integer > 0
        
            cout << "Gentile utente, inserisci la posizione nel testo da cui iniziare la ricerca (>= 1): ";
            cin >> pivot;

            if(cin && pivot >= 1) {

                break;

            } else if(!cin) {

                cout << "Il tipo di dato inserito NON e' corretto!" << endl;

                cin.clear();
                cin.ignore(256,'\n');

            } else {

                cout << "L'intero che esprime la posizione da cui iniziare la ricerca non puo' essere < 0" << endl;

            }

        } while(true);
    
        int spotted_position = search(input_text,pivot,special_chars);
    
        if(spotted_position != negative_ack) {

            cout << "*** Trovato carattere speciale in posizione " << spotted_position << " ***"<< endl;

        } else {

            cout << "Nel testo che hai inserito NON ho trovato alcun carattere speciale!" << endl;

        }

        cin.ignore(256,'\n');

        cout << "Gentile utente, vuoi ripetere il test da capo? (s per si', n per no): ";
        cin.getline(token,2,'\n');

    } while(token[0] == 's');
    
    cout << "*** Programma terminato ***";

    return 0;

}