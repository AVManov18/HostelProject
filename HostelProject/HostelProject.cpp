#include <iostream>
#include <string>
using namespace std;

struct Login
{
    string Username;
    string Password;
};
struct USER
{
    string firstName;
    string lastName;
    string Address;
    string studentFName;
    string studentLName;
    int studentYears;
};


void Admin(Login& loginData)
{

    cout << "Please insert username: ";
    cin >> loginData.Username;
    cout << endl << "Please insert password: ";
    cin >> loginData.Password;

    while (loginData.Username != "admin" or loginData.Password != "adminpass")
    {
        //checks if the PASSWORD and USERNAME match the password and username given to us
        if (loginData.Username != "admin" or loginData.Password != "adminpass")
        {
            cout << endl << "Wrong username or password! Try Again" << endl;
        }
        cout << endl << "Please insert username: ";
        cin >> loginData.Username;
        cout << endl << "Please insert password: ";
        cin >> loginData.Password;
    }
    cout << endl;
    cout << "    --------------------------     " << endl;
    cout << "             WELCOME!              " << endl;
    cout << "    --------------------------     " << endl;

}
//function to check for the first and last name is there any numbers or symbols in the name
bool isCharacter(string check)
{
    for (int i = 0; i < check.length(); i++)
    {
        if (isalpha(check[i]) == false)
        {
            return true;
        }
    }
    return false;
}

void Register()
{
    USER user[200];
    int numberStudents;
    cout << endl << "Please insert first name: ";
    cin >> user[0].firstName;
    while (isCharacter(user[0].firstName))
    {
        if (isCharacter(user[0].firstName))
        {
            cout << endl << "The name should start with Capital letter and it should contain only letters!" << endl;
        }
        cout << endl << "Please insert first name: ";
        cin >> user[0].firstName;
    }
    cout << endl << "Please insert last name: ";
    cin >> user[0].lastName;
    while (isCharacter(user[0].lastName))
    {
        if (isCharacter(user[0].lastName))
        {
            cout << endl << "The last name should start with Capital letter and it should contain only letters!" << endl;
        }
        cout << endl << "Please insert last name: ";
        cin >> user[0].lastName;
    }
    cout << endl << "Please insert your address WITHOUT SPACES: ";
    cin >> user[0].Address;
    cout << endl << "Please insert number of students: ";
    cin >> numberStudents;
    if (numberStudents > 9 or numberStudents < 1)
    {
        cout << endl << "Please insert number of students between 1 and 9: ";
        for (int i = 0; i < 3; i++)
        {
            cin >> numberStudents;
            if (numberStudents > 9 or numberStudents < 1);
            {

            }
        }
    }




    for (int i = 0; i < numberStudents; i++)
    {
        cout << endl << "Please insert your child first and last name: ";
        cin >> user[i].studentFName;
        cin >> user[i].studentLName;
        cout << endl << "Please insert your child years: ";
        cin >> user[i].studentYears;
        while (user[i].studentYears < 12 or user[i].studentYears>16)
        {
            if (user[i].studentYears < 12)
            {
                cout << "Your kid is under 12 years!" << endl;
            }
            if (user[i].studentYears > 16)
            {
                cout << "Your kid is above 16 years!" << endl;
            }


            cin >> user[i].studentYears;

        }
    }


    for (int i = 0; i < numberStudents; i++)
    {
        cout << endl;
        cout << user[i].studentFName << " " << user[i].studentLName << " " << user[i].studentYears << endl;
    }
}


int main()
{

    Login loginData;
    cout << "-------------------------" << endl;
    cout << "    1.Add new student!   " << endl;
    cout << "    2.Delete student!    " << endl;
    cout << "    3.Edit student data! " << endl;
    cout << "    4.Show all students! " << endl;
    cout << "    5.Search student!    " << endl;
    cout << "    6.Exit               " << endl;
    cout << "-------------------------" << endl;
    cout << "Choose an option: ";
    int option;
    cin >> option;
    while (option > 6 or option < 1)
    {
        if (option > 6 or option < 1)
        {
            cout << "Wrong number. Choose an option again!" << endl;
            cout << endl << "Choose an option: ";
            cin >> option;
        }
    }
    switch (option) {
    case 1:
        Register();
        break;
    case 2:
        cout << "Delete student!";
        break;
    case 3:
        cout << "Edit student data!";
        break;
    case 4:
        cout << "Show all students!";
        break;
    case 5:
        cout << "Search student!";
        break;
    case 6:
        return 0;
    }
}