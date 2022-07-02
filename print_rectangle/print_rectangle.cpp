//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>

using namespace std;

int main() {

    char token, texture;

    int rows, cols;

    do {

        do {

            cout << "Gentile utente, inserisci quante righe vuoi (>=2): ";
            cin >> rows;

        } while(rows < 2);

        do {

            cout << "Gentile utente, inserisci quante colonne vuoi (>=2): ";
            cin >> cols;

            if(cols == rows) cout << "La figura da disegnare deve essere un rettangolo e NON un quadrato!" << endl;

        } while(cols < 2 || cols == rows);

        cout << "Gentile utente, inserisci il carattere che riempira' il rettangolo (prova con .): ";
        cin >> texture;

        for(int i = 1; i <= rows; i++) {

            if(i == 1 || i == rows) {

                for(int j = 1; j <= cols; j++) {

                    cout << '*';

                }

            } else {

                for(int k = 1; k <= cols; k++) {

                    if(k == 1 || k == cols) {

                        cout << '*';

                    } else {

                        cout << texture;

                    }

                }

            }

        cout << endl;

        }

        cout << "Gentile utente, vuoi ripetere il test da capo? (s per si', n per no): ";
        cin >> token;

    } while(token == 's');

    cout << "*** Programma terminato ***";

    return 0;

}