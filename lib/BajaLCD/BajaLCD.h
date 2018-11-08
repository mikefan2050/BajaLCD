/*
A set of custom made large numbers for a 16x2 LCD using the
LiquidCrystal librabry. Works with displays compatible with the
Hitachi HD44780 driver.

The Cuicuit:
 LCD RS pin to D12
 LCD Enable pin to D11
 LCD D4 pin to D5
 LCD D5 pin to D4
 LCD D6 pin to D3
 LCD D7 pin to D2
 LCD Vee tied to a pot to control brightness
 LCD Vss and R/W tied to ground
 LCD Vcc to +5V
 LCD pin 15 tied to pushbutton for control of backlight
 
This code has the custum numbers counting from 0 to 9 on
the left hand side of the LCD with a 1 sec delay between
numbers. On the right is a counter tracking the number of
times the program has looped.
 
Made by Michael Pilcher
2/9/2010
*/

#ifndef __LCD_INCLUDED__
#define __LCD_INCLUDED__

#include <Arduino.h>
#include <LiquidCrystal.h>

class BajaLCD : public LiquidCrystal
{
  private:
    byte LT[8] = {
        B00111,
        B01111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111};
    byte UB[8] = {
        B11111,
        B11111,
        B11111,
        B00000,
        B00000,
        B00000,
        B00000,
        B00000};
    byte RT[8] = {
        B11100,
        B11110,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111};
    byte LL[8] = {
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B01111,
        B00111};
    byte LB[8] = {
        B00000,
        B00000,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111,
        B11111};
    byte LR[8] = {
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11110,
        B11100};
    byte MB[8] = {
        B11111,
        B11111,
        B11111,
        B00000,
        B00000,
        B00000,
        B11111,
        B11111};
    byte block[8] = {
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111,
        B11111};

  public:
    BajaLCD(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, 
    uint8_t d2, uint8_t d3)
    : LiquidCrystal(rs, enable, d0, d1, d2, d3) {
        this->createChar(0,LT);
        this->createChar(1,UB);
        this->createChar(2,RT);
        this->createChar(3,LL);
        this->createChar(4,LB);
        this->createChar(5,LR);
        this->createChar(6,MB);
        this->createChar(7,block);

        this->begin(20, 4);
    }

    void custom0(int col);
    void custom1(int col);
    void custom2(int col);
    void custom3(int col);
    void custom4(int col);
    void custom5(int col);
    void custom6(int col);
    void custom7(int col);
    void custom8(int col);
    void custom9(int col);
    void clearnumber(int col);
    void print_digit(int number, int bit);
};

#endif