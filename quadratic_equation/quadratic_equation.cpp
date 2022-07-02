//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    char token;

    double a, b, c;

    cout << "*** Programma di calcolo delle soluzioni di un'equazione di II grado della forma: ax^2 + bx + c = 0 ***" << endl;

    do {

        cout << "Gentile utente, inserisci il coefficiente a: ";
        cin >> a;

        cout << "Gentile utente, inserisci il coefficiente b: ";
        cin >> b;

        cout << "Gentile utente, inserisci il coefficiente c: ";
        cin >> c;

        double first_root, second_root, double_root, discriminant = pow(b,2) - 4 * a * c;

        if(discriminant > 0) {

            first_root = (-b + sqrt(discriminant)) / (2 * a); // parenthesis useful to force operator precedence

            second_root = (-b - sqrt(discriminant)) / (2 * a); // parenthesis useful to force operator precedence

            cout << "Soluzioni distinte: " << "x1 = " << first_root << ", x2 = " << second_root << endl;

        } else if(discriminant == 0) {

            double_root = -b / (2 * a); // parenthesis useful to force operator precedence

            cout << "Soluzioni coincidenti: " << "x1 = x2 = " << double_root << endl;

        } else {

            cout << "Discriminante negativo! L'equazione non ha soluzioni Reali" << endl;

        }

        cout << "Gentile utente, vuoi ripetere il test da capo? (s per si', n per no): ";
        cin >> token;

    } while(token == 's');

    cout << "*** Programma terminato ***";

    return 0;

}
