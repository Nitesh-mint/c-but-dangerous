#include <stdio.h>
#include <stdlib.h>

struct MaxHeap {
  int *data;
  int size;
  int capacity;
};

struct MaxHeap *HEAP_INIT() {
  struct MaxHeap *maxHeap = malloc(sizeof(struct MaxHeap));

  if (maxHeap == NULL) {
    return NULL;
  }
  maxHeap->size = 0;
  maxHeap->capacity = 10;
  maxHeap->data = malloc(sizeof(int) * maxHeap->capacity);

  printf("----- The Heap is Initialized succesfully!\n");
  return maxHeap;
}

int getParentIndex(int i) {
  if (i == 0) {
    return 0;
  }
  return (i - 1) / 2;
}

int getleftchild(int i) { return 2 * i + 1; }
int getrightchild(int i) { return 2 * i + 2; }

int HEAP_ADD(struct MaxHeap *maxHeap, int number) {
  if (maxHeap == NULL) {
    printf("The Heap is not Initialized cannot insert!");
  }

  if (maxHeap->capacity == maxHeap->size) {
    int newCap = maxHeap->capacity * 2;
    int *newData = realloc(maxHeap->data, sizeof(int) * newCap);
    if (newData != NULL) {
      maxHeap->data = newData;
      maxHeap->capacity = newCap;
    } else {
      return -1;
    }
  }

  int currentIndex = maxHeap->size;
  int parentIndex = getParentIndex(currentIndex);

  if (number <= maxHeap->data[parentIndex]) {
    maxHeap->data[currentIndex] = number;
    maxHeap->size++;
    return 1;
  }

  while (number > maxHeap->data[parentIndex]) {
    maxHeap->data[currentIndex] = maxHeap->data[parentIndex];
    maxHeap->data[parentIndex] = number;
    currentIndex = parentIndex;
    parentIndex = getParentIndex(currentIndex);
  }

  maxHeap->size++;
  return 1;
}

void HEAP_PRINT(struct MaxHeap *maxHeap) {
  int size = maxHeap->size;
  for (int i = 0; i < size; i++) {
    printf("%d \n", maxHeap->data[i]);
  }
}

int main(void) {
  struct MaxHeap *maxHeap = HEAP_INIT();
  HEAP_ADD(maxHeap, 10);
  HEAP_ADD(maxHeap, 20);
  HEAP_ADD(maxHeap, 5);
  HEAP_ADD(maxHeap, 30);
  // HEAP_ADD(maxHeap, 7);
  HEAP_PRINT(maxHeap);
  return 0;
}
