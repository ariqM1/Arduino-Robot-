/* 
Coded by Ariq Mukul
ORIGINAL TEMPLATE CODE WAS PROVIDED BY ARDUINO BUT MODIFIED BY ME
first robot project, and Arduino provides examples of sample code
I based this code off the sample code, but all modifications and manipulation of robot are coded by ME
 */

#
include < AFMotor.h >
AF_DCMotor motor1(1, MOTOR12_8KHZ);
AF_DCMotor motor2(2, MOTOR12_8KHZ);
AF_DCMotor motor3(3, MOTOR12_1KHZ);
AF_DCMotor motor4(4, MOTOR12_1KHZ);
const int pingPin = 19;
void setup() {
    Serial.begin(9600); // Serial library set up 
    motor1.setSpeed(200); // motors speed setup
motor2.setSpeed(200);
motor3.setSpeed(200);
motor4.setSpeed(200);
}
ﬂoat ping() { // code that runs ping sensor 
    long duration, inches;
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);
    pinMode(pingPin, INPUT);
    duration = pulseIn(pingPin, HIGH);
    long microsecondsToInches(long microseconds);
    inches = microsecondsToInches(duration);
    return inches;
}
void forward() { // moves wheels forward 
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}
void backward() // moves wheel backward
{
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}
void haltMotors() // motor stop function, stop motors before changing direction 
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}
void turnRight() // robot turns right
{
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(BACKWARD);
}
void loop() { 
    long duration, inches; // declaration of variables 
    inches = ping(); // initializing inches variable
    Serial.print(inches);
    Serial.print("in, ");
    Serial.println();

    while (inches > 8) { // run while robot is more than 8 inches away from object 
        inches = ping();
        forward(); // moves robot forward 
    }
    haltMotors(); // stops motor for 2 seconds, then changes direction
    delay(1000);
    while (inches < 10) { // runs while robot is 10+ inches away from object
        inches = ping();
        backward(); // Move the robot backward. 
    }
    turnRight(); // when robot is finished moving backward, turns robot to right
    delay(1500); 
    haltMotors();
    delay(1000);
}
long microsecondsToInches(long microseconds) {
    return microseconds / 74 / 2;
}