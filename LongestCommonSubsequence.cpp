#include<bits/stdc++.h>
using namespace std;

int lcs(char *X, char *Y, int m , int n){
     
    int xy[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
          
          if(i==0 || j==0){
              xy[i][j]=0;
          }

          else if(X[i-1]==Y[j-1]){
             xy[i][j]=xy[i-1][j-1]+1;
          }

          else{
              xy[i][j]= max(xy[i-1][j],xy[i][j-1]);
          }
        }
    }

    return xy[m][n];

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