#pragma once
#include<functional>
#include<ostream>
#include<initializer_list>
#include<iomanip>

template<class Data>
class FoolBST
{
public:
    using value_type = typename Data;

    struct Node
    {
        Data data;
        int height;
        Node* left;
        Node* right;

        Node(Data data = Data(), int height = 0, Node* left = nullptr, Node* right = nullptr)
            :data(data), height(height), left(left), right(right)
        {

        }
    };

    Node* root = nullptr;

    Data min()
    {
        Node* current = root;
        while (current->left)
        {
            current = current->left;
        }
        return current->data;
    }

    Data max()
    {
        Node* current = root;
        while (current->right)
        {
            current = current->right;
        }
        return current->data;
    }

    void insert(Data data)
    {
        root = insert(root, std::move(data));
    }

    void insert(const std::initializer_list<Data>& initList)
    {
        for (auto& i : initList)
        {
            insert(i);
        }
    }

    void inOrderTraverse(const std::function<void(Data)>& visit)
    {
        inOrderTraverse(root, visit);
    }

    friend std::ostream& operator<<(std::ostream& out, FoolBST<Data> toPrint)
    {
        int count = 0;

        toPrint.inOrderTraverse(toPrint.root, [&count, &out](Data data)
            {
                out << std::setw(13) << data;
                ++count;
                if (count % 10 == 0)
                {
                    out << '\n';
                }
            });
        return out;
    }

    ~FoolBST()
    {
        clear(root);
        delete root;
    }

protected:
    inline static int nodeHeight(Node* current)
    {
        if (!current)
            return -1;
        else
            return current->height;
    }

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
        current->height = caculateAVLHeight(current);
        ++current->height;
        return current;
    }

    inline static int caculateAVLHeight(Node* current)
    {
        return nodeHeight(current->left) > nodeHeight(current->right) ? nodeHeight(current->left) : nodeHeight(current->right);
    }

    void inOrderTraverse(Node* current, const std::function<void(Data)>& visit)
    {
        if (!current)
            return;
        inOrderTraverse(current->left, visit);
        visit(current->data);
        inOrderTraverse(current->right, visit);
    }

    void clear(Node* current)
    {
        if (current->left)
        {
            clear(current->left);
            delete current->left;
        }
        if (current->right)
        {
            clear(current->right);
            delete current->right;
        }
    }
};
