#include<iostream>
using namespace std;

class queue{
    int start, end;
    int size;
    int *arr;
    public: 
        queue(){
            start=-1;
            end=-1;
            size=10;
            arr = new int[size];
        }
        void push(int x){
            if(isFull()){
                cout<<"Queue Overflow"<<endl;
                return;
            }
            if(isEmpty()){
                start=0;
                end=0;
            }
            else{
                end = (end+1)%size;
            }
            arr[end] = x;
            
        }
        int pop(){
            if(isEmpty()){
                cout<<"Queue underflow"<<endl;
                return -1;
            }
            int elem = arr[start];
            if(start==end){
                start=-1;
                end=-1;
            }
            else{
                start = (start+1)%size;
            }
            return elem;
        }
        int getFront(){
            if(isEmpty()){
                return -1;
            }
            return arr[start];
        }
        int getBack(){
            if(isEmpty()){
                return -1;
            }
            return arr[end];

        }
        int getSize(){
            if(isEmpty()){
                return 0;
            }
            if(end>=start){
                return end-start+1;
            }
            return size-(start-end-1);
        }
        bool isEmpty(){
            return (start==-1 && end==-1);
        }
        bool isFull(){
            return ((end+1)%size==start);
        }


};

int main(){
    
}