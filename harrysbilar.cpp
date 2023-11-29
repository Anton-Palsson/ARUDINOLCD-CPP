#include "lcd.h"

// Funktion för att visa information om Kund 1
void displayCustomerInfo(const Customer& customer) {
    lcd.Clear();
    lcd.GoTo(0, 0);
    lcd.WriteText(customer.name);
    lcd.GoTo(0, 1);
    lcd.WriteText(getNextText(customer.textOptions));
}

const char* getNextText(const char* textOptions[2]) {
    return (rand() % 2 == 0) ? textOptions[0] : textOptions[1];
}

