#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

char tu[2048][2048];

void draw(int x, int y, int rank){
    if(rank == 1){
        // 如果阶数为1，直接画
        tu[x][y] = ' ';
        tu[x][y+1] = '/';
        tu[x][y+2] = '\\';
        tu[x+1][y] = '/';
        tu[x+1][y+1] = '_';
        tu[x+1][y+2] = '_';
        tu[x+1][y+3] = '\\';

        return;
    }

    // 如果阶数不是1，递归调用
    // 采用位运算提高速度，相当于2的幂
    draw(x, y + (2 << (rank - 2)), rank - 1);
    draw(x + (2 << (rank - 2)), y, rank - 1);
    draw(x + (2 << (rank - 2)), y + (2 << (rank - 1)), rank - 1);

    return;
}

int main(){
    int rank;
    memset(tu, ' ', sizeof(tu));

    scanf("%d", &rank);
    draw(0, 0, rank);

    for(int i = 0; i < (2 << (rank - 1)); i++){
        for(int j = 0; j < (2 << rank); j++){
            printf("%c", tu[i][j]);
        }
        printf("\n");
    }
}