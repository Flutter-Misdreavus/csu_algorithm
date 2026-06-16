#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

auto cmp = [](auto& a, auto& b){
	if(a.second != b.second){
		return a.second > b.second;
	}else{
		return a.first > b.first;
	}
};

priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, decltype(cmp)> bulid(cmp);
priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, less<pair<long long int, long long int>>> pd;

int main(){
	long long int n;
	long long int t1, t2;
	long long int t3, t4;
	long long int zt = 0;
	long long int s = 0;

	scanf("%lld", &n);
	for(long long int i = 0; i < n; i++){
		scanf("%d%d", &t1, &t2);
		bulid.push({t1, t2});
	}

	while(!bulid.empty()){
		t1 = bulid.top().first;
		t2 = bulid.top().second;
		bulid.pop();

		if(zt + t1 <= t2){
			zt += t1;
			s++;
			pd.push({t1, t2});
		}else{
			t3 = pd.top().first;
			t4 = pd.top().second;
			if(t3 > t1){
				pd.pop();
				pd.push({t1, t2});
				zt -= t3;
				zt += t1;
				bulid.push({t3, t4});
			}
		}
	}

	printf("%d\n", s);
}
