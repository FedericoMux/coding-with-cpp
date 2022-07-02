//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>

using namespace std;

int const k_day = 3;
int const k_week = 2;

struct bank_account {

    double incomes, outflows, balance;

};

void calculate(bank_account my_bank_account[k_week][k_day], int week, int day) {

    my_bank_account[week][day].balance = my_bank_account[week][day].incomes - my_bank_account[week][day].outflows;

    if(my_bank_account[week][day].balance > 0) {

        my_bank_account[week][day].balance *= 0.8; // account balance - 20%

    }

}

void total(bank_account my_bank_account[k_week][k_day]) {

    for(int week = 0; week < k_week; week++) {

        double bank_statement = 0;

        for(int day = 0; day < k_day; day++) {

            bank_statement += my_bank_account[week][day].balance;

            if(day == k_day - 1) cout << "*** Il saldo della settimana " << week + 1 << " e' " << bank_statement << " ***" << endl;

        }

    }

}

int main() {

    bank_account my_bank_account[k_week][k_day]; // matrix data structure

    for(int week = 0; week < k_week; week++) { // fill table

        for(int day = 0; day < k_day; day++) {

            cout << "Gentile utente, inserisci entrate e uscite del giorno " << day + 1 << " della settimana " << week + 1 << ": " << endl;
            cin >> my_bank_account[week][day].incomes >> my_bank_account[week][day].outflows;

            calculate(my_bank_account, week, day);

            cout << "*** Il saldo e' " << my_bank_account[week][day].balance << " ***" << endl;

        }

    }

    cout << "Gentile utente, ecco il tuo estratto conto:" << endl;

    total(my_bank_account);

    cout << "*** Programma terminato ***";

    return 0;

}
