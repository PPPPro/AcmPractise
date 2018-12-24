
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int i,j,n,r;
    vector<int>a;
    cin >> n >> r;
    if(n<0){
        n=-n;
        cout<<"-";
    }
    for(i = 0; n >= r; i++){
        a.push_back(n%r);
        n /= r;
    }
    a.push_back(n);



    for(i = a.size()-1; i >= 0; i--){

        if(a.at(i) == 10){cout<<"A";}
        else if(a.at(i) == 11){cout<<"B";}
        else if(a.at(i) == 12){cout<<"C";}
        else if(a.at(i) == 13){cout<<"D";}
        else if(a.at(i) == 14){cout<<"E";}
        else if(a.at(i) == 15){cout<<"F";}
        else
        cout<<a.at(i);
    }
    return 0;
}
