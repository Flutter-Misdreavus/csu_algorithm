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

struct Node{
	long long w;
	int h;
};

struct CMP{
	bool operator()(const Node& a, const Node& b) const {
		if(a.w != b.w) return a.w > b.w; // 小根堆，先合并权值小的
		return a.h > b.h;               // 权值相同时先合并高度小的，保证树更平衡
	}
};

priority_queue<Node, vector<Node>, CMP> pq;

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		long long w;
		scanf("%lld", &w);
		pq.push((Node){w, 0});
	}

	if(n == 1){
		printf("0\n0\n");
		return 0;
	}

	// 补齐虚拟节点，使 (总叶子数 - 1) 能被 (k - 1) 整除
	int pad = (k - 1 - (n - 1) % (k - 1)) % (k - 1);
	for(int i = 0; i < pad; i++){
		pq.push((Node){0, 0});
	}

	long long total = 0;
	while((int)pq.size() > 1){
		long long sum = 0;
		int maxH = 0;
		for(int i = 0; i < k; i++){
			Node cur = pq.top();
			pq.pop();
			sum += cur.w;
			if(cur.h > maxH) maxH = cur.h;
		}
		total += sum;
		pq.push((Node){sum, maxH + 1});
	}

	Node root = pq.top();
	printf("%lld\n%d\n", total, root.h);
}
