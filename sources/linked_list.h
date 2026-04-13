//One way linked list with head only
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
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

    unsigned int len()
    {
        if(this->head == nullptr){return 0;}
        unsigned int ln=1;
        Node *tmp = this->head;

        while (tmp->next != nullptr)
        {
            tmp = tmp->next;
            ln++;
        }     
        return ln;
    }
    unsigned int size()
    {
		return len();
	}
	
    unsigned int mem_size()
    {
		return len();
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

    int add_last (T val)
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
        return 0;
    }

    int add_first (T val)
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
        return 0;
    }

    int add_on_position (T val, unsigned int pos)
    {
        if (this->isEmpty() && pos == 0)
        {
            this->head = new Node (val);
            return 0;
        }

        if (pos == 0)
        {
            this->add_first(val);
            return 0;
        }

        if(this->getOnPossition(pos-1) == nullptr) return -1;
        else
        {
            Node *tmp = this->getOnPossition(pos-1);
            Node *tmp2 = tmp->next;
            tmp->next = new Node(val);
            tmp = tmp->next;
            tmp-> next = tmp2;
            return 0;
        }
    }

    long long int find (T val)//returns index, if not -1
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

    T* remove_first()
    {
		T* usuwany_element = new T;
        if (this->isEmpty())
            return nullptr;
        Node *tmp = this->head;
        this->head = this->head->next;
        *usuwany_element=std::move(tmp->data);
        delete tmp;
        return usuwany_element;
    }

    T* remove_last()
    {
        if (this->isEmpty())
            return nullptr;
        if (this->head->next == nullptr)
        {
            delete this->head;
            this->head = nullptr;
            return nullptr;
        }
        
        Node *tmp = this->head;
        Node *tmplast = this->getLast();
        while(tmp->next != tmplast && tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = nullptr;
		T* usuwany_element = new T;
        *usuwany_element=std::move(tmplast->data);
        delete tmplast;
        return usuwany_element;
        
    }

    T* remove_on_position(unsigned int pos)
    {

		
        
        if (this->isEmpty() || pos < 0)
            return nullptr;
   


        if (pos == 0)
        {
            return this->remove_first();
        }
   
     Node *tmp = this->getOnPossition(pos-1);

        if(tmp == nullptr) return nullptr;

        if (tmp->next == nullptr)
        return nullptr;        

        if (tmp->next->next == nullptr)
        {
            return this->remove_last();
        }        
        
            
		T* usuwany_element = new T;
            Node *tmp2 = tmp->next;
            Node *tempgc = tmp->next;
            tmp2 = tmp2->next;
            tmp->next = tmp2;
        *usuwany_element=std::move(tempgc->data);
            delete tempgc;
        return usuwany_element;
            
        
    }
    
	T operator [](int i) const    {
		Node* current = head;
		for(int j = 0; j < i; j++)
		{
			current=current->next;
		}
		return (current.data);
	}
    T & operator [](int i) {
		Node* current = head;
		for(int j = 0; j < i; j++)
		{
			current=current->next;
		}
			return (current->data);
		}
};


#endif
