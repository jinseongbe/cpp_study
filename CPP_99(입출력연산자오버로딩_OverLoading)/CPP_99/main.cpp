#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
    double m_x, m_y, m_z;
    
public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0)
    : m_x(x), m_y(y), m_z(z)
    {}
    
    double getX() { return m_x; }
    double getY() { return m_y; }
    double getZ() { return m_z; }
    
    void print()
    {
        cout << m_x << "\t" << m_y << "\t" << m_z << endl;
    }
    
    friend std::ostream &operator << (std::ostream &out, const Point &point)    // MemberFunction이 아닌 Friend로 사용하는 이유
    {                                                                           // => 첫번째 파라미터가 Point의 것이 아닌 std::ostream것이기 때문, 즉 첫번쨰 파라미터가 Class자신의 것이여야함!
        out << "( " << point.m_x << "\t" << point.m_y << "\t" << point.m_z << " )";
        
        return out;
    }
    
    friend std::istream &operator >> (std::istream &in, Point &point)    // input이니까 const 쓰면 안되죠~
    {
        in >> point.m_x >> point.m_y >> point.m_z;

        return in;
    }
};


int main()
{
    Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);
    
    p1.print();
    p2.print();
    cout << endl;
    
    // 연산자 오버로딩
    cout << p1 << endl << p2 << endl;
    
    // file로 출력
    ofstream of("out.txt");
    of << p1 << endl << p2 << endl;
    
    of.close(); // 알아서 닫고 나가지만 그래도 해주면 성실한 프로그래머!
    
    Point P1, P2;
    cin >> P1 >> P2;
    cout << P1 << endl << P2;
    
    
    return 0;
}
