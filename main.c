#include <stdio.h>

#define MAX_ROOMS 5  // Max number of rooms

// Function prototypes
void initializeSystem(int rooms, int lights[], float temperatures[], int motion[], int locks[]);
void displayMenu();
void controlLights(int rooms, int lights[]);
void readTemperature(int rooms, float temperatures[]);
void detectMotion(int rooms, int motion[]);
void securitySystem(int rooms, int locks[]);
void analyzeHouseStatus(int rooms, int lights[], float temperatures[], int motion[], int locks[]);

int main() {
    int rooms;
    
    printf("Enter the number of rooms (Max %d): ", MAX_ROOMS);
    scanf("%d", &rooms);
    
    if (rooms > MAX_ROOMS || rooms <= 0) {
        printf("Invalid number of rooms! Setting to %d by default.\n", MAX_ROOMS);
        rooms = MAX_ROOMS;
    }

    int lights[rooms], motion[rooms], locks[rooms];
    float temperatures[rooms];

    initializeSystem(rooms, lights, temperatures, motion, locks);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                controlLights(rooms, lights);
                break;
            case 2:
                readTemperature(rooms, temperatures);
                break;
            case 3:
                detectMotion(rooms, motion);
                break;
            case 4:
                securitySystem(rooms, locks);
                break;
            case 5:
                analyzeHouseStatus(rooms, lights, temperatures, motion, locks);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Initialize system with default values
void initializeSystem(int rooms, int lights[], float temperatures[], int motion[], int locks[]) {
    for (int i = 0; i < rooms; i++) {
        lights[i] = 0;  // Lights OFF
        locks[i] = 1;   // Locked
        motion[i] = 0;  // No motion
        temperatures[i] = 22 + i;  // Example temperature values
    }
    printf("System initialized with %d rooms.\n", rooms);
}

// Display menu options
void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

// Toggle light status
void controlLights(int rooms, int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", rooms);
    scanf("%d", &room);

    if (room >= 1 && room <= rooms) {
        lights[room - 1] = !lights[room - 1];
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number!\n");
    }
}

// Read and display temperature
void readTemperature(int rooms, float temperatures[]) {
    int room;
    printf("Enter room number to check temperature (1-%d): ", rooms);
    scanf("%d", &room);

    if (room >= 1 && room <= rooms) {
        printf("Temperature in Room %d: %.1f°C\n", room, temperatures[room - 1]);
    } else {
        printf("Invalid room number!\n");
    }
}

// Motion sensor
void detectMotion(int rooms, int motion[]) {
    int room;
    printf("Enter room number to check motion (1-%d): ", rooms);
    scanf("%d", &room);

    if (room >= 1 && room <= rooms) {
        printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
    } else {
        printf("Invalid room number!\n");
    }
}

// Doors
void securitySystem(int rooms, int locks[]) {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", rooms);
    scanf("%d", &room);

    if (room >= 1 && room <= rooms) {
        locks[room - 1] = !locks[room - 1];
        printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
    } else {
        printf("Invalid room number!\n");
    }
}

// House status summary
void analyzeHouseStatus(int rooms, int lights[], float temperatures[], int motion[], int locks[]) {
    printf("\n-----House Status Summary -----\n");
    for (int i = 0; i < rooms; i++) {
        printf("Room %d: Light %s, Temp %.1f°C, %s, %s\n", 
            i + 1, 
            lights[i] ? "ON" : "OFF", 
            temperatures[i], 
            motion[i] ? "Motion Detected" : "No Motion", 
            locks[i] ? "Locked" : "Unlocked");
    }
}
