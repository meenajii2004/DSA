#include<iostream>
using namespace std;

class Node{

    public:
        int key ;
        int value;
        Node* next ;

        Node(){
            key = 0;
            value =0;
            next = NULL;
        }

        Node(int k , int data){
            key = k;
            value = data;
        }
};

class CircularLinkedList{
    public:
        Node* head;

        CircularLinkedList(){
            head =NULL;
        }

    //Node Exist 
        Node* NodeExist(int k ){
            Node* temp = NULL;
            Node* ptr = head;

            if(ptr == NULL){
                return temp;
            }
            else{
                do{
                    if(ptr->key == k)
                    {
                        temp = ptr;
                    }
                    ptr= ptr->next;
                }while(ptr->next != head);
            }
            return temp;
        }

    // Node Appending
        void AppendNode(Node* n){

            if(NodeExist(n->key) != NULL){
                cout<<"Please Enter Other key value "<<endl;
            }
            else{
                if(head == NULL){
                    head = n;
                    n->next = head;
                    cout<<"Node Appended as Head ."<<endl;
                }

                else{
                Node* ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
                cout<<"Node Appended ."<<endl;
                }
            }
        }

        //Node Prepended 
        void NodePrepended(Node* n){
            if(NodeExist(n->key) != NULL){
                cout<<"Please Enter Other key value "<<endl;
            }
            else{
                if(head == NULL){
                    head = n;
                    n->next = head;
                    cout<<"Node Prepended As Head ."<<endl;
                }
                else{
                    Node* ptr = head;
                    while(ptr->next != head)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;

                    n->next = head;
                    head = n;

                    cout<<"Node Prepended"<<endl;
                }
            }
        }

        //Insert After Key K
        void InsertAfterKthNode(int k,Node* n){
            Node* ptr = NodeExist(k);

            if(ptr == NULL){
                cout<<"No Node Exist With This Key ."<<endl;
            }
            else{
                if(NodeExist(n->key) != NULL){
                    cout<<"Node Already Exist With key "<<n->key<<" Append Another Node With different Kry value ."<<endl;
                }
                else{
                    if(ptr->next == head){
                        n->next =head ;
                        ptr->next = n;
                        cout<<"Node Inserted at The End ."<<endl;
                    }
                    else{
                        n->next = ptr->next;
                        ptr->next = n;
                        cout<<"Node Inserted after the Key "<<k<<endl;
                    }
                }
            }
        }

        //Deletion Of Node By Key 
        void DeletionByKey(int k){
            Node* ptr = NodeExist(k);
            if(ptr == NULL){
                cout<<"No Node Exists With Key Value of :"<<k<<endl;
            }
            else{
                if(ptr == head){
                    if(head->next == NULL){
                        head = NULL;
                        cout<<"Head node Unlinked  ... List Empty "<<endl;
                    }
                    else{
                        Node* ptr1 = head;
                        while ((ptr1->next != head))
                        {
                            ptr1 = ptr1->next;
                        }
                        ptr->next = head->next;
                        head = head->next;
                        cout<<"Node Unlinked With Key Value "<<k<<endl;
                    }
                }
                else{
                    Node* temp = NULL;
                    Node* prevptr = head;
                    Node* currentptr = head->next;

                    while(currentptr!= NULL){
                        if(currentptr->key == k){
                            temp = currentptr;
                            currentptr = NULL;
                        }
                        else{
                            prevptr = prevptr->next;
                            currentptr = currentptr->next;
                        }
                    }
                    prevptr->next = temp->next;
                    cout<<"Node Unlinked With Keys Value :"<<k<<endl;
                }
            }
        }

        // Updation of Node
        void UpdateNode(int k , int d){
        Node* ptr = NodeExist(k);
        if(ptr!=NULL){
            ptr->value=d;
            cout<<"Node has Been Update of Key :"<<k<<endl;
        }
        else {
            cout<<"We Didn't find the Node with Key :"<<k<<endl;
        }
    }

    //Print 
    void PrintList(){

        if(head == NULL){
            cout<<"No Nodes in Singly Linked List "<<endl;
        }
        else{
            cout<<"Head Address : "<<head<<endl;
            cout<<"Singly Linked List Values : "<<endl;

            Node* temp = head;

            do{
                cout<<"("<<temp->key<<" , "<<temp->value<<") --> ";
                temp = temp->next;
            }while(temp != head);
        }
    }
};


int main() {

CircularLinkedList  s;
    int Option;
    int k1 ,d1 , key1;

    do{
        cout<<"Enter any option which you want to perform or Exit with 0."<<endl;
        cout<<"1. Print  ."<<endl;
        cout<<"2. Node Append ."<<endl;
        cout<<"3. Node Prepend ."<<endl;
        cout<<"4. Insert Node After Key ."<<endl;
        cout<<"5. Delete Node by Key ."<<endl;
        cout<<"6. Update Node ."<<endl;
        cout<<"7. Clear ."<<endl;

        cin>>Option;
        Node* n1 = new Node();

        switch (Option)
        {
        case 0:{
            break;
        }
        case 1:{
            s.PrintList();
            break;
        }
        case 2:{
            cout<<"Enter the key of Node to append and the data of Node ."<<endl;
            cin>>k1;
            cin>>d1;
            n1->key=k1;
            n1->value=d1;
            s.AppendNode(n1);
            break;
        }
        case 3:{
            cout<<"Enter the key of Node to prepend and the data of Node ."<<endl;
            cin>>k1;
            cin>>d1;
            n1->key=k1;
            n1->value=d1;
            s.NodePrepended(n1);
            break;
        }
        case 4:{
            cout<<"Enter the key of Node After which you want to insert New Node ."<<endl;
            cin>>key1;
            cout<<"Enter the key of Node to Insert and the data of Node ."<<endl;
            cin>>k1;
            cin>>d1;
            n1->key=k1;
            n1->value=d1;
            s.InsertAfterKthNode(key1,n1);
            break;
        }
        case 5:{
            cout<<"Enter the key of Node which you want to Delete ."<<endl;
            cin>>k1;
            s.DeletionByKey(k1);
            break;
        }
        case 6:{
            cout<<"Enter the key of Node which you want to update ."<<endl;
            cin>>k1;
            cout<<"Enter the data of Node ."<<endl;
            cin>>d1;
            s.UpdateNode(k1,d1);
            break;
        }
        case 7:{
            system("cls");
            break;
        }
        
        default:
            cout<<"Please Select Valid Option ."<<endl;
            break;
        }

    }while(Option!=0);

return 0;
}