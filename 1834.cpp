
#include<iostream>
#include<vector>
#include<queue> //priority_queue
#include<algorithm>
#include<numeric> //iota
using namespace std;
class Solution {
private:
    using PII = pair<int, int>;
    using LL = long long;

public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return tasks[i][0] < tasks[j][0];
        });

        vector<int> ans;
        // 优先队列
        priority_queue<PII, vector<PII>, greater<PII>> q;
        // 时间戳
        LL timestamp = 0;
        // 数组上遍历的指针
        int ptr = 0;
        
        for (int i = 0; i < n; ++i) {
            // 如果没有可以执行的任务，直接快进
            if (q.empty()) {
                timestamp = max(timestamp, (LL)tasks[indices[ptr]][0]);
            }
            // 将所有小于等于时间戳的任务放入优先队列
            while (ptr < n && tasks[indices[ptr]][0] <= timestamp) {
                q.emplace(tasks[indices[ptr]][1], indices[ptr]);
                ++ptr;
            }
            // 选择处理时间最小的任务
            auto&& [process, index] = q.top();
            timestamp += process;
            ans.push_back(index);
            q.pop();
        }
        
        return ans;
    }
};
 
 int main(){
     vector<vector<int>> tasks = {{1,2},{2,4},{3,2},{4,1}};
     Solution *a = new Solution();
     vector<int> answer=a->getOrder(tasks);
     cout<<endl<<"tasks"<<endl;
     for(auto iter:tasks){
            for(auto iter_inner:iter){
                cout<<iter_inner<<", ";
            }
         cout<<"\n";
     }
     cout<<endl<<"answer"<<endl;
     for(auto iter:answer){
         cout<<iter<<", ";
     }

     delete(a);
     int b =0;
     cin>>b;
     return 0;
 }
//  tasks
// 1, 2, 
// 2, 4, 
// 3, 2, 
// 4, 1, 

// answer
// 0, 2, 3, 1, 
