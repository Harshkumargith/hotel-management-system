#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Room class definition
class Room {
public:
    int roomNumber;
    string guestName;
    bool isOccupied;

    Room(int number) {
        roomNumber = number;
        isOccupied = false;
        guestName = "";
    }

    void checkIn(string name) {
        if (!isOccupied) {
            guestName = name;
            isOccupied = true;
            cout << "✅ Checked in successfully to Room " << roomNumber << ".\n";
        } else {
            cout << "❌ Room " << roomNumber << " is already occupied.\n";
        }
    }

    void checkOut() {
        if (isOccupied) {
            guestName = "";
            isOccupied = false;
            cout << "✅ Checked out successfully from Room " << roomNumber << ".\n";
        } else {
            cout << "❌ Room " << roomNumber << " is already empty.\n";
        }
    }

    void showDetails() {
        cout << "Room " << roomNumber << ": ";
        if (isOccupied)
            cout << "Occupied by " << guestName << "\n";
        else
            cout << "Available\n";
    }
};

// Global list of rooms
vector<Room> hotelRooms;

// Initialize rooms
void initializeRooms(int count) {
    for (int i = 1; i <= count; i++) {
        hotelRooms.push_back(Room(i));
    }
}

// Function to check in a guest
void checkInGuest() {
    int roomNo;
    string name;
    cout << "Enter room number: ";
    cin >> roomNo;
    cin.ignore();
    cout << "Enter guest name: ";
    getline(cin, name);
    if (roomNo >= 1 && roomNo <= hotelRooms.size()) {
        hotelRooms[roomNo - 1].checkIn(name);
    } else {
        cout << "❌ Invalid room number.\n";
    }
}

// Function to check out a guest
void checkOutGuest() {
    int roomNo;
    cout << "Enter room number: ";
    cin >> roomNo;
    if (roomNo >= 1 && roomNo <= hotelRooms.size()) {
        hotelRooms[roomNo - 1].checkOut();
    } else {
        cout << "❌ Invalid room number.\n";
    }
}

// Show status of all rooms
void showAllRooms() {
    cout << "\n📋 Room Status:\n";
    for (Room &room : hotelRooms) {
        room.showDetails();
    }
}

// 🔻 MAIN FUNCTION 🔻
int main() {
    int roomCount = 10; // Set number of rooms here
    initializeRooms(roomCount);

    int choice;
    do {
        cout << "\n========== HOTEL MANAGEMENT SYSTEM ==========\n";
        cout << "1. Check-in Guest\n";
        cout << "2. Check-out Guest\n";
        cout << "3. View All Rooms\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            checkInGuest();
            break;
        case 2:
            checkOutGuest();
            break;
        case 3:
            showAllRooms();
            break;
        case 4:
            cout << "🔚 Exiting the system. Thank you!\n";
            break;
        default:
            cout << "❌ Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
