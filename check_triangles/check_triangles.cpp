//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>

using namespace std;

int main() {

    int user_choice;

    float side_1, side_2, side_3;

    do {

        cout << "*** Gentile utente, inserisci la lunghezza dei 3 lati di un triangolo ***" << endl;
    
        cout << "Primo lato: ";
        while(!(cin >> side_1)) {
    
            cout << "Il tipo di dato inserito NON e' corretto!" << endl;
    
            cin.clear();
            cin.ignore(256,'\n');
    
            cout << "Primo lato: ";
    
        }
    
        cout << "Secondo lato: ";
        while(!(cin >> side_2))  {
    
            cout << "Il tipo di dato inserito NON e' corretto!" << endl;
    
            cin.clear();
            cin.ignore(256,'\n');
    
            cout << "Secondo lato: ";
    
        }
    
        cout << "Terzo lato: ";
        while(!(cin >> side_3)) { // stream test
    
            cout << "Il tipo di dato inserito NON e' corretto!" << endl;
    
            cin.clear();
            cin.ignore(256,'\n');
    
            cout << "Terzo lato: ";
    
        }
    
        cout << "*** Scegli una delle operazioni seguenti: ***" << endl;
        cout << "Digita 1 per tipo di triangolo" << endl << "Digita 2 per verifica triangolo" << endl << "Digita 3 per cambiare triangolo" << endl << "Digita 4 per uscire" << endl;
        
        do {

            cout << "Operazione scelta? ";
            cin >> user_choice;
    
            switch(user_choice) { // simulate user menu
    
                case 1: {
    
                    if(
                        (side_1 + side_2 > side_3) &&
                        (side_2 + side_3 > side_1) &&
                        (side_3 + side_1 > side_2)
                    ) { // first test if it is a triangle
                        
                        if( (side_1 == side_2) && (side_2 == side_3) ) { // test the type of triangle
                            
                            cout << "Il triangolo e' equilatero" << endl;
                            
                        } else if( (side_1 != side_2) && (side_2 != side_3) && (side_1 != side_3) ) {
                            
                            cout << "Il triangolo e' scaleno" << endl;
                            
                        } else if( 
                            ( (side_1 == side_2 ) && (side_1 != side_3) ) ||
                            ( (side_2 == side_3) && (side_2 != side_1) ) ||
                            ( (side_1 == side_3) && (side_1 != side_2) )
                        ) {

                            cout << "Il triangolo e' isoscele" << endl;

                        }

                    } else {
                        
                        cout << "NON e' un triangolo!" << endl;

                        // user_choice = 3; // not necessary

                    }
                   
                    break;
                    
                }
                
                case 2: {

                    if( // first test if it is a triangle
                        (side_1 + side_2 > side_3) &&
                        (side_2 + side_3 > side_1) &&
                        (side_3 + side_1 > side_2)
                    ) {

                        if(
                            (side_1 > side_2) && (side_1 > side_3) ||
                            (side_2 > side_1) && (side_2 > side_3) ||
                            (side_3 > side_1) && (side_3 > side_2)
                        ) { // test if triangle is also a right triangle

                            cout << "Il triangolo e' rettangolo" << endl;

                        } else {

                            cout << "Il triangolo NON e' rettangolo" << endl;

                        }

                    } else {

                        cout << "NON e' un triangolo!" << endl;

                        // user_choice = 3; // not necessary

                    }

                    break;
                    
                }
                
                case 3: break;

                case 4: {

                    cout << "Arrivederci!" << endl;

                    break;

                }
                
                default: {

                    cout << "Carattere immesso NON consentito!" << endl;

                    user_choice = 3;

                }
                
            }
    
        } while(user_choice == 1 || user_choice == 2);

    } while(user_choice == 3);

    cout << "*** Programma terminato ***";

    return 0;

}