#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
     int data;
     Node* next;

     Node(int data1){
        data = data1;
        next = nullptr;
     }
};

//creating an ll from array
Node* createLL(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i =1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

//deletion of head in ll
Node* Deletehead(Node* head){
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

//delete of tail in ll
Node* Deletetail(Node* head){
    if(head == nullptr || head->next==nullptr){
        return nullptr;
    }
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    free(temp->next);//free tail (i.e temp->next is tail)as we stoppend on ll before
    temp->next = nullptr;
    return head;
}

//deletion of kth element 
Node* Deletekthelem(Node* head , int k){

    //if head is null
    if(head == nullptr) return head;

    //if head itself kth elem 
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    //if not the head and tail
    int cnt;
    Node* temp = head;
    Node* prev = nullptr;

    while(temp){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next; // moving temp forward
    }

    return head;
}


//deletion of the element with value k
Node* Deletvalueinll(Node* head , int k){

    //if head is null
    if(head == nullptr) return head;

    //if head itself kth elem 
    if(head->data == k){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    //if not the head and tail
    Node* temp = head;
    Node* prev = nullptr;

    while(temp){

        if(temp->data == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next; // moving temp forward
    }

    return head;
}

//INSERTION at head
Node* insertathead(Node*head , int el){
    Node* temp = new Node(el);
    temp->next = head;
    return temp;
}

//insertion at the end
Node* insertattail(Node*head , int el){
    if(head ==NULL) return new Node(el);
    Node*temp = head;
    Node*prev = nullptr;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* temp2 = new Node(el);
    temp2->next = nullptr;
    temp->next = temp2;
    return head;
}

//insertion at the kth position 
Node* insertatkth(Node* head , int el , int k){

    //if linked list is empty (i.e head is null)
    if(head == nullptr){
        if(k==1) return new Node(el);
        else return nullptr;
    }

    //insert at head
    if(k==1){
        Node* temp = new Node(el);
        temp->next = head;
        return temp;
    }

    //insert in somewhere middle
    int cnt = 0;
    Node* temp = head;
    while(temp!=nullptr){
        cnt++;
        if(cnt == k-1){
            Node* temp2 = new Node(el);
            temp2->next = temp->next;
            temp->next = temp2;
            break;
        }
        temp = temp->next;
    }
    return head;
}

//insertion before the value x
Node* insertbeforeval(Node* head , int el , int val){
    if(head==nullptr){
        return new Node(el);
    }
    if(val == head->data){
        Node* temp = new Node(el);
        temp->next = head;
        return temp;
    }

    Node*temp = head;
    while(temp->next!=nullptr){
        if(temp->next->data == val){
            Node* temp2 = new Node(el);
            temp2->next = temp->next;
            temp->next = temp2;
            break;
        }
        temp = temp->next;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    vector<int>arr= {2,4,6,8,10,12};
    Node* head = createLL(arr);
    // head = Deletehead(head);
    print(head);
    // head = Deletetail(head);
    print(head);
    int k = 12;
    // head = Deletvalueinll(head,k);
    // head = Deletekthelem(head , k);
    print(head);

    int el = 11;
    head = insertathead(head , el);
    print(head);

    el = 13;
    head = insertattail(head , el);
    print(head);

    el = 14;
    k = 10; // if position is greter than elements in ll then will not do anything
    head = insertatkth(head , el ,k);
    print(head);

    el = 15;
    int val = 12;
    head = insertbeforeval(head , el , val);
    print(head);
    return 0;
}