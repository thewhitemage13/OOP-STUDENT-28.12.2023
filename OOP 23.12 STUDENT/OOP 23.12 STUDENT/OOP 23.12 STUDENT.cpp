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
    //Делегирование
    Data(unsigned short day, unsigned short month) : Data(day, month, 2005){}


    void PrintData() const
    {
        cout << day << "." << month << "." << year << "\n";
    }
    //day SetGet
    void SetDay(unsigned short day)
    {
        if (day == 0 || day > 31) throw "ERROR!!! The day must be from 0 to 31 !!!";
        this->day = day;
    }
    unsigned short GetDay() const
    {
        return day;
    }
    //month SetGet
    void SetMonth(unsigned short month)
    {
        if (month == 0 || month > 12) throw "ERROR!!! The day must be from 1 to 12 !!!";
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
    unsigned int countpractic = 0;
    unsigned int counthomework = 0;
    unsigned int countexam = 0;
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
    //Делегирование
    Student(string surname, string name, string middlname, string adress):Student(surname, name, middlename, adress, "0687680685") {}


    ~Student()
    {
        if (grade_of_practic != nullptr)
            delete[] grade_of_practic;
        if (grade_of_homework != nullptr)
            delete[] grade_of_homework;
        if (grade_of_exam != nullptr)
            delete[] grade_of_exam;
    }

    void PrintStudent() const
    {
        cout << "Surname: " << surname << "\n";
        cout << "Name: " << name << "\n";
        cout << "Midlname: " << middlename << "\n";
        cout << "Adress: " << adress << "\n";
        cout << "Phonnumber: " << phonenumber << "\n";
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
        delete[]grade_of_practic;
        grade_of_practic = temp;
    }
    //Добавил,чтоб "учитель" мог просмотреть все оценки
    void PrintPractic() const
    {
        for (int i = 0; i < countpractic; i++)
        {
            cout << grade_of_practic[i] << ", ";
        }
    }

    int GePracticRatesCount(unsigned int index) const
    {
        if (index < countpractic)
        {
            return grade_of_practic[index];
        }
    }
    //HomeWork
    void AddHomeWork(int newcountry)
    {
        int* temp = new int[counthomework + 1];
        for (int i = 0; i < counthomework; i++)
        {
            temp[i] = grade_of_homework[i];
        }
        temp[counthomework] = newcountry;
        counthomework++;
        delete[]grade_of_homework;
        grade_of_homework = temp;
    }
    //Добавил,чтоб "учитель" мог просмотреть все оценки
    void PrintHomeWork() const
    {
        for (int i = 0; i < counthomework; i++)
        {
            cout << grade_of_homework[i] << ", ";
        }
    }
    int GetHomeWorkRatesCount(unsigned int index) const
    {
        if (index < counthomework)
        {
            return grade_of_homework[index];
        }
    }
    //Exam
    void AddExam(int newcountry)
    {
        int* temp = new int[countexam + 1];
        for (int i = 0; i < countexam; i++)
        {
            temp[i] = grade_of_exam[i];
        }
        temp[countexam] = newcountry;
        countexam++;
        delete[]grade_of_exam;
        grade_of_exam = temp;
    }
    //Добавил,чтоб "учитель" мог просмотреть все оценки
    void PrintExam() const
    {
        for (int i = 0; i < countexam; i++)
        {
            cout << grade_of_exam[i] << ", ";
        }
    }
    int GetExamRatesCount(unsigned int index) const
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
};

int main()
{
    srand(time(NULL));
    Student s;
    Data da;
    Data d(04,02);
    s.PrintStudent();
    cout << "Dirthday: ";
    da.PrintData();
    cout << "Start study: ";
    d.PrintData();
    cout << "\n\n";
    cout << "Practic: ";
    s.AddPractic(12);
    s.AddPractic(8);
    s.AddPractic(3);
    s.PrintPractic();
    cout << "\n\n";
    cout << "Home Work: ";
    s.AddHomeWork(5);
    s.AddHomeWork(10);
    s.PrintHomeWork();
    cout << "\n\n";
    cout << "Exam: ";
    s.AddExam(6); 
    s.AddExam(7);
    s.AddExam(4);
    s.PrintExam();
    cout << "\n";
}
