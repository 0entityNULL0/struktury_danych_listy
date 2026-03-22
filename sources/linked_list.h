//One way linked list with head only

#include <utility>

template <typename T> class LinkedList{
private:
    struct Node{
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr){}
    }

    Node* head;

    public:
    LinkedList() : head(nullptr){};

    ~LinkedList()
    {
        Node *temp;
        while(head != nullptr)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
    }

    LinkedList(LinkedList&& other)
    {
        this->head = copy.head;
        other->head = nullptr;
    }

    LinkedList(LinkedList<T> const &copy)
    {
        if(copy.head == nullptr){this->head = nullptr; return;}

        this->head = new Node(copy.head->data);

        Node *tmp = this->head;
        Node *tmp2 = copy.head->next;

        while (tmp2 != nullptr)
        {
            tmp->next = new Node(tmp2->data);

            tmp.head = tmp->next;
            tmp2.head = tmp2->next;
        }        
    }





}

