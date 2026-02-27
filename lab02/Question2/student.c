#include "Student.h"
#include <stdlib.h>   // malloc, free
#include <stdbool.h>  // bool

MyCircularQueue* myCircularQueueCreate(int k) {
    if (k <= 0) return NULL;

    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if(!obj) return NULL;

    obj -> data = (int*)malloc(sizeof(int)*k);
    if (!obj->data) {
        free(obj);
        return NULL;
    }

    obj->capacity = k;
    obj->head = 0;
    obj->tail = 0;
    obj->size = 0;

    return obj;

}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (!obj || obj->size == obj->capacity) {
        return false;  // full
    }

    obj->data[obj->tail] = value;
    obj->tail = (obj->tail + 1) % obj->capacity;
    obj->size++;

    return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (!obj || obj->size == 0) {
        return false;  // empty
    }

    obj->head = (obj->head + 1) % obj->capacity;
    obj->size--;

    return true;
}


int myCircularQueueFront(MyCircularQueue* obj) {
    if (!obj || obj->size == 0) {
        return -1;
    }

    return obj->data[obj->head];

}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (!obj || obj->size == 0) {
        return -1;
    }

    // tail points to next insertion position,
    // so last element is (tail - 1 + capacity) % capacity
    int index = (obj->tail - 1 + obj->capacity) % obj->capacity;
    return obj->data[index];

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (!obj) return true;
    return obj->size == 0;

}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (!obj) return false;
    return obj->size == obj->capacity;
 
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (!obj) return;

    free(obj->data);
    free(obj);
  
}
