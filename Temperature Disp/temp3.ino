#include<LiquidCrystal.h>  // Importing library for the LCD display
const int sensor_pin = A1; 
LiquidCrystal lcd(12, 11, 2, 3, 4, 5);

void setup()
{
 lcd.begin(16, 2);   // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
 Serial.begin(9600);

 byte degree_symbol[8]={   // Creating a custom character, the degree "°" unit
  0b00111,
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
lcd.createChar(1,degree_symbol);

}

void loop()
{
  
  int sensor_data = analogRead(sensor_pin);  // Reading the sensor data 
  float voltage = sensor_data * (5.0 / 1024.0);   // Converting the sensor values into voltage values
  float temperature_Celsius = (voltage - 0.5) * 100;  // Mapping the voltage values onto units of temperature
  float temperature_Fahrenheit = (temperature_Celsius * 9.0 / 5.0) + 32.0;
 
  delay(1000); 
  // Output to the LCD display
  lcd.setCursor(0,0);          
  lcd.print("Temperature"); 
  lcd.setCursor(0,1);           
  lcd.print(temperature_Celsius);
  lcd.setCursor(5,1);
  lcd.write(1);    // Prints the custom character created previously
  lcd.print("C");
  lcd.print(" ");
  lcd.print(temperature_Fahrenheit);
  lcd.setCursor(12,1);
  lcd.write(1);
  lcd.print("F");
  Serial.println(temperature_Celsius);
}
