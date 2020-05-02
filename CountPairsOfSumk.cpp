#include<bits/stdc++.h>
using namespace std;

void findPairs(int arr[],int k,int size){

   
  int freq[k]={0};
  for(int i=0;i<size;i++){
     ++freq[(arr[i]%k)];
  }

  int count =(freq[0]*(freq[0]-1))/2;
  for(int i=1;i<=k/2 && i!=(k-i);i++){
      count += (freq[i]*(freq[k-i]));
  }
  if(k%2==0){
      count+= ((freq[k/2]*(freq[k/2]-1))/2);
  }

   cout << count << endl;
} 

int main(){
   
   int arr[]={2, 2, 1, 7, 5, 3};
   int k=4;
   int size= sizeof(arr)/sizeof(int);

   findPairs(arr,k,size);

   return 0;
}