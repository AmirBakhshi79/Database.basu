#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
void start();
void ChangeUpperToLower(string  &name);
bool FileName(string &pointer);
void HelpDocumention();
vector <string> VectorSplitedStrings;
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
        string * PointerToVector = VectorSplitedStrings.data();
        if(PointerToVector[0] == "basu" && PointerToVector[1] == "add" && PointerToVector[2] == "class" && FileName(PointerToVector[3]))
        {
            cout << "Yes";
            VectorSplitedStrings.clear();
        }
        else if(PointerToVector[0] == "basu" && PointerToVector[1] == "remove" && PointerToVector[2] == "class" && FileName(PointerToVector[3]))
        {



        }
        else if(PointerToVector[0] == "basu" && PointerToVector[1] == "show" && FileName(PointerToVector[2]))
        {
        cout << "dorost kar mikone :D";
        }
        else if(PointerToVector[0] == "basu" && PointerToVector[1] == "sort" && PointerToVector[2] == "name")
        {
            cout << "Sort Name";
        }
        else if(PointerToVector[0] == "basu" && PointerToVector[1] == "sort" && PointerToVector[2] == "ID")
        {
            cout << "Sort ID";
        }
        else if(PointerToVector[0] == "basu" && PointerToVector[1] == "save")
        {
            cout << "Saved :D";
        }
        else if(PointerToVector[0] == "basu" && PointerToVector[1] == "help")
        {
            HelpDocumention();
        }
        else if(PointerToVector[0] == "basu" && PointerToVector[1] == "select" && PointerToVector[2] == "class" && FileName(PointerToVector[3]))
        {
            string YourClass = PointerToVector[3];
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
                string * PointerToVector = VectorSplitedStrings.data();
                if(PointerToVector[0] == "basu" && PointerToVector[1] == "remove" && PointerToVector[2] == "student" )
                {
                    cout << "Great";
                }
                else if(PointerToVector[0] == "basu" && PointerToVector[1] == "add" && PointerToVector[2] == "student")
                {
                    cout <<"Add Student Pleas";
                }
                else if(PointerToVector[0] == "basu" && PointerToVector[1] == "search")
                {

                }
                else if(PointerToVector[0] == "basu" && PointerToVector[1] == "search")
                {

                }
                else if(PointerToVector[0] == "basu" && PointerToVector[1] == "show" && PointerToVector[2] != YourClass)
                {
                    cout << "ali";
                }
                else if(PointerToVector[0] == "basu" && PointerToVector[1] == "show" && PointerToVector[2] == YourClass)
                {
                    cout << "Hello World";
                }
                else if(PointerToVector[0] == "basu" && PointerToVector[1] == "help")
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
        }

    }
}
void ChangeUpperToLower(string &name)
{
    for(string :: iterator it = name.begin(); it != name.end() ; it++)
    {
        if(*it >= 65 && *it <= 90)
        {
            *it += 32;
        }
    }
}
bool FileName(string &pointer)
{
    vector <string> filename {"hes" , "her" , "us"};
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