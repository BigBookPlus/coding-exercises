#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    Node* prev=nullptr;
    Node* next=nullptr;
    int value;
}Node;

Node* table[100005];



int main()
{
    memset(table, 0, sizeof(table));
    Node* head = new Node;
    head->value=1;
    table[1]=head;
    int n,m;
    int k,p;

    cin>>n;
    for(int i=2;i<=n;++i)
    {
        cin>>k>>p;
        //cout<<k<<" "<<p<<endl;
        Node* node = new Node;
        node->value=i;
        table[i]=node;
        Node* cur = table[k];
        //cout<<cur->value<<endl;
        if(p==0)
        {
            node->prev=cur->prev;
            cur->prev=node;
            node->next=cur;
            if(node->prev!=nullptr)
                node->prev->next=node;
        }
        else if(p==1)
        {
            node->next=cur->next;
            cur->next=node;
            node->prev=cur;
            if(node->next!=nullptr)
                node->next->prev=node;

        }
        //cout<<table[i]->value<<" ";
    }
    cin>>m;
    for(int i=0;i<m;++i)
    {
        int k;
        cin>>k;
        Node* cur = table[k];
        if(cur!=nullptr)
        {
            if(cur->prev!=nullptr)
                cur->prev->next = cur->next;
            if(cur->next!=nullptr)
                cur->next->prev=cur->prev;
            table[k]=nullptr;
        }
    }
    
    //cout<<head->value<<" ";
    head=nullptr;
    for(int i=1;i<=n;++i)
    {
        if (table[i]!=nullptr&&table[i]->prev==nullptr&&table[i]->next!=nullptr)
        {
            head = table[i];
            break;
        }
    }
    if(head)
    {
        
        while(head!=nullptr)
        {
            cout<<head->value<<" ";
            head=head->next;
        }
    }
    cout<<endl;
    return 0;
}