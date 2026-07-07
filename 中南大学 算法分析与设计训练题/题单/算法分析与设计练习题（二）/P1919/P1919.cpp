// P1919 【模板】高精度乘法 / A*B Problem 升级版
/*
链接：https://www.luogu.com.cn/problem/P1919
知识点：FFT、高精度
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

typedef complex<double> cd;
const double PI = acos(-1);
const int BASE = 1000;

void fft(vector<cd> &a, bool invert){
	int n = a.size();

	for(int i = 1, j = 0; i < n; i++){
		int bit = n >> 1;
		for(; j & bit; bit >>= 1){
			j ^= bit;
		}
		j ^= bit;

		if(i < j){
			swap(a[i], a[j]);
		}
	}

	for(int len = 2; len <= n; len <<= 1){
		double ang = 2 * PI / len * (invert ? -1 : 1);
		cd wlen(cos(ang), sin(ang));
		for(int i = 0; i < n; i += len){
			cd w(1);
			for(int j = 0; j < len / 2; j++){
				cd u = a[i + j];
				cd v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}

	if(invert){
		for(cd &x : a){
			x /= n;
		}
	}
}

vector<long long> multiply(const vector<int> &a, const vector<int> &b){
	vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	int n = 1;
	while(n < (int)a.size() + (int)b.size()){
		n <<= 1;
	}
	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);
	for(int i = 0; i < n; i++){
		fa[i] *= fb[i];
	}
	fft(fa, true);

	vector<long long> res(n);
	for(int i = 0; i < n; i++){
		res[i] = (long long)round(fa[i].real());
	}
	return res;
}

char buf[1000005];

int main(){
	vector<int> a, b;

	scanf("%s", buf);
	int lena = strlen(buf);
	for(int i = lena - 1; i >= 0; i -= 3){
		int x = 0;
		for(int j = max(0, i - 2); j <= i; j++){
			x = x * 10 + (buf[j] - '0');
		}
		a.push_back(x);
	}

	scanf("%s", buf);
	int lenb = strlen(buf);
	for(int i = lenb - 1; i >= 0; i -= 3){
		int x = 0;
		for(int j = max(0, i - 2); j <= i; j++){
			x = x * 10 + (buf[j] - '0');
		}
		b.push_back(x);
	}

	vector<long long> c = multiply(a, b);

	long long jin = 0;
	for(int i = 0; i < (int)c.size(); i++){
		c[i] += jin;
		jin = c[i] / BASE;
		c[i] %= BASE;
	}
	while(jin){
		c.push_back(jin % BASE);
		jin /= BASE;
	}

	int pos = c.size() - 1;
	while(pos > 0 && c[pos] == 0){
		pos--;
	}

	printf("%lld", c[pos]);
	for(int i = pos - 1; i >= 0; i--){
		printf("%03lld", c[i]);
	}
	printf("\n");
}
