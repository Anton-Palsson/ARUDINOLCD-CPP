
#include "lcd.h"
#include <util/delay.h>

void scrollChoice(const char* choice, int displayWidth, int scrollSpeed, int delayBetweenScrolls) {
    HD44780 lcd;
    lcd.Initalize();

    int choiceLength = strlen(choice);

    while (1) {
        for (int i = 0; i <= choiceLength + displayWidth; i++) {
            lcd.Clear(); // Nollställ hela skärmen innan du skriver ny text

            if (i < displayWidth) {
                lcd.GoTo(displayWidth - i, 0);
                lcd.WriteText(choice + i);
            } else {
                lcd.GoTo(0, 0);  // Återgå till början av första raden
                lcd.WriteText(choice);
            }

            _delay_ms(scrollSpeed);
        }
        _delay_ms(delayBetweenScrolls);
    }
}

// Funktion för att visa information om Kund 1
void displayCustomerInfo(const Customer& customer) {
    scrollChoice("Köp bil hos Harry", 16, 500, 2000);

    lcd.Clear();
    lcd.GoTo(0, 0);
    lcd.WriteText(customer.name);
    lcd.GoTo(0, 1);
    lcd.WriteText(getNextText(customer.textOptions));
}

const char* getNextText(const char* textOptions[2]) {
    return (rand() % 2 == 0) ? textOptions[0] : textOptions[1];
}
