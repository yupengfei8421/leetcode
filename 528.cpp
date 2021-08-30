#include<iostream>
#include<vector>
#include<random>
#include<numeric>
#include<iterator>
#include<algorithm>
// mt19937头文件是<random> 是伪随机数产生器，用于产生高性能的随机数
// uniform_int_distribution 头文件在<random>中，是一个随机数分布类，参数为生成随机数的类型，构造函数接受两个值表示区间段
// accumulate 头文件在<numeric>中，求特定范围内所有元素的和。
// spartial_sum函数的头文件在<numeric>，对(first, last)内的元素逐个求累计和，放在result容器内
// back_inserter函数头文件<iterator>，用于在末尾插入元素。
// lower_bound头文件在<algorithm>，用于找出范围内不大于num的第一个元素
// using namespace std;
class Solution1 {
private:
    std::mt19937 gen;
    std::uniform_int_distribution<int> dis;
    std::vector<int> pre;

public:
    Solution1(std::vector<int>& w): gen(std::random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
        partial_sum(w.begin(), w.end(), back_inserter(pre));
    }
    
    int pickIndex() {
        int x = dis(gen);
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }
};
// 1 <= w.length <= 10000
// 1 <= w[i] <= 10^5

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// 二分搜索优化
using namespace std;

class Solution {
public:
    int range = 0;
    vector<int> weights;

    Solution(vector<int>& w) {
        for (auto w_ : w) {
            range += w_;
            weights.push_back(range);
        }
    }
    
    int pickIndex() {
        int rnd = rand() % range;

        int left = 0;
        int right = weights.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (rnd < weights[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};


int main(){
    std::vector<int> test;

    std::cout<<"test="<<std::endl;
    int i;
    while(std::cin>>i){
        test.push_back(i);
    }
    {
        Solution1* obj = new Solution1(test);
        int param_1 = obj->pickIndex();
        std::cout<<"answer="<<param_1 <<std::endl;
    }
    {
        Solution *obj = new Solution(test);
        int param_1 = obj->pickIndex();
        std::cout<<"answer="<<param_1 <<std::endl;
    }
    return 0;
}