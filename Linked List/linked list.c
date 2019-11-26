/* Tuesday, 26 November 2019. Cost: 2hours

Implementation of one-way linked list

    make_empty_list
    is_empty_list
    free_list
    insert_at_head
    insert_at_foot
    get_head
    get_tail
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*Define the node_t and list_t structure for the one-way linked list.*/
typedef struct node node_t;

struct node{
    void* data;
    node_t* next;
};

typedef struct{
    node_t* head;
    node_t* tail;
}list_t;

/*                        Function prototype                           */
// return a pointer to an empty list, an empty is that both head and tail are null.
list_t* make_empty_list();
// return 1 for an empty list, otherwise return 0
int is_empty_list(list_t* list);
// make all pointers in the linked list to be NULL
void free_list(list_t* list);
// insert data at the head of the linked list.
void insert_at_head(list_t* list, void* data);
// insert data at the tail of the linked list.
void insert_at_foot(list_t* list, void* data);
// return the data at the head of the linked list without altering the list.
void* get_head(list_t* list);
// return the data at the head of the likned list and remove the head of the list.
void* pop_head(list_t* list);
// return the data at the tail of the linked list without altering the list.
void* get_tail(list_t* list);
// return the data at the tail of the likned list and remove the tail of the list.
void* pop_tail(list_t* list);
// find a node in list that before given node, assume such node must exists.
node_t* find_node_before(list_t* list, node_t* node);
// print the linked list from head to tail one by one.
void print_linked_list_head_to_tail(list_t* list);
// print the linked list from tail to head one by one.
void print_linked_list_tail_to_head(list_t* list);
// seach for a given data, if not found return NULL
node_t* search_list(list_t* list, void* data);
// delete the first occurence of a given data if exists;
node_t* remove_from_list(list_t* list, void* data);

/*                      The Main Function                               */
int main(int argc, char* argv[]){
    list_t* list = make_empty_list();
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int len = sizeof(data)/sizeof(data[0]);
    for (int i=0; i<len; i++){

    insert_at_foot(list, &data[i]);
    }


    if (is_empty_list(list)){
        printf("List is empty.\n");
    }else{
        printf("List is not empty.\n");
        // printf("The head is %d\n", *(int*)pop_head(list));
        printf("The tail is %d\n", *(int*)pop_tail(list));
        int y = 14;
        remove_from_list(list, &y);
        print_linked_list_head_to_tail(list);
        print_linked_list_tail_to_head(list);
    }

    int x = 13;
    node_t *result = search_list(list, &x);
    if (result==NULL){
        printf("%d is not found in the list\n", x);
    }else{
        printf("%d is found in the list\n", x);
    }


    return 0;
}

/*                  Implementation of the Linked List                   */
list_t* make_empty_list(){
    // Declare a pointer to a list
    list_t* list;
    // Allocate memory for the list and assign it to list
    list = (list_t*)malloc(sizeof(list_t));
    // Leave head and tail to be null
    assert(list != NULL);
    list->head = NULL;
    list->tail = NULL;

    return list;
}

int is_empty_list(list_t* list){
    assert(list!=NULL);
    return (list->head == NULL && list->tail == NULL);
}

void insert_at_head(list_t* list, void* data){
    assert(list!=NULL);
    // make a new node for insert
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = data;

    // head is NULL
    if (list->head == NULL){
        list->head = node;
        list->tail = node;
    }else{
    // head is not NULL
        node->next = list->head;
        list->head = node;
    }
}


void insert_at_foot(list_t* list, void* data){
    assert(list!=NULL);
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    // foot is NULL
    if (list->tail == NULL){
        list->head = node;
        list->tail = node;
    }else{
    // foot is not NULL
        list->tail->next = node;
        list->tail = node;
    }
}


void print_linked_list_head_to_tail(list_t* list){
    assert(list!=NULL);
    node_t* node = list->head;
    while (node != NULL){
        printf(" %d ->", *((int*)node->data));
        node = node->next;
    }
    printf(" NULL\n");
}


void print_linked_list_tail_to_head(list_t* list){
    assert(list!=NULL && list->head!=NULL);
    // create a new linked list that is a reverse of the given linked list
    list_t* reverse_list = make_empty_list();

    node_t* node = list->head;
    while (node!=NULL) {
        insert_at_head(reverse_list, node->data);
        node = node->next;
    }

    print_linked_list_head_to_tail(reverse_list);
    free_list(reverse_list);
}


void free_list(list_t* list){
    if (list == NULL){
        return;
    }

    // If head is NULL
    if (list->head == NULL){
        return;
    }else{
        // Free each node
        node_t* curr_node = list->head, *next_node;
        while (curr_node!=NULL) {
            next_node = curr_node->next;
            free(curr_node);
            curr_node=next_node;
        }
    }

    // Free the list
    free(list->head);
    free(list->tail);
    free(list);
}

void* get_head(list_t* list){
    assert(list!=NULL && list->head!=NULL);
    return list->head->data;
}

void* pop_head(list_t* list){
    assert(list!=NULL && list->head!=NULL);
    node_t* old_head = list->head;
    void* data = old_head->data;

    // if only one node in the list
    if (old_head->next==NULL){
        list->head = list->tail = NULL;
    }else{
        list->head = old_head->next;
    }

    free(old_head);
    return data;
}

void* get_tail(list_t* list){
    assert(list!=NULL && list->tail!=NULL);
    return list->tail->data;
}

void* pop_tail(list_t* list){
    assert(list!=NULL && list->tail!=NULL);
    node_t* old_tail = list->tail;
    void* data = old_tail->data;

    // if the list contains only one node
    if (list->head == old_tail){
        list->tail = list->head = NULL;
    }else{
        // NOT EAST TO DO THIS :< LOL.
        list->tail = find_node_before(list, old_tail);
        list->tail->next = NULL;
    }

    free(old_tail);
    return data;
}

node_t* find_node_before(list_t* list, node_t* node){
    assert(list!=NULL && node!=NULL && list->head!=node);

    node_t* curr_node = list->head;
    while (curr_node->next != node) {
        curr_node = curr_node->next;
    }

    return curr_node;
}

node_t* search_list(list_t* list, void* data){
    assert(list!=NULL);
    if(list->head==NULL){
        return NULL;
    }else{
        node_t* node = list->head;
        while (node!=NULL) {
            if (*(int*)(node->data) == *(int*)data){
                return node;
            }
            node = node->next;
        }
    }
    return NULL;
}


node_t* remove_from_list(list_t* list, void* data){
    assert(list!=NULL);
    node_t* node;
    if (list->head==NULL){
        return NULL;
    }else{
        node = list->head;
        while (node!=NULL) {
            if (*(int*)(node->data) == *(int*)data){
                break;
            }
            node = node->next;
        }
    }

    if (node!=NULL){
        if (list->head == node){
            pop_head(list);
        }else{
            node_t* prev_node = find_node_before(list, node);
            if (list->tail == node){
                list->tail = prev_node;
                prev_node->next = NULL;
            }else{
                prev_node->next = node->next;
            }
        }
    }

    return node;
}
