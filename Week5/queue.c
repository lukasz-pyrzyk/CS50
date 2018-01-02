typedef struct
{
    int front;
    int numbers[CAPACITY];
    int size;
}
queueWithArray;

typedef struct
{
    int front;
    int *numbers;
    int size;
}
queue;