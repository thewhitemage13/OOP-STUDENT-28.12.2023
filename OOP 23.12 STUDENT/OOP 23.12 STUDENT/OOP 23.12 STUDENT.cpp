#include <iostream>
#include <ctime>
using namespace std;

class Data {
    unsigned short day;
    unsigned short month;
    long long year;
public:
    Data() : Data(23, 12, 2023) {}

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
    void PrintData() const
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
    unsigned int countpractic;
    unsigned int counthomework;
    unsigned int countexam;
    int* grade_of_practic = new int[countpractic];
    int* grade_of_homework = new int[counthomework];
    int* grade_of_exam = new int[countexam];

public:

    Student() : Student("Lolo", "Mukhammed", "Kamel", "Vilkovskaya 38", "0687680685") {}

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
        if (grade_of_practic != nullptr || grade_of_homework != nullptr || grade_of_exam != nullptr)
            delete[] grade_of_practic;
        delete[]grade_of_homework;
        delete[]grade_of_exam;
    }

    void PrintStudent() const
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
        for (int i = 0; i < countpractic; i++)
        {
            grade_of_practic[i] = rand() % 12;
        }
    } 
    void AddPractic(int newcountry)
    {
        int* temp = new int[countpractic + 1];
        for (int i = 0; i < countpractic; i++)
        {
            temp[i] = grade_of_practic[i];
        }

        temp[countpractic] = newcountry;
        countpractic++;
        for (int i = 0; i < countpractic; i++)
        {
            cout<<temp[i]<<", ";
        }
        delete[]grade_of_practic;
        grade_of_practic = temp;
    }
    int GetGradeByPractic(unsigned int index) const
    {
        if (index < countpractic)
        {
            return grade_of_practic[index];
        }
    }
    //HomeWork
    void GenHomeWork()
    {
        for (int i = 0; i < counthomework; i++)
        {
            grade_of_homework[i] = rand() % 12;
        }
    }
    void AddHomeWork(int newcountry)
    {
        int* temp = new int[counthomework + 1];
        for (int i = 0; i < counthomework; i++)
        {
            temp[i] = grade_of_homework[i];
        }

        temp[counthomework] = newcountry;
        counthomework++;
        for (int i = 0; i < counthomework; i++)
        {
            cout << temp[i] << ", ";
        }
        delete[]grade_of_homework;
        grade_of_homework = temp;
    }
    int GetGradeByHomeWork(unsigned int index) const
    {
        if (index < counthomework)
        {
            return grade_of_homework[index];
        }
    }
    //Exam
    void GenExam()
    {
        for (int i = 0; i < countexam; i++)
        {
            grade_of_exam[i] = rand() % 12;
        }
    }
    void AddExam(int newcountry)
    {
        int* temp = new int[countexam + 1];
        for (int i = 0; i < countexam; i++)
        {
            temp[i] = grade_of_exam[i];
        }

        temp[countexam] = newcountry;
        countexam++;
        for (int i = 0; i < countexam; i++)
        {
            cout << temp[i] << ", ";
        }
        delete[]grade_of_exam;
        grade_of_exam = temp;
    }
    int GetGradeByExam(unsigned int index) const
    {
        if (index < countexam)
        {
            return grade_of_exam[index];
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
    void SetPractic(unsigned int countpractic)
    {
        this->countpractic = countpractic;
    }
    unsigned int GetPractic()
    {
        return countpractic;
    }
    void SetHomeWork(unsigned int counthomework)
    {
        this->counthomework = counthomework;
    }
    unsigned int GetHomeWork()
    {
        return counthomework;
    }
    void SetExam(unsigned int countexam)
    {
        this->countexam = countexam;
    }
    unsigned int GetExam()
    {
        return countexam;
    }
};

int main()
{
    srand(time(NULL));
    Student s;
    Data d;
    Data da(04, 02, 2005);
    s.PrintStudent();
        cout << "Birthday: ";
    da.PrintData();
    cout << "\n\n";
    cout << "Start study: ";
    d.PrintData();

    cout << "\n\n";
    s.GenPractic();
    s.AddPractic(12);
    s.AddPractic(12);
    s.AddPractic(13);
    cout << "\n\n";
    cout << s.GetGradeByPractic(1) << "\n\n";
    s.GenHomeWork();
    s.AddHomeWork(12);
    s.AddHomeWork(6);
    cout << "\n\n";
    cout << s.GetGradeByHomeWork(1) << "\n\n";
    s.GenExam();
    s.AddExam(12);
    s.AddExam(2);
    cout << "\n\n";
    cout << s.GetGradeByExam(0) << "\n\n";
}
