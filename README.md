# ATM-and-Banking-Transaction-system

The program implements a simulation of an ATM Banking System with features such as account creation, user authentication, and various transaction options (balance inquiry, withdrawal, deposit). The system allows users to manage their account details and performs operations securely by utilizing PIN-based authentication. Data persistence is handled through file operations to store and retrieve user data.

<h3>Transaction Options:</h3>
After a successful login, users can:
<ul style="list-style-type:i;">
<li>Check Balance : View the current account balance.</li>
<li>Withdraw Money : Withdraw funds from the account (if the balance is sufficient).</li>
<li>Deposit Money : Deposit a specified amount into the account.</li>
<li>Change PIN : Update the account PIN for added security.</li>
<li>View Profile : View the user’s profile, including their account details.</li>
<li>Update Profile : Modify user details such as name, mobile number, or date of birth.</li></ul>

<p>The program saves user data to a file (UserDatabase.txt) to persist information across sessions. User details are loaded from this file at the start of the program and saved back after any changes.

The program uses ANSI escape codes to display messages in different colors, providing a clear distinction between success, error, warnings, and user prompts.

Each transaction (such as withdrawing funds or changing the PIN) requires the user to enter their PIN for verification. If the PIN is incorrect, an error message is displayed.

Users can log out and exit the system, with all changes saved before exiting.</p>

<h3>How to Use:</h3><ul style="list-style-type:square;">
<li>Create a new account by choosing the option from the main menu.</li>
<li>Login using your account number and PIN.</li>
<li>Perform transactions such as checking balance, withdrawing money, or depositing funds.</li>
<li>Update your profile or change your PIN for enhanced security.</li>
<li>Logout  when finished, and the system will save your data for the next session.</li></ul>
   
<h3>In this Program I used :</h3>
<ul>
<li>C++: For implementing the ATM functionality and user interface.</li>
<li>File Handling: Used to persist user data in a text file </li>(`UserDatabase.txt`).
UserDatabase.txt: Stores user data in .txt format (Account No, Name, PIN, Balance, Mobile No, DOB).
</ul>

<p>This program is an excellent starting point for learning how to implement basic banking operations in C++, including file handling, object-oriented programming, and handling user input.

Feel free to customize, enhance, and use this program for educational or practical purposes!</p>
