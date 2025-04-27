public:
    Vector(int** mas, int count);
    ~Vector(){
        delete (*mas);
    };
    
    void append(int a);
    int pop();
    int pop(int in);

    void print();