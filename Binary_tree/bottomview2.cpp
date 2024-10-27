 #include <iostream>
using namespace std;
struct Node
{
    char data;
    struct Node *left, *right;
    int hd;
};
struct Node *newNode(char item)
{
    struct Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    temp->hd=INT_MAX;
    return temp;
}
void printbtwlevel(struct Node *root)
{
          if(root==NULL)
               return ;
           queue<struct Node *> revl;
           struct Node *tmp;
           int hd=0,lvl;
           map<int,char> arr;
           root->hd=hd;
           revl.push(root);
           while(!revl.empty())
           {          
                       lvl=revl.size();                      
                       while(lvl--)
                       {
                            tmp=revl.front();
                            hd=tmp->hd;
                            revl.pop();
                            arr[hd]=(tmp->data);
                            if(tmp->left!=NULL)
                            {
                              revl.push(tmp->left);
                              tmp->left->hd=hd-1;
                            }
                            if(tmp->right!=NULL)
                            {
                              revl.push(tmp->right);
                              tmp->right->hd=hd+1;
                            }
                       }
                       
           }
           map<int,char> ::iterator it = arr.begin();
           for(it = arr.begin();it!=arr.end();it++)
           {
                cout<<(it)->second<<" ";
           }
}
void bottomView(Node *root)
{
    if (root == NULL)
        return;
 
    // Initialize a variable 'hd' with 0
    // for the root element.
    int hd = 0;
 
    // TreeMap which stores key value pair
    // sorted on key value
    map<int, int> m;
 
    // Queue to store tree nodes in level
    // order traversal
    queue<Node *> q;
    root->hd = hd;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        hd = temp->hd;
        m[hd] = temp->data;
        if (temp->left != NULL)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
 
    // Traverse the map elements using the iterator.
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
}
void printInorder(struct Node *root)
{
    if (root == NULL) 
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
    struct Node *root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->left = newNode('f');
    root->right->right = newNode('g');
    root->left->left->left = newNode('h');
    root->left->left->right = newNode('i');
    root->left->right->left = newNode('j');
    root->left->right->right = newNode('k');
    root->right->left->left = newNode('l');
    root->right->left->right = newNode('m');
    root->right->right->left = newNode('n');
    root->right->right->right = newNode('o'); 
    cout << "Inorder Traversal of given tree\n";
    printInorder(root);
    cout<<"\n";
    printbtwlevel(root);
 
 
    return 0;
}