//One way linked list with head only

#include <utility>

template <typename T> class LinkedList{
private:
    struct Node{
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr){}
    };

    Node* head;

    void clear() {
        Node* temp;
        while (head != nullptr) {
            temp = head->next;
            delete head;
            head = temp;
        }
        head = nullptr;
    }

    Node* getLast(){
        if(this->head == nullptr){return nullptr};

        Node* temp = this->head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp;
    }
    
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
        this->head = other.head;
        other.head = nullptr;
    }

    LinkedList(const LinkedList<T> &copy)
    {
        if(copy.head == nullptr){this->head = nullptr; return;}

        this->head = new Node(copy.head->data);

        Node *tmp = this->head;
        Node *tmp2 = copy.head->next;

        while (tmp2 != nullptr)
        {
            tmp->next = new Node(tmp2->data);

            tmp = tmp->next;
            tmp2 = tmp2->next;
        }        
    }



    
    LinkedList& operator=(LinkedList<T>&& other)
    {
        if (this == &other) return *this;
        
        this->clear();

        this->head = other.head;
        other.head = nullptr;

        return *this;
    }

    LinkedList& operator=(const LinkedList<T>& copy)
    {
        this->clear();
        if (copy.head == nullptr) return *this;

        this->head = new Node(copy.head->data);

        Node *tmp = this->head;
        Node *tmp2 = copy.head->next;

        while (tmp2 != nullptr)
        {
            tmp->next = new Node(tmp2->data);

            tmp = tmp->next;
            tmp2 = tmp2->next;
        }

        return *this;     
    }

    void addLast (T val)
    {
        if (this->head == nullptr)
        {
            thi->head = new Node(val);
        }
        else
        {
        Node* tmplast = this->getLast();
        tmplast->next = new Node(val);
        }

};

