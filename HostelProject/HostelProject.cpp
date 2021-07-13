#include <iostream>
#include <string>studentName
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct USER
{
    int id;
    string firstName;
    string lastName;
    string username;
    string password;
    string address;
    string studentFName;
    string studentLName;
    int studentYears;
};


void Admin(string UsernName, string pass)
{
    string admin;
    string adminPass;

    cout << "Please insert username: ";
    cin >> admin;
    cout << endl << "Please insert password: ";
    cin >> adminPass;

    while (admin != "admin" or adminPass != "adminpass")
    {
        //checks if the PASSWORD and USERNAME match the password and username given to us
        if (admin != "admin" or adminPass != "adminpass")
        {
            cout << endl << "Wrong username or password! Try Again" << endl;
        }
        cout << endl << "Please insert username: ";
        cin >> admin;
        cout << endl << "Please insert password: ";
        cin >> adminPass;
    }
    cout << endl;
    cout << setw(70) << "    --------------------------     " << endl;
    cout << setw(70) << "             WELCOME!              " << endl;
    cout << setw(70) << "    --------------------------     " << endl;

}





/*=========CRUD=========*/
int getUserId(USER* users, int& userCount, int id) //Gets user's index by using the id of the user
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

void registerUser(USER* users, int& userCount, int& maxId, USER newUsers) // adds new user to the main list (the array)
{
    users[userCount] = newUsers;
    newUsers.id = maxId++;
    userCount++;
}

void modifyUser(USER* users, int userCount, int id, USER newUsers) //edits the data of the user
{
    int index = getUserId(users, userCount, id);
    users[index] = newUsers;
}

void deleteUser(USER* users, int& usersCount, int id) // "deletes" user
{
    int index = getUserId(users, usersCount, id);

    for (int i = index; i < usersCount - 1; i++)
    {
        users[i] = users[i + 1];
    }
    usersCount--;
}

USER getUser(USER* users, int& userCount, int id) // finds product by its index
{
    int index = getUserId(users, userCount, id);
    return users[index];
}

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
/*======================*/




void enterUserMenu(USER* users, int& userCount, int& maxId) //dislays the menu that help the admin to enter user's data
{
    USER user;
    int numberStudents;
    cout << "Enter the id of the parent: "; cin >> user.id;
    cout << endl << "Please insert first name of the parent: "; cin >> user.firstName;
    while (isCharacter(user.firstName))
    {
        if (isCharacter(user.firstName))
        {
            cout << endl << "The name should be only from letters! ";
        }
        cout << endl << "Please insert first name of the parent: "; cin >> user.firstName;
    }
    cout << endl << "Please insert last name of the parent: "; cin >> user.lastName;
    while (isCharacter(user.lastName))
    {
        if (isCharacter(user.lastName))
        {
            cout << endl << "The last name should be only from letters! " ;
        }
        cout << endl << "Please insert last name of the parent: "; cin >> user.lastName;
    }
    cout << "Enter the username of the parent: "; cin >> user.username; cout << endl;
    cout << "Enter the password of the parent: "; cin >> user.password;

    cout << endl << "Please insert your address WITHOUT SPACES: "; cin >> user.address;
    cout << endl << "Please insert number of students: "; cin >> numberStudents;
    if (numberStudents > 9 or numberStudents < 1)
    {
        cout << endl << "Please insert number of students between 1 and 9: ";
        for (int i = 0; i < 3; i++)
        {
            cin >> numberStudents;
        }
    }
    for (int i = 0; i < numberStudents; i++)
    {
        cout << endl << "Please insert your child first name: "; cin >> user.studentFName;
        cout << endl << "Please insert your child last name: "; cin >> user.studentLName;
        cout << endl << "Please insert your child years: "; cin >> user.studentYears;
        while (user.studentYears < 12 or user.studentYears>16)
        {
            if (user.studentYears < 12)
            {
                cout << "Your kid is under 12 years!" << endl;
            }
            if (user.studentYears > 16)
            {
                cout << "Your kid is above 16 years!" << endl;
            }
            cin >> user.studentYears;

        }
    }
    registerUser(users, userCount, maxId, user);
    cout << "You are ready! The user has been added to your list!" << endl;
}

void showUserMenu(USER* users, int& userCount, int& maxId) // shows all current saved users' data to the admin
{
    cout << endl << "List of the entered users:" << endl;
    for (int i = 0; i < userCount; i++)
    {
        cout << endl << "Id: " << users[i].id << endl;
        cout << endl << "First name: " << users[i].firstName << endl;
        cout << endl << "Last name: " << users[i].lastName << endl;
        cout << endl << "Username: " << users[i].username << endl;
        cout << endl << "Password: " << users[i].password << endl;
        cout << endl << "Address:" << users[i].address << endl;
        cout << endl << "Student name:" << users[i].studentFName << endl;
        cout << endl << "Student name:" << users[i].studentLName << endl;
        cout << endl << "Student years:" << users[i].studentYears << endl;
        cout << endl;
    }
}

