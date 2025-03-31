#include <iostream>


using namespace std;

// Все что с * распаполагается в куче(куча делится со всеми функциями)/ Все что без * распаполагается в стеке(стек не делится со всеми функциями) -> Стек живет в {}
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
// Конец массива
// какой массив?
// входной? Нет -> нам надо создать массив, который будет изменяться -> При создании масиива, под скольколько элементов выделять память? ->
// -> Поскольку нас просят именно ДОБАВИТЬ, значит нам нельзя потерять старые значения(исходного масива)


int main() {
    int numbers_count = 5;
    // int mass[numbers_count]{1,2,3,4,5}; // массивы бывают статитическими + динамика // статика лежит в стеке

    int** numbers {new int* {new int[numbers_count]{1,2,3,4,5}}}; // Динамический массив // new это бронь места // статика лежит в куча
    // int* numbers2 = new int[numbers_count]; // Второй способ
    // *_(перееменная) - разименовывает(идет в значение переменной берет оттуда адрес и обращается по нему)
    // &_(перееменная) - берет адрес ячейки в которой лежит переменная

    cout<<"massive init: "<< numbers << endl;
    cout<<"massive init: "<< *numbers << endl;
    cout<<"massive init: "<< **numbers << endl;

    append(numbers, &numbers_count, 6);
    int* new_numbers = *numbers;
    for (int i=0; i<numbers_count; i++) {
        cout<<"mass elem: "<<*(new_numbers+i) << " elem_index: " << i << endl;
    }

    int  arr[6] = {5,4,3,2,1,0};

    int len = (*numbers + 1) - *numbers;
    
    cout<<"massive len: "<< len << endl;
    cout<<"massive res: "<< numbers << endl;
    cout<<"massive res: "<< *numbers << endl;
    cout<<"massive fin: "<< &*numbers+1 << endl;
    cout<<"massive res: "<< **numbers << endl;
    cout<<numbers<< " sizeof: "<< sizeof(numbers)<<endl;
    cout<<"sizeof: "<< sizeof(int)<<endl;

    return 0;
}

// Стек и куча
// Стек располагается в быстрой памяти и имеет oграничение для исполнения
// Куча располагается в оперативной памяти и имеет только физическое ограничение(сколько оперативки в компе столько и можем использовать)... по окончанию синий экран
// Стек ограничевается для сохранения быстрой доступности, а также скорости подключения к исполняемому коду.




/*
main:
    massive init: 0x16d85701a10 - указатель на массив он живет в стеке main
    massive init: 0x16d85701a30 - указатель на первый элемент, он живет в куче
append(происходит подмена исходного массива на который передается указатель в метод): append(numbers(сюда кладем результат), &numbers_count, 6);
    massive вход: 0x16d85701a10 - указатель на массив он живет в стеке append
    massive вход: 0x16d85701a30 - указатель на первый элемент, он живет в куче
    
    massive mas: 0x16d85701a10 - указатель на массив он живет в стеке append
    massive mas: 0x16d85701a50 - мы положили в кучу чтобы даменить указатель на первый элемент исходного массива
*/