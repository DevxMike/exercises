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

void multiply_matrix_cols(int n, int m, const float m1[][max_cols], 
    const float m2[][max_cols], float* result){
    
    float f[max_rows], l[max_rows];
    for(int i = 0; i < n; ++i){
        f[i] = m1[i][0];
        l[i] = m2[i][m - 1];    
    }
    multiply_vect(m, f, l, result);
}

float min_max(int n, int m, const float m1[][max_cols],
    float* max){
    
    float temp[max_rows];
    for(int i = 0; i < n; ++i){
        temp[i] = m1[i][m - 1];
    }
    return min_max(m, temp, max);
}

void max_min_vals(int n, int m, float m1[][max_cols],
    float vector_min[max_rows], float vector_max[max_rows]){
    float temp_max;    

    for(int i = 0; i < n; ++i){ 
        vector_min[i] = min_max(m, m1[i],&temp_max);
        vector_max[i] = temp_max;
    }
}

void max_min_cols(int n, int m, float m1[][max_cols], 
    float vector_min[max_cols], float vector_max[max_cols]){
    
    float temp_vect[max_rows], max;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            temp_vect[j] = m1[j][i];
        }
        vector_min[i] = min_max(m, temp_vect, &max);
        vector_max[i] = max;
    }
}
int main(){
    using namespace std;
    /*
    cout << "Podaj rozmiary macierzy A:\n";
    int m, n;
    cin >> m >> n;
    float m1[max_rows][max_cols];
    char name[] = "matrix";
    get_matrix(m, n, m1, name);
    print_matrix(m, n, m1, name);
    float v1[max_cols];
    multiply_vect(n, m1[0], m1[m - 1], v1);
    print_vector(n, v1);
    multiply_matrix_cols(m, n, m1, m1, v1);
    print_vector(n, v1);
    float max;
    cout << "Minimum: " << min_max(n, m1[m - 1], &max) << endl;
    cout << "Maksimum: " << max << endl; 

    cout << "Minimum w ostatniej kolumnie: " << min_max(m, n, m1, &max) << endl;
    cout << "Maksimum w ostatniej kolumnie: " << max << endl;

    float max_vect[max_rows], min_vect[max_rows];
    max_min_vals(m, n, m1, min_vect, max_vect);
    cout << "Minimalne: ";
    print_vector(m, min_vect);
    cout << endl << "Maksymalne: " << endl;
    print_vector(m, max_vect);

    max_min_cols(m, n, m1, min_vect, max_vect);

    cout << "\nMinimalne: ";
    print_vector(m, min_vect);
    cout << endl << "Maksymalne: " << endl;
    print_vector(m, max_vect);
    */
    return 0;
}