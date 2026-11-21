#define F_CPU 160000000UL
#include<AVR/IO.h>
int main(void)
{
  DDRB |= (1<<PB3);
   DDRC |= (1<<PC4);
   DDRC |= (1<<PC5); 
 
    while(1)
  {
     PORTB |= (1<<PB3);
     _delay_ms(500);     //red light on and off
     PORTB&~ -(1<<PB3);

     _delay_ms(1000);

     PORTC |=(1<<PC4);
     _delay_ms(500);    //yellow light on and off
      PORTB&~ -(1<<PC4);

      _delay_ms(1000);

      PORTC |=(1<<PC5);
     _delay_ms(500);    //green light on and off
      PORTC&~ -(1<<PC5);



     
  return 0;
  }
}