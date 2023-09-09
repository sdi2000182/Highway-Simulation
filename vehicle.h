#include <iostream>
#include <cstdlib>

using namespace std;


class Vehicle{
	private:
	bool IsReady;
	int flag;
	int exit;
	int flag2;
	public:
	Vehicle(int size_of_seg_list,int flag1=-1,int flag2=-1){
	this->flag=flag;
	this->flag2=flag2;
	IsReady=false;
	if(flag!=-1){
		 exit=rand()%(size_of_seg_list - flag) + (flag + 1);
		 cout<<"Vehicle entering segment of highway\n ";
	}
	else{
		exit=rand()%(size_of_seg_list - flag2) + (flag2 + 1);
        cout << "Vehicle in waiting toll line\n" ;
	}
}
~Vehicle();
bool is_ready();
int get_exit() const;
int get_flag2() const;
int get_flag() const;
void set_ready(bool);
int movement();
int movement2();
};
