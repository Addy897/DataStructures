#include <iostream>
using namespace std;
class LinkedList{
    private:
        struct node{
            int data;
           struct node* next;
        };
        struct node* head;
        struct node* top = new node;
    public:
        LinkedList(int data){
           head=(struct node *)malloc(sizeof(struct node));
           head->data=data;
           head->next=NULL;
           top=head;
        }
        ~LinkedList(){
            while(top!=head){
                struct node* nodet = new node;
                nodet=head;
            
                while (true)
                {
                    if(nodet->next==nullptr){
                        break;
                    }
                    top=nodet;
                    nodet=nodet->next;
                }
                top->next=nullptr;
                delete nodet;
            }
            free(head);
            
        }
        void remove(int index){
            struct node* nodetemp = new node;
            struct node* nodeprev = new node;
            nodetemp=head;
            nodeprev=head;
            int i =0;
            while (i!=index)
            {
                nodeprev=nodetemp;
                nodetemp=nodetemp->next;
                
                i++;
            }
            nodeprev->next=nodetemp->next;
             if(nodetemp==head){
                head=nodeprev->next;
                return;
            }
            delete nodetemp;
        }
        void append(int data){
            struct node* node2 = new node;
            node2->data=data;
            node2->next=nullptr;
            top->next=node2;
            top=node2;
           
        }
        void insert(int index,int data){
            struct node* nodetemp = new node;
            struct node* nodeprev = new node;
            nodetemp=head;
            nodeprev=head;
            int i =0;
            while (i!=index)
            {
                nodeprev=nodetemp;
                nodetemp=nodetemp->next;
                
                i++;
            }
            struct node* node2 = new node;
            node2->data=data;
            node2->next=nodetemp;
            if(nodeprev==head){
                head=node2;
                return;
            }
            nodeprev->next=node2;

        }
        void print(){
            struct node* nodet = new node;
            nodet=head;
            
            while (true)
            {
                if(nodet->next==nullptr){
                    break;
                }
                cout<<nodet->data<<" --> ";
                nodet=nodet->next;
            }
            cout<<nodet->data<<endl;
        }

        
};
int main(int argc, char const *argv[])
{
    srand(time(0)); 
    int p =8989;
    LinkedList a =  LinkedList(9);
    
    for (int i = 0; i < 8; i++)
    {
        a.append(rand()%10000);
    }
    a.print();
    a.insert(0,889);
    a.print();
    a.remove(9);
    a.print();
    return 0;
}
