// P1024 [NOIP 2001 提高组] 一元三次方程求解
/*
链接：https://www.luogu.com.cn/problem/P1024
知识点：二分法、枚举
*/
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

double a, b, c, d;

double f(double x){
	return a * x * x * x + b * x * x + c * x + d;
}

int main(){
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

	vector<double> gen;
	for(int i = -100; i < 100; i++){
		double l = i, r = i + 1;
		double fl = f(l), fr = f(r);

		if(fl == 0){
			gen.push_back(l);
		}else if(fl * fr < 0){
			// 二分求根
			double left = l, right = r;
			for(int j = 0; j < 100; j++){
				double mid = (left + right) / 2;
				double fm = f(mid);
				if(f(left) * fm <= 0){
					right = mid;
				}else{
					left = mid;
				}
			}
			gen.push_back(left);
		}
	}

	// 处理右端点 100 处的根
	if(f(100) == 0){
		gen.push_back(100.0);
	}

	sort(gen.begin(), gen.end());

	for(int i = 0; i < 3; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%.2f", gen[i]);
	}
	printf("\n");
}
