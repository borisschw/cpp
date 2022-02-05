#include <stdio.h>
#include <stdlib.h>

struct myQueue
{
    int num;
    myQueue* next;
};

myQueue* queue = NULL; // holding th ehead of the list

myQueue* create_node(int data)
{
    myQueue* head = (myQueue*)malloc(sizeof(myQueue));
    head->num = data;
    head->next = NULL;
    return head;
}


void push(int num)
{
    myQueue* tmp = create_node(num);

    if (!(queue)) // if the first
    {
        queue = tmp;
    }
    else
    {
        tmp->next = queue;
        queue = tmp;
    }
}


int pop()
{
    int ret = 0;
    myQueue* tmp = queue;
    if(!queue)
        ret = -1;
    ret = queue->num;
    queue = queue->next;
    free(tmp);
    return ret;
}



int main()
{

    for(int i=0; i<10;i++)
        push(i);
    for(int i=0; i<10;i++)
        printf("%d\n",pop());
    return 0;
}

