#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,n,tmp,ans = 0;
	string web,s;
	stack<string> s1,s2;
	cin >> n;
	for(i = 0; i < n; i++){

        cin >> s;
        if(s == "VISIT"){
            cin >> web;
            cout << web <<endl;
            s1.push(web);
            while(!s2.empty())s2.pop();
        }
        if(s == "BACK"){
            if(s1.empty())cout<<"Ignore"<<endl;
            else if(s1.size() == 1)cout<<"Ignore"<<endl;
            else{
            s2.push(s1.top());
            s1.pop();
                cout << s1.top()<<endl;
            }
        }
        else if(s == "FORWARD"){
            if( s2.empty())cout<<"Ignore"<<endl;
            else{
                cout << s2.top()<<endl;
                s1.push(s2.top());
                s2.pop();
            }

        }
	}
	return 0;
}
