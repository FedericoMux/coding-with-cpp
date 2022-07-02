//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>

using namespace std;

int const thirty_with_honours = 31;

int main() {

    float grade, summation = 0, valid_grades_counter = 0, general_counter = 0;

    do {

        cout << "Gentile utente, immetti un voto (negativo per smettere): ";
        cin >> grade;

        general_counter++;

        if(grade >= 0 && grade <= thirty_with_honours) {

            summation = summation + grade; // summation logic

            valid_grades_counter += 1;

        } else if(grade > thirty_with_honours) {

            cout << "Il voto inserito supera il massimo voto consentito!" << endl;

            grade = 0; // grade reset so I stay in do-while loop

        } else if(grade < 0 && general_counter == 1) { // negative grade only at first time

            cout << "Non hai ancora inserito nessun voto!" << endl;

            general_counter = 0; // reset
            grade = 0; // grade reset so I stay in do-while loop

        }

    } while(grade >= 0 && grade <= thirty_with_honours);

    cout << "Hai immesso " << valid_grades_counter << " voti" << endl;

    float arithmetic_average = summation / valid_grades_counter;

    cout << "La media dei tuoi voti su base 30 e': " << arithmetic_average << endl;
    cout << "La media dei tuoi voti su base 110 e': " << arithmetic_average * 110 / (thirty_with_honours - 1) << endl;

    cout << "*** Programma terminato ***";

    return 0;

}

