#include <Arduino.h>
#include <math.h>
#define resistor 97700
#define constanteB 3950
#define logtemppadrao 11.512925465
#define temp25 0.00335401643
#define adctensao 0.00346041055
 float Termistor(int rawadc)
 {
 float temp;
 float resistance;
 resistance = resistor*((1023/rawadc)-1);
 temp=(logf(resistance)-logtemppadrao)/constanteB+temp25;
 temp=1/temp-273.15;
 return temp;
 }

float val = 0;
float temperature;
void setup()
{
  Serial.begin(9600);              //  setup serial
  pinMode(A5, INPUT);
  pinMode(8, INPUT);
}

void loop()
{

  //Tensão
  Serial.print("Tensão: ");
  val = analogRead(A0)*adctensao;
  Serial.println(val);
  delay(1000);

  //Temperatura
  temperature = Termistor(analogRead(A5));
  Serial.print("Temperatura: "); 
  Serial.print(temperature); 
  Serial.println(" C");
  delay(1000); 
  
  //Serial.print("Hall: ");
  //Serial.println(analogRead(A7));
  //delay(100);

}
