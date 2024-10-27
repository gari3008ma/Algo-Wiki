 #include <iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
node* newNode(int key)
{
    node *temp = new node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
struct node *rear1(struct node *head)
{
                struct node *tmp=head,*pre=NULL,*head1=NULL,*c;
                    vector<struct node *> a;
                    while(tmp!=NULL)
                    {
                        c=tmp;
                        if(tmp->data%2!=0)
                        {
                            pre=tmp->next;
                            if(head1==NULL)
                            {
                                tmp->next=head1;
                                head1=tmp;
                                pre=tmp;
                            }
                            else
                            {
                                    pre->next=tmp;
                                    tmp->next=NULL;
                                    pre=tmp;
                            }
                            tmp=pre;
                        }
                        else
                        {
                            a.push_back(tmp);
                            tmp=tmp->next;
                        }
                    }
                    tmp=c;
                   vector<struct node*> :: iterator it=a.begin();
                   while(it!=a.end())
                   {
                        tmp->next=(*it);
                        tmp=(*it);
                        (*it)->next=NULL;
                            it++;
                   }
                   return head;
}
void printlist(node * node)
{
    while (node != NULL)
    {
        cout << node->data << "->";
        node = node->next;
    }
    cout << "NULL" << endl;
}
int main(void)
{
    node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
 
    cout << "Given Linked List\n";
    printlist(head);
 
    head = rear1(head);
 
    cout << "\nModified Linked List\n";
    printlist(head);
 
    return 0;
}