#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 4

struct queue{
    int data[MAX_SIZE];
    int rear, front, size;
};

void enqueue(struct queue *q, int);
int isFull(struct queue *q);
int isEmpty(struct queue *q);
int dequeue(struct queue *q);
void display(struct queue *q);

int main(){
    int choice, ele, ch;
    
    struct queue q1;
    q1.front=0;
    q1.rear=-1;
    q1.size=0;
    
    do {
        printf("1.enqueue\n2.dequeue\n3.isFull\n4.isEmpty\n5.Display\n6.exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to Insert\n");
                scanf("%d", &ele);
                enqueue(&q1, ele);
                break;

            case 2: {
                int x1 = dequeue(&q1);
                if (x1 != -1) {
                    printf("%d element is deleted\n", x1);
                } else {
                    exit(0);
                }
                break;
            }

            case 3:
                if (isFull(&q1)) {
                    printf("Queue is Full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;

            case 4:
                if (isEmpty(&q1)) {
                    printf("Queue is Empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;

            case 5:
                display(&q1);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }

        printf("Do you want to continue? (0 to continue & 1 to exit)\n");
        scanf("%d", &ch);
        if (ch == 1) {
            break;
        }
    } while (1);

}

void enqueue(struct queue *q, int ele){
    if(isFull(q)){
        printf("queue is full\n");
        exit(0);
    }else{
        q->rear=(q->rear+1)%MAX_SIZE;
        q->data[q->rear]=ele;
        q->size++;
    }
}

int isFull(struct queue *q){
    return q->size==MAX_SIZE;
}

int isEmpty(struct queue *q){
    return q->size==0;
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("queue is empty");
        exit(0);
    }else{
        int x=q->data[q->front];
        q->front=(q->front+1)%MAX_SIZE;
        q->size--;
        return x;
    }
}

void display(struct queue *q){
    if(isEmpty(q)){
        int n=1;
        int i= q->front;
        while(n<=q->size){
            printf("%d--> ", q->data[i]);
            i=(i+1)%MAX_SIZE;
            n++;
        }
    }
}


