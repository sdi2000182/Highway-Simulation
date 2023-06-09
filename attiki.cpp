#include <iterator>
#include "attiki1.h"


using namespace std;
Highway::Highway(){
	int cap,i;
	for(i=0;i<Nsegs;i++){
		cout<<"\n\n Capacity of Segment " << i << endl;
		cin >> cap;
		AddNode(i,cap);
	}
	cout << "\nHighway has been constructed\n";
}

Highway::~Highway(){
	cout << "Highway to be destructed\n";
	for(it3 = list_of_segs.begin(); it3 != list_of_segs.end(); it3++)
    {
        delete (*it3);
        cout << "\n\n";
    }
    list_of_segs.clear();
}

void Highway::AddNode(int i,int cap)
{
    Segment* var = new Segment(i,cap);
    list_of_segs.push_back(var);
}


int Highway::GetVehicleNumber()
{
    int var = 0;
    for(list<Segment*>::iterator it8 = list_of_segs.begin(); it8 != list_of_segs.end(); it8++){
		var += (*it8)->get_number_of_vehicles();}//prosthetw sto yparxon ton arithmo twn oximatwn

    return var;
}

void Highway::operate() //diasxizw thn lista kai h segment operate pairnei orisma to previous 
{
    list<Segment*>::iterator c;
	list<Segment*>::iterator v;
	int flag=0;//einai ena flag gia na mhn kseperaso ta  oria
    for(list<Segment*>::iterator i = list_of_segs.begin(); i == list_of_segs.end(); i++)
    {	if(flag==0){
		i++;
		}
		c=i--;
        (*i)->operate(*c);
		flag++; 
    }        
    cout << "Number of vehicles in the highway " << GetVehicleNumber() << endl;
    cout << "\n";
}