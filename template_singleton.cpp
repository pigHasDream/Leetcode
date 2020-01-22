#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

// singleton old school class
class SingletonOldSchoolCL {
  public:
    static SingletonOldSchoolCL* getInstance() {
      if(instance_ == nullptr)
        instance_ = new SingletonOldSchoolCL();
    
      return instance_;
    }

    SingletonOldSchoolCL& operator=(const SingletonOldSchoolCL& other) = delete;
    SingletonOldSchoolCL(const SingletonOldSchoolCL& other) = delete;

    void printName() {
      cout << name_ << endl;
    }

    ~SingletonOldSchoolCL() {
      if(instance_) 
        delete instance_;
      instance_ = nullptr;
    }

  private:
    SingletonOldSchoolCL() {
      name_ = "My name is SingletonOldSchoolCL";
      cout << "Now creating an instance of SingletonOldSchoolCL" << endl;
    };

    // must be static member as it's get from another static member function!
    static SingletonOldSchoolCL* instance_;
    string name_;
};

// static member must be initialized outside the class
SingletonOldSchoolCL* SingletonOldSchoolCL::instance_ = nullptr;

// singleton class
class SingletonCL {
  public:
    static SingletonCL& getInstance() {
      static SingletonCL instance_;
    
      return instance_;
    }

    SingletonCL& operator=(const SingletonCL& other) = delete;
    SingletonCL(const SingletonCL& other) = delete;

    void printName() {
      cout << name_ << endl;
    }

  private:
    SingletonCL() {
      name_ = "My name is SingletonCL";
      cout << "Now creating an instance of SingletonCL" << endl;
    };

    string name_;
};


int main() {

  SingletonCL::getInstance().printName();
  SingletonCL::getInstance().printName();
  SingletonCL::getInstance().printName();

  SingletonOldSchoolCL::getInstance()->printName();
  SingletonOldSchoolCL::getInstance()->printName();
  SingletonOldSchoolCL::getInstance()->printName();

  return 0;
}
