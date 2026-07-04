#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// 大整数：低位在前，每位 0~9
struct BigNum{
	vector<int> d;
};

void mul(BigNum& num, int x){
	int carry = 0;
	for(int i = 0; i < (int)num.d.size(); i++){
		int prod = num.d[i] * x + carry;
		num.d[i] = prod % 10;
		carry = prod / 10;
	}
	while(carry){
		num.d.push_back(carry % 10);
		carry /= 10;
	}
}

BigNum divSmall(const BigNum& num, int x){
	BigNum res;
	res.d.resize(num.d.size());
	long long rem = 0;
	for(int i = (int)num.d.size() - 1; i >= 0; i--){
		rem = rem * 10 + num.d[i];
		res.d[i] = (int)(rem / x);
		rem %= x;
	}
	while(res.d.size() > 1 && res.d.back() == 0){
		res.d.pop_back();
	}
	return res;
}

bool greaterThan(const BigNum& a, const BigNum& b){
	if(a.d.size() != b.d.size()) return a.d.size() > b.d.size();
	for(int i = (int)a.d.size() - 1; i >= 0; i--){
		if(a.d[i] != b.d[i]) return a.d[i] > b.d[i];
	}
	return false;
}

void print(const BigNum& num){
	for(int i = (int)num.d.size() - 1; i >= 0; i--){
		printf("%d", num.d[i]);
	}
	printf("\n");
}

struct Minister{
	int a, b;
	long long prod;
};

bool cmp(const Minister& x, const Minister& y){
	return x.prod < y.prod;
}

Minister ministers[1010];

int main(){
	int n;
	scanf("%d", &n);
	int a0, b0;
	scanf("%d%d", &a0, &b0);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &ministers[i].a, &ministers[i].b);
		ministers[i].prod = 1LL * ministers[i].a * ministers[i].b;
	}

	sort(ministers, ministers + n, cmp);

	BigNum P;
	P.d.clear();
	int t = a0;
	while(t){
		P.d.push_back(t % 10);
		t /= 10;
	}
	if(P.d.empty()) P.d.push_back(0);

	BigNum ans;
	ans.d.push_back(0);

	for(int i = 0; i < n; i++){
		BigNum reward = divSmall(P, ministers[i].b);
		if(greaterThan(reward, ans)){
			ans = reward;
		}
		mul(P, ministers[i].a);
	}

	print(ans);
}
