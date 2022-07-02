//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>
#include <cstring>

using namespace std;

int const max_struct_size = 100;
int const max_c_string_length = 50;
int const max_person_age = 150;

struct people_data {

    char name[max_c_string_length];

    int age;

    // bool age_check; // alternative to check age

};

int main() {

    char terminator_character[] = "stop";

    int people_data_table_row_index = 0;

    people_data people_data_table[max_struct_size];

    do {

        char name[max_c_string_length];

        cout << "Gentile utente, inserisci il cognome (" << terminator_character << " per smettere): ";
        cin.getline(name,max_c_string_length + 1,'\n');
        // alternative to cin.getline(strcpy(people_data_table[i].name, name), max_c_string_length + 1,'\n');

        // cout << "name = " << name << " lughezza = " << strlen(name) << endl; // debug

        if(strcmp(name, terminator_character) == 0) {

            break;

        } else {

            strcpy(people_data_table[people_data_table_row_index].name,name);

            do {

                cout << "Gentile utente, inserisci l'eta': ";
                cin >> people_data_table[people_data_table_row_index].age;

                // cout << "age " << people_data_table[people_data_table_row_index].age << endl; // debug

                if(!cin) {

                    cout << "Il tipo di dato inserito NON e' corretto!" << endl;

                    cin.clear();
                    cin.ignore(256,'\n');

                } else if(
                    people_data_table[people_data_table_row_index].age >= 0 &&
                    people_data_table[people_data_table_row_index].age <= max_person_age
                ) {

                    break;

                }

            } while(true);

        }

        cin.ignore(256, '\n'); // without this I have an odd and eager cin.getline() behaviour in do-while loop

        people_data_table_row_index++;

    } while(people_data_table_row_index <= max_struct_size);

    int people_youth_table_row_index = people_data_table_row_index, minimum_age = 0;

    people_data youth_people_data_table[people_youth_table_row_index];
    // people_youth_table_row_index because people added to the table can all have the same age

    for(int i = 0; i < people_youth_table_row_index; i++) { // min algorithm

        switch(i) { // raw alternative to if-else statement

            case 0: {

                minimum_age = people_data_table[i].age;

            }

            default: {

                if(people_data_table[i].age <= minimum_age) {

                    minimum_age = people_data_table[i].age;

                }

            }

        }

    }

    // print starting table
    /*for(int i = 0; i < people_data_table_row_index; i++) {
        cout << "name: " << people_data_table[i].name << ", age: " << people_data_table[i].age << endl;
    }*/

    for(int i = 0; i < people_youth_table_row_index; i++) { // check minimum ages

        if(people_data_table[i].age == minimum_age) {

            youth_people_data_table[i].age = people_data_table[i].age;

            strcpy(youth_people_data_table[i].name,people_data_table[i].name);

            // youth_people_data_table[i].age_check = 1;

        } else {

            strcpy(youth_people_data_table[i].name,"/" );

            youth_people_data_table[i].age = -1;

            // youth_people_data_table[i].age_check = 0;

        }
    }

    // print ending table
    /*for(int i = 0; i < people_youth_table_row_index; i++) {
        cout << "name: " << youth_people_data_table[i].name << ", age: " << youth_people_data_table[i].age << endl;
    }*/

    cout << (minimum_age == 0 ? "" : "*** I piu' giovani sono: ***") << endl;

    for(int i = 0; i < people_youth_table_row_index; i++) { // print youth table

        // if(youth_people_data_table[i].age_check == 1) {

        if(youth_people_data_table[i].age == minimum_age) {

            cout << "|";
            cout.width(36);

            cout << youth_people_data_table[i].name;
            cout.width(8);

            cout << youth_people_data_table[i].age;

            cout << endl;

        }

    }

    cout << "*** Programma terminato ***";

    return 0;

}
