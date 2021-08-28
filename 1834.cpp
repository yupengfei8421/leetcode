
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
        // 根据task进入队列的先后顺序，对其序号进行排序
        int n = tasks.size();
        vector<int> indices(n);
        iota(indices.begin(),indices.end(),0);
        sort(indices.begin(),indices.end(),[&](int i, int j){
            return tasks[i][0]< tasks[j][0];
        });
        vector<int> answer;
        //优先队列，存储处理tasks的先后次序
        priority_queue<PII, vector<PII>, greater<PII>> q;//std::greater 的特化为任何指针类型产生严格全序
        //时间戳，存储cpu的当前时间
        LL timestamp = 0;
        //指针，用于遍历 
        int ptr =0;
        for(int i=0; i<n; ++i){
            //如果没有可以执行的任务，直接快进
            if (q.empty()){
                timestamp = max(timestamp,(LL)tasks[indices[ptr]][0]);
            }
            //将所有小于等于时间戳的任务放入优先队列中
            while((ptr<n)&& tasks[indices[ptr]][0]<timestamp){
                q.emplace(tasks[indices[ptr]][1],indices[ptr]);//有序放入优先队列中
                ++ptr;
            }
            //处理时间最小的任务
            auto && [process,index]=q.top();
            timestamp += process;
            answer.push_back(index);
            q.pop();
        }     
        return answer;
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
