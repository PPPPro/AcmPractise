#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(){
	int i,j,n,tmp,ans = 0,cnt = 0,tmp1,tmp2,x,y;
	vector<int> v;
	int a_i[5],a_j[5],b_i[5],b_j[5];
	for(i = 1; i <= 2; i++){
        cin>>a_i[i] >> a_j[i];
	}
	for(i = 1; i <= 2; i++){
        cin>>b_i[i] >> b_j[i];
	}
    a_i[3] = a_i[2];
    a_j[3] = a_j[1];
    a_i[4] = a_i[1];
    a_j[4] = a_j[2];
    b_i[3] = b_i[2];
    b_j[3] = b_j[1];
    b_i[4] = b_i[1];
    b_j[4] = b_j[2];

    if(b_i[1] > a_i[1] && b_i[1] <b_i[3] && b_j[1] > a_j[1] &&b_j[1] < b_j[4]){
        cnt++;
        v.push_back(1);
    }
    if(b_i[3] > a_i[1] && b_i[3] <b_i[3] && b_j[3] > a_j[1] &&b_j[3] < b_j[4]){
        cnt++;
        v.push_back(3);
    }
    if(b_i[2] > a_i[1] && b_i[2] <b_i[3] && b_j[2] > a_j[1] &&b_j[2] < b_j[4]){
        cnt++;
        v.push_back(2);
    }
    if(b_i[4] > a_i[1] && b_i[4] <b_i[3] && b_j[4] > a_j[1] &&b_j[4] < b_j[4]){
        cnt++;
        v.push_back(4);
    }
    if(cnt = 0){
        y = a_j[2] - a_j[1];
        x = a_i[2] - a_i[1];
    }
    else if(cnt = 1){
        tmp1 = v[0];
        y = b_j[tmp1] - a_j[tmp1];
        x = b_i[tmp1] - a_i[tmp1];
    }
    else if(cnt == 2){
        tmp1 = v[0];
        tmp2 = v[1];
        if(tmp1 == 1 && tmp2 == 4){
            y = b_j[4] - b_j[1];
            x = a_i[2] - b_i[1];
        }
        if(tmp1 == 1 && tmp2 == 3){
            y = a_j[3] - a_j[1];
            x = b_i[3] - b_i[1];
        }
        if(tmp1 == 3 && tmp2 == 2){
            y = b_j[3] - b_j[2];
            x = b_i[3] - a_i[1];
        }
        if(tmp1 == 2 && tmp2 == 4){
            y = b_j[2] - a_j[2];
            x = b_i[2] - b_i[4];
        }
    }
    else if(cnt == 4){
        y = b_j[2] - b_j[1];
        x = b_i[2] - b_i[1];
    }
    float u = y*x;
    printf("%.2f",u);
	return 0;
}
