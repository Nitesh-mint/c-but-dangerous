#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Vector {
  int *data;
  int size;
  int capacity;
};

struct Vector *Vector_Init() {
  struct Vector *vector = malloc(sizeof(struct Vector));
  if (vector == NULL)
    return NULL;

  vector->size = 0;
  vector->capacity = 5;
  vector->data = malloc(sizeof(int) * vector->capacity);
  return vector;
}

void Vector_Add(int value, struct Vector *vector) {
  if (vector == NULL)
    return;

  // Check if the vector is full
  if (vector->size == vector->capacity) {
    // realloc it with double the size of the current array;
    int newCapacity = vector->capacity * 2;

    int *newData = realloc(vector->data, sizeof(int) * newCapacity);

    if (newData != NULL) {
      vector->data = newData;
      vector->capacity = newCapacity;
    } else {
      return;
    }
  }
  vector->data[vector->size] = value;
  vector->size++;
  printf("The %d is added to the memory: %d\n", value, vector->size - 1);
}

void Vector_Get(struct Vector *vector, int index) {
  if (vector == NULL) {
    printf("The vector is null\n");
    return;
  }
  if (index < 0 || index > vector->size - 1) {
    printf("The index is out of range for the vector to handle\n");
    return;
  }
  printf("The item at %d is %d\n", index, vector->data[index]);
}

// update the value at specific index
void Vector_Set(struct Vector *vector, int index, int value) {
  if (vector == NULL) {
    printf("The vector is null\n");
    return;
  }
  if (index < 0 || index > vector->size - 1) {
    printf("The index is out of range for the vector to handle\n");
    return;
  }
  int oldValue = vector->data[index];
  vector->data[index] = value;
  printf("The value at the index %d is update from %d to %d\n", index, oldValue,
         vector->data[index]);
}

void Vector_Pop(struct Vector *vector) {
  if (vector == NULL || vector->size == 0)
    return;
  vector->size--;
  if (vector->size > 0 && vector->size == vector->capacity / 2) {
    float newCapacity = round(vector->capacity / 2.0);

    int *newData = realloc(vector->data, sizeof(int) * newCapacity);
    if (newData != NULL) {
      vector->data = newData;
      vector->capacity = newCapacity;
    }
  }
}

void Vector_Destroy(struct Vector *vector) {
  if (vector == NULL)
    return;
  // start freeing from the root nodes;
  free(vector->data);
  vector->size = 0;
  vector->data = NULL;
  vector->capacity = 0;
}

int main(void) {
  struct Vector *vector = Vector_Init();
  Vector_Add(1, vector);
  Vector_Add(2, vector);
  Vector_Add(3, vector);
  Vector_Add(4, vector);
  Vector_Get(vector, 0);
  Vector_Get(vector, 2);
  Vector_Set(vector, 2, 6);
  printf("Size of vector: %d\n", vector->size);
  Vector_Destroy(vector);
  free(vector);
  return 0;
}
