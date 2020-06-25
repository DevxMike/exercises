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
    if(n == 0) return 1;
    else return n*factorial_recursion(n - 1);
}

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
    //ex 1
    float r3[3];
    r3[0] = sum(5);//function test
    sum(5, r3[1]);
    sum(5, &r3[2]);
    for(auto x : r3){
        cout << "Result: " << x << endl; //print
    }
    //end
    
    //ex2
    long long fac4[4];
    fac4[0] = factorial_iter(5); //function test
    factorial_iter(5, fac4[1]);
    factorial_iter(5, &fac4[2]);
    fac4[3] = factorial_recursion(5);
    for(auto x : fac4){
        cout << "Factorial: " << x << endl; //print
    }
    //end

    //ex3
    int n = 3; 
    float vector[n];
    char name[] = "Vector";
    get_vector(n, vector, name);
    print_vector(n, vector, name);
    float result_vector[n];
    char result_name[] = "Result vector: ";
    multiply_vector(n, vector, vector, result_vector);
    print_vector(n, result_vector, result_name);
    //end
    
    return 0;
}