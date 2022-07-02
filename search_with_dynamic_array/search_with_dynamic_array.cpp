//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>
#include <fstream>

using namespace std;

int const max_c_string_length = 64;

double max_search(double* &F, int k) {

    double the_max_is = F[0];

    for(int i = 0; i < k; i++) {

        if(F[i] > the_max_is) {

            the_max_is = F[i];

        }

    }

    return the_max_is;

}

int double_arr_capacity(double* &E, int n) {

    double* temp = new double[n*2];

    for(int i = 0; i < n; i++) {

        temp[i] = E[i];

    }

    delete[] E;

    E = temp;

    return n * 2;

}

int main() {

    int starter_arr_dim = 4;

    double* D = new double[starter_arr_dim];

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

    int h = 0;

    read.open(filename);
    read >> D[h];
    while(!read.eof()) { // check incompatible data types on file

        h++;

        if(!(read >> D[h]) && !read.eof()) {

            cout << "--- \"Rilevati uno o piu' tipi di dato incompatibili con il file!\" ---" << endl;

            return cout.fail();

        }

        if(h == starter_arr_dim - 1) starter_arr_dim = double_arr_capacity(D,starter_arr_dim);

    }
    read.close();

    starter_arr_dim -= h; // overwrite array capacity (vital to find the max value)

    /*for(int i = 0; i < h; i++) { // print loop

        cout << ((double)D[i]) << ' '; // weird pointer dereferencing with Clion

        if(i == h - 1) cout << endl;

    }*/

    double winner = max_search(D,starter_arr_dim);
    cout << "L'elemento massimo della sequenza e': " << winner << endl;

    for(int i = 0; i < max_c_string_length; i++) { // print separator loop

        cout << '/';

        if(i == max_c_string_length - 1) cout << endl;

    }

    cout << "*** Programma terminato ***" << endl;

    return 0;

}
