#include <iostream>   // For input-output operations
#include <cmath>      // For math operations like ceil
#include <string>     // For using strings

using namespace std;

// Constants representing various costs
const double CostPerHour = 18.50;      
const double CostPerMinute = 0.40;     
const double CostOfDinner = 20.70;   

 class Event 
 
 {
private:
    // Private member variables to store event and guest details
    string eventName;      // Name of the event
    string firstName;      // Host's first name
    string lastName;       // Host's last name
    int numberOfGuests;    // Number of guests attending
    int numberOfMinutes;   // Duration of the event in minutes
    int numberOfServers;   // Number of servers required for the event

    // Private member function to calculate the required number of servers
    int calculateNumberOfServers() const 
    {
         return ceil(static_cast<double>(numberOfGuests) / 20);
    }

    // Private member function to calculate the cost for one server
    double calculateCostForOneServer() const 
    {
        // Calculate server cost based on hours and minutes worked
        double cost1 = (numberOfMinutes / 60) * CostPerHour;  // Cost for full hours
        double cost2 = (numberOfMinutes % 60) * CostPerMinute;  // Cost for extra minutes
        return cost1 + cost2;
    }

    // Private member function to calculate total food cost for all guests
    double calculateTotalFoodCost() const 
    {
        return numberOfGuests * CostOfDinner;
    }

    // Private member function to calculate the average cost per person
    double calculateAverageCostPerPerson() const 
    {
        return calculateTotalFoodCost() / numberOfGuests;
    }

public:
    // Public method to input event details from the user
    void inputEventDetails() 
    {
        printf("*** Event Management System ***\n");

        // Get event name, host's first and last name, number of guests, and event duration
        cout << "Enter the name of the event: ";
        getline(cin, eventName);

        cout << "Enter your first name: ";
        getline(cin, firstName);

        cout << "Enter your last name: ";
        getline(cin, lastName);

        cout << "Enter the number of guests: ";
        cin >> numberOfGuests;

        cout << "Enter the number of minutes in the event: ";
        cin >> numberOfMinutes;

        // Calculate the required number of servers
        numberOfServers = calculateNumberOfServers();
    }

    // Public method to display the cost estimation for the event
    void displayCostEstimation() const 
    
    {
        // Calculate costs
        double costForOneServer = calculateCostForOneServer();
        double totalFoodCost = calculateTotalFoodCost();
        double averageCostPerPerson = calculateAverageCostPerPerson();
        double totalCost = totalFoodCost + (costForOneServer * numberOfServers);
        double depositAmount = totalCost * 0.25; 

        // Display the event cost estimation
        printf("\n* Event Estimate for *\n");
        cout << "Host: " << firstName << " " << lastName << endl;
        cout << "Number of Servers: " << numberOfServers << endl;
        cout << "The Cost for Servers: " << costForOneServer * numberOfServers << endl;
        cout << "The Cost for Food: " << totalFoodCost << endl;
        cout << "Average Cost Per Person: " << averageCostPerPerson << endl;
        cout << "Total Cost: " << totalCost << endl;
        cout << "Please deposit a 25% deposit to reserve the event." << endl;
        cout << "Deposit Amount: " << depositAmount << endl;
    }
};

int main() 

{
    Event event;  // Create an Event object
// Get event details and display cost estimation
    event.inputEventDetails();
    event.displayCostEstimation();

    return 0; // end of program 
}