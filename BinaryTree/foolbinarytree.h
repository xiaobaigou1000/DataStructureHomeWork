#pragma once
#include<iostream>
#include<functional>

template<class Data>
class FoolBinaryTree
{
public:
    struct BTNode
    {
        Data data;
        BTNode* lchild, * rchild;

        BTNode()
        {
            lchild = nullptr;
            rchild = nullptr;
        };

        BTNode(Data data) :data(data)
        {
            lchild = nullptr;
            rchild = nullptr;
        }

        BTNode(Data data, BTNode* lchild, BTNode* rchild)
            :data(data), lchild(lchild), rchild(rchild)
        {

        }

        void insertLeft(const Data& data)
        {
            if (lchild != nullptr)
            {
                BTNode* temp = new BTNode(data, lchild, nullptr);
                lchild = temp;
            }
            else
            {
                lchild = new BTNode(data, nullptr, nullptr);
            }
        }

        void insertRight(const Data& data)
        {
            if (rchild != nullptr)
            {
                BTNode* temp = new BTNode(data, nullptr, rchild);
                rchild = temp;
            }
            else
            {
                rchild = new BTNode(data, nullptr, nullptr);
            }
        }
    };

    FoolBinaryTree()
    {
        root = new BTNode(Data(), nullptr, nullptr);
        endInputFlag = Data();
    }

    ~FoolBinaryTree()
    {
        destroyFunc(root);
    }

    void preOrderTraverse(const std::function<void(Data)>& visit)
    {
        preOrderTraverse(root, visit);
    }

    void inOrderTraverse(const std::function<void(Data)>& visit)
    {
        inOrderTraverse(root, visit);
    }

    void postOrderTraverse(const std::function<void(Data)>& visit)
    {
        postOrderTraverse(root, visit);
    }

    void createBinaryTreeByPreOrder(const std::function<Data()>& input)
    {
        createBinaryTreeByPreOrder(root, input);
    }

    int leafCount()
    {
        return leafCount(root);
    }

    int nodeCount()
    {
        return nodeCount(root);
    }

    int caculateDepth()
    {
        return depth(root);
    }

    void exchangeChildren()
    {
        exchangeChildren(root);
    }

    BTNode* root;
    Data endInputFlag;
private:
    void createBinaryTreeByPreOrder(BTNode*& current, const std::function<Data()>& input)
    {
        Data currentData;
        currentData = input();
        if (currentData == endInputFlag)
        {
            current = nullptr;
            return;
        }
        current = new BTNode(currentData, nullptr, nullptr);
        std::cout << "Please input left child for student: " << current->data << '\n';
        createBinaryTreeByPreOrder(current->lchild, input);
        std::cout << "Please input right child for student: " << current->data << '\n';
        createBinaryTreeByPreOrder(current->rchild, input);
    }

    int leafCount(BTNode* current)
    {
        if (!current)
            return 0;
        if (!current->lchild && !current->rchild)
            return 1;
        return (leafCount(current->lchild) + leafCount(current->rchild));
    }

    int nodeCount(BTNode* current)
    {
        if (!current)
            return 0;
        return (nodeCount(current->lchild) + nodeCount(current->rchild)+1);
    }

    void preOrderTraverse(BTNode* current, const std::function<void(Data)>& visit)
    {
        if (current != nullptr)
        {
            visit(current->data);
            preOrderTraverse(current->lchild, visit);
            preOrderTraverse(current->rchild, visit);
        }
    }

    void inOrderTraverse(BTNode* current, const std::function<void(Data)>& visit)
    {
        if (current != nullptr)
        {
            inOrderTraverse(current->lchild, visit);
            visit(current->data);
            inOrderTraverse(current->rchild, visit);
        }
    }

    void postOrderTraverse(BTNode* current, const std::function<void(Data)>& visit)
    {
        if (current != nullptr)
        {
            postOrderTraverse(current->lchild, visit);
            postOrderTraverse(current->rchild, visit);
            visit(current->data);
        }
    }

    int depth(BTNode* current)
    {
        if (!current)
            return 0;
        int h1 = depth(current->lchild);
        int h2 = depth(current->rchild);
        if (h1 > h2)
            return h1 + 1;
        else
            return h2 + 1;
    }

    void destroyFunc(BTNode* current)
    {
        if (current)
        {
            destroyFunc(current->lchild);
            destroyFunc(current->rchild);
            delete current;
        }
    }

    void exchangeChildren(BTNode* current)
    {
        if (current)
        {
            BTNode* temp;
            exchangeChildren(current->lchild);
            exchangeChildren(current->rchild);
            temp = current->lchild;
            current->lchild = current->rchild;
            current->rchild = temp;
        }
    }
};