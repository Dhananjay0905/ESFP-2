#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;

void login();
void registration();
void forgot();
void aboutus();
void features();

class loggedin
{
public:
    int count1 = 0;
    string name, surname, filename, address;
    int mm()
    {
        if (count1 == 0)
        {
            cout << "\n| Enter your name: ";
            cin >> name;
            filename = name + ".txt";
            ifstream fn;
            fn.open(filename);
            if (fn)
            {
                count1 = 1;
                return count1;
            }
            else
            {
                count1 = 0;
                return count1;
            }
        }
        else
        {
            return count1;
        }
    }
};

class user : public loggedin
{
public:
    void menu()
    {
        if (mm() == 1)
        {
            string ask;
            while (1)
            {
                cout << "\n| Welcome Back " << name;
                cout << "\n| You have already added your details";
                cout << "\n| Do you want to add emergency contacts? (y or n): ";
                cin >> ask;
                if (ask == "y")
                {
                    string pname, pno, paddress;
                    cout << "\n| Enter the name of the person: ";
                    cin >> pname;
                    cout << "\n| Enter the phone number of the person: ";
                    cin >> pno;
                    cout << "\n| Enter the address of the person: ";
                    cin.ignore();
                    getline(cin, paddress);
                    ofstream fn(filename, ios::app);
                    fn << pname << " " << pno << " " << paddress << endl;
                    fn.close();
                }
                else
                {
                    break;
                }
            }
        }
        else if (mm() == 0)
        {
            string ask;
            ofstream fn;
            fn.open(filename, ios::app);
            cout << "\n| Enter your last name: ";
            cin >> surname;
            fn << name << " " << surname << "\n"
               << "Address\n";
            cout << "\n| Enter your Address ( in 1 line): ";
            cin.ignore();
            getline(cin, address);
            fn << address;
            fn << "\n"
               << "Emergency Contacts:-\n";
            while (1)
            {
                cout << "\n| Add emergency contacts (y or n): ";
                cin >> ask;
                if (ask == "y")
                {
                    string pname, pno, paddress;
                    cout << "\n| Enter name of the person: ";
                    cin >> pname;
                    cout << "\n| Enter phone number of the person: ";
                    cin >> pno;
                    cout << "\n| Enter address of the person: ";
                    cin.ignore();
                    getline(cin, paddress);
                    fn << pname << " " << pno << " " << paddress << " ";
                }
                else
                {
                    break;
                }
            }
        }
    }
};

int main()
{
    int c;
    cout << "|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n";
    cout << "|                                  GANPAT UNIVERTSITY - ICT                                     |\n";
    cout << "|                          BRANCH - CLOUD BASED APPLICATIONS (CBA)                              |\n";
    cout << "|                                          BATCH - 11                                           |\n";
    cout << "|                                    ENROLLMENT NO. - CBA04                                     |\n";
    cout << "|                         PROJECT TITLE - PID593 NARI - Women Safety                            |\n";
    cout << "|                                        ESFP-II PROJECT                                        |\n";
    cout << "|=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|\n";
    cout << endl;
    cout << "\n\n************************************************************************************************";
    cout << "\n                              N A R I    -    W O M E N     S A F E T Y";
    cout << "\n************************************************************************************************\n";
    while (1)
    {
        cout << "\n| Press 1 to Login                    |";
        cout << "\n| Press 2 to Register                 |";
        cout << "\n| Press 3 if you Forgot your password |";
        cout << "\n| Press 4 for About                   |";
        cout << "\n| Press 5 for Features                |";
        cout << "\n| Press 6 for Contact                 |";
        cout << "\n| Press 0 to Exit                     |";
        cout << "\n\n| Please enter your choice:  ";
        cin >> c;
        cout << endl;

        if (c == 1)
        {
            login();
            user afterlogin;
            afterlogin.mm();
            afterlogin.menu();
        }

        else if (c == 2)
        {
            registration();
        }

        else if (c == 3)
        {
            forgot();
        }

        else if (c == 4)
        {
            cout << "\n\n----------------------------------------About Us-----------------------------------------------\n\n";
            aboutus();
            cout << "\n\n-----------------------------------------------------------------------------------------------\n\n";
        }

        else if (c == 5)
        {
            cout << "\n\n----------------------------------------Features-----------------------------------------------\n\n";
            features();
            cout << "\n\n-----------------------------------------------------------------------------------------------\n\n";
        }
        else if (c == 6)
        {
            cout << "\n\n-----------------------------------------------------------------------------------------------\n\n";
            cout << "Contact Us on: ";
            cout << "\n\n24/7 Toll-free Number: 1234567890";
            cout << "\n\nEmail: nariwsapp@gmail.com\n\n";
            cout << "\n\n-----------------------------------------------------------------------------------------------\n\n";
        }
        else
        {
            cout << "\nThank You! \n\n";
            return 0;
        }
    }
}

