# Chada-Tech Clock

## Project Overview

This project was developed as part of a coding skills test for my clas CS-210. The goal was to create an object-oriented C++ application that displays both a 12-hour and a 24-hour clock simultaneously and allows for user input to modify the time.

## Situation

Chada Tech has domestic and international clients and wants to meet the international standard ISO 8601 by providing both 12-hour and 24-hour clocks on their website. The application should:

- Display the current time in both 12-hour and 24-hour formats.
- Allow the user to add hours, minutes, and seconds to the current time.
- Ensure the application is secure and efficient.

## Project Structure

The project consists of the following files:

- `CLOCKSCHADATECH.CPP`: Contains the main logic for the clock application.
- `HEADER.H`: Contains metadata about the project.

## Key Features

- **Clock Class**: Represents a clock with hours, minutes, and seconds. It includes methods to add hours, minutes, and seconds, and to display the time in both 12-hour and 24-hour formats.
- **User Input**: The application allows the user to set the initial time and modify it by adding hours, minutes, or seconds.
- **Menu System**: A simple menu system to interact with the clock.

## Usage

1. **Set Initial Time**: The user is prompted to enter the initial time (hours, minutes, and seconds).
2. **Display Time**: The current time is displayed in both 12-hour and 24-hour formats.
3. **Modify Time**: The user can choose to add hours, minutes, or seconds to the current time.
4. **Exit**: The user can exit the application.

## Example

```
WELCOME TO 12_AND_24 HOURS CLOCK!

Please Enter Initial Time
Hours (0-23): 14
Minutes (0-59): 30
Seconds (0-59): 45

12-Hour Clock: 02:30:45 PM
24-Hour Clock: 14:30:45

***************************
MENU:
1 - Add One Hour
2 - Add One Minute
3 - Add One Second
4 - Exit Program
***************************
Enter Your Choice: 1

12-Hour Clock: 03:30:45 PM
24-Hour Clock: 15:30:45
```

## Conclusion

This project demonstrates the ability to write professional, well-documented, and readable C++ code. It showcases object-oriented programming principles and user interaction through a simple menu system.
