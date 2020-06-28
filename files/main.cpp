#include <iostream>
#include <fstream>
using simple = struct{
    int liczba;
    char napis[50];
};

int main(){
    using namespace std;
    simple temp{ 1 , "Tescik"};
    ofstream file1, file2;
    file1.open("tekstowy.txt", 
        ios_base::out);
    file2.open("binarny.dat", 
        ios_base::out | ios_base::binary);
    file1 << temp.liczba << endl << temp.napis;
    file2.write((char*)&temp, sizeof(simple));
    file1.close();
    file2.close();
    ifstream fin1, fin2;
    fin1.open("tekstowy.txt",
        ios_base::in);
    fin2.open("binarny.dat",
        ios_base::in | ios_base::binary);
    if(fin1.is_open() && fin2.is_open()){
        simple r1, r2;
        fin1 >> r1.liczba;
        fin1.get();
        fin1 >> r1.napis;
        cout << "tekstowy: " << endl << r1.liczba << " " << r1.napis << endl << endl;
        fin2.read((char*)&r2, sizeof(simple));
        cout << "binarny: " << endl << r2.liczba << " " << r2.napis << endl << endl;
        fin1.close();
        fin2.close();
    }   
    return 0;
}