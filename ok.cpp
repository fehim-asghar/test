#include<iostream>
#include<vector>
using namespace std;

void sortarray(int arr[] , int size){
    for(int i =0 ; i<size ; i++){
            for(int j=i+1 ; j<size ; j++){
                if(arr[i]>arr[j]){
                    int temp = arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                    
                }
                
            }
    }
}