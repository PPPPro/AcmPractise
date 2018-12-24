#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int Max = 10000;
int d(int n,vector<int> f){
    int i;
    for(i = 0; n >= 10;i++){
        f.push_back(n%10);
        n /= 10;
    }
    f.push_back(n%10);
    sort(f.begin(),f.end());
}
int main(){
    vector<int>f;
    vector<int>b;
	int i,j,n,l,ans = 0;
	bool tmp = 1;
	d(n,f);
	for(n = 0; n <= Max; n++){
        tmp = 1;
        for(i = 2; i <= 6; i++){
            d(n*i,b);
            for(j = 0; j < f.size(); j++){
                if(f[j] != b[j])tmp=0;break;
            }
            if(!tmp)break;

        }//·Ö½â}
        if(!tmp)break;
            else
                ans++;

}
    cout << ans;
	return 0;
}
