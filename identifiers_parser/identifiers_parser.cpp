//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>

using namespace std;

int const max_c_string_length = 100;
int const ascii_jumping_pattern = 32;

bool id_remainder(char R[], int start_index) { // parser logic

    if(R[start_index + 1] == '\0') { // base case

        return true;

    } else {

        if( // recursive case
            (R[start_index + 1] > 96 && R[start_index + 1] < 123) || // handle lowercase
            (R[start_index + 1] > 96 - ascii_jumping_pattern && R[start_index + 1] < 123 - ascii_jumping_pattern) || // handle uppercase
            R[start_index + 1] == 95 || // underscore char
            (R[start_index + 1] > 47 && R[start_index + 1] < 58) // integers from 0 to 9
        ) {

            start_index += 1;

            return id_remainder(R, start_index);

        } else {

            return false;

        }

    }

}

bool id(char S[]) { // parser logic

    if(
        (S[0] > 96 && S[0] < 123) || // handle lowercase
        (S[0] > 96 - ascii_jumping_pattern && S[0] < 123 - ascii_jumping_pattern) || // handle uppercase
        S[0] == 95 // underscore char
    ) {

        return id_remainder(S,0);

    } else {

        return false;

    }

}

int main() {

    char input_identifier[max_c_string_length], token, step_char;

    bool response;

    do {

        int index = 0;

        cout << "Gentile utente, inserisci una stringa terminata da a capo (max " << max_c_string_length << " caratteri):" << endl;

        do {

            cin.get(step_char);

            if(index > max_c_string_length) {

                cout << "La lunghezza della stringa inserita supera il valore massimo consentito di " << max_c_string_length << "!" << endl;

                cin.ignore(256, '\n'); // without this, in this statement branch \n character remains on std input stream

                break;

            }

            if(step_char == '\n') {

                input_identifier[index] = '\0';

                break;
            }

            else {

                input_identifier[index] = step_char;

                index++;

            }

        } while(true);

        response = id(input_identifier);

        if(!response){

            cout << "Errore!" << endl;

        } else {

            cout << "*** Identificatore corretto ***" << endl;

        }

        cout << "Gentile utente, vuoi ripetere il test da capo? (s per si', n per no): ";
        cin >> token;

        cin.ignore(256, '\n'); // fundamental to prevent cin.get() eager behaviour

    } while(token == 's');

    cout << "*** Programma terminato ***" << endl;

    return 0;

}
