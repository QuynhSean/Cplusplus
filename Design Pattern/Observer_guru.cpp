#include <iostream>
#include <vector>
using namespace std;
class IOserver
{
private:
    /* data */
public:
    virtual void update(string operation, string record) = 0;
};


class ISubject
{
private:
    /* data */
public:
    virtual void registerObserver(IOserver* o) = 0;
    virtual void removeObserver(IOserver* o) = 0;
    virtual void notifyObservers() = 0
};

class DataBase
{
private:
    vector <IOserver*> mObservers;
    string mOperation;
    string mRecord;
public:
    DataBase(){}
    ~DataBase();
    void registerObserver(IOserver* o){
        mObservers.push_back(o);
    }
    void removeObserver(IOserver* o){
        auto observer = find(mObservers.begin(), mObservers.end(), o);
        if (observer != mObservers.end()) 
        {
            mObservers.erase(observer, observer +1);
        }
        
    }
    void notifyObservers() {
        for (auto& o : mObservers) {
            o->update(mOperation, mRecord);
        }
    }
    void editRecord(string operation, string record){
        mOperation = operation;
        mRecord = record;
        notifyObservers();
    }
};

class Client
{
private:
    /* data */
public:
    Client(/* args */){}
    ~Client();

    void update(string operation, string record){
        cout << "Client " << operation << " operation was performed on " << record << endl;
    }
};

class Developer : public IObserver
{
public:
    Developer() {}
 
    void update(string operation, string record) {
        cout << "Developer: " << operation << " opeation was performed on " << record << endl;
    }
};
 
class Boss : public IOserver
{
public:
    Boss() {}
 
    void update(string operation, string record) {
        cout << "Boss: " << operation << " opeation was performed on " << record << endl;
    }
};
int main()
{    
    DataBase database;
    Developer dev;
    Client client;
    Boss boss;
    database.registerObserver(&dev);
    database.registerObserver(&client);
    database.registerObserver(&boss);
    database.editRecord("delete", "record1");
    // remove boss
    database.removeObserver(&boss);
    database.editRecord("modify", "record2");
    return 0;
}