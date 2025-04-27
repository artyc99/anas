#include <iostream>

using namespace std;

class Vector {
    private:
    int** mas;
    int count;
    
    public:
    Vector(int** mas, int count);
    ~Vector(){
        delete (*mas);
    };
    
    void append(int a);
    int pop();
    int pop(int in);

    void print();
};

Vector::Vector(int** mas, int count) {
    this->mas=mas;
    this->count=count;
};

void Vector::append(int a){
    int* last_mass = *(this->mas);
    int* mass {new int[(this->count)+1]}; // выделяем независимые ячейки для наших данных
    for (int i=0;i<this->count;i++){
        *(mass+i)=*(last_mass+i);
    }
    *(mass+this->count)=a;
    *mas = mass;
    this->count++;
};

int Vector::pop(){
    int* last_mass = *(this->mas);
    int* mass {new int[(this->count)-1]}; // выделяем независимые ячейки для наших данных
    for (int i=0;i<this->count-1;i++){
        *(mass+i)=*(last_mass+i);
    }
    *this->mas = mass;
    this->count--;
    return *(*this->mas+count-1);
};

int Vector::pop(int in){
    int* last_mass = *(this->mas);
    int* mass {new int[(this->count)-1]}; // выделяем независимые ячейки для наших данных
    for (int i=0;i<this->count;i++){
        if (i>=in) {
            *(mass+i)=*(last_mass+i+1);
        } else {
            *(mass+i)=*(last_mass+i);
        }
    }
    *this->mas = mass;
    this->count--;
    
    return *(*this->mas+in);
};

void Vector::print(){
    for (int i=0; i<this->count; i++) {
        cout<<"mass elem: "<<*((*this->mas)+i) << " elem index: "<< i << endl;
      }
};

/*
Свой динамический массив. содержит указатель на массив, длинну(количество элементов), 
капасити(на сколько элементов выделено памяти). append, pop. pprint
*/

int main(){
    int** mass {new int* {new int[5]{1,2,3,4,5}}};

    Vector vect(mass, 5);

    // vect.append(6);
    // vect.print();

    // vect.pop();
    // vect.print();

    // vect.pop(0);
    // vect.print();

    // vect.~Vector();
    // vect.print();
};
