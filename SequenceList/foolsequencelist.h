#pragma once
#include <iostream>

template <class Data>
class FoolLinkedList
{
public:
    struct Node
    {
        Data data;
        Node* next;

        Node()
        {
            next = nullptr;
        }

        Node(const Data& data) : data(data)
        {
            next = nullptr;
        }
    };

    FoolLinkedList()
    {
        head = new Node();
    }

    ~FoolLinkedList()
    {
        if (head)
        {
            clear();
            delete head;
        }
    }

    void clear()
    {
        if (head)
        {
            Node* toDel;
            Node* current = head->next;
            while (current)
            {
                toDel = current;
                current = current->next;
                delete toDel;
            }
            head->next = nullptr;
        }
    }

    int getLength()
    {
        Node* current = head->next;
        int length=0;
        while (current)
        {
            length++;
            current = current->next;
        }
        return length;
    }

    bool isEmpty()
    {
        if (head->next)
            return false;
        else
            return true;
    }

    int locateElem(const Data& data)
    {
        Node* current = head->next;
        int position = 0;
        while (current && (current->data != data))
        {
            current = current->next;
            position++;
        }
        if (current)
            return position;
        else
            return -1;
    }

    Data getElem(int position)
    {
        // if (position < 0)
        //     throw std::exception();

        Node* current = head->next;
        for (int i = 0; i != position && current; i++)
        {
            current = current->next;
        }

        if (current)
            return current->data;
        else
            throw std::exception();
    }

    void insertElem(int position, Data toInsert)
    {
        // if (position < 0)
        //     throw std::exception();
        Node* current = head;
        for (int i = 0; i < position && current != nullptr; i++)
            current = current->next;
        if (current)
        {
            Node* newNode = new Node(toInsert);
            newNode->next = current->next;
            current->next = newNode;
        }
        else
        {
            throw std::exception();
        }
    }

    Data deleteElem(int position)
    {
        Node* current = head;

        for (int i = 0; i < position && current != nullptr; i++)
            current = current->next;

        Data retValue;
        if (current)
        {
            Node* toDel = current->next;
            current->next = toDel->next;
            retValue = toDel->data;
            delete toDel;
        }
        else
        {
            throw std::exception();
        }

        return retValue;
    }

    friend FoolLinkedList<Data>* operator*(FoolLinkedList<Data>& list1, FoolLinkedList<Data>& list2)
    {
        Node* aPos = list1.head->next;
        Node* bPos = list2.head->next;
        Node* toDel;
        typename FoolLinkedList<Data>::Node* before = list1.head;
        while (aPos && bPos)
        {
            if (aPos->data > bPos->data)
            {
                bPos = bPos->next;
            }
            else if (aPos->data < bPos->data)
            {
                toDel = aPos;
                aPos = aPos->next;
                delete toDel;
            }
            else
            {
                before->next = aPos;
                before = before->next;
                aPos = aPos->next;
                bPos = bPos->next;
            }
        }

        before->next = nullptr;

        if (aPos)
        {
            Node* current = aPos;
            while (current)
            {
                toDel = current;
                current = current->next;
                delete toDel;
            }
            aPos->next = nullptr;
        }
        return &list1;
    }

    void breakInTwo(FoolLinkedList<Data>& list1, FoolLinkedList<Data>& list2)
    {
        Node* current = this->head->next;
        Node* beforeToDel = this->head;
        Node* toDel;
        while (current)
        {
            if (current->data < 0)
            {
                toDel = current;
                beforeToDel->next = current->next;
                current = current->next;
                list1.push_front_with_pointer(toDel);
            }
            else
            {
                toDel = current;
                beforeToDel->next = current->next;
                current = current->next;
                list2.push_front_with_pointer(toDel);
            }
        }
        delete this->head;
        this->head = nullptr;
    }

    void push_front(Data data)
    {
        Node* toAdd = new Node(data);
        toAdd->next = head->next;
        head->next = toAdd;
    }

