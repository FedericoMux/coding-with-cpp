//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>

using namespace std;

void write(bool enabled, int user_choice, int formal_input_params, int result) {

    if(enabled) {

        switch(user_choice) {

            case 2: {

                cout << "*** Il quadrato di " << formal_input_params << " e' " << result << " ***" << endl;
                break;

            }
            
            case 3: {

                cout << "*** La sommatoria dei numeri compresi tra 1 e " << formal_input_params << " e' " << result << " ***" << endl;
                break;

            }
            
            case 4: {

                cout << "*** Il fattoriale di " << formal_input_params << " e' " << result << " ***" << endl;
                break;

            }
            
            default: {

                cout << "Ops, la scelta inserita NON e' valida!" << endl;

            }

        }

    } else {

        cout << "Prima di fare un'operazione devi dare un numero!" << endl;

    }

}

int read() {
    
    int formal_input_params;

    cout << "Gentile utente, inserire un numero intero: ";
    cin >> formal_input_params;

    return formal_input_params;
    
}

int square(int formal_input_params) {

    // alternative
    // int res = formal_input_params * formal_input_params;
    // return res

    return formal_input_params * formal_input_params;
    
}

int summation(int formal_input_params) {

    int res = formal_input_params * (formal_input_params + 1) / 2; // Gauss formula for the sum of positive integers from 1 to n

    return res;

}

int factorial(int formal_input_params) { // recursive implementation

    if(formal_input_params == 0) { // base case

        return 1;

    } else { // recursive case

        return factorial(formal_input_params - 1) * formal_input_params;

    }

}

void menu_operations() {

    int user_choice, current_input_params, result;

    bool enabled = false; // remember user selected operation

    do {

        cout << "Gentile utente, scegli una delle operazioni seguenti:" << endl;

        for(int i = 1; i <= 5; i++) {

            cout.width(52);

            if(i == 1) {

                cout << "1. Leggi e memorizza" << endl;

            } else if(i == 2) {

                cout << "2. Quadrato" << endl;

            } else if(i == 3) {

                cout << "3. Sommatoria" << endl;

            } else if(i == 4) {

                cout << "4. Fattoriale" << endl;

            } else if(i == 5) {

                cout << "5. Esci" << endl;

            }

        }

        cout << "Operazione scelta? ";
        cin >> user_choice;

        if(user_choice == 5) {

            cout << "*** Programma terminato ***" << endl;

            break;

        } else if(user_choice != 1 && user_choice != 2 && user_choice != 3 && user_choice != 4) {

            cout << "Ops, la scelta inserita NON e' valida!" << endl;

        } else {

            switch(user_choice) {

                case 1: {

                    current_input_params = read();
                    enabled = true;

                    break;

                }

                case 2: {

                    result = square(current_input_params);
                    write(enabled, user_choice,current_input_params, result);

                    break;

                }

                case 3: {

                    if(current_input_params < 0) {

                        cout << "La sommatoria di un numero negativo e' un'operazione NON consentita" << endl;

                    } else {

                        result = summation(current_input_params);
                        write(enabled, user_choice,current_input_params, result);

                    }

                    break;

                }

                case 4: {

                    if(current_input_params < 0) {

                        cout << "Il fattoriale di un numero negativo e' un'operazione NON consentita" << endl;

                    } else {

                        result = factorial(current_input_params);
                        write(enabled, user_choice,current_input_params, result);

                    }

                    break;

                }

                default: {

                    cout << "Ops, la scelta inserita NON e' valida!" << endl;

                }

            }

        }

    } while(true);

}

int main() {

    menu_operations();

    return 0;

}
