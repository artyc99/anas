#include <iostream>
#include <vector>

using namespace std;


void test(void (*func)()) {
    func();
}

void test_(void* func) {
    // reinterpret_cast - преобразовывает штуку в (func) в тип данных который ва <void (*)()>
    void (*func2)() = reinterpret_cast<void (*)()>(func); // void (*func2)() - переменная с типом указатель на функцию => func2 - указатель на функцию
    func2();
}

void test2() {
    cout<<"test2"<<endl;
}


bool clear() {
    cout<<"clear"<<endl;
    return 1;
    clear();
}


void listen(bool (*func)()){
    while (1) {
        bool success = func();
        if (success) {
            break;
        }
    }
}


class Internet {
    private:
    vector<bool(*)(Internet*, int)> handlers; // массив обработчиков bool (*handlers[])(); - bool тип возращаемого, * указатель, handlers - название массива(в котором у нас хранятся методы), () - указание что это вызываемый обьект(функция)
    bool running = 0;
    public:
    void register_handler(bool (*handler)(Internet*, int)) {
        this->handlers.push_back(handler);
    };
    void listen() {
        this->running = 1;
        while (this->running) {
            int var;
            cin>>var; // пункт меню от 1-9 ....
            cout<<endl;
            bool res = this->handlers[var](this, var); // вызывать нужный обработчик
            // итерируемся по всем хендлерам в поиске нужного и вызываем

            if (!res) {
                this->stop();
            }
        }
    };
    void stop() {
        this->running = 0;
    };
};

/*
Есть меню 5 пунктов на каждый пункт свой метод, и надо читать с консоли и выполнять нужный метод.
1) 5 пунктов
2) 5 методов для каждого пункта - 5 различных методов которые делают что-то(принт номер пункта)
3) читать с консоли - номер пункта
*/


bool process_user(Internet* internet, int user_count){
    cout<<"user_count: "<<user_count<<endl;
    return 1;
}

bool process_animal(Internet* internet, int animal_count){
    cout<<"animal_count: "<<animal_count<<endl;
    return 1;
}

bool process_book(Internet* internet, int book_count){
    cout<<"book_count: "<<book_count<<endl;
    return 1;
}

bool stop(Internet* e, int){
    cout<<"stoping internet";
    e->stop();
    return 1;
}



int main() {
    Internet internet;

    internet.register_handler(process_user);
    internet.register_handler(process_animal);
    internet.register_handler(process_book);
    internet.register_handler(process_user);
    internet.register_handler(process_animal);
    internet.register_handler(process_book);
    internet.register_handler(stop);
    
    cout<<"Enter 0-6: "<< endl;

    internet.listen();
    
    return 0;
}