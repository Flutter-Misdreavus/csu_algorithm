#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define UNTORCH 0X7FFFFFFF

using namespace std;

vector<int> dis;
vector<vector<pair<int, int>>> ditu;
vector<bool> book;

int findmin(int n){
	int minpos = 0;
	int mina = UNTORCH;

	for(int i = 1; i <= n; i++){
		if(dis[i] < mina && !book[i]){
			mina = dis[i];
			minpos = i;
		}
	}

	book[minpos] = true;
	return minpos;
}

void relax(int kaishi){
	int b, c;
	for(auto it = ditu[kaishi].begin(); it != ditu[kaishi].end(); it++){
		b = (*it).first;
		c = (*it).second;
		if(dis[b] > dis[kaishi] + c){
			dis[b] = dis[kaishi] + c;
		}
	}
}

int main(){
	int n, m, s;
	int a, b, c;
	scanf("%d%d%d", &n, &m, &s);

	for(int i = 0; i <= n; i++){
		dis.push_back(UNTORCH);
	}
	dis[s] = 0;
	book.resize(n+1, false);
	ditu.resize(n+1);

	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &a, &b, &c);
		ditu[a].push_back({b, c});
	}

	for(int i = 0; i < n; i++){
		a = findmin(n);
		relax(a);
	}

	for(int i = 1; i <= n; i++){
		printf("%d ", dis[i]);
	}

	printf("\n");
}
