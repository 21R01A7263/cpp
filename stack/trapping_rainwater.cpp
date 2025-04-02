#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        vector<int> prefixMax(vector<int> &arr){
            int n = arr.size();
            vector<int> prefix(n);
            prefix[0] = arr[0];
            for(int i=1;i<n;i++){
                prefix[i] = max(prefix[i-1],arr[i]);
            }
            return prefix;
        }
        vector<int> suffixMax(vector<int> &arr){
            int n = arr.size();
            vector<int> suffix(n);
            suffix[n-1] = arr[n-1];
            for(int i=n-2;i>=0;i--){
                suffix[i] = max(suffix[i+1],arr[i]);
            }
            return suffix;
        }
        int trappingRainwater(vector<int> &arr){
            int n = arr.size();
            if(n<=2){
                return 0;
            }
            int trapped = 0;
            vector<int> prefixMaximum = prefixMax(arr);
            vector<int> suffixMaximum = suffixMax(arr);
            
            for(int i=1;i<n-1;i++){
                int left_max = prefixMaximum[i-1];
                int right_max = suffixMaximum[i+1];
                
                
                if(arr[i]<min(left_max, right_max)){
                    trapped += min(left_max, right_max) - arr[i];
                }
            }
            return trapped;
        }
};

int main(){
    Solution s;
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = s.trappingRainwater(arr);
    cout<<"Trapped Rainwater: "<<result<<endl;
    return 0;
}