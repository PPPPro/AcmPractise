#include <iostream>
#include<map>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,n,tmp,ans = 0,tmp1,tmp2;
	map<int, int> m;
	cin >> n;
	for(i = 0; i < n; i++){
        cin >> tmp;
        if(m.count(tmp)){
            m[tmp]++;
        }
        else{
            m.insert(pair<int,int>(tmp,1));
        }
	}
	tmp1 = 0;
	tmp2 = 0;
	//for(map<int,int>::iterator it = m.begin();
	// it != m.end(); it++){cout<<it->first<<" "<<it->second<<endl;}
	for(map<int,int>::iterator it = m.begin();
	 it != m.end(); it++){
	     if(it->second > tmp2){
                tmp2 = it->second;
                tmp1 = it->first;
	     }
	     else if(it->second == tmp2 && it->first>tmp1){
            tmp1 = it->first;
	     }

	}
	cout<<tmp1<<" "<<tmp2;
	return 0;
}
