#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include <stdlib.h>
#include <string.h>

struct Customer {
    const char* name;
    int frequency;
};

const Customer customers[] = {
    {" Harrys bilar ", 9},
    {" Farmor Anka ", 4},
    {" Knegar Petter ", 6},
    {" Detektivbyra ", 8},
    {" Virusskydd ", 1}
};

const int numCustomers = sizeof(customers) / sizeof(customers[0]);

HD44780 lcd;

void scrollText(const char* text, int durationInSeconds) {
    int textLength = strlen(text);
    int displayWidth = 16;
    int scrollSpeed = 300;

    int iterations = (durationInSeconds * 1000) / (textLength + displayWidth * scrollSpeed);

    for (int j = 0; j < iterations; j++) {
        for (int i = 0; i < textLength; i++) {  // Ändra här
            lcd.Clear();

            lcd.GoTo(displayWidth - i, 0);
            lcd.WriteText(text + i);

            _delay_ms(scrollSpeed);
        }
    }
}

void staticText(const char* text) {
    lcd.Clear();
    lcd.GoTo(0, 0);
    lcd.WriteText(text);
    _delay_ms(20000);
}

void svartePetter(){
   lcd.Initalize();

    int randomValue = rand() % 2;

    if (randomValue == 0) {
        scrollText("Lat Petter bygga åt dig ", 20);
    } else {
        staticText("Bygga svart?                            Ring Petter ");
    }

}

void virusSkydd(void){
     lcd.Initalize();

    int randomValue = rand() % 2;

    if (randomValue == 0) {
        scrollText("Synas här? IOT:s Reklambyrå", 10);
}
}

void farmorAnka() {
    lcd.Initalize();

    int randomValue = rand() % 2;

    if (randomValue == 0) {
        scrollText("Kop paj hos Farmor Anka ", 20);
    } else {
        staticText("Skynda innan                            Leo tar all paj ");
    }
}

void harrysBilar() {
    lcd.Initalize();

    int randomValue = rand() % 2;

    if (randomValue == 0) {
        scrollText("Kop bil hos Harry ", 20);
    } else {
        staticText("En god bilaffar                         (for Harry!) ");
    }
}

void detektivByra() {
    lcd.Initalize();

    int randomValue = rand() % 2;

    if (randomValue == 0) {
        staticText("Mysterier?                              Ring Langben! ");
    } else {
        staticText("Langben fixar                           biffen ");
    }
}

void displayCustomer(const char* customer) {
    lcd.Clear();
    lcd.GoTo(0, 0);
    lcd.WriteText(customer);
}

int getNextCustomerIndex(int currentIndex) {
    int totalFrequency = 0;

    for (int i = 0; i < numCustomers; ++i) {
        totalFrequency += customers[i].frequency;
    }

    int randomValue = rand() % totalFrequency + 1;

    for (int i = 0; i < numCustomers; ++i) {
        randomValue -= customers[i].frequency;
        if (randomValue <= 0 && i != currentIndex) {
            return i;
        }
    }

    return getNextCustomerIndex(currentIndex);
}

void startProgram(void) {
    lcd.Initalize();

    int currentIndex = -1;
    int nextIndex;

    while (1) {
        nextIndex = getNextCustomerIndex(currentIndex);

        currentIndex = nextIndex;

        displayCustomer(customers[nextIndex].name);

        if (strcmp(customers[nextIndex].name, " Harrys bilar ") == 0) {
            harrysBilar();
        } else if (strcmp(customers[nextIndex].name, " Farmor Anka ") == 0) {
            farmorAnka();
        } else if (strcmp(customers[nextIndex].name, " Knegar Petter ") == 0) {
            svartePetter();
        } else if (strcmp(customers[nextIndex].name, " Detektivbyra ") == 0) {
            detektivByra();
        } else if (strcmp(customers[nextIndex].name, " Virusskydd ") == 0) {
            virusSkydd();
        }

      
    }
}

int main(void) {
    startProgram();
    return 0;
}
