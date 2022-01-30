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
// 2 punti
}

/* Ordina il vettore “giri” di lunghezza “n” in maniera crescente secondo il
campo “giro.tempo”. */
void ordinaTempi(giro giri[], int n) {
// 5 punti
}

/* Stampa il vettore “giri” di lunghezza “n” come mostrato nell'esempio di
esecuzione */
void stampaGriglia(giro giri[], int n) {
// 3 punti
}

/* Se nel vettore “giri” esiste un elemento per cui il campo “giro.pilota” è
uguale a “nomePilota”, lo stampa a schermo, indicandone posizione e tempo.
Altrimenti avvisa l'utente che “nomePilota” non è presente nel vettore. */
void stampaPilota(giro giri[], int n, char nomePilota[]) {
// 4 punti
}

// Programma principale: mostra il menù e chiama le altre funzioni.
int main() {

// 4 punti
}