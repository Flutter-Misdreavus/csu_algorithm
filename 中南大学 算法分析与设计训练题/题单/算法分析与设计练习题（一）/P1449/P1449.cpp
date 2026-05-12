#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    stack<int> num;
    int an = 0;
    int a, b;
    char ch;

    while((ch = getchar()) != '@'){
        if(isdigit(ch)){
            an *= 10;
            an += ch - '0';
        }
        else if(ch == '.'){
            num.push(an);
            an = 0;
        }
        else{
            b = num.top();
            num.pop();
            a = num.top();
            num.pop();

            if(ch == '+'){
                num.push(a + b);
            }else if(ch == '-'){
                num.push(a - b);
            }else if (ch == '*'){
                num.push(a * b);
            }else if (ch == '/'){
                num.push(a / b);
            }
            
        }
    }

    printf("%d\n", num.top());
}