    void push_back(Data data)
    {
        Node* back = head;
        while (back->next)
        {
            back = back->next;
        }

        Node* toAdd = new Node(data);
        back->next = toAdd;
    }

    void push_front_with_pointer(Node* toPush)
    {
        Node* toAdd = toPush;
        toAdd->next = head->next;
        head->next = toAdd;
    }

    Node* getHeadPointer()
    {
        return head;
    }

    friend FoolLinkedList<Data> linearMerge(FoolLinkedList<Data>& list1, FoolLinkedList<Data>& list2)
    {
        FoolLinkedList<Data> newList;
        Node* aPos = list1.head->next;
        Node* bPos = list2.head->next;
        Node* newListPos = newList.head;

        while (aPos && bPos)
        {
            if (aPos->data > bPos->data)
            {
                newListPos->next = bPos;
                bPos = bPos->next;
                newListPos = newListPos->next;
            }
            else
            {
                newListPos->next = aPos;
                aPos = aPos->next;
                newListPos = newListPos->next;
            }
        }

        while (aPos)
        {
            newListPos->next = aPos;
            aPos = aPos->next;
            newListPos = newListPos->next;
        }

        while (bPos)
        {
            newListPos->next = bPos;
            bPos = bPos->next;
            newListPos = newListPos->next;
        }

        delete list1.head;
        list1.head = nullptr;
        delete list2.head;
        list2.head = nullptr;
        return newList;
    }

    Data operator[](int position)
    {
        if (position < 0)
            throw std::exception();

        Node* current = head->next;
        for (int i = 0; i != position && current; i++)
        {
            current = current->next;
        }

        if (current)
            return current->data;
        else
            throw std::exception();
    }

    friend FoolLinkedList<Data> operator+(FoolLinkedList<Data>& list1, FoolLinkedList<Data>& list2)
    {
        FoolLinkedList<Data> newList;
        newList.head = list1.head;
        Node* listmiddle = list1.head;
        while (listmiddle->next)
        {
            listmiddle = listmiddle->next;
        }
        listmiddle->next = list2.head->next;

        list1.head = nullptr;
        delete list2.head;
        list2.head = nullptr;
        return newList;
    }

    friend std::ostream& operator<<(std::ostream& out, const FoolLinkedList<Data>& list)
    {
        typename FoolLinkedList<Data>::Node* current;
        current = list.head->next;
        while (current)
        {
            out << current->data << " ";
            current = current->next;
        }
        return out;
    }

private:
    Node* head;
};

void menu()
{
    using std::cout;
    cout << "\n\n\n";
    cout << "linked list example program\n\n";
    cout << "   1---initialize list\n";
    cout << "   2---destroy list\n";
    cout << "   3---clear list\n";
    cout << "   4---get length of list\n";
    cout << "   5---test if list is empty\n";
    cout << "   6---search list by position\n";
    cout << "   7---search list by element value\n";
    cout << "   8---insert an element\n";
    cout << "   9---delete element by id\n";
    cout << "   a---delete element by value\n";
    cout << "   b---print the whole list\n";
    cout << "   please choose option\n";
}

void LinkedListTest()
{
    char choice = -1;
    FoolLinkedList<int>* list = nullptr;
    menu();
    int value;
    int position;
    int result;


    while (std::cin >> choice)
    {
        switch (choice)
        {
        case '1':
            if (list)
            {
                std::cout << "list already exist.\n";
                break;
            }
            list = new FoolLinkedList<int>;
            std::cout << "create list success.\n";
            break;
        case '2':
            delete list;
            std::cout << "list delete success.\n";
            break;
        case '3':
            list->clear();
            std::cout << "list clear success.\n";
            break;
        case '4':
            std::cout << "list length is: " << list->getLength() << '\n';
            break;
        case '5':
            std::cout << "list is " << (list->isEmpty() ? "empty" : "not empty") << '\n';
            break;
        case '6':
            std::cout << "please input elem position: ";
            std::cin >> position;
            result = list->getElem(position);
            std::cout << "the element in " << position << " is: " << result << '\n';
            break;
        case '7':
            std::cout << "search for element with value of: ";
            std::cin >> value;
            result = list->locateElem(value);
            std::cout << "element with value " << value << "is at: " << result << '\n';
            break;
        case '8':
            int toInsert;
            std::cout << "please input position to insert: ";
            std::cin >> position;
            std::cout << "please input value for element to insert: ";
            std::cin >> toInsert;
            list->insertElem(position, toInsert);
            break;
        case '9':
            std::cout << "please input position of element to delete: ";
            std::cin >> position;
            list->deleteElem(position);
            break;
        case 'a':
            std::cout << "please input element value: ";
            std::cin >> value;
            position = list->locateElem(value);
            list->deleteElem(position);
            break;
        case 'b':
            std::cout << *list;
        default:
            break;
        }
    }
}

