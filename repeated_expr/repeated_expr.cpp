//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>
#include <cmath>

using namespace std;

int const ascii_jumping_pattern = 32;

int main() {

    char op, token;

    int num_1, num_2, result;

    do {

        bool check_op = true, check_num_1 = true, check_num_2 = true;

        cout << "Gentile utente, dai un'espressione intera semplice (della forma num op num): ";

        if(!(cin >> num_1) || ceil(num_1) != num_1) { // stream test cin + ceil() because only integers are allowed

            check_num_1 = false;

            cout << "Espressione NON valida" << endl;

            cin.clear();
            cin.ignore(256,'\n');

        } else {

            cin >> op; // cin instead of get()
            if(op != '+' && op != '-' && op != '*' && op != '/' && op != ':') {

                check_op = false;

                cout << "Espressione NON valida!" << endl;

                cin.clear();
                cin.ignore(256,'\n');

            } else {

                if(!(cin >> num_2) || ceil(num_2) != num_2) { // stream test cin + ceil() because only integers are allowed

                    check_num_2 = false;

                    cout << "Espressione NON valida!" << endl;

                    cin.clear();
                    cin.ignore(256,'\n');

                }

            }

        }

        if(check_num_1 && check_op && check_num_2) { // check as a compiler

            switch(op) {

                case '+': {

                    result = num_1 + num_2;

                    cout << "Il risultato e': " << result << endl;

                    break;

                }

                case '-': {

                    result = num_1 - num_2;

                    cout << "Il risultato e': " << result << endl;

                    break;

                }

                case '*': {

                    result = num_1 * num_2;

                    cout << "Il risultato e': " << result << endl;

                    break;

                }

                case '/': case ':': {

                    if(num_2 == 0) {

                        cout << "Il divisore NON puo' essere zero!" << endl;

                    } else {

                        result = num_1 / num_2;

                        // int result_con_cast = (int) result; // force explicit cast to int if num_1 and num_2 are double

                        cout << "Il risultato e': " << result << endl;

                    }

                    break;
                }

                default: cout << "Operatore NON valido!" << endl;

            }
        }

        do { // check terminator character with case in-sensitive logic

            cout << "Gentile utente, vuoi ripetere il test da capo? (s per si', n per no): ";
            cin >> token;

            if(token != 's' && token != 'n' && token != 's' - ascii_jumping_pattern && token != 'n' - ascii_jumping_pattern) {
                cout << "Carattere NON ammesso!" << endl;
            }

        } while(token != 's' && token != 'n' && token != 's' - ascii_jumping_pattern && token != 'n' - ascii_jumping_pattern);

    } while(token == 's' || token == 's' - ascii_jumping_pattern);

    cout << "*** Programma terminato ***";

    return 0;

}