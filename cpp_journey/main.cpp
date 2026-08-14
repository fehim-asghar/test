#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
   vector<int> scores{45, 88, 92,60 , 74 , 98 , 55};
   int vip = 0;
   double sum =0;

   for(int i =0 ; i<scores.size(); i++){
      if(scores[i]>=75){
         vip++;
      }

      sum = sum+scores[i];


   }
   cout<<vip;
   cout<<sum/scores.size();

}