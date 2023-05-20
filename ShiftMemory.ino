#define LATCH 5
#define CLOCK 6
#define DATA 4 

byte leds = 0;
int loops = 0;

void setup()
{
    pinMode(LATCH, OUTPUT);
    pinMode(DATA, OUTPUT);
    pinMode(CLOCK, OUTPUT);
}

void updateRegister()
{
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, 0, leds);
    digitalWrite(LATCH, HIGH);
}

void loop()
{
    leds = 0;
    updateRegister();
    delay(500);
    int b = loops % 2;

    for (int i = 0; i < 8; i++)
    {
        b = !b;
      	
        leds |= b << i;
      
        updateRegister();
        delay(200);
    }

    loops++;
}