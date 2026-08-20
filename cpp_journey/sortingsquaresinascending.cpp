#include<iostream>
#include<vector>
using namespace std;

void newway(vector<int> &v){
    int i=0 ;
    int j=v.size()-1;

    while(i<j){
        if(abs(v[i]) < abs(v[j])){
            v.push_back(v[j]*v[j]);
            j--;
        }
        
        else if (abs(v[i])>abs(v[j])){
            

        }
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