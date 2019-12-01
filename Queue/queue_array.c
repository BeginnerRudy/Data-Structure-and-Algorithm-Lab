/*
Date: Sunday, 1 December 2019

Queue Operations:
Enqueue
Dequeue
Front
is_empty
is_full
print_queue
print_queue_size
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct{
    int* data;
    int curr_count;
    int max_count;
}queue_t;

queue_t* make_queue(int size);
void enqueue(queue_t *queue, int data);
int dequeue(queue_t *queue);
int front(queue_t *queue);
int is_empty(queue_t *queue);
int is_full(queue_t *queue);
void print_queue(queue_t* queue);
void print_queue_size(queue_t* queue);

int main(){
    queue_t* queue = make_queue(2);
    print_queue_size(queue);

    for (int i = 0; i < 6; i++) {
        enqueue(queue, i);
        printf("enqueue(queue, %d)\n", i);
    }
    print_queue(queue);
    print_queue_size(queue);

    dequeue(queue);
    printf("dequeue the queue\n");
    print_queue(queue);
    print_queue_size(queue);

    front(queue);
    printf("front the queue\n");
    print_queue(queue);
    print_queue_size(queue);

    printf("===============================================\n");
    if (is_empty(queue)){
        printf("Current queue is empty.\n");
    }else{
        printf("Current queue is not empty.\n");
    }

    return 0;
}

queue_t *make_queue(int size){
    queue_t *queue = (queue_t*)malloc(sizeof(queue));
    assert(queue!=NULL);
    queue->data = (int*)malloc(size*sizeof(int));
    queue->curr_count = 0;
    queue->max_count = size;
    return queue;
}


int is_full(queue_t *queue){
    assert(queue!=NULL&&queue->data!=NULL);
    if (queue->curr_count==queue->max_count){
        return 1;
    }
    return 0;
}


int is_empty(queue_t* queue){
    assert(queue!=NULL&&queue->data!=NULL);
    return queue->curr_count==0;
}

void enqueue(queue_t *queue, int data){
    assert(queue!=NULL&&queue->data!=NULL);
    if (is_full(queue)){
        queue->data = (int*)realloc(queue->data, 2*queue->max_count*sizeof(int));
        queue->max_count *= 2;
    }

    queue->data[queue->curr_count] = data;
    queue->curr_count += 1;
}

int dequeue(queue_t *queue){
    assert(queue!=NULL&&queue->data!=NULL&&queue->curr_count>0);
    int data = queue->data[0];
    for (int i=0; i<queue->curr_count-1; i++){
        queue->data[i] = queue->data[i+1];
    }
    queue->curr_count -= 1;
    return data;
}

int front(queue_t *queue){
    assert(queue!=NULL&&queue->data!=NULL&&queue->curr_count>0);
    return queue->data[0];
}

void print_queue(queue_t* queue){
    assert(queue!=NULL&&queue->data!=NULL&&queue->curr_count>0);
    printf("===============================================\n");
    printf("Print out the queue from top to bottom\n" );
    for (int i=queue->curr_count-1; i>=0; i--){
        printf("[%d]: %d\n", i, ((int*)queue->data)[i]);
    }
    printf("===============================================\n");
}

void print_queue_size(queue_t* queue){
    assert(queue!=NULL&&queue->data!=NULL);
    printf("Current count in queue is %d\n", queue->curr_count);
    printf("Max size of the queue is %d\n", queue->max_count);
}
