//
// Created by Federico Stefanoni on 01/01/2020.
//

#include <iostream>

using namespace std;

int main() {

    char token;

    do {

        // assumption: number of mountain chain peaks is the number of matrix coefficients
        // assumption: target matrix is compulsorily a square matrix nxn

        int num_of_peaks, peaks_counter = 0, boundary = -1;

        do {

            cout << "Gentile utente, inserisci la dimensione della matrice (3 <= n <= 100): ";
            cin >> num_of_peaks;
    
            if(cin.fail()) {
    
                cout << "Il tipo di dato inserito NON e' corretto!" << endl;
    
                cin.clear();
                cin.ignore(256,'\n');
    
            } else if(num_of_peaks >= 3 && num_of_peaks <= 100) {
    
                break;
    
            }

        } while(true);
        
        int mountain_chain[num_of_peaks][num_of_peaks];

        // set all peaks value in the mountain chain
        cout << "Gentile utente, inserisci le altitudini:" << endl;
        
        for(int i = 0; i < num_of_peaks; i++) {

            for(int j = 0; j < num_of_peaks; j++) {

                cin >> mountain_chain[i][j];
    
                while(!cin) {
    
                    cout << "Il tipo di dato inserito NON e' corretto!" << endl;
    
                    cin.clear();
                    cin.ignore(256,'\n');
    
                    cin >> mountain_chain[i][j];
    
                }

            }

        }

        // print peaks matrix first
        cout << "Le vette formano una matrice quadrata di dimensioni " << num_of_peaks << '*' << num_of_peaks << endl;

        for(int i = 0; i < num_of_peaks; i++) {

            for(int j = 0; j < num_of_peaks; j++) {

                cout.width(5);
                cout << mountain_chain[i][j];

            }

            cout << endl;

        }

        // reset matrix borders with negative integers
        for(int i = 0, j = 0; j < num_of_peaks; j++) { // top border

            mountain_chain[i][j] = boundary;

        }

        for(int i = 0, j = 0; i < num_of_peaks; i++) { // left border

            mountain_chain[i][j] = boundary;

        }

        for(int i = num_of_peaks - 1, j = 0; j < num_of_peaks; j++) { // right border

            mountain_chain[i][j] = boundary;

        }

        for(int i = 0, j = num_of_peaks - 1; i < num_of_peaks; i++) { // bottom border

            mountain_chain[i][j] = boundary;

        }

        /*
        // print matrix test after border peaks are reset (it is just a simple check)
        for(int i = 0; i < num_of_peaks; i++) {
            for(int j = 0; j < num_of_peaks; j++) {
                cout.width(3);
                cout << mountain_chain[i][j];
            }
            cout << endl;
        }
        */

        // max peaks calculation
        int max_peak[num_of_peaks * 2];
        // max_peak is not a matrix but a simple array
        // * 2 because all the peaks can have same value

        // in the calculation model of peaks the number must be greater than the adjacent numbers, see example below
        /*
        ------- 50 -------
        ---- 40 60 30 ----
        ------- 30 -------
        */

        int k = 0; // max peak array index
        for(int i = 1; i < num_of_peaks - 1; i++) {

            for(int j = 1; j < num_of_peaks - 1; j++) {

                if(
                    mountain_chain[i][j] >= mountain_chain[i][j+1] &&
                    mountain_chain[i][j] >= mountain_chain[i+1][j] &&
                    mountain_chain[i][j] >= mountain_chain[i][j-1] &&
                    mountain_chain[i][j] >= mountain_chain[i-1][j]
                ) {

                    int coord_row = i + 1, coord_col = j + 1;

                    peaks_counter++;

                    max_peak[k] = mountain_chain[i][j]; // save max speak spotted
                    max_peak[k+1] = coord_row; // save max peak row coordinate value
                    max_peak[k+2] = coord_col; // save max peak column coordinate value

                    k += 3;
                    // += 3 because k includes max peak value, max peak row coordinate value and max peak column coordinate value

                }

            }

        }

        // ending print of all max peaks
        cout << "I picchi rilevati sono " << peaks_counter << ":" << endl;

        for(int h = 0; h < peaks_counter * 3; h += 3) {

            cout << "(((ACK))) trovato picco a quota " << max_peak[h] << " metri con coordinate ";
            cout << "[" << max_peak[h+1] << "]" << "[" << max_peak[h+2] << "]";
            cout << endl;

        }

        cout << "Gentile utente, vuoi ripetere il test da capo? (s per si', n per no): ";
        cin >> token;

    } while(token == 's');

    cout << "*** Programma terminato ***";

    return 0;

}
