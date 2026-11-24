#include<iostream>

using namespace std;

//e26
const int f = 3, c = 3;
void cargar(int m[][c], int i, int j) {
    if (i==f) return;
    if (j==c) {
        cargar(m, i+1, 0);
        return;
    }
    cout << "Ingrese [" << i << "][" << j << "]: ";
    cin >> m[i][j];
    cargar(m, i, j + 1);
}
//e27
void mostrar(int m[][c], int i, int j) {
    if (i==f){
        cout << endl;
        return;
    }
    if (j==c)  {
        cout << endl;
        mostrar(m, i+1, 0); 
        return;
    }
    cout << m[i][j] << " ";
    mostrar(m, i, j + 1);
}

//e28
int sumarTodosLosElementos(int m[][c], int i, int j) {
    if (i==f) return 0;
    if (j==c) return sumarTodosLosElementos(m, i+1, 0);
    return m[i][j] + sumarTodosLosElementos(m, i, j+1);
}
//e29
void contarParesImpares(int m[][c], int i, int j, int& par, int& impar) {
    if (i == f) return;

    if (j == c) {
        contarParesImpares(m, i + 1, 0, par, impar);
        return;
    }

    if (m[i][j] % 2 == 0)
        par++;
    else
        impar++;

    contarParesImpares(m, i, j + 1, par, impar);
}
//e30
int encontrarMayor(int m[][c], int i, int j) {

    if (i == f - 1 && j == c - 1)
        return m[i][j];

    if (j == c)
        return encontrarMayor(m, i + 1, 0);

    int may = encontrarMayor(m, i, j + 1);

    if (m[i][j] > may)
        return m[i][j];

    return may;
}

//e31
void encontrarMenorYPos(int m[][c], int i, int j, int& menor, int& posf, int& posc) {

    if (i == f) return;

    if (j == c) {
        encontrarMenorYPos(m, i + 1, 0, menor, posf, posc);
        return;
    }

    if (m[i][j] < menor) {
        menor = m[i][j];
        posf = i;
        posc = j;
    }

    encontrarMenorYPos(m, i, j + 1, menor, posf, posc);
}

//e32
void contarCerosPositivosNegativos(int m[][c], int i, int j, int& ceros, int& positivos, int& negativos) {
    if (i == f) return;

    if (j == c){
        contarCerosPositivosNegativos(m, i + 1, 0, ceros, positivos, negativos);
        return;
    }
    if (m[i][j] == 0) ceros++;
    else if (m[i][j] > 0) positivos++;
    else negativos++;

    contarCerosPositivosNegativos(m, i, j + 1, ceros, positivos, negativos);
}

//e33
void encontrarPosicionDeX(int m[][c], int i, int j, int x, int& posf, int& posc) {
    if (i == f) return;

    if (j == c){
        encontrarPosicionDeX(m, i + 1, 0, x, posf, posc);
        return;
    }
    if (m[i][j] == x) {
        posf = i;
        posc = j;
        return; 
    }

    encontrarPosicionDeX(m, i, j + 1, x, posf, posc);
}

bool buscarPosicionDeX(int m[][c], int i, int j, int x, int& posf, int& posc) {
    if (i == f) return false;

    if (j == c){
        return buscarPosicionDeX(m, i + 1, 0, x, posf, posc);
    }
    if (m[i][j] == x) {
        posf = i;
        posc = j;
        return true; 
    }

    return buscarPosicionDeX(m, i, j + 1, x, posf, posc);
}

//e34
int sumarFila(int m[][c], int i, int j) {
    if (j == c) return 0;
    return m[i][j] + sumarFila(m, i, j + 1);
}
void mostrarSumaFila(int m[][c], int i) {
    if (i == f) return;
    cout << "Fila " << i << ": " << sumarFila(m, i, 0) << endl;

    mostrarSumaFila(m, i + 1);
}

//e35
int sumarColumna(int m[][c], int i, int j) {
    if (i == f) return 0;
    return m[i][j] + sumarColumna(m, i + 1, j);
}

void mostrarSumaColumna(int m[][c], int j) {
    if (j == c) return;
    cout << "Columna " << j << ": " << sumarColumna(m, 0, j) << endl;

    mostrarSumaColumna(m, j + 1);
}

//e36
int sumarDiagonalPrincipal(int m[][c], int i) {
    if (i == f) return 0;
    return m[i][i] + sumarDiagonalPrincipal(m, i + 1);
}

//e37
int sumarDiagonalSecundaria(int m[][c], int i) {
    if (i == f) return 0;
    return m[i][c -1 - i] + sumarDiagonalSecundaria(m, i + 1);
}

