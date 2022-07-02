//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>

using namespace std;

int main() {

    char token;

    do {

        int current_year;
        cout << "Gentile utente, inserisci l'anno corrente?" << ' ';
        cin >> current_year;

        int current_age;
        cout << "Gentile utente, inserisci la tua eta':" << ' ';
        cin >> current_age;

        int time_travel;
        cout << "Gentile utente, inserisci l'anno per calcolare l'eta':" << ' ';
        cin >> time_travel;

        int my_age;
        int date_of_birth  = current_year - current_age;

        if(time_travel > current_year) { // jump ahead in time

            my_age = (time_travel - current_year) + current_age;

            cout << "La tua eta' nel" << ' ' << time_travel << ' ' << "sara' di" << ' ' << my_age << ' ' << (my_age == 1 ? "anno" : "anni") << endl;

        } else if(time_travel == current_year) { // do not jump

            cout << "La tua eta' quest'anno e' di" << ' ' << current_age << ' ' << (current_age == 1 ? "anno" : "anni") << endl;

        } else if(time_travel < current_year && time_travel >= date_of_birth) { // jump back in time

            my_age = current_age - (current_year - time_travel);

            cout << "La tua eta' nel" << ' ' << time_travel <<  ' ' << "era di" << ' ' << my_age << ' ' << (my_age == 1 ? "anno" : "anni") << endl;

        } else {

            cout << "Nel" << ' ' << time_travel << ' ' << "non eri ancora nato" << endl;

        }

        cout << "Gentile utente, vuoi ripetere il test da capo? (s per si', n per no):" << ' ';
        cin >> token;

    } while(token == 's');

    cout << "*** Programma terminato ***";

    return 0;

}
