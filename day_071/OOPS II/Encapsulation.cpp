// here we discuss encapsulation in C++

//definition of encapsulation
// Encapsulation is a fundamental principle of object-oriented programming that restricts direct access to an object's data and methods, allowing interaction only through well-defined interfaces. This promotes data hiding, enhances security, and improves code maintainability by preventing unintended interference with an object's internal state.

#include <iostream> 
#include <string>
using namespace std;


class Student{
private:
    string name;
    int age;
    int rollNo;
public:
    // Constructor to initialize the student object
    Student(string name ,int age, int rollNo) {
        // Using 'this' pointer to refer to the current object's members
        // 'this' pointer is used to avoid ambiguity between member variables and parameters
        this->name = name;
        this->age = age;
        this->rollNo = rollNo;

        cout << "Student object created with name: " << this->name << ", age: " << this->age << ", roll number: " << this->rollNo << endl;
    }

    // Getter for name
    string getName() const {
        return name;
    }
    // Getter for age
    int getAge() const {
        return age;
    }
    // Getter for roll number
    int getRollNo() const {
        return rollNo;
    }

    // Method to display student information
    void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << ", Roll No: " << rollNo << endl;
    }

     // setter for name
    void setName(const string& newName) {
        name = newName;
    }
    // setter for age
    void setAge(int newAge) {
        if (newAge > 0) { // Basic validation to ensure age is positive
            age = newAge;
        } else {
            cout << "Invalid age. Age must be positive." << endl;
        }
    }

    // setter for roll number
    void setRollNo(int newRollNo) {
        if (newRollNo > 0) { // Basic validation to ensure roll number is positive
            rollNo = newRollNo;
        } else {
            cout << "Invalid roll number. Roll number must be positive." << endl;
        }
    }
    // Destructor to clean up resources if needed
    ~Student() {
        cout << "Student object with name: " << name << " is being destroyed." << endl;
    }
};

int main(){
    // Creating a Student object
    Student student1("Alice", 20, 101);
    
    // Displaying student information
    student1.displayInfo();

    // Accessing student information using getters
    cout << "Name: " << student1.getName() << endl;
    cout << "Age: " << student1.getAge() << endl;
    cout << "Roll No: " << student1.getRollNo() << endl;

    // Modifying student information using setters
    student1.setName("Bob");
    student1.setAge(21);
    student1.setRollNo(102);

    // Displaying updated student information
    student1.displayInfo();


    // dynamically creating a Student object
    Student* student2 = new Student("Charlie", 22, 103);
    // Displaying student information
    student2->displayInfo();

    // Accessing student information using getters
    cout << "Name: " << student2->getName() << endl;
    cout << "Age: " << student2->getAge() << endl;
    cout << "Roll No: " << student2->getRollNo() << endl;
    // Modifying student information using setters
    student2->setName("David");
    student2->setAge(23);
    student2->setRollNo(104);

    // Displaying updated student information
    student2->displayInfo();
    // Deleting the dynamically created object to free memory
    delete student2;

    return 0;

}