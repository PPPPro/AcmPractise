#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    int i,j,k,tmp,n,many;
    string fruits,place;
    map<string,map<string,int>> m;
    cin >> n;
    for(i = 0; i < n; i++){
        cin>>fruits>>place>>many;
        if(m.count(place)){
            if(m[place].count(fruits)){
                m[place][fruits]+=many;
            }
            else{
            m[place][fruits] = many;}
        }
        else{
            m[place][fruits] = many;
        }
    }
    for(map<string,map<string,int>>::iterator it = m.begin();
        it != m.end(); it++){
            cout<<it->first<<endl;
            for(map<string,int>::iterator it1 = it->second.begin();
            it1 != it->second.end(); it1++){
                 cout<<"   |----"<<(it1->first)<<'('<<(it1->second)<<')'<<endl;
            }
        }
    return 0;
}
