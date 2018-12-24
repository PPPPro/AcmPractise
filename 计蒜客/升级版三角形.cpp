#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){

	int i,j,tmp,ans = 0;
	char n;
	cin >> n;
	if('1'<= n && n <= '9'){
        for(i = 0; i < int(n-'0'); i++){
            for(j = 1; j < int(n - '0') - i; j++)
            cout<<" ";
            for(j = 0; j < i; j++){
                cout <<  j+1;
            }
            for(j = i; j >= 0; j--){
                cout << j+1;
            }
        cout << endl;
	}
	}
	else{
        for(i = 0; i < int(n - 'A'+1); i++){
            for(j = 1; j < int(n - 'A'+1) - i; j++)
            cout<<" ";
            for(j = 0; j < i; j++){
                cout <<  char('A' + j);
            }
            for(j = i; j >= 0; j--){
                cout << char('A' + j);
            }
        cout << endl;
	}
	}
	return 0;
}
