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

int main(){
	int n;
	int day = 0;
	int road;
	int hight = 0;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &road);
		if(road > hight){
			day += road - hight;
		}
		hight = road;
	}

	printf("%d\n", day);
}
