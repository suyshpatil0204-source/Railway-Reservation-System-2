#include <iostream>
#include <string>
using namespace std;

class Railway
{
private:
    int ticketNo;
    string passengerName;
    int age;
    string trainName;
    string travelDate;
    string classType;
    string source;
    string destination;

    float fare;
    float discount;
    float finalFare;

    string paymentMethod;
    string paymentStatus;

    bool booked;

public:

    // Book Ticket
    void bookTicket(int number)
    {
        ticketNo = number;

        cin.ignore();

        cout << "\nEnter Passenger Name: ";
        getline(cin, passengerName);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();

        cout << "Enter Train Name: ";
        getline(cin, trainName);

        cout << "Enter Travel Date: ";
        getline(cin, travelDate);

        cout << "Choose Class:";
        cout << "\n1. General";
        cout << "\n2. Sleeper";
        cout << "\n3. AC";
        cout << "\nEnter Choice: ";

        int classChoice;
        cin >> classChoice;

        if(classChoice == 1)
        {
            classType = "General";
            fare = 500;
        }
        else if(classChoice == 2)
        {
            classType = "Sleeper";
            fare = 800;
        }
        else if(classChoice == 3)
        {
            classType = "AC";
            fare = 1000;
        }
        else
        {
            cout << "\nInvalid Class!";
            classType = "General";
            fare = 500;
        }

        cin.ignore();

        cout << "Enter Source: ";
        getline(cin, source);

        cout << "Enter Destination: ";
        getline(cin, destination);


        // Senior Citizen Scheme
        if(age >= 60)
        {
            discount = fare * 0.10;
            finalFare = fare - discount;

            cout << "\n*** SENIOR CITIZEN SCHEME ***";
            cout << "\nDiscount: 10%";
            cout << "\nDiscount Amount: Rs. " << discount;
        }
        else
        {
            discount = 0;
            finalFare = fare;

            cout << "\nNo Senior Citizen Discount.";
        }


        // Payment Method
        cout << "\n\nChoose Payment Method:";
        cout << "\n1. UPI";
        cout << "\n2. Debit/Credit Card";
        cout << "\n3. Cash";
        cout << "\nEnter Choice: ";

        int paymentChoice;
        cin >> paymentChoice;

        if(paymentChoice == 1)
        {
            paymentMethod = "UPI";
        }
        else if(paymentChoice == 2)
        {
            paymentMethod = "Debit/Credit Card";
        }
        else if(paymentChoice == 3)
        {
            paymentMethod = "Cash";
        }
        else
        {
            paymentMethod = "Not Selected";
        }


        // Payment Status
        if(paymentChoice >= 1 && paymentChoice <= 3)
        {
            paymentStatus = "Paid";
        }
        else
        {
            paymentStatus = "Pending";
        }


        booked = true;


        // Display ticket number after successful booking
        cout << "\n\nTicket Booked Successfully!";
        cout << "\nTicket Number: " << ticketNo;
        cout << "\nFinal Fare: Rs. " << finalFare;
        cout << "\nPayment Method: " << paymentMethod;
        cout << "\nPayment Status: " << paymentStatus << endl;
    }


    // Display Ticket
    void displayTicket()
    {
        cout << "\n================================";
        cout << "\n        TICKET DETAILS";
        cout << "\n================================";

        cout << "\nTicket Number : " << ticketNo;
        cout << "\nPassenger Name: " << passengerName;
        cout << "\nAge           : " << age;
        cout << "\nTrain Name    : " << trainName;
        cout << "\nTravel Date   : " << travelDate;
        cout << "\nClass         : " << classType;
        cout << "\nSource        : " << source;
        cout << "\nDestination   : " << destination;

        cout << "\nOriginal Fare : Rs. " << fare;
        cout << "\nDiscount      : Rs. " << discount;
        cout << "\nFinal Fare    : Rs. " << finalFare;

        cout << "\nPayment Method: " << paymentMethod;
        cout << "\nPayment Status: " << paymentStatus;

        if(booked)
        {
            cout << "\nStatus        : Booked";
        }
        else
        {
            cout << "\nStatus        : Cancelled";
        }

        cout << "\n================================\n";
    }


    // Get Ticket Number
    int getTicketNo()
    {
        return ticketNo;
    }


    // Cancel Ticket
    void cancelTicket()
    {
        if(booked)
        {
            booked = false;
            paymentStatus = "Refund/Cancelled";

            cout << "\nTicket Cancelled Successfully!";
        }
        else
        {
            cout << "\nTicket is already cancelled.";
        }
    }
};


int main()
{
    Railway ticket[100];

    int count = 0;
    int choice;
    int searchNo;

    do
    {
        cout << "\n\n===== RAILWAY RESERVATION SYSTEM =====";

        cout << "\n1. Book Ticket";
        cout << "\n2. Display All Tickets";
        cout << "\n3. Search Ticket";
        cout << "\n4. Cancel Ticket";
        cout << "\n5. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;


        switch(choice)
        {
            // Book Ticket
            case 1:

                if(count < 100)
                {
                    ticket[count].bookTicket(1001 + count);
                    count++;
                }
                else
                {
                    cout << "\nNo More Tickets Can Be Added.";
                }

                break;


            // Display All Tickets
            case 2:

                if(count == 0)
                {
                    cout << "\nNo Tickets Available.";
                }
                else
                {
                    for(int i = 0; i < count; i++)
                    {
                        ticket[i].displayTicket();
                    }
                }

                break;


            // Search Ticket
            case 3:

                cout << "\nEnter Ticket Number to Search: ";
                cin >> searchNo;

                {
                    bool found = false;

                    for(int i = 0; i < count; i++)
                    {
                        if(ticket[i].getTicketNo() == searchNo)
                        {
                            ticket[i].displayTicket();

                            found = true;

                            break;
                        }
                    }

                    if(!found)
                    {
                        cout << "\nTicket Not Found.";
                    }
                }

                break;


            // Cancel Ticket
            case 4:

                cout << "\nEnter Ticket Number to Cancel: ";
                cin >> searchNo;

                {
                    bool found = false;

                    for(int i = 0; i < count; i++)
                    {
                        if(ticket[i].getTicketNo() == searchNo)
                        {
                            ticket[i].cancelTicket();

                            found = true;

                            break;
                        }
                    }

                    if(!found)
                    {
                        cout << "\nTicket Not Found.";
                    }
                }

                break;


            // Exit
            case 5:

                cout << "\nThank You for Using Railway Reservation System!";
                break;


            default:

                cout << "\nInvalid Choice!";
        }

    } while(choice != 5);


    return 0;
}
