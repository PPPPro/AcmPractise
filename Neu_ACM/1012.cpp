#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,n,tmp,ans = 0;
	string s;
	cin >> n;
    fflush(stdin);
        while(n){
            getline(cin,s);
            cout << s <<" "<<endl<<endl;
            n--;
        }
        while(cin>>s){
                cout << s <<" "<< endl<<endl;
        }


	return 0;
}
