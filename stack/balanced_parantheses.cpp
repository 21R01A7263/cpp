#include <iostream>
#include <stack>   
#include <string>  
#include <vector>  

using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (char it : s) 
    {        
        if (it == '(' || it == '{' || it == '[')
        {
            st.push(it);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            char ch = st.top();
            st.pop(); 

            if ((it == ')' && ch == '(') || 
                (it == '}' && ch == '{') || 
                (it == ']' && ch == '['))  
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string s = "()[{}()]";
    if (isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    string s2 = "([)]"; 
    if (isValid(s2))
        cout << "True" << endl;
    else
        cout << "False" << endl;

     string s3 = "{[]}";
    if (isValid(s3))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    string s4 = "(";
     if (isValid(s4))
        cout << "True" << endl;
    else
        cout << "False" << endl;

     string s5 = ")";
     if (isValid(s5))
        cout << "True" << endl;
    else
        cout << "False" << endl;


    return 0; 
}