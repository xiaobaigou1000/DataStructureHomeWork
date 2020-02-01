#pragma once
#include"FoolBST.h"

template<class Data>
class FoolAVL :public FoolBST<Data>
{
public:
    using Node = FoolBST<Data>::Node;

    void insert(Data data)
    {
        this->root = insert(this->root, std::move(data));
    }

    void insert(const std::initializer_list<Data>& initList)
    {
        for (auto& i : initList)
        {
            insert(i);
        }
    }
protected:
    Node* insert(Node* current, Data data)
    {
        if (current == nullptr)
        {
            current = new Node(std::move(data));
            return current;
        }

        if (data < current->data)
        {
            current->left = insert(current->left, data);
        }
        else
        {
            current->right = insert(current->right, data);
        }
        current->height = FoolBST<Data>::caculateAVLHeight(current);
        ++current->height;

        if (testAVL(current) < -1)
        {
            if (testAVL(current->right) < 0)
            {
                current = leftRotate(current);
            }
            else
            {
                current->right = rightRotate(current->right);
                current = leftRotate(current);
            }
        }
        else if (testAVL(current) > 1)
        {
            if (testAVL(current->left) > 0)
            {
                current = rightRotate(current);
            }
            else
            {
                current->left = leftRotate(current->left);
                current = rightRotate(current);
            }
        }

        return current;
    }

    inline static int testAVL(Node* current)
    {
        return FoolBST<Data>::nodeHeight(current->left) - FoolBST<Data>::nodeHeight(current->right);
    }

    inline static Node* leftRotate(Node* toRotate)
    {
        Node* right = toRotate->right;
        toRotate->right = right->left;
        right->left = toRotate;
        toRotate->height = FoolBST<Data>::caculateAVLHeight(toRotate);
        right->height = FoolBST<Data>::caculateAVLHeight(right);
        return right;
    }

    inline static Node* rightRotate(Node* toRotate)
    {
        Node* left = toRotate->left;
        toRotate->left = left->right;
        left->right = toRotate;
        toRotate->height = FoolBST<Data>::caculateAVLHeight(toRotate);
        left->height = FoolBST<Data>::caculateAVLHeight(left);
        return left;
    }
};