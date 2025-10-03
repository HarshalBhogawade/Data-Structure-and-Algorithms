#include<iostream>
#include<vector>
using namespace std;


//Node structure of Doubly
class Node{
    public:
        int data;
        Node* next;
        Node* back;

        //when no need to specifying next and prev pointers
        Node(int data1){
            data = data1;
            next  = nullptr;
            back = nullptr;
        }
        
        //while creating dll from array this required
        Node(int data1 , Node* next1 , Node* back1){
            data = data1;
            next  = next1;
            back = back1;
        }
};


//converting array to Doubly LL
Node* ConvertarrtoDll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    
    for(int i = 1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr , prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

//Printing nodes of doubly
void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//Deleting head in Dll 
Node* DeleteheadinDll(Node*head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }

    //unlinking head from first node
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;

    free(prev);
    return head;
}


//Deletion of Tail in Dll
Node* DeletetailofDll(Node*head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    free(tail);
    return head;
}


//De;eting Kth Node in Dll
Node* DeleteKthNode(Node* head , int k){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    if(k == 1){
        Node* prev = head;
        head = head->next;
        prev->next = nullptr;
        head->back = nullptr;
        return head;
    }
    Node* temp = head;
    int cnt = 0;
    while(temp!= nullptr){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* Next = temp->next;
    if(prev == nullptr && Next == nullptr) return nullptr;
    else if ( prev == nullptr) return DeleteheadinDll(head);
    else if (Next == nullptr) return DeletetailofDll(head);
    prev->next = temp->next;
    Next->back = temp->back;
    delete temp;
    return head;
}

//Deleting Node (means by address , not by value or kth node just by pointer adress)
void DeleteNodeinDll(Node* temp){
    Node* prev = temp->back;
    Node* Next = temp->next;
    if(Next == nullptr){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
    }

    prev->next = temp->next;
    Next->back = temp->back;
    temp->next = temp->back = nullptr;
    free(temp);

}

//Insertion at the head
Node* Insertionbeforethehead(Node*head , int val){
    Node* temp = new Node(val);
    temp->next = head;
    head->back = temp;
    return temp;
}

//Insertion after head
Node* Insertionafterhead(Node* head , int val){
    Node* frontofhead = head->next;
    Node* temp = new Node(val);
    temp->back = head;
    temp->next = frontofhead;
    frontofhead->back = temp;
    head->next = temp;
    return head;
    
}

// insertion after the tail
Node* Insertionaftertail(Node* head , int val){
    Node* New = new Node(val);
    if(head == nullptr){
        return New;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    New->next = nullptr;
    New->back = temp;
    temp->next = New;
    return head;
}

// insertion before tail
Node* insertionbeforetail(Node* head , int val){
    Node* New = new Node(val);
    if(head == nullptr){
        return New;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* prev = temp->back;
    prev->next = New;
    New->back = prev;
    New->next = temp;
    temp->back = New;
    return head;
}

//insertbeforekthnode
Node* insertbeforekth(Node* head , int val , int k){
    Node* New = new Node(val);
    if(head == nullptr){
        return New;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt == k-1){
        break;
        }
        temp= temp->next; 
    }
    Node* prev = temp->back;
    prev->next = New;
    New->back = prev;
    temp->back = New;
    New->next = temp;
    return head;
    
}

//insertafterkthnode
Node* insertafterkth(Node* head , int val , int k){
    Node* New = new Node(val);
    if(head == nullptr) return New;

    int cnt =0;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt == k+1){
            break;
        }
        temp = temp->next;
    }
    Node* front = temp->next;
    if(front == nullptr) Insertionaftertail(head , k);
    New->next = front;
    front->back = New;
    temp->next = New;
    New->back = temp;
    return head;

}

// insertbeforenode
void insesrtbeforenode(Node* temp , int val ){
    Node* New = new Node(val);
    Node* prev = temp->back;
    prev->next = New;
    New->back = prev;
    New->next = temp;
    temp->back = New;
    
}

//insertafternode
void insesrtafternode(Node* temp , int val ){
    Node* New = new Node(val);
    Node* front = temp->next;
    front->back = New;
    New->next = front;
    New->back = temp;
    temp->next = New;
    
}
int main(){
    vector<int> arr = {12,2,6,9,10,14};
    Node* head = ConvertarrtoDll(arr);
    // print(head);
    // cout<<endl;
    // head = DeleteheadinDll(head);
    // print(head);
    // cout<<endl;
    // head = DeletetailofDll(head);
    // print(head);
    // int k = 4;
    // head = DeleteKthNode(head , k);
    // print(head);
    // cout<<endl;
    // DeleteNodeinDll(head->next);
    // print(head);
    int val = 7;
    head = Insertionbeforethehead(head , val);
    print(head);
    cout<<endl;
    val = 8;
    head = Insertionafterhead(head , val);
    print(head);
    cout<<endl;
    val = 13;
    head = Insertionaftertail(head , val);
    print(head);
    cout<<endl;
    val = 22;
    head = insertionbeforetail(head , val);
    print(head);
    cout<<endl;
    val=21;
    int k = 3;
    head = insertbeforekth(head , val , k);
    print(head);
    cout<<endl;
    k = 5;
    val = 25;
    head = insertafterkth(head , val , k);
    print(head);
    cout<<endl;
    val = 23;
    insesrtbeforenode(head->next->next , val);
    print(head);
    cout<<endl;
    val = 17;
    insesrtafternode(head->next->next->next->next , val);
    print(head);
}