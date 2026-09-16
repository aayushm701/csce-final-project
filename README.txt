Campus Resource Reservation System

Build from the project directory:

    c++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp src/CampusSystem.cpp src/ReservationList.cpp -Iinclude -o campus

Run:

    ./campus

Data files use pipe-separated fields. Resources are read from data/resources.txt
and saved reservations can be loaded from data/reservations.txt.

Project structure:

    include/  Public class and data declarations
    src/      Implementations and the program entry point
    data/     Input files

The program demonstrates a vector for resources, a linked list for active
reservations, queues for waiting lists, a stack for cancellation history, linear
search, and merge sort.