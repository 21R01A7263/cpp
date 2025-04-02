#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution{
    public:
        vector<int> nextGreaterElement(vector<int> &nums){
            int n = nums.size();
            vector<int> nge(n, -1);
            stack<int> st;
            for(int i=n-1;i>=0;i--){
                while(!st.empty() &&st.top()<=nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    nge[i] = -1;
                }
                else{
                    nge[i] = st.top();
                }
                st.push(nums[i]);

            }
            return nge;
        }
};

int main(){
    Solution s;
    vector<int> nums = {4,5,2,10,8};
    vector<int> result = s.nextGreaterElement(nums);
    cout<<"Next Greater Element: ";
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}