# Day of Week

This program has a command line and also a GUI version to determine on which day a specific date was (will be). Until now, the Gregorian calendar is implemented but I will also include other calendars.

[//]: # (TODO: add screenshots from Windows and Linux)

## Design principles

For the sake of modularity, the command line and the GUI is fully detached from the algorithms which determine the day of the week. Moreover, these algorithms are written in C, so no C++ runtime environment is required. The GUI was written in [Qt](https://www.qt.io/) therefore it is cross-platform.

## Usage

### Command line

Coming soon...

### GUI

After installation, open the application. A language selector welcomes you.

![Language selection menu](/GUI/screenshots/LanguageSelection.PNG "Language selection menu")

After selecting your language, the main window appears:

![Main window](/GUI/screenshots/MainWindow.PNG "Main window")

The usage is then straightforward, but in case you get stuck, hover the mouse over an entry to get a concise help or click on the *Help* button for more a detailed guide.

[//]: # (Tested on Windows XP, 7, 8.1 and Linux Fedora 24, Ubuntu 14.04 LTS, Ubuntu 16.04 LTS)

[//]: # ([Zeller's congruence](https://en.wikipedia.org/wiki/Zeller%27s_congruence) is a method to determine the day the week for Gregorian or Julian calendar date.)
