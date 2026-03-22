/* 
    题目
    1. 设计不同策略实现一种特殊的栈，使得入栈、出栈以及求栈的最小值均在O(1)的时间完成。
    2. 基于问题1，设计基于栈的排序算法。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

struct NUMBER{
    int value;
    int min; // 当前栈中的最小值
    struct NUMBER* last; // 指向上一个元素
};

struct NUMBER* minstack = NULL;
struct NUMBER* top = NULL; // 栈顶元素

void push(int value){
    struct NUMBER* new_number = (struct NUMBER*)malloc(sizeof(struct NUMBER));
    new_number->value = value;

    if(top == minstack){ // 如果栈为空
        new_number->min = value; // 当前元素即为最小值
    } else {
        if (top->min < value){
            new_number->min = top->min; // 继承上一个元素的最小值
        } else {
            new_number->min = value; // 当前元素为新的最小值
        }
    }

    new_number->last = top; // 将新元素的last指向当前栈顶
    top = new_number; // 更新栈顶为新元素

    return;
}

int get(){
    if(top == minstack){
        printf("栈为空\n");
        return 0;
    }

    return top->value;
}

int get_min(){
    if(top == minstack){
        printf("栈为空\n");
        return 0;
    }

    return top->min; // 返回当前栈顶元素的最小值
}

int pop(){
    if(top == minstack){
        printf("栈为空\n");
        return 0;
    }

    int value = top->value;
    top = top->last;
    return value;
}

int pop_min(){
    if(top == minstack){
        printf("栈为空\n");
        return 0;
    }

    int min = get_min(); // 获取当前最小值
    std::stack<int> temp_stack; // 临时栈用于存储出栈的元素

    // 找到栈中的最小值并将其出栈
    while (top != minstack) {
        if (get() == min){
            pop(); // 出栈最小值
            break;
        } else {
            temp_stack.push(pop()); // 将非最小值压入临时栈并且出栈
        }
    }

    while(temp_stack.size() > 0){
        push(temp_stack.top()); // 将临时栈中的元素重新压入主栈
        temp_stack.pop();
    }

    return min;
}

int main(){
    minstack = (struct NUMBER*)malloc(sizeof(struct NUMBER)); // 初始化栈底
    top = minstack; // 栈顶初始指向栈底

    int test_values[] = {7, 23, 6, 8, 9, 3, 5, 2, 1, 4};
    for (int i = 0; i < 10; i++) {
        push(test_values[i]);
        printf("Pushed: %d, Current Min: %d\n", test_values[i], get_min());
    }

    printf("\n");

    // 测试出栈和获取最小值
    printf("Popped: %d, Current Min: %d\n", pop(), get_min());
    printf("Popped: %d, Current Min: %d\n", pop(), get_min());
    printf("Popped Min: %d\n", pop_min());
    printf("Current Min %d\n", get_min());
    printf("Popped: %d, Current Min: %d\n", pop(), get_min());

    // 排序
    int test_array[] = {5, 2, 9, 1, 5, 6};
    int sorted_array[6];
    for (int i = 0; i < 6; i++) {
        push(test_array[i]);
    }
    for(int i = 0; i < 6; i++){
        sorted_array[i] = pop_min(); // 每次出栈最小值
    }
    for(int i = 0; i < 6; i++){
        printf("%d ", sorted_array[i]);
    }
}