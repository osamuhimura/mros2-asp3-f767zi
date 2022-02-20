#include "app.h"
#include "mros2.h"
#include "std_msgs/msg/u_int16.hpp"

#include "stm32f7xx_nucleo_144.h"

mros2::Subscriber sub;

void userCallback(std_msgs::msg::UInt16 *msg)
{
  MROS2_INFO("subscribed msg: '%d'", msg->data);
}

int main(int argc, char * argv[])
{
  MROS2_INFO("mROS 2 application is started");

  mros2::init(argc, argv);
  MROS2_DEBUG("mROS 2 initialization is completed");
  BSP_LED_Toggle(LED1);

  mros2::Node node = mros2::Node::create_node("mros2_node");
  sub = node.create_subscription<std_msgs::msg::UInt16>("to_stm", 10, userCallback);

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