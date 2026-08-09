#include<iostream>
#include<cstdint>
using namespace std;

int main(){
   cout<<sizeof(int)<<endl;
   cout<<sizeof(double)<<endl;
   cout<<sizeof(std::int8_t)<<endl;
   cout<<sizeof(std::int64_t)<<endl;

   int max_num {2147483647};

   max_num=max_num+1;

   cout<<max_num<<endl;

   return 0;
}