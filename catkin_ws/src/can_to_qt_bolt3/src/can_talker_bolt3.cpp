#include "ros/ros.h"

#include "std_msgs/String.h"
#include "std_msgs/Int16.h"

#include "canrecieve.cpp"
#include "shared_messages.h"
//ROS topic message declerations 
#include "can_msg.h"
#include "fault_msg.h"

#include <iostream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "can_talker_bolt3");

  ros::NodeHandle n;

  ros::Publisher topic_can_msg = n.advertise<can_to_qt_bolt3::can_msg>("can_msg", 1000);
  ros::Publisher topic_fault_msg = n.advertise<can_to_qt_bolt3::can_msg>("fault_msg", 1000);
	  
  
  ros::Rate loop_rate(10);
  
  struct canfd_frame message;
  char* argv2[2];
  
  argv2[0] = " ";
  argv2[1] = "can0";
  int count = 0;
  
  while (ros::ok())
    {
      std::cout << "while loop" << std::endl;
      std::string name;
      std::string data_s;
      signed short data = 0;
      std::string fault;
      
      can_to_qt_bolt3::can_msg can_msg;
      can_to_qt_bolt3::fault_msg fault_msg;
      
      //std::cout << "calling canrecieve" << std::endl;
      message = canrecieve(2, argv2, std::cin);

      switch(message.can_id)
	{
	case 0xA0:
	  {
	    can_msg.can_id = message.can_id;
	    data = (message.data[1] << 8 | message.data[0]);
	    can_msg.name = "TEMP_MOD_A";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    data = (message.data[3] << 8 | message.data[2]);
	    can_msg.name = "TEMP_MOD_B";
	    can_msg.data = data;
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    topic_can_msg.publish(can_msg);
	    data = (message.data[5] << 8 | message.data[4]);
	    can_msg.name = "TEMP_MOD_C";
	    can_msg.data = data;
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    topic_can_msg.publish(can_msg);
	    data = (message.data[7] << 8 | message.data[6]);
	    can_msg.name = "TEMP_GATE_DRIVER_BOARD";
	    can_msg.data = data;
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    topic_can_msg.publish(can_msg);
	    break;
	  }
	case 0xA1:
	  {
     	    can_msg.can_id = message.can_id;
	    data = (message.data[1] << 8 | message.data[0]);
	    can_msg.name = "TEMP_CONTROL_BOARD";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    break;
	  }
	case 0xA2:
	  {
	    can_msg.can_id = message.can_id;
	    data = (message.data[5] << 8 | message.data[4]);
	    can_msg.name = "MOTOR_TEMP";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);

	    break;
	  }
	case 0xA4:
	  {
	    can_msg.can_id = message.can_id;
	    data = message.data[3];
	    can_msg.name = "REGEN_DISABLE";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	  break;
	  }
	case 0xA5:
	  {
	    can_msg.can_id = message.can_id;
	    data = (message.data[1] << 8 | message.data[0]);
	    can_msg.name = "MOTOR_ANGLE";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    data = (message.data[3] << 8 | message.data[2]);
	    can_msg.name = "MOTOR_SPEED";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    data = (message.data[7] << 8 | message.data[6]);
	    can_msg.name = "RESOLVER_ANGLE";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    break;
	  }
	case 0xA6:
	  {
	    can_msg.can_id = message.can_id;
	    data = (message.data[7] << 8 | message.data[6]);
	    can_msg.name = "DC_BUS_CURRENT";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    break;
	  }
	case 0xA7:
	  {
	    can_msg.can_id = message.can_id;
	    data = (message.data[1] << 8 | message.data[0]);
	    can_msg.name = "DC_BUS_VOLTAGE";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    data = (message.data[3] << 8 | message.data[2]);
	    can_msg.name = "OUTPUT_VOLTAE";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    data = (message.data[5] << 8 | message.data[4]);
	    can_msg.name = "PHASE_AB_VOLTAGE";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    data = (message.data[7] << 8 | message.data[6]);
	    can_msg.name = "PHASE_BC_VOLTAGE";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	   	   	   
	    break;
	  }
	case 0xA8:
	  {
	    can_msg.can_id = message.can_id;
	    data = (message.data[5] << 8 | message.data[4]);
	    can_msg.name = "ID_FEEDBACK";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    data = (message.data[7] << 8 | message.data[6]);
	    can_msg.name = "IQ_FEEDBACK";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    break;
	  }
	case 0xAA:
	  {
	    can_msg.can_id = message.can_id;
	    data = (message.data[1] << 8 | message.data[0]);
	    can_msg.name = "VSM_STATE";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    data = (message.data[2]);
	    can_msg.name = "INVERTER_STATE";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    break;
	  }
	case 0xAB:
	  {
	    //fault_msg.can_id = message.can_id;
	    //data = (message.data[7] << 8 | message.data[6]);
	    //fault_msg.name = "FAULT";
	    //fault_msg.data = data;
	    //topic_can_msg.publish(can_msg);
	    //ROS_INFO("FAULT name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    break;
	  }
	case 0xAC:
	  {
	    can_msg.can_id = message.can_id;
	    data = (message.data[1] << 8 | message.data[0]);
	    can_msg.name = "COMMAND_TORQUE";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    data = (message.data[3] << 8 | message.data[2]);
	    can_msg.name = "TORQUE_FEEDBACK";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);

	    break;
	  }
	case 0xC0:
	  {
	    can_msg.can_id = message.can_id;
	    data = (message.data[3] << 8 | message.data[2]);
	    can_msg.name = "SPEED_COMMAND";
	    can_msg.data = data;
	    topic_can_msg.publish(can_msg);
	    ROS_INFO("name: %s, can_id [%i], data: %i", can_msg.name, can_msg.can_id, can_msg.data);
	    break;
	  }
	}  
      
      if(count > 700)
	exit(0);
      else
	count++;
      
      ros::spinOnce();

      loop_rate.sleep();
    }


  return 0;
    }
