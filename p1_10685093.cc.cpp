#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Student{
public:
    string FirstName;
    string LastName;
    string StudentNumber;
    double Grade;
};

class Course{
public:
    string Name;
    string creditHours;
    string CourseNumber;
    Student registeredStudents[100];

    void AddCourses(string CourseName, string CreditHours, string CourseNumber){
        this->Name = CourseName;
        this->creditHours = CreditHours;
        this->CourseNumber = CourseNumber;
    }

    void EditCourse(string CourseName, string CreditHours, string CourseNumber){
        this->Name = CourseName;
        this->creditHours = CreditHours;
        this->CourseNumber = CourseNumber;
    }

    void AddStudentToCourse(Student obj){
        registeredStudents[indexOfStudent]=obj;
        cout << "Enter Course Grade: ";
        cin >> registeredStudents[indexOfStudent].Grade;
        indexOfStudent++;
        cout << "Student Added To Course" << endl;
    }

    void PrintStudentGrade(string studentNumber){
        int index =0; bool isFound=false;
      for (int i=0; i<=indexOfStudent; i++){
            if (studentNumber == registeredStudents[i].StudentNumber){
                index=i;
                isFound=true;
                break;
            }
            else{

                isFound=false;
            }
        }
        if (isFound == true){
            cout << this->Name << ": " << registeredStudents[index].Grade <<endl;
        }
    }
private:
    int indexOfStudent=0;
};

class Staff{
    public:
    string FirstName;
    string LastName;
    string CourseName;
    string StaffNumber;
};

class ArrayInfo{
public:
    int studentArrayIndex=0;
    int courseArrayIndex=0;
    int staffArrayIndex=0;
};

