
#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
class CArray
{
     private:
        int *start; //Starting Positon of array.
        int *top; //Positon of cursor.
        int *end; //End Position of array.

        //Shits All Elemets to right.
        void shiftRight(int * indexAddress){
            
            for(int* i=top;i>=indexAddress;i--){
                *i=*(i-1);
            }
            top++;
            filled++;
            
        }
        //Shits All Elemets to left.
        void shiftLeft(int * indexAddress){
            
            for(int* i=indexAddress;i<top;i++){
                *i=*(i+1);
            }
            top--;
            filled--;
            
        }

    public:
        CArray(int size){
           // start =  (int*)malloc(size*sizeof(int));
           start = new int[size];
            top=start;
            end=start+size;
            length=size;
        }
        ~CArray(){
           
            delete [] start;
            
        }

        int const& operator[](int i) const {
            if( i > length) {
                cout << "Index out of bounds" <<endl; 
                return *start;
            }
            if(i>=0){
                return *(start+i);
            }else{
                return *(end+i-1);
            }
        }

        int length; //Size of array.
        int filled=0; //Space used of alloted space.

        //Return item based on index.
        int get(int index){
            if( index > length) {
                cout << "Index out of bounds" <<endl; 
                return *start;
            }
            if(index>filled){
                cout << "Array space not used" <<endl; 
                return 0;
            }
            if(index>=0){
            return(*(start+index));
            }
            else{
               return(*(start+index+1));
            }
        }
        //Set and sort array item based on index.
        void set(int index,int item){
            if( index > length) {
                cout << "Index out of bounds" <<endl; 
                return;
            }
            
            if(index>=0){
               shiftLeft((start+index));
               this->insert(item);
            }
            else{
                shiftLeft((top+index+1));
                this->insert(item);
            }
        }
        //Returns the sum of all elements in the array.
        int sum(){
            int res=0;
            for(int* i = start ;i<top;i++){
                res+=*i;
            }
            return res;
        }

        //Returns the largest element in the array.
        int max(){

            //return the topmost element in the array(Since its sorted array topmost=largest).
            return *(top-1);
        }

        // Insert item in sorted way(binary inseertion).
        void insert(int item){    
            //If array already filled the renturn
            if(filled==length){
                cout<<"[-] Error: Array already filled"<<endl;
                return;
            }
            //If array is empty insert at start.
            if(filled==0){
                *top=item;
                top++;
                filled++;
                return;
                    
            }
            int *mid, *leftEnd = start,*rightEnd =top;
            while (leftEnd-rightEnd<0)
            {
                //Get the middle position of the array.
                mid=leftEnd+(rightEnd-leftEnd)/2;

                //Search for position to insert item.
                if(item>*mid){
                    leftEnd=mid;
                }
                else{
                    rightEnd=mid;
                }

                //Insert item on the suitable position.
                if(mid==leftEnd && rightEnd-leftEnd==1){
                    
                    if(item>*mid){
                        shiftRight(leftEnd+1);
                        *(leftEnd+1)=item;
                    }
                    else{
                        shiftRight(leftEnd);
                        *(leftEnd)=item;
                    }
                    
                    return;  
                }
            } 
        }
        //Remove element at given from array.
        void remove(int index){
            if(index>=0){
               shiftLeft((start+index));
               
            }
            else{
                shiftLeft((top+index+1));
                
            }
           
        }
        int pop(){
            int lastElement=*(top-1);
            shiftLeft(top-1);
            return lastElement;
        }
        int search(int element){
            int *mid, *leftEnd = start,*rightEnd =top;
            while (leftEnd!=rightEnd)
            {
                //Get the middle position of the array.
                mid=leftEnd+(rightEnd-leftEnd)/2;

                //Search for position to insert item.
                if(element>*mid){
                    leftEnd=mid;
                }
                else if(element<*mid){
                    rightEnd=mid;
                }
                if(*mid==element){
                    return mid-start;
                }
            }
            return -1;
        }
        void print(){
            for(int* i = start ;i<top;i++){
                cout<<*i<<endl;
            }
        }
       
};



int main(int argc, char const *argv[])
{
    srand(time(nullptr)); 
    int size = 10;
    CArray a =  CArray(size);
    for (int i = 0; i < 8; i++)
    {
        a.insert(rand()%10000);
    }
   
    a.insert(6789);
    a.print();
    cout<<"Element 6789 is at index: "<<a.search(6789)<<endl;
    

}
