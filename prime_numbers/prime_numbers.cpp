//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>

using namespace std;

int main() {

    char token;

    int sup;

    cout << "*** Benvenuto nel programma che determina e stampa tutti i numeri primi nell'intervallo tra 1 ed n ***" << endl;

    do {

        cout << "Gentile utente, immetti un numero n: ";
        cin >> sup; // upper bound

        if(sup < 0) {

            cout << "Non sono ammessi valori interi negativi!" << endl;

        } else if(sup == 0 || sup == 1) {

            cout << "Non ci sono numeri primi in questo range!" << endl;

        } else {

            cout << "I numeri primi tra 1 e " << sup << " sono:" << endl;

            for(int number = 1; number <= sup; number++) { // primality test

                int general_counter = 0;

                for(int divisor = 1; divisor <= sup; divisor++) {

                    if(number % divisor == 0){

                        general_counter++;

                    }

                }

                if(general_counter == 2) { // if number of remainders equal to zero is 2 then the number is prime

                    cout << number << endl;

                }

            }

        }

        cout << "Gentile utente, vuoi ripetere il test da capo? (s per si', n per no): ";
        cin >> token;

    } while(token == 's');

    cout << "*** Programma terminato ***";

    return 0;

}

