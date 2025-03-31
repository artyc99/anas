#include <iostream>


using namespace std;


void numberic_count(int* mass, int n, int* res){
    // Считаем четные и не четные и кладем результат в res[2]{чет, нечет}
    
    *res=0;
    *(res+1)=0;
    for(int i=0;i<n;i++)
    {
        // cout<<"DEBUG "<< *(mass+i)%2 << " n: "<< n <<endl;
        if (*(mass+i)%2==0) { // if (bool) // if (1=0)
            (*res)++;
        }
        else {
            (*(res+1))++; // (res+1)++ а потом от него берем указатель
            // * преобразование типа на подобии int()
        }
    }
}


int main() {
    int nimbers_count = 5;
    int mass[nimbers_count]{1,2,3,4,5}; // массивы бывают статитическими + динамика
    int res[2]; // массивы бывают статитическими + динамика
    // Массив представляет из себя укузатель на первый элемент 1, 2, 3, 4, 5

    numberic_count(mass, nimbers_count, res); // 2, 3

    cout<<res<<" res"<<endl;
    cout<<*res<<" first elem"<<endl;
    cout<<*(res+1)<<" second elem"<<endl;
    
    return 0;
}

// int p{25}; // 0x99d3fff774          1) p=25
// int* pn{&p}; // 0x99d3fff774        2) *pn=25

// int* nn{pn}; // 0x99d3fff770        3) nn=*{25}

// p=66;
// // *pn=p;

// cout<< pn << " pn" <<endl;
// cout<< &nn << " &nn" <<endl;
// cout<< &p << " &p" <<endl;
// cout<< *nn << " nn" <<endl;
// cout<< p << " p" <<endl;