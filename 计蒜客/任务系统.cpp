#include <iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
    int dist, loc;
    node() { }
    bool operatr < (const node & a) const {
        return dist > a.dist;
    }
};
typedef std::pair<int, int> pair_t

queue<pair_t> q ;

operator bool ()(pair_t x, pair_t y)
{
    if(x.first == y.first) {
        return x.second > y.second;
    } else {
        return x.first > y.first;
    }

    if (x.first > y.first){
        return c
    } else if(x.first == y.first) {
        return x.second > y.second;
    } else {
        return x.first > y.first;
    }


    return��x > y;���� // xС�����ȼ���       //Ҳ����д��������ʽ���磺 return p[x] > p[y];��ʾp[i]С�����ȼ���
}

int main(){
	int i,j,n,k,tmp,ans = 0;
	cin >> n >> k;
	priority_queue<int,int> q;
	return 0;
}
