// main.cpp   123
//import Vector; // get Vector's interface
// branch hotfox
#include <iostream>
#include <stdexcept>

// master test   change_branch
///import <iostream>;

///#include <windows.h>
//#include "vector.h"
#include  "kmk_vector.h"

//double sqrt_sum(Vector<double>& v)
//{
//    double sum = 0;
//    for (int i = 0; i != v.size(); ++i)
//        sum += std::sqrt(v[i]); // sum of square roots
//    return sum;
//}
using  namespace std;
struct tableEntry {
    int symvol;
    char type; // C-константа L- метки V - переменные
    int location; // 0-999
};

int main()
{
///    SetConsoleCP(1251);
///    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");  // дает русские буквы в консоле
    // кодировка
//    Vector<double> v(3.3);//{2.1,2,3};
    try {
//        Vector<double> v1(3);
//        Vector<double> v={2.1,2,3};
//        Vector<tableEntry> v1(3);
        Kmk_Vector<tableEntry> v1; // (1);
        tableEntry te;
        te.symvol = 100;
        te.type = 'L';
        te.location = 900;
        v1.push_back(te);
       
        te.symvol = 200;
        te.type = 'L';
        te.location = 900;
        v1.push_back(te);

        for (Kmk_Vector<tableEntry>::iterator iter = v1.begin(); iter != v1.end(); ++iter)
            std::cout << iter->symvol << " type " << iter->type << iter->location << '\n';

 ///       Kmk_Vector<tableEntry>::iterator it;// = symvolTable.begin();

//        if (CompareVec<double>(v1, v))  cout << "вектора совпадают";
//        else cout << "no";
    }
    catch (std::length_error& err) {
    //    // ... handle negative size ...
        std::cout << "»сключение !\n" << err.what() ;
        return 1;
    }
    std::cout << "ѕривет!\n"; // << sqrt_sum(v);
}
