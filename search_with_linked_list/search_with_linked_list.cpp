//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>
#include <fstream>

using namespace std;

int const max_c_string_length = 64;

struct elem {

    double info;

    elem* punt;

};

void add_in_linked_list(elem* &l, double y) { // add from the head of the linked list

    elem* t = new elem; // new operator allocates memory and returns the address memory

    t->info = y; // initialization
    t->punt = l; // initialization

    l = t; // assignment between pointers

    t = NULL; // set NULL

}

double max_search(elem* &l) {

    double the_max_is = l->info;

    while(l != NULL) {

        if(l->info > the_max_is) {

            the_max_is = l->info;

        }

        l = l->punt;

    }

    return the_max_is;

}

int main() {

    elem* L = NULL;

    ifstream read;

    char filename[max_c_string_length];

    do {

        cout << "Gentile utente, inserisci il nome del file (terminato da a capo)" << endl;
        cout << "Suggerimento! prova ad inserire: Real-scale.txt" << endl;
        cout << "Inserisci:" << endl;

        cin.getline(filename,max_c_string_length + 1,'\n');

        read.open(filename);

        for(int i = 0; i < max_c_string_length; i++) { // print separator loop

            cout << '/';

            if(i == max_c_string_length - 1) cout << endl;

        }

        if(read.fail()) {

            cout << "--- \"Impossibile aprire il file!\" ---" << endl;

        } else {

            cout << "+++ \"File aperto correttamente!\" +++" << endl;

        }

    } while(read.fail());
    read.close();

    for(int i = 0; i < max_c_string_length; i++) { // print separator loop

        cout << '/';

        if(i == max_c_string_length - 1) cout << endl;

    }

    read.open(filename);

    double x;
    read >> x;
    while(!read.eof()) { // check incompatible data types on file

        if(!(read >> x) && !read.eof()) {

            cout << "--- \"Rilevati uno o piu' tipi di dato incompatibili con il file!\" ---" << endl;

            return cout.fail();

        }

        add_in_linked_list(L,x);

    }
    read.close();

    double winner = max_search(L);
    cout << "L'elemento massimo della sequenza e': " << winner << endl;

    for(int i = 0; i < max_c_string_length; i++) { // print separator loop

        cout << '/';

        if(i == max_c_string_length - 1) cout << endl;

    }

    cout << "*** Programma terminato ***" << endl;

    return 0;

}


