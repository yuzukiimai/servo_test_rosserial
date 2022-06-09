#include <ros.h>
#include <std_msgs/Empty.h>
#include <Servo.h>
ros::NodeHandle nh;
Servo servo5;

void messageCb( const std_msgs::Empty& toggle_msg) {
  //digitalWrite(11, HIGH);
  //delay(100);
  //digitalWrite(11, LOW);
  //delay(100);
  servo5.write(0);
  delay(1000);
  servo5.write(90);
  delay(1000);
  servo5.write(180);
  delay(1000);
  servo5.write(90);
  delay(1000);
}

ros::Subscriber<std_msgs::Empty> sub("servo", &messageCb );

void setup(){
  servo5.attach(4);
  //pinMode(11, OUTPUT);
  //digitalWrite(11, HIGH); 
  nh.initNode();
  nh.subscribe(sub);
}

void loop(){
  nh.spinOnce();
  delay(1);
}
