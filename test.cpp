#include <iostream>
using namespace std;

void Izm(int ch){

    if (ch - 50 >= 0){
        if ((ch-50)<49){
            cout<<"L";
            Izm(int (ch-50));
        }

        else{
            cout<<"L";
            Izm(int (ch-50));
        }
    }
    else if(ch==49){
        cout<<"X"<<"L";
    }
    else if (ch - 10 >= 0){
        if ((ch-10)<9){
            cout<<"X";
            Izm(int (ch-10));
        }

        else{
            cout<<"X";
            Izm(int (ch-10));
        }
    }
    else if(ch==9){
        cout<<"I"<<"X";
    }
    else if (ch==4){
        cout<<"I"<<"V";
    }
    else if (ch - 5>=0){
        if (ch-5<4){
            cout<<"V";
            Izm(int (ch-5));
        }
        else{
            cout<<"V";
            Izm(int (ch-5));
        }
    }
    else
    {
        for(int i=0;i<ch;i++){
            cout<<"I";
        }
    }
}

int main() {
    Izm(41);
}