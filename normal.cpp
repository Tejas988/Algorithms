#include <bits/stdc++.h>
using namespace std;






class Car{
private:
	int reg_no;
	string color;
	string owner;
public:
	Car()
	{
		reg_no=0;
	}
	Car(int regno,string color)
	{
		reg_no=regno;
		this.color=color;
	}	
};

class Slot{
private:
	int slotno;
	Car *parkedCar;
public:
	Slot()
	{
		slotno=-1;
	}
	Slot(int slotno)
	{
		this.slotno=slotno;
		this.parkedCar=nullptr;
	}
	void assignCar(Car &parkedCar)
	{
		this.parkCar=&parkedCar;
	}	
	void unassignCar()
	{
		this.parkedCar=nullptr;
	}
	bool isfree()
	{
		return this.parkedCar==nullptr;
	}
};


class ParkingScheme{
private:
	priority_queue<int> pq;
public:
	ParkingScheme(int capacity)
	{
		for(int i=1;i<=capacity;i++)
			pq.push(i);
	}	
	int giveNxtSlot()
	{	
		if(pq.empty())
			return -1;
		int nxt=pq.top();
		pq.pop();
		return nxt;
	}
	void addFreeSlot(int slot)
	{	
		pq.push(slot);
	}

};

class ParkingLot{
private:
	int capacity; 
	vector<Slot> slots;
	priority_queue<int> pq;
public:
	ParkingLot(int capacity)
	{
		this.capacity=capacity;
		slots.resize(capacity+1);
		for(int i=1;i<=capacity;i++)
		{
			pq.push(i);
			slots[i]
		}
	}
	void parkCar(Car car,const int slotno)
	{	
		if(slots[slotno].isfree())
		slots[slotno].assignCar(car);
		else
		{
			throw "Slot is not free";
		}
	}
	void unparkCar(const int slotno)
	{
		slots[slotno].unassignCar();
	}
};

int main()
{
	
	int capacity;
	cout<<"Give capacity"<<endl;
	cin>>capacity;
	ParkingLot p=new ParkingLot(capacity);
	ParkingScheme p1scheme=ParkingScheme(capacity);
	
}
