#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

long long int w[22][22][22];

long long int getw(long long int a, long long int b, long long int c){
	if(a <= 0 || b <= 0 || c <= 0){
		return 1;
	}

	if(a > 20 || b > 20 || c > 20){
		return w[20][20][20];
	}

	return w[a][b][c];
}

void iniw(){
	for(int a = 1; a <= 20; a++){
		for(int b = 1; b <= 20; b++){
			for(int c = 1; c <= 20; c++){
				if(a < b && b < c){
					w[a][b][c] = getw(a, b, c - 1) + getw(a, b - 1, c - 1) - getw(a, b - 1, c);
				}else{
					w[a][b][c] = getw(a - 1, b, c) + getw(a - 1, b - 1, c) + getw(a - 1, b, c - 1) - getw(a - 1, b - 1, c -  1);
				}
			}
		}
	}
}

int main(){
	long long int a, b, c;
	iniw();

	while(1){
		scanf("%lld%lld%lld", &a, &b, &c);
		if(a == -1 && b == -1 && c == -1){
			break;
		}

		printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, getw(a, b, c));
	}
}
