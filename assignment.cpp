#include <iostream>
#include <string> // std::string
using namespace std;

const int MAX_LEN = 100;

int vowelDetector(char c)
{
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
        return 1;
    else
        return 0;
}
void operationChoice(string stringValue)
{
    cout << "\nEnter D(Delete), I(Insert), F(Find), T(Tokenize), V(Vowal Remove) or Q(Quit) > ";
    string temp;
    char operationChar;
    cin >> operationChar;
    switch (operationChar)
    {
    case 'D':
    {
        cout << "String to Delete > ";
        cin >> temp;
        size_t found = stringValue.find(temp);
        stringValue.erase(found, temp.size());
        cout << "\n New source : " << stringValue << "\n";
        break;
    }
    case 'I':
    {
        cout << "String to Insert > ";
        cin >> temp;
        int pos;
        cout << "\nPosition of insertion > ";
        cin >> pos;
        stringValue.insert(pos, temp);
        cout << "\n New source : " << stringValue << "\n";

        break;
    }
    case 'F':
    {
        cout << "String to Find > ";
        cin >> temp;
        size_t found = stringValue.find(temp);
        cout << "'" << temp << "' found at position " << found;
        cout << "\n New source : " << stringValue << "\n";
        break;
    }
    case 'T':
    {
        char newTemp[5];
        char stringValueArr[stringValue.size() + 1];
        strcpy(stringValueArr, stringValue.c_str());
        cout << "Select a delimiter > ";
        cin >> newTemp;
        char *pch = strtok(stringValueArr, newTemp);
        int i = 0;
        while (pch != NULL)
        {
            cout << "\nToken " << i << " : " << pch;
            pch = strtok(NULL, " ,.-");
            i++;
        }
    }
    case 'V':
    {
        char newTemp[MAX_LEN];
        char stringValueArr[stringValue.size() + 1];
        strcpy(stringValueArr, stringValue.c_str());
        int j=0;
        for (int i=0; i<stringValue.size(); i++)
        {
            if (vowelDetector(stringValueArr[i]) == 0)
            {
                newTemp[j] = stringValueArr[i];
                j++;
            }
        }
        stringValueArr[j] = '\0';
        cout << "\nNew Source > " << stringValueArr;
        break;
    }
    case 'Q':
    {
        cout << "See you \n";
        break;
    }
    default:
        operationChoice(stringValue);
    }
}
int main()
{
    string stringValue;
    cout << "Enter the source string: \n";
    getline(cin, stringValue);
    operationChoice(stringValue);
}
