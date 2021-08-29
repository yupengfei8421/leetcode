#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        for(int i = 0; i < arr.size(); i ++){
            int left = i + 1, right = arr.size() - i,
                left_even = (left + 1) / 2, right_even = (right + 1) / 2,
                left_odd = left / 2, right_odd = right / 2;
            res += (left_even * right_even + left_odd * right_odd) * arr[i];
        }
        return res;
    }
    
};
int main(){
    vector<int> test;
    Solution solution;
    cout<<"test="<<endl;
    int i;
    while(cin>>i){
        test.push_back(i);
    }
    cout<<"answer="<<solution.sumOddLengthSubarrays(test)<<endl;
}