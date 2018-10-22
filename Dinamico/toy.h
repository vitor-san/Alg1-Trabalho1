#ifndef TOY_H
	#define TOY_H

	typedef struct toy TOY;
	typedef TOY* Toy;

	Toy newToy(int serial_number, const char *model);
	int getSerial(Toy x);
	char *getModel(Toy x);
	void delToy(Toy x);

#endif