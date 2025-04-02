#include<iostream>
using namespace std;
#include<stack>

class minimum_stack{
    stack<pair<int,int>> st;
    public:
        void push(int val){
            if(st.empty()){
                st.push({val,val});
            }
            else{
                st.push({val, min(val,st.top().second)});

            }
        }
        void pop(){
            if(st.empty()){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            int elem = st.top().first;
            cout<<"Popped Element: "<<elem<<endl;
            st.pop();
        }
        void getMin(){
            if(st.empty()){
                cout<<"Stack is empty"<<endl;
                return;
            }
            cout<<"Minimum is:"<<st.top().second<<endl;
        }   
        void getTop(){
            if(st.empty()){
                cout<<"Stack Underflow"<<endl;
                return;
            }
            else{
                cout<<"Top Element is: "<<st.top().first<<endl;
            }
        }
        
};

int main(){
    minimum_stack min_stack;
    min_stack.push(10);
    min_stack.push(20);
    min_stack.push(5);
    min_stack.getTop();
    min_stack.getMin();
    min_stack.pop();
    min_stack.getMin();
    min_stack.getTop();
    min_stack.pop();
    min_stack.getMin();
    min_stack.pop();
    min_stack.getMin();
}