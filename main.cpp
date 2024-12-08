#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
const float extrasPrices[] = {1.50, 4.00, 1.20, 0.80, 1.00, 1.20};
const float toppingsPrices[] = {1.00, 0.40, 0.50, 0.75, 1.20, 0.80, 0.40, 1.50};
char yesNo; // variable for the yes or no input. global so that it can be accessed by all functions.

// Function declarations...
void DrawLine();
void DisplayMenu(int &menuNav);
void MenuChoiceLoop(int menuNav, double &totalPrice);
void newOrder(double &totalPrice);
void addCredits();
void pauseSys();
int closeApp();
void yesNoValidation();
void totalPriceDisplay(double totalPrice);
void toppingsSelect(double &totalPrice);
void handleMenuOption(int toppings, double &totalPrice);
void extraSelect();
// Function definitions...

void DrawLine() {
    cout << "=======================================================================" << endl;
}

int closeApp() {
    exit(0);
}

void pauseSys() {
    cout << "press enter to continue..." << endl;
    cin.ignore(100, '\n');
    cin.get();
}

void handleMenuOption(int toppings, double &totalPrice) {
    switch (toppings) {
        case 1: DrawLine();
        cout << "you have chosen Cheese as your topping..." << endl;
        totalPrice += toppingsPrices[0];
        totalPriceDisplay(totalPrice);
        break;

        case 2: DrawLine();
        cout << "you have chosen Butter as your topping..." << endl;
        totalPrice += toppingsPrices[1];
        totalPriceDisplay(totalPrice);
        break;

        case 3: DrawLine();
        cout << "you have chosen Garlic Butter as your topping..." << endl;
        totalPrice += toppingsPrices[2];
        totalPriceDisplay(totalPrice);
        break;

        case 4: DrawLine();
        cout << "you have chosen Beans as your topping..." << endl;
        totalPrice += toppingsPrices[3];
        totalPriceDisplay(totalPrice);
        break;

        case 5: DrawLine();
        cout << "you have chosen Curry Sauce as your topping..." << endl;
        totalPrice += toppingsPrices[4];
        totalPriceDisplay(totalPrice);
        break;

        case 6: DrawLine();
        cout << "you have chosen Mushrooms as your topping..." << endl;
        totalPrice += toppingsPrices[5];
        totalPriceDisplay(totalPrice);
        break;

        case 7: DrawLine();
        cout << "you have chosen Onions as your topping..." << endl;
        totalPrice += toppingsPrices[6];
        totalPriceDisplay(totalPrice);
        break;

        case 8: DrawLine();
        cout << "you have chosen Extra Special Cheese as your topping..." << endl;
        totalPrice += toppingsPrices[7];
        totalPriceDisplay(totalPrice);
        break;

        default: closeApp();
    }
}

void extraSelect(double &totalPrice) {
int extra;
    cout << "Extras" << endl;
    DrawLine();
    cout << left << setw(25) << "1. Salad Box" << "    Cost: £" << setprecision(2) << fixed << extrasPrices[0] << endl;
    cout << left << setw(25) << "2. Hot Dog" << "    Cost: £" << setprecision(2) << fixed << extrasPrices[1] << endl;
    cout << left << setw(25) << "3. Can of Fizzy Drink" << "    Cost: £" << setprecision(2) << fixed << extrasPrices[2] << endl;
    cout << left << setw(25) << "4. Bottle of Water" << "    Cost: £" << setprecision(2) << fixed << extrasPrices[3] << endl;
    cout << left << setw(25) << "5. Tea" << "    Cost: £" << setprecision(2) << fixed << extrasPrices[4] << endl;
    cout << left << setw(25) << "6. Coffee" << "    Cost: £" << setprecision(2) << fixed << extrasPrices[5] << endl;
    DrawLine();
    cout << "Choose an extra [1-6]" << endl;
    cin >> extra;
    while (extra < 1 || extra > 6 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout <<"invalid choice. Please enter a number from 1-6" << endl;
        cin >> extra;
    }
    switch (extra) {
        case 1: DrawLine();
        cout << "you have chosen Salad Box as your extra..." << endl;
        totalPrice += extrasPrices[0];
        totalPriceDisplay(totalPrice);
        break;
        case 2: DrawLine();
        cout << "you have chosen Hot Dog as your extra..." << endl;
        totalPrice += extrasPrices[1];
        totalPriceDisplay(totalPrice);
        break;
        case 3: DrawLine();
        cout << "you have chosen Can of Fizzy Drink as your extra..." << endl;
        totalPrice += extrasPrices[2];
        totalPriceDisplay(totalPrice);
        break;
        case 4: DrawLine();
        cout << "you have chosen Bottle of Water as your extra..." << endl;
        totalPrice += extrasPrices[3];
        totalPriceDisplay(totalPrice);
        break;
        case 5: DrawLine();
        cout << "you have chosen Tea as your extra..." << endl;
        totalPrice += extrasPrices[4];
        totalPriceDisplay(totalPrice);
        break;
        case 6: DrawLine();
        cout << "you have chosen Coffee as your extra..." << endl;
        totalPrice += extrasPrices[5];
        totalPriceDisplay(totalPrice);
    }
}
void toppingsSelect(double &totalPrice) {
    int toppings;
    cout << "Toppings" << endl;
    DrawLine();
    cout << left << setw(25) << "1. Cheese" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[0] << endl;
    cout << left << setw(25) << "2. Butter" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[1] << endl;
    cout << left << setw(25) << "3. Garlic Butter"<< "    Cost: £" << setprecision(2) << fixed << toppingsPrices[2] << endl;
    cout << left << setw(25) << "4. Beans" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[3] << endl;
    cout << left << setw(25) << "5. Curry Sauce" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[4] << endl;
    cout << left << setw(25) << "6. Mushrooms" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[5] << endl;
    cout << left << setw(25) << "7. Onions" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[6] << endl;
    cout << left << setw(25) << "8. Extra Special Cheese" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[7] << endl;
    DrawLine();
    cout << "Choose a topping" << endl;
    cin >> toppings;
    while (toppings < 1 || toppings > 8 || cin.fail() ) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout <<"invalid choice. Please enter a number from 1-8" << endl;
        cin >> toppings;
    }
    handleMenuOption(toppings,  totalPrice);
    cout << "Would you like to choose an extra?" << endl;
    cout << "Enter 'y' for yes or 'n' for no: " << endl;
    cin >> yesNo;
    yesNoValidation();
    if (yesNo == 'y' || yesNo == 'Y') {
        extraSelect(totalPrice);
    } else
        {
        cout << "Thank you for your order!" << endl;
        pauseSys();
        system("clear");
    }
}

