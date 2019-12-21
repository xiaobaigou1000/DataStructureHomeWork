#include"foolbinarytree.h"

#include<iostream>
#include<iomanip>
void menu()
{
    std::cout << "\n\n";
    std::cout << "binary tree example program.\n\n";
    std::cout << "    1---create binary tree\n";
    std::cout << "    2---preorder traverse\n";
    std::cout << "    3---in-order traverse\n";
    std::cout << "    4---post order traverse\n";
    std::cout << "    5---count leafs\n";
    std::cout << "    6---count nodes\n";
    std::cout << "    7---caculate depth of binary tree\n";
    std::cout << "    8---exchange children of binary tree\n";
}

struct Student
{
    long id;
    std::string name;
    Student()
    {
        id = -1;
        name = "";
    }

    Student(long id,const std::string& name)
        :id(id), name(name)
    {
    }

    bool operator==(const Student& stu)
    {
        if (id == stu.id)
            return true;
        return false;
    }

    friend std::istream& operator>>(std::istream& in, Student& toInput)
    {
        std::cout << "please input student id: ";
        in >> toInput.id;
        std::cout << "please input student name: ";
        in >> toInput.name;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student& toPrint)
    {
        out << std::setw(12) << toPrint.id << std::setw(12) << toPrint.name;
        return out;
    }
};

int main()
{
    int choice = -1;
    FoolBinaryTree<Student>* binTree = nullptr;
    menu();
    while (std::cin >> choice)
    {
        switch (choice)
        {
        case 1:
            binTree = new FoolBinaryTree<Student>();
            binTree->createBinaryTreeByPreOrder([]() {
                Student temp;
                std::cin >> temp;
                return temp;
                });
            break;
        case 2:
            binTree->preOrderTraverse([](const Student& stu) {
                std::cout << stu << '\n';
                });
            break;
        case 3:
            binTree->inOrderTraverse([](const Student& stu) {
                std::cout << stu << '\n';
                });
            break;
        case 4:
            binTree->postOrderTraverse([](const Student& stu) {
                std::cout << stu << '\n';
                });
            break;
        case 5:
            std::cout << "There are " << binTree->leafCount() << " leafs in current binary tree.\n";
            break;
        case 6:
            std::cout << "There are " << binTree->nodeCount() << " nodes in current binary tree.\n";
            break;
        case 7:
            std::cout << "The binary tree max depth is: " << binTree->caculateDepth();
            break;
        case 8:
            binTree->exchangeChildren();
            std::cout << "exchange binary tree children success.\n";
            break;
        default:
            break;
        }
    }

    return 0;
}