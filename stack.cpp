#include<iostream>
using namespace std;

class stack{
    private:
        int top;
        int arr[5];

    public:
        stack(){
            top = -1;
            for(int i=0;i<5;i++){
                arr[i] = 0;
            }
        }

        bool isEmpty(){
            if(top == -1){
                return true ;
            }
            else{
                return false;
            }
        }

        bool isFull(){
            if(top == 4){
                return true;
            }
            else{
                return false;
            }
        }

        void push(int value){
            if(isFull()){
                cout<<"Stack OverFlow "<<endl;
            }
            else{
                top++;
                arr[top] = value ;
                cout<<"Value Pushed "<<endl;
            }
        }

        int pop(){
            if(isEmpty()){
                cout<<"Stack UnderFlow "<<endl;
                return 0;
            }
            else{
                int popValue = arr[top];
                arr[top] = 0;
                top--;
                return popValue;
            }
        }

        int peek(){
            if(isEmpty()){
                cout<<"Stack Underflow "<<endl;
                return 0;
            }
            else{
                return arr[top];
            }
        }

        int count(){
            return (top+1);
        }

        void change(int pos ,int value){
            if(isEmpty()){
                cout<<"Stack is Empty ,We can't change the value "<<endl;
            }
            else if (pos > top){
                cout<<"We didn't have value at that position "<<endl;
            }
            else{
                arr[pos] = value;
            }
        }

        void display(){
            cout<<"All the Value of Stack :";
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
        }
};


int main() {

    stack S;
    int position , option , value;

    do{
        cout<<"Choose the option which you want to perform "<<endl;
        cout<<"0 . Exit "<<endl;
        cout<<"1 . Push "<<endl;
        cout<<"2 . Pop "<<endl;
        cout<<"3 . isEmpty "<<endl;
        cout<<"4 . isFull "<<endl;
        cout<<"5 . Peek "<<endl;
        cout<<"6 . Count "<<endl;
        cout<<"7 . Change "<<endl;
        cout<<"8 . Display "<<endl;
        cout<<"9 . Clear  "<<endl;

        cin>>option;


        switch (option)
        {
        case 0:
            break;

        case 1:
            cout<<"Enter the Value to Push "<<endl;
            cin>>value;
            S.push(value);
            cout<<endl;
            break;

        case 2:
            cout<<"Pop Opertion Called - "<<S.pop()<<endl;
            break;

        case 3:
            if(S.isEmpty()){
                cout<<"Stack is Empty "<<endl;
            }
            else{
                cout<<"Stack is Not Empty "<<endl;
            }
            break;
        
        case 4:
            if(S.isFull()){
                cout<<"Stack is Full "<<endl;
            }
            else{
                cout<<"Stack is Not Full "<<endl;
            }
            break;
        
        case 5:
            cout<<S.peek()<<endl;
            break;
        
        case 6:
            cout<<S.count()<<endl;
            break;
        
        case 7:
            cout<<"Enter the Postion or the Value which you want to update "<<endl;
            cin>>position;
            cin>>value;
            S.change(position , value);
            cout<<endl;
            break;
        
        case 8:
            S.display();
            cout<<endl;
            break;

        case 9:
            system("cls");
            break;
        
        default:
            cout<<"Please Enter Valid Operation "<<endl;
            break;
        }
    }
    while(option!=0);

return 0;
}