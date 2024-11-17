// Name: Carlos Bracho
// Course: CS-210 Programming Languages

#include <iostream>
#include <iomanip> // Used for setw() and setfill() formatting
using namespace std;

// Class to represent a clock with hours, minutes and seconds
class Clock {
    private:
        int hours;
        int minutes;
        int seconds;

    public:
    // Constructor to initialize the clock with hours, minutes and seconds
        Clock(int h, int m, int s) {
            hours = h;
            minutes = m;
            seconds = s;
        }

    // Function to add one hour
        void addHour() {
            hours = (hours + 1) % 24;
        }

    // Function to add one minute
        void addMinute() {
            minutes++;
            if (minutes == 60) {
                minutes = 0;
                addHour();
            }
        }

    // Function to add one second
        void addSecond() {
            seconds++;
            if (seconds == 60)
            {
                seconds = 0;
                addMinute();
            }
        }

    // Function to display time in 12-hour and 24-hour formats
        void display() {

            // Converting to 12 hour format
            int hourTwelveFormat;
            if (hours % 12 == 0) 
            {
                hourTwelveFormat = 12;
            } else {
                hourTwelveFormat = hours % 12;
            }
            
            // Determine whether the time is AM or PM
            string period;
            if (hours >= 12) {
                period = "PM";
            } else {
                period = "AM";
            }

            // Display the 12 hour format
            cout << "\n12-Hour Clock: " 
                << setw(2) << setfill('0') << hourTwelveFormat << ":"
                << setw(2) << setfill('0') << minutes << ":"
                << setw(2) << setfill('0') << seconds << " " << period << endl;

            // Display the 24 hour format 
            cout << "24-Hour Clock: " 
                << setw(2) << setfill('0') << hours << ":"
                << setw(2) << setfill('0') << minutes << ":"
                << setw(2) << setfill('0') << seconds << "\n" << endl;


        }
};

// Function to display a border
void border() {
    cout << "***************************";
}

// Function to display the menu and get the user's choice
void menuDisplay(int& choice) {
    border();
    cout << "\nMENU:\n";
    cout << "1 - Add One Hour\n";
    cout << "2 - Add One Minute\n";
    cout << "3 - Add One Second\n";
    cout << "4 - Exit Program\n";
    border();
    cout << "\nEnter Your Choice: ";
    cin >> choice;
}

// Function to set the initial time for the clock from the user
void setInitialTime(int& hours, int& minutes,int& seconds) {

    do
    {
        cout << "\nPlease Enter Initial Time\n";
        cout << "Hours (0-23): ";
        cin >> hours;
        cout << "Minutes (0-59): ";
        cin >> minutes;
        cout << "Seconds (0-59): ";
        cin >> seconds;

        // Validating user input
        if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59 && seconds >= 0 && seconds <= 59)
        {
            break;
        } else {
            cout <<"Invalid input! Please use valid values.\n";
        }
        
    } while (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59);
    
}

// Function to process the user's choice from the menu
void processChoice(int choice, Clock& clock) {
    switch (choice)
    {

    // Add one hour 
    case 1:
        clock.addHour();
        break;

    // Add one minute
    case 2:
        clock.addMinute();
        break;
    
    // Add one second
    case 3:
        clock.addSecond();
        break;
    
    // Exit Program 
    case 4:
        cout << "Exiting program.\n";
        exit(0); // Exits Program
        break;
    
    default:
        cout << "Invalid choice. Please try again.\n";
        break;
    }


}

// Main function
int main() {

    cout << "WELCOME TO 12_AND_24 HOURS CLOCK!";

    int hours, minutes, seconds, choice;

    // Setting the initial time for the clock
    setInitialTime(hours,minutes,seconds);
    
    // Creates the Clock object
    Clock clock(hours,minutes,seconds);

    // Displays the initial time
    clock.display();

    // Loop to display the menu and process user choices until they choose to exit
    do
    {
        menuDisplay(choice);
        processChoice(choice, clock);
        clock.display();
    } while (choice != 4);
    

    return 0;
}