#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEATS_PER_BUS 40
#define CONSOLE_WIDTH 80

typedef struct Seat
{
    int seat_number;
    int booked;
    struct Seat *next;
} Seat;

typedef struct Bus
{
    int bus_id;
    char route[100];
    Seat *seats;
    struct Bus *next;
} Bus;

Bus *head = NULL;

void printcenter(const char *text, int newline)
{
    int len = strlen(text);
    int spaces = (CONSOLE_WIDTH - len) / 2;
    printf("%*s%s", spaces, "", text);
    if (newline == 1)
    {
        printf("\n");
    }
}

Seat *createSeat(int seat_number)
{
    Seat *seat = (Seat *)malloc(sizeof(Seat));

    if (seat == NULL)
    {

        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    seat->seat_number = seat_number;
    seat->booked = 0;
    seat->next = NULL;

    return seat;
}

void addBus()
{

    Bus *newBus = (Bus *)malloc(sizeof(Bus));

    if (newBus == NULL)
    {

        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printcenter("Enter bus ID: ", 0);

    scanf("%d", &newBus->bus_id);

    printcenter("Enter route: ", 0);

    scanf("%s", &newBus->route);

    newBus->seats = NULL;
    newBus->next = NULL;

    for (int i = 1; i <= SEATS_PER_BUS; i++)
    {

        Seat *newSeat = createSeat(i);
        newSeat->next = newBus->seats;
        newBus->seats = newSeat;
    }

    if (head == NULL)
    {

        head = newBus;
    }

    else
    {

        Bus *temp = head;

        while (temp->next != NULL)
        {

            temp = temp->next;
        }

        temp->next = newBus;
    }

    printcenter("[Bus added successfully]", 1);
}

void cancelBus()
{

    int bus_id;
    printcenter("Enter Bus ID to cancel: ", 0);

    if (scanf("%d", &bus_id) != 1)
    {

        printf("Invalid input Please enter a number.\n");
        scanf("%*s");

        return;
    }

    Bus *prev = NULL;
    Bus *current = head;

    while (current != NULL)
    {

        if (current->bus_id == bus_id)
        {

            if (prev == NULL)
            {

                head = current->next;
            }

            else
            {
                prev->next = current->next;
            }

            Seat *tempSeat = current->seats;

            while (tempSeat != NULL)
            {

                Seat *temp = tempSeat;
                tempSeat = tempSeat->next;
                free(temp);
            }

            free(current);
            printcenter("[Bus canceled successfully]", 1);

            return;
        }

        prev = current;
        current = current->next;
    }

    printcenter("[Bus ID not found]", 1);
}

void displayBuses()
{

    if (head == NULL)
    {

        printcenter("[No buses available]", 1);

        return;
    }

    printf("\n");
    printcenter(" List of all buses:", 1);
    printcenter("-------------------", 1);

    Bus *current = head;
    int count = 1;

    while (current != NULL)
    {

        printf("                             %d. Bus ID: %d, Route: %s\n", count, current->bus_id, current->route);
        current = current->next;
        count++;
    }
}

void bookSeat()
{

    int bus_id, seat_number;

    printcenter("Enter Bus ID to book a seat: ", 0);

    if (scanf("%d", &bus_id) != 1)
    {

        printcenter("Invalid input. Please enter a number.\n", 1);
        scanf("%*s");

        return;
    }

    Bus *current = head;
    while (current != NULL)
    {

        if (current->bus_id == bus_id)
        {

            printcenter("Enter seat number (1-40): ", 0);

            if (scanf("%d", &seat_number) != 1)
            {

                printcenter("Invalid input. Please enter a number.\n", 1);
                scanf("%*s");

                return;
            }

            if (seat_number < 1 || seat_number > SEATS_PER_BUS)
            {

                printcenter("[Invalid seat number]\n", 1);
                return;
            }

            Seat *seat = current->seats;

            while (seat != NULL)
            {

                if (seat->seat_number == seat_number)
                {

                    if (seat->booked == 1)
                    {

                        printcenter("[This seat is already booked]\n", 1);
                    }

                    else
                    {

                        seat->booked = 1;
                        printcenter("[Seat booked successfully]\n", 1);
                    }
                    return;
                }

                seat = seat->next;
            }

            printcenter("[Seat number not found]\n", 1);
            return;
        }
        current = current->next;
    }
    printcenter("[Bus ID not found]\n", 1);
}

void cancelSeat()
{

    int bus_id, seat_number;
    printcenter("Enter Bus ID to cancel a seat: ", 0);

    if (scanf("%d", &bus_id) != 1)
    {

        printcenter("Invalid input. Please enter a number.\n", 1);
        scanf("%*s");
        return;
    }

    Bus *current = head;

    while (current != NULL)
    {

        if (current->bus_id == bus_id)
        {

            printcenter("Enter seat number (1-40): ", 0);

            if (scanf("%d", &seat_number) != 1)
            {

                printcenter("Invalid input. Please enter a number.\n", 1);
                scanf("%*s");
                return;
            }

            if (seat_number < 1 || seat_number > SEATS_PER_BUS)
            {

                printcenter("[Invalid seat number]\n", 1);
                return;
            }

            Seat *seat = current->seats;

            while (seat != NULL)
            {

                if (seat->seat_number == seat_number)
                {

                    if (seat->booked == 0)
                    {

                        printcenter("[This seat is not booked]\n", 1);
                    }

                    else
                    {

                        seat->booked = 0;
                        printcenter("[Seat cancellation successful]\n", 1);
                    }

                    return;
                }
                seat = seat->next;
            }
            printcenter("[Seat number not found]\n", 1);
            return;
        }
        current = current->next;
    }

    printcenter("[Bus ID not found]\n", 1);
}

void show_all_bus()
{

    if (head == NULL)
    {

        printcenter("[No buses available]", 1);
        return;
    }

    printf("\n");
    printcenter(" List of all buses", 1);
    printcenter("-------------------", 1);

    Bus *current = head;

    int list = 1;
    while (current != NULL)
    {

        printf("  Bus ID: %d, Route: %s\n\n", current->bus_id, current->route);
        printf("  Seats status: ");
        Seat *seat = current->seats;

        while (seat != NULL)
        {

            if (seat->booked == 0)
            {

                printf("%d:Not booked|  ", seat->seat_number);
            }
            else
            {
                printf("%d:Booked || ", seat->seat_number);
            }
            list++;
            seat = seat->next;
        }

        printf("\n");
        current = current->next;
    }
}

int main()
{
    system("color 1c");
    int adminPass;
    int passward = 234;
    int choice;

    while (1)
    {

        printcenter("\n", 1);
        printcenter("---------------------------", 1);
        printcenter(" DIU Bus Management System", 1);
        printcenter("---------------------------", 1);
        printcenter("1. Admin", 1);
        printcenter("2. User", 1);
        printcenter("3. Exit", 1);
        printcenter("Enter your choice: ", 0);

        if (scanf("%d", &choice) != 1)
        {

            printf("Invalid input Please enter a number.\n");
            scanf("%*s");
            continue;
        }

        switch (choice)
        {

        case 1:
            printcenter("Enter Admin Password:", 0);
            scanf("%d", &adminPass);
            if (adminPass == passward)
            {

                while (1)
                {
                    printcenter("\n", 1);
                    printcenter(" Admin Menu", 1);
                    printcenter("------------", 1);
                    printcenter("1. Add New Bus", 1);
                    printcenter("2. Cancel Bus", 1);
                    printcenter("3. Display All Buses", 1);
                    printcenter("4. Back to Main Menu", 1);
                    printcenter("Enter your choice: ", 0);

                    if (scanf("%d", &choice) != 1)
                    {
                        printf("Invalid input. Please enter a number.\n");
                        scanf("%*s");
                        continue;
                    }

                    switch (choice)
                    {
                    case 1:
                        addBus();
                        break;

                    case 2:
                        cancelBus();
                        break;

                    case 3:
                        displayBuses();
                        break;

                    case 4:
                        break;
                    default:
                        printcenter("Invalid choice. Please try again.", 1);
                    }
                    if (choice == 4)
                        break;
                }
                break;
            }

            else
            {
                printcenter("[INVALID PASSWARD]", 1);
            }
            break;

        case 2:
            while (1)
            {
                printcenter("\n", 1);
                printcenter(" User Menu", 1);
                printcenter("------------", 1);
                printcenter("1. Book a Seat", 1);
                printcenter("2. Cancel a Seat", 1);
                printcenter("3. Show All Buses", 1);
                printcenter("4. Back to Main Menu", 1);
                printcenter("Enter your choice: ", 0);

                if (scanf("%d", &choice) != 1)
                {

                    printf("Invalid input. Please enter a number.\n");
                    scanf("%*s");
                    continue;
                }

                switch (choice)
                {

                case 1:
                    bookSeat();
                    break;

                case 2:
                    cancelSeat();
                    break;

                case 3:
                    show_all_bus();
                    break;

                case 4:
                    break;

                default:
                    printcenter("Invalid choice. Please try again.", 1);
                }
                if (choice == 4)
                    break;
            }
            break;

        case 3:
            printcenter("Exiting program....", 1);
            exit(0);
            break;

        default:
            printcenter("Invalid choice Please choose again.", 1);
        }
    }

    return 0;
}
