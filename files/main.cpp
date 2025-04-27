#include <iostream>
#include <string>
#include <fstream> // fstream, ifstream(чтение), ofstream(запись)

using namespace std;

class FileManager {
    public:
    string path;
    fstream file;
    bool open=0;

    bool is_open(){
        return this->open;
    };

    string read(){
        string variable;
        this->file >> variable;
        return variable;
    };

    void write(string data_in){
        this->file << data_in;
    };

    void close(){
        this->file.close();
    };

    FileManager(string path) {
        this->path=path;
        this->file.open(path, ios::in|ios::out);
        this->open=1;
    };
    ~FileManager(){this->file.close();};
};

struct Persona {
    int age;
    int height;

    string toString(){
        string res;
        res += "age: ";
        res += to_string(this->age);
        res += " height: ";
        res += to_string(this->height);

        return res;
    };

    void fromString(string data){
        int splitter_index;
        splitter_index = data.find(':');
        cout<<"index: "<< splitter_index << endl;

        string substring;
        substring = data.substr(splitter_index+2, data.length()); 
        cout<<"age: "<< substring << endl;
        cout<<"data: "<< data << endl;
    };
};

int main() {
    // FileManager file("test50");
    // file.close();

    Persona p1{10, 20};

    fstream file2;
    file2.open("objectDump.dat", ios::out|ios::binary|ios::in);
    file2<<p1.toString();
    file2.seekg(0);
    string res;
    cout<<res<<endl;
    file2 >> res;

    Persona p2;
    p2.fromString(res);
    
    // ifstream file("test25"); // Не понятно как происходит запись в бинорные файды
    // if (!file.is_open()) {
    //     cout<<"Not found file"<<endl;
    // }

    // fstream file2;
    // file2.open("test25", ios::out);
    // if (file2.is_open()) {
    //     file2 << 1000000 << endl;
    //     string varName;
    //     // getline(file2, varName);
    //     file.seekg(0);
    //     file >> varName;
    //     file2.close();
    //     cout << "Finish writing file: " << varName << endl;
    // } else {
    //     cout << "Erorr openning file" << endl;
    // }

    return 0;
}

/*
ios::in	Чтение
ios::out	Запись
ios::app	Добавление в конец файла
ios::trunc	Очистка содержимого при открытии
ios::binary	Бинарный режим
*/