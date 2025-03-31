#include <iostream>

using namespace std;

// pop метод который возвращает последний элемент массива и уменьшает его на 1

int iz(int** mass, int* n) // void_stack: mass=0x2c34dffcc4
{
    return *mass[*n-1];
}

int main(){ // main_stack: mas=0x2c34dffcc4;
  int mas[]{1,2,3};
  int count = 3;
//   cout<<mas<<endl;
//   cout<<&mas<<endl; // &mas == mas == 0x2c34dffcc4 => *

  int* massPtr;
  massPtr = mas;
//   cout<<"massPtr: "<<massPtr<<endl;
//   cout<<"&massPtr: "<<&massPtr<<endl; // **

  popItem = iz(&massPtr, &count); // main_stack -> void_stack | main_stack <- void_stack
  cout<<*massPtr<<endl; // изменилось
  cout<<&massPtr<<endl; // сохранилось
}
// еще один указатель
// Общая куча: 0x...=5