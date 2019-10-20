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
void AddStudent1(string Srt);
void ShowClass(string Str);
void ShowAll();
void BasuSearchID(unsigned long long int ID);
void BasuShowClass(string Str);
void Search(string Str1 , string Str2);
void LowToUp(string &pointer);
void SortByName();
void SortById();
string NameFileForDataBaseSaved();
string YourClass;
int i = 0;
vector <string> VectorSplitedStrings;
void Save();
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
void AddStudent2(string FirstName , string LastName , Date date , unsigned long long int ID , float Average);
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
        bool Boolean = false;
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
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "show" && Class_Name(VectorSplitedStrings.at(2)))
        {
            BasuShowClass(VectorSplitedStrings.at(2));
            VectorSplitedStrings.clear();
        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "sort" && VectorSplitedStrings.at(2) == "name")
        {
            SortByName();
            VectorSplitedStrings.clear();
        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "sort" && VectorSplitedStrings.at(2) == "id")
        {
            SortById();
            VectorSplitedStrings.clear();
        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "save")
        {
            Save();
            VectorSplitedStrings.clear();
        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "help")
        {
            HelpDocumention();
            VectorSplitedStrings.clear();
        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "showall" && VectorSplitedStrings.size() == 2)
        {
            ShowAll();
            VectorSplitedStrings.clear();
        }
        else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "select" && VectorSplitedStrings.at(2) == "class" && Class_Name(VectorSplitedStrings.at(3)))
        {
            cout << VectorSplitedStrings.at(3) << " >> ";
            YourClass = VectorSplitedStrings.at(3);
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

                    string Str;
                    getline(cin , Str);
                    AddStudent1(Str);
                    VectorSplitedStrings.clear();

                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "show" && Class_Name(VectorSplitedStrings.at(2)))
                {
                    BasuShowClass(VectorSplitedStrings.at(2));
                    VectorSplitedStrings.clear();
                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "search" && VectorSplitedStrings.size() == 3)
                {
                    unsigned long long int id = stoll(VectorSplitedStrings.at(2));
                    BasuSearchID(id);
                    VectorSplitedStrings.clear();
                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "search" && VectorSplitedStrings.size() == 4)
                {
                    LowToUp(VectorSplitedStrings.at(2));
                    LowToUp(VectorSplitedStrings.at(3));
                    Search(VectorSplitedStrings.at(2) , VectorSplitedStrings.at(3));
                    VectorSplitedStrings.clear();
                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "show" )
                {
                    ShowClass(YourClass);
                    VectorSplitedStrings.clear();
                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "showall" && VectorSplitedStrings.size() == 2)
                {
                    ShowAll();
                    VectorSplitedStrings.clear();
                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "help")
                {
                    HelpDocumention();
                }
                else if(VectorSplitedStrings.at(0) == "basu" && VectorSplitedStrings.at(1) == "select" && VectorSplitedStrings.at(2) == "none" && VectorSplitedStrings.size() == 3)
                {
                    Boolean = true;
                    VectorSplitedStrings.clear();
                    break;
                }
                else
                {
                    cout << "basu help" << setw(4) << "-> help documention" << endl;
                    VectorSplitedStrings.clear();
                }

            }
        }
        else if(VectorSplitedStrings.at(0) == "exit" && VectorSplitedStrings.size() == 1)
        {
            break;
        }
        else
        {
            cout << "basu help" << setw(4) << "-> help documention" << endl;
            VectorSplitedStrings.clear();
        }
        if(Boolean)
        {
            continue;
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
    float total = 0;
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
            total += NewStudent.Grade;
            Input >> NewStudent.ID;
            NewClass.Data.push_back(NewStudent);
        }
    }
    NewClass.Average = total / NewClass.Capacity;
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
void AddStudent1(string Str)
{
    Str += ' ';
    vector <string> YourString;
    string t;
    Date YourStudetDate;
    unsigned long long int ID;
    float Average;
    for(auto &i : Str)
    {
        if(i != ' ')
        {
            t += i;
        }
        else
        {
            YourString.push_back(t);
            t = "";
        }

    }
    string temp[3];
    unsigned int counter = 0;
    for(auto j : YourString.at(2))
    {
        if (j != '/')
            temp[counter] += j;
        else
            counter++;
    }
    YourStudetDate.Year = stoi(temp[0]);
    YourStudetDate.Month = stoi(temp[1]);
    YourStudetDate.Day = stoi(temp[2]);
    ID = stoll(YourString.at(3));
    Average = stof(YourString.at(4));
    AddStudent2(YourString.at(0) , YourString.at(1), YourStudetDate , ID , Average);


}
void AddStudent2(string FirstName , string LastName , Date date , unsigned long long int ID , float Average)
{
    for(int i = 0 ; i <Database.size() ; i++)
    {
        if(Database.at(i).ClassName == YourClass)
        {
            Student NewStudent;
            NewStudent.Firstname = FirstName ;
            NewStudent.Lastname = LastName;
            NewStudent.Birthday.Year = date.Year;
            NewStudent.Birthday.Month = date.Month;
            NewStudent.Birthday.Day = date.Day;
            NewStudent.ID = ID;
            NewStudent.Grade = Average;
            Database.at(i).Data.push_back(NewStudent);
            Database.at(i).Capacity++;
            cout << Database.at(0).ClassName << endl;
            cout << Database.at(0).Capacity << endl;
            for (Student s : Database.at(0).Data)
            {
                cout << s.Firstname << " " << s.Lastname << " " << s.Birthday.Year << "/" <<
                     s.Birthday.Month << "/" << s.Birthday.Day << " " << s.Grade << " " << s.ID << endl;
            }
        }
    }
}
void ShowClass(string Str)
{
    bool Status = false;
    for(auto &i : Database)
    {
        if(i.ClassName == Str)
        {
            Status = true;
            for(int j = 0 ; j < i.Capacity ; j++)
            {
                cout << i.Data.at(j).Firstname << " " << i.Data.at(j).Lastname << " " << i.Data.at(j).Birthday.Year << "/" <<
                i.Data.at(j).Birthday.Month << "/" << i.Data.at(j).Birthday.Day << "/" << i.Data.at(j).Grade << " " << i.Data.at(j).ID << endl;
            }
        }

    }
    if(!Status)
    {
        cout << "You must first add your favorite class to datebase then show that class" << endl;
        HelpDocumention();
    }
}
void ShowAll()
{
    if(Database.size() != 0)
    {
        for(auto &i : Database)
        {

            for(int k = 0 ; k < i.Capacity ; k++)
            {
                cout << i.Data.at(k).Firstname << " " << i.Data.at(k).Lastname << " " << i.Data.at(k).Birthday.Year << "/" <<
                     i.Data.at(k).Birthday.Month << "/" << i.Data.at(k).Birthday.Day << "/" << i.Data.at(k).Grade << " " << i.Data.at(k).ID << endl;
            }
            cout << endl << endl << endl ;

        }
    }
    else
    {
        cout << "You must add at least one class to database then type showall" << endl;
    }


}
void BasuSearchID(unsigned long long int ID)
{
    bool Status = false;
    for(auto i : Database)
    {
        if(i.ClassName == YourClass)
        {
            for(int j = 0 ; j < i.Capacity ; j++)
            {
                if(i.Data.at(j).ID == ID)
                {
                    cout << i.Data.at(j).Firstname << " " << i.Data.at(j).Lastname << " " << i.Data.at(j).Birthday.Year << "/" <<
                    i.Data.at(j).Birthday.Month << "/" << i.Data.at(j).Birthday.Day << "/" << i.Data.at(j).Grade << " " << i.Data.at(j).ID << endl;
                    Status = true;
                }
            }
        }
    }
    if(!Status)
    {
        cout << "Your ID isnt in your selected class...";
    }
}
void BasuShowClass(string Str)
{
    bool Status = false;
    for(auto i : Database)
    {
        if(i.ClassName == Str)
        {
            for(int j = 0 ; j < i.Capacity ; j++)
            {
                cout << i.Data.at(j).Firstname << " " << i.Data.at(j).Lastname << " " << i.Data.at(j).Birthday.Year << "/" <<
                i.Data.at(j).Birthday.Month << "/" << i.Data.at(j).Birthday.Day << "/" << i.Data.at(j).Grade << " " << i.Data.at(j).ID << endl;
                Status = true;

            }
        }
    }
    if(!Status)
    {
        cout << "There is no class in database" << endl;
        cout << "You must add at least one class to data base" << endl;
    }
}
void Save()
{
    ofstream CoutInFile;
    if(Database.size() == 0)
    {
        cout << "Your database is already empty";
    }
    else
    {
        for(auto i : Database)
        {
            ofstream CoutInFile;
            CoutInFile.open(NameFileForDataBaseSaved());
            CoutInFile << i.ClassName << endl;
            CoutInFile << i.Capacity << endl;
            CoutInFile << i.Average << endl;
            for(int j = 0 ; j < i.Capacity ; j++)
            {
                CoutInFile << i.Data.at(j).Firstname << "   ";
                CoutInFile << i.Data.at(j).Lastname << "   ";
                CoutInFile << i.Data.at(j).ID << "   ";
                CoutInFile << i.Data.at(j).Grade << "   ";
                CoutInFile << i.Data.at(j).Birthday.Year << "/" <<
                           i.Data.at(j).Birthday.Month << "/" << i.Data.at(j).Birthday.Day << endl;

            }
            CoutInFile.close();
        }
    }

}
string NameFileForDataBaseSaved()
{

    while(true)
    {
        string Str;
        Str = to_string(i) + ".basu";
        i++;
        return Str;
    }
}
void Search(string Str1 , string Str2)
{
    bool Status = false;
    for (auto i : Database)
    {
        if(i.ClassName == YourClass)
        {
            for(int j = 0 ; j < i.Capacity ; j++)
            {
                if(i.Data.at(j).Firstname == Str1 && i.Data.at(j).Lastname == Str2)
                {
                    cout << i.Data.at(j).Firstname << " " << i.Data.at(j).Lastname << " " << i.Data.at(j).Birthday.Year << "/" <<
                    i.Data.at(j).Birthday.Month << "/" << i.Data.at(j).Birthday.Day << "/" << i.Data.at(j).Grade << " " << i.Data.at(j).ID << endl;
                    Status = true;
                    break;
                }
            }
        }
    }
    if(!Status)
    {
        cout << "Your selected student isnt in your selected class";
    }

}
void LowToUp(string &pointer)
{
    pointer.at(0)  -= 32;
}
void SortById()
{
    for(auto & i : Database)
    {
        for(int j = 0 ; j < i.Capacity - 1 ; j++)
        {
            for(int k = 0 ; k < i.Capacity - j - 1 ; k++)
            {
                if(i.Data.at(k).ID > i.Data.at(k+1).ID)
                {
                    swap(i.Data.at(k) , i.Data.at(k+1));
                }
            }
        }
    }
}
void SortByName()
{
    for(auto & i : Database)
    {
        for(int j = 0 ; j < i.Capacity - 1 ; j++)
        {
            for(int k = 0 ; k < i.Capacity - j - 1 ; k++)
            {
                for(int n = 0 ; n <= 4 ; n++)
                {
                    if(i.Data.at(k).Firstname.at(n) == i.Data.at(k+1).Firstname.at(n))
                    {
                        continue;
                    }
                    else if(i.Data.at(k).Firstname.at(n) > i.Data.at(k+1).Firstname.at(n))
                    {
                        swap(i.Data.at(k) , i.Data.at(k + 1));
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
}