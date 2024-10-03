#include <iostream>
#include <vector>

struct Node{
    //public: by default while class is private: by default
        int data;
        Node* next;

    Node(int data = (int)NULL, Node* next = NULL){
        this->data = data;
        this->next = next;
    }
};


class LinkedList{
    private:
        Node* head;
    
    public: 
        //LinkedList() : head(NULL) {}
        
        LinkedList(){
            this->head = nullptr;
        }
        
        void InsertAtEnd(int value){
            Node* newNode = new Node(value);
            newNode->next = NULL;
        
            if (!this->head){
                this->head = newNode;
                return;
            }
            
            Node* temp = this->head;
            while (temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        
        void LogNodes(){
            Node* cur = this->head;
            std::vector<int> elem;
            while (cur->next){
                if (cur == this->head){
                    elem.push_back(cur->data);
                }
                cur = cur->next;
                elem.push_back(cur->data);
            }
            
            for (int i : elem){
                if (i != elem[elem.size()-1]){
                    std::cout << "[" << i << "]" << "->";
                }
                else {
                    std::cout << "[" << i << "]" << std::endl;
                }
            }
        }
        
        void Index_Insert(int value, int index){
            Node* cur = this->head;
            Node* new_Node = new Node(value);
            int cur_idx = 0;
            
            if (index == 0){
                InsertAtBeginning(value);
                return;
            }
            
            while (cur->next){
                if (cur_idx == index && cur_idx != 0){
                    new_Node->next = cur->next;
                    cur->next = new_Node;
                    break;
                }
                else{
                    cur = cur->next;
                    cur_idx++;
                }
            }
        }
        
        void InsertAtBeginning(int value){
//            Node* cur = this->head;
            Node* newNode = new Node(value);
            //Node* temp = newNode;
            newNode->next = this->head;
            this->head = newNode;
            //newNode = cur->next;
            //cur = newNode;
        }
        
        void DeleteNode(int value){
            Node* cur = this->head;
            while (cur->next){
//                std::cout << cur->data << std::endl;
                if (cur->next->data == value){
//                    std::cout << cur->data << std::endl;
                    cur->next = cur->next->next;
//                    std::cout << cur->next->data << std::endl;
                    return;
                }
                else{
                    cur = cur->next;
                }
            }
        }
};

void ArrNodeBuilder(int (*arr)[10]){
    LinkedList Llist;
    for (int &elem : *arr){
        Llist.InsertAtEnd(elem);
    }
    Llist.LogNodes();
    delete [] arr;
}

void DynamicNodeBuilder(std::vector<int> vec){ 
    LinkedList Llist;
    for (int elem : vec){
        Llist.InsertAtEnd(elem);
    }
    Llist.LogNodes();
}

int main(){
//    LinkedList Llist;
//    Llist.InsertAtEnd(1);
//    Llist.InsertAtEnd(5);
//    Llist.InsertAtEnd(10);
//    Llist.InsertAtEnd(3);
//    Llist.LogNodes();
//    Llist.Index_Insert(20, 0);
//    Llist.LogNodes();
//    Llist.DeleteNode(1);
//    Llist.LogNodes();
//    Llist.DeleteNode(10);
//    Llist.LogNodes();
    int (*arr)[10] = new int[1][10]{{1,2,3,4}};
    ArrNodeBuilder(arr);
    std::vector<int> vec = {10,20,30,40};
    DynamicNodeBuilder(vec);
    return 0;
}