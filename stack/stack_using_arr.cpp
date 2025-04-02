#include<iostream>
using namespace std;


class stack{

    int size;
    int top;
    int *arr;
    public:
        stack(){
            top=-1;
            size=10;
            arr = new int[size];
        }

        void push(int x){
            if(top==size-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            top++;
            arr[top] = x;
        }
        int pop(){
            if(top==-1){
                return -1;
            }
            int elem = arr[top];
            top--;
            return elem;
        }
        int getTop(){
            if(top==-1){
                return -1;
            }
            int elem = arr[top];
            return elem;
        }
        int getSize(){
            return top+1;
        }
};

int main(){
    stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.getTop()<<endl;
    s.pop();
    cout<<s.getSize();
    return 0;
};