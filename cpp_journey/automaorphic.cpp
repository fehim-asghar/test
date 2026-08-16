#include<iostream>
using namespace std;

bool isautomorphic(int n){
    long long square = (long long) n*n;
    while(n>0){
        if(square%10 != n%10){
            return false;
        }

        square = square /10;
        n = n/10;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
if(isautomorphic(n)){
    cout<<"true";
}
else{
    cout<<"false";
}

return 0;

}