#include<vector>
using std::vector;

class Solution1 {
    //暴力求解
    //超时间限制了！
//     1 <= n <= 2 * 104
// 1 <= bookings.length <= 2 * 104
// bookings[i].length == 3
// 1 <= firsti <= lasti <= n
// 1 <= seatsi <= 104
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/corporate-flight-bookings
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> answer(n);
        for(auto book : bookings){
            int first = book.at(0);
            int last = book.at(1);
            int seat = book.at(2);
            while(first <= last){
                answer.at(first-1)+=seat;
                first++;
            }
        }
        return answer;

    }
};
class Solution {
//采用差分算法
// 执行用时：
// 208 ms, 在所有 C++ 提交中击败了 58.49 % 的用户 内存消耗： 72.4 MB, 在所有 C++ 提交中击败了 25.04 % 的用户
public : vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
{
    vector<int> answer(n);
    for (auto book : bookings)
    {
        int first = book.at(0);
        int last = book.at(1);
        int seat = book.at(2);
        answer.at(first - 1) += seat;
        if (last < n)
            answer.at(last) -= seat;
    }
    for (int i = 1; i < n; i++)
        answer.at(i) += answer.at(i - 1);
    return answer;
}
};