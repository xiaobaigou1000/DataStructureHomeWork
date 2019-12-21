#pragma once
#include<ostream>
#include<iomanip>
#include<exception>

class StackEmpty :std::exception
{
    const char* what() const
    {
        return "empty stack";
    }
};

template<class Data>
class FoolStack
{
public:
    struct Node
    {
        Data data;
        Node* next;

        Node()
        {
            data = Data();
            next = nullptr;
        }

        Node(const Data& data, Node* next)
            :data(data), next(next)
        {
        }
    };

    friend std::ostream& operator<<(std::ostream& out, const FoolStack<Data>& myStack)
    {
        FoolStack<Data>::Node* tmp = myStack.head;
        while (tmp)
        {
            out << std::setw(20) << tmp->data;
            tmp = tmp->next;
        }

        return out;
    }

    FoolStack()
        :head(nullptr)
    {

    }

    void push(const Data& data)
    {
        Node* toPush = new Node(data, head);
        head = toPush;
    }

    Data pop()
    {
        if (empty())
        {
            throw StackEmpty();
        }

        Node* toPop = head;
        Data ret = toPop->data;
        head = toPop->next;
        delete toPop;
        return ret;
    }

    Data top()
    {
        if (empty())
        {
            throw StackEmpty();
        }

        return head->data;
    }

    bool empty()
    {
        return head == nullptr;
    }

    void clear()
    {
        Node* ite = head;
        Node* toDel;
        while (ite)
        {
            toDel = ite;
            ite = ite->next;
            delete toDel;
        }

        head = nullptr;
    }

    ~FoolStack()
    {
        clear();
    }
private:
    Node* head;
};