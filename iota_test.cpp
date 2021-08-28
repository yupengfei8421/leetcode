#include<numeric>
#include<vector>
#include<iostream>
int main(){
    std::vector<int> test_vector(10);
    for(int iter =0;iter<10;iter++){
        test_vector.at(iter) = iter*iter;
        std::cout<<test_vector.at(iter)<<", ";
    }
    std::cout<<std::endl;
    iota(test_vector.begin(),test_vector.end(),1);
    for(int iter =0;iter<10;iter++){
        //test_vector.at(iter) = iter*iter;
        std::cout<<test_vector.at(iter)<<", ";
    }
    std::cin>>test_vector.at(0);
    return 0;
}