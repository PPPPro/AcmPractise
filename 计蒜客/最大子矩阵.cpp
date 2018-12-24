#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m,i,j,k,l,o,tmp = 0,tmp1 = 0,Max = 0;
    int f[n][m];
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            cin >> f[i][j];
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            tmp = 0;
            for(k = j; k < m; k++){
                tmp += f[i][k];
                for(l = i+1; l < n; l++){
                    for(o = j; o < k; o++){
                        tmp1 += f[l][o];
                    }
                }
            if(Max<tmp1+tmp)Max = tmp1+tmp;
            }

        }
    }
    return 0;
}
