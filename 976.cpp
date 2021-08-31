
#include<vector>
#include<algorithm>
using std::vector;
using std::sort;
class Solution {
public:
    bool X(const int a,const int b, const int c){
        return ((a-b)<c)&&((a+b)>c);
    }
    int largestPerimeter(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int n=nums.size();
        while(n>2){
            if( X( nums.at(n-1),nums.at(n-2),nums.at(n-3) ) )
            return nums.at(n-1)+nums.at(n-2)+nums.at(n-3);
            n--;
        }
        return 0;

    }
};