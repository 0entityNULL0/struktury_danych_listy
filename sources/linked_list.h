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
        if(this->head == nullptr){return nullptr;}

        Node* temp = this->head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp;
    }
    Node* getOnPossition(long long int pos){
        if(this->head == nullptr || pos < 0){return nullptr;}

        Node* temp = this->head;
        for (int i=1; i<=pos; i++)
        {
            if(temp->next == nullptr) return nullptr;
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

    bool isEmpty() //1 empty, 0 no
    {
        return this->head == nullptr;
    }

    long long int len()
    {
        if(this->head == nullptr){return 0;}
        long long int ln=1;
        Node *tmp = this->head;

        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
            ln++;
        }     
        return ln;
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
            this->head = new Node(val);
        }
        else
        {
        Node* tmplast = this->getLast();
        tmplast->next = new Node(val);
        }
    }

    void addFirst (T val)
    {
        if (this->head == nullptr)
        {
            this->head = new Node(val);
        }
        else
        {
        Node* tmpfirst = new Node(val);
        tmpfirst->next = this->head;
        this->head = tmpfirst;
        }
    }

    void addAtPos (T val, long long int pos)
    {
        if (this->isEmpty() && pos == 0)
        {
            this->head = new Node (val);
            return;
        }

        if (pos == 0)
        {
            this->addFirst(val);
            return;
        }

        if(this->getOnPossition(pos-1) == nullptr) return;
        else
        {
            Node *tmp = this->getOnPossition(pos-1);
            Node *tmp2 = tmp->next;
            tmp->next = new Node(val);
            tmp = tmp->next;
            tmp-> next = tmp2;
        }
    }

    long long int findValue(T val)//returns index, if not -1
    {
        long long int ind =0;
        if(this->head == nullptr ){return -1;}

        Node* temp = this->head;
        while(temp != nullptr)
        {
            if(temp->data == val) return ind;
            temp = temp->next;
            ind++;
        }
        return -1;
    }
};