int main()
{
    Course courses[100]; Student students[100]; Staff staffs[100];
    ArrayInfo IndexInfo;
    string userInput;
    string selectOperator;

    do{
        //system("cls");
        cout << "Enter course to select Course, student to select Student, staff \nto select Staff or exit to Exit System, print to Print Records: ";
        cin >> selectOperator;
         if (selectOperator == "course"){
            cout << "Select An Operation:" <<endl;
            cout << "Enter add to Add Course | edit to Edit Course | delete to Delete Course | assign to Student to a course"<<endl;
            cin >> userInput;

            if (userInput == "add"){
                cout << "\nYou have chosen to add to a new Course" << endl;
                cout << "Enter Course Name: ";
                cin >> courses[IndexInfo.courseArrayIndex].Name;
                cout << "Enter Course Number: ";
                cin >> courses[IndexInfo.courseArrayIndex].CourseNumber;
                cout << "Enter Credit Hours of Course: ";
                cin >> courses[IndexInfo.courseArrayIndex].creditHours;
                cout << "Course Added!" << endl;
                IndexInfo.courseArrayIndex++;
            }

            else if (userInput == "edit"){
                string courseName; int index; bool isFound=false;
                cout << "\nYou have chosen to edit to a Course" << endl;
                cout << "Enter Course Name: ";
                cin >> courseName;
                for (int i=0; i<=IndexInfo.courseArrayIndex; i++){
                    if (courseName == courses[i].Name){
                        index=i;
                        isFound=true;
                        break;
                    }
                    else{
                        isFound=false;
                    }
                }
                if (isFound = true){
                    cout << "Course Found" << endl;
                    cout << "Enter New Course Name: ";
                    cin >> courses[index].Name;
                    cout << "Enter New Course Number: ";
                    cin >> courses[index].CourseNumber;
                    cout << "Enter New Credit Hours of Course: ";
                    cin >> courses[index].creditHours;
                    cout << "Course has been successfully edited!" << endl;
                }
                else{
                    cout << "Course Not Found" <<endl;
                }
            }
            else if (userInput == "delete"){
                string courseName; int index=0; bool isFound=false;
                cout << "Enter Course Name: ";
                cin >> courseName;

                 for (int i=0; i<=IndexInfo.courseArrayIndex; i++){
                   if (courseName == courses[i].Name){
                        index = i;
                        isFound = true;
                        break;
                   }
                   else{
                        isFound = false;
                   }
                }

                if (isFound == true){
                     for (int i=index; i<=IndexInfo.courseArrayIndex; i++){
                        if (!((i++) > IndexInfo.courseArrayIndex)){
                            courses[i] = courses[i++];
                        }
                    }
                    IndexInfo.courseArrayIndex--;
                }
                else{

                }
            }

            else if (userInput == "list"){
                for (int i=0; i<=IndexInfo.courseArrayIndex; i++){
                   cout << courses[i].Name << endl;
                }
            }

            else if (userInput == "assign"){
                string studentNumber; bool isFound=false; int index=0;
                cout << "Enter Student's Student Number: ";
                cin >> studentNumber;

                for (int i=0; i<=IndexInfo.studentArrayIndex; i++){
                    if (students[i].StudentNumber == studentNumber){
                        index=i;
                        isFound=true;
                        break;
                    }
                    else{
                        isFound=false;
                    }
                }

                if (isFound == true){
                    string courseName;
                    cout << "Student Found" << endl;
                    cout << "Enter Course Name To Be Assigned To: ";
                    cin >> courseName;

                    for (int i=0; i<=IndexInfo.courseArrayIndex; i++){
                        if (courses[i].Name == courseName){
                            cout << "Course Found" << endl;
                            courses[i].AddStudentToCourse(students[index]);
                            isFound=true;
                        }
                        else{
                            isFound=false;
                        }
                    }
                }
                else{

                }
            }
         }
         else if (selectOperator == "student"){
            cout << "Select An Operation:" <<endl;
            cout << "Enter add to Add Student|edit to Edit Student|delete to Delete Student"<<endl;
            cin >> userInput;

            if (userInput == "add"){
                cout << "\nYou have chosen to add to a new Student" << endl;
                cout << "Enter Student First Name: ";
                cin >> students[IndexInfo.studentArrayIndex].FirstName;
                cout << "Enter Student Last Name: ";
                cin >> students[IndexInfo.studentArrayIndex].LastName;
                cout << "Enter Student's Student Number: ";
                cin >> students[IndexInfo.studentArrayIndex].StudentNumber;
                cout << "Student Added!" << endl;
                IndexInfo.studentArrayIndex++;
            }

            else if (userInput == "edit"){
                string studentNumber; int index; bool isFound=false;
                cout << "\nYou have chosen to edit to a Student" << endl;
                cout << "Enter Student's Student Number: ";
                cin >> studentNumber;
                for (int i=0; i<=IndexInfo.studentArrayIndex; i++){
                    if (studentNumber == students[i].StudentNumber){
                        index=i;
                        isFound=true;
                        break;
                    }
                    else{
                        isFound=false;
                    }
                }
                if (isFound = true){
                    cout << "Student Found" << endl;
                    cout << "Enter Student First Name: ";
                    cin >> students[index].FirstName;
                    cout << "Enter Student Last Name: ";
                    cin >> students[index].LastName;
                    cout << "Enter Student's Student Number: ";
                    cin >> students[index].StudentNumber;
                    cout << "Student's Details has been successfully edited!" << endl;
                }
                else{
                    cout << "Course Not Found" <<endl;
                }
            }
            else if (userInput == "delete"){
                string studentNumber; int index=0; bool isFound=false;
                cout << "Enter Student's Student Number: ";
                cin >> studentNumber;

                 for (int i=0; i<=IndexInfo.studentArrayIndex; i++){
                   if (studentNumber == students[i].StudentNumber){
                        index = i;
                        isFound = true;
                        break;
                   }
                   else{
                        isFound = false;
                   }
                }

                if (isFound == true){
                     for (int i=index; i<=IndexInfo.studentArrayIndex; i++){
                        if (!((i++) > IndexInfo.studentArrayIndex)){
                            students[i] = students[i++];
                        }
                    }
                    IndexInfo.studentArrayIndex--;
                }
                else{

                }
            }

            else if (userInput == "list"){
                for (int i=0; i<=IndexInfo.courseArrayIndex; i++){
                   cout << courses[i].Name << endl;
                }
            }

         }
         else if (selectOperator == "staff"){
            cout << "Select An Operation:" <<endl;
            cout << "Enter add to Add Staff | edit to Edit Staff | delete to Delete Staff"<<endl;
            cin >> userInput;

            if (userInput == "add"){
                cout << "\nYou have chosen to add to a new Staff" << endl;
                cout << "Enter Staff's First Name: ";
                cin >> staffs[IndexInfo.staffArrayIndex].FirstName;
                cout << "Enter Staff's Last Name: ";
                cin >> staffs[IndexInfo.staffArrayIndex].LastName;
                cout << "Enter Staff's Staff Number: ";
                cin >> staffs[IndexInfo.staffArrayIndex].StaffNumber;
                cout << "Enter Staff's Course Name: ";
                cin >> staffs[IndexInfo.staffArrayIndex].CourseName;
                cout << "Staff Added to List!" << endl;
                IndexInfo.staffArrayIndex++;
            }

            else if (userInput == "edit"){
                string staffNumber; int index; bool isFound=false;
                cout << "\nYou have chosen to edit to a Staff" << endl;
                cout << "Enter Staff's Staff Number: ";
                cin >> staffNumber;
                for (int i=0; i<=IndexInfo.staffArrayIndex; i++){
                    if (staffNumber == staffs[i].StaffNumber){
                        index=i;
                        isFound=true;
                        break;
                    }
                    else{
                        isFound=false;
                    }
                }
                if (isFound = true){
                    cout << "Staff Found" << endl;
                    cout << "Enter Staff's First Name (New): ";
                    cin >> staffs[index].FirstName;
                    cout << "Enter Staff's Last Name: ";
                    cin >> staffs[index].LastName;
                    cout << "Enter Staff's Staff Number: ";
                    cin >> staffs[index].StaffNumber;
                    cout << "Staff's Details has been successfully edited!" << endl;
                }
                else{
                    cout << "Staff Not Found" <<endl;
                }
            }
            else if (userInput == "delete"){
                string staffNumber; int index=0; bool isFound=false;
                cout << "Enter Staff's Staff Number: ";
                cin >> staffNumber;

                 for (int i=0; i<=IndexInfo.staffArrayIndex; i++){
                   if (staffNumber == staffs[i].StaffNumber){
                        index = i;
                        isFound = true;
                        break;
                   }
                   else{
                        isFound = false;
                   }
                }

                if (isFound == true){
                     for (int i=index; i<=IndexInfo.staffArrayIndex; i++){
                        if (!((i++) > IndexInfo.staffArrayIndex)){
                            staffs[i] = staffs[i++];
                        }
                    }
                    IndexInfo.staffArrayIndex--;
                }
                else{

                }
            }

            else if (userInput == "list"){
                for (int i=0; i<=IndexInfo.staffArrayIndex; i++){
                   cout << staffs[i].FirstName << " " <<staffs[i].LastName << endl;
                }
            }
         }
         else if (selectOperator == "print"){
             string studentNumber; int index; bool isFound=false;
                cout << "\nYou have chosen to print Student's Results" << endl;
                cout << "Enter Student's Student Number: ";
                cin >> studentNumber;
                for (int i=0; i<=IndexInfo.studentArrayIndex; i++){
                    if (studentNumber == students[i].StudentNumber){
                        index=i;
                        isFound=true;
                        break;
                    }
                    else{
                        isFound=false;
                    }
                }
                if (isFound == true){
                    cout << "Student Found" << endl;
                    cout << "Student's Results" << endl;
                    cout << "Full Name: " << students[index].FirstName << " "
                    << students[index].LastName << endl;
                    cout << "Course List" << endl;
                    for (int i=0; i<=IndexInfo.courseArrayIndex; i++){
                        courses[i].PrintStudentGrade(studentNumber);
                    }
                }
                else{
                    cout << "Student Not Found" << endl;
                }
         }
         else if (selectOperator == "exit"){
            cout << "System Exited"<< endl;
            return 0;
         }
         else{
            cout << "Invalid Operator"<< endl;
         }

}while (true);

    return 0;
}
