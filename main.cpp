#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
void start();
void ChangeUpperToLower(string  &name);
bool FileName(string &pointer);
vector <string> VectorSplitedStrings;
int main()
{
    start();
    return 0;
}
void start()
{
    while()
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
        if(PointerToVector[0] == "basu" && PointerToVector[1] == "remove" && PointerToVector[2] == "class" && FileName(PointerToVector[3]))
        {



        }
        if(PointerToVector[0] == "basu" && PointerToVector[1] == "show" && FileName(PointerToVector[2]))
        {
        cout << "dorost kar mikone :D";
        }
        if(PointerToVector[0] == "basu" && PointerToVector[1] == "sort" && PointerToVector[2] == "name")
        {
            cout << "Sort Name";
        }
        if(PointerToVector[0] == "basu" && PointerToVector[1] == "sort" && PointerToVector[2] == "ID")
        {
            cout << "Sort ID";
        }
        if(PointerToVector[0] == "basu" && PointerToVector[1] == "save")
        {
            cout << "Saved :D";
        }
        if(PointerToVector[0] == "basu" && PointerToVector[1] == "select" && PointerToVector[2] == "class" && FileName(PointerToVector[3]))



        {
            VectorSplitedStrings.clear();
            string YourClass = PointerToVector[3];
            while()
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
                if(PointerToVector[0] == "basu" && PointerToVector[1] == "search")
                {

                }
                if(PointerToVector[0] == "basu" && PointerToVector[1] == "search")
                {

                }
                if(PointerToVector[0] == "basu" && PointerToVector[1] == "show" && PointerToVector[2] != YourClass)
                {
                    cout << "ali";
                }
                if(PointerToVector[0] == "basu" && PointerToVector[1] == "show" && PointerToVector[2] == YourClass)
                {
                    cout << "Hello World";
                }

            }


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