
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
#include<sstream>
using namespace std;

const string RESET = "\033[0m";     // Reset the color
const string GREEN = "\033[1;32m"; // Green color  - [Success]
const string RED = "\033[1;31m";   //  Red color   -  [Error]
const string YELLOW = "\033[1;33m";  // Yellow color - [Enter] 
const string BLUE = "\033[1;34m";   // Blue color  - [Program Menu]
const string CYAN = "\033[36m";      //  same as SkyBlue -[Prompt]
const string MAGENTA = "\033[35m";    // Magenta color
const std::string BOLD_WHITE = "\033[1;37m"; //bold White color
const string BOLD = "\033[1m";         // Bold
const string UNDERLINE = "\033[4m";    // Underline
const string REVERSED = "\033[7m";     // Reversed colors


class Bank{
    int Account_No;
    string Name;
    int Pin;
    float Balance;
    string Mobile_No, DOB;

    public:
        void setdata(int account_No_a,string name_a,int PIN_a,float balance_a,string moblie_No_a,string DateOfBirth){
            Account_No=account_No_a;
            Name=name_a;
            Pin=PIN_a;
            Balance=balance_a;
            Mobile_No=moblie_No_a;
            DOB=DateOfBirth;
        }

        string UserName(){
            return (Name);
        }

        int getAccountNo() const{
            return Account_No;
        }

        int get_Pin(){
            return Pin;
        }

        int changePIN(int newPin){
            Pin=newPin;
        }

        float getBalance(){
            return Balance;
        }

         void wrong_pin(){
            cout<<RED<<"-----------------------\n";
            cout<<"  wrong Pin Entered !\n";
            cout<<"-----------------------\n"<<RESET;
        }

        void Withdraw(float amount){
            if(amount>Balance){
                cout<<RED<<"[ERROR]"<<"Insufficient founds !\n\n"<<RESET;
            }
            else{
                Balance-=amount;
                cout<<GREEN<<"[SUCCESS]"<<"Withdrawal successful Collect Your Cash !\n"<<RESET;
                cout<<GREEN<<"Current balance :"<<Balance<<RESET<<endl<<endl;
            }
        }

        void Deposit(float amount){
            if(amount <= 0 ){
                cout<<RED<<"[ERROR]"<<" Invalid deposit amount !\n\n"<<RESET;
            }
            else{
                Balance+=amount;
                cout<<GREEN<<"[SUCCESS]"<<" Deposit successful !\n"<<RESET;
                cout<<GREEN<<"Current Balance :"<<Balance<<RESET<<endl<<endl;
            }
        }

        void UpdateProfile(){
            cout<<CYAN<<"Enter your choice to update profile :\n"<<RESET;
            cout<<BLUE<<"1. User Name\n2. Mobile Number\n3. Date of Birth\n"<<RESET;
            cout<<YELLOW<<"Choice :"<<RESET;
            int choice;
            cin>>choice;
            switch(choice){
                case 1:{
                    cout<<YELLOW<<"Enter new User Name :"<<RESET;
                    string newname;
                    cin.ignore();
                    getline(cin,newname);
                    Name=newname;
                    cout<<GREEN<<"Name Change successfully..\n"<<RESET;
                    break;
                }
                case 2:{
                    cout<<YELLOW<<"Enter Mobile Number :"<<RESET;
                    string newMobile;
                    cin>>newMobile;
                    Mobile_No=newMobile;
                    cout<<GREEN<<"Mobile Number changed successfully..\n"<<RESET;
                    break;
                }
                case 3:{
                    cout<<YELLOW<<"Enter new Date of Birt :"<<RESET;
                    string newDOB;
                    cin>>newDOB;
                    DOB=newDOB;
                    cout<<GREEN<<"Date of Birth changed successfully..\n"<<RESET;
                    break;
                }
                default:
                    cout<<RED<<"Invalid Choice..\n"<<RESET;
            }
        }

        void userProfile(){ 
            cout<<GREEN<<"User Profile -\n"<<RESET;
            //from ref.cpp line No 2654
            cout<<MAGENTA<<"+"<<string(50,'-')<<"+"<<RESET<<endl;
            cout<<MAGENTA<<"|"<<left<<setw(21)<<" UserName"<<"| "<<setw(27)<<Name<<"|"<<RESET<<endl;
            cout<<MAGENTA<<"+"<<string(50,'-')<<"+"<<RESET<<endl;
            cout<<MAGENTA<<"|"<<left<<setw(21)<<" Account No. :"<<"| "<<setw(27)<<Account_No<<"|"<<RESET<<endl;
            cout<<MAGENTA<<"+"<<string(50,'-')<<"+"<<RESET<<endl;
            cout<<MAGENTA<<"|"<<left<<setw(21)<<" Mobile No. :"<<"| "<<setw(27)<<Mobile_No<<"|"<<RESET<<endl;
            cout<<MAGENTA<<"+"<<string(50,'-')<<"+"<<RESET<<endl;
            cout<<MAGENTA<<"+"<<left<<setw(21)<<" Date Of Birth :"<<"| "<<setw(27)<<DOB<<"|"<<RESET<<endl;
            cout<<MAGENTA<<"+"<<string(50,'-')<<"+"<<RESET<<endl<<endl;
        }

