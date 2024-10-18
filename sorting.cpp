#include<bits/stdc++.h>
using namespace std;

void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}

void selectionsort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min=a[i],minindex=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<min){
                min=a[j];
                minindex=j;
            }
        }
        int temp=a[i];
        a[i]=min;
        a[minindex]=temp;
    }
}

void bubblesort(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void insertionsort(int a[],int n){
    for(int i=1;i<n;i++){
        int current= a[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(a[j]>current){
                a[j+1]=a[j];
            }
            else{
                break;
            }
        }
        a[j+1]=current;
    }
}

int main(){
    int a[]={1,4,7,9,3};
    insertionsort(a,5);
    print(a,5);
}