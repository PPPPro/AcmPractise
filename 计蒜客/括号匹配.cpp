#include<iostream>
#include<algorithm>
#include<cctype>
#include<stack>
#include<cstring>
using namespace std;
int main(){
     string s;
     int i,j,k,tmp,n,m;
     cin >> s;
     k = 0;
     n = s.size();
     int a[n],b[n];

     memset(b,0,sizeof(b));
     memset(a,0,sizeof(a));
     for(i = 0; i < s.size(); i++){
        tmp = 0;
        if(s[i] == '('){
            //cout << i+1 <<" ";
            if(b[i] == 0){

            a[k++] = i+1;
            b[i] = 1;
            }
            for(j = i; j < s.size(); j++){
                if(s[j] == '('){
                    tmp++;
                }
                else if(s[j] == ')'){
                    tmp--;
                }
                if(tmp == 0 && b[j] == 0){

                   // cout << j+1 << endl;
                    a[k++] = j+1;
                    b[j] = 1;
                    break;
                }
            }
        }

     }
     bool ok = 1;
     for(i = 0; i < n; i++){
        if(a[i] == 0)ok = 0;
     }
     if(ok){
        cout<< "Yes"<<endl;
        for(i = 0; i < n; i++){
        if(i!=0 && i%2 == 0)cout<<endl;
        cout<< a[i] <<" ";
        }
     }
     else cout<<"No";


     return 0;
}
