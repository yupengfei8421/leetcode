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
    
    vector<pair<int, int>> freq(group.begin(), group.end());
    sort(freq.begin(), freq.end(), [](const auto& u, const auto& v) {return u.second < v.second;});
    
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
}