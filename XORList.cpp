#include <bits/stdc++.h> 
#include <cinttypes>
using namespace std;
class Node
{ public: int data;
Node *npx;
};
Node *XOR(Node *a,Node *b)
{
return reinterpret_cast<Node *>(reinterpret_cast<uintptr_t>(a)^reinterpret_cast<uintptr_t>(b));
}
void insert_beg(Node **head_ref,int data)
{
Node *new_node = new Node(); new_node->data = data;
new_node->npx = *head_ref;
if(*head_ref != NULL)
(*head_ref)->npx = XOR(new_node , (*head_ref)->npx);
*head_ref = new_node;
}
void display (Node *head)
{
Node *curr = head;
Node *prev = NULL; Node *next;
cout << "Linked List: \n";
while (curr != NULL)
{
cout<<curr->data<<" "; next = XOR (prev, curr->npx);
prev = curr; curr = next;
}
}
int main()
{
Node *head = NULL; int num , n; cout << "Enter the number of elements: "; cin >> n; for(int i=0;i<n;i++)
{
cout << "Enter the number: "; cin >> num; insert_beg(&head,num);
} display (head);
return (0);
}