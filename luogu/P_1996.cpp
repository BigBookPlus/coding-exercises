#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    Node* next;
    int value;
}Node;

int main()
{
    int m, n;
    std::cin >> n >> m;
    Node* head = new Node;
    head->value=1;
    Node* prev= head;
    for(int i=1;i<n;++i){
        Node* node= new Node;
        node->value=i+1;
        prev->next=node;
        prev=node;
    }
    prev->next=head;
    Node* cur=head;
    int i=1;
    while(cur->next!=cur)
    {
        if(i<m)
        {
            prev=cur;
            cur=cur->next;
            ++i;
        }
        else if(i==m)
        {
            i=1;
            std::cout<<cur->value<<" ";
            prev->next=cur->next;
            cur = prev->next;
        } 
    }
    std::cout<<cur->value<<endl;


    return 0;

}