#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int numCourses = 0;
    cout << "****************************************" << endl;
    cout << "*         CGPA CALCULATOR              *" << endl;
    cout << "****************************************" << endl;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    string *courseNames = new string[numCourses];
    double *grades = new double[numCourses];
    int *credits = new int[numCourses];

    double totalPoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; i++)
    {
        cout << "\nCourse " << i + 1 << ":" << endl;
        cin.ignore();
        cout << "  Enter Course Name: ";
        getline(cin, courseNames[i]);
        cout << "  Enter Grade Points: ";
        cin >> grades[i];
        cout << "  Enter Credit Hours: ";
        cin >> credits[i];

        totalPoints += (grades[i] * credits[i]);
        totalCredits += credits[i];
    }

    cout << endl;
    cout << setw(46) << setfill('*') << " "<< endl;
    cout << left << setw(25) << setfill(' ') << "Course Name" << " | " << "Grade" << " | " << "Credits" << endl;
    cout << setfill('-') << setw(45) << "" << setfill(' ') << endl;

    for (int i = 0; i < numCourses; i++)
    {
        cout << left << setw(25) << courseNames[i] << " | " << setw(5) << grades[i] << " | " << credits[i] << endl;
    }

    if (totalCredits > 0)
    {
        double cgpa = totalPoints / totalCredits;
        cout << setfill('*') << setw(45) << "" << endl;
        cout << "Final CGPA: " << fixed << setprecision(2) << cgpa << endl;
        cout << setfill('*') << setw(45) << "" << endl;
    }

    delete[] courseNames;
    delete[] grades;
    delete[] credits;

    return 0;
}