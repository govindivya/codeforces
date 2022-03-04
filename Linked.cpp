#include <bits/stdc++.h>

using namespace std;

template <typename T>

class LinkedList
{
private:
    class Node
    {
    public:
        Node *next;
        Node *prev;
        T data;
        Node(T data)
        {
            this->data = data;
        }
    };
    Node *front;
    Node *back;
    int listSize = 0;

public:
    LinkedList()
    {
        this->front = NULL;
        this->back = NULL;
        this->listSize = 0;
    }
    LinkedList(T data)
    {
        this->front = new Node(data);
        this->back = this->front;
        this->front->next = this->front;
        this->front->prev = this->front;
        this->listSize = 1;
    }
    bool insertBack(T data)
    {
        try
        {
            if (this->front == NULL)
            {
                this->front = new Node(data);
                this->back = this->front;
                this->front->next = this->front;
                this->front->prev = this->front;
                return true;
            }
            Node *newNode = new Node(data);
            newNode->prev = this->back;
            newNode->next = this->front;
            this->back->next = newNode;
            this->front->prev = newNode;
            this->back = newNode;
            this->listSize += 1;
            return true;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            throw new exception(e);
        }
    }
    bool insertFront(T data)
    {
        try
        {
            if (this->front == NULL)
            {
                this->front = new Node(data);
                this->back = this->front;
                this->front->next = this->front;
                this->front->prev = this->front;
                return true;
            }
            Node *newNode = new Node(data);
            newNode->prev = this->back;
            newNode->next = this->front;
            this->back->next = newNode;
            this->front->prev = newNode;
            this->front = newNode;
            this->listSize += 1;
            return true;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            throw new exception(e);
        }
    }
    bool remove(T data)
    {
        try
        {
            if (this->front == NULL)
            {
                return true;
            }
            if (this->front->data == data)
            {
                if (this->listSize == 1)
                {
                    delete this->front;
                    this->front = NULL;
                    this->back = NULL;
                    return true;
                }
                else
                {
                    this->back->next = this->front->next;
                    this->front->next->prev = this->back;
                    delete front;
                    this->front = this->back->next;
                    return true;
                }
            }
            Node *node = this->front;
            while (node->next != this->front && node->data != data)
            {
                node = node->next;
            }
            if (node != this->front)
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                if (node == this->back)
                {
                    this->back = node->prev;
                    this->front->prev = this->back;
                }
                delete node;
                return true;
            }
            return false;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
    }
    T getfront()
    {
        try
        {
            return this->front->data;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    T getBack()
    {
        try
        {
            return this->back->data;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    T popFront()
    {
        try
        {
            T val = this->front->data;
            this->remove(val);
            return val;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    T popBack()
    {
        try
        {
            T val = this->back->data;
            this->remove(val);
            return val;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    bool find(T data)
    {
        if (this->front == NULL)
        {
            return false;
        }
        Node *n = this->front;
        if (n->data == data)
        {
            return true;
        }
        n = n->next;
        while (n != this->front && n->data != data)
        {
            n = n->next;
        }
        if (n == this->front)
        {
            return false;
        }
        return true;
    }
    int getSize()
    {
        return this->listSize;
    }
    void printList()
    {
        if (this->front == NULL)
        {
            return;
        }
        Node *n = this->front;
        cout << n->data << " ";
        n = n->next;
        while (n != this->front)
        {
            cout << n->data << " ";
            n = n->next;
        }
    }
    bool insertAll(T data[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            this->insertBack(data[i]);
        }
        return true;
    }
    bool clear()
    {
        if (this->front == NULL)
        {
            return true;
        }
        Node *node1 = this->front->next;
        Node *node2 = this->front->next;

        while (node2 != this->front)
        {
            node2 = node2->next;
            delete node1;
            node1 = node2;
        }
        delete node2;
        this->front = NULL;
        this->back = NULL;
        this->listSize = 0;
        return true;
    }
    void sort()
    {
        if (this->front == NULL)
        {
            return;
        }
        Node *n = this->front->next;
        Node *n1 = this->front->next;

        T val;
        while (n != this->front)
        {
            while (n != this->front)
            {
            }
        }
    }
    void reverse()
    {
        if (this->front == NULL)
        {
            return;
        }
        Node *n = this->front;
        this->front = this->back;
        this->back = n;
    }
    ~LinkedList()
    {
        this->clear();
    }
};

int main()
{
    LinkedList<int> *l = new LinkedList<int>(20);
    l->insertBack(21);
    l->insertBack(23);
    l->insertBack(26);
    l->insertBack(29);
    l->insertBack(34);
    // int arr[]={35,67,89,100};
    // l->insertAll(arr,4);
    // l->printList();
    cout << l->find(21) << "\n";
    cout << l->getBack() << "\n";
    cout << l->getfront() << "\n";
    l->reverse();
    cout << l->getfront() << "\n";

    l->clear();
}