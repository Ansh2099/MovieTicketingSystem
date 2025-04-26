# Movie Ticket Booking System

A simple console-based movie ticket booking application written in C. It uses basic file I/O to persist bookings and a fixed-size 5×5 seating chart for each movie.

## Features
- View available movies and seat layout (O = available, X = booked)
- Book tickets by selecting movie, row, and column
- View all booked tickets
- Persists bookings in a text file (`bookings.dat`)

## File Structure
```
main.c        // Main menu and program entry point
functions.c   // Business logic and file handling functions
bookings.dat  // Data file storing bookings (created on first booking)
booking.exe   // Compiled executable
``` 

## Prerequisites
- GCC compiler (e.g., MinGW on Windows)

## Compile
```bash
gcc main.c functions.c -o booking.exe
```

## Run
```bash
# On Windows command prompt:
booking.exe

# On Unix-like shell:
./booking.exe
```

## Usage
1. **View available movies**: Displays each movie's seating grid.
2. **Book a ticket**: Enter movie number, row (1–5), and column (1–5).
3. **View booked tickets**: Lists all tickets booked so far.
4. **Exit**: Quit the program.

Booking data is appended to `bookings.dat`, so bookings persist between runs.

---
*Created on 2025-04-26*
