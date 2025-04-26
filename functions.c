#include <stdio.h>

#define NUM_MOVIES 3
#define ROWS 5
#define COLS 5
#define MAX_BOOKINGS (NUM_MOVIES * ROWS * COLS)
#define BOOKINGS_FILE "bookings.dat"

const char *movies[NUM_MOVIES] = {"Movie A", "Movie B", "Movie C"};

static int seats[NUM_MOVIES][ROWS][COLS] = {0};
static struct Booking { int movie; int row; int col; } bookings[MAX_BOOKINGS];
static int booking_count = 0;

void loadSeats() {
    FILE *file = fopen(BOOKINGS_FILE, "r");
    if (!file) return;
    int m, r, c;
    while (fscanf(file, "%d %d %d", &m, &r, &c) == 3) {
        if (m >= 0 && m < NUM_MOVIES && r >= 0 && r < ROWS && c >= 0 && c < COLS) {
            seats[m][r][c] = 1;
            bookings[booking_count++] = (struct Booking){m, r, c};
        }
    }
    fclose(file);
}

void displayMovies() {
    for (int m = 0; m < NUM_MOVIES; m++) {
        printf("\n%d. %s\n", m + 1, movies[m]);
        printf("   Seats (O=available, X=booked):\n");
        for (int i = 0; i < ROWS; i++) {
            printf(" ");
            for (int j = 0; j < COLS; j++) {
                printf("%c ", seats[m][i][j] ? 'X' : 'O');
            }
            printf("\n");
        }
    }
}

void bookTicket() {
    int m, r, c;
    displayMovies();
    printf("Select movie number: ");
    if (scanf("%d", &m) != 1 || m < 1 || m > NUM_MOVIES) {
        printf("Invalid movie selection.\n"); while (getchar()!='\n'); return;
    }
    m--;
    printf("Enter row (1-%d): ", ROWS);
    if (scanf("%d", &r) != 1 || r < 1 || r > ROWS) {
        printf("Invalid row.\n"); while (getchar()!='\n'); return;
    }
    r--;
    printf("Enter column (1-%d): ", COLS);
    if (scanf("%d", &c) != 1 || c < 1 || c > COLS) {
        printf("Invalid column.\n"); while (getchar()!='\n'); return;
    }
    c--;
    if (seats[m][r][c]) {
        printf("Seat already booked.\n");
        return;
    }
    seats[m][r][c] = 1;
    bookings[booking_count++] = (struct Booking){m, r, c};
    FILE *file = fopen(BOOKINGS_FILE, "a");
    if (file) {
        fprintf(file, "%d %d %d\n", m, r, c);
        fclose(file);
        printf("Ticket booked for %s at row %d, column %d.\n", movies[m], r + 1, c + 1);
    } else {
        printf("Error saving booking.\n");
    }
}

void viewBookings() {
    if (booking_count == 0) {
        printf("No bookings found.\n");
        return;
    }
    printf("\nBooked Tickets:\n");
    for (int i = 0; i < booking_count; i++) {
        int m = bookings[i].movie;
        printf("%d. %s - Row %d, Column %d\n", i + 1, movies[m], bookings[i].row + 1, bookings[i].col + 1);
    }
}
