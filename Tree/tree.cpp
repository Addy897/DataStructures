#include <iostream>
using namespace std;
class Tree
{
private:
    struct node
    {
        int data;
        struct node *next[2];
    };
    struct node *root;
    
public:
    int height;
    int index=0;
    struct node **leaf;
    
    Tree(int h)
    {
        root = (struct node *)malloc(sizeof(struct node));
        leaf=new node *[2^h];

        height = h;
    }
    ~Tree(){
        free(root);
    }

    void Create(int root_data)
    {
        root->data = root_data;
        recurCreate(root, height-1);
        display(root);
        
    }
    void recurCreate(struct node *parent, int h)
    {
        for (int i = 0; i < 2; i++)
        {
            struct node *tempNode = new node;
            cout << "Enter Level " << height - h << " Node " << i << " : ";
            cin >> tempNode->data;
            parent->next[i] = tempNode;
            tempNode->next[0]=nullptr;
            tempNode->next[1]=nullptr;
            if (h > 0)
            {
                recurCreate(tempNode, h-1);
                
            }
            else if (h==0){
                leaf[index]=tempNode;
                index++;
                
            }
            tempNode = nullptr;
            delete tempNode;
        }
    }
    void display(struct node *parent){
        for (int i = 0; i < 2; i++)
        {
           
            cout <<parent->data<<"-->";
            if (parent->next[i]==nullptr)
            {
               return;
            }
            
            if (parent->next[i]!=nullptr)
            {
                display(parent->next[i]);
                cout<<endl;
                
            }
        }
        
        
    }
    
};
int main()
{
    Tree tree = Tree(2);
    tree.Create(1);
}
