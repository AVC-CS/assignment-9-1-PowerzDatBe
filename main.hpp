#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Node
{
    double value;
    struct Node *next;
};

struct Node *makeNumbers(int N);
void printNumbers(struct Node *head);
int getLength(struct Node *head);
struct Node *sortNumbers(struct Node *head);
void swapNode(struct Node *prev, struct Node *ptr);

struct Node *makeNumbers(int N)
{
    struct Node *head, *tmp, *prev;
    srand(time(0));
    for(int i = 0; i < N; i++) {
        tmp = (struct Node *)malloc(sizeof(struct Node));   //during each loop - alloc mem to pointer tmp for struct Node
        tmp->value = rand() % 100;  //assign a random number to double value in struct Node
        tmp->next = NULL;   //next in struct Node assigned with NULL
        if(i == 0) {    //If first loop, the first node(tmp) assigned to pointer head
            head = tmp;
        }
        else {  //else, pointer prev at node next pointing to pointer tmp
            prev->next = tmp;
        }
        prev = tmp; //pointer prev assigned with pointer tmp
    }
    return head;
}
void printNumbers(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->value << "\t";
        ptr = ptr->next;
    }
    cout << endl;
}

int getLength(struct Node *head)
{
    struct Node *ptr = head;
    int cnt = 0;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

struct Node *sortNumbers(struct Node *head)
{
    struct Node *ptr, *after;
    bool swapped = true;

    while(swapped) {
        swapped = false;
        ptr = head;
        after = ptr->next;
        while(after != nullptr) {
            if(ptr->value > after->value) {
                swapNode(ptr, after);
                swapped = true;
            }
            ptr = ptr->next;
            after = after->next;
        }
    }
    
    return head;
}

void swapNode(struct Node *prev, struct Node *ptr)
{
    double temp = prev->value;
    prev->value = ptr->value;
    ptr->value = temp;
}