//e38
void sumarSobreYDebajoDiagonalPrincipal(int m[][c], int i, int j, int& encima, int& debajo) {
    if (i == f) return;

    if (j == c){
        sumarSobreYDebajoDiagonalPrincipal(m, i + 1, 0, encima, debajo);
        return;
    }

    if (i < j) encima += m[i][j];
    else if (i > j) debajo += m[i][j];

    sumarSobreYDebajoDiagonalPrincipal(m,i,j+1,encima,debajo);
}

//e39
void mostrarBorde(int m[][c], int i, int j) {
    if (i == f) return;

    if (j == c){
        mostrarBorde(m, i + 1, 0);
        return;
    }

    if (i == 0 || i == f - 1 || j == 0 || j == c - 1)
        cout << m[i][j] << " ";

    mostrarBorde(m, i, j + 1);
}

//e40
int sumarBorde(int m[][c], int i, int j) {
    if (i == f) return 0;

    if (j == c) return sumarBorde(m, i + 1, 0);

    if (i == 0 || i == f - 1 || j == 0 || j == c - 1)
        return m[i][j] + sumarBorde(m, i, j + 1);
    return sumarBorde(m, i, j + 1);
}

//e41
void mostrarTranspuesta(int m[][c], int i, int j) {
    if (j == c){
        cout << endl;
        return;
    } 

    if (i == f) {
        cout << endl;
        mostrarTranspuesta(m, 0, j + 1);
        return;
    }

    cout << m[i][j] << " ";
    mostrarTranspuesta(m, i + 1, j);
}

//e42
int mayorDeFila(int m[][c], int i, int j) {
    if (j == c - 1)
        return m[i][j];

    int may = mayorDeFila(m, i, j + 1);

    if (m[i][j] > may)
        return m[i][j];

    return may;
}

void mostrarMayorDeFila(int m[][c], int i) {
    if (i == f) return;
    cout << "Mayor de la fila " << i << ": " << mayorDeFila(m, i, 0) << endl;
    mostrarMayorDeFila(m, i + 1);
}

//e43
bool esSimetrica(int m[][c], int i, int j) {
    if (i == f) return true;

    if (j == c)
        return esSimetrica(m, i + 1, 0);

    if (m[i][j] != m[j][i])
        return false;

    return esSimetrica(m, i, j + 1);
}

//e44
void Rotar90Grados(int m[][c], int i, int j) {
    if (j == c){
        cout << endl;
        return; 
    } 

    if ( i < 0) {
        cout << endl;
        Rotar90Grados(m, f - 1, j + 1);
        return;
    }
    cout << m[i][j] << " ";
    Rotar90Grados(m, i - 1, j);
}

//e45
void recorrerDerecha(int m[][c], int arriba, int j, int derecha) {
    if (j > derecha) return;

    cout << m[arriba][j] << " ";

    recorrerDerecha(m, arriba, j + 1, derecha);
}

void recorrerAbajo(int m[][c], int i, int derecha, int abajo) {
    if (i > abajo) return;

    cout << m[i][derecha] << " ";

    recorrerAbajo(m, i + 1, derecha, abajo);
}

void recorrerIzquierda(int m[][c], int abajo, int j, int izquierda) {
    if (j < izquierda) return;

    cout << m[abajo][j] << " ";

    recorrerIzquierda(m, abajo, j - 1, izquierda);
}

void recorrerArriba(int m[][c], int i, int izquierda, int arriba) {
    if (i < arriba) return;

    cout << m[i][izquierda] << " ";

    recorrerArriba(m, i - 1, izquierda, arriba);
}

void recorrerEspiral(int m[][c], int arriba, int izquierda, int abajo, int derecha) {
    if (arriba > abajo || izquierda > derecha) return;

    recorrerDerecha(m, arriba, izquierda, derecha);

    if (arriba < abajo) recorrerAbajo(m, arriba + 1, derecha, abajo);

    if (arriba < abajo && izquierda < derecha){
        recorrerIzquierda(m, abajo, derecha - 1, izquierda);
        recorrerArriba(m, abajo - 1, izquierda, arriba); 
    }

    recorrerEspiral(m, arriba + 1, izquierda + 1, abajo - 1, derecha - 1);
}

//e46
bool esTriangularSuperior(int m[][c], int i, int j) {
    if (i == f) return true;

    if (j == c) return esTriangularSuperior(m, i + 1, 0);

    if (i > j && m[i][j] != 0) return false;

    return esTriangularSuperior(m, i, j + 1);
}

//e47
void sumarTriangulos(int m[][c], int i, int j, int& superior, int& inferior) {

    if (i == f) return;

    if (j == c) {
        sumarTriangulos(m, i + 1, 0, superior, inferior);
        return;
    }

    if (i <= j) superior += m[i][j];

    if (i >= j) inferior += m[i][j];

    sumarTriangulos(m, i, j + 1, superior, inferior);
}

