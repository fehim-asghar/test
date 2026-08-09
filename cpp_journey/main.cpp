#include<iostream>
#include<string>
using namespace std;

int main(){
   int itemPrice = 100;
   double taxRate = 1.05;

   double finalPrice = static_cast<double>(itemPrice)*taxRate;
   cout<<"Final price : "<<finalPrice;

   return 0;
}