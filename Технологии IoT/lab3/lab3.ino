#include <Wire.h>
#include <time.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>
#include <Adafruit_GFX.h>

#define hmc5883l_address 0x1E
#define DS1307_ADDRESS 0x69


const int MPU_addr = 0x68; // I2C address of the MPU-6050
int16_t AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ, Test;
void setup() {
 Serial.begin(115200); /* begin serial for debug */
 Wire.begin(4, 5); /* join i2c bus with SDA=D7 and SCL=D6 of NodeMCU */
 setDS1307time(30,20,11,2,27,3,23);
}


void loop() {
 Wire.beginTransmission(MPU_addr);
 Wire.write(0x6B); // PWR_MGMT_1 register
 Wire.write(0); // set to zero (wakes up the MPU-6050)
 Wire.endTransmission(true);

 Serial.println(hmc5883l_GetHeading());
 delay(500);
 Wire.beginTransmission(MPU_addr);
 Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
 Wire.endTransmission(false);
 Wire.requestFrom(MPU_addr, 14, true); // request a total of 14 registers
 AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
 AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
 AcZ = Wire.read() << 8 | Wire.read(); // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
 Tmp = Wire.read() << 8 | Wire.read(); // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
 GyX = Wire.read() << 8 | Wire.read(); // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
 GyY = Wire.read() << 8 | Wire.read(); // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
 GyZ = Wire.read() << 8 | Wire.read(); // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

 Serial.print("AcX = "); Serial.print(AcX);
 Serial.print(" | AcY = "); Serial.print(AcY);
 Serial.print(" | AcZ = "); Serial.print(AcZ);
 Serial.print(" | Tmp = "); Serial.print(Tmp / 340.00 + 36.53); //equation for temperature in degrees C from datasheet
 Serial.print(" | GyX = "); Serial.print(GyX);
 Serial.print(" | GyY = "); Serial.print(GyY);
 Serial.print(" | GyZ = "); Serial.println(GyZ);
 displayTime();

 delay(500);
 hmc5883l_init();
}


void setDS1307time(byte second, byte minute, byte hour, byte dayOfWeek, byte
dayOfMonth, byte month, byte year)
{
 // sets time and date data to DS1307
 Wire.beginTransmission(DS1307_ADDRESS);
 Wire.write(0); // set next input to start at the seconds register
 Wire.write(decToBcd(second)); // set seconds
 Wire.write(decToBcd(minute)); // set minutes
 Wire.write(decToBcd(hour)); // set hours
 Wire.write(decToBcd(dayOfWeek)); // set day of week (1=Sunday, 7=Saturday)
 Wire.write(decToBcd(dayOfMonth)); // set date (1 to 31)
 Wire.write(decToBcd(month)); // set month
 Wire.write(decToBcd(year)); // set year (0 to 99)
 Wire.endTransmission();
}


void displayTime()
{
 byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
 // retrieve data from DS1307
 readDS1307time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month,
 &year);
 // send it to the serial monitor
 Serial.print(hour, DEC);
 // convert the byte variable to a decimal number when displayed
 Serial.print(":");
 if (minute<10)
 {
 Serial.print("0");
 }
 Serial.print(minute, DEC);
 Serial.print(":");
 if (second<10)
 {
 Serial.print("0");
 }
 Serial.print(second, DEC);
 Serial.print(" ");
 Serial.print(dayOfMonth, DEC);
 Serial.print("/");
 Serial.print(month, DEC);
 Serial.print("/");
 Serial.print(year, DEC);
 Serial.print(" День недели: ");
 switch(dayOfWeek){
 case 1:
 Serial.println("Воскресенье");
 break;
 case 2:
 Serial.println("Понедельник");
 break;
 case 3:
 Serial.println("Вторник");
 break;
 case 4:
 Serial.println("Среда");
 break;
 case 5:
 Serial.println("Четверг");
 break;
 case 6:
 Serial.println("Пятница");
 break;
 case 7:
 Serial.println("Суббота");
 break;
 }
 Serial.println();
}


void readDS1307time(byte *second, byte *minute, byte *hour, byte *dayOfWeek, byte *dayOfMonth, byte *month, byte *year) {
 Wire.beginTransmission(DS1307_ADDRESS);
 Wire.write(0);
// set DS1307 register pointer to 00h
 Wire.endTransmission();
 Wire.requestFrom(DS1307_ADDRESS, 7);

// request seven bytes of data from DS1307 starting from register 00h
 *second = bcdToDec(Wire.read() );//& 0x7f);
 *minute = bcdToDec(Wire.read());
 *hour = bcdToDec(Wire.read() );//& 0x3f);
 *dayOfWeek = bcdToDec(Wire.read());
 *dayOfMonth = bcdToDec(Wire.read());
 *month = bcdToDec(Wire.read());
 *year = bcdToDec(Wire.read());
}


void hmc5883l_init(){ /* Magneto initialize function */
 Wire.beginTransmission(hmc5883l_address);
 Wire.write(0x00);
 Wire.write(0xF0); //8 samples per measurement, 15Hz data output rate, Normal measurement
 Wire.write(0xA0); //
 Wire.write(0x00); //Continuous measurement mode
 Wire.endTransmission();
 delay(500);
}


int hmc5883l_GetHeading(){
 int16_t x, y, z;
 double Heading;
 Wire.beginTransmission(hmc5883l_address);
 Wire.write(0x03);
 Wire.endTransmission();
 /* Read 16 bit x,y,z value (2's complement form) */
 Wire.requestFrom(hmc5883l_address, 6);
 x = (((int16_t)Wire.read()<<8) | (int16_t)Wire.read());
 z = (((int16_t)Wire.read()<<8) | (int16_t)Wire.read());
 y = (((int16_t)Wire.read()<<8) | (int16_t)Wire.read());
 Serial.print("X="); Serial.println(x);
 Serial.print("Y="); Serial.println(y);
 Serial.print("Z="); Serial.println(z);

 Serial.print("Heading Angle : ");
 Heading = atan2((double)y, (double)x);// + Declination;
 if (Heading>2*PI) /* Due to declination check for >360 degree */
 Heading = Heading - 2*PI;
 if (Heading<0) /* Check for sign */
 Heading = Heading + 2*PI;
 return (Heading* 180 / PI);/* Convert into angle and return */
}
byte decToBcd(byte val) { return( (val/10*16) + (val%10) ); }
// Convert normal decimal numbers to binary coded decimal
byte bcdToDec(byte val) { return( (val/16*10) + (val%16) ); }
// Convert binary coded decimal to normal decimal numbers