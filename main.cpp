#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

#define LED_PIN 2

int main(void) {
    HD44780 lcd;
    lcd.Initalize();
    lcd.GoTo(0, 0);
    lcd.WriteText("HEEEEEEJSAN ");

    char text[50];
    return 0;
}
