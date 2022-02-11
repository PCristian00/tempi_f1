#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
#define NUMERO_PILOTI 20
#define NOME_MAX 15
struct giro {
    char pilota[NOME_MAX + 1];
    char tempo[9];
};
giro tempi[NUMERO_PILOTI];

// Legge in input il file “nomefile” e popola il vettore “tempi”.
void leggiFile(const char nomefile[]) {
    fstream file;
    file.open(nomefile, ios::in);
    if (!file) {
        cout << nomefile << " NON TROVATO!" << endl;
        exit(1);   // call system to stop
    }
    for (int i = 0; i < NUMERO_PILOTI; i++) file >> tempi[i].pilota >> tempi[i].tempo;
    file.close();
}

/* Ordina il vettore “giri” di lunghezza “n” in maniera crescente secondo il
campo “giro.tempo”. */
void ordinaTempi(giro giri[], int n) {
    giro tmp;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (strcmp(giri[i].tempo, giri[j].tempo) > 0) {
                tmp = giri[i];
                giri[i] = giri[j];
                giri[j] = tmp;
            }
}

/* Stampa il vettore “giri” di lunghezza “n” come mostrato nell'esempio di
esecuzione */
void stampaGriglia(giro giri[], int n) {
    for (int i = 0; i < n; i++)
        cout << (i + 1) << ". " << giri[i].pilota << " " << giri[i].tempo << endl;
}

/* Se nel vettore “giri” esiste un elemento per cui il campo “giro.pilota” è
uguale a “nomePilota”, lo stampa a schermo, indicandone posizione e tempo.
Altrimenti avvisa l'utente che “nomePilota” non è presente nel vettore. */
void stampaPilota(giro giri[], int n, char nomePilota[]) {
    //Nome completamente in minuscolo
    strlwr(nomePilota);
    //Prima lettera maiuscola
    nomePilota[0] = toupper(nomePilota[0]);

    //posizione del pilota trovato
    int pf = -1;
    for (int i = 0; i < n; i++)
        if (strcmp(giri[i].pilota, nomePilota) == 0) pf = i;

    if (pf != -1)
        cout << giri[pf].pilota << " partira' in posizione " << pf + 1 << " con il tempo di " << giri[pf].tempo << endl;
    else cout << "Nessun pilota in gara si chiama " << nomePilota << endl;

}

// Programma principale: mostra il menù e chiama le altre funzioni.
int main() {
    //TODO mettere solo "tempi.txt" pare non funzionare, modificare questo indirizzo con il path assoluto sul tuo terminale
    char filename[] = "C:\\Users\\Thinkpad User\\CLionProjects\\tempi_f1\\tempi.txt";

    leggiFile(filename);
    ordinaTempi(tempi, NUMERO_PILOTI);

    char scelta;
    char pilota[NOME_MAX];
    bool run = true;

    do {

        cout << endl;
        cout << "MENU" << endl;
        cout << "A) STAMPA GRIGLIA PARTENZA" << endl;
        cout << "B) STAMPA PILOTA" << endl;
        cout << "C) ESCI" << endl;
        cout << endl;

        cin >> scelta;

        switch (scelta) {
            case 'a':
            case 'A':
                stampaGriglia(tempi, NUMERO_PILOTI);
                break;

            case 'b':
            case 'B':
                cout << "INSERIRE NOME PILOTA: " << endl;
                cin >> pilota;
                stampaPilota(tempi, NUMERO_PILOTI, pilota);
                break;

            case 'c':
            case 'C':
                cout << "CHIUSURA APPLICAZIONE" << endl;
                run = false;
                break;

            default:
                cout << "SCELTA INCOMPATIBILE" << endl;
                break;
        }
    } while (run);

}