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

int ditu[1030][1030];

void draw0(int x1, int y1, int size){
	int x2 = 1 << size;
	int y2 = 1 << size;
	x2 += x1;
	y2 += y1;

	for(int i = x1; i < x2; i++){
		for(int j = y1; j < y2; j++){
			ditu[i][j] = 0;
		}
	}
}

void drawz(int x1, int y1, int size){
	if(size == 0){
		ditu[x1][y1] = 1;
		return;
	}

	size--;
	int xadd = 1 << size;
	int yadd = 1 << size;

	draw0(x1, y1, size);
	drawz(x1 + xadd, y1, size);
	drawz(x1, y1 + yadd, size);
	drawz(x1 + xadd, y1 + yadd, size);

	return;
}

int main(){
	int n;
	scanf("%d", &n);

	int x2 = 1 << n;
	int y2 = 1 << n;
	drawz(0, 0, n);

	for(int i = 0; i < x2; i++){
		for(int j = 0; j < y2; j++){
			printf("%d ", ditu[i][j]);
		}
		printf("\n");
	}

}
