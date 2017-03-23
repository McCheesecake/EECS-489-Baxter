#include "ros/ros.h"
#include "baxter_core_msgs/JointCommand.h"
#include <sensor_msgs/JointState.h>

double tourque_exp[7]; //expected torques
double torque_real[7]; //torque values from sensors
double torque_err[7];  // error 
double theta[7]; //position set


void myCallback(const sensor_msgs::JointState& joint_torque){ 
	
	ROS_INFO("torques recieved");
}

double Torque1(double theta[]){
 //calculate the torque value for s1
 // check with tony for the corosponding torque

double t = 0.167*sin(theta[2]) - 26.1*cos(theta[2]) - 8.14*cos(theta[2])*cos(theta[4]) + 0.932*cos(theta[3])*sin(theta[2]) + 0.227*cos(theta[2])*sin(theta[4]) - 0.588*sin(theta[2])*sin(theta[3]) - 1.35*cos(theta[2])*cos(theta[4])*cos(theta[6]) + 0.227*cos(theta[3])*cos(theta[4])*sin(theta[2]) - 2.68*cos(theta[2])*cos(theta[5])*sin(theta[4]) - 0.0948*cos(theta[2])*cos(theta[4])*sin(theta[6]) + 8.14*cos(theta[3])*sin(theta[2])*sin(theta[4]) - 1.06*cos(theta[5])*sin(theta[2])*sin(theta[3]) - 1.06*cos(theta[2])*sin(theta[4])*sin(theta[5]) + 2.68*sin(theta[2])*sin(theta[3])*sin(theta[5]) - 2.68*cos(theta[3])*cos(theta[4])*cos(theta[5])*sin(theta[2]) - 0.0948*cos(theta[2])*cos(theta[5])*cos(theta[6])*sin(theta[4]) - 0.00509*cos(theta[2])*cos(theta[4])*cos(theta[6])*sin(theta[6]) - 1.06*cos(theta[3])*cos(theta[4])*sin(theta[2])*sin(theta[5]) + 1.35*cos(theta[3])*cos(theta[6])*sin(theta[2])*sin(theta[4]) + 1.35*cos(theta[2])*cos(theta[5])*sin(theta[4])*sin(theta[6]) + 0.355*cos(theta[5])*cos(theta[6])*sin(theta[2])*sin(theta[3]) + 0.355*cos(theta[2])*cos(theta[6])*sin(theta[4])*sin(theta[5]) + 0.355*cos(theta[2])*cos(theta[4])*sin(theta[6])*sin(theta[6]) + 0.0948*cos(theta[3])*sin(theta[2])*sin(theta[4])*sin(theta[6]) + 0.0948*cos(theta[6])*sin(theta[2])*sin(theta[3])*sin(theta[5]) + 0.00509*cos(theta[5])*sin(theta[2])*sin(theta[3])*sin(theta[6]) + 0.00509*cos(theta[2])*sin(theta[4])*sin(theta[5])*sin(theta[6]) - 1.35*sin(theta[2])*sin(theta[3])*sin(theta[5])*sin(theta[6]) - 0.0948*cos(theta[3])*cos(theta[4])*cos(theta[5])*cos(theta[6])*sin(theta[2]) - 0.00509*cos(theta[2])*cos(theta[5])*cos(theta[6])*cos(theta[6])*sin(theta[4]) + 1.35*cos(theta[3])*cos(theta[4])*cos(theta[5])*sin(theta[2])*sin(theta[6]) + 0.355*cos(theta[3])*cos(theta[4])*cos(theta[6])*sin(theta[2])*sin(theta[5]) + 0.355*cos(theta[2])*cos(theta[5])*cos(theta[6])*sin(theta[4])*sin(theta[6]) + 0.00509*cos(theta[3])*cos(theta[4])*sin(theta[2])*sin(theta[5])*sin(theta[6]) + 0.00509*cos(theta[3])*cos(theta[6])*sin(theta[2])*sin(theta[4])*sin(theta[6]) + 0.00509*cos(theta[6])*cos(theta[6])*sin(theta[2])*sin(theta[3])*sin(theta[5]) - 0.355*cos(theta[3])*sin(theta[2])*sin(theta[4])*sin(theta[6])*sin(theta[6]) - 0.355*cos(theta[6])*sin(theta[2])*sin(theta[3])*sin(theta[5])*sin(theta[6]) - 0.00509*cos(theta[3])*cos(theta[4])*cos(theta[5])*cos(theta[6])*cos(theta[6])*sin(theta[2]) + 0.355*cos(theta[3])*cos(theta[4])*cos(theta[5])*cos(theta[6])*sin(theta[2])*sin(theta[6]);

return t;

}

