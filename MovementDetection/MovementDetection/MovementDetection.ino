//LingShun lab
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> //引用I2C库
 
//设置LCD1602设备地址，这里的地址是0x3F，一般是0x20，或者0x27，具体看模块手册
LiquidCrystal_I2C lcd(0x27,16,2); //这里是0x27

#define PIR_sensor 14
#define ledpin 7


void setup() 
{
  pinMode(PIR_sensor, INPUT);
  lcd.init();                  // 初始化LCD
  lcd.backlight();             //设置LCD背景等亮

  lcd.setCursor(0,0); 
  lcd.print("    Automatic    ");
  lcd.setCursor(0,1); 
  lcd.print("  Lights opener   ");
  delay(3000);
  lcd.clear();

}

void loop() 
{
  if(digitalRead(PIR_sensor))
  {
    lcd.setCursor(0,0);
    lcd.print("Movement Detected");
    lcd.setCursor(0, 1);
    lcd.print("    Lights On    ");
    digitalWrite(ledpin, HIGH);         // gate opening
    delay(1000);
    lcd.clear();
    lcd.print("   Lights Off    ");
    digitalWrite(ledpin, LOW);           // gate closing
    delay(1000);
  }
   else 
  {
    lcd.setCursor(0,0);
    lcd.print("   No Movement   ");
    lcd.setCursor(0,1);
    lcd.print("   Lights Off   ");
    digitalWrite(ledpin, LOW);

  }

}