//e48
int menorFila(int m[][c], int i, int j) {
    if (j == c - 1) return m[i][j];

    int menor = menorFila(m, i, j + 1);

    if (m[i][j] < menor) return m[i][j];

    return menor;
}

int mayorColumna(int m[][c], int i, int j) {
    if (i == f - 1) return m[i][j];

    int mayor = mayorColumna(m, i + 1, j);

    if (m[i][j] > mayor) return m[i][j];

    return mayor;
}

bool buscarPuntoSilla(int m[][c], int i, int j) {
    if (i == f){
        cout << endl;
        return false;
    }

    if (j == c) {
        return buscarPuntoSilla(m, i + 1, 0);
    }

    if (m[i][j] == menorFila(m, i, 0) &&
        m[i][j] == mayorColumna(m, 0, j)) {

        cout << "Punto de silla: " << m[i][j];
        cout << " Fila: " << i << " Columna: " << j << endl;

        return true;
    }

    return buscarPuntoSilla(m, i, j + 1);
}

//e49
bool comprobarHorizontal(int m[][c], int i, int j, int valor, int k) {

    if (k == 0) return true;

    if (j == c) return false;

    if (m[i][j] != valor) return false;

    return comprobarHorizontal(m, i, j + 1, valor, k - 1);
}

bool comprobarVertical(int m[][c], int i, int j, int valor, int k) {

    if (k == 0) return true;

    if (i == f) return false;

    if (m[i][j] != valor) return false;

    return comprobarVertical(m, i + 1, j, valor, k - 1);
}

bool comprobarDiagonal(int m[][c], int i, int j, int valor, int k) {

    if (k == 0) return true;

    if (i == f || j == c) return false;

    if (m[i][j] != valor) return false;

    return comprobarDiagonal(m, i + 1, j + 1, valor, k - 1);
}
bool comprobarDiagonalInversa(int m[][c], int i, int j, int valor, int k) {

    if (k == 0) return true;

    if (i == f || j < 0) return false;

    if (m[i][j] != valor) return false;

    return comprobarDiagonalInversa(m, i + 1, j - 1, valor, k - 1);
}

bool buscarSecuencia(int m[][c], int i, int j, int k) {

    if (i == f) return false;

    if (j == c) {
        return buscarSecuencia(m, i + 1, 0, k);
    }

    if (comprobarHorizontal(m, i, j, m[i][j], k) ||
        comprobarVertical(m, i, j, m[i][j], k) ||
        comprobarDiagonal(m, i, j, m[i][j], k) ||
        comprobarDiagonalInversa(m, i, j, m[i][j], k)) {

        return true;
    }

    return buscarSecuencia(m, i, j + 1, k);
}

//e50
int sumaMaxima(int m[][c], int i, int j) {

    if (i == f - 1 && j == c - 1)
        return m[i][j];

    if (i == f - 1)
        return m[i][j] + sumaMaxima(m, i, j + 1);

    if (j == c - 1)
        return m[i][j] + sumaMaxima(m, i + 1, j);

    int derecha = sumaMaxima(m, i, j + 1);
    int abajo = sumaMaxima(m, i + 1, j);

    if (derecha > abajo) {
    return m[i][j] + derecha;
    } else {
    return m[i][j] + abajo;
    }
}

void mostrarCamino(int m[][c], int i, int j) {

    cout << m[i][j] << " ";

    if (i == f - 1 && j == c - 1)
        return;

    if (i == f - 1) {
        mostrarCamino(m, i, j + 1);
        return;
    }

    if (j == c - 1) {
        mostrarCamino(m, i + 1, j);
        return;
    }

    int derecha = sumaMaxima(m, i, j + 1);
    int abajo = sumaMaxima(m, i + 1, j);

    if (derecha > abajo)
        mostrarCamino(m, i, j + 1);
    else
        mostrarCamino(m, i + 1, j);
}

int main()
{
    int m[f][c] = {{2,4,6},{1,3,5},{7,8,9}};
    mostrar(m, 0, 0);
    int encima = 0, debajo = 0;
    /*
    encontrarPosicionDeX(m, 0, 0, x, posf, posc);
    cout << "Posicion de " << x << " : [" << posf << "][" << posc << "]" << endl;
    if (buscarPosicionDeX   (m, 0, 0, x, posf, posc))
    cout << "Encontrado en [" << posf << "][" << posc << "]";
    else
    cout << "No encontrado";
    */

    //buscarPuntoSilla(m, 0, 0);

    cout << "Suma maxima: " << sumaMaxima(m, 0, 0) << endl;
    cout << "Camino: ";
    mostrarCamino(m, 0, 0);
    
    return 0;
}
