#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int Max = 1010;

struct stu{
    string name;
    int aver;
    int num;
};


bool cmp(stu a,stu b){
    if(a.aver > b.aver){
    	return 1;
    }
	else if(a.aver == b.aver){
		return a.name < b.name;
	}
    else return 0;
}
stu E[Max];
int main(){
    int n;
    int m,t;
    vector<stu> v;
    while(cin >> n){



        for(int i = 0; i < n; i++){
            cin >> E[i].name >> E[i].aver >> E[i].num;
        }
        cin >> m >> t;
        for(int i = 0; i < n; i++){
            if(E[i].num >= t)v.push_back(E[i]);
        }
       // vector<stu>::iterator
        int it = v.size();
        sort(v.begin(),v.end(),cmp);
        //cout<<" 1111111111"<<endl;
        for(int i = 0; i <= n; i++){
            if(E[i].num < t)v.push_back(E[i]);
        }
       // cout<<" 1111111111"<<endl;
        sort(v.begin()+it,v.end(),cmp);
        int cnt = 0;
        for(int i = 0;i < m; i++){
                cout << v[i].name;
                cout << endl;
        }
        v.clear();
    }

    return 0;
}
/*
4

a 80 6
b 120 1
c 90 7
d 100 1
4
2
*/
