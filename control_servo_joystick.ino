#include <Servo.h>
Servo servoMotor;
int xPin = A0;
int yPin = A1;

int contador1 = 0;
int xPosition = 0;
int yPosition = 0;
int buttonState = 0;

void setup()
{

  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  servoMotor.attach(8);
 
}

void loop()
{
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);

  if (xPosition == 0 && contador1 >= 0)
  {
    contador1 = contador1 - 10;
    servoMotor.write(contador1);
  }
  if (xPosition == 1023 && contador1 <= 180)
  {
    contador1 = contador1 + 10;
    servoMotor.write(contador1);
  }

  Serial.print("contador: ");
  Serial.print(contador1);
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");

}
