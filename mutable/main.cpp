#include <iostream>
#include <vector>


using namespace std;

/*
    Изменяемость обьектов дает нам гарантии того что обьект не будет модифицирован или будет если стоит пометка о модификации
    const/mutable
*/

class IAnimal {
    public:
    virtual void voice() = 0;
};

class Lion: public IAnimal {
    mutable int age;
    public:
    Lion(){};
    void voice() {
        this->age = 5;
        cout<<"Im a Lion!"<<endl;
    };
};

class Dog: public IAnimal {
    mutable int age;
    public:
    virtual void voice() override {
        this->age = 5;
        cout<<"Im a Dog! "<<"age: "<<age<<endl;
    };
};

class BullDog: public Dog {
    mutable int age;
};

void makeSomeNoze(IAnimal* animal) {
    animal->voice();
};

// void makeSomeNozeVectorize(vector<IAnimal*> zoo) {
    
// };

int main() {
    // IAnimal* an1 = new BullDog();

    // makeSomeNoze(an1);

    vector<IAnimal*> zoo = {
        new Dog(),
        new Lion(),
        new Lion(),
        new Lion(),
        new Lion(),
        new Lion(),
    };

    vector<int> integers = {1,2,3,4,5};
    integers.push_back(6);
    integers.push_back(8);
    cout<<"vector counter: "<<integers.size()<<" vector capacity: "<<integers.capacity()<<endl;

    cout<<"Test!"<<endl;
}
