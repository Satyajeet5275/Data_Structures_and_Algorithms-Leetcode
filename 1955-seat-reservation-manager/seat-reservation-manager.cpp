
class SeatManager {
private:
    std::set<int> seats; // Use a set to store available seats.

public:
    SeatManager(int n) {
        if (n <= 0) {
            throw std::invalid_argument("Invalid value of n.");
        }

        // Initialize available seats from 1 to n.
        for (int i = 1; i <= n; ++i) {
            seats.insert(i);
        }
    }

    int reserve() {
        if (seats.empty()) {
            return -1; // No available seats.
        }
        
        int reservedSeat = *seats.begin(); // Get the smallest available seat.
        seats.erase(reservedSeat); // Remove the seat from available seats.
        return reservedSeat;
    }

    void unreserve(int seatNumber) {
        if (seatNumber > 0) {
            seats.insert(seatNumber); // Add the seat back to available seats.
        }
    }
};