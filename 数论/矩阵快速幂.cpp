#include<iostream>
#include<cstdio>
using namespace std;
int n; // 所有矩阵都是 n * n 的矩阵
struct matrix {
   int a[100][100];
};

matrix matrix_mul(matrix A, matrix B, int mod) {
    // 2 个矩阵相乘
    matrix C;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C.a[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C.a[i][j] += A.a[i][k] * B.a[k][j] % mod;
                C.a[i][j] %= mod;
            }
        }
    }
    return C;
}
matrix unit() {
    // 返回一个单位矩阵
    matrix res;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                res.a[i][j] = 1;
            } else {
                res.a[i][j] = 0;
            }
        }
    }
    return res;
}
matrix matrix_pow(matrix A, int n, int mod) {
    // 快速求矩阵 A 的 n 次方
    matrix res = unit(), temp = A;
    for (; n; n /= 2) {
        if (n & 1) {
            res = matrix_mul(res, temp, mod);
        }
        temp = matrix_mul(temp, temp, mod);
    }
    return res;
}
int main(){
    matrix x,y;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> x.a[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cin >> y.a[i][j];
        }
    }

    cin >> n;
    matrix t = matrix_pow(x,n,30);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cout << t.a[i][j] << " ";
        }cout << endl;
    }
    t = matrix_mul(x,y,1000);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cout << t.a[i][j] << " ";
        }cout << endl;
    }
}
