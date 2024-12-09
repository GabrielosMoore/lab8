// list/list.h
// Interface definition for linked list.

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct block {
    int pid;   // pid
    int start;
    int end;
}block_t;

typedef struct node {
  block_t *blk;
  struct node *next;
}node_t;

struct list {
    node_t *head;
};
typedef struct list list_t;

list_t *list_alloc();
node_t *node_alloc(block_t *blk);
void list_free(list_t *l);
void node_free(node_t *node);
void list_print(list_t *l);
int list_length(list_t *l);
void list_add_to_back(list_t *l, block_t *blk);
void list_add_to_front(list_t *l, block_t *blk);
void list_add_at_index(list_t *l, block_t *blk, int index);
void list_add_ascending_by_address(list_t *l, block_t *blk);
void list_add_ascending_by_blocksize(list_t *l, block_t *blk);
void list_add_descending_by_blocksize(list_t *l, block_t *blk);
void list_coalese_nodes(list_t *l);
block_t* list_remove_from_back(list_t *l);
block_t* list_remove_from_front(list_t *l);
block_t* list_remove_at_index(list_t *l, int index);
bool list_is_in(list_t *l, block_t* blk);
bool list_is_in_by_size(list_t *l, int Size);
bool list_is_in_by_pid(list_t *l, int pid);
block_t* list_get_elem_at(list_t *l, int index);
int list_get_index_of(list_t *l, block_t* blk);
int list_get_index_of_by_Size(list_t *l, int Size);
int list_get_index_of_by_Pid(list_t *l, int pid);
block_t* list_get_from_front(list_t *l);

// helper compare functions
bool compareBlks(block_t* a, block_t *b);
bool compareSize(int a, block_t *b);
bool comparePid(int a, block_t *b);

#endif

