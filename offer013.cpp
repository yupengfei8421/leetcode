
#include<vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for(int iter1=0;iter1<(const int)matrix.size();iter1++){
            for(int iter2=0;iter1<(const int)matrix.at(0).size();iter2++){
                if((iter1>0)&&(iter2>0)){
                matrix.at(iter1).at(iter2)=
                matrix.at(iter1).at(iter2)+
                matrix.at(iter1).at(iter2-1)+
                matrix.at(iter1-1).at(iter2)-
                matrix.at(iter1-1).at(iter2-1);
                continue;
                }
                if((iter1>0)&&(iter2==0)){
                matrix.at(iter1).at(iter2)+=
                matrix.at(iter1-1).at(iter2);
                continue;
                }
                if((iter1=0)&&(iter2>0)){
                matrix.at(iter1).at(iter2)+=
                matrix.at(iter1).at(iter2-1);
                continue;
                }

            }
        }
        matrix1=matrix;
    }            
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return ((*matrix1).at(row2).at(col2)+matrix1.at(row1).at(col1)-matrix1.at(row1).at(col2)-matrix1.at(row2).at(col1));
    }
    vector<vector<int>> * matrix1 =new vector<vector<int>>;

};
