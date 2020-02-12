#include "trafficGenerator.h"

trafficGenerator::trafficGenerator(string fName)
{
	setFilename(fName);
	settingDataMembers();
}

void trafficGenerator::setFilename(string fileName)
{
	fname = fileName;
}

string trafficGenerator::getFilename()
{
	return fname;
}


void trafficGenerator::settingDataMembers()
{
	string fName = getFilename();
	string pType;
	ifstream fin(fName);
	string temp;

	//fin.open("Data.txt");
	cout << fName ;
	if (!fin) {
		cerr << "Unable to open file datafile.txt";
		exit(1);   // call system to stop
	}

	fin >> totalFloor;

	for (int i = 0; i < 1; i++) {
		while (fin.get() != '\n')
			fin.ignore();
	}

	while (!fin.eof()) {
		fin >> pType;

		if (pType == "Visitor") {
			visiRequir.passengerType = pType;
			fin >> visiRequir.passArrivingProb;
			fin >> temp;
			fin >> visiRequir.regCall;
			fin >> visiRequir.emerCall;
			fin >> visiRequir.evacCall;
			visiRequir.ExWgh1 = 0;
			visiRequir.ExWgh2 = 0;
		}
		else if (pType == "Patient") {
			patiRequir.passengerType = pType;
			fin >> patiRequir.passArrivingProb;
			fin >> temp;
			fin >> patiRequir.regCall;
			fin >> patiRequir.emerCall;
			fin >> patiRequir.evacCall;
			fin >> temp;
			fin >> patiRequir.ExWgh1;
			fin >> patiRequir.ExWgh2;
		}
		else if (pType == "Support") {
			supstaffRequir.passengerType = pType;
			fin >> temp;
			fin >> supstaffRequir.passArrivingProb;
			fin >> temp;
			fin >> supstaffRequir.regCall;
			fin >> supstaffRequir.emerCall;
			fin >> supstaffRequir.evacCall;
			fin >> temp;
			fin >> supstaffRequir.ExWgh1;
			fin >> supstaffRequir.ExWgh2;
		}
		else if (pType == "Medical") {
			medstaffRequir.passengerType = pType;
			fin >> temp;
			fin >> medstaffRequir.passArrivingProb;
			fin >> temp;
			fin >> medstaffRequir.regCall;
			fin >> medstaffRequir.emerCall;
			fin >> medstaffRequir.evacCall;
			medstaffRequir.ExWgh1 = 0;
			medstaffRequir.ExWgh2 = 0;
		}
		else if (pType == "Security") {
			secstaffRequir.passengerType = pType;
			fin >> temp;
			fin >> secstaffRequir.passArrivingProb;
			fin >> temp;
			fin >> secstaffRequir.regCall;
			fin >> secstaffRequir.emerCall;
			fin >> secstaffRequir.evacCall;
			secstaffRequir.ExWgh1 = 0;
			secstaffRequir.ExWgh2 = 0;
		}
		else {
		}

	}
}

void trafficGenerator::display()
{
	cout << "Passenger Type  " << "Arriving Probabitlity  " << "Regular Call  " << "Emer Call  " << "Evac Call  " << "Extra Weight Range" << endl;
	cout << visiRequir.passengerType << "\t \t \t" << visiRequir.passArrivingProb << "\t \t" << visiRequir.regCall << "\t \t" << visiRequir.emerCall << "\t" << visiRequir.evacCall << "\t \t" << visiRequir.ExWgh1 << "-" << visiRequir.ExWgh2 << endl;
	cout << patiRequir.passengerType << "\t \t \t" << patiRequir.passArrivingProb << "\t \t" << patiRequir.regCall << "\t \t" << patiRequir.emerCall << "\t" << patiRequir.evacCall << "\t \t" << patiRequir.ExWgh1 << "-" << patiRequir.ExWgh2 << endl;
	cout << supstaffRequir.passengerType << "\t \t \t" << supstaffRequir.passArrivingProb << "\t \t" << supstaffRequir.regCall << "\t \t" << supstaffRequir.emerCall << "\t" << supstaffRequir.evacCall << "\t \t" << supstaffRequir.ExWgh1 << "-" << supstaffRequir.ExWgh2 << endl;
	cout << medstaffRequir.passengerType << "\t \t \t" << medstaffRequir.passArrivingProb << "\t \t" << medstaffRequir.regCall << "\t \t" << medstaffRequir.emerCall << "\t" << medstaffRequir.evacCall << "\t \t" << medstaffRequir.ExWgh1 << "-" << medstaffRequir.ExWgh2 << endl;
	cout << secstaffRequir.passengerType << "\t \t" << secstaffRequir.passArrivingProb << "\t \t" << secstaffRequir.regCall << "\t \t" << secstaffRequir.emerCall << "\t" << secstaffRequir.evacCall << "\t \t" << secstaffRequir.ExWgh1 << "-" << secstaffRequir.ExWgh2 << endl;
}

