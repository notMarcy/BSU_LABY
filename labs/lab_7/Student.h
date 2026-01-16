#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student{
protected:
    static int idCounter;
    const int id;
    char* name;
    int course;
    int group;
    const int recordBook;
public:
    Student(const char* n, int c, int g, int rb);
    Student(const Student& other);
    virtual ~Student();
    Student() = delete;
    void setName(const char* n);
    void setCourse(int c);
    void setGroup(int g);

    const char* getName() const{
        return name;
    }
    int getCourse() const{
        return course;
    }
    int getGroup() const{
        return group;
    }
    int getId() const{
        return id;
    }
    int getRecordBook() const{
        return recordBook;
    }

    virtual double getAverage() const{
        return 0.0;
    }
    virtual void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

class Session1:public Student{
protected:
    int marks1[4];

public:
    Session1(const char* n, int c, int g, int rb, const int m1[4]);
    Session1(const Session1& other);

    void setMark1(int index, int value);
    int getMark1(int index) const;

    double getAverage() const override;
    void print(std::ostream& os) const override;
};

class Session2:public Session1{
private:
    int marks2[5];

public:
    Session2(const char* n, int c, int g, int rb, const int m1[4], const int m2[5]);
    Session2(const Session2& other);
    void setMark2(int index, int value);
    int getMark2(int index) const;
    double getAverage() const override;
    void print(std::ostream& os) const override;
};

#endif
