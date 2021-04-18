#pragma once

#include <string>
#include "Position2D.h"

class Monster
{
private:
    std::string m_name;
    Position2D m_location;      // compositon 관계: Monster가 Position2D를 사용하는것, 이때 Monster가 메모리에서 사라지면
//    int m_x;    // location                      Position 또한 사라진다!
//    int m_y;
    
public:
    Monster(const std::string name_in, const Position2D &pos_in)
//    : m_name(name_in), m_x(x_in), m_y(y_in)
    : m_name(name_in), m_location(pos_in)
    {}
    
    void moveTo(const Position2D &pos_target)
    {
        m_location.set(pos_target);
//        m_x = x_target;
//        m_y = y_target;
    }
    
    friend std::ostream &operator << (std::ostream &out, const Monster & monster)
    {
        out << monster.m_name << " " << monster.m_location;
        return out;
    }
};
