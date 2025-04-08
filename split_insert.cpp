#include <iostream>

using namespace std;

// Алгоритм сортировки
// Суть:
// Поиск максимального и вставка в конец n for, max среди значений n-i

int maxM(int* mass, int n) {
    int maxInd=0;
    for (int i=1;i<n;i++) {
        cout<<"DEBUG MAX elem index: "<< i << " elem: " << mass[i] << endl;
        if (mass[i] > mass[maxInd]) {
            maxInd=i;
        }
    }
    
    return maxInd;
}

void sortMass(int* mass,int n) {
    int maxInd;
    int t;
    for (int i=n-1;i>=0;i--) {
        cout<<"DEBUG elem index: "<< i << " elem: " << mass[i] << endl;
        cout<<"DEBUG elem index: "<< i+1 << " elem: " << mass[i+1] << endl;

        maxInd=maxM(mass, i+1);
        t=mass[i];
        mass[i]=mass[maxInd];
        mass[maxInd]=t;

        cout<<endl;
    }
}

int main() {
    int num=5;
    int* mas {new int[5]{5,2,4,3,1}};

    sortMass(mas, num);

    for (int i=0; i<num; i++){
        cout<<"elem index: "<< i << " elem: " << *(mas+i) << endl;
    }
}