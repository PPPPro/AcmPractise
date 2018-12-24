#include<iostream>
#include<string>
using namespace std;
int main(){
    int i,j,ans = 0;
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(i = 0; i < a.size(); i++){
        int tmp = 1;
        for(j = 0; j < b.size(); j++){
            if( b[j] != a[i+j])tmp = 0;
        }
        if(tmp)ans++;
    }
    cout<<ans;
}
