//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>
#include <cstring>

using namespace std;

int const ascii_jumping_pattern = 32;
int const max_c_string_length = 1000;
int const max_new_c_string_length = 3000; // because every character can potentially be a vowel

int main() {
    
    char input_sentence[max_c_string_length], leader_character = 'f';

    int occurrences_counter = 0;

    cout << "Gentile utente, inserisci una frase qualsiasi (max " << max_c_string_length << " caratteri e terminata da a capo): " << endl;
    cin.getline(input_sentence,max_c_string_length + 1,'\n');

    // length calculation of input string
    int string_length = strlen(input_sentence);

    char translated_sentence[max_new_c_string_length];

    for(int i = 0 , j = 0; i < string_length && j < string_length * 3; i++, j++) { // translation process

        translated_sentence[j] = input_sentence[i];

        if(
            translated_sentence[j] == 'a' ||
            translated_sentence[j] == 'e' ||
            translated_sentence[j] == 'i' ||
            translated_sentence[j] == 'o' ||
            translated_sentence[j] == 'u' ||
            translated_sentence[j] == 'a' - ascii_jumping_pattern ||
            translated_sentence[j] == 'e' - ascii_jumping_pattern ||
            translated_sentence[j] == 'i' - ascii_jumping_pattern ||
            translated_sentence[j] == 'o' - ascii_jumping_pattern ||
            translated_sentence[j] == 'u' - ascii_jumping_pattern
        ) {

            translated_sentence[j+1] = leader_character; // set 'f'
            translated_sentence[j+2] = translated_sentence[j]; // copy vowel read

            occurrences_counter += 2; // set number of insertions

            j += 2; // this can be compacted with j++

        }

    }

    // modified string length calculation
    string_length += occurrences_counter;

    // ending print
    cout << "La frase inserita tradotta nella lingua \"segreta\" del Farfallese e':" << endl;
    for(int i = 0; i < string_length; i++) {

        cout << translated_sentence[i];

    }
    cout << endl;

    cout << "*** Programma terminato ***";

    return 0;

}
