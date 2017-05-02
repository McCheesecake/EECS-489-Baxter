//RRT_Baxter.cpp
//Ammar Nahari axn337
//04/23/2017
//THis code performs rapidly exploring random tree algorithm (RRT) on a rethink baxter robot.


//basic include statements for interfacing with ROS and Baxter
#include <ros/ros.h>
#include "baxter_core_msgs/JointCommand.h"
#include <std_msgs/Float64.h>
//#include <baxter_core_msgs/SEAJointState.h>

//include statements for special functionality used
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <boost/random.hpp>
#include <boost/random/normal_distribution.hpp>
#include <cmath>
#include <complex>
#include <valarray>
#include <algorithm>    // std::find
#include <vector>       // std::vector


//global variables:----------------------------------------------------------------------

std::vector<std::vector<double> > g_vertices_set; //2-D vectors contains the verticies in the free work-space
//std::vector<std::vector<std::vector<double> > > g_edges_set; //3-dimension vector that contains the set of collision free edges
int g_number_of_samples=10000;//select number of samples in free workspace
double g_max_edge_length=0.5;//TODO: select value

std::vector<double> g_initial_vertex;//initial vertex setting up //g_initial_vertex
std::vector<double> g_trgt_vertex;//TODO: put real values
double trgt_zone=0.2 ;
bool g_trgt_reached= false;
double g_index_counter=1;


//RRT_Functions-------------------------------------------------------------------------------
void RandomAssignment(std::vector<double> rand_vertex){
	//a function that assignes a random variable to rand_vertex
	//TODO: fill up with a random generator code

	double generator;

	double range_from[]={-1.5,-1.5,-1.5,-1.5-1.5,-1.5,-1.5};//TODO: change the range for each joint seperatly
    double range_to[]= {1.5,1.5,1.5,1.5,1.5,1.5,1.5};


	for(int i=0; i<7; ++i){

		generator= ((double) rand() / (RAND_MAX));


		if(generator>.90){
			rand_vertex=g_trgt_vertex; 
			i=7;
		}
		else{
			rand_vertex.push_back((range_to[i]-range_from[i])*generator+range_from[i]);
		}
	}
}
double v_distance(std::vector<double> vertex_1, std::vector<double> vertex_2){
	//a function that takes two verteces and return the distance between them
	double dist=0;
	ROS_INFO("dist 1");

	for(int i=0; i<7; i++){
					ROS_INFO("size1 %d size2 %d",vertex_1.size(),vertex_2.size() );

		dist+=pow((vertex_1[i]-vertex_2[i]),2);
		
			ROS_INFO("dist 2");

	}
	
	return sqrt(dist);
}
double NearestVertex(std::vector<double> vertex){
	//TODO: fill up
	//A function that chooses the nearest node in the verteces set

	std::vector<double> nearest= g_vertices_set[0];//Temporary assumbtion in seek of comparison
	double nearest_index=0;
	double distance_1;
	double distance_2;

	for(int i=1; i<g_vertices_set.size(); i++){ //TODO: check g_vertices_set.size, 2-D vector
		
		distance_1=v_distance(vertex,g_vertices_set[0]);
		distance_2=v_distance(vertex,nearest);

		if(distance_1<distance_2){
			nearest=g_vertices_set[i]; //replace nearest with the new shortest in distance vertex 
			nearest_index= (double)i;
		}
	}
	return nearest_index;
}



std::vector<double> Steer(double nearest_index, std::vector<double> rand_vertex){
	//returns a node in the same direction  of the random_vertex, but with a maximum distance from the nearest vertex

	//TODO: Check calculation
	std::vector<double> nearest_vertex= g_vertices_set[nearest_index];
			ROS_INFO("steer 1");

	double current_dist=0;// distance btw nearest_vertex and rand_vertex
		ROS_INFO("steer 2");
		
	ROS_INFO("size1 %d size2 %d",nearest_vertex.size(),rand_vertex.size() );


	current_dist=v_distance(nearest_vertex,rand_vertex);
	ROS_INFO("steer 3");

	double dist_ratio= g_max_edge_length/current_dist; // ratio btw maximum edge lenght and current_dist
	std::vector<double> steered_vertex; 
	ROS_INFO("steer 4");

	if(dist_ratio>1){
//		rand_vertex.push_back(g_index_counter);
//		++g_index_counter;
		return rand_vertex;
	}
	else{
		for(int i=0; i<7; ++i){
			//calculate coordinates in 7 dimensions
			steered_vertex.push_back((1-dist_ratio)*nearest_vertex[i]+dist_ratio*rand_vertex[i]);
		}
		
//		steered_vertex.push_back(g_index_counter);
//		++g_index_counter;
		return steered_vertex;
	}
}


bool obstacle_free_vertex(std::vector<double> new_vertex){
	//The purpose of this function is to return true if new_vertex is in obsticle free ws
	//and false otherwise
	//TODO: fill up
	//get code from Tony
	return true;

}