double Torque2(double theta[]){

 //calculate the torque value for e0
 // check with tony for the corosponding torque
double t = 0.588*cos(theta[2])*cos(theta[3]) + 0.932*cos(theta[2])*sin(theta[3]) + 1.06*cos(theta[2])*cos(theta[3])*cos(theta[5]) + 0.227*cos(theta[2])*cos(theta[4])*sin(theta[3]) - 2.68*cos(theta[2])*cos(theta[3])*sin(theta[5]) + 8.14*cos(theta[2])*sin(theta[3])*sin(theta[4]) - 0.355*cos(theta[2])*cos(theta[3])*cos(theta[5])*cos(theta[6]) - 2.68*cos(theta[2])*cos(theta[4])*cos(theta[5])*sin(theta[3]) - 0.0948*cos(theta[2])*cos(theta[3])*cos(theta[6])*sin(theta[5]) - 0.00509*cos(theta[2])*cos(theta[3])*cos(theta[5])*sin(theta[6]) - 1.06*cos(theta[2])*cos(theta[4])*sin(theta[3])*sin(theta[5]) + 1.35*cos(theta[2])*cos(theta[6])*sin(theta[3])*sin(theta[4]) + 1.35*cos(theta[2])*cos(theta[3])*sin(theta[5])*sin(theta[6]) + 0.0948*cos(theta[2])*sin(theta[3])*sin(theta[4])*sin(theta[6]) - 0.0948*cos(theta[2])*cos(theta[4])*cos(theta[5])*cos(theta[6])*sin(theta[3]) - 0.00509*cos(theta[2])*cos(theta[3])*cos(theta[6])*cos(theta[6])*sin(theta[5]) + 1.35*cos(theta[2])*cos(theta[4])*cos(theta[5])*sin(theta[3])*sin(theta[6]) + 0.355*cos(theta[2])*cos(theta[4])*cos(theta[6])*sin(theta[3])*sin(theta[5]) + 0.355*cos(theta[2])*cos(theta[3])*cos(theta[6])*sin(theta[5])*sin(theta[6]) + 0.00509*cos(theta[2])*cos(theta[4])*sin(theta[3])*sin(theta[5])*sin(theta[6]) + 0.00509*cos(theta[2])*cos(theta[6])*sin(theta[3])*sin(theta[4])*sin(theta[6]) - 0.355*cos(theta[2])*sin(theta[3])*sin(theta[4])*sin(theta[6])*sin(theta[6]) - 0.00509*cos(theta[2])*cos(theta[4])*cos(theta[5])*cos(theta[6])*cos(theta[6])*sin(theta[3]) + 0.355*cos(theta[2])*cos(theta[4])*cos(theta[5])*cos(theta[6])*sin(theta[3])*sin(theta[6]);
return t;
}

double Torque3(double theta[]){
 //calculate the torque value for e1
 // check with tony for the corosponding torque
double t = 0.227*cos(theta[4])*sin(theta[2]) + 8.14*sin(theta[2])*sin(theta[4]) - 8.14*cos(theta[2])*cos(theta[3])*cos(theta[4]) + 0.227*cos(theta[2])*cos(theta[3])*sin(theta[4]) - 2.68*cos(theta[4])*cos(theta[5])*sin(theta[2]) - 1.06*cos(theta[4])*sin(theta[2])*sin(theta[5]) + 1.35*cos(theta[6])*sin(theta[2])*sin(theta[4]) + 0.0948*sin(theta[2])*sin(theta[4])*sin(theta[6]) - 1.35*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[6]) - 2.68*cos(theta[2])*cos(theta[3])*cos(theta[5])*sin(theta[4]) - 0.0948*cos(theta[2])*cos(theta[3])*cos(theta[4])*sin(theta[6]) - 0.0948*cos(theta[4])*cos(theta[5])*cos(theta[6])*sin(theta[2]) - 1.06*cos(theta[2])*cos(theta[3])*sin(theta[4])*sin(theta[5]) + 1.35*cos(theta[4])*cos(theta[5])*sin(theta[2])*sin(theta[6]) + 0.355*cos(theta[4])*cos(theta[6])*sin(theta[2])*sin(theta[5]) + 0.00509*cos(theta[4])*sin(theta[2])*sin(theta[5])*sin(theta[6]) + 0.00509*cos(theta[6])*sin(theta[2])*sin(theta[4])*sin(theta[6]) - 0.355*sin(theta[2])*sin(theta[4])*sin(theta[6])*sin(theta[6]) - 0.0948*cos(theta[2])*cos(theta[3])*cos(theta[5])*cos(theta[6])*sin(theta[4]) - 0.00509*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[6])*sin(theta[6]) - 0.00509*cos(theta[4])*cos(theta[5])*cos(theta[6])*cos(theta[6])*sin(theta[2]) + 1.35*cos(theta[2])*cos(theta[3])*cos(theta[5])*sin(theta[4])*sin(theta[6]) + 0.355*cos(theta[2])*cos(theta[3])*cos(theta[6])*sin(theta[4])*sin(theta[5]) + 0.355*cos(theta[2])*cos(theta[3])*cos(theta[4])*sin(theta[6])*sin(theta[6]) + 0.355*cos(theta[4])*cos(theta[5])*cos(theta[6])*sin(theta[2])*sin(theta[6]) + 0.00509*cos(theta[2])*cos(theta[3])*sin(theta[4])*sin(theta[5])*sin(theta[6]) - 0.00509*cos(theta[2])*cos(theta[3])*cos(theta[5])*cos(theta[6])*cos(theta[6])*sin(theta[4]) + 0.355*cos(theta[2])*cos(theta[3])*cos(theta[5])*cos(theta[6])*sin(theta[4])*sin(theta[6]);
return t;
}

