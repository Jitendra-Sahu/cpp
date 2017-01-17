#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student
{
    public:
            void set_age(int age);
            void set_standard(int standard);
            void set_first_name(string f_name);
            void set_last_name(string l_name);
    
            int get_age() const;
            int get_standard() const;
            string get_last_name() const;
            string get_first_name() const;
    
            string to_string();
    private:
            int age_;
            int standard_;
            string first_name_;
            string last_name_;
};

void Student::set_age(int age)
{
       this->age_ = age;
}

void Student::set_standard(int standard)
{
       this->standard_ = standard;
}

void Student::set_first_name(string f_name)
{
       this->first_name_ = f_name;
}

void Student::set_last_name(string l_name)
{
       this->last_name_ = l_name;
}

int Student::get_age() const
{
    return age_;
}

int Student::get_standard() const
{
    return standard_;
}

string Student::get_first_name() const
{
    return first_name_;
}

string Student::get_last_name() const
{
    return last_name_;
}

string Student::to_string()
{
    stringstream ss;
    ss<<age_<<","<<first_name_<<","<<last_name_<<","<<standard_; 
    return ss.str();
}

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
