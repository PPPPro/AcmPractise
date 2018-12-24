#include<iostream>
#include<set>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iterator>
using namespace std;
int main(){
    int i,j,n,d;
    string word;
    set<string> s;
    set<string> s1;
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> d >> word;
        for(j = 0; j < word.size(); j++){
            if(word[j] <= 'z' && word[j] >= 'a'){

             word[j] -= 32;
            }
        }


        if( d == 0){
                cout << word;
            s.insert(word);
        }
        else{
            cout << word;
            if(s.count(word))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        s.swap(s1);
    }
    return 0;
}
