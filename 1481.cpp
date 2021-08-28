//1481
// c++ .\1481.cpp -o .\1481.exe -std=c++17 -fexec-charset=GBK
#include<vector>
#include<unordered_map>
#include<iostream>
#include<algorithm>//#include<sort>
using std::pair;// #include<pair>
using namespace std;


int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> group;
    for (int num: arr) {
        ++group[num];
    }
    cout<<"group"<<endl;
    for(auto i: group){
       cout<<i.first<<", "<<i.second<<endl;
    }
    cout<<"freq"<<endl;
    vector<pair<int, int>> freq(group.begin(), group.end());
    for(auto [i,j]: freq){
       cout<<i<<", "<<j<<endl;
    }
    sort(freq.begin(), freq.end(), [](const auto& u, const auto& v) {return u.second < v.second;});
    cout<<"freq"<<endl;
    for(auto i: freq){
       cout<<i.first<<", "<<i.second<<endl;
    }
    int ans = freq.size();
    for (auto [_, occ]: freq) {
        if (k >= occ) {
            --ans;
            k -= occ;
        } else {
            break;
        }
    }
    return ans;
}
int main(){
vector<int> arr{1,2,3,4,5,6,7,8,9,1,2,3,4,1,2,3};
int k = 2;
for(auto i: arr){
    cout<<i<<", ";
}

cout<<endl<<"\n长度："<<arr.size()<<"\n去除："<<k<<"个"<<endl;
int answer = findLeastNumOfUniqueInts(arr,k);
cout<<"还剩"<<answer<<"个不同数字";
return 0;
// PS C:\Users\admin\Desktop\leetcode> .\1481.exe
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 1, 2, 3, 

// 长度：16
// 去除：2个
// group
// 9, 1
// 8, 1
// 7, 1
// 2, 3
// 1, 3
// 3, 3
// 4, 2
// 5, 1
// 6, 1
// freq
// 9, 1
// 8, 1
// 7, 1
// 2, 3
// 1, 3
// 3, 3
// 4, 2
// 5, 1
// 6, 1
// freq
// 9, 1
// 8, 1
// 7, 1
// 5, 1
// 6, 1
// 4, 2
// 2, 3
// 1, 3
// 3, 3
// 还剩7个不同数字
}