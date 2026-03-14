#include <iostream>
#include <iomanip>
using namespace std;
const int MAXR = 100;
const int MAXC = 100;

void caricaMatricePitagorica(int mat[][MAXC], int nr, int nc);
void stampaMatrice(const int mat[][MAXC], int nr, int nc, int np);
int contaPosizioni(int num);
int maxMatrice(int mat[][MAXC], int nr, int nc);

int main() {
    const int nr = 5;
    const int nc = 5;
    int mat [MAXR][MAXC];
    int m, cf;
    caricaMatricePitagorica(mat,nr,nc);
    mat[2][2] = -1000;
    m = maxMatrice(mat,nr,nc);
    cf = contaPosizioni(m);
    stampaMatrice(mat,nr,nc,cf);


    return 0;
}

void caricaMatricePitagorica(int mat[][MAXC], int nr, int nc) {
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            mat [i][j] = i * j;
        }
    }
}

void stampaMatrice(const int mat[][MAXC], int nr, int nc, int np) {
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            cout << setw(np+1) << mat [i][j];
        }
        cout << endl;
    }
}

int contaPosizioni(int num) {
    // Gestione del caso zero
    if ( num == 0 )
        return 1;

    int cont = 0;
    if ( num < 0 ) {
        num = -1 * num;
        cont++;
    }
    while( num > 0 ) {
        num /= 10;
        cont++;
    }
    return cont;
}

int maxMatrice(int mat[][MAXC], int nr, int nc) {
    int max = mat[0][0];
    for(int i = 0; i < nr; i++) {
        for (int j  = 0; j < nc; j++) {
            if ( mat[i][j] > max )
                max = mat[i][j];
        }
    }
    return max;
}