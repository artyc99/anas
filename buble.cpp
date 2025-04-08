#include <iostream>

using namespace std;

void sortMass(int* mass,int n) {
    int t;
    
    for(int j=0;j<n;j++) { // 2 цикла которые проходят n элементов -> n^2 -> O(n^2) - нотация сложности
        cout<<"DEBUG target elem index: "<< j << " elem: " << mass[j] << endl;
        for (int i=0; i<n-1; i++) {
            cout<<"DEBUG elem index: "<< i << " elem: " << mass[i] << endl;
            cout<<"DEBUG elem index: "<< i+1 << " elem: " << mass[i+1] << endl;
            

            if (mass[i] < mass[i+1]) {
                t = mass[i];
                mass[i] = mass[i+1];
                mass[i+1] = t;

                cout<<"SWAP: "<<i<<" <-> "<<i+1<<endl;
            }

            cout<<endl;
        }
    }
}

// Сортировку пузырик массива , ответ положить в исходный массив
// 1) Берем элемент сравниваем со следующим, потом если первый больше меняем местами
// 2) Переходим к следующему элементу и повторяем (1) до тех пор пока не пройдем все элементы
// тесты:


int main() {
    int num=5;
    int* mas {new int[5]{5,2,4,1,3}};

    sortMass(mas, num);

     for (int i=0; i<num; i++){
        cout<<"elem index: "<< i << " elem: " << *(mas+i) << endl;
    }
}