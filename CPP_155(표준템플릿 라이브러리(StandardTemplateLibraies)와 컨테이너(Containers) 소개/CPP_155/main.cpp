#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void sequence_containers()
{
    // vector
    {
        cout << "vector" << endl;
        vector<int> vec;    // #include <vector>
        for (int i = 0; i < 10; ++i)
            vec.push_back(i);
        
        for (auto & e : vec)
            cout << e << " ";
        cout << endl;
    }   // vector에는 push front가 없다!
    
    // deque
    {
        cout << "deque" << endl;
        deque<int> deq;     // #include <deque>
        for (int i = 0; i < 10; ++i)
        {
            deq.push_back(i);
            deq.push_front(i);
        }
        
        for (auto & e : deq)
            cout << e << " ";
        cout << endl;
    }
}

void associative_containers()
{
    // set : 특징 - 중복이 허용되지 않는다!
    {
        cout << "set" << endl;
        set<string> str_set;
        
        str_set.insert("Hello");
        str_set.insert("World");
        str_set.insert("Hello");
        
        cout << str_set.size() << endl;
        
        for (auto & e : str_set)
            cout << e << " ";
        cout << endl;
    }
    cout << endl;
    
    // multiset : duplication is allowed
    {
        cout << "multiset" << endl;
        
        std::multiset<string> str_set;
        
        str_set.insert("Hello");
        str_set.insert("World");
        str_set.insert("Hello");
        
        cout << str_set.size() << endl;
        
        for (auto & e : str_set)
            cout << e << " ";
        cout << endl;
    }
    cout << endl;
    
    // map : key/value
    {
        cout << "map" << endl;
        std::map<char, int> map;
        map['c'] = 50;      // c가 먼져 있더라도 저렬된 순서로 출력됨!
        map['a'] = 10;
        map['b'] = 20;
        
        
        cout << map['a'] << endl;
        
        map['a'] = 100;
        
        cout << map['a'] << endl;
        
        for (auto & e : map)
            cout << e.first << " " << e.second << " ";
        cout << endl;
    }
    cout << endl;
    
    // multimap : dupicated keys
    {
        cout << "multimap" << endl;
        
        std::multimap<char, int> map;
        map.insert(std::pair('a', 10));     // before c++ 14, pairchar, int>('a', 10)
        map.insert(std::pair('b', 10));
        map.insert(std::pair('c', 10));
        map.insert(std::pair('a', 100));
        
        cout << map.count('a') << endl;
        
        for (auto & e : map)
            cout << e.first << " " << e.second << " ";
        cout << endl;
    }
}

void container_adapters()
{
    // stack
    {
        cout << "stack" << endl;
        
        std::stack<int> stack;
        stack.push(1);          // push adds a copy
        stack.emplace(2);       // emplace constructs a new object
        stack.emplace(3);
        cout << stack.top() << endl;
        stack.pop();
        cout << stack.top() << endl;
    }
    cout << endl;
    
    // queue
    {
        cout << "queue" << endl;
        
        std::queue<int> queue;
        queue.push(1);
        queue.push(2);
        queue.push(3);
        cout << queue.front() << " " << queue.back() << endl;
        queue.pop();
        cout << queue.front() << " " << queue.back() << endl;
    }
    cout << endl;
    
    // Priority queue : sorting 기능이 있음  // 만일 사용자 지정 class가 들어갈 경우에는 크기를 비교해주는 연산자를 오버로딩해줘야함!
    {
        cout << "priority queue" << endl;
        
        std::priority_queue<int> queue;
        
        for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
            queue.push(n);
        
        for (int i = 0; i < 10; ++i)
        {
            cout << queue.top() << endl;
            queue.pop();
        }
    }
}


int main()
{
    sequence_containers();
    cout << endl;
    
    associative_containers();
    cout << endl;
    
    container_adapters();
    
    return 0;
}
