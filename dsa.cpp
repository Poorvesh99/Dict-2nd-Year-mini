#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;


unsigned int has(string key)
{
    // TODO: Improve this hash function
    return (toupper(key[0]) - 'A') % 26;
}

void check(string key)
{
    string word;
    string meaning;

    char filename1 = has(key)+'A';
    string name1 = "words/"+ string(1, filename1) +"word.csv";

    ifstream wordfile;
    wordfile.open(name1);
    if (!wordfile.is_open()) 
    {
       cout << "\nNo Such File Exist:-"<<name1;
    }

    char filename2 = has(key)+'A';
    string name2 = "meaning/"+ string(1, filename2) +".csv";

    ifstream meaningfile;
    meaningfile.open(name2);
     if (!meaningfile.is_open()) 
    {
        cout << "\nNo Such File Exist:-"<<name2;
    }

    while(getline(wordfile, word))
    {
        word = word.substr(0, word.length() - 2);
        if (word.compare(key)== 0)
        {
            while(word.compare(key) == 0)
            {
                getline(meaningfile, meaning);
                cout<<"\n"<<meaning<<"\n";
                getline(meaningfile, meaning);
                getline(wordfile, word);
                word = word.substr(0, word.length() - 2);   
            }
            wordfile.close();
            meaningfile.close();
            return;
        }   
        getline(meaningfile, meaning);
        getline(meaningfile, meaning);
    }
    cout << "\nword not found";
}

int main()
{   int ch;
    string key;
    do
    {
        cout << "\n\n-----------------------Menu-------------------------";
        cout << "\nenter 1 to search word";
        cout << "\nenter 2 to Exit";
        cout <<"\n\nEnter Your choice :- ";
        cin >> ch;
        
        switch (ch)
        {
        case 1:
            cout<<"\nEnter key:- ";
            cin>> key;
            transform(key.begin(), key.end(), key.begin(), ::tolower);
            check(key);
            break;
        
        case 2:
            cout<< "\nThank You\n";
            break;
        
        default:
            cout << "\nwrong choice";
            break;
        }
        
    } while (ch != 2);
}