double Torque4(double theta[]){
 //calculate the torque value for w0
 // check with tony for the corosponding torque
double t = 2.68*sin(theta[2])*sin(theta[4])*sin(theta[5]) - 1.06*cos(theta[2])*sin(theta[3])*sin(theta[5]) - 1.06*cos(theta[5])*sin(theta[2])*sin(theta[4]) - 2.68*cos(theta[2])*cos(theta[5])*sin(theta[3]) + 1.06*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[5]) - 2.68*cos(theta[2])*cos(theta[3])*cos(theta[4])*sin(theta[5]) - 0.0948*cos(theta[2])*cos(theta[5])*cos(theta[6])*sin(theta[3]) + 1.35*cos(theta[2])*cos(theta[5])*sin(theta[3])*sin(theta[6]) + 0.355*cos(theta[2])*cos(theta[6])*sin(theta[3])*sin(theta[5]) + 0.355*cos(theta[5])*cos(theta[6])*sin(theta[2])*sin(theta[4]) + 0.00509*cos(theta[2])*sin(theta[3])*sin(theta[5])*sin(theta[6]) + 0.0948*cos(theta[6])*sin(theta[2])*sin(theta[4])*sin(theta[5]) + 0.00509*cos(theta[5])*sin(theta[2])*sin(theta[4])*sin(theta[6]) - 1.35*sin(theta[2])*sin(theta[4])*sin(theta[5])*sin(theta[6]) - 0.0948*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[6])*sin(theta[5]) - 0.00509*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[5])*sin(theta[6]) - 0.00509*cos(theta[2])*cos(theta[5])*cos(theta[6])*cos(theta[6])*sin(theta[3]) + 1.35*cos(theta[2])*cos(theta[3])*cos(theta[4])*sin(theta[5])*sin(theta[6]) + 0.355*cos(theta[2])*cos(theta[5])*cos(theta[6])*sin(theta[3])*sin(theta[6]) + 0.00509*cos(theta[6])*cos(theta[6])*sin(theta[2])*sin(theta[4])*sin(theta[5]) - 0.355*cos(theta[6])*sin(theta[2])*sin(theta[4])*sin(theta[5])*sin(theta[6]) - 0.355*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[5])*cos(theta[6]) - 0.00509*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[6])*cos(theta[6])*sin(theta[5]) + 0.355*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[6])*sin(theta[5])*sin(theta[6]);
return t;
}

