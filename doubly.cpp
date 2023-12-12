#include<iostream>
using namespace std;

class Node{
    public:
        int key ;
        int value;
        Node* prev;
        Node* next;

        Node(){
            key =0 ;
            value =0;
            next = NULL;
            prev = NULL;
        }

        Node(int k ,int v){
            key = k;
            value = v;
        }
};

class DoublyLinkedList{
    public:
        Node* head;

        DoublyLinkedList(){
            head = NULL;
        }
        DoublyLinkedList(Node* n){
            head = n;
        }

    // Node Exist
        Node* NodeExist(int k){
            Node* ptr = head;
            Node* temp = NULL;

            while(ptr!=NULL){
                if(ptr->key == k){
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp;
        }
        // append Node

        Node* AppendNode(Node* n){
            if(NodeExist(n->key)!=NULL){
                cout<<"Node Already Exist With this key ."<<endl;
            }
            else{
                if(head == NULL){
                    head = n;
                    cout<<"Node Appended as a head ."<<endl;
                }
                else{
                    Node* ptr = head ;
                    while (ptr->next!=NULL){
                        ptr=ptr->next;
                    }
                    ptr->next=n;
                    n->prev=ptr;
                    cout<<"Node Appended ."<<endl;
                }
            }
        }

        // Prepend Node 
        void prependNode(Node* n){
            if(NodeExist(n->key)!=NULL){
                cout<<"Node already exist with this key ."<<endl;
            }
            else{
                if(head == NULL){
                    head = n;
                    cout<<"Node Appended as a head ."<<endl;
                }
                else{
                head->prev = n;
                n->next = head;
                head = n;

                cout<<"Node Prepended ."<<endl;
                }
            }
        }

        //Insert At Kth Postion 
        void InsertAfterKey(int k ,Node* n){
            Node* ptr = NodeExist(k);

            if(ptr==NULL){
                cout<<"NO Node Exist With This Key "<<endl;
            }
            else{
                if(NodeExist(n->key)!=NULL){
                    cout<<"Node Already Exist"<<n->key<<"Create with Another Key."<<endl;
                }
                else{
                    cout<<"Inserting "<<endl;
                    Node* nextNode = ptr->next;

                    if(nextNode == NULL){
                        ptr->next = n;
                        n->prev = ptr;
                        cout<<"Node Inserted "<<endl;
                    }
                    else{
                        n->next = nextNode;
                        nextNode->prev = n;
                        n->prev = ptr;
                        ptr->next = n;

                        cout<<"Node Inserted "<<endl;
                    }
                }
            }
        }

        //Node Deletion
        void DeletionOfNode(int k){
            Node* ptr = NodeExist(k);

            if(ptr == NULL){
                cout<<"Node Doesn't exist with key "<<endl;
            }
            else{
                if(head->key == NULL){
                    head = head->next;
                    cout<<"Node Unlinked "<<endl;
                }
                else{
                    Node* nextNode = ptr->next;
                    Node* prevNode = ptr->prev;

                    if(nextNode == NULL){
                        prevNode->next = NULL;
                        cout<<"Node Delete from End ."<<endl;
                    }
                    else{
                        prevNode->next = nextNode;
                        nextNode->prev = prevNode;
                        cout<<"Delete in Between "<<endl;
                    }
                }
            }
        }
        //Update to Node

        void UpdateNode(int k , int d){
            Node* ptr = NodeExist(k);

            if(ptr == NULL){
                cout<<"Node Doesn't Exist ."<<endl;
            }
            else{
                ptr->value = d;
                cout<<"Node Update ."<<endl;
            }
        }
        //Printing of List

        void PrintList(){
            Node* temp = head;
            if(temp == NULL){
                cout<<"Linked List is empty ."<<endl;
            }
            else{
                cout<<"Linked List Values :"<<endl;

                while(temp!=NULL){
                    cout<<"( "<<temp->key<<" , "<<temp->value<<")";
                    temp=temp->next;
                }
                cout<<endl;
            }
        }
};

int main() {

    DoublyLinkedList s;
    int key1 ,d1 , k1;
    int option;

    do{
        cout<<"Enter operation to perform the function , Enter 0 to exit ."<<endl;
        cout<<"1. Print  ."<<endl;
        cout<<"2. Node Append ."<<endl;
        cout<<"3. Node Prepend ."<<endl;
        cout<<"4. Insert Node After Key ."<<endl;
        cout<<"5. Delete Node by Key ."<<endl;
        cout<<"6. Update Node ."<<endl;
        cout<<"7. Clear ."<<endl;

        cin>>option;
        Node* n1 = new Node;
        switch (option)
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
            s.prependNode(n1);
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
            s.InsertAfterKey(key1,n1);
            break;
        }
        case 5:{
            cout<<"Enter the key of Node which you want to Delete ."<<endl;
            cin>>k1;
            s.DeletionOfNode(k1);
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
        


    }
    while(option!=0);




return 0;
}