#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <iterator>
#include "vehicle.h"
#include "extern.h"



class Segment;
class Toll;

class Highway{
	private:
	list<Segment*> list_of_segs; // lista apo segment
	list<Segment*>::iterator it3;
	public:
	static int Nsegs; //einai auta pou diavazo apo grammi entolwn einai public wste na exei prosvash h main
	static int K;
	static int Percent;
	Highway(); 
	~Highway();
	void operate();
	int GetVehicleNumber(); // gyrnaei ton arithmo twn oximatwn 
	void AddNode(int,int); // ftiaxnei kai allo segment
};




class Entrance{
	private:
	vector<Toll*>::iterator iter; 
	vector<Toll*> t;
	int Seg;
	int Tolls;
	int eTolls;
	public:
	Entrance(int);
	~Entrance();
	vector<Vehicle*> operate(int);
	int vehicles_in_toll_queue(); // ta oximata pou einai sthn oura
};

class Segment{
	private:
	Entrance ent;
	int capacity;
	int seg;
	int number_of_vehicles;
	vector<Vehicle*>::iterator iter2;
	vector<Vehicle*> v;
	public:
	Segment(int,int);
	~Segment();
	int get_number_of_vehicles();
	void operate(Segment*);
	vector<Vehicle*> pass(Segment*);
	int enter(vector<Vehicle*>);
	void exit();
	int get_cap() const;
	bool check(int);
};





 class Toll
{
	private:
	bool is_regular;
	int K;
	int eksodos;
	int cap;
	public:
	queue<Vehicle*> vq;
	Toll(int,int,bool);
	~Toll();
	int get_size_of_vq() const;
	void push_into_vq(int);
	Vehicle* pop1();//vgazei apo to queue
	void modify();//allazei to k
};

class Highway;
