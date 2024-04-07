# BankSystemProject

## Project goal

This system is designed to manage bank accounts.
It can:
    1. Create accounts
    2. View accounts data
    3. Edit accounts
    4. Perform transactions between accounts
    5. Delete accounts


## Getting started
To start, you need to run application using command prompt: 

`BankSystem.exe {name} {surname}`

Where *{name}* and *{surname}* are your credentials. They are important since every time you will start application, you will use them.

If you enter Name and Surname which don't have corresponding .csv file, you will be prompted to enter your IBan, your currency and your balance.
If you do have a .csv file with corresponding name+surname, you will instantly login and skip to the menu.

The menu will look like this:

~~~
Welcome to TEST bank interface.

Which action do you want to do? (Enter the number of operation)
1. Perform transactions
2. Edit account
3. View account info
4. Delete account
5. Logout and Exit
~~~
Here you can perform actions with your account.
Whatever action you choose, you will be prompted of whatever is needed from you.


### Changelog

06.04.2024:
Added Perform transaction function and finished main functionalities.
Some of safeguards were implemented.

05.04.2024:
Added Edit info function.
Added free memory to functions.

01.04.2024:
Added Delete account function.
Fixed bug when creating new account, information was not stored in .csv.
Added explanation comments to different parts of code.

30.03.2024:
Re-designed login system to use arguments. Discarded use of structures as active account, instead, using .csv files as a way to store and access accounts.
Re-designed ViewInfo.

10.03.2024:
Implemented Login() function and organized file structure.
Added accounts.csv as account database.

05.03.2024:
Created prototype of user-interface and empty functions for future development.

02.03.2024:
Created Repository.
