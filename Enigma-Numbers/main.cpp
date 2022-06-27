#include <iostream>

using namespace std;

int main() {
    int ile_liter, ile_wirnikow, ile_reflektorow, ile_zadan;
    cin >> ile_liter >> ile_wirnikow;
    int** wirnik = new int* [ile_wirnikow];
    int** litery_powodojace_obrot = new int* [ile_wirnikow];
    for (int i = 0; i < ile_wirnikow; i++) {
        int* pojedynczy_wirnik = new int[ile_liter * 2];
        for (int j = 0; j < ile_liter; j++) {
            int a;
            cin >> a;
            pojedynczy_wirnik[j * 2] = a - 1 - j;
            pojedynczy_wirnik[(a - 1) * 2 + 1] = j - a + 1;

        }
        wirnik[i] = pojedynczy_wirnik;

        int liczba_litery_powodojace_obrot_tego_wirnika;
        cin >> liczba_litery_powodojace_obrot_tego_wirnika;

        int* litery_powodojace_obrot_tego_wirnika = new int[liczba_litery_powodojace_obrot_tego_wirnika + 1];
        litery_powodojace_obrot_tego_wirnika[0] = liczba_litery_powodojace_obrot_tego_wirnika;
        for (int j = 1; j <= liczba_litery_powodojace_obrot_tego_wirnika; j++) {
            cin >> litery_powodojace_obrot_tego_wirnika[j];
            litery_powodojace_obrot_tego_wirnika[j] -= 2;
            if (litery_powodojace_obrot_tego_wirnika[j] < 0)
                litery_powodojace_obrot_tego_wirnika[j] += ile_liter;

        }
        litery_powodojace_obrot[i] = litery_powodojace_obrot_tego_wirnika;

    }

    cin >> ile_reflektorow;
    int** reflektor = new int* [ile_reflektorow];
    for (int i = 0; i < ile_reflektorow; i++) {
        int* pojedynczy_wirnik = new int[ile_liter];
        for (int j = 0; j < ile_liter; j++) {
            int a;
            cin >> a;
            pojedynczy_wirnik[j] = a - j - 1;

        }
        reflektor[i] = pojedynczy_wirnik;

    }

    cin >> ile_zadan;
    for (int i = 0; i < ile_zadan; i++) {
        int ile_wirnikow_uzywamy, ktory_reflektor;
        cin >> ile_wirnikow_uzywamy;
        int** wirnik_uzywany = new int* [ile_wirnikow_uzywamy];
        int pierwszy_ruch[2] = {
        };

        for (int j = 0; j < ile_wirnikow_uzywamy; j++) {
            int* pozycja_wirnik = new int[2];
            cin >> pozycja_wirnik[0];
            cin >> pozycja_wirnik[1];
            pozycja_wirnik[1] -= 1;
            wirnik_uzywany[j] = pozycja_wirnik;

        }
        cin >> ktory_reflektor;

        int znak;
        while (cin >> znak) {
            if (znak == 0) {
                cout << endl;
                break;

            }

            if (ile_wirnikow_uzywamy > 1 && pierwszy_ruch[0] != 0) {
                int przesuniecie = 0;
                if (ile_wirnikow_uzywamy > 2 && pierwszy_ruch[1] != 0) {
                    for (int j = 1; j <= litery_powodojace_obrot[wirnik_uzywany[1][0]][0]; j++) {
                        if ((wirnik_uzywany[1][1] % ile_liter) == litery_powodojace_obrot[wirnik_uzywany[1][0]][j]) {
                            wirnik_uzywany[2][1] += 1;
                            wirnik_uzywany[1][1] += 1;
                            przesuniecie += 1;
                            break;

                        }

                    }

                }
                if (przesuniecie == 0) {
                    for (int j = 1; j <= litery_powodojace_obrot[wirnik_uzywany[0][0]][0]; j++) {
                        if ((wirnik_uzywany[0][1] % ile_liter) == litery_powodojace_obrot[wirnik_uzywany[0][0]][j]) {
                            wirnik_uzywany[1][1] += 1;
                            pierwszy_ruch[1] += 1;
                            break;

                        }

                    }

                }

            }
            wirnik_uzywany[0][1] += 1;
            pierwszy_ruch[0] += 1;


            for (int j = 0; j < ile_wirnikow_uzywamy; j++) {
                znak += wirnik[wirnik_uzywany[j][0]][((wirnik_uzywany[j][1] + znak - 1) % ile_liter) * 2];
                if (znak <= 0)
                    znak += ile_liter;
                else if (znak > ile_liter)
                    znak -= ile_liter;

            }

            znak += reflektor[ktory_reflektor][znak - 1];

            for (int j = ile_wirnikow_uzywamy - 1; j >= 0; j--) {
                znak += wirnik[wirnik_uzywany[j][0]][((wirnik_uzywany[j][1] + znak - 1) % ile_liter) * 2 + 1];
                if (znak <= 0)
                    znak += ile_liter;
                else if (znak > ile_liter)
                    znak -= ile_liter;

            }

            cout << znak << " ";

        }
        for (int j = 0; j < ile_wirnikow_uzywamy; j++)
            delete[] wirnik_uzywany[j];
        delete[] wirnik_uzywany;


    }

    for (int i = 0; i < ile_wirnikow; i++) {
        delete[] wirnik[i];
        delete[] litery_powodojace_obrot[i];


    }
    for (int i = 0; i < ile_reflektorow; i++)
        delete[] reflektor[i];
    delete[] wirnik;
    delete[] litery_powodojace_obrot;
    delete[] reflektor;
    return 0;
}