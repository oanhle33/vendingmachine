//airbnb
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Menu{
    char  name[25]; // room for a 24-character name, plus one for the '\0'
    float price;
    unsigned quantity;
};
void printMenu(Menu *k){
    for ( int i = 0; i < 5; i++){
        // The . operator ("dot" or member-of) says the thing on the left is a
        // struct and the thing on the right is the field of the struct. It
        // evaluates to the field as either an L-value or an R-value.
        // use -> for pointer
        cout << "\n" << i + 1 <<") " << k->name <<"\t\t" << k->price << "\t(" << k->quantity << ") remaining";
        k++;
    }
}
void void_drink(){
  cout << "\nYou selected softdrinks\n";
  cout << "Here are the available softdrinks\n";
}
void void_cookies(){
  cout << "You selected cookies\n";
  cout << "Here are the available cookies\n";
}
void validateChoice(Menu *p, int &choice2){
    cout << "\n\nChoose one: ";
    cin >> choice2;
    //validate the input
    while ( choice2 == 0 || choice2 > 5){
        //Error
        cout << "Please enter number from 1 to 5";
        cout << "\n\nChoose one: ";
        cin >> choice2;
    }
    while(p[choice2-1].quantity == 0){
        //Explain the error
        cout << "Out of stock \n";
        cout << "Please choose the other ones! \n";
        //Get the input
        cout << "Choose one: ";
        cin >> choice2;
    }
}

void calMoney(Menu *c,float &money,int &choice2){
    cout << "\nEnter any amount of money: ";
    cin >> money;
    //Validate the input money
    while (money < c[choice2 - 1].price){
        cout << "There is not enough money.\n";
        cout << "Please insert money again! \n";
        cout << "Enter any amount of money: ";
        cin >> money;
    }
}

void printCongrats(Menu *a,int money,int choice2){
    cout<<"\nEnjoy! ";
    cout<<"\n\nChange calculated: " << money - a[choice2 - 1].price;
    cout<<"\nYour change, " << money - a[choice2 - 1].price <<
          " just dropped into the Change Dispenser." << endl;
}

int main()
{
    Menu softdrinks[5], cookies[5];
    strcpy(softdrinks[0].name,"Cream Soda"); softdrinks[0].price=0.75; softdrinks[0].quantity=0;
    strcpy(softdrinks[1].name,"Root Beer"); softdrinks[1].price=0.75; softdrinks[1].quantity=20;
    strcpy(softdrinks[2].name,"Lemon Lime"); softdrinks[2].price=0.75; softdrinks[2].quantity=20;
    strcpy(softdrinks[3].name,"Grape Soda"); softdrinks[3].price=0.80; softdrinks[3].quantity=20;
    strcpy(softdrinks[4].name,"Coca Cola"); softdrinks[4].price=0.80; softdrinks[4].quantity=20;

    strcpy(cookies[0].name,"Shortbread"); cookies[0].price=6.75; cookies[0].quantity=0;
    strcpy(cookies[1].name,"Biscotti"); cookies[1].price=7.75; cookies[1].quantity=20;
    strcpy(cookies[2].name,"Gingerbread"); cookies[2].price=8.75; cookies[2].quantity=22;
    strcpy(cookies[3].name,"Chocolate"); cookies[3].price=9.80; cookies[3].quantity=20;
    strcpy(cookies[4].name,"Macaroon"); cookies[4].price=10.80; cookies[4].quantity=20;

    string choice1; //variable hold the letter for drinks,and cookies.
    int choice2;   // variable hole the the number for different types under drinks and cookies.

    cout << "Welcome to the vending machine!\n\n";
    float money;
    while (bool loop = true){
        cout << "Enter A for soft drinks, B for cookies: ";
        cin >> choice1;
        if (choice1 == "A" || choice1 == "a"){
                void_drink();
                printMenu(softdrinks);
                validateChoice(softdrinks,choice2);
                calMoney(softdrinks, money ,choice2);
                printCongrats(softdrinks, money,choice2);
                loop == false;
        } else if (choice1 == "B" || choice1 == "b"){
            void_cookies();
            printMenu(cookies);
            validateChoice(cookies,choice2);
            calMoney(cookies, money,choice2);
            printCongrats(cookies, money,choice2);
            loop == false;
        } else{
            cout << "You entered something else, please try again! \n";
            loop == true;
        }
    }
    return 0;
}

