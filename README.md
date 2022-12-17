# 一、电路连接
## PIR运动检测器
| PIR运动检测器引脚 | Arduino引脚 |
|--|--|
| VCC | 5V |
| GND | GND |
| OUT | A0(14) |

![在这里插入图片描述](https://img-blog.csdnimg.cn/d1d9396814d543dfaab5cc13475847d2.png)

## LCD1602IIC
| LCD1602IIC引脚 | Arduino引脚 |
|--|--|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

我这里的LCD1602是IIC的，所以只需要4根线

![在这里插入图片描述](https://img-blog.csdnimg.cn/f0f63b0ccc684b42b617c94a959a2ea6.png)


## LED
|LED引脚| Arduino引脚 |
|--|--|
| 正极 | 7 |
| 阴极 | GND |
# 二、代码

```c
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> //引用I2C库
 
//设置LCD1602设备地址，这里的地址是0x27，一般是0x20，或者0x27，具体看模块手册
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
    digitalWrite(ledpin, HIGH);         
    delay(1000);
    lcd.clear();
    lcd.print("   Lights Off    ");
    digitalWrite(ledpin, LOW);           
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
```
## 三、效果
![请添加图片描述](https://img-blog.csdnimg.cn/d1edf4791fa44b1888394420609db98b.gif)
