#include <stdio.h>
#include <stdlib.h>

// 双向循环链表 
struct Node {
    int data;  //数据域
    Node *prior; //指向前驱结点的指针
    Node *next;  //指向后继结点的指针
};

void init(Node  **mylist)
{
    *mylist = new Node;
    (*mylist)->data = 0;
    (*mylist)->prior = *mylist;
    (*mylist)->next = *mylist;
}

// 插入元素操作
bool insert(Node *mylist, int i, int data)
{
    // 判断链表是否存在
    if (!mylist)
    {
        printf("list not exist!\n");
        return false;
    }
    // 只能在位置1以及后面插入，所以i至少为1
    if (i < 1)
    {
        printf("i is invalid!\n");
        return false;
    }

    // 找到i位置所在的前一个结点
    Node *front = mylist; // 这里是让front与i不同步，始终指向j对应的前一个结点
    for (int j = 1; j < i; j++) {
        front = front->next;
        if (front == mylist)
        {
            printf("dont find front!\n");
            return false;
        }
    }
        
    // 创建一个空节点，存放要插入的新元素
    Node *s = new Node;
    s->data = data;

    // 插入结点
    s->prior = front;
    s->next = front->next;
    front->next->prior = s;
    front->next = s;

    return true;
}

// 删除元素操作
Node * deleteNode(Node *mylist, int i)
{
    // 找到i位置所在的前一个结点
    Node *front = mylist, *s; 
    for (int j = 1; j < i; j++) 
    {
        front = front->next;
        if (front->next == mylist)
        {
            printf("dont find front!\n");
            return NULL;
        }
    }

    s=front->next;
    
    front->next->prior = front;
    front->next = front->next->next;

    return s;
}

// 头部插入元素操作
bool insert(Node  *mylist, int data)
{
    Node *head;
    Node *s;

	head = mylist;

    // 创建存放插入元素的结点
    s = new Node;
    s->data = data;

    // 头结点后插入结点
    s->prior = head;
    s->next = head->next;
    head->next->prior = s;
    head->next = s;

    return true;
}

// 遍历链表操作
void print(Node *mylist)
{
    Node *cur = mylist->next;
    while (cur != mylist)
    {
        printf("<-->%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    Node  *mylist;

    // 初始化链表
    init(&mylist);
    for (int i = 0; i < 6; i++)
    {
        insert(mylist, i+1);
    }

	print(mylist);
	
    // 插入结点
    insert(mylist, 1, 9);

    print(mylist);
    printf("\n");

    // 删除结点
	int val;
    deleteNode(mylist, 2);
    print(mylist);
    printf("\n");

    return 0;
}
