#include <BajaLCD.h>

void BajaLCD::custom0(int col)
{
    this->setCursor(col, 0);
    this->write((byte)0);
    this->write((byte)7);
    this->write((byte)7);
    this->write((byte)2);
    this->setCursor(col, 1);
    this->write((byte)7);
    this->write("  ");
    this->write((byte)7);
    this->setCursor(col, 2);
    this->write((byte)7);
    this->write("  ");
    this->write((byte)7);
    this->setCursor(col, 3);
    this->write((byte)3);
    this->write((byte)7);
    this->write((byte)7);
    this->write((byte)5);
}

void BajaLCD::custom1(int col)
{
    this->setCursor(col + 1, 0);
    this->write((byte)1);
    this->write((byte)2);
    this->setCursor(col + 2, 1);
    this->write((byte)7);
    this->setCursor(col + 2, 2);
    this->write((byte)7);
    this->setCursor(col + 1, 3);
    this->write((byte)4);
    this->write((byte)7);
    this->write((byte)4);
}
void BajaLCD::custom2(int col)
{
    this->setCursor(col, 0);
    this->write((byte)1);
    this->write((byte)1);
    this->write((byte)1);
    this->write((byte)2);
    this->setCursor(col, 1);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)5);
    this->setCursor(col, 2);
    this->write((byte)7);
    this->setCursor(col, 3);
    this->write((byte)3);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)4);
}
void BajaLCD::custom3(int col)
{
    this->setCursor(col, 0);
    this->write((byte)1);
    this->write((byte)1);
    this->write((byte)1);
    this->write((byte)2);
    this->setCursor(col, 1);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)7);
    this->setCursor(col + 3, 2);
    this->write((byte)7);
    this->setCursor(col, 3);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)5);
}

void BajaLCD::custom4(int col)
{
    this->setCursor(col, 0);
    this->write((byte)0);
    this->write("  ");
    this->write((byte)7);
    this->setCursor(col, 1);
    this->write((byte)3);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)7);
    this->setCursor(col + 3, 2);
    this->write((byte)7);
    this->setCursor(col + 3, 3);
    this->write((byte)7);
}

void BajaLCD::custom5(int col)
{
    this->setCursor(col, 0);
    this->write((byte)0);
    this->write((byte)1);
    this->write((byte)1);
    this->write((byte)1);
    this->setCursor(col, 1);
    this->write((byte)3);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)4);
    this->setCursor(col + 3, 2);
    this->write((byte)7);
    this->setCursor(col, 3);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)5);
}

void BajaLCD::custom6(int col)
{
    this->setCursor(col, 0);
    this->write((byte)0);
    this->write((byte)1);
    this->write((byte)1);
    this->write((byte)1);
    this->setCursor(col, 1);
    this->write((byte)7);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)4);
    this->setCursor(col, 2);
    this->write((byte)7);
    this->write("  ");
    this->write((byte)7);
    this->setCursor(col, 3);
    this->write((byte)3);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)5);
}

void BajaLCD::custom7(int col)
{
    this->setCursor(col, 0);
    this->write((byte)1);
    this->write((byte)1);
    this->write((byte)1);
    this->write((byte)2);
    this->setCursor(col + 3, 1);
    this->write((byte)7);
    this->setCursor(col + 3, 2);
    this->write((byte)7);
    this->setCursor(col + 3, 3);
    this->write((byte)7);
}

void BajaLCD::custom8(int col)
{
    this->setCursor(col, 0);
    this->write((byte)0);
    this->write((byte)1);
    this->write((byte)1);
    this->write((byte)2);
    this->setCursor(col, 1);
    this->write((byte)7);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)7);
    this->setCursor(col, 2);
    this->write((byte)7);
    this->write("  ");
    this->write((byte)7);
    this->setCursor(col, 3);
    this->write((byte)3);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)5);
}

void BajaLCD::custom9(int col)
{
    this->setCursor(col, 0);
    this->write((byte)0);
    this->write((byte)1);
    this->write((byte)1);
    this->write((byte)2);
    this->setCursor(col, 1);
    this->write((byte)3);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)7);
    this->setCursor(col + 3, 2);
    this->write((byte)7);
    this->setCursor(col, 3);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)4);
    this->write((byte)5);
}

void BajaLCD::clearnumber(int col)
{
    this->setCursor(col, 0);
    this->print("    ");
    this->setCursor(col, 1);
    this->print("    ");
    this->setCursor(col, 2);
    this->print("    ");
    this->setCursor(col, 3);
    this->print("    ");
}

void BajaLCD::print_digit(int number, int bit)
{
    int col;
    if (bit == 0)
        col = 1;
    else
        col = 6;
    if (number == 0 && bit == 1)
        this->custom0(col);
    else if (number == 1)
        this->custom1(col);
    else if (number == 2)
        this->custom2(col);
    else if (number == 3)
        this->custom3(col);
    else if (number == 4)
        this->custom4(col);
    else if (number == 5)
        this->custom5(col);
    else if (number == 6)
        this->custom6(col);
    else if (number == 7)
        this->custom7(col);
    else if (number == 8)
        this->custom8(col);
    else if (number == 9)
        this->custom9(col);
}
