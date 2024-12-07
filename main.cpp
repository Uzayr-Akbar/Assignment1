/*
 * Name: Mohammed Uzayr Akbar
 * Student ID: 21271979
 * Note: This program was developed on macOS using the cLion IDE.
 * some features may not work on widnwos such as some system commands.
 */
#include <iostream>
#include <iomanip> // using this library to format/config console outputs
#include <cstdlib> // using this library for the exit function.
using namespace std;
// variable declaration...
const float toppingsPrices[] = {1.00, 0.40, 0.50, 0.75, 1.20, 0.80, 0.40, 1.50};
double balance = 0.0; // global variable for the balance. global so that it can be accessed by all functions.
int menuNav;
int toppings;
char additionalToppings;
char extras;
double totalPrice;
double creditAdd;
char yesNo; // variable for the yes or no input. global so that it can be accessed by all functions.

 //Function declarations...
void DrawLine();
void DisplayMenu();
void MenuChoiceLoop();
void newOrder();
void addCredits();
void pauseSys();
int closeApp();
void yesNoValidation();
void totalPriceDisplay();
void toppingsSelect();
void handleMenuOption();
void extraSelect();

// Function definitions...

// Functions that arent being modified...

// ====================================
void DrawLine() {
    cout << "=======================================================================" << endl;
}

int closeApp() {
    exit(0); //terminate program.
}

void pauseSys() {
    cout << "press enter to continue..." << endl;
    cin.ignore(100, '\n');
    cin.get();
}

// ====================================


void handleMenuOption() {
    switch (toppings) {
        case 1: DrawLine();
        cout << "you have chosen Cheese as your topping..." << endl;
        totalPrice += toppingsPrices[0];
        totalPriceDisplay();
        break;

        case 2: DrawLine();
        cout << "you have chosen Butter as your topping..." << endl;
        totalPrice += toppingsPrices[1];
        totalPriceDisplay();
        break;

        case 3: DrawLine();
        cout << "you have chosen Garlic Butter as your topping..." << endl;
        totalPrice += toppingsPrices[2];
        totalPriceDisplay();
        break;

        case 4: DrawLine();
        cout << "you have chosen Beans as your topping..." << endl;
        totalPrice += toppingsPrices[3];
        totalPriceDisplay();
        break;

        case 5: DrawLine();
        cout << "you have chosen Curry Sauce as your topping..." << endl;
        totalPrice += toppingsPrices[4];
        totalPriceDisplay();
        break;

        case 6: DrawLine();
        cout << "you have chosen Mushrooms as your topping..." << endl;
        totalPrice += toppingsPrices[5];
        totalPriceDisplay();
        break;

        case 7: DrawLine();
        cout << "you have chosen Onions as your topping..." << endl;
        totalPrice += toppingsPrices[6];
        totalPriceDisplay();
        break;

        case 8: DrawLine();
        cout << "you have chosen Extra Special Cheese as your topping..." << endl;
        totalPrice += toppingsPrices[7];
        totalPriceDisplay();
        break;

        default: closeApp();
    }
}

void extraSelect() {
    DrawLine();
    cout << "Extras" << endl;
    cout << endl;
}

void toppingsSelect() {
    cout << "Toppings" << endl;
    DrawLine(); // arrays count from 0 not 1....
    cout << left << setw(25) << "1. Cheese" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[0] << endl;
    cout << left << setw(25) << "2. Butter" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[1] << endl;
    cout << left << setw(25) << "3. Garlic Butter"<< "    Cost: £" << setprecision(2) << fixed << toppingsPrices[2] << endl;
    cout << left << setw(25) << "4. Beans" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[3] << endl;
    cout << left << setw(25) << "5. Curry Sauce" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[4] << endl;
    cout << left << setw(25) << "6. Mushrooms" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[5] << endl;
    cout << left << setw(25) << "7. Onions" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[6] << endl;
    cout << left << setw(25) << "8. Extra Special Cheese" << "    Cost: £" << setprecision(2) << fixed << toppingsPrices[7] << endl;
    DrawLine();
     /*I used the iomanip library to stop the length of the topping name affecting the positioning
     of each topping making the output look much more pleasant
     the setprecision(2) means that it is precise to 2 deimal points and the "fixed" means that its after the decimal points and not before.
     */
    cout << "Choose a topping" << endl;
    cin >> toppings;
    while (toppings < 1 || toppings > 8 || cin.fail() ) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout <<"invalid choice. Please enter a number from 1-8" << endl;
        cin >> toppings;
    }
    handleMenuOption();
}

void totalPriceDisplay() {
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

void DisplayMenu() {
    // Function that displays the menu.
    DrawLine();
    cout << "Welcome to the Hot Potato!!!" << endl;
    DrawLine();
    cout << "1. Add credits/View Balance." << endl; // Displays credits available to the user and gives user option to add credits
    cout << "2. New order." << endl; // Allows the user to start a new order.
    cout << "3. Exit." << endl; // Closes the app.
    DrawLine();
    cout << "Enter your choice: "; // input for the user to enter their choice for what they would like to do.
    cin >> menuNav;
    while (menuNav > 3 || menuNav < 1 || cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid choice. Please enter a valid choice: "<< endl;
        cin >> menuNav;
    }
    // MenuChoiceLoop(); // Calls the function MenuChoiceLoop so that the user can navigate through the menu.
}

void MenuChoiceLoop() // Function that loops the menu choices.
{
    cin.clear();
    cin.ignore(1000, '\n');
    switch (menuNav) {
        case 1: addCredits();
        break;

        case 2: newOrder();
        break;

        case 3: closeApp();
        break;

        default: cout << "invalid input. Session terminated!" << endl;
    }
}

void addCredits() // Function that allows the user to add credits to their balance.
{
    DrawLine();
    cout << "Your credit balance is £" << balance << endl;
    DrawLine();
    cout << "Enter the amount you would like to add: " << endl;
    cin >> creditAdd;
    balance += creditAdd;
    DrawLine();
    cout << "Your new balance is £" << balance << endl;
    pauseSys();
    system("clear"); // Clears the screen. (For Windows use system("cls")) for demonstration.
    DisplayMenu();
}

void newOrder() //  Main Function that allows the user to select the size of the potato and toppings/extras.
        {
        // Local Variable Declaration...
        // PotatoeSizePrices...
        int potatoSize;
        double smallPotatoCost = 5.0;
        double mediumPotatoCost = 8.50;
        double largePotatoCost = 10.25;
        // ToppingsPriceVariables...
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
        switch (potatoSize)
        {
            case 1: // code that is executed if the user chooses option 1
                totalPrice += smallPotatoCost;
            toppingsSelect();
            case 2: // code that is executed if the user chooses option 2.
                totalPrice += mediumPotatoCost;
            toppingsSelect();
            case 3: // code that is executed if the user chooses option3.
                totalPrice += largePotatoCost;
            toppingsSelect();
            default: closeApp();
        }
        }

int main() {
    DisplayMenu(); // Displays the menu by getting the function DisplayMenu.
    MenuChoiceLoop(); // Loops through the menu choices.
}