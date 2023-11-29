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


//SCROLL SOM FUNKAR:
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void) {
    HD44780 lcd;
    lcd.Initalize();

    char text[] = "HEEEEEEJSAN ";
    int textLength = 12;
    int displayWidth = 16;
    int scrollSpeed = 500;  // Justera för önskad scrollhastighet
    int delayBetweenScrolls = 2000;  // Justera för väntetid innan nästa scrollning

    while (1) {
        for (int i = 0; i <= textLength + displayWidth; i++) {
            lcd.Clear(); // Nollställ hela skärmen innan du skriver ny text

            if (i < displayWidth) {
                lcd.GoTo(displayWidth - i, 0);
                lcd.WriteText(text + i);
            } else {
                lcd.GoTo(0, 0);  // Återgå till början av första raden
                lcd.WriteText(text);
            }

            _delay_ms(scrollSpeed);
        }
        _delay_ms(delayBetweenScrolls);
    }

    return 0;
}
