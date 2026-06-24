#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

vector<pair<int, int>> bisai;

int main(){
	int a, b;
	int n;
	int lastend = 0;
	int ge = 0;

	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%d%d", &a, &b);
		bisai.push_back({a, b});
	}

	sort(bisai.begin(), bisai.end());

	for(auto& it : bisai){
		a = it.first;
		b = it.second;

		if(a >= lastend){
			ge++;
			lastend = b;
			continue;
		}

		if(b < lastend){
			lastend = b;
		}
	}

	printf("%d\n", ge);
}
