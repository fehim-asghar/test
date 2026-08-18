#include<iostream>
#include<vector>
using namespace std;

void newway(vector<int> &v){
    int i=0 ;
    int j=v.size()-1;

    while(i<j){
        if( v[i]%2 == 0 )i++;
        else if( v[j]%2 != 0 )j--;
        else{
            int temp = v[i];
            v[i]=v[j];
            v[j]=temp;
            i++;
            j--;
        }
       


    }

}

int main(){
    int n; 
    cin>>n;

    vector<int> v;
    for(int i=0 ; i<n ; i++ ){
        int ele ;
        cin>>ele;
        v.push_back(ele);
    }

    newway(v);

    for(int i=0 ; i<n ; i++ ){
        cout<<v[i]<<" ";
    } cout<<endl;

}