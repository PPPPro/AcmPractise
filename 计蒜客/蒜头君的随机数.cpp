#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int f(string s){
    int i,j;
    for(i = 0, j = (s.size()-1); i <= j; i++,j--){
        cout<<s[i]<<" "<<s[j]<<endl;
        if(s[i] != s[j]){
            return 0;
        }
    }
    return 1;
}

int main(){
	string s;
	int n;
	cin >> n;

	if(f(s))){
        cout<<s;
	}
	else{
        while(){

            for(i = s.size()-1; i>=0; i--){
                tmp += (int(s[i] - '0'))*ten;
                ten*=10;
            }
        }
	}
	return 0;
}
