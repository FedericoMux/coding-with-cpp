//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>

using namespace std;

int const max_arr_dim = 1000;

int main() {

    char token;

    int set_dim_A, set_dim_B, counter_intersections;

    cout << "*** Benvenuto nel programma di calcolo dell'intersezione insiemistica ***" << endl;

    // assumption: I adopted set logic and NOT multi-set logic
    do {

        bool same_num = false;

        cout << "Gentile utente, dammi il numero di elementi del PRIMO insieme: ";
        cin >> set_dim_A;

        while(!cin || set_dim_A < 0) {

            if(set_dim_A < 0) {

                cout << ">>>>>Errore: la dimensione dell'insieme NON puo' essere negativa!" << endl;

            }

            if(!cin) {

                cout << ">>>>>Errore: il tipo di dato inserito non e' corretto!" << endl;

                cin.clear();
                cin.ignore(256,'\n');

            }

            cout << "Gentile utente, dammi il numero di elementi del PRIMO insieme: ";
            cin >> set_dim_A;

        }

        int set_A[set_dim_A];

        for(int i = 0; i < set_dim_A; i++) {

            int supporter;

            cout << "Dammi il \"" << i << "-esimo\" numero del PRIMO insieme: ";
            cin >> supporter;

            for(int j = 0; j < set_dim_A; j++) { // check repeated items

                if(set_A[j] == supporter) {

                    same_num = true;

                    break;

                }

            }

            if(!same_num && supporter >= 0) {

                set_A[i] = supporter;

            }

            while(!cin || supporter < 0 || same_num) {

                if(supporter < 0) {

                    cout << ">>>>>Errore: sono ammessi solo numeri interi positivi (n >= 0)!" << endl;

                    i--;

                    break;

                }

                if(!cin) {

                    cout << ">>>>>Errore: il tipo di dato inserito non e' corretto!" << endl;

                    cin.clear();
                    cin.ignore(256,'\n');

                    i--;

                }

                if(same_num) {

                    cout << ">>>>>Errore: hai gia' inserito un numero uguale nell'insieme (e' un insieme, non un multi-insieme)!" << endl;

                    same_num = false;

                    i--;

                }

            }

        }

        cout << "Gentile utente, dammi il numero di elementi del SECONDO insieme: ";
        cin >> set_dim_B;

        while(!cin || set_dim_B < 0) {

            if(set_dim_B < 0) {

                cout << ">>>>>Errore: la dimensione dell'insieme NON puo' essere negativa!" << endl;

            }

            if(!cin) {

                cout << ">>>>>Errore: il tipo di dato inserito non e' corretto!" << endl;

                cin.clear();
                cin.ignore(256,'\n');

            }

            cout << "Gentile utente, dammi il numero di elementi del SECONDO insieme: ";
            cin >> set_dim_B;

        }

        int set_B[set_dim_B];

        for(int i = 0; i < set_dim_B; i++) {

            int contributor;

            cout << "Dammi il \"" << i << "-esimo\" numero del SECONDO insieme: ";
            cin >> contributor;

            for(int j = 0; j < set_dim_B; j++) { // check repeated items

                if(set_B[j] == contributor) {

                    same_num = true;

                    break;

                }

            }

            if(!same_num && contributor >= 0) {

                set_B[i] = contributor;

            }

            while(!cin || contributor < 0 || same_num) {

                if(contributor < 0) {

                    cout << ">>>>>Errore: sono ammessi solo numeri interi positivi (n >= 0)!" << endl;

                    i--;

                    break;

                }

                if(!cin) {

                    cout << ">>>>>Errore: il tipo di dato inserito non e' corretto!" << endl;

                    cin.clear();
                    cin.ignore(256,'\n');

                    i--;

                }

                if(same_num) {

                    cout << ">>>>>Errore: hai gia' inserito un numero uguale nell'insieme (e' un insieme, non un multi-insieme)!" << endl;

                    same_num = false;

                    i--;

                }

            }

        }

        int set_C[max_arr_dim];
        counter_intersections = 0;

        for(int i = 0; i < set_dim_A; i++) {

            for(int j = 0; j < set_dim_B; j++) {

                if(set_A[i] == set_B[j]) {

                    set_C[counter_intersections] = set_A[i];

                    counter_intersections++;

                }

            }

        }

        if(counter_intersections == 0) {

            cout << "L'intersezione insiemistica tra i due insiemi e' vuota" << endl;

        } else {

            cout << "L'intersezione insiemistica tra i due insiemi e': ";

            for(int k = 0; k < counter_intersections; k++) {

                cout.width(5);
                cout << set_C[k];

            }

           cout << endl;

        }

        cout << "Gentile utente, vuoi ripetere il test da capo? (s per si', n per no): ";
        cin >> token;

    } while(token == 's');

    cout << "*** Programma terminato ***";

    return 0;

}