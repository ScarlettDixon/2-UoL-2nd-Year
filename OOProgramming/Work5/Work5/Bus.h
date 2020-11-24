#pragma once
class Bus
{
private:
	bool running;
	double price;
public:
	Bus();
	Bus(bool running, double price);
	~Bus();
	void horn();
	void route();
	void enableRun();
	void stopRun();
	void setPrice(double price);
	void getPrice();
};

