#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> prevSmallerElement(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> pse(n, -1);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                pse[i] = -1;
            }
            else
            {
                pse[i] = st.top();
            }
            st.push(nums[i]);
        }
        return pse;
    }    
};

int main(){
    Solution s;
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> result = s.prevSmallerElement(nums);
    cout << "Previous Smaller Element: ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
