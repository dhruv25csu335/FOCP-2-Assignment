#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
private:
    unordered_map<int, unordered_set<int>> movieBookings; 
    unordered_map<int, int> availableTickets; 
    const int MAX_TICKETS = 100;

public:
    // BOOK X Y
    bool book(int customerID, int movieID) {
        if (availableTickets.find(movieID) == availableTickets.end())
            availableTickets[movieID] = MAX_TICKETS;

        if (movieBookings[movieID].count(customerID)) 
            return false; // already booked

        if (availableTickets[movieID] == 0) 
            return false; // sold out

        movieBookings[movieID].insert(customerID);
        availableTickets[movieID]--;
        return true;
    }

    // CANCEL X Y
    bool cancel(int customerID, int movieID) {
        if (!movieBookings[movieID].count(customerID)) 
            return false; // not booked

        movieBookings[movieID].erase(customerID);
        availableTickets[movieID]++;
        return true;
    }

    // IS_BOOKED X Y
    bool isBooked(int customerID, int movieID) {
        return movieBookings[movieID].count(customerID) > 0;
    }

    // AVAILABLE_TICKETS Y
    int availableTicketsCount(int movieID) {
        if (availableTickets.find(movieID) == availableTickets.end())
            return MAX_TICKETS; // no bookings yet
        return availableTickets[movieID];
    }
};

int main() {
    int Q;
    cin >> Q;
    MovieTicket system;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (system.book(X, Y) ? "true" : "false") << endl;
        } 
        else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (system.cancel(X, Y) ? "true" : "false") << endl;
        } 
        else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (system.isBooked(X, Y) ? "true" : "false") << endl;
        } 
        else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << system.availableTicketsCount(Y) << endl;
        }
    }
    return 0;
}
