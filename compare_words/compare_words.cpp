//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>
#include <cstring>

using namespace std;

int const max_c_string_length = 100;

int main() {

    char terminator_character[] = "$$$";

    int prefix_counter;

    do {

        bool comparison = false;

        prefix_counter = 0;

        // grab first word
        char word_1[max_c_string_length];

        cout << "Gentile utente, inserisci la PRIMA parola ($$$ per terminare): ";
        cin.getline(word_1,max_c_string_length + 1,'\n');

        /* // version with input string without space and break line
        cin >> word_1;
        cin.ignore(256, '\n');
        */

        if(strcmp(word_1, terminator_character) == 0) { // break from do-while loop

            break;

        }

        // grab second word
        char word_2[max_c_string_length];

        cout << "Gentile utente, inserisci la SECONDA parola ($$$ per terminare): ";
        cin.getline(word_2,max_c_string_length + 1,'\n');

        /* // version with input string without space and break line
        cin >> word_2;
        cin.ignore(256, '\n');
        */

        if(strcmp(word_2, terminator_character) == 0) { // break from do-while loop

            break;

        }

        // calculate and compare string lengths
        int len_word_1 = strlen(word_1);
        int len_word_2 = strlen(word_2);

        if(len_word_1 < len_word_2) {

            comparison = true;

        }

        if(strcmp(word_1, word_2) == 0) { // lexicographic precedence word_1 == word_2

            cout << "*** Le due parole sono uguali ***" << endl;

        } else if(strcmp(word_1, word_2) < 0) { // lexicographic precedence word_1 < word_2

            cout << "*** La parola " << word_1 << " precede la parola " << word_2 << " ***" << endl;

            for(int i = 0; i < (comparison ? len_word_1 : len_word_2); i++) {

                if(word_1[i] == word_2[i]) {

                    prefix_counter++;

                } else {

                    break;

                }

            }

            if(prefix_counter == (comparison ? len_word_1 : len_word_2)) {

                cout << "*** La parola " << word_1 << " e' un prefisso di " << word_2 << " ***" << endl;

            }

        } else if(strcmp(word_1, word_2) > 0) { // lexicographic precedence word_1 > word_2

            cout << "*** La parola " << word_2 << " precede la parola " << word_1 << " ***" << endl;

            for(int i = 0; i < (comparison ? len_word_1 : len_word_2); i++) {

                if(word_2[i] == word_1[i]) {

                    prefix_counter++;

                } else {

                    break;

                }

            }

            if(prefix_counter == (comparison ? len_word_1 : len_word_2)) {

                cout << "*** La parola " << word_2 << " e' un prefisso di " << word_1 << " ***" << endl;

            }

        }

    } while(true);

    cout << "*** Programma terminato ***";

    return 0;

}
