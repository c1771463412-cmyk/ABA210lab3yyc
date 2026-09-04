// COMSC-210-5293 | Lab 3 | Yuyi Chen

#include <iostream>
#include <string>
using namespace std;

struct Restaurant
{
    string name;
    string address;
    double rating;
    int priceLevel;
    bool parkingAvailable;
    bool takeoutAvailable;
};

Restaurant populateRestaurant();
void displayRestaurant(const Restaurant& restaurant);

int main()
{
    Restaurant restaurant1 = populateRestaurant();
    displayRestaurant(restaurant1);
    return 0;
}

Restaurant populateRestaurant() {
    Restaurant temp;
    char entry;

    cout << "Enter the restaurant name: ";
    getline(cin, temp.name);

    cout << "\nEnter the restaurant address: ";
    getline(cin, temp.address);

    cout << "\nEnter the restaurant rating (0.0 - 5.0): ";
    cin >> temp.rating;
    while (temp.rating < 0.0 || temp.rating > 5.0) {
        cout << "Invalid input. Please enter a rating between 0.0 and 5.0: ";
        cin >> temp.rating;
    }

    cout << "\nEnter the restaurant price level (1 - 4): ";
    cin >> temp.priceLevel;
    while (temp.priceLevel < 1 || temp.priceLevel > 4) {
        cout << "Invalid input. Please enter a price level between 1 and 4: ";
        cin >> temp.priceLevel;
    }

    cout << "\nIs parking available? (Y/N): ";
    cin >> entry;
    entry = toupper(entry);
    while (entry != 'Y' && entry != 'N') {
        cout << "Invalid input. Please enter Y or N: ";
        cin >> entry;
        entry = toupper(entry);
    }
    temp.parkingAvailable = entry == 'Y' ? true : false;

    cout << "\nIs takeout available? (Y/N): ";
    cin >> entry;
    entry = toupper(entry);
    while (entry != 'Y' && entry != 'N') {
        cout << "Invalid input. Please enter Y or N: ";
        cin >> entry;
        entry = toupper(entry);
    }
    temp.takeoutAvailable = entry == 'Y' ? true : false;

    return temp;
}

void displayRestaurant(const Restaurant& restaurant) {
    cout << "\nRestaurant Information:\n";
    cout << "Name: " << restaurant.name << endl;
    cout << "\nAddress: " << restaurant.address << endl;
    cout << "\nRating: " << restaurant.rating << endl;
    cout << "\nPrice Level: " << restaurant.priceLevel << endl;
    cout << "\nParking Available: " << (restaurant.parkingAvailable ? "Yes" : "No") << endl;
    cout << "\nTakeout Available: " << (restaurant.takeoutAvailable ? "Yes" : "No") << endl;
}