double Torque5(double theta[]){
 //calculate the torque value for w1
 // check with tony for the corosponding torque
double t = 1.35*cos(theta[4])*sin(theta[2])*sin(theta[6]) - 0.0948*cos(theta[4])*cos(theta[6])*sin(theta[2]) - 0.0948*cos(theta[2])*cos(theta[3])*cos(theta[6])*sin(theta[4]) - 0.00509*cos(theta[4])*cos(theta[6])*cos(theta[6])*sin(theta[2]) + 1.35*cos(theta[2])*cos(theta[3])*sin(theta[4])*sin(theta[6]) + 1.35*cos(theta[2])*cos(theta[6])*sin(theta[3])*sin(theta[5]) + 1.35*cos(theta[5])*cos(theta[6])*sin(theta[2])*sin(theta[4]) + 0.355*cos(theta[4])*cos(theta[6])*sin(theta[2])*sin(theta[6]) + 0.0948*cos(theta[2])*sin(theta[3])*sin(theta[5])*sin(theta[6]) + 0.0948*cos(theta[5])*sin(theta[2])*sin(theta[4])*sin(theta[6]) - 0.0948*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[5])*sin(theta[6]) - 0.00509*cos(theta[2])*cos(theta[3])*cos(theta[6])*cos(theta[6])*sin(theta[4]) + 0.355*cos(theta[2])*cos(theta[3])*cos(theta[6])*sin(theta[4])*sin(theta[6]) + 0.00509*cos(theta[2])*cos(theta[6])*sin(theta[3])*sin(theta[5])*sin(theta[6]) + 0.00509*cos(theta[5])*cos(theta[6])*sin(theta[2])*sin(theta[4])*sin(theta[6]) - 0.355*cos(theta[2])*sin(theta[3])*sin(theta[5])*sin(theta[6])*sin(theta[6]) - 0.355*cos(theta[5])*sin(theta[2])*sin(theta[4])*sin(theta[6])*sin(theta[6]) - 1.35*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[5])*cos(theta[6]) - 0.00509*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[5])*cos(theta[6])*sin(theta[6]) + 0.355*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[5])*sin(theta[6])*sin(theta[6]);
return t;
}


