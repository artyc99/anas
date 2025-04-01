#include <iostream>

using namespace std;

// pop метод который возвращает последний элемент массива и уменьшает его на 1

int iz(int** mass, int* n) // void_stack: mass=0x2c34dffcc4
{
    return *mass[*n-1];
}

int pop(int** mass, int* n) {
  int *mas2{new int [(*n)-1]};

  int value;
  value = (*mass)[(*n)-1];

  for (int i=0; i < (*n)-1; i++){
    cout<<(*mass)[i]<<"jjjj"<<endl;
    mas2[i]=(*mass)[i];
    cout<<mas2[i]<<"ff"<<endl;
  }
  (*mass)=mas2;
  (*n)--;

  return value;
}

void append(int** mas, int* num, int c) { // mas[5]{.,.,.,.,.} -> mas = *на первый элемент....обработка -> mass[6] -> mass = *первый элемент 
    cout<<"massive mas: "<< mas << endl;
    cout<<"massive mas: "<< *mas << endl;
    cout<<"massive mas: "<< **mas << endl;

    // Добавить элемент в конец массива
    int* last_mass = *mas;
    int* mass {new int[(*num)+1]}; // выделяем независимые ячейки для наших данных
    for (int i=0;i<*num;i++){
        *(mass+i)=*(last_mass+i);
    }
    *(mass+*num)=c;
    *mas = mass;
    (*num)++;

    cout<<"massive mas: "<< mas << endl;
    cout<<"massive mas: "<< *mas << endl;
    cout<<"massive mas: "<< **mas << endl;
}

int main(){ // main_stack: mas=0x2c34dffcc4;
  int numbers_count = 5;
  int** numbers {new int* {new int[numbers_count]{1,2,3,4,5}}};
//   cout<<mas<<endl;
//   cout<<&mas<<endl; // &mas == mas == 0x2c34dffcc4 => *
//   cout<<"massPtr: "<<massPtr<<endl;
//   cout<<"&massPtr: "<<&massPtr<<endl; // **
  
  cout<<"mass ptr: "<<&numbers[3]<<endl; // изменилось
  cout<<"mass ptr: "<<sizeof(*numbers)<<endl; // изменилось
  int retItem;
  retItem = pop(numbers, &numbers_count); // main_stack -> void_stack | main_stack <- void_stack
  append(numbers, &numbers_count, 6);
  cout<<"mass ptr: "<<numbers[3]<<endl; // изменилось
  // cout<<"mass ptr: "<<sizeof(*numbers)<<endl; // изменилось
  for (int i=0; i<numbers_count + 1; i++) {
    cout<<"mass elem: "<<*((*numbers)+i) << " elem_index: " << i << endl;
  }
  cout<<"Poped item: "<< retItem << endl;

}
// еще один указатель
// Общая куча: 0x...=5