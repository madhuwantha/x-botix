//QTR Sensor ----------------------------------------------------------------------------------------------------
QTRSensors qtr;
const uint8_t SensorCount = 16;
uint16_t sensorValues[SensorCount];
bool dval[SensorCount];


//PID Coefficients and Variables -------------------------------------------------------------------------------------------------------

float Kp; // experiment to determine this, start by something small that just makes your bot follow the line at a slow speed
float Kd; // experiment to determine this, slowly increase the speeds and adjust this value. ( Note: Kp < Kd)
float Ki;

byte maxSpeed;
byte minSpeed;
byte baseSpeed;

int lastError = 0;
int integral = 0;

int rightMotorSpeed;
int leftMotorSpeed;

char manner = 'F';
#define junctionCount 550 //encoder counts needed to bring the robot at center of juction

//Mototrs -------------------------------------------
#define leftMotorForward 53//48  //motor directions
#define leftMotorBackward 52//46
#define rightMotorForward 51
#define rightMotorBackward 50//52
#define rightMotorPWM 4 //PWM controls
#define leftMotorPWM 5//9

//Encorders---------------------------------------------------
volatile unsigned long leftCount = 0, rightCount = 0;


//LCD Menu ------------------------------------------------------------------------------------------------------
LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display


//Key Pad ------------------------------------------------------------------------------------------------------
const byte ROWS = 1; //four rows
const byte COLS = 6; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'A', 'B', 'C', 'D', 'E', 'F'}      //change - 10     change buttons names
};
byte rowPins[ROWS] = {40}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {34, 35, 36, 37, 38, 39}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

char customKey;



// right servo 11
// left servo 12