        string toString() const{
            return to_string(Account_No) + "," + Name + "," + to_string(Pin) + "," + to_string(Balance) + "," + Mobile_No + "," + DOB;
        }

        static Bank fromString(const string &userData){
            Bank user;
            stringstream ss(userData);
            string token;

            getline(ss,token,',');
            user.Account_No=stoi(token);
            getline(ss,user.Name,',');
            getline(ss,token,',');
            user.Pin=stoi(token);
            getline(ss,token,',');
            user.Balance=stoi(token);
            getline(ss,user.Mobile_No,',');
            getline(ss,user.DOB,',');

            return user;
        }

    
};

void loadUsers(vector<Bank> &users){
    ifstream inFile("UserDatabase.txt");
    if(!inFile){
        cout<<RED<<"No Data found, Could not open file for reading.Crreating new file...\n"<<RESET;
        return; // If the file doesn't exist, return without loading anything
    }
    string line;
    while(getline(inFile,line)){
        users.push_back(Bank::fromString(line));
    }
    inFile.close();
}

void saveUsers(const vector<Bank> &users){
    ofstream outFile("UserDatabase.txt");
    for(const auto &user:users){
        outFile << user.toString() << endl;
    }
    outFile.close();
}

class Transaction : public Bank{

    Bank *user;
    int temp_pin;
    
    public:
        void setUser(Bank *u){
            user=u;
        }
        
        void changePin(){
            int new_pin;
            cout<<YELLOW<<"Enter new Pin : "<<RESET;
            cin>>new_pin;
            user->changePIN(new_pin);
            cout<<GREEN<<"[SUCCESS]"<<"PIN changed successfully !\n\n"<<RESET;
        }

        void checkBalance(){
            cout<<YELLOW<<"Enter your Pin : "<<RESET;
            cin>>temp_pin;
            if(user->get_Pin()==temp_pin){
                cout<<MAGENTA<<"+"<<string(50,'-')<<"+"<<RESET<<endl;
                cout<<GREEN<<"\t   Current Balance :"<<user->getBalance()<<RESET<<endl;
                cout<<MAGENTA<<"+"<<string(50,'-')<<"+"<<RESET<<endl;
            }
            else{
                wrong_pin();
            }
        }

        void withdraw(){
            cout<<YELLOW<<"Enter your Pin : "<<RESET;
            cin>>temp_pin;
            if(user->get_Pin()==temp_pin){
                float amount;
                cout<<YELLOW<<"Enter The Amount : "<<RESET;
                cin>>amount;
                user->Withdraw(amount);
            }
            else{
                wrong_pin();
            }
        }

        void deposite(){ 

            cout<<YELLOW<<"Enter The Pin : "<<RESET;
            cin>>temp_pin;
            if(user->get_Pin()==temp_pin){
                float amount;
                cout<<YELLOW<<"Enter the amount : "<<RESET;
                cin>>amount;
                user->Deposit(amount);
            }
            else{
                wrong_pin();
            }
                
        }

        void viewProfile(){
            cout<<YELLOW<<"Enter The Pin : "<<RESET;
            cin>>temp_pin;
            if(user->get_Pin()==temp_pin){
                user->userProfile();
            }
            else{
                wrong_pin();
            }
            
        }
        void updateprofile(vector<Bank> &users){
            cout<<YELLOW<<"Enter The Pin : "<<RESET;
            cin>>temp_pin;
            if(user->get_Pin()==temp_pin){
                user->UpdateProfile();
                saveUsers(users);
                cout<<GREEN<<"Profile Updated successfully...\n"<<RESET;
            }
            else{
                wrong_pin();
            }
            
        }

};

void createAccount(vector<Bank> &users) {
    int account_No, Pin;
    float balance;
    string name, mobile_No,dob;

    cout << CYAN << "\nEnter the details to create a new account:\n" << RESET;
    cout << YELLOW << "Account No: " << RESET;
    cin >> account_No;

    // Check if account number already exists
    for (const auto &user : users) {
        if (user.getAccountNo() == account_No) {
            cout << RED << "[ERROR] Account number already exists!\n" << RESET;
            return;
        }
    }

    cout << YELLOW << "Name: " << RESET;
    cin.ignore(); // To clear the newline from the input buffer
    getline(cin, name);                

    cout << YELLOW << "PIN "<<CYAN<<"(It must be 4 digits) :" << RESET;
    cin >> Pin;

    cout << YELLOW << "Initial Deposit Balance: " << RESET;
    cin >> balance;

    cout << YELLOW << "Mobile Number: " << RESET;
    cin >> mobile_No;

    cout<<YELLOW<<"Date of Birth in "<<CYAN<<"DD/MM/YYYY"<<YELLOW<<" format :"<<RESET;
    cin>>dob;

    Bank newUser;
    newUser.setdata(account_No, name, Pin, balance, mobile_No,dob);
    users.push_back(newUser);

   
    saveUsers(users);

    cout << GREEN << "[SUCCESS] Account created successfully!\n" << RESET;
}

