#include <Arduino.h>
#include <BajaLCD.h>
#define MAXINTERVAL 4200 //calculated from 1mph
#define INT_STEP 40
#define UNIT "MPH"

// initialize the interface pins
BajaLCD lcd(12, 11, 5, 4, 6, 2);
int sensorPin = 3; // input pin, use digital
int interval;
int read_count;
float speed;

//record every reading from hall effect sensor
void hit()
{
    read_count += 1;
}

//timer1 ISR
ISR(TIMER1_COMPA_vect)
{
    if (read_count > 0) {
        //if there is reading, calculate speed + clear the read_count
        //pi * circu * 1000 * 60 * 60 / (interval * 63360)
        speed = (float)read_count * 4105.37 / (float)interval;
        read_count = 0;
        interval = 0;
    } else if (interval < MAXINTERVAL) {
        //if there is no reading, increment the time interval
        interval += INT_STEP;
    }

    if (interval >= MAXINTERVAL) {
        //check if the wheel if still + reset interval
        speed = 0;
        interval = 0;
    }
}

void setup()
{
    read_count = 0;
    interval = 0;

    //timer1 setup
    cli();
    TCCR1A = 0; // set entire TCCR1A register to 0
    TCCR1B = 0; // same for TCCR1B
    TCNT1 = 0;
    // set timer count for every 40ms
    OCR1A = 625;
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS11 bit for 8 prescaler
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // enable timer compare interrupt
    TIMSK1 |= _BV(OCIE1A);
    sei();
    
    //for debug
    //Serial.begin(9600);
    //Serial.println("begin");

    //RISING for debouning?
    attachInterrupt(digitalPinToInterrupt(sensorPin), hit, RISING);
}

void loop()
{
    //display speed every 0.5 sec
    int i = (int)speed;
    int least = i % 10;
    int tenth = i / 10;
    lcd.clearnumber(1);
    lcd.clearnumber(6);
    lcd.print_digit(tenth, 0);
    lcd.print_digit(least, 1);
    lcd.setCursor(11, 3);
    lcd.print(UNIT);
    delay(800);
}