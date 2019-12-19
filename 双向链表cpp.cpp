#include <stdio.h>
#include <stdlib.h>

// ˫��ѭ������ 
struct Node {
    int data;  //������
    Node *prior; //ָ��ǰ������ָ��
    Node *next;  //ָ���̽���ָ��
};

void init(Node  **mylist)
{
    *mylist = new Node;
    (*mylist)->data = 0;
    (*mylist)->prior = *mylist;
    (*mylist)->next = *mylist;
}

// ����Ԫ�ز���
bool insert(Node *mylist, int i, int data)
{
    // �ж������Ƿ����
    if (!mylist)
    {
        printf("list not exist!\n");
        return false;
    }
    // ֻ����λ��1�Լ�������룬����i����Ϊ1
    if (i < 1)
    {
        printf("i is invalid!\n");
        return false;
    }

    // �ҵ�iλ�����ڵ�ǰһ�����
    Node *front = mylist; // ��������front��i��ͬ����ʼ��ָ��j��Ӧ��ǰһ�����
    for (int j = 1; j < i; j++) {
        front = front->next;
        if (front == mylist)
        {
            printf("dont find front!\n");
            return false;
        }
    }
        
    // ����һ���սڵ㣬���Ҫ�������Ԫ��
    Node *s = new Node;
    s->data = data;

    // ������
    s->prior = front;
    s->next = front->next;
    front->next->prior = s;
    front->next = s;

    return true;
}

// ɾ��Ԫ�ز���
Node * deleteNode(Node *mylist, int i)
{
    // �ҵ�iλ�����ڵ�ǰһ�����
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

// ͷ������Ԫ�ز���
bool insert(Node  *mylist, int data)
{
    Node *head;
    Node *s;

	head = mylist;

    // ������Ų���Ԫ�صĽ��
    s = new Node;
    s->data = data;

    // ͷ���������
    s->prior = head;
    s->next = head->next;
    head->next->prior = s;
    head->next = s;

    return true;
}

// �����������
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

    // ��ʼ������
    init(&mylist);
    for (int i = 0; i < 6; i++)
    {
        insert(mylist, i+1);
    }

	print(mylist);
	
    // ������
    insert(mylist, 1, 9);

    print(mylist);
    printf("\n");

    // ɾ�����
	int val;
    deleteNode(mylist, 2);
    print(mylist);
    printf("\n");

    return 0;
}