void totalPriceDisplay(double totalPrice) {
    DrawLine();
    cout << "The current total price is: £" << setprecision(2) << fixed << totalPrice << endl;
    DrawLine();
}

void yesNoValidation() {
    while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N' || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid choice. Please enter a valid choice: ";
        cin >> yesNo;
    }
}

void DisplayMenu(int &menuNav) {
    DrawLine();
    cout << "Welcome to the Hot Potato!!!" << endl;
    DrawLine();
    cout << "1. Add credits/View Balance." << endl;
    cout << "2. New order." << endl;
    cout << "3. Exit." << endl;
    DrawLine();
    cout << "Enter your choice: ";
    cin >> menuNav;
    while (menuNav > 3 || menuNav < 1 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid choice. Please enter a valid choice: "<< endl;
        cin >> menuNav;
    }
}

void MenuChoiceLoop(int menuNav, double &totalPrice) {
    cin.clear();
    cin.ignore(1000, '\n');
    switch (menuNav) {
        case 1: addCredits();
        break;

        case 2: newOrder(totalPrice);
        break;

        case 3: closeApp();
        break;

        default: cout << "invalid input. Session terminated!" << endl;
    }
}

void addCredits() {
    double balance = 0.0;
    double creditAdd;
    DrawLine();
    cout << "Your credit balance is £" << balance << endl;
    DrawLine();
    cout << "Enter the amount you would like to add: " << endl;
    cin >> creditAdd;
    balance += creditAdd;
    DrawLine();
    cout << "Your new balance is £" << balance << endl;
    pauseSys();
    system("clear");
}

void newOrder(double &totalPrice) {
    int potatoSize;
    double smallPotatoCost = 5.0;
    double mediumPotatoCost = 8.50;
    double largePotatoCost = 10.25;
    DrawLine();
    cout << "Enter the size you would like: " << endl;
    cout << left << setw(20) << "1. Small Potato" << "    Cost: £" << setprecision(2) << fixed << smallPotatoCost << endl;
    cout << left << setw(20) << "2. Medium Potato" << "    Cost: £" << setprecision(2) << fixed << mediumPotatoCost << endl;
    cout << left << setw(20) << "3. Large Potato" << "    Cost: £" << setprecision(2) << fixed << largePotatoCost << endl;
    DrawLine();
    cout << "Enter your choice: ";
    cin >> potatoSize;
    while (potatoSize > 3 || potatoSize < 1 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid choice. Please enter a valid choice: ";
        cin >> potatoSize;
    }
    switch (potatoSize) {
        case 1:
            totalPrice += smallPotatoCost;
            toppingsSelect(totalPrice);
            break;
        case 2:
            totalPrice += mediumPotatoCost;
            toppingsSelect(totalPrice);
            break;
        case 3:
            totalPrice += largePotatoCost;
            toppingsSelect(totalPrice);
            break;
        default: closeApp();
    }
}

int main() {
    double totalPrice = 0.0;
    int menuNav;
    DisplayMenu(menuNav);
    MenuChoiceLoop(menuNav, totalPrice);
}