#include<iostream>
using namespace std;

class Node{
    public:
        int key;
        int value;
        Node * next;

        Node(){
            key=0;
            value=0;
            next=NULL;
        }

        Node(int k ,int v){
            key = k;
            value = v;
        }
};

class SinglyLinkedList{
    public:
        Node* head;

        SinglyLinkedList(){
            head = NULL;
        }
        SinglyLinkedList(Node* n){
            head = n;
        }
        
    // node existing
        Node* nodeExist(int k){
            Node* temp = NULL;
            Node* ptr = head;

            while(ptr!=NULL){
                if(ptr->key == k){
                    temp = ptr;
                }
                ptr=ptr->next;
            }
            return temp;
        }

    // node appending
        Node* appendNode(Node* n){
            if(nodeExist(n->key)!=NULL){
                cout<<"Node Already Exist"<<n->key<<"Create with Another key."<<endl;
            }
            else{
                if(head==NULL){
                    head=n;
                    cout<<"Node Appended"<<endl;
                }
                else{
                    Node* ptr=head;
                    while(ptr->next!=NULL){
                        ptr=ptr->next;
                    }
                    ptr->next=n;
                    cout<<"Node Appended"<<endl;
                }
            }
        }

    // node prepending 
    Node* prependNode(Node* n){
        if(nodeExist(n->key)!=NULL){
                cout<<"Node Already Exist"<<n->key<<"Create with Another Key."<<endl;
            }
        else{
            n->next=head;
            head=n;
                    cout<<"Node Prepended"<<endl;
            }
    }
        
    // Insert at Kth Position
    Node* InsertNodeAfter(int k,Node* n){
        Node* ptr = nodeExist(k);

        if(ptr == NULL){
            cout<<"No node Exist with the key value : "<<k<<endl;
        }
        else{
            if(nodeExist(n->key)!=NULL){
                    cout<<"Node Already Exist"<<n->key<<"Create with Another Key."<<endl;
                }
            else{
                n->next = ptr->next;
                ptr->next=n;
                cout<<"Node Inserted "<<endl;
            }
        }
    }

    // Deletion At the End 
    void DeleteNodeByKey(int k){
        if(head == NULL){
            cout<<"Linked List is already Empty , Can't Delete "<<endl;
        }
        else if(head != NULL){
            if(head->key == k){
                head = head->next;
                cout<<"Deletion of Node has been done of key :"<<k<<endl;
            }
            else{
                Node* temp=NULL;
                Node* CurrentNode=head->next;
                Node* PrevNode=head;

                while(CurrentNode!=NULL){

                    if(CurrentNode->key == k){
                        temp = CurrentNode;
                        CurrentNode=NULL;
                    }
                    else{
                        PrevNode = PrevNode->next;
                        CurrentNode = CurrentNode->next;
                    }
                }
                if(temp!=NULL){
                    PrevNode->next=temp->next;
                    cout<<"Node Unlinked with key :"<<k<<endl;
                }
                else{
                    cout<<"Node Doesn't exist with key :"<<k<<endl;
                }
            }
        }
    }

    // Update Node 
    void UpdateNode(int k , int d){
        Node* ptr = nodeExist(k);
        if(ptr!=NULL){
            ptr->value=d;
            cout<<"Node has Been Update of Key :"<<k<<endl;
        }
        else {
            cout<<"We Didn't find the Node with Key :"<<k<<endl;
        }
    }

    // Print Linked List
    void PrintList(){
        if(head == NULL){
            cout<<"No Node in Singly Linked List ."<<endl;
        }
        else{
            Node* temp = head;
            cout<<"Singly Linked List Value : ";

            while(temp!=NULL){
                cout<<"("<<temp->key<<","<<temp->value<<") -->";
                temp=temp->next;
            }
        }
    }
};

int main() {
    SinglyLinkedList s;
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
            s.appendNode(n1);
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
            s.InsertNodeAfter(key1,n1);
            break;
        }
        case 5:{
            cout<<"Enter the key of Node which you want to Delete ."<<endl;
            cin>>k1;
            s.DeleteNodeByKey(k1);
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