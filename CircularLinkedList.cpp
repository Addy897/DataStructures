#include <iostream>
using namespace std;
class CiruclarLinkedList{
    private:
        struct node{
            int data;
           struct node* next;
        };
        struct node* head;
        struct node* top = new node;
    public:
        CiruclarLinkedList(int data){
           head=(struct node *)malloc(sizeof(struct node));
           head->data=data;
           head->next=NULL;
           top=head;
        }
        ~CiruclarLinkedList(){
            while(top!=head){
                struct node* nodet = new node;
                nodet=head;
            
                while (true)
                {
                    if(nodet->next==head){
                        break;
                    }
                    top=nodet;
                    nodet=nodet->next;
                }
                top->next=head;
                delete nodet;
            }
            free(head);
            
        }
        void remove(int index){
            struct node* nodetemp = new node;
            struct node* nodeprev = new node;
            nodetemp=head;
            for (int i = 0; i !=index; i++)
            {
                nodeprev=nodetemp;
                nodetemp=nodetemp->next;
            }
            
                
            nodeprev->next=nodetemp->next;
             
            if(nodetemp==head){
                head=head->next;
                
                top->next=head;
                
            }
            if(nodetemp==top){
                top=nodeprev;
            }
           
            nodeprev=nullptr;
            delete nodeprev;
            delete nodetemp;
        }
        void append(int data){
            struct node* node2 = new node;
            node2->data=data;
            node2->next=head;
            top->next=node2;
            top=node2;
            node2=nullptr;
            delete node2;
           
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
                top->next=head;
                return;
            }
            nodeprev->next=node2;
            nodeprev=nullptr;
            nodetemp=nullptr;
            delete nodeprev;
            delete nodetemp;

        }
        void print(){
            struct node* nodet = new node;
            nodet=head;
            while (true)
            {
                if(nodet->next==&(*head)){
                    break;
                }
                cout<<nodet->data<<" --> ";
                nodet=nodet->next;
            }
            cout<<nodet->data<<endl;
            nodet=nullptr;
            delete nodet;
        }

        
};
int main(int argc, char const *argv[])
{
    srand(time(0)); 
    int p =8989;
    CiruclarLinkedList* a = new CiruclarLinkedList(9);
    
    for (int i = 0; i < 8; i++)
    {
        a->append(rand()%10000);
    }
    a->print();
    a->insert(7,889);
   a->print();
   a->remove(9);
   a->print();
   a->remove(0);
   a->print();
   delete a;
    return 0;
}
