#include <iostream>
#include <vector>

using namespace std;

/*
nxn - n(количесво узлов)... по x идут узлы, по y идат узлы а в пересечениях ставится либо 1 либо 0... это матрица связностей

  0, 1, 2, 3
0 1  6  0  0
1 0  1  0  1
2 0  0  1  0
3 0  1  0  1

  0, 1, 2, 3
0 1  1  0  0
1 1  1  0  1
2 0  0  0  0
3 0  1  0  0
*/


//   0, 1, 2, 3
// 0 1  6  0  0
// 1 0  1  0  1
// 2 0  0  1  0
// 3 0  1  0  1
class Node {
    public:
    int index;
    vector<Node*> nextNodes; // массив [] мы в ноде 0... у нас есть дорога в 0 и в 1 -> следующие ноды [0, 1]
    vector<Node*> lastNodes; // массив [] мы в ноде 0... у нас есть дорога в 0 и в 1 -> предыдущие ноды [0,1]
    // Поиск.
    // Добавление следующей ноды в граф
    void add(Node* node);
    void print();
};

void Node::add(Node* node) {
    this->nextNodes.push_back(node); // msc.nextNode += sp
    node->lastNodes.push_back(this); // sp.lastNodes += msc
}

void Node::print() {
    for (int i=0; i<this->nextNodes.size(); i++) {
        cout<<this->index<<" -> "<<this->nextNodes[i]->index<<endl;
    }
    for (int i=0; i<this->lastNodes.size(); i++) {
        cout<<this->index<<" <- "<<this->lastNodes[i]->index<<endl;
    }
}

int main() {
    Node* moscow = new Node{index: 0};

    Node* sp = new Node{index: 1};
    (*moscow).add(sp); // msc -> sp /// msk узнает о дороге до питера

    (*sp).add(moscow); // sp -> msc /// sp узнает о дороге до москвы ... но москва не вкурсе

    moscow->print();
    sp->print();
};
