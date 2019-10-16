#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
void start();
void RemoveClass(string File);
void AddClass(string File);
void ChangeUpperToLower(string  &name);
bool FileName(string &pointer);
bool Class_Name(string &pointer);
void HelpDocumention();
bool IsOrIsnt(string &Str);
void RemoveStudent(unsigned long long int id);
‫‪void AddStudent();‪
vector <string> VectorSplitedStrings;
struct Date
{
    unsigned short int Year;
    unsigned short int Month;
    unsigned short int Day;
};
struct Student
{
    string Firstname;
    string Lastname;
    unsigned long long int ID;
    Date Birthday;
    float Grade;
};
struct Class
{
    string ClassName;
    float Average;
    unsigned short int Capacity;
    vector <Student> Data;
};
vector <Class> Database;
int main()
{
    start();
    return 0;
}
void start()
{
    while(1)
    {
        string YourCommandLine;
        getline(cin , YourCommandLine);
        ChangeUpperToLower(YourCommandLine);
        int length = YourCommandLine.length();
        for(int Counter1 = 0, Counter2 = 0; Counter1 < length ; Counter1++)
        {
            string SplitedWithSpaces;
            if(YourCommandLine[Counter1] == ' ')
            {
                SplitedWithSpaces = YourCommandLine.substr(Counter2,Counter1 - Counter2);
                Counter2 = Counter1 + 1;
                VectorSplitedStrings.push_back(SplitedWithSpaces);
            }
            if(Counter1 == length - 1)
            {
                SplitedWithSpaces = YourCommandLine.substr(Counter2 , Counter1 - Counter2 + 1);
                VectorSplitedStrings.push_back(SplitedWithSpaces);
            }
        }
        if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "add" && VectorSplitedStrings.at(2) == "class" && FileName(VectorSplitedStrings.at(3)))
        {
            AddClass(VectorSplitedStrings.at(3));
            VectorSplitedStrings.clear();
        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "remove" && VectorSplitedStrings.at(2) == "class" && Class_Name(VectorSplitedStrings.at(3)))
        {
            RemoveClass(VectorSplitedStrings.at(3));
            VectorSplitedStrings.clear();


        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "show" && FileName(VectorSplitedStrings.at(2)))
        {
        cout << "dorost kar mikone :D";
        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "sort" && VectorSplitedStrings.at(2) == "name")
        {
            cout << "Sort Name";
        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "sort" && VectorSplitedStrings.at(2) == "ID")
        {
            cout << "Sort ID";
        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "save")
        {
            cout << "Saved :D";
        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "help")
        {
            HelpDocumention();
            VectorSplitedStrings.clear();
        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "select" && VectorSplitedStrings.at(2) == "class" && Class_Name(VectorSplitedStrings.at(3)))
        {
            cout << VectorSplitedStrings.at(3) << " >> ";
            string YourClass = VectorSplitedStrings.at(3);
            VectorSplitedStrings.clear();
            while(1)
            {

                string YourCommandLine;
                getline(cin , YourCommandLine);
                ChangeUpperToLower(YourCommandLine);
                int length = YourCommandLine.length();
                for(int Counter1 = 0, Counter2 = 0; Counter1 < length ; Counter1++)
                {
                    string SplitedWithSpaces;
                    if(YourCommandLine[Counter1] == ' ')
                    {
                        SplitedWithSpaces = YourCommandLine.substr(Counter2,Counter1 - Counter2);
                        Counter2 = Counter1 + 1;
                        VectorSplitedStrings.push_back(SplitedWithSpaces);
                    }
                    if(Counter1 == length - 1)
                    {
                        SplitedWithSpaces = YourCommandLine.substr(Counter2 , Counter1 - Counter2 + 1);
                        VectorSplitedStrings.push_back(SplitedWithSpaces);
                    }
                }
                if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "remove" && VectorSplitedStrings.at(2) == "student" )
                {
                    if(IsOrIsnt(YourClass))
                    {
                        unsigned long long int id = stoll(VectorSplitedStrings.at(3));
                        RemoveStudent(id);

                    }
                    else
                    {
                        cout << "Your classname isnt in database..." << endl;
                    }
                    VectorSplitedStrings.clear();

                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "add" && VectorSplitedStrings.at(2) == "student")
                {
                    cout <<"Add Student Pleas";
                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "search")
                {

                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "search")
                {

                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "show" && VectorSplitedStrings.at(2) != YourClass)
                {
                    cout << "ali";
                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "show" && VectorSplitedStrings.at(2) == YourClass)
                {
                    cout << "Hello World";
                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "help")
                {
                    HelpDocumention();
                }
                else
                {
                    cout << "basu help" << setw(4) << "-> help documention" << endl;
                    VectorSplitedStrings.clear();
                }

            }


        }
        else
        {
            cout << "basu help" << setw(4) << "-> help documention" << endl;
            VectorSplitedStrings.clear();
        }

    }
}
void ChangeUpperToLower(string &name)
{
    for(string :: iterator it = name.begin(); it != name.end() ; it++)
    {
        if(*it == 12)
        {
            continue;
        }
        if(*it >= 65 && *it <= 90)
        {
            *it += 32;
        }
    }
}
bool FileName(string &pointer)
{
    vector <string> filename {"l1.basu" , "l2.basu" , "l3.basu" , "l4.basu" , "l5.basu"};
    for(vector  <string> :: iterator it = filename.begin(); it != filename.end() ; it++)
    {
        if(*it == pointer)
        {
            return true;
        }
    }
    return false;

}
void HelpDocumention()
{
    cout << "There is some commandline for ypu that can enter to consol" << endl << endl;
    cout << "1 : basu add class" << endl;
    cout << "2 : basu remove class" << endl;
    cout << "3 : basu add student" << endl;
    cout << "4 : basu remove student <ID>" << endl;
    cout << "5 : basu select class <Class Name>" << endl;
    cout << "6 : basu select none" << endl;
    cout << "7 : basu search <ID>" << endl;
    cout << "8 : basu search <Full Name>" << endl;
    cout << "9 : basu show" << endl;
    cout << "10 : basu show <Class Name>" << endl;
    cout << "11 : basu sort name " << endl;
    cout << "12 : basu sort id" << endl;
    cout << "13 : basu save" << endl;
    cout << "14 : exit" << endl;
}
void AddClass(string File)
{
    const char* fName = File.c_str();
    Class NewClass;
    ifstream Input;
    Input.open(fName);
    if(!Input)
    {
        cout << "Ops...Error";
    }
    else
    {
        Input >> NewClass.ClassName;
        Input >> NewClass.Capacity;
        for(int i = 1 ; i <= NewClass.Capacity ; i++)
        {
            string date ;
            string temp[3];
            short int counter = 0;
            Student NewStudent;
            Input >> NewStudent.Firstname;
            Input >> NewStudent.Lastname;
            Input >> date;
            for(auto j : date)
            {
                if (j != '/')
                    temp[counter] += j;
                else
                    counter++;
            }
            NewStudent.Birthday.Year = stoi(temp[0]);
            NewStudent.Birthday.Month = stoi(temp[1]);
            NewStudent.Birthday.Day = stoi(temp[2]);
            Input >> NewStudent.Grade;
            Input >> NewStudent.ID;
            NewClass.Data.push_back(NewStudent);
        }
    }
    Database.push_back(NewClass);
    Input.close();
}
void RemoveClass(string File)
{
    bool status = false;
    for(int i = 0 ; i < Database.size()  ; i++)
    {
        if(File == Database.at(i).ClassName)
        {
            Database.erase(Database.begin() + i);
            status = true;
        }

    }
    if(!status)
    {
        cout  << "Your classname wasnt in database";
    }

}
bool Class_Name(string &pointer)
{
    vector <string> classname {"advanced_programming" ,"logic_circuits" , "discrete_mathematics" , "data_structure" , "artificial_intelligence" };
    for(vector  <string> :: iterator it = classname.begin(); it != classname.end() ; it++)
    {
        if(*it == pointer)
        {
            char * ptr[pointer.size() + 1];
            for(int i = 0 ; i <= pointer.size() ; i++)
            {
                if(i == 0 || pointer[i - 1] == '_')
                {
                    pointer[i] -= 32;
                }
                ptr[i] = &pointer[i];

            }
            return true ;
        }
    }
    return false;

}
bool IsOrIsnt(string &Str)
{
    for(auto &p : Database)
    {
        if(p.ClassName == Str)
        {
            return true;
        }
    }
    return false;

}
void RemoveStudent(unsigned long long int id)
{
    for(auto &t : Database)
    {
        for(int j = 0 ; j < Database.size() ; j++)
        {
            if(t.Data.at(j).ID == id)
            {
                t.Data.erase(t.Data.begin() + j);
                t.Capacity--;
            }
        }
    }

}