int main() {
    Transaction t;
    vector<Bank> users;
    loadUsers(users);
    
    if (users.empty()) {
        Bank user1;
        user1.setdata(2307003, "Balaji Bandgar", 1234, 100000, "8669506088","28/11/2006");
        users.push_back(user1);
    }

    cout<<REVERSED<<BLUE<<"\n-*-**-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-**-*-*-WELCOME to STATE BANK OF INDIA-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-**-*-*-\n\n"<<RESET;

    while (true) {
        int choice;
        cout << CYAN << "\nMain Menu:\n" << RESET;
        cout << BLUE << "1. Create a New Account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n" << RESET;
        cout << YELLOW << "Enter your choice: " << RESET;
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(users);  
                break;
            case 2: {
                int Enter_Account_no, Enter_Pin;
                cout << CYAN << "\nEnter login details:\n" << RESET;
                cout << YELLOW << "Account No.: " << RESET;
                cin >> Enter_Account_no;
                cout << YELLOW << "PIN: " << RESET;
                cin >> Enter_Pin;

                Bank *currentUser = nullptr;

                // Authenticate user by account number and PIN
                for (auto &user : users) {
                    if (Enter_Account_no == user.getAccountNo() && Enter_Pin == user.get_Pin()) {
                        currentUser = &user;
                        break;
                    }
                }

                if (currentUser) {
                    t.setUser(currentUser);
                    cout<<MAGENTA<<"\n+"<<string(50,'-')<<"+"<<RESET<<endl;
                    cout << GREEN << "\t   Welcome " << BOLD << UNDERLINE << currentUser->UserName() << RESET << endl;
                    cout<<MAGENTA<<"+"<<string(50,'-')<<"+\n"<<RESET<<endl;

                    int transactionChoice;
                    do {
                        // cout<<string(10,' ')<<REVERSED<<BLUE<<string(10,'-')<<"TRANSACTION"<<string(10,'-')<<endl;
                        cout <<endl<<string(10,' ')<<REVERSED<< CYAN << "Please, Select your Transaction\n" << RESET;
                        cout << BLUE << "+----------------------+---------------------------+\n" << RESET;
                        cout << BLUE << "| (1) Check Balance    | (2) Change the Pin        |\n" << RESET;
                        cout << BLUE << "+----------------------+---------------------------+\n" << RESET;
                        cout << BLUE << "| (3) Withdraw Money   | (4) Deposit Money         |\n" << RESET;
                        cout << BLUE << "+----------------------+---------------------------+\n" << RESET;
                        cout << BLUE << "| (5) View Profile     | (6) Update Profile        |\n" << RESET;
                        cout << BLUE << "+----------------------+---------------------------+\n" << RESET;
                        cout << BLUE << "| (7) Logout           |                           |\n" << RESET;
                        cout << BLUE << "+----------------------+---------------------------+\n" << RESET;

                        cout<<MAGENTA<<"+"<<string(20,'-')<<"+"<<RESET<<endl;
                        cout << YELLOW << "   Choice: " << RESET;
                        cin >> transactionChoice;
                        cout<<MAGENTA<<"+"<<string(20,'-')<<"+"<<RESET<<endl;

                        switch (transactionChoice) {
                            case 1:
                                cout<<"\n";
                                t.checkBalance();
                                break;
                            case 2:
                                cout<<"\n";
                                t.changePin();
                                break;
                            case 3:
                                cout<<"\n";
                                t.withdraw();
                                break;
                            case 4:
                                cout<<"\n";
                                t.deposite();
                                break;
                            case 5:
                                cout<<"\n";
                                t.viewProfile();
                                break;
                            case 6:
                                cout<<"\n";
                                t.updateprofile(users);
                                break;
                            case 7:
                             cout<<"\n";
                                saveUsers(users);  // Save user data before exiting
                                cout << GREEN << "Logout successfully!\n" << RESET;
                                break;
                            default:
                                cout << RED << "Invalid Option!\n" << RESET;
                        }
                    } while (transactionChoice != 7); // Exit the transaction menu on choice 7

                } else {
                    cout << RED << "Invalid Account Number or PIN!\n" << RESET;
                }
                break;
            }
            case 3:
                cout << GREEN << "Thank you for using the ATM system. Goodbye!\n" << RESET;
                return 0;
            default:
                cout << RED << "Invalid choice! Please try again.\n" << RESET;
        }
    }

    return 0;
}


