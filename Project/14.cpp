#include <iostream>
#include <vector>
#include <regex>
#include <ctime>
#include <sstream>
using namespace std;

class InvalidFullNameException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid Full Name Exception";
    }
};
class InvalidDoBException : public std::exception
{
public:
    const char* what() const noexcept override {
        return "Invalid Date of Birth Exception";
    }
    
};
class InvalidPhoneBException : public std::exception
{
public:
    const char* what() const noexcept override {
        return "Invalid Phone Exception";
    }
    
};


class Student 
{
protected:
    string fullName;
    string doB;
    string sex;
    string phoneNumber;
    string universityName;
    string gradeLevel;
    
public:
    Student (string fullName_, string doB_, string sex_,
     string phoneNumber_, string universityName_, string gradeLevel_);
    virtual ~Student (){}
    virtual void ShowMyInfor () const = 0;
    string getfullname() const { return fullName;}
    string getphoneNumber() const {return phoneNumber;}
    bool isValidDOBFormat(const std::string& dob) const {
        // Use a regular expression to check if the date has the format dd/MM/YYYY
        std::regex dobRegex(R"(\d{2}/\d{2}/\d{4})");
        if (!std::regex_match(dob, dobRegex)) {
        return false;
    }

    // Parse the date to check if it is a valid date
    std::tm tm = {};
    std::istringstream ss(dob);
    char discard;  // To discard the separator '/'
    ss >> tm.tm_mday >> discard >> tm.tm_mon >> discard >> tm.tm_year;

    // Check if the parsing was successful and the date is valid
    return !ss.fail() && (tm.tm_mday != 0 && tm.tm_mday <= 31 && tm.tm_mon >= 0 && tm.tm_mon <= 11 && tm.tm_year >= 0);


    }
bool isValidPhoneFormat(const std::string phone){
    if (phone.length()!=10)
    {
        return false;
    }
    // Check if the phone number starts with one of the specified prefixes
    std::vector<std::string> validPrefixes = {"090", "098", "091", "031", "035", "038"};
    return std::any_of(validPrefixes.begin(), validPrefixes.end(),
        [&phone](const std::string& prefix) {
            return phone.compare(0, prefix.length(), prefix) == 0;
                });
    
    
}

}; 


Student ::Student (string fullName_, string doB_, string sex_,
     string phoneNumber_, string universityName_, string gradeLevel_){
     try {
        

        if ((fullName_.length() > 50)||(fullName_.length()<10))
        {
            throw InvalidFullNameException();
        }
        
        
        
        if (!isValidDOBFormat(doB_))
        {
            throw InvalidDoBException();
        }

        if(!isValidPhoneFormat(phoneNumber_)){
            throw InvalidPhoneBException();
        }
        fullName = fullName_;
        doB = doB_;
        
        sex = sex_;
        phoneNumber = phoneNumber_;
        universityName = universityName_;
        gradeLevel = gradeLevel_ ;
        } catch (const InvalidFullNameException& e){
            std::cout << e.what() << std::endl;
        }
        catch(const InvalidDoBException& e ){
            std::cout << e.what() << std::endl;
        }
        catch (const InvalidPhoneBException& e){
            std::cout << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Input files have unknown errors !!!" << std::endl;
        }
     
     }



