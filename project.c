#include <stdio.h>

#define TOTAL_SEATS 10

int seats[TOTAL_SEATS];

// Function to initialize seats
void initializeSeats() {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i] = 0; // 0 = available
    }
}

// Function to display seat status
void displaySeats() {
    printf("\nSeat Status:\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (seats[i] == 0)
            printf("Seat %d : Available\n", i + 1);
        else
            printf("Seat %d : Booked\n", i + 1);
    }
}

// Function to book a seat
void bookSeat() {
    int seatNo;
    printf("\nEnter seat number to book (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
    } 
    else if (seats[seatNo - 1] == 1) {
        printf("Seat already booked!\n");
    } 
    else {
        seats[seatNo - 1] = 1;
        printf("Seat %d booked successfully!\n", seatNo);
    }
}

// Function to cancel booking
void cancelSeat() {
    int seatNo;
    printf("\nEnter seat number to cancel (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNo);

    if (seatNo < 1 || seatNo > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
    } 
    else if (seats[seatNo - 1] == 0) {
        printf("Seat is already available!\n");
    } 
    else {
        seats[seatNo - 1] = 0;
        printf("Seat %d booking cancelled!\n", seatNo);
    }
}

int main() {
    int choice;

    initializeSeats();

    do {
        printf("\n=== Railway Ticket Booking System ===\n");
        printf("1. View Seat Status\n");
        printf("2. Book Seat\n");
        printf("3. Cancel Seat\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                cancelSeat();
                break;
            case 4:
                printf("Thank you for using the system!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}