//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>

using namespace std;

int const max_arr_dim = 1000;

int main() {

    int x, pivot = 0, allocations_counter = 0;

    int* A[max_arr_dim];

    for(int i = 0; i < max_arr_dim; i++) {

        cout << "Gentile utente, inserisci un numero intero (negativo per smettere): ";
        cin >> x;

        if(i == 0 && x < 0) { // super bad case

            cout << "Hai inserito subito un numero negativo!" << endl;
            cout << "Allocate: " << allocations_counter << " variabili" << endl;
            cout << "Sequenza finale vuota" << endl;

            return -1;

        } else if(i == 0) { // allocate a dynamic variable with new operator first

            A[0] = new int(x);

            allocations_counter++;
            pivot++;

        } else if(x < 0) { // handle x < 0

            break;

        }
        else if(i == max_arr_dim - 1) { // handle max dimension

            cout << "Dimensione massima raggiunta!" << endl;

            return 0;

        } else {

            for(int j = 0; j < pivot; j++) {

                if(x == *A[j]) { // values are identical

                    int* temp = A[j];

                    A[pivot] = temp;

                    pivot++;

                    break;

                } else if(j == pivot - 1) { // if I didn't find identical values before, now I allocate a new dynamic variable

                    A[pivot] = new int(x);

                    pivot++;

                    allocations_counter++;

                    break;

                }
            }
        }
    }

    // for(int h = 0; h < pivot; h++) cout << A[h] << ' '; // debug memory addresses

    cout << "Allocate: " << allocations_counter << " variabili" << endl;
    cout << "Sequenza:" << endl;

    for(int k = 0; k < pivot; k++) {

        cout << *A[k] << ' ';

        if(k == pivot - 1) cout << endl;

    }

    cout << "*** Programma terminato ***" << endl;

    return 0;

}
