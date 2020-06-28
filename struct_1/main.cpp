#include <iostream>
using namespace std;


using cmp = struct{
    float re;
    float im;
};

const int max_rows = 10, max_cols = 10;

void get_cmp(cmp* liczba){
    cout << "Podaj liczbe zespolona:" << endl;
    cout << "Podaj czesc rzeczywista: ";
    cin >> liczba->re;
    cout << "Podaj czesc urojona: ";
    cin >> liczba->im;
}

void get_matrix(int rows, int cols, cmp tab[][max_cols]){
    cout << "Wypelnij macierz " << rows << " x " << cols
    << " liczb zespolonych:" << endl;

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            get_cmp(&tab[i][j]);
        }
    }
}

void print_cmp(const cmp* liczba){
    cout << (*liczba).re << ((*liczba).im >= 0? (" + i") : (" - i")) << abs((*liczba).im); 
}

void print_matrix(int rows, int cols, cmp tab[][max_cols]){
    cout << "Macierz zawierajaca liczby zespolone:" << endl;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            print_cmp(&tab[i][j]);
            cout << " ";
        }
        cout << endl;
    }
}

cmp sum_matrix(int rows, int cols, cmp tab[][max_cols]){
    cmp temp{0.0f, 0.0f};
    /* alternatywnie
    temp.re = 0;
    temp.im = 0;
    */
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            temp.re += tab[i][j].re;
            temp.im += tab[i][j].im;
        }
    }
    return temp;
}

void sum_matrix(int rows, int cols, cmp tab[][max_cols], cmp* result){
    result->re = 0;
    (*result).im = 0;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            result->re += tab[i][j].re;
            (*result).im += tab[i][j].im;
        }
    }
}

float min_max(int cols, cmp* tab, float* max){
    cmp temp; //alternatywnie = tab[0];
    temp.re = tab[0].re; //->min
    temp.im = tab[0].im; //->max
    for(int i = 1; i < cols; ++i){
        if(temp.re > tab[i].re) temp.re = tab[i].re;
        if(temp.im < tab[i].im) temp.im = tab[i].im;
    }
    *max = temp.im;
    return temp.re;
}

void merge_vectors(int cols, const cmp* v1, const cmp* v2, cmp* result){
    //re max
    //im min
    for(int i = 0; i < cols; ++i){
        result[i].re = (v1[i].re > v2[i].re? v1[i].re : v2[i].re);
        result[i].im = (v1[i].im < v2[i].im? v1[i].im : v2[i].im);
    }
}

void print_cmp_vector(int cols, const cmp* v){
    cout << "Wypis wektora liczb zespolonych:" << endl;
    for(int i = 0; i < cols; ++i){
        cout << i + 1 << ": ";
        print_cmp(&v[i]);
        cout << endl;
    }
}

int main(){
    /*
    cmp tab[max_rows][max_cols];
    get_matrix(2, 2, tab);
    print_matrix(2, 2, tab);
    */
    /*
    const int max = 200;
    int suma = 0, n;
    cout << "Podaj liczbe: ";
    cin >> n;
    suma += n;
    while(max > suma){
        cout << "Podaj liczbe: ";
        cin >> n;
        suma += n;
    }
    cout << "Koniec, suma to: " << suma << endl;
    */
    //1 - 6, zliczać sume parzystych, póki ilość 6 suma oczek < 100 albo 50 zapisanych liczb
    /*
    int tab[50], i, suma = 0;
    for(i = 0; i < 50; ++i){
        cout << "Podaj liczbe z przedzialu 1 - 6: ";
        cin >> tab[i];
        suma += tab[i];
        if(suma > 100) break;
    }
    cout << "Suma wpisanych liczb to: " << suma
    << endl << "Ilosc wpisanych liczb: " << i << endl;
    int ilosc_6 = 0;
    suma = 0;
    for(int j = 0; j < i; ++j){
        if(tab[j] == 6) ++ilosc_6;

        if(tab[j] % 2 == 0) suma += tab[j];
    }

    cout << "Liczba 6: " << ilosc_6 << endl
    << "Suma parzystych: " << suma << endl;
    */


    return 0;
}