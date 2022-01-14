#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void inseretAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void insterAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int length(node *head){
    int l = 0;
    node *temp = head;
    while(temp!=NULL){
        l++;
        temp = temp->next;
    }
    return l;
}
node* kappend(node*&head,int k){
    node *newHead;
    node *newTail;
    node *tail = head;
    int l = length(head);
    k = k % l;
    int count = 1;
    while(tail->next!=NULL){
        if(count==l-k){
            newTail = tail; 
        }
        if(count==l-k+1){
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

int main()
{
    node *head = NULL;

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n;i++){
        insterAtTail(head, arr[i]);
    }

    display(head);

    node *newhead = kappend(head,3);
    display(newhead);
    return 0;
}