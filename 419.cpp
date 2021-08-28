#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int length=board.size();
        int width=board.at(0).size();
        int answer=0;
        for(int l=0;l<length;l++){
            for(int w=0;w<width;w++){
                if(board.at(l).at(w) == 'X'){
                    board.at(l).at(w)='x';
                    bool up=true;
                    bool down=true;
                    bool left=true;
                    bool right=true;            
                    if(l-1>=0){
                        if(board.at(l-1).at(w)=='x')
                        up=false;
                    }
                    if(l+1<length){
                        if(board.at(l+1).at(w)=='x')
                        down=false;
                    }
                    if(w-1>=0){
                        if(board.at(l).at(w-1)=='x')
                        left=false;
                    }
                    if(w+1<width){
                        if(board.at(l).at(w+1)=='x')
                        right=false;
                    }
                    if((up&&down)&&(left&&right)){
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
};
int main(){
    vector<vector<char>> test={{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    for(auto iter1: test){
        for(auto iter2: iter1){
            cout<<iter2<<" ";
        }
        cout<<endl;
    }
    Solution solution;
    cout<<solution.countBattleships(test)<<endl;
    cin>>test.at(0).at(0);

}
//前向声明的累或者结构体只能用来定义指针或者引用
