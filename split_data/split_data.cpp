//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int const max_c_string_length = 100;
int const max_c_string_length_with_default_fields = 111;
int const max_struct_size = 1000;

struct S{

    int c1;

    double c2;

};

int main() {

    S T[max_struct_size];

    char filename[max_c_string_length];

    int general_counter = 0;

    ifstream read;

    ofstream write;

    cout << "Gentile utente, inserisci il nome del file (terminato da a capo)" << endl;
    cout << "Suggerimento! prova ad inserire: pairs.txt" << endl;
    cout << "Inserisci:" << endl;
    cin.getline(filename,max_c_string_length + 1,'\n');

    read.open(filename);

    for(int i = 0; i < max_c_string_length; i++) { // print separator loop

        cout << '/';

        if(i == max_c_string_length - 1) cout << endl;

    }

    if(read.fail()) {

        cout << "--- \"Impossibile aprire il file!\" ---" << endl;

        return cout.fail(); // return the boolean value of failbit field. It is a clear alternative to return -1;

    } else {

        cout << "+++ \"File aperto con successo!\" +++" << endl;

    }
    read.close();

    for(int i = 0; i < max_c_string_length; i++) { // print separator loop

        cout << '/';

        if(i == max_c_string_length - 1) cout << endl;

    }

    read.open(filename);

    read >> T[general_counter].c1 >> T[general_counter].c2;
    while(!read.eof()) { // check incompatible data types on file

        general_counter++;

        if(!(read >> T[general_counter].c1 >> T[general_counter].c2) && !read.eof()) {

            cout << "--- \"Rilevati uno o piu' tipi di dato incompatibili con il file!\" ---" << endl;

            return cout.fail();

        }

    }
    read.close();

    cout << "Il controllo del tipo di dato presente nel file di input " << filename << " ha dato il seguente esito:" << endl;

    general_counter = 0;

    read.open(filename);

    read >> T[general_counter].c1 >> T[general_counter].c2;
    cout << "( " << T[general_counter].c1 << ',' << T[general_counter].c2 << " ) ";
    while(!read.eof()) { // EOF test

        general_counter++;

        read >> T[general_counter].c1 >> T[general_counter].c2;

        if(!read.eof()) {

            cout << "( " << T[general_counter].c1 << ',' << T[general_counter].c2 << " ) ";

        } else cout << endl;

    }
    read.close();

    for(int i = 0; i < max_c_string_length; i++) { // print separator loop

        cout << '/';

        if(i == max_c_string_length - 1) cout << endl;

    }
    
    // handle writing on file
    char file_output_1[max_c_string_length_with_default_fields] = "campi1_di_";
    strcat(file_output_1,filename);

    write.open(file_output_1);
    for(int i = 0; i < general_counter; i++) { // write c1 field on output file

        write << T[i].c1 << endl;

    }
    cout << "Il file " << file_output_1 << " e' stato creato e scritto con successo!" << endl;
    write.close();

    char file_output_2[max_c_string_length_with_default_fields] = "campi2_di_";
    strcat(file_output_2,filename);

    write.open(file_output_2);
    for(int i = 0; i < general_counter; i++) { // write c2 field on output file

        write << T[i].c2 << endl;

    }
    write.close();
    cout << "Il file " << file_output_2 << " e' stato creato e scritto con successo!" << endl;

    cout << "*** Programma terminato ***";

    return 0;
    
}
