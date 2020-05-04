#include<bits/stdc++.h>
using namespace std;

int lcs(char *X, char *Y, int m , int n){
     
    int xy[m+1][n+1];

    bool bi;

    for(int i=0;i<=m;i++){
        bi=i&1;
        for(int j=0;j<=n;j++){
          
          if(i==0 || j==0){
              xy[bi][j]=0;
          }

          else if(X[i-1]==Y[j-1]){
             xy[bi][j]=xy[1-bi][j-1]+1;
          }

          else{
              xy[bi][j]= max(xy[1-bi][j],xy[bi][j-1]);
          }
        }
    }

    return xy[bi][n];

}


int max(int a, int b){

    return a>b?a:b;
}

int main(){

    char X[] = "AGGTAB";  
    char Y[] = "GXTXAYB";  
      
    int m = strlen(X);  
    int n = strlen(Y);  

    cout << lcs(X,Y, m, n) << endl;
    return 0;
}