void login()
{
    int count, i = 0;
    string userid, id, pass;
    char ch, password[30];

    cout << "| Please enter the username and password: " << endl;
    cout << "| Username: ";
    cin >> userid;
    cout << "| Password: ";
    do
    {
        ch = getch();
        if (ch != 13)
        {
            password[i] = ch;
            i++;
            cout << "*";
        }

    } while (ch != 13);

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userid && pass == password)
        {
            count = 1;
        }
    }
    input.close();

    if (count == 1)
    {
        cout << endl;
        system("cls");
        cout << "Welcome " << userid << "\nYour LOGIN is succesfull \nThanks for logging in \n\n";
    }
    else
    {
        cout << "\nLOGIN ERROR \nPlease check your username and password\n";
        main();
    }
}

void registration()
{
    string ruserid, rpassword, rid, rpass;
    cout << "| Enter the username: ";
    cin >> ruserid;
    cout << "\n| The password criteria is: ";
    cout << "\n| 1.Atleast one upper case character.";
    cout << "\n| 2.Atleast one lower case character.";
    cout << "\n| 3.Atleast one digit character.";
    cout << "\n| 4.Atleast one special character.";
    while (true)
    {
        cout << "\n| Enter the password: ";
        rpassword = "";
        char ch;
        ch = getch();
        while (ch != 13)
        {
            rpassword.push_back(ch);
            cout << '*';
            ch = getch();
        }

        bool uppercase = false;
        bool lowercase = false;
        bool digit = false;
        bool specialchar = false;

        for (char ch : rpassword)
        {
            if (isupper(ch))
                uppercase = true;
            if (islower(ch))
                lowercase = true;
            if (isdigit(ch))
                digit = true;
            if (!isalnum(ch))
                specialchar = true;
        }

        if (rpassword.length() < 8 || !uppercase || !lowercase || !digit || !specialchar)
        {
            cout << "\n| Password does not meet the strength criteria. Please try again.\n";
        }
        else
        {
            break;
        }
    }

    ofstream f1("records.txt", ios::app);
    f1 << ruserid << ' ' << rpassword << endl;

    cout << "\nRegistration is successfull \n\n\n";
    main();
}

void forgot()
{
    int option;
    cout << "You forgot the password? No Worries \n";
    cout << "Press 1 to search your id by username" << endl;
    cout << "Press 2 to go back to the main menu" << endl;
    cout << "\nEnter your choice: ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserid, sid, spass;
        cout << "\nEnter your username: ";
        cin >> suserid;

        ifstream f2("records.txt");
        while (f2 >> sid >> spass)
        {
            if (sid == suserid)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\nYour account is found! \n";
            cout << "\nYour password is: " << spass << "\n\n";
            main();
        }
        else
        {
            cout << "\nSorry! your account is not found! \n";
            main();
        }
        break;
    }

    case 2:
    {
        main();
    }
    default:
        cout << "| Wrong choice! Please try again" << endl;
        forgot();
    }
}
void aboutus()
{
    ifstream aboutus("aboutus.txt");
    string line2;
    while (getline(aboutus, line2))
    {
        cout << line2 << endl;
    }
}
void features()
{
    ifstream features("features.txt");
    string line1;
    while (getline(features, line1))
    {
        cout << line1 << endl;
    }
}
