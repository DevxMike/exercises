#include <iostream>

namespace{
    const int max_rows = 10, max_cols = 10;
}

void get_matrix(int rows, int cols, float matrix[][max_cols], char* name){
    std::cout << "Uzupelnianie macierzy " << name << "." << std::endl;
    for(int i = 0; i < rows; ++i){
        std::cout << "Wiersz " << i + 1 << ":" << std::endl;
        for(int j = 0; j < cols; ++j){
            std::cout << "Podaj wartosc dla kolumny " << j + 1 << ": ";
            std::cin >> matrix[i][j];
        }
    }
}

void print_matrix(int rows, int cols, float matrix[][max_cols], char* name){
    using std::cout;
    cout << "Zawartosc macierzy " << name << ":\n";
    auto original_fmt = cout.setf(std::ios_base::fixed,
        std::ios_base::floatfield);
    cout.precision(2);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            cout << matrix[i][j] << " ";
        }
        cout << std::endl;
    }
    cout.setf(original_fmt);
}

void multiply_vect(int cols, float* v1, float* v2, float* result){
    for(int i = 0; i < cols; ++i){
        result[i] = v1[i] * v2[i];
    }
}

float min_max(int cols, float* vector, float* max_val){
    float max, min;
    max = min = vector[0];
    for(int i = 1; i < cols; ++i){
        if(max < vector[i]) max = vector[i];
        if(min > vector[i]) min = vector[i];
    }
    *max_val = max;
    return min;
}

void print_vector(int cols, float* vector){
    for(int i = 0; i < cols; ++i)
        std::cout << vector[i] << " ";
    std::cout << std::endl;
}

void add_matrix(int rows, int cols, const float m1[][max_cols],
    const float m2[][max_cols], float result[][max_cols]){
    
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void multiply_matrix(int rows1, int cols1, int rows2, int cols2,
    const float m1[][max_cols], const float m2[][max_cols], 
    float result[][max_cols]){
    
    if(cols1 == rows2){
        float temp = 0.0f;

        for(int i = 0; i < rows1; ++i){
            for(int j = 0; j < cols2; ++j){
                for(int k = 0; k < rows2; ++k){
                    temp += m1[i][k] * m2[k][j]; 
                }
                result[i][j] = temp;
                temp = 0.0f;
            }
        }
    }
    else{
        result = NULL;
    }
}

int main(){
    //ex 1
    float tab[max_rows][max_cols], result[3];
    char name[] = "matrix";
    get_matrix(3, 3, tab, name);
    print_matrix(3, 3, tab, name);
    multiply_vect(3, tab[0], tab[1], result);
    std::cout << "Wynik mnozenia dwoch wektorow w macierzy: ";
    print_vector(3, result);
    float max;
    std::cout << "Min wartosc w wektorze: " << min_max(3, result, &max) << std::endl;
    std::cout << "Max wartosc w wektorze: " << max << std::endl; 
    std::cout << std::endl;
    //end

    //ex 2
    int m = 3, n = 3, p = 4;
    float m1[max_rows][max_cols], m2[max_rows][max_cols], 
        result_mat[max_rows][max_cols];
    get_matrix(m, n, m1, name);
    get_matrix(n, p, m2, name);
    std::cout << "Macierze do wymnozenia:\n";
    print_matrix(m, n, m1, name);
    std::cout << std::endl;
    print_matrix(n, p, m2, name);
    std::cout << std::endl;
    std::cout << "Wynik:\n";

    multiply_matrix(m, n, n, p, m1, m2, result_mat);
    print_matrix(m, p, result_mat, name);
    //end
    return 0;
}