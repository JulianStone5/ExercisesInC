#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} Node;

int compare_nodes(const void *a, const void *b) {
  Node **node_a = (Node **) a;
  Node **node_b = (Node **) b;
  return node_a[0]->val - node_b[0]->val;
}

int main() {
  Node **arr = malloc(3 *sizeof(Node));
  Node *a = malloc(sizeof(Node));
  a->val = 2;
  Node *b = malloc(sizeof(Node));
  b->val = 3;
  Node *c = malloc(sizeof(Node));
  c->val = 1;
  arr[0] = a;
  arr[1] = b;
  arr[2] = c;
  qsort((void*)arr, 3, sizeof(arr[0]),compare_nodes);
  printf("%d, %d, %d\n", arr[0]->val, arr[1]->val, arr[2]->val);
  return 0;
}