//void LinkedListTestFailed() {
//    int choice = -1;
//    FoolLinkedList<int>* list = nullptr;
//    menu();
//    while (std::cin >> choice)
//    {
//        switch (choice) {
//        case 1:
//            if(!list)
//            {
//                std::cout << "顺栈已存在\n";
//                break;
//            }
//            list = new FoolLinkedList<int>();
//            std::cout << "初始化成功\n";
//            break;
//        case 2:
//            delete list;
//            std::cout << "顺序表已删除\n";
//            break;
//        case 3:
//            if (!list)
//            {
//                std::cout << "顺序表不存在，操作失败\n";
//                break;
//            }
//            list = new FoolLinkedList<int>();
//            std::cout << "顺序表已清空\n";
//            break;
//        case 4:
//            if (!list) 
//            {
//                std::cout << "顺序表不存在，操作失败\n";
//                break;
//            }
//            std::cout << "顺序表" << (list->isEmpty() ? "空" : "不空");
//            std::cout << *list;
//            break;
//        case 5:
//            if (!list)
//            {
//                std::cout << "顺序表不存在，操作失败\n";
//                break;
//            }
//            std::cout << "+" << list->getLength() << '\n';
//            std::cout << *list;
//            break;
//        case 6:
//            if (!list)
//            {
//                std::cout << "顺序表不存在，操作失败\n";
//                break;
//            }
//            std::cout<<"请输入元素的值\n";
//            int toPush;
//            std::cin >> toPush;
//            std::cout<<"请输入位置\n";
//            int position;
//            std::cin >> position;
//            list->insertElem(position, toPush);
//            std::cout << *list;
//            break;
//        case 7:
//            if (!list)
//            {
//                std::cout << "顺序表不存在，操作失败\n";
//                break;
//            }
//            int position;
//            std::cout << "请输入位置\n";
//            std::cin >> position;
//            int deleted = list->deleteElem(position);
//            std::cout << "删除元素的值" << deleted << '\n';
//            std::cout << *list;
//            break;
//        case 8:
//            if (!list)
//            {
//                std::cout << "顺序表不存在，操作失败\n";
//                break;
//            }
//            std::cout<<"请输入元素的值\n";
//            int toFind;
//            std::cin >> toFind;
//            int position = list->locateElem(toFind);
//            if(position>-1)
//                std::cout << "该元素位置是" << position << '\n';
//            else
//                std::cout << "找不到该元素\n";
//            std::cout << *list;
//            break;
//        case 9:
//            if (!list)
//            {
//                std::cout << "顺序表不存在，操作失败\n";
//                break;
//            }
//            std::cout << "请输入元素的位置\n";
//            int position;
//                scanf_s("%d", &Position);
//                if (StackGet(S, Position, item)) {
//                    std::cout<<("该%d位置的元素是：%d\n", Position, item);
//                }
//                else {
//                    std::cout<<("找不到该位置\n");
//                }
//                DispStack_Sq(S);
//            }
//            else
//                std::cout<<("顺序表不存在，操作失败\n");
//            break;
//        case 0:
//            std::cout<<("谢谢使用\n");
//            DestoryStack_Sq(S);
//            break;
//
//        default:
//            std::cout<<("Wrong.\n");
//        }
//    }
//}