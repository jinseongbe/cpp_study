#include <iostream>
#include <vector>

using namespace std;
void printStack(const vector<int> &stack);

int main()
{
    // vector에 대하여
    // vector : size, capacity가 있음
    // size - capacity에서 가지고 있는 것 중 사용할 개수
    // capacity - 메모리를 가지고 있는 개수
    // vector을 잘 쓰는 법 - 내부에서 이루어지는 new와 delete가 적게 사용되도록 만드는 것
    
    // 아래는 내부적으로 이와 비슷하게 실행되는 것임
    // int *v_ptr = new int[3]{ 1, 2, 3 } 똑같지는 않음!
    vector<int> v{ 1, 2, 3 };
    v.reserve(1024);        // 미리 메모리를 만들어놔서 new를 하는 시간은 단축 시키기 위한 것임!
    for(auto &e : v)
        cout << e << " ";
    cout << endl;
    
    cout << v.size() << endl;
    
    
    v.resize(10);
    for(auto &e : v)
        cout << e << " ";
    cout << endl;
    
    cout << v.size() << " " << v.capacity() << endl;


    v.resize(2);            // vector를 설계할때, 사이즈를 줄여서 delete(또는 new)를 하려면 시간이 더 걸리기 때문에
    for(auto &e : v)        // 그냥 없에지 않고 사이즈를 줄인만큼(2)만 사용 되도록 만들어 버리는 것임!
        cout << e << " ";
    cout << endl;
    
    cout << v.size() << " " << v.capacity() << endl;

    
    cout << v[2] << endl;
//    cout << v.at(2) << endl;
    
    int *ptr = v.data();
    cout << ptr[2] << endl;
    cout << endl;
    
    
    // stack 처럼 사용하는 방법
    cout << "like stack" << endl;
    vector<int> stack;
    // stack.reserve(1024); // 이렇게 미리 해두면 프로그램이 빨리짐!
    stack.push_back(3);
    printStack(stack);
    stack.push_back(5);
    printStack(stack);
    stack.push_back(7);
    printStack(stack);
    stack.pop_back();       // size만 줄이고 키우는 것이기 때문에 new,delete연산 속도가 필요 없어 효율적임!
    printStack(stack);      // 다만 처음에 reserve를 할때 용량을 너무 크게 잡으면 메모리 낭비가 심할 수 있음!
    stack.pop_back();
    printStack(stack);
    stack.pop_back();
    printStack(stack);
    
    
    return 0;
}

void printStack(const vector<int> &stack)
{
    for(auto &e : stack)
        cout << e << " ";
    cout << endl;
}
