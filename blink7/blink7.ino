#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

// LCD control pins
#define RS PB0
#define EN PB1

// Send command to LCD
void lcd_command(unsigned char cmd) {
  PORTB = (PORTB & 0x0F) | (cmd & 0xF0);

  PORTB &= ~(1 << RS);

  PORTB |= (1 << EN);
  _delay_ms(1);
  PORTB &= ~(1 << EN);

  PORTB = (PORTB & 0x0F) | (cmd << 4);

  PORTB |= (1 << EN);
  _delay_ms(1);
  PORTB &= ~(1 << EN);

  _delay_ms(2);
}


// Send data to LCD
void lcd_data(unsigned char data) {
  PORTB = (PORTB & 0x0F) | (data & 0xF0);

  PORTB |= (1 << RS);

  PORTB |= (1 << EN);
  _delay_ms(1);
  PORTB &= ~(1 << EN);

  PORTB = (PORTB & 0x0F) | (data << 4);

  PORTB |= (1 << EN);
  _delay_ms(1);
  PORTB &= ~(1 << EN);

  _delay_ms(2);
}

// Initialize LCD
void lcd_init() {
  DDRB = 0xFF;

  _delay_ms(20);

  lcd_command(0x02);
  lcd_command(0x28);
  lcd_command(0x0C);
  lcd_command(0x06);
  lcd_command(0x01);
}

// Display string
void lcd_string(char *str) {
  while (*str) {
    lcd_data(*str++);
  }
}
int main(void) {
  int i;
  lcd_init();

  lcd_command(0x01);
  lcd_command(0x80);
  for (int i = 9; i <= 0; i--) 
  {
    lcd_string(i);
  }

  while (1) {
  }
}
