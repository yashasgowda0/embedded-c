#define F_CPU 160000000UL
#include<AVR/IO.h>
int main(void)
{
  DDRB |= (1<<PB3);
  PORTB |= (1<<PB3);
  while(1)
  {
  PORTB&~ -(1<<PB3);
  _delay_ms(500);
  }
  return 0;
}