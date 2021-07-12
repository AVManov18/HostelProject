#include <iostream>
#include <string>
#include <iomanip>
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
    int id;
};
int getUserId(USER* users, int& userCount, int id) 
{
    for (int i = 0; i < userCount; i++)
    {
        if (users[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

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
    cout << setw(70) << "    --------------------------     " << endl;
    cout << setw(70) << "             WELCOME!              " << endl;
    cout << setw(70) << "    --------------------------     " << endl;

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

void Register(USER* users)
{
    USER user[50];
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
            if (numberStudents > 9 or numberStudents < 1)
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


void deleteUser(USER* users, int& usersCount, int id) // Function that delete user by id
{
    int index = getUserId(users, usersCount, id);

    for (int i = index; i < usersCount - 1; i++)
    {
        users[i] = users[i + 1];
    }
}
void deleteUserMenu(USER* users, int& userCount, int& maxId) //displays a menu that delete a user
{
    int userId;

    cout << endl << "Enter Id of the student: ";
    cin >> userId;

    deleteUser(users, userCount, userId);

    cout << endl << "The student has been removed!" << endl;
}
bool MainMenu( USER* users, int& usersCount, int& id) // diplsays main menu of the program
{
    int maxId = 1;
    Login loginData;
    int userCount = 0;
    int option;
    cout << setw(70) << "-----------------------------" << endl;
    cout << setw(56) << "   1. Register" << endl;
    cout << setw(62) << "   2. Login as admin" << endl;
    cout << setw(52) << "   3. Exit" << endl;
    cout << setw(70) << "-----------------------------" << endl;
    cout << setw(62) << "Choose an option: ";
    cin >> option;
    while (option > 3 or option < 1)
    {
        if (option > 3 or option < 1)
        {
            cout << "Wrong number. Choose an option again!" << endl;
            cout << endl << "Choose an option: ";
            cin >> option;
        }
    }
    switch (option)
    {
    case 1:
        Register(users);
        break;
    case 2:
        Admin(loginData);
        int admopt;
        cout << setw(70) << "----------------------------" << endl;
        cout << setw(64) << "   1. Add new student" << endl;
        cout << setw(64) << "   2. Delete student!" << endl;
        cout << setw(67) << "   3. Edit student data!" << endl;
        cout << setw(67) << "   4. Show all students!" << endl;
        cout << setw(64) << "   5. Search student!" << endl;
        cout << setw(54) << "   6. Exit!" << endl;
        cout << setw(70) << "----------------------------" << endl;
        cout << setw(64) << "Choose an option: ";
        cin >> admopt;
        while (admopt > 6 or admopt < 1)
        {
            if (admopt > 6 or admopt < 1)
            {
                cout << "Wrong number. Choose an option again!" << endl;
                cout << endl << "Choose an option: ";
                cin >> admopt;
            }
        }
        switch (admopt)
        {
        case 1:
            Register(users);
            break;
        case 2:
            deleteUserMenu(users,userCount, id);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            return 0;
        }
    case 3:
        return 0;


    }
}

int main()
{
    Login loginData;
    int usersCount = 0;
    int maxId = 1;

    USER users[100];
    do
    {
        MainMenu(users, usersCount, maxId);
    } while (MainMenu);
}