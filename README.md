# ATM-and-Banking-Transaction-system

The program implements a simulation of an ATM Banking System with features such as account creation, user authentication, and various transaction options (balance inquiry, withdrawal, deposit). The system allows users to manage their account details and performs operations securely by utilizing PIN-based authentication. Data persistence is handled through file operations to store and retrieve user data.

Transaction Options:<br>
 After a successful login, users can:
- **Check Balance:** View the current account balance.
- **Withdraw Money:** Withdraw funds from the account (if the balance is sufficient).
- **Deposit Money:** Deposit a specified amount into the account.
- **Change PIN:** Update the account PIN for added security.
- **View Profile:** View the user’s profile, including their account details.
- **Update Profile:** Modify user details such as name, mobile number, or date of birth.<br>
The program saves user data to a file (UserDatabase.txt) to persist information across sessions. User details are loaded from this file at the start of the program and saved back after any changes.

The program uses ANSI escape codes to display messages in different colors, providing a clear distinction between success, error, warnings, and user prompts.

Each transaction (such as withdrawing funds or changing the PIN) requires the user to enter their PIN for verification. If the PIN is incorrect, an error message is displayed.

Users can log out and exit the system, with all changes saved before exiting.

How to Use:

1. **Create a new account** by choosing the option from the main menu.
2. **Login** using your account number and PIN.
3. Perform transactions such as checking balance, withdrawing money, or depositing funds.
4. Update your profile or change your PIN for enhanced security.
5. **Logout** when finished, and the system will save your data for the next session.
In this Program I used :

- **C++:** For implementing the ATM functionality and user interface.
- **File Handling:** Used to persist user data in a text file (`UserDatabase.txt`).
UserDatabase.txt: Stores user data in .txt format (Account No, Name, PIN, Balance, Mobile No, DOB)
.
This program is an excellent starting point for learning how to implement basic banking operations in C++, including file handling, object-oriented programming, and handling user input.

Feel free to customize, enhance, and use this program for educational or practical purposes!
