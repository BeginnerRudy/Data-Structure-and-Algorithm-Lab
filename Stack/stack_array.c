/*
Date: Sunday, 1 December 2019
Time: 25 mins
*/

/*
Basic Operations:
push()
pop()
peek()
is_full()
is_empty()

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
    int* data;
    int curr_count;
    int max_count;
}stack_t;

stack_t *make_stack(int size);
void push(stack_t *stack, int data);
int pop(stack_t *stack);
int peek(stack_t *stack);
int is_full(stack_t *stack);
int is_empty(stack_t *stack);
void print_stack(stack_t* stack);
void print_stack_size(stack_t* stack);

int main(){
    stack_t* stack = make_stack(2);

    print_stack_size(stack);

    for (int i = 0; i < 6; i++) {
        push(stack, i);
        printf("push(stack, %d)\n", i);
    }


    print_stack(stack);
    print_stack_size(stack);


    pop(stack);
    printf("Pop the stack\n");
    print_stack(stack);
    print_stack_size(stack);

    peek(stack);
    printf("Peek the stack\n");
    print_stack(stack);
    print_stack_size(stack);

    printf("===============================================\n");
    if (is_empty(stack)){
        printf("Current stack is empty.\n");
    }else{
        printf("Current stack is not empty.\n");
    }
    return 0;
}

stack_t *make_stack(int size){
    stack_t *stack = (stack_t*)malloc(sizeof(stack));
    assert(stack!=NULL);
    stack->data = (int*)malloc(size*sizeof(int));
    stack->curr_count = 0;
    stack->max_count = size;
    return stack;
}


int is_full(stack_t *stack){
    assert(stack!=NULL&&stack->data!=NULL);
    if (stack->curr_count==stack->max_count){
        return 1;
    }
    return 0;
}


int is_empty(stack_t* stack){
    assert(stack!=NULL&&stack->data!=NULL);
    return stack->curr_count==0;
}

void push(stack_t *stack, int data){
    assert(stack!=NULL&&stack->data!=NULL);
    // check if the stack is is full
    if (is_full(stack)){
        stack->data = (int*)realloc(stack->data, 2*stack->max_count*sizeof(int));
        stack->max_count *= 2;
        stack->data[stack->curr_count] = data;
        stack->curr_count += 1;
    }else{
        stack->data[stack->curr_count] = data;
        stack->curr_count += 1;
    }
}


int pop(stack_t *stack){
    assert(stack!=NULL&&stack->data!=NULL&&stack->curr_count>0);
    int data = stack->data[stack->curr_count-1];
    stack->data[stack->curr_count-1] = 0;
    stack->curr_count -= 1;
    return data;
}

int peek(stack_t *stack){
    assert(stack!=NULL&&stack->data!=NULL&&stack->curr_count>0);
    int data = stack->data[stack->curr_count-1];
    return data;
}

void print_stack(stack_t* stack){
    assert(stack!=NULL&&stack->data!=NULL&&stack->curr_count>0);
    printf("===============================================\n");
    printf("Print out the stack from top to bottom\n" );
    for (int i=stack->curr_count-1; i>=0; i--){
        printf("[%d]: %d\n", i, ((int*)stack->data)[i]);
    }
    printf("===============================================\n");
}

void print_stack_size(stack_t* stack){
    assert(stack!=NULL&&stack->data!=NULL);
    printf("Current count in stack is %d\n", stack->curr_count);
    printf("Max size of the stack is %d\n", stack->max_count);
}
