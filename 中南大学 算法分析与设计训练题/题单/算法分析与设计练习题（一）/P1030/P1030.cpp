#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

struct TREE{
	char ch;
	TREE* left;
	TREE* right;
};

char qian1[10];
char zhong1[10];
char hou1[10];

string qian;
string zhong;
string hou;

TREE* find_tree(int houf, int zhonga, int zhongb){
	TREE* head = (TREE*)malloc(sizeof(TREE));
	head->ch = hou[houf];
	head->left = NULL;
	head->right = NULL;

	if(zhonga == zhongb){
		return head;
	}

	int poshead = zhongb;
	while(zhong[poshead] != hou[houf]){
		poshead--;
	}

	if(poshead != zhongb){
		// 有右子树
		head->right = find_tree(houf - 1, poshead + 1, zhongb);
	}

	if(poshead != zhonga){
		// 有左子树
		head->left = find_tree(houf - 1 - zhongb + poshead, zhonga, poshead - 1);
	}

	return head;
}

void show(TREE* head){
	if(head == NULL){
		return;
	}

	printf("%c", head->ch);

	show(head->left);
	show(head->right);
}

int main(){
	scanf("%s", zhong1);
	scanf("%s", hou1);

	zhong = zhong1;
	hou = hou1;

	TREE* head = find_tree(hou.size() - 1, 0, zhong.size() - 1);
	show(head);
	printf("\n");
}
