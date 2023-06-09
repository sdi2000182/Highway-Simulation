#include "attiki1.h"

using namespace std;

Segment::Segment(int ind,int cap) : ent(ind),seg(ind),capacity(cap){
	number_of_vehicles = NewCarsSegment%((cap%7)+1)+1;
	Vehicle* ptr;
	int i;
	for(i=0;i<number_of_vehicles;i++){
		iter2 = v.begin();
		ptr=new Vehicle(Highway::Nsegs,seg);
		iter2= v.insert(iter2,ptr);
	}
	cout << "A segment has been created\n";
}

Segment::~Segment(){
	cout << "A segment to be destructed\n\n";
	int j;
	for(j=0;j<number_of_vehicles;j++) 
	{ delete v[j]; 
	}
    v.clear();
}

int Segment::enter(vector<Vehicle*> prev){//mpainoun oximata apo diodia alla kai apo prev_seg
	vector<Vehicle*> en_vector;
	v.insert(v.end(),prev.begin(),prev.end());
	number_of_vehicles+= prev.size();
	if(number_of_vehicles<capacity){
		int temp=capacity-number_of_vehicles;
		en_vector=ent.operate(temp);
		v.insert(v.end(),en_vector.begin(),en_vector.end());
		number_of_vehicles+=en_vector.size();
		return en_vector.size();
	}
	else{
		return 0;
	}
}

int Segment::get_number_of_vehicles(){
    return number_of_vehicles;
}

void Segment::exit()
{   int i;
    for(i=0;i<number_of_vehicles;i++)
     if(check(i) && v[i]->is_ready())
     {
         delete v[i]; 
         v.erase(v.begin()+i);
         number_of_vehicles--; 
		 i--;
     } 
}//ginetai h eksodos otan prepei

vector<Vehicle*> Segment::pass(Segment* next_node)
{
    Vehicle* ptr2;
    vector<Vehicle*> to_be_passed;
    vector<Vehicle*>::iterator iter5;
    int c,i;
    c=next_node->get_number_of_vehicles();
    for(i = 0;i<number_of_vehicles; i++)
     if(v[i]->is_ready() && (!check(i)) && c<next_node->get_cap())
     {
         ptr2 = v[i];
         ptr2->set_ready(false); 
         ptr2->movement(); 
         iter5=to_be_passed.begin();
         iter5=to_be_passed.insert(iter5,ptr2);
         c++;
         v.erase(v.begin()+i);
         number_of_vehicles--;
	 	i--;
     }
     return to_be_passed;
}

int Segment::get_cap() const{
    return capacity;
}
  
bool Segment::check(int i){
int a1 = v[i]->get_exit();
int a2 = v[i]->get_flag() + 1;
return a1=a2;}


void Segment::operate(Segment* prev)
{
    vector<Vehicle*> passing;
    int entering;
    int to_be_moved = 0, is_ready2 = 0;
    int waiting; 
    int i;
    int flag3;
    if(seg != 0)
    {
        exit();
        for(i = 0; i < prev->get_number_of_vehicles(); i++) { 
		if(prev->v[i]->is_ready()){
			is_ready2++;}}
        passing = prev->pass(this);
        to_be_moved = passing.size();
    }

    waiting = ent.vehicles_in_toll_queue();
    entering = enter(passing);
    waiting -= entering; 
    if(entering >= waiting)
   {
	cout << "Threite tis apostaseis asfaleias sto tmima meta ton komvo " << seg << "\n\n";}
    else{
	cout << "Kathusterhseis sthn eisodo tou komvou " << seg << "\n\n";
        if(to_be_moved < is_ready2 && seg!=0) {
            cout << "Kathusterhseis meta ton komvo " << seg << "\n\n" ;}
    }
    flag3=Highway::Percent*number_of_vehicles; 
    for(i=0;i<flag3;i++) {
		v[i]->set_ready(true);}    
}