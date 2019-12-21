#include"foolstack.h"
#include<iostream>

void menu()
{
    std::cout << "\n\n";
    std::cout << "linked stack example program.\n\n";
    std::cout << "    1---initialize linked stack\n";
    std::cout << "    2---destroy stack\n";
    std::cout << "    3---clear stack\n";
    std::cout << "    4---check if stack is empty\n";
    std::cout << "    5---push a value to stack\n";
    std::cout << "    6---pop a value from stack\n";
    std::cout << "    7---get the top value of stack\n";
}

int main()
{
    int choice;
    FoolStack<int>* stack = nullptr;

    int result;
    int position;
    int value;
    menu();
    while (std::cin >> choice)
    {
        switch (choice)
        {
        case 1:
            stack = new FoolStack<int>();
            std::cout << "stack initialize success.\n";
            break;
        case 2:
            delete stack;
            std::cout << "stack destroy success.\n";
            break;
        case 3:
            stack->clear();
            std::cout << "stack clear success.\n";
            break;
        case 4:
            std::cout << "stack is " << (stack->empty() ? "empty" : "not empty") << '\n';
            break;
        case 5:
            int toPush;
            std::cout << "please input a value to push: ";
            std::cin >> toPush;
            stack->push(toPush);
            break;
        case 6:
            result = stack->pop();
            std::cout << result << " is poped from the stack.\n";
            break;
        case 7:
            result = stack->top();
            std::cout << "the top element of stack is: " << result << '\n';
            break;
        default:
            break;
        }
    }
    return 0;
}