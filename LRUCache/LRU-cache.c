#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key, val;
  struct Node *next;
  struct Node *prev;
  struct Node *next;
}NODE;

typedef struct {
  int cap, size;
  NODE *head;
  NODE*tail;
  NODE* map[10001];
} LRUCache;

void removeNode(LRUCache * obj, NODE *node)
{
  if(node->prev) node->prev->next = node->next;
  else {
    obj->head = node->next;
  }
  if (node->next) node->next->prev = node->prev;
  else {
    obj->tail = node->prev;
  }
  node->prev = NULL;
  node->next = NULL;
}

void InsertAtFront(LRUCache *obj, NODE* node)
{
  node->prev = NULL;
  node->next = obj->head;

  if(obj->head) obj->head->prev = node;
  else {
    obj->tail = node;
  }
  obj->head = node;
}


LRUCache* lRUCacheCreate(int capacity) {
  LRUCache *l = calloc(1, sizeof(LRUCache));
  l->cap = capacity;
  return l;
}

int lRUCacheGet(LRUCache* obj, int key) {
  NODE* node = obj->map[key];
  if(node == NULL) return -1;

  removeNode(obj, node);
  InsertAtFront(obj, node);

  return node->val;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if(obj->cap == 0) return; //empty 
    NODE* node = obj->map[key];

  if(node){
    node->val = value;
    removeNode(obj, node);
    InsertAtFront(obj, node);
    return;
  }

  if(obj->size == obj->capacity) {
    NODE* oldNode = obj->tail;
    obj->map[oldNode->key] = NULL;
    removeNode(obj, oldNode);
    free(oldNode);
    obj->size--;
  }

  NODE* newN = calloc(1,sizeof(NODE));
  newN-> key = key;
  newN->val = value;

  InsertAtFront(obj, newN);
  obj->map[key] = newN;
  obj->size++;
}


void lRUCacheFree(LRUCache* obj) {
  NODE *cur = obj->head;
  while(cur){
    NODE* tmp = cur;
    cur = cur->next;
    free(tmp);
  }

  free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
