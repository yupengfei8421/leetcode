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

// 关键就是，如何计算一个数字在多少个奇数长度的数组中出现过？

// 对于一个数字，它所在的数组，可以在它前面再选择 0, 1, 2, ... 个数字，一共有 left = i + 1 个选择；

// 可以在它后面再选择 0, 1, 2, ... 个数字，一共有 right = n - i 个选择。

// 如果在前面选择了偶数个数字，那么在后面，也必须选择偶数个数字，这样加上它自身，才构成奇数长度的数组；

// 如果在前面选择了奇数个数字，那么在后面，也必须选择奇数个数字，这样加上它自身，才构成奇数长度的数组；

// 数字前面共有 left 个选择，其中偶数个数字的选择方案有 left_even = (left + 1) / 2 个，奇数个数字的选择方案有 left_odd = left / 2 个；

// 数字后面共有 right 个选择，其中偶数个数字的选择方案有 right_even = (right + 1) / 2 个，奇数个数字的选择方案有 right_odd = right / 2 个；

// 所以，每个数字一共在 left_even * right_even + left_odd * right_odd 个奇数长度的数组中出现过。

// 作者：liuyubobobo
// 链接：https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/solution/cong-on3-dao-on-de-jie-fa-by-liuyubobobo/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。