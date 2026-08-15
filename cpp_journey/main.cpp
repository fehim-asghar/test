#include<iostream>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int arra [m][n];
    

    for(int i =0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            cin>>arra[i][j];
        }
        cout<<endl;
   }
   int max =arra[0][0];
   int x{0};
   int y{0};
   for(int i =0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            if(arra[i][j]>max){
            max=arra[i][j]; 
            x=i ;
            y=j ;
            }
        }
        cout<<endl;
   }
   cout<<x<<" "<<y<<endl;
   
   
}