bool obstacle_free_edge(std::vector<double> new_vertex,double nearest_index){
	//The purpose of this function is to return true if the edge is in obsticle free ws
	//and false otherwise
	//TODO: fill up
	//get code from Tony
	return true;

}
//finding_path -----------------------------------------------------------------------------

std::vector<std::vector<double> > FindPath(int p=0){
	
	//A function that finds the parent of each vertex starting from the target and moving towards the initial node, and construct a path accordingly 

	std::vector<std::vector<double> > path;
	int index;

	//construct reversed path from target to initial vertex

	int i=g_vertices_set.size();

	do{	
		path.push_back(g_vertices_set[i]); //adds the parent vertex to the path

		i = (int) g_vertices_set[i][7];

	
	}while(i>-1);

	// reverse back the path so that it goes from initial to target vertices
	std::reverse(path.begin(),path.end());

	ROS_INFO("Path generated with %i vertices", i);

	return path;

} 

void MoveToTRGT(std::vector<std::vector<double> > bath){
	//excecute the movement from current pose to target pose
	
}


//Main function-------------------------------------------------------------------------------

int main(int argc, char **argv){
	//basic ROS setup for communications with baxter
	ros::init(argc, argv, "RRT_Baxter");
	ros::NodeHandle n;
	ros::Publisher action_publisher = n.advertise<baxter_core_msgs::JointCommand>("/robot/limb/left/joint_command",1);


	std::vector<double> rand_vertex; //generate random vertex 
	//std::vector<double> nearest_vertex; //holds the value of the nearest vertex
	double nearest_index;
	std::vector<double> new_vertex; // steer the vertex with a Max distance
	std::vector<std::vector<double> > path;// contains a set of nodesfrom the goal to the initial pose

	

	//spicify initial and trgt vertix and add it to the vertices set

	for(int i=0;i<7;i++){
		g_initial_vertex.push_back(0);
		g_trgt_vertex.push_back(1);
	}
	g_initial_vertex.push_back(-1);
 	//double g_initial[]={0,0,0,0,0,0,0,-1};
	//double g_trgt[]={1,1,1,1,1,1,1};

	//g_initial_vertex (g_initial, g_initial + sizeof(g_initial) / sizeof(double) );//initial vertex setting up //g_initial_vertex
	//g_trgt_vertex (g_initial, g_initial + sizeof(g_initial) / sizeof(double) );

	g_vertices_set.push_back(g_initial_vertex); // add initial vertex to the vertices set

	int i=1;
	do{

		RandomAssignment(rand_vertex); // assign a random variable to rand_vertex

		nearest_index=NearestVertex(rand_vertex); // look for the nearest vertex and its index in g_vertices_set
					ROS_INFO("loc 1");

		new_vertex=Steer(nearest_index, rand_vertex); //steer to the maximum edge legnth

		if(obstacle_free_vertex(new_vertex)&&obstacle_free_edge(new_vertex,nearest_index)){
			g_vertices_set.push_back(new_vertex); //add new_vertex to the vertices set
			g_vertices_set[i].push_back(nearest_index); //add the index of the parent
			//g_edges_set[0].push_back(new_vertex); //add the new edge to the edges set.
			//g_edges_set[1].push_back(nearest_vertex); 


			
			//optional: AddGraph(new_vertex,nearest_vertex) a function that visually present the RRT process

			i++; // increase the counter only when the new edge and vertex are added. If not repeat the loop.
		}
//		else{
//			--g_index_counter;
//		}

		ROS_INFO("number of particles accepted=%f",g_index_counter+1);

		if(v_distance(new_vertex, g_trgt_vertex)<trgt_zone){
			g_trgt_reached=true; 
			ROS_INFO("RRT reached goal");
			break;
		}

	}while(i<g_number_of_samples);
	ROS_INFO("loc 3");

	if(g_trgt_reached==false){
		ROS_INFO("unable to connect to goal");
		return 0;
	}
	ROS_INFO("loc 4");

	//plan the path and store it in "path"
	path= FindPath( );

	//path movement execution-------------------------

	ros::Rate loop_rate(100);
  	baxter_core_msgs::JointCommand cmd;
	cmd.mode = baxter_core_msgs::JointCommand::POSITION_MODE;
	
	cmd.names.push_back("left_s0");
	cmd.names.push_back("left_s1");
	cmd.names.push_back("left_e0");
	cmd.names.push_back("left_e1");
	cmd.names.push_back("left_w0");
	cmd.names.push_back("left_w1");
	cmd.names.push_back("left_w2");
      
	cmd.command.resize(cmd.names.size());
	ROS_INFO("loc 5");


	for(int j=0; j<path.size(); j++){
		
		for(int k=0; k<path[j].size()-1;k++){
			cmd.command[k]=path[j][k];
		}
		action_publisher.publish(cmd);
		loop_rate.sleep();
		ros::spinOnce();
		//TODO: we need to wait until the execution of the movement
	}

	//MoveToTRGT(bath);




	return 0;
}
