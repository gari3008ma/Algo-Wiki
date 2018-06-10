#include<bits/stdc++.h>
#include<stdlib.h>
#include <time.h>
#include<string>
 using namespace std;
/* Link list node */
struct node
{
    char key;
    struct node* next;
};
node* newNode(char c)
{
    node *temp = new node;
    temp->key = c;
    temp->next = NULL;
    return temp;
};
 int compare(struct node *head1,struct node *head2)
 {
          if(head1==NULL && head2==NULL)
             return 0;
          if(head1==NULL && head2!=NULL)
             return -1;
           if(head1!=NULL && head2==NULL)
             return 1; 
        string  a,b;
        struct node *tmp=head1;
        while(tmp!=NULL)
        {
                   a=a+(tmp->key);
                   tmp=tmp->next;
        }   
       // cout<<"\n"<<a<<"\n";
                tmp=head2;  
         while(tmp!=NULL)
        {
                   b=b+(tmp->key);
                   tmp=tmp->next;
        }   
        //cout<<"\n"<<b<<"\n"; 
        if(a==b)
        return 0;
        else
        {
             if(a.length()>b.length())
                  return 1;
              else if(a.length() < b.length())
                return -1;
            string :: iterator it=a.begin();
            string :: iterator et=b.begin();
            while(it!=a.end() && (et!=b.end()))
            {
                if((*it)>(*et))
                    return 1;
                else if((*it) < (*et))
                    return -1;
                it++;
                et++;
            }
        }  
        return 0;    
 }
int main()
{
    node *list1 = newNode('g');
    list1->next = newNode('e');
    list1->next->next = newNode('e');
    list1->next->next->next = newNode('k');
    list1->next->next->next->next = newNode('s');
    list1->next->next->next->next->next = newNode('b');
    node *u=list1;
   /* while(u!=NULL)
    {
        cout<<u->key<<" ";
        u=u->next;
    }
    */
    node *list2 = newNode('g');
    list2->next = newNode('e');
    list2->next->next = newNode('e');
    list2->next->next->next = newNode('k');
    list2->next->next->next->next = newNode('s');
    list2->next->next->next->next->next = newNode('a');
    u=list2;
    /*cout<<"\n";
    while(u!=NULL)
    {
        cout<<u->key<<" ";
        u=u->next;
    }
   */
    cout << compare(list1, list2)<<"\n";
  
    return 0;
}