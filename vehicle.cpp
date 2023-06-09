#include <iostream>
#include "vehicle.h"
#include <cstdlib>


using namespace std; 

Vehicle::~Vehicle(){}

bool Vehicle::is_ready(){
	return IsReady;
}

int Vehicle::get_flag() const {
	return flag;
}
int Vehicle::get_flag2() const {
	return flag2;
}

int Vehicle::get_exit() const {
	return exit;
}

void Vehicle::set_ready(bool var){
	IsReady=var;
}

int Vehicle::movement(){
	flag++;
	return flag;
}

int Vehicle::movement2(){
	flag2++;
	return flag2;
}