class GoodStudent : public Student
{
private:
    double gpa;
    string bestRewardName;
public:
    GoodStudent(string fullName_, string doB_, string sex_,
     string phoneNumber_, string universityName_, string gradeLevel_, double gpa_, string bestRewardName_):Student( fullName_,  doB_,  sex_,
      phoneNumber_,  universityName_,  gradeLevel_), gpa{gpa_}, bestRewardName{bestRewardName_}{}
    ~GoodStudent(){}
    void ShowMyInfor() const override {
        std::cout << fullName << " " << doB << " " <<sex <<" " << phoneNumber << " " << universityName << " " << gradeLevel << " " << gpa << bestRewardName << endl;
    }
    double getgpa(){ return gpa;}

};
class NormalStudent : public Student
{
private:
    double englishScore;
    double entryTestScore;
public:
    NormalStudent(string fullName_, string doB_, string sex_,
    string phoneNumber_, string universityName_, string gradeLevel_, double englishScore_, double entryTestScore_ )
        : Student(fullName_, doB_, sex_, phoneNumber_, universityName_, gradeLevel_), englishScore{englishScore_}, 
            entryTestScore{entryTestScore_}{}
    ~NormalStudent(){}
    void ShowMyInfor( ) const override{
        cout << fullName << " " << doB << " " <<sex <<" " << phoneNumber << " " << universityName << " " << gradeLevel << englishScore << endl;

    }
    double getEnglishScore(){ return englishScore;}
    double getEntryTestScore(){ return entryTestScore;}
};
bool sortbygpa( GoodStudent& a,  GoodStudent& b){
    if (a.getgpa() != b.getgpa() )
    {
        return a.getgpa() > b.getgpa();
    }
    else if(a.getgpa() == b.getgpa()) {return a.getfullname() < b.getfullname();}
    else 
        {return false;}
    
    
}
bool sortbyentrycore(NormalStudent& a, NormalStudent& b){
    if (a.getEntryTestScore() != b.getEntryTestScore())
    {
        return a.getEntryTestScore() > b.getEntryTestScore();
    }
    else if (a.getEntryTestScore() == b.getEntryTestScore())
    {
        if (a.getEnglishScore() != b.getEnglishScore())
        {
            return a.getEnglishScore() > b.getEnglishScore();
        }
        else {
            return a.getfullname() < b.getfullname();
        }
        
    }
    else return false;
    
    
}
// bool sortbyname( Student& a,const Student& b){
//     return a.getfullname() > b.getfullname();
// }
// bool sortbyphonenumber( Student& a, Student& b){
//     return a.getphoneNumber() < b.getphoneNumber();
// }
vector <Student*> selectStudent(vector <NormalStudent>& nomalstudent, vector <GoodStudent>& goodstudent, int recuit){
    // vector <Student> select;
    // if (goodstudent.size() > recuit)
    // {
    //     sort(goodstudent.begin(), goodstudent.end(), sortbygpa);
    //     select.insert(select.end(), goodstudent.begin(), goodstudent.begin() + recuit);
    // }
    // else{
    //     select.insert(select.begin(), goodstudent.begin(), goodstudent.end());
    //     recuit -= goodstudent.size();
    //     sort(nomalstudent.begin(), nomalstudent.end(), sortbyentrycore);
    //     select.insert(select.end(), nomalstudent.begin(), nomalstudent.begin() + recuit);
    // }
    // return select;
    vector<Student*> selected;
    if (goodstudent.size() > recuit) {
        sort(goodstudent.begin(), goodstudent.end(), sortbygpa);
        for (int i = 0; i < recuit; ++i) {
            selected.push_back(&goodstudent[i]);
        }
    } else {
        for (auto& student : goodstudent) {
            selected.push_back(&student);
        }
        recuit -= goodstudent.size();
        sort(nomalstudent.begin(), nomalstudent.end(), sortbyentrycore);
        for (int i = 0; i < recuit; ++i) {
            selected.push_back(&nomalstudent[i]);
        }
    }
    return selected;

}

int main(){
    std::vector<GoodStudent> allGoodStudent = {
        {"dinh thi quynh", "23/11/2001", "female","0909161350", "hust", "good", 3.07, "good student"},
        {"jeni nguyen", "24/11/2001", "male","0909341350", "hust", "good", 3.39, "good student"}
    };
    std::vector<NormalStudent> allNormalStudent = {
        {"nguyen van a", "23/11/2001", "female","0909161350", "hust", "normal", 450, 9},
        {"nguyen van b", "24/11/2001", "male","0909341350", "hust", "normal", 990, 7.5}
    };
    vector<Student*> selectedStudents = selectStudent(allNormalStudent, allGoodStudent, 4);
    
    cout << "Danh sach sinh vien duoc chon:" << endl;
    for (const auto& student : selectedStudents) {
        student->ShowMyInfor();
    }
    
    return 0;
        
    
    
}