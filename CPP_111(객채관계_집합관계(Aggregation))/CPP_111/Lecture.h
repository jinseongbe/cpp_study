#pragma once

#include <vector>
#include "Student.h"
#include "Teacher.h"

class Lecture
{
private:
    std::string m_name;
    
//    Teacher teacher;
//    std::vector<Student> students;
    
    Teacher *teacher;
    std::vector<Student*> students;
    
public:
    Lecture(const std::string & name_in)
    : m_name(name_in)
    {}
    
    ~Lecture()
    {
        // do NOT delete teacher
        // do NOT delete students
    }
    
//    void assignTeacher(const Teacher & teacher_input)
//    {
//        teacher = teacher_input;
//    }
    
    
    void assignTeacher(Teacher * const teacher_input)
    {
        teacher = teacher_input;
    }
    
    
//    void registerStudent(const Student & student_input)
//    {
//        students.push_back(student_input);
//
//        // &student_input != &students[0]
//    }
     
    
    void registerStudent(Student * const student_input)
    {
        students.push_back(student_input);
    }
    
    
    void study()
    {
        std::cout << m_name << " Study " << std::endl << std::endl;
        
//        for (auto & element : students) // Note : ' auto element' doesn't work
//            element.setIntel(element.getIntel() + 1);
        
        
        for (auto element : students)
            (*element).setIntel((*element).getIntel() + 1);
        
        /* 위에 있는 것과 동일하게 작동함
        for (auto & element : students)   // Note : ' auto element' works
            element->setIntel(element->getIntel() + 1);
        */

    }
    
    friend std::ostream & operator << (std::ostream & out, const Lecture & lecture)
    {
        out << "Lecture name : " << lecture.m_name << std::endl;
        
//        out << lecture.teacher << std::endl;
//        for (auto element : lecture.students)
//            out << element << std::endl;  // 포인터 주소 자체를 출력하기 때문임!
                
        out << *lecture.teacher << std::endl;
        for (auto element : lecture.students)
            out << *element << std::endl;

        return out;
    }
};
