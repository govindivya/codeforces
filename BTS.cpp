#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BST
{
private:
    class Node
    {
    public:
        Node *left = NULL;
        Node *right = NULL;
        Node *parent = NULL;
        T data = 0, totalChild = 0;
        Node(T value)
        {
            this->data = value;
        }
    };
    Node *root = NULL;
    int bstSize = 0;


public:
    BST(T data)
    {
        try
        {
            this->root = new Node(data);
            this->bstSize=1;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            throw new exception(e);
        }
    }
    bool insert(T data)
    {
        try
        {
            if (this->root != NULL)
            {
                Node *A = this->root;
                Node *B = this->root;

                while (B != NULL)
                {
                    A = B;
                    A->totalChild++;
                    if (B->data > data)
                    {
                        B = B->left;
                    }
                    else
                    {
                        B = B->right;
                    }
                }
                Node *newNode = new Node(data);
                newNode->left = NULL;
                newNode->right = NULL;
                newNode->totalChild = 0;
                if (A->data > data)
                {
                    A->left = newNode;
                    newNode->parent = A;
                }
                else
                {
                    A->right = newNode;
                    newNode->parent = A;
                }
            }
            else
            {
                this->root = new Node(data);
                this->root->totalChild++;
            }
            this->bstSize=this->bstSize+1;
            return true;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            throw new exception(e);
            return false;
        }
    }
    bool remove(T data)
    {
        try
        {
            if (this->root == NULL)
            {
                return true;
            }
            Node *B = this->root;
            while (B != NULL && B->data != data)
            {
                if (B->data > data)
                {
                    B = B->left;
                }
                else
                {
                    B = B->right;
                }
            }
            if (B != NULL && this->size == 1)
            {
                delete root;
                root = NULL;
                size = 0;
                return true;
            }
            if (B != NULL)
            {
                Node *leftChild = B->left;
                Node *rightChild = B->right;
                B->totalChild--;

                if (leftChild != NULL && rightChild != NULL)
                {
                    while (leftChild->right != NULL)
                    {
                        leftChild->totalChild--;
                        leftChild = leftChild->right;
                    }
                    Node *parent = leftChild->parent;
                    T value = leftChild->data;
                    delete leftChild;
                    parent->right = NULL;
                    B->data = value;
                }
                else if (leftChild != NULL)
                {
                    T value = leftChild->data;
                    Node *bp = B->parent;
                    delete B;
                    leftChild->parent = bp;
                    bp->left = leftChild;
                    bp->totalChild--;
                }
                else if (rightChild != NULL)
                {
                    T value = rightChild->data;
                    Node *bp = B->parent;
                    delete B;
                    rightChild->parent = bp;
                    bp->right = rightChild;
                    bp->totalChild--;
                }
                else
                {
                    if (B == B->parent->right)
                    {
                        B->parent->right = NULL;
                    }
                    else
                    {
                        B->parent->left = NULL;
                    }
                    delete B;
                }
            }
            this->bstSize=this->bstSize-1;
            return true;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            throw new exception(e);
            return false;
        }
    }
    void deleteBST(Node node)
    {
        if (node->left == NULL && node->right == NULL)
        {
            delete node;
            return;
        }
        deleteBST(node->left);
        deleteBST(node->right);
    }
    ~BST()
    {
        deleteBST();
    }
    bool find(T data)
    {
        if (this->root == NULL)
        {

            return false;
        }
        Node *b = this->root;
        while (b != NULL && b->data != data)
        {
            if (b->data > data)
            {
                b = b->left;
            }
            else
            {
                b = b->right;
            }
        }
        if (b != NULL)
        {
            return true;
        }
        return false;
    }
    int size()
    {
        return this->bstSize;
    }
    bool replace(T val1, T val2)
    {
        if (this->root == NULL)
        {

            return false;
        }
        bool isExist = this->find(val1);
        if(isExist){
            this->remove(val1);
            this->insert(val2);
            return true;
        }
        return false;
    }
    void printBST(Node *node)
    {
        if (node != NULL)
        {
            printBST(node->left);
            cout << node->data << " ";
            printBST(node->right);
        }
    }
    void print()
    {
        printBST(this->root);
    }
};

int main()
{
    BST<int> *bst = new BST<int>(15);
    bst->insert(20);
    bst->insert(21);
    bst->insert(5);
    bst->insert(3);
    bst->print();
}