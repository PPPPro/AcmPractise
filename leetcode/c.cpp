#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int res = 0;
vector<int> beautifulArray(int N) {
    int cnt = 0;
    vector<int> v(N);
	while(next_permutation(v.begin(),v.end())){
        for(int i = 0; i < (N/2+0.5); i++){
            for(int j = i+2; j < N; j++){
                for(int k = i+1; k < j; k++){
                    if(v[k]*2 == v[i]+v[j])return v;
                }
            }
        }
	}

    }
int main(){
    vector< vector<int> > A;
    vector<int> t;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        t.clear();
        for(int j = 0; j < size ; j++){
            int tmp;
            cin >> tmp;
            t.push_back(tmp);
        }
        A.push_back(t);
    }
    for(int i = 0; i < A.size(); i++){
        for(int j = 0; j < A[i].size(); j++){
            cout <<A[i][j] << " ";
        }cout << endl;
    }
    //minFallingPathSum(A);
}