double Torque6(double theta[]){
 //calculate the torque value for w2
 // check with tony for the corosponding torque
double t = 0.355*cos(theta[2])*cos(theta[5])*sin(theta[3])*sin(theta[6]) - 0.00509*cos(theta[2])*cos(theta[5])*cos(theta[6])*sin(theta[3]) + 0.355*cos(theta[4])*cos(theta[6])*sin(theta[2])*sin(theta[6]) + 0.00509*cos(theta[6])*sin(theta[2])*sin(theta[4])*sin(theta[5]) + 0.00509*cos(theta[4])*sin(theta[2])*sin(theta[6])*sin(theta[6]) - 0.355*sin(theta[2])*sin(theta[4])*sin(theta[5])*sin(theta[6]) - 0.00509*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[6])*sin(theta[5]) + 0.355*cos(theta[2])*cos(theta[3])*cos(theta[4])*sin(theta[5])*sin(theta[6]) + 0.355*cos(theta[2])*cos(theta[3])*cos(theta[6])*sin(theta[4])*sin(theta[6]) + 0.355*cos(theta[2])*cos(theta[6])*cos(theta[6])*sin(theta[3])*sin(theta[5]) + 0.355*cos(theta[5])*cos(theta[6])*cos(theta[6])*sin(theta[2])*sin(theta[4]) + 0.00509*cos(theta[2])*cos(theta[3])*sin(theta[4])*sin(theta[6])*sin(theta[6]) + 0.00509*cos(theta[2])*cos(theta[6])*sin(theta[3])*sin(theta[5])*sin(theta[6]) + 0.00509*cos(theta[5])*cos(theta[6])*sin(theta[2])*sin(theta[4])*sin(theta[6]) - 0.355*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[5])*cos(theta[6])*cos(theta[6]) - 0.00509*cos(theta[2])*cos(theta[3])*cos(theta[4])*cos(theta[5])*cos(theta[6])*sin(theta[6]);
return t;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "torque_tracker");
  ros::NodeHandle n;
  ros::Publisher left_cmd_pub = n.advertise<baxter_core_msgs::JointCommand>("/robot/limb/left/joint_command", 1);
  ros::Subscriber torque_subscriber = n.subscribe<sensor_msgs/JointState>("/robot/joint_states", 1,myCallback);

   publish at at least 5 Hz, or else Baxter switches back to Position mode and holds position
  ros::Rate loop_rate(100);
  baxter_core_msgs::JointCommand cmd;
  sensor_msgs::JointState states;
  
  states.mode= sensor_msgs::JointState::effort;
  
  states.names.push_back("left_s0");
  states.names.push_back("left_s1");
  states.names.push_back("left_e0");
  states.names.push_back("left_e1");
  states.names.push_back("left_w0");
  states.names.push_back("left_w1");
  states.names.push_back("left_w2");
  
  states.effort.resize(states.names.size());
  
  // command in position mode
  cmd.mode = baxter_core_msgs::JointCommand::POSITION_MODE;
  
  // command joints in the order shown in baxter_interface
  cmd.names.push_back("left_s0");
  cmd.names.push_back("left_s1");
  cmd.names.push_back("left_e0");
  cmd.names.push_back("left_e1");
  cmd.names.push_back("left_w0");
  cmd.names.push_back("left_w1");
  cmd.names.push_back("left_w2");
  
  // set your calculated positions
  cmd.command.resize(cmd.names.size());
  
  
  //initial torque readings
  for(size_t i = 0; i < states.names.size(); i++){
    states.effort[i] = 0.0; // get torque reading
    ROS_INFO("Torque for joint %d = %d", i, states.effort[i]);
	}
  
  //fisrt pose------------------------------------------------------------------------------
  
  theta[]=[0,0,0,0,0,0,0]; // theta[] = [s0,s1,eo,e1,w0,w1,w2]
  
  //position command
  for(size_t i = 0; i < cmd.names.size(); i++){
    cmd.command[i] = theta[i];
  }

  //calculate expected torque
  torque_exp[] = [0,Torque1(theta[]),Torque1(theta[]),Torque2(theta[]),Torque3(theta[]),Torque4(theta[]),Torque5(theta[]),Torque6(theta[])];

  sleep(5);//wiat for movment completion

  // get torque readings from baxter
  for(size_t i = 0; i < states.names.size(); i++){
    torque_real = states.effort[i]; //actual value
    ROS_INFO("for joint %d: actual Torque  = %d, expected torque = %d", i, states.effort[i], torque_exp[i]);
	}

  // calculate torque error
  torque_err= torque_real[] - torque_exp[]; 
  ROS_INFO("Torque Error = &d", torque_err[]);
  
  //second pose---------------------------------------------------------------------------
  
  theta[]=[0.25,0.25,0.25,0.25,0.25,0.25,0.25]; // theta[] = [s0,s1,eo,e1,w0,w1,w2]
  
  //position command
  for(size_t i = 0; i < cmd.names.size(); i++){
    cmd.command[i] = theta[i];
  }

  //calculate expected torque
  torque_exp[] = [0,Torque1(theta[]),Torque1(theta[]),Torque2(theta[]),Torque3(theta[]),Torque4(theta[]),Torque5(theta[]),Torque6(theta[])];

  sleep(5);//wiat for movment completion

  // get torque readings from baxter
  for(size_t i = 0; i < states.names.size(); i++){
    torque_real = states.effort[i]; //actual value
    ROS_INFO("for joint %d: actual Torque  = %d, expected torque = %d", i, states.effort[i], torque_exp[i]);
	}

  // calculate torque error
  torque_err= torque_real[] - torque_exp[]; 
  ROS_INFO("Torque Error = &d", torque_err[]);
  
  //third pose---------------------------------------------------------------------------
  
  theta[]=[0.5,0.5,0.5,0.5,0.5,0.5,0.5]; // theta[] = [s0,s1,eo,e1,w0,w1,w2]
  
  //position command
  for(size_t i = 0; i < cmd.names.size(); i++){
    cmd.command[i] = theta[i];
  }

  //calculate expected torque
  torque_exp[] = [0,Torque1(theta[]),Torque1(theta[]),Torque2(theta[]),Torque3(theta[]),Torque4(theta[]),Torque5(theta[]),Torque6(theta[])];

  sleep(5);//wiat for movment completion

  // get torque readings from baxter
  for(size_t i = 0; i < states.names.size(); i++){
    torque_real = states.effort[i]; //actual value
    ROS_INFO("for joint %d: actual Torque  = %d, expected torque = %d", i, states.effort[i], torque_exp[i]);
	}

  // calculate torque error
  torque_err= torque_real[] - torque_exp[]; 
  ROS_INFO("Torque Error = &d", torque_err[]);



  //fourth pose---------------------------------------------------------------------------
  
  theta[]=[0.75,0.75,0.75,0.75,0.75,0.75,0.75]; // theta[] = [s0,s1,eo,e1,w0,w1,w2]
  
  //position command
  for(size_t i = 0; i < cmd.names.size(); i++){
    cmd.command[i] = theta[i];
  }

  //calculate expected torque
  torque_exp[] = [0,Torque1(theta[]),Torque1(theta[]),Torque2(theta[]),Torque3(theta[]),Torque4(theta[]),Torque5(theta[]),Torque6(theta[])];

  sleep(5);//wiat for movment completion

  // get torque readings from baxter
  for(size_t i = 0; i < states.names.size(); i++){
    torque_real = states.effort[i]; //actual value
    ROS_INFO("for joint %d: actual Torque  = %d, expected torque = %d", i, states.effort[i], torque_exp[i]);
	}

  // calculate torque error
  torque_err= torque_real[] - torque_exp[]; 
  ROS_INFO("Torque Error = &d", torque_err[]);

  //----------------------------------------------------------------------------------------
  std::cout<<cmd<<std::endl;
  while(ros::ok()){
    //update cmd.command commands here
    left_cmd_pub.publish(cmd);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
