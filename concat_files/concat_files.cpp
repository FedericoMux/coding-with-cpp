//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int const max_c_string_length = 50;
int const max_extension_string_length = 4;

int main() {

    char single_character;

    char filename_1[max_c_string_length], filename_2[max_c_string_length], composite_result_filename[max_c_string_length * 2 + 1];

    ifstream read;

    ofstream write;

    do {

        cout << "Gentile utente, inserisci il nome del PRIMO file di input (max " << max_c_string_length << " char)" << endl;
        cout << "Suggerimento! prova ad inserire: a.txt" << endl;
        cout << "Inserisci:" << endl;
        cin.getline(filename_1,max_c_string_length + 1,'\n');

        read.open(filename_1);

        if(!read.fail()) {

            cout << "+++ \"File aperto correttamente!\" +++" << endl;

            read.close();

            break;

        } else {

            cout << "--- \"Impossibile aprire il PRIMO file!\" ---" << endl;

        }

    } while(true);

    for(int i = 0; i < max_c_string_length; i++) { // print separator loop

        cout << '/';

        if(i == max_c_string_length - 1) cout << endl;

    }

    do {

        cout << "Gentile utente, inserisci il nome del SECONDO file di input (max " << max_c_string_length << " char)" << endl;
        cout << "Suggerimento! prova ad inserire: b.txt" << endl;
        cout << "Inserisci:" << endl;
        cin.getline(filename_2,max_c_string_length + 1,'\n');

        read.open(filename_2);

        if(!read.fail()) {

            cout << "+++ \"File aperto correttamente!\" +++" << endl;

            read.close();

            break;

        } else {

            cout << "--- \"Impossibile aprire il SECONDO file!\" ---" << endl;

        }

    } while(true);

    for(int i = 0; i < max_c_string_length; i++) { // print separator loop

        cout << '/';

        if(i == max_c_string_length - 1) cout << endl;

    }

    for(int i = 0; i < strlen(filename_1) - max_extension_string_length; i++) {

        composite_result_filename[i] = filename_1[i];

    }

    strcat(composite_result_filename,"_"); // concat with underscore
    strcat(composite_result_filename,filename_2); // concat with second filename

    write.open(composite_result_filename);

    // copy first file content to composite result file
    read.open(filename_1);
    single_character = read.get();
    while(single_character != EOF) {

        write.put(single_character);

        single_character = read.get();

    }
    read.close();

    // copy second file content to composite result file
    read.open(filename_2);
    single_character = read.get();
    while(single_character != EOF) {

        write.put(single_character);

        single_character = read.get();

    }
    write.close();
    read.close();

    // ending prints
    cout << "L'operazione di copia tra file ha prodotto il seguente risultato:" << endl;

    cout << "File di input" << ' ' << filename_1 << ':' << endl;
    read.open(filename_1);
    do { // print first file content

        // read >> single_character;
        read.get(single_character);

        if(read.eof()) {

            // cout << "EOF" << endl; // debug
            cout << endl;
            break;

        }

        cout << single_character;

    } while(true);
    read.close();

    read.open(filename_2);
    cout << "File di input" << ' ' << filename_2 << ':' << endl;
    do { // print second file content

        // read >> single_character;
        read.get(single_character);

        if(read.eof()) {

            // cout << "EOF" << endl; // debug
            cout << endl;
            break;

        }

        cout << single_character;

    } while(true);
    read.close();

    read.open(composite_result_filename);
    cout << "File di output" << ' ' << composite_result_filename << ':' << endl;
    do { // print composite result file content
        
        // read >> single_character;
        read.get(single_character);

        if(read.eof()) {

            // cout << "EOF" << endl; // debug
            cout << endl;
            break;
            
        }
        
        cout << single_character;
        
    } while(true);
    read.close();

    for(int i = 0; i < max_c_string_length; i++) { // print separator loop

        cout << '/';

        if(i == max_c_string_length - 1) cout << endl;

    }

    cout << "*** Programma terminato ***" << endl;

    return 0;

}
