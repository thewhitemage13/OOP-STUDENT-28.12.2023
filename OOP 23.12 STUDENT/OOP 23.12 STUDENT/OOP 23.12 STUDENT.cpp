#include <iostream>
#include <ctime>
using namespace std;

class Data {
    unsigned short day;
    unsigned short month;
    long long year;
public:

    Data() : Data(23,12,2023){}

    Data(unsigned short day, unsigned short month, long long year)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(year);
    }

    Data(unsigned short day, unsigned short month)
    {
        SetDay(day);
        SetMonth(month);
        SetYear(2023);
    }
    void PrintData()
    {
        cout << day << "." << month << "." << year;
    }
    //day SetGet
    void SetDay(unsigned short day)
    {
        if (day > 31) throw "ERROR!!!";
        this->day = day;
    }
    unsigned short GetDay() const
    {
        return day;
    }
    //month SetGet
    void SetMonth(unsigned short month)
    {
        if (month > 12) throw "ERROR!!!";
        this->month = month;
    }
    unsigned short GetMonth() const
    {
        return month;
    }
    //year SetGet
    void SetYear(long long year)
    {
        this->year = year;
    }
    long long GetYear() const
    {
        return year;
    }

};

class Student {
private: 
    string surname;
    string name;
    string middlename;
    string adress;
    string phonenumber;
    unsigned int count = 16;
    int* grade_of_practic = new int[count];
    int* grade_of_homework = new int[count];
    int* grade_of_exam = new int[count];
    
    int* grade_of_practic_new = new int[count + 1];
    int* grade_of_homework_new = new int[count + 1];
    int* grade_of_exam_new = new int[count + 1];

public:
    
    Student() : Student("Lolo", "Mukhammed", "Kamel", "Vilkovskaya 38", "0687680685"){}

    Student(string surname, string name, string middlname, string adress, string phonenumber)
    {
        SetSurname(surname);
        SetName(name);
        SetMiddlName(middlname);
        SetAdress(adress);
        SetPhone(phonenumber);
    }

    Student(string surname, string name, string middlname, string adress)
    {
        SetSurname(surname);
        SetName(name);
        SetMiddlName(middlname);
        SetAdress(adress);
        SetPhone("0687680685");
    }

    ~Student() 
    {
        if (grade_of_practic != nullptr || grade_of_homework!= nullptr || grade_of_exam != nullptr)
        delete[] grade_of_practic;
        delete[]grade_of_homework;
        delete[]grade_of_exam;
    }
    ///////
    void PrintStudent()
    {
        cout << "Surname: " << surname << "\n";
        cout << "Name: " << name << "\n";
        cout << "Midlname: " << middlename << "\n";
        cout << "Adress: " << adress << "\n";
        cout << "Phonnumber: " << phonenumber << "\n\n";
    }
    //Practic
    void GenPractic()
    {
        for (int i = 0; i < count; i++)
        {
            grade_of_practic[i] = rand() % 12;
        }
    }
    void PrintPractic()
    {
        cout << "Practic: ";
        for (int i = 0; i < count; i++)
        {
            cout << grade_of_practic[i] << ", ";
        }
    }
    void AddPractic(int newpractic)
    {
        for (int i = 0; i < count; i++)
        {
            grade_of_practic_new[i] = grade_of_practic[i];
        }
    }
    void PrintNewPractic() const 
    {
        cout << "Add Practic: ";
        for (int i = 0; i < count; i++)
        {
            cout << grade_of_practic_new[i] << ", ";
        }
    }
    void FreeMemoryPractic()
    {
        delete[]grade_of_practic;
        grade_of_practic = grade_of_practic_new;
    }

    int GetGradeByPractic(unsigned int index) const
    {
        if (index < count)
        {
            cout << "The grade you're looking for: " << grade_of_practic[index];

            return grade_of_practic[index];
        }
    }
    //Exam
    void GenExam()
    {
        for (int i = 0; i < count; i++)
        {
            grade_of_exam[i] = rand() % 12;
        }
    }
    void PrintExam()
    {
        cout << "Exam: ";
        for (int i = 0; i < count; i++)
        {
            cout << grade_of_exam[i] << ", ";
        }
    }
    void AddExam(int newpractic)
    {
        for (int i = 0; i < count; i++)
        {
            grade_of_exam_new[i] = grade_of_exam[i];
        }
        grade_of_exam_new[count] = newpractic;
        count++;

    }
    void PrintNewExam() const
    {
        cout << "Add Exam: ";
        for (int i = 0; i < count; i++)
        {
            cout << grade_of_exam_new[i] << ", ";
        }
    }
    void FreeMemoryExam()
    {
        delete[]grade_of_exam;
        grade_of_exam = grade_of_exam_new;
    }

