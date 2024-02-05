#include <iostream>
#include <vector>

using namespace std;

class Student 
{
private:
    string fullName;
    string doB;
    string sex;
    int phoneNumber;
    string universityName;
    string gradeLevel;
public:
    Student (string fullName_, string doB_, string sex_,
     int phoneNumber_, string universityName_, string gradeLevel_);
    virtual ~Student (){}
};

Student ::Student (string fullName_, string doB_, string sex_,
     int phoneNumber_, string universityName_, string gradeLevel_) :
     fullName{fullName_}, doB{doB_}, sex{sex_}, phoneNumber{phoneNumber_},
     universityName{universityName_}, gradeLevel{gradeLevel_} {}



class GoodStudent : public Student
{
private:
    double gpa;
    string bestRewardName;
public:
    GoodStudent();
    ~GoodStudent();
};

GoodStudent::GoodStudent(/* args */)
{
}

GoodStudent::~GoodStudent()
{
}
int main(){
    
}