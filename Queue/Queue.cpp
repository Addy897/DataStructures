#include <iostream>

using namespace std;
class Queue{
    private:
        struct node{
            int data;
            struct node* next;
        };
        struct node* front;
        struct node* rear = new node;
    public:
        int size;
        Queue(){
           front=(struct node *)malloc(sizeof(struct node));
           size=0;
           rear=front;
        }
        ~Queue(){
            if(size==0){
                return;
            }
            while(rear!=front){
                struct node* nodeTemp = new node;
                nodeTemp=front;
            
                while (true)
                {
                    if(nodeTemp->next==front){
                        break;
                    }
                    rear=nodeTemp;
                    nodeTemp=nodeTemp->next;
                }
                rear->next=front;
                delete nodeTemp;
            }
            free(front);
            
        }
      
        int dequeue(){
            struct node* node2 = new node;
            int data = front->data;
            
            node2=front;
            front=front->next;
            rear->next=front;
            size--;
            
            delete node2;
            
            return data;


        }
        void append(int data){
            struct node* node2 = new node;
            node2->data=data;
            node2->next=front;
            if(size==0){
                front=node2;
                rear=front;

            }
            rear->next=node2;
            rear=node2;
            node2=nullptr;
            size++;
           delete node2;
           
        }
        
        void print(){
            if(size==0){
                cout<<"Empty!!!"<<endl;
                return;
            }
            struct node* nodeTemp = new node;
            nodeTemp=front;
            
            while (true)
            {
                if(nodeTemp->next==front){
                    break;
                }
                cout<<nodeTemp->data<<" --> ";
                nodeTemp=nodeTemp->next;
            }
            cout<<nodeTemp->data<<endl;
            nodeTemp=nullptr;
            delete nodeTemp;
        }

        
};
int main(int argc, char const *argv[])
{
    srand(time(0)); 
    Queue* a = new Queue();
   
    int d1=1;
    a->append(d1);
    int d2 =2;
    a->append(d2);
    a->print();
    cout<<a->dequeue()<<endl;
    a->print();
    delete a;
    return 0;
}
