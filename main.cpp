#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Subject
{
    public:
        string title;
        int units;
        double grade;
};

double SumOfProduct(const vector<Subject>& subjects)
{
    double sum = 0;
    for(const Subject& foo : subjects){
        sum += foo.grade * foo.units;
    }
    return sum;
}

double SumOfUnits(const vector<Subject>& subjects)
{
    double sum = 0;
    for(const Subject& foo : subjects){
        sum += foo.units;
    }
    return sum;
}

double ComputeGWA(const vector<Subject>& subjects)
{
    double gwa = 0;
    gwa = SumOfProduct(subjects) / SumOfUnits(subjects);
    return gwa;
}

void Table(const vector<Subject>& subjects)
{
    system("CLS");
    cout << setw(20) << "Subject" << setw(20) << "Units" << setw(20) << "Grade" << setw(20) << endl;
    cout << setfill('-') << setw(80) << "" << setfill(' ') << endl;

    for (const Subject& sub : subjects){
        cout << setw(20) << sub.title << setw(20) << sub.units << setw(20) << sub.grade << setw(20) << endl;
    }
    cout << setfill('-') << setw(80) << "" << setfill(' ') << endl;
}

int main()
{
    vector<Subject> subjects;
    bool loop = true;
    int count = 1;
    char choice;
    Subject sub;
    system("cls");
    cout << "-------------------\n";
    cout << "   GWA Calculator   " << endl;
    cout << "-------------------\n";
    while(loop)
    {
        cout << "Press Enter to proceed." << endl;
        cin.ignore();
        system("CLS");
        cout << "Number of Subjects: " << count << endl;
        cout << "Subject: "; getline(cin, sub.title);
        cout << "Units  : "; cin >> sub.units;
        cout << "Grade  : "; cin >> sub.grade;

        subjects.push_back({sub.title, sub.units, sub.grade});

        cout << "\nDo you Want to add another Subject? (y/n)"; cin >> choice;
        if(choice == 'n'){
            cout << endl;
            loop = false;
        }
        else{
            count++;
        }
    }

    Table(subjects);
    double gwa = ComputeGWA(subjects);
    int unt = SumOfUnits(subjects);
    cout << "Total of Subjects: " << count << endl;
    cout << "Total of Units   : " << unt << endl;
    cout << "\nYour GWA is " << gwa;
}
