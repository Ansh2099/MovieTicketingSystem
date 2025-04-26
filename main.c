#include <stdio.h>

// Function prototypes
void loadSeats();
void displayMovies();
void bookTicket();
void viewBookings();

int main() {
    loadSeats();
    int choice;
    do {
        printf("\nMovie Ticket Booking System\n");
        printf("1. View available movies\n");
        printf("2. Book a ticket\n");
        printf("3. View booked tickets\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = 0;
        }
        switch (choice) {
            case 1: displayMovies(); break;
            case 2: bookTicket(); break;
            case 3: viewBookings(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
