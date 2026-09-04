// COMSC-210-5293 | Lab 3 | Yuyi Chen

#include <iostream>
#include <string>
using namespace std;

// Define a structure to hold restaurant information
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
    // Create an array of 4 Restaurant structures
    Restaurant restaurant[4];
    for (int i = 0; i < 4; i++) {
        cout << "\nEnter information for restaurant #" << (i + 1) << ":\n";
        restaurant[i] = populateRestaurant();
    }

    // Display the information for each restaurant
    for (int i = 0; i < 4; i++) {
        cout << "\nDisplaying information for restaurant #" << (i + 1) << ":\n";
        displayRestaurant(restaurant[i]);
    }
    return 0;
}

// Function to populate a Restaurant structure with user input
Restaurant populateRestaurant() {
    Restaurant temp;
    char entry;

    // Get restaurant name
    cout << "Enter the restaurant name: ";
    getline(cin, temp.name);

    // Get restaurant address
    cout << "Enter the restaurant address: ";
    getline(cin, temp.address);

    // Get restaurant rating
    cout << "Enter the restaurant rating (0.0 - 5.0): ";
    cin >> temp.rating;
    // Validate input for rating
    while (temp.rating < 0.0 || temp.rating > 5.0) {
        cout << "Invalid input. Please enter a rating between 0.0 and 5.0: ";
        cin >> temp.rating;
    }

    // Get restaurant price level
    cout << "Enter the restaurant price level (1 - 4): ";
    cin >> temp.priceLevel;
    // Validate input for price level
    while (temp.priceLevel < 1 || temp.priceLevel > 4) {
        cout << "Invalid input. Please enter a price level between 1 and 4: ";
        cin >> temp.priceLevel;
    }

    // Get restaurant parking availability
    cout << "Is parking available? (Y/N): ";
    cin >> entry;
    entry = toupper(entry);
    // Validate input for parking availability
    while (entry != 'Y' && entry != 'N') {
        cout << "Invalid input. Please enter Y or N: ";
        cin >> entry;
        entry = toupper(entry);
    }
    temp.parkingAvailable = entry == 'Y' ? true : false;

    // Get restaurant takeout availability
    cout << "Is takeout available? (Y/N): ";
    cin >> entry;
    entry = toupper(entry);
    // Validate input for takeout availability
    while (entry != 'Y' && entry != 'N') {
        cout << "Invalid input. Please enter Y or N: ";
        cin >> entry;
        entry = toupper(entry);
    }
    temp.takeoutAvailable = entry == 'Y' ? true : false;

    // Clear the input buffer to avoid issues with getline in the next iteration
    cin.ignore();

    return temp;
}

// Function to display the information of a Restaurant structure
void displayRestaurant(const Restaurant& restaurant) {
    // Display restaurant information
    cout << "\nRestaurant Information:\n";

    // Display the restaurant name
    cout << "Name: " << restaurant.name << endl;

    // Display the restaurant address
    cout << "Address: " << restaurant.address << endl;

    // Display the restaurant rating
    cout << "Rating: " << restaurant.rating << endl;

    // Display the restaurant price level
    cout << "Price Level: ";
    // Display dollar signs based on the price level
    for (int i = 0; i < restaurant.priceLevel; i++) {
        cout << "$";
    }
    cout << endl;

    // Display restaurant parking availability
    cout << "Parking Available: " << (restaurant.parkingAvailable ? "Yes" : "No") << endl;

    // Display restaurant takeout availability
    cout << "Takeout Available: " << (restaurant.takeoutAvailable ? "Yes" : "No") << endl;
}