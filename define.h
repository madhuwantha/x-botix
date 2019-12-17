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

char manner;
char temp;
int junctionCount = 210; //encoder counts needed to bring the robot at center of juction
#define skipJunction  120
int T = 210;
int L = 210;
//Mototrs -------------------------------------------
#define leftMotorForward 53//48  //motor directions
#define leftMotorBackward 52//46
#define rightMotorForward 51
#define rightMotorBackward 50//52
#define rightMotorPWM 4 //PWM controls
#define leftMotorPWM 5//9
int brakeTime = 50;
int a = 0;

//Encorders---------------------------------------------------
volatile unsigned long leftCount = 0, rightCount = 0;


// ******************************Color Detection*********************************************//
#define redpin 3
#define greenpin 5
#define bluepin 6

#define SDApinN 24
#define SCLpinN 26
#define SDApinO 28
#define SCLpinO 30

#define commonAnode true
bool colorArray = 0;

byte gammatable[256];

Adafruit_TCS34725softi2c tcsN = Adafruit_TCS34725softi2c(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X, SDApinN, SCLpinN);
Adafruit_TCS34725softi2c tcsO = Adafruit_TCS34725softi2c(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X, SDApinO, SCLpinO);

int colorCount = 0;
char colorAreaA;
char colorAreaC[4] ;
//color sorvo
Servo leftServo;
Servo rightServo;
Servo baseServo;
Servo leftCatchServo;
Servo rightCatchServo;

// right servo 11
// left servo 12



// ******************************Arm*********************************************//
//B - 7
//L - 8
//R - 9


// ******************************Key pad*********************************************//
const byte ROWS = 1; //four rows
const byte COLS = 6; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'A','B','C','D','E','F'}
};
byte rowPins[ROWS] = {31}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {33,35,37,39,41,43}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
char customKey;


//metal detector
#define metalPin 32


// ******************************Mesh*********************************************//
char junction;

int status = 0;
int mode = 0;
bool er=0;

# define STOPPED 0
# define FOLLOWING_LINE 1
# define NO_LINE 2
# define CONT_LINE 3
# define POS_LINE 4
# define RIGHT_TURN 5
# define LEFT_TURN 6
#define END_MAZE 7

char junctionMaze;

char path[100] = " ";
unsigned char pathLength = 0; // The path length
int pathIndex = 0; // used to reach an specific array element.


// ******************************Line mode*********************************************//
bool lineMode = 1;  // initially for black line 



///*LCD Configurations*/
//LiquidCrystal_I2C lcd(0x27, 16, 2);
