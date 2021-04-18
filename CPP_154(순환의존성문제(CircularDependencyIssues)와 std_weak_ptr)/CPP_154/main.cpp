// shared 포인터를 사용할때 생길수있는 순환의존성 문제를 알아보고 weak_ptr로 해결하는 방법

#include <iostream>
#include <memory>
#include <string>

class Person
{
    std::string m_name;
    
    // 1.shared로 썻을때 순환의존성 문제 발생!
//    std::shared_ptr<Person> m_parter;
    
    // 2.weak포이터로 해결, 대신 weak포인터는 lock을 호출해줘야 한다!
    std::weak_ptr<Person> m_partner;
    
public:
    Person(const std::string &name) : m_name(name)
    {
        std::cout << m_name << " created\n";
    }
    
    ~Person()
    {
        std::cout << m_name << " destroyed\n";
    }
    
    friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
    {
        if (!p1 || !p2)
        {
            return false;
        }
        
        p1->m_partner = p2;
        p2->m_partner = p1;
        
        std::cout << p1->m_name << " is partnered with " << p2->m_name << "\n";
        
        return true;
    }
    
    const std::shared_ptr<Person> getPartner() const
    {
        return m_partner.lock();
        // lock함수를 호출하면, shared pointer로 리턴해준다, 그것을 가지고 사용하는것!
    }

    const std::string &getName() const
    {
        return m_name;
    }
};

int main()
{
    auto lucy = std::make_shared<Person>("Lucy");
    auto ricky = std::make_shared<Person>("Ricky");
    
    partnerUp(lucy, ricky);
    
    std::cout << lucy->getPartner()->getName() << std::endl;
    
    return 0;
}
