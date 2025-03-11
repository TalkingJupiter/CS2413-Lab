typedef struct {
    int* queue1;
    int* queue2;
    int front1;
    int rear1;
    int front2;
    int rear2;
    int capacity;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->capacity = 100;
    stack->queue1 = (int*)malloc(stack->capacity * sizeof(int));
    stack->queue2 = (int*)malloc(stack->capacity * sizeof(int));
    stack->front1 = stack->rear1 = -1;
    stack->front2 = stack->rear2 = -1;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->queue1[++obj->rear1] = x;
    if (obj->front1 == -1) obj->front1 = 0;
}

int myStackPop(MyStack* obj) {
    while (obj->front1 != obj->rear1) {
        obj->queue2[++obj->rear2] = obj->queue1[obj->front1++];
    }
    int popped = obj->queue1[obj->front1];
    
    obj->front1 = obj->rear1 = -1;
    
    int* tempQueue = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = tempQueue;
    obj->front1 = (obj->rear2 == -1) ? -1 : 0;
    obj->rear1 = obj->rear2;
    obj->front2 = obj->rear2 = -1;
    
    return popped;
}

int myStackTop(MyStack* obj) {
    return obj->queue1[obj->rear1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->rear1 == -1;
}

void myStackFree(MyStack* obj) {
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}

