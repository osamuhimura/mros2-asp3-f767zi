#include "app.h"
#include "mros2.h"
#include "std_msgs/msg/string.hpp"
#include <string>

#include "stm32f7xx_nucleo_144.h"

std::string double_to_string(double value)
{
  int intpart, fracpart;
  char str[12];
  intpart = (int)value;
  fracpart = (int)((value - intpart) * 1000000);
  sprintf(str, "%d.%06d", intpart, fracpart);
  return str;
}

mros2::Subscriber sub;
mros2::Publisher pub;

void userCallback(std_msgs::msg::String *msg)
{
  std::string sub_str1 = msg->data.substr(0,8);
  std::string sub_str2 = msg->data.substr(8,8);
  std::string sub_str3 = msg->data.substr(16,8);
  std::string sub_str4 = msg->data.substr(24,8);
  std::string sub_str5 = msg->data.substr(32,8);
  std::string sub_str6 = msg->data.substr(40,8);

  double linear_x = std::stod(sub_str1);
  double linear_y = std::stod(sub_str2);
  double linear_z = std::stod(sub_str3);
  double angular_x = std::stod(sub_str4);
  double angular_y = std::stod(sub_str5);
  double angular_z = std::stod(sub_str6);
  
  auto reconverted_message = std_msgs::msg::String();

  std::string pub_str1 = double_to_string(linear_x);
  std::string pub_str2 = double_to_string(linear_y);
  std::string pub_str3 = double_to_string(linear_z);
  std::string pub_str4 = double_to_string(angular_x);
  std::string pub_str5 = double_to_string(angular_y);
  std::string pub_str6 = double_to_string(angular_z);

  std::string pub_str = pub_str1 + pub_str2 + pub_str3 + pub_str4 + pub_str5 + pub_str6;
  reconverted_message.data = pub_str;

  pub.publish(reconverted_message);
}

int main(int argc, char * argv[])
{
  MROS2_INFO("mROS 2 application is started");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("mros2_node");
  pub = node.create_publisher<std_msgs::msg::String>("to_linux", 10);
  sub = node.create_subscription<std_msgs::msg::String>("to_stm", 10, userCallback);
  std_msgs::msg::String msg;

  MROS2_INFO("ready to pub/sub message");
  mros2::spin();
  BSP_LED_Toggle(LED3);
}

void main_task(void)
{
  main(0, NULL);
}

void
led_cyclic_handler(intptr_t exinf)
{
  BSP_LED_Toggle(LED2);
}