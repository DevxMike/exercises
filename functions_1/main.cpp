#include <iostream>

float sum(int n){
    float sum = 0.0f;
    for(int i = 1; i <= n; ++i){
        sum += 1.0f / (i + 1);
    }
    return sum;
}
void sum(int n, float& result){
    result = 0.0f;
    for(int i = 1; i <= n; ++i){
        result += 1.0f / (i + 1);
    }
}
void sum(int n, float* result){
    *result = 0.0f;
    for(int i = 1; i <= n; ++i){
        *result += 1.0f / (i + 1);
    }
}

long long factorial_iter(int n){
    long long result = 1;
    for(int i = 1; i <= n; ++i){
        result *= i;
    } 
    return result;
}

void factorial_iter(int n, long long& result){
    result = 1;
    for(int i = 1; i <= n; ++i){
        result *= i;
    } 
}

void factorial_iter(int n, long long* result){
    *result = 1;
    for(int i = 1; i <= n; ++i){
        *result *= i;
    }
}

long long factorial_recursion(int n){
    std::cout << n << std::endl;
    if(n == 0) return 1;
    else {
        std::cout << n << std::endl;
        return n*factorial_recursion(n - 1);
    }
    
}
/*
    n = 5
    5 * funkcja(5 - 1);

    n = 4
    5 * 4 * funkcja(4 - 1)
    .
    .
    .
    5*4*3*2*1*1
*/
void get_vector(int n, float vector[], char* name){
    for(int i = 0; i < n; ++i){
        std::cout << "Podaj " << name <<"[" << i+1 <<"]: ";
        std::cin >> vector[i];
    }
}

void print_vector(int n, float vector[], char* name){
    for(int i = 0; i < n; ++i){
        std::cout << "Skladowa " << name 
        <<"[" << i+1 <<"]: " << vector[i] << std::endl;
    }
}

void multiply_vector(int n, const float v1[], const float v2[], float result[]){
    for(int i = 0; i < n; ++i){
        result[i] = v1[i] * v2[i];
    }
}



int main(){
    using std::cout;
    using std::endl;
    using std::cin;

    int max = 10;

    cout << "Podaj wielkosc wektora: ";
    int n;
    cin >> n; 
    if(n>0 && n<=10){
        float vector[max];
        char name[] = "wektor";
        get_vector(n, vector, name);
        print_vector(n, vector, name);
        float result[max];
        multiply_vector(n, vector, vector, result);
        print_vector(n, result, name);
    }else{
        cout << "Bledna wielkosc wektora.\n";
    }
    
    
    
    return 0;
}