int trafficGenerator::randNumGen(int range, char addreq)
{
	int random_num;
	random_num = rand() % range;

	if (addreq == 'y' or addreq == 'Y')
	{
		random_num++;
	}
	return random_num;
}

int trafficGenerator::addweight(int max_weight)
{
	int random_num;
	random_num = rand() % max_weight;
	if (random_num == 0)
	{
		random_num++;
	}
	return random_num;
}

Passenger* trafficGenerator::generatePassenger(sysGenerator* sg, int typeNo)
{
	time_t now = time(0);
	tm* ltm = localtime(&now);

	string type;
	int currFloor, desFloor, weightAge;
	Passenger* p{};
	int visitors, patients, ss, ms, se;
	int v1, v2, v3, v4, v5, v6;

	visitors = visiRequir.passArrivingProb * 100;
	patients = patiRequir.passArrivingProb * 100;
	ss = supstaffRequir.passArrivingProb * 100;
	ms = medstaffRequir.passArrivingProb * 100;
	se = secstaffRequir.passArrivingProb * 100;

	v1 = visitors + 1;
	v2 = visitors + patients + 1;
	v3 = visitors + patients + ss + 1;
	v4 = visitors + patients + ss + ms + 1;
	v5 = visitors + patients + ss + ms + se + 1;
	

	int count = 0;
	do {
		currFloor = rand() % totalFloor;
		desFloor = rand() % totalFloor;
	} while (currFloor == desFloor);

	if (0 <= typeNo && typeNo < v1 && visitor::getCounter() < round(statKeeper::getTotalPass() * visiRequir.passArrivingProb))
	{
		p = new visitor;
		p->setWeightage(1);
		p->setregcall("Y");
		p->setemercall("N");
		p->setevaccall("N");
	}
	else if (v1 <= typeNo && typeNo < v2 && patient::getCounter() < round(statKeeper::getTotalPass() * patiRequir.passArrivingProb))

	{
		p = new patient;
		p->setWeightage(1 + addweight(patiRequir.ExWgh2));
		p->setregcall("Y");
		p->setemercall("N");
		p->setevaccall("N");
		
	}
	else if (v2 <= typeNo && typeNo < v3 && supportstaff::getCounter() < round(statKeeper::getTotalPass() * supstaffRequir.passArrivingProb))

	{
		p = new supportstaff;
		p->setWeightage(1 + addweight(supstaffRequir.ExWgh2));
		
	}
	else if (v3 <= typeNo && typeNo < v4 && medicalstaff::getCounter() < round(statKeeper::getTotalPass() * medstaffRequir.passArrivingProb))

	{
		p = new medicalstaff;
		p->setWeightage(1);
	}
	else if (v4 < typeNo && typeNo < v5 && security::getCounter() < round(statKeeper::getTotalPass() * secstaffRequir.passArrivingProb))
	{
		p = new security;
		p->setWeightage(1);

	}
	if (p != NULL)
	{
		p->setCreationTime(0);
		p->setCurrFloor(currFloor);
		p->setDesFloor(desFloor);
		sg->queueGenerate(currFloor, desFloor, p);
	}
	return p;
}
