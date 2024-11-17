// Name: Carlos Bracho
// Course: CS-210 Programming Languages

#include <iostream>
#include <iomanip>
using namespace std;

class Clock {
    private:
        int hours;
        int minutes;
        int seconds;

    public:
        Clock(int h, int m, int s) {
            hours = h;
            minutes = m;
            seconds = s;
        }

        void addHour() {
            hours = (hours + 1) % 24;
        }

        void addMinute() {
            minutes++;
            if (minutes == 60) {
                minutes = 0;
                addHour();
            }
        }

        void addSecond() {
            seconds++;
            if (seconds == 60)
            {
                seconds = 0;
                addMinute();
            }
        }

        void display() {

            // 12-hour format
            int hourTwelveFormat;
            if (hours % 12 == 0) 
            {
                hourTwelveFormat = 12;
            } else {
                hourTwelveFormat = hours % 12;
            }
            
            string period;
            if (hours >= 12) {
                period = "PM";
            } else {
                period = "AM";
            }

            // Display times
            cout << "\n12-Hour Clock: " 
                << setw(2) << setfill('0') << hourTwelveFormat << ":"
                << setw(2) << setfill('0') << minutes << ":"
                << setw(2) << setfill('0') << seconds << " " << period << endl;

                        
            cout << "24-Hour Clock: " 
                << setw(2) << setfill('0') << hours << ":"
                << setw(2) << setfill('0') << minutes << ":"
                << setw(2) << setfill('0') << seconds << "\n" << endl;


        }
};

void border() {
    cout << "***************************";
}

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

        if (hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59 && seconds >= 0 && seconds <= 59)
        {
            break;
        } else {
            cout <<"Invalid input! Please use valid values.\n";
        }
        
    } while (hours < 0 || hours > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59);
    
}

void processChoice(int choice, Clock& clock) {
    switch (choice)
    {
    case 1:
        clock.addHour();
        break;
    
    case 2:
        clock.addMinute();
        break;
    
    case 3:
        clock.addSecond();
        break;
    
    case 4:
        cout << "Exiting program.\n";
        exit(0);
        break;
    
    default:
        cout << "Invalid choice. Please try again.\n";
        break;
    }


}

// Main
int main() {

    cout << "WELCOME TO 12_AND_24 HOURS CLOCK!";

    int hours, minutes, seconds, choice;

    setInitialTime(hours,minutes,seconds);
    
    Clock clock(hours,minutes,seconds);

    clock.display();

    do
    {
        menuDisplay(choice);
        processChoice(choice, clock);
        clock.display();
    } while (choice != 4);
    

    return 0;
}