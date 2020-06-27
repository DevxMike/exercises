#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
/*
float fun(float* a1, float a2, float& a3){
    *a1 += a2; //a1 = 2, 2 += 1 a1 = 3
    a2 +=2; //a2 = 1, 1 += 2 -> a2 = 3
    a3 *= 2; //a3 = 3, 3 *= 2 a3 = 6
    return 2*a2 + 5; //2 * a2 + 5 = 2 * 3 + 5 = 6 + 5 = 11
}

float fun(float& z1, float* z2, float z3){
    z1 -= -2; // z1 = 2, 2 -= -2 -> z1 = 2 - -2 = 4 e = 4
    z3 *= z1; // z3 = 1, 1 *= 4 = 4 z3 = 1
    *z2 += 4; // z2 = 3, 3 += 4 = 7 z2 = 7
    return z3 + 2; //4 + 2 = 6
}

void fun(float tab[15]){

}

*/
/*
using t_str = struct{
    float b1;
    float b2[5];
};

using t_str1 = struct {
    float a1;
    int a2;
};

using t_str2 = struct {
    t_str1 b1;
    float b2;
};

*/
using t_str = struct{
    float s1[10];
    float s2;
};

float fun(float* a1, float a2, float& a3){
    *a1 += a2; //a1 = 4, a2 = 2, a1 += a2 -> 4 += 2 = 6
    a2 += 2; //a2 = 2, 2 += 2 = 4 
    a3 *= 2; // a3 = 3, 3 *= 2 = 6
    return 2 * a2 + 5; //2*4 + 5 = 8 + 5 = 13
}

int main(void){
    /*
        t_str y[5];
    y[4].s1[0] = 1;
    */
    /*
        float x = 4, y = 2, z = 3, q;
    q = fun(&x, y, z);
    std::cout << "6 x = " << x << ",2 y = " << y << ",6 z = " << z << ",13 q = " << q << std::endl; 
    */
    /*
    float x = 2, y = 1, z = 3, q;
    q = fun(&x, y, z);
    std::cout << "3 x = " << x << ",1 y = " << y << ",6 z = " << z << ",11 q = " << q << std::endl; 
    */

    
    /*
        t_str y[4];
        y[0]
        y[1]
        y[2] <- przedostatni
        y[3]
        y[2].s1[1] = 2;
    */
    /*
        float a[5][10];
    for(int i = 0; i < 10; ++i)
        a[1][i] = 0;
    */
    /*
    t_str x;
    t_str* pt = &x;

    pt->b2[4] = 1;
    */
    /*
    float e = 2, f = 3, g = 1, h;
    h = fun(e, &f, g);
    std::cout << "4 e = " << e << ", 7 f = " << f << ", 1 g = " << g << ", 6 h = " << h << std::endl; 
    */
    /*
        t_str2 x;
    x.b1.a1 = 0.0f;
    x.b1.a2 = 0;
    */
    /*
        float a[6][15];
    fun(a[1]);
    */
    /*
        float a[10][20]{0.0f};
    for(int i = 0; i < 10; ++i){
        //a[i][2] = 1;
        *(*(a + i) + 2) = 1;
    }
    */


   
    /* tablica 1D
    int* tab = new int[5];
    delete[] tab;
    */

    /* tablica 2D dynamicznie
    std::srand(std::time(NULL));
    int** tab = new int*[5];
    for(int i = 0; i < 5; ++i)
        tab[i] = new int[5];
    
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            tab[i][j] = rand() % 5;
        }
    }
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            std::cout << tab[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < 5; ++i)
        delete[] tab[i];
    delete[] tab;
    */
    return 0;
}