#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Customer
{
    string name;
    int id;
    string phone;

public:
    Customer(string a, int b, string c)
    {
        name = a;
        id = b;
        phone = c;
    }

    Customer() {}

    void display1()
    {
        cout << "\nNAME: " << name << " \n" << "CUSTOMER ID: " << id << "\n" << "PHONE NUMBER: " << phone<<"\n"<< endl;
    }

    friend class Agency;
};

class Package
{
    int packagecode[8];
    string destination[8];
    int prices[8];

public:
    void addPackages()
    {
        //declaring code for switch case
        packagecode[0] = 1;
        packagecode[1] = 2;
        packagecode[2] = 3;
        packagecode[3] = 4;
        packagecode[4] = 5;
        packagecode[5] = 6;
        packagecode[6] = 7;
        packagecode[7] = 8;
        //declaring prices for desired package
        prices[0] = 7000;
        prices[1] = 5000;
        prices[2] = 9500;
        prices[3] = 6500;
        prices[4] = 5600;
        prices[5] = 7500;
        prices[6] = 7000;
        prices[7] = 6000;

//declaring vacation packages that we offer
        destination[0] = "Bandarban,Rangamati,Khagrachari";
        destination[1]="Kuakata,Barishal,Pirojpur";
        destination[2]="Cox's bazar,Saint-Martin,Teknaf";
        destination[3]="Srimanagal,Moulavibazar,Chatok";
        destination[4]="Bhola,Chandpur,Cumilla,B-Baria";
        destination[5] = "Rajshahi,Natore,  Bogura";
        destination[6]="Sylhet,Habiganj,Bisanakan";
        destination[7]="Sundarban,Bagerhat,Khulna";

    }


    void displayPackage()
    {cout << "Package Code" << "\t" << "\t" << "\t" << "Destination" << "\t" << "\t " << "Prices-Per-Head" << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << packagecode[i] << "\t\t" << destination[i] << "\t\t" << prices[i] << endl;
        }
    }

    friend class Agency;
};

class Booking
{
    long long int bookingid;
    long long int nationalId;

public:
    static int i;

    Booking()
    {
        i++;
        cout << "Give your national id card number" << endl;
        cin >> nationalId;
        bookingid = nationalId;
        cout << "Your booking is completed" << endl;
        cout << "BOOKING ID :" << "880" << bookingid << "\t\t" << "NATIONAL ID: " << nationalId << " \t";
    }

    friend class Agency;
};

int Booking::i;

class Payment
{
public:
    virtual void paymentMethod() = 0;
};

class Agency : public Package, public Payment
{
    int numberofperson;
    int numberofchild;

public:
    Agency(int a, int b)
    {
        numberofperson = a;
        numberofchild = b;
    }

    void paymentMethod() override
    {
        int choose;
        do{
        cout << "Please choose your payment method:" << endl;
        cout << "1. Cash payment" << endl << "2. Online payment" << endl;
        cin >> choose;


        if (choose == 1)
        {
            cout << "Please contact our agency in person within 3 days." << endl;
        }

        if (choose == 2)
        {
            cout << "Choose the online payment option:" << endl;
            cout << "1. Bkash" << endl << "2. Nagad" << endl << "3. Rocket" << endl << "4. Card" << endl;
            int u;
            cin >> u;

            if (u == 1 || u == 2 || u == 3)
            {
                cout << "Make payment to this number using payment option: 01911900733" << endl;
                cout << "Enter your transaction ID:" << endl;
                string tran;
                cin >> tran;
            }
            if (u == 4)
            {
                cout << "Enter your card number:" << endl;
                string cnum;
                cin >> cnum;
            }
        }}while(choose!=1&&choose!=2);


    }


    void vaacationcost(Package &obj, int n)
    {
        float sum = 0;
        if (numberofperson > 1)
        {
            sum += obj.prices[n] * numberofperson - (obj.prices[n] * numberofperson * 0.1);
            if (numberofchild)
            {
                sum += obj.prices[n] * numberofchild - (obj.prices[n] * numberofchild * 0.3);
            }
        }
        else if (numberofperson == 1)
        {
            sum += obj.prices[n];
            if (numberofchild)
            {
                sum += obj.prices[n] * numberofchild - (obj.prices[n] * numberofchild * 0.3);
            }
        }
        cout << "Your Total cost for this trip will be: ";
        cout << sum << "TK only" << endl;

        string s;
        Customer obj4;
        cout << "Tap to continue" << endl;
        cout << "Type 'Yes' or 'yes' if you are interested to continue to book, otherwise type 'No'" << endl;
        cin >> s;

        if (s == "Yes" || s == "yes")
        {
            char yesno;
            cout << "Give your information" << endl;
            string name;
            int id;
            string phone;
            do
            {
                cout << "Enter your customer ID" << endl;
                cin >> id;
                cout << "Enter your phone number" << endl;
                getchar();
                getline(cin, phone);
                cout << "Enter your name" << endl;
                getline(cin, name);
                Customer obj2(name, id, phone);
                cout << "Check your information" << endl;
                obj2.display1();
                obj4 = obj2;
                paymentMethod();
                cout << "Type 'y' if it's okay, otherwise type 'n' " << endl;
                cin >> yesno;
            }
            while (yesno == 'n');

            cout << "Press for booking" << endl;
            Booking obj3;
            obj4.display1();
            cout << "Your booking is successful, thanks for the visit" << endl;
            cout << "\t\t\t\t\t" << "HAPPY Vacation" << endl;
        }
        else
        {
            cout << "Thanks for the inquiry, keep supporting us. THANK YOU" << endl;
        }
    }
};

int main()
{
    Package obj;
    obj.addPackages();
    obj.displayPackage();

    cout << "\nChoose your package by entering the package code: ";
    int n, person, child;
    cin >> n;
    cout << "Enter the total number of adults and children" << endl;

    switch (n)
    {
    case 1:
    {
        cin >> person >> child;
        Agency obj1(person, child);
        obj1.vaacationcost(obj, n - 1);
        break;
    }

    case 2:
    {
        cin >> person >> child;
        Agency obj1(person, child);
        obj1.vaacationcost(obj, n - 1);
        break;
    }
    case 3:
    {
        cin >> person >> child;
        Agency obj1(person, child);
        obj1.vaacationcost(obj, n - 1);
        break;
    }
    case 4:
    {
        cin >> person >> child;
        Agency obj1(person, child);
        obj1.vaacationcost(obj, n - 1);
        break;
    }
    case 5:
    {
        cin >> person >> child;
        Agency obj1(person, child);
        obj1.vaacationcost(obj, n - 1);
        break;
    }
    case 6:
    {
        cin >> person >> child;
        Agency obj1(person, child);
        obj1.vaacationcost(obj, n - 1);
        break;
    }
    case 7:
    {
        cin >> person >> child;
        Agency obj1(person, child);
        obj1.vaacationcost(obj, n - 1);
        break;
    }
    case 8:
    {
        cin >> person >> child;
        Agency obj1(person, child);
        obj1.vaacationcost(obj, n - 1);
        break;
    }
    default:
        cout << "Package is not available" << endl;
    }

    cout << "For any inquiries, please contact us at 01772895851" << endl;
    return 0;
}