void editMenu(USER* users, int& userCount) //displays the menu that help the admin to edit data of a user
{
    int userId;

    cout << "Please enter the id of the user that you want to edit: ";
    cin >> userId;

    USER user = getUser(users, userCount, userId);

    cout << endl << "1.Id: " << endl;
    cout << endl << "2.First name of the parent: " << endl;
    cout << endl << "3.Last name of the parent: " << endl;
    cout << endl << "4.Username: " << endl;
    cout << endl << "5.Password: " << endl;
    cout << endl << "6.Address: " << endl;
    cout << endl << "7.Student first name: " << endl;
    cout << endl << "8.Student last name: " << endl;
    cout << endl << "9.Student years " << endl;
    cout << endl << "What do you want to edit: " << endl;

    int choose;
    cin >> choose;

    switch (choose)
    {
    case 1:
        cout << "Enter new ID: ";
        cin >> user.id;
        modifyUser(users, userCount, userId, user);
        break;
    case 2:
        cout << "Enter new first name of the parent: ";
        cin >> user.firstName;
        modifyUser(users, userCount, userId, user);
        break;
    case 3:
        cout << "Enter new last name of the parent: ";
        cin >> user.lastName;
        modifyUser(users, userCount, userId, user);
        break;
    case 4:
        cout << "Enter new username: ";
        cin >> user.username;
        modifyUser(users, userCount, userId, user);
        break;
    case 5:
        cout << "Enter new pasword: ";
        cin >> user.password;
        modifyUser(users, userCount, userId, user);
        break;
    case 6:
        cout << "Enter new address: ";
        cin >> user.address;
        modifyUser(users, userCount, userId, user);
        break;
    case 7:
        cout << "Enter new student first name: ";
        cin >> user.studentFName;
        modifyUser(users, userCount, userId, user);
        break;
    case 8:
        cout << "Enter new student last name: ";
        cin >> user.studentLName;
        modifyUser(users, userCount, userId, user);
        break;
    case 9:
        cout << "Enter new student years: ";
        cin >> user.studentYears;
        modifyUser(users, userCount, userId, user);
        break;

    default:
        cout << "Invalid input!" << endl;
    }
    cout << "You are ready! The user has been edited in the list!" << endl;
}

void deleteUserMenu(USER* users, int& userCount, int& maxId) //displays a menu that help the admin to delete a whole user
{
    int userId;

    cout << "Please enter the id of the user that you want to delete: ";
    cin >> userId;
    deleteUser(users, userCount, userId);

    cout << "The user has been removed from the list!" << endl;
}


/*=====PRESENTATION LAYER=====*/

bool MainMenu(USER* users, int& usersCount, int& id) // diplsays main menu of the program
{
    int choice;
    cout << setw(70) << "-----------------------------" << endl;
    cout << setw(62) << "  ADMIN MENU:" << endl;
    cout << setw(60) << "1.Enter user" << endl;
    cout << setw(64) << "2.View all users" << endl;
    cout << setw(59) << "3.Edit user" << endl;
    cout << setw(61) << "4.Delete user" << endl;
    cout << setw(54) << "5.Exit" << endl;
    cout << setw(70) << "-----------------------------" << endl;
    cout << endl << "Choose an option: ";
    cin >> choice;
    while (choice > 5 or choice < 1)
    {
        if (choice > 5 or choice < 1)
        {
            cout << "Wrong number. Choose an choice again!" << endl;
            cout << endl << "Choose an another option: ";
            cin >> choice;
        }
    }
    switch (choice) {
    case 1: {
        enterUserMenu(users, usersCount, id);
        break;
    }
    case 2: {
        showUserMenu(users, usersCount, id);
        break;
    }
    case 3: {
        editMenu(users, usersCount);
        break;
    }
    case 4: {
        deleteUserMenu(users, usersCount, id);
        break;
    }

    case 5: {
        return false;
    }

    default:
        break;

    }
}

/*===================================================*/
int main() // the main function of the project
{

    int customerCount = 0;
    int maxId = 1;
    USER customers[100];

    bool mainMenu = true;
    string admin;
    string adminpass;
    Admin(admin, adminpass);
    if (Admin)
    {
        do {
            mainMenu = MainMenu(customers, customerCount, maxId);
        } while (mainMenu);
    }
}