    int GetGradeByExam(unsigned int index) const
    {
        if (index < count)
        {
            cout << "The grade you're looking for: " << grade_of_exam[index];
            return grade_of_exam[index];
        }
    }
    //Home Work
    void GenHomeWork()
    {
        for (int i = 0; i < count; i++)
        {
            grade_of_homework[i] = rand() % 12;
        }
    }
    void PrintHomeWork()
    {
        cout << "HomeWork: ";
        for (int i = 0; i < count; i++)
        {
            cout << grade_of_homework[i] << ", ";
        }
    }
    void AddHomeWork(int newpractic)
    {
        for (int i = 0; i < count; i++)
        {
            grade_of_homework_new[i] = grade_of_homework[i];
        }
        grade_of_homework_new[count] = newpractic;
        count++;

    }
    void PrintNewHomeWork() const
    {
        cout << "Add HomeWork: ";
        for (int i = 0; i < count; i++)
        {
            cout << grade_of_homework_new[i] << ", ";
        }
    }
    void FreeMemoryHomeWork()
    {
        delete[]grade_of_homework;
        grade_of_homework = grade_of_homework_new;
    }

    int GetGradeByHomeWork(unsigned int index) const
    {
        if (index < count)
        {
            cout <<"The grade you're looking for: " << grade_of_homework[index];
            return grade_of_homework[index];
        }
    }
    //surname GetSet
    void SetSurname(string surname)
    {
        this->surname = surname;
    }   
    string GetSurname() const
    {
        return surname;
    }
    //name GetSet
    void SetName(string name)
    {
        this->name = name;
    }
    string GetName() const 
    {
        return name;
    }
    //middlename GetName
    void SetMiddlName(string middlname)
    {
        this->middlename = middlname;
    }
    string GetMiddlName() const
    {
        return middlename;
    }
    //adress GetNam
    void SetAdress(string adress)
    {
        this->adress = adress;
    }
    string GetAdress() const
    {
        return adress;
    }
    //phonnumber GetSet
    void SetPhone(string phonenumber)
    {
        this->phonenumber = phonenumber;
    }
    string GetPhone() const
    {
        return phonenumber;
    }
    void SetCount(unsigned int count)
    {
        this->count = count;
    }
    unsigned int GetCount()
    {
        return count;
    }
};

int main()
{
    srand(time(NULL));
    Student s;
    Data birthday(04,02,2005);
    Data start;
    cout << "Mystat: " << "\n\n\n";
    Student st("Mukhammed", "Lolo", "Kamel", "Vilkovkaya 38", "0687680685");
    s.PrintStudent();
    cout << "Birthday: ";
    birthday.PrintData();
    cout << "\n\n";
    cout << "Start study: ";
    start.PrintData();
    cout << "\n\n";
    cout << "Grades: " << "\n\n";
    s.GenPractic();
    s.PrintPractic();
    cout << "\n\n";
    s.AddPractic(12);
    s.PrintNewPractic();
    s.FreeMemoryPractic();
    cout << "\n\n";
    s.GenHomeWork();
    s.PrintHomeWork();
    cout << "\n\n";
    s.AddHomeWork(2);
    s.PrintNewHomeWork();
    s.FreeMemoryHomeWork();
    cout << "\n\n";
    s.GenExam();
    s.PrintExam();
    cout << "\n\n";
    s.AddExam(1);
    s.PrintNewExam();
    cout << "\n\n";
    s.GetGradeByHomeWork(3);
    cout << "\n\n";
    s.GetGradeByPractic(2);
    cout << "\n\n";
    s.GetGradeByExam(4);
    s.FreeMemoryExam();
    s.FreeMemoryHomeWork();
    s.FreeMemoryPractic();
}
