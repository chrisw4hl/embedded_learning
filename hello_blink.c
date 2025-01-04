#include<avr/io.h>
#include<avr/interrupt.h>
//using https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf
//background information from https://www.youtube.com/watch?v=hX5k1OWqCtg&list=PLCfTdbBFZLXWOjRyKWdliCb-AvCyAP_9l&index=4
volatile uint8_t counter = 0;

int main(void){
  //set arduino pin 11 (at2560 port b5 to output)
  DDRB |= (1 << DDB5);
  //turn on TCCR0A pins to setup timing
  TCCR0A |= (1 << WGM01);
  TCCR0A |= (1 << COM0A1);
  //set timing scaling register
  OCR0A = 249;
  //setup OCIE0A compare inturrupt
  TIMSK0 |= (1 << OCIE0A);
  //setup global interrupt status register i-bit
  SREG |= (1 << 7);

  //also setup global interrupt (above may be redundant)
  sei();
  //setup prescaler
  TCCR0B |= (1 << CS02);

  while(1){

    //when counter has reached desired value (500 ms) toggle arduino pin 11, at2560 portb5, reset counter
    if(counter >= 125){
      PORTB ^= (1 << DDB5);
      counter = 0;
    }
  }
}

ISR (TIMER0_COMPA_vect)
{
  counter++;
}
