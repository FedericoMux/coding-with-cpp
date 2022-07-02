//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int const max_c_string_length = 50;

int main() {

    char filename[max_c_string_length], filename_for_pos[max_c_string_length], filename_for_neg[max_c_string_length];

    int input_value, zeroes_counter = 0;

    ifstream read;

    ofstream write_logs, write_pos, write_neg;

    cout << "Gentile utente, inserisci il nome del file (terminato da a capo)" << endl;
    cout << "Suggerimento! l'estensione del file viene aggiunta in automatico dal programma!" << endl;
    cout << "Suggerimento! prova ad inserire: data" << endl;
    cout << "Inserisci:" << endl;

    cin.getline(filename,max_c_string_length + 1,'\n');

    for(int i = 0; i < max_c_string_length; i++) { // print separator loop

        cout << '/';

        if(i == max_c_string_length - 1) cout << endl;

    }

    strcpy(filename_for_pos,filename);
    strcpy(filename_for_neg,filename);
    strcat(filename,".txt");

    read.open(filename); // bind ifstream

    if(read.fail()) { // stream test

        cerr << "--- \"Il file " << filename << " non esiste! ---\" " << endl;

        write_logs.open("user-logs.txt", ios::app); // append mode to avoid file overwriting

        char A[] = "--- \"Il file non esiste!\" ---";

        for(int i = 0; i < strlen(A); i++) {

            char c = A[i];

            write_logs.put(c);

        }

        return -1; // required from exercise

    } else {

        cerr << "+++ \"Apertura del file " << filename << " corretta\" +++" << endl;

        write_logs.open("user-logs.txt", ios::app); // append mode to avoid file overwriting

        char A[] = "+++ \"Apertura del file corretta\" +++";

        for(int i = 0; i < strlen(A); i++) {

            char c = A[i];

            write_logs.put(c);

        }

    }

    write_logs.close(); // unbind ofstream

    strcat(filename_for_pos,"_pos.txt");
    strcat(filename_for_neg,"_neg.txt");

    write_pos.open(filename_for_pos); // bind ofstream
    write_neg.open(filename_for_neg); // bind ofstream

    read >> input_value;
    do {

        // cout << "integer " << input_value << endl; // debug

        if(input_value > 0) {

            write_pos << input_value << ' ';

        } else if(input_value < 0) {

            write_neg << input_value << ' ';

        } else {

            zeroes_counter += 1;

            // cout << "zeroes counter " << zeroes_counter << endl; // debug

        }

    } while(read >> input_value); // is better test EOF in this manner because it is false if it fails to read EOF

    read.close(); // unbind ifstream
    write_pos.close(); // unbind ofstream
    write_neg.close(); // unbind ofstream

    cout << "Statistiche:" << endl;

    read.open(filename_for_pos); // bind ifstream
    cout << filename_for_pos << ": ";
    do {

        read >> input_value;

        if(read.eof()) {

            cout << endl;
            break;

        }

        cout << input_value << ' ';

    } while(true);
    read.close(); // unbind ifstream

    read.open(filename_for_neg); // bind ifstream
    cout << filename_for_neg << ": ";
    do {

        read >> input_value;

        if(read.eof()) {

            cout << endl;
            break;

        }

        cout << input_value << ' ';

    } while(true);
    read.close(); // unbind ifstream

    cout << "Eliminati dal file iniziale " << filename << ' ' << zeroes_counter << " zeri" << endl;

    cout << "*** Programma terminato ***" << endl;

    return 0;

}
