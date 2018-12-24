#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
    int T;
    cin >> T;
    while(T--){
    int i,j,n,tmp,ans = 0;
    int Q;
    char a[55][55];
    string s;
    cin >> n;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    cin >> Q;
    for(int l = 0; l < Q; l++){
        cin >> s;
        int n_i,n_j;
        for(i = 0; i< n; i++){
            for(j = 0; j < n; j++){
                if(a[i][j] == 'S'){
                    n_i = i;
                    n_j = j;
                }
            }
        }
        int ok = 0;
        for(i = 0; i < s.length(); i++){


            if(s[i] == 'L'){
                n_j--;
            }
            if(s[i] == 'R'){
                n_j++;
            }
            if(s[i] == 'U'){
                n_i--;
            }
            if(s[i] == 'D'){
                n_i++;
            }

            if(n_i < 0 || n_i>=n || n_j < 0 || n_j >= n){
                cout << "I  am  out!"<<endl;
                ok = 1;
                break;
            }
            else if(a[n_i][n_j] == '#'){
                cout << "I  am  dizzy!"<<endl;
                ok  = 1;
                break;

            }
            else if(a[n_i][n_j] == 'T'){
                cout << "I  get  there!"<<endl;
                ok = 1;
                break;
            }

        }
            if(!ok|| a[n_i][n_j] == 'S'){ cout<<"I  have  no  idea!"<<endl;}
    }
    }
    return 0;
}
