//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>
#include <cstring>

using namespace std;

int const max_c_string_sequence_length = 1000; // include space char, null char terminator, etc.
int const max_c_string_length = 100; // focus only on exact match words

struct Elem{
   
    char name[max_c_string_length];

    int counter;
   
};

void update(Elem A[], int m, char S[]) {
    
    bool on_off = false;

    if(m == 0) { // write immediately the first word founded

        strcpy(A[0].name,S);

        A[0].counter = 1;

    } else {

        for(int i = 0; i < m; i++) {

            if(strcmp(A[i].name, S) == 0) {

                A[i].counter++;

                on_off = true;

                break;

            }

        }

        if(!on_off) { // write at the end only if no identical word was found

            strcpy(A[m].name,S);

            A[m].counter = 1;

        }

    }

}

int main() {

    Elem words_sequence[max_c_string_sequence_length];

    char single_word[max_c_string_length], single_character;

    int words_counter = -1;

    cout << "Gentile utente, inserisci il testo terminato da a capo (max " << max_c_string_length << " parole):" << endl;

    for(int i = 0; i < max_c_string_sequence_length; i++) { // max_c_string_sequence_length because include possible space, etc.

        single_character = cin.get();

        if(single_character == '\40') { // space character in octal encoding ASCII

            words_counter++;

            if(words_counter > max_c_string_length) { // exceeded maximum number of words allowed

                break;

            }

            single_word[i] = '\0'; // replace C-like null terminator in place of space character. Now it is a C like string

            // necessary for handle accented words
            if(strlen(single_word) != 0) { // if single_word == 0 meaning of keep only the null terminator char

                update(words_sequence,words_counter,single_word);

            }

            i = -1; // reset for loop index
            
        } else if(single_character == '\n') {

            words_counter++;

            if(words_counter > max_c_string_length) {

                break;

            }

            single_word[i] = '\0';

            // necessary for handle accented words
            if(strlen(single_word) != 0) { // if single_word == 0 meaning of keep only the null terminator char

                update(words_sequence,words_counter,single_word);

            }

            break;
        
        } else if(
            (single_character >= 65 && single_character <= 90) ||
            (single_character >= 97 && single_character <= 122)
        ) {

            single_word[i] = single_character;

        } else { // handle fallback , . ; ? ! ' etc

            i--; // without this, test exercise input with "il contratto è"

        }
    
    }

    cout << "Il numero di occorrenze di ciascuna parola nel testo e' :" << endl;
    
    for(int i = 0; i < words_counter + 1; i++) { // ending print loop

        if(words_sequence[i].counter != 0) {

            cout << words_sequence[i].name << ' ' << words_sequence[i].counter << endl;

        }

    }
    
    cout << "*** Programma terminato ***" << endl;
    
    return 0;
    
}
