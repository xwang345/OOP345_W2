#include "Station.h"
#include <string>
#include <iomanip>
using namespace w2;
using namespace std;

Station::Station() {
	passes[ADULT_PASS] = 0;
	passes[STUDENT_PASS] = 0;
	stationName = '\0';
}

Station::Station(istream & is) {
   string str;
   getline(is, str, ';');        // get station name
   is.ignore();
   stationName = str;
   is >> passes[STUDENT_PASS];   // get number of student passes
   is.ignore();
   is >> passes[ADULT_PASS];     // get number of adult passes
   is.ignore();
}

void Station::update() {
   cout << stationName << "\n";
   cout << " Student Passes sold : ";
   int student;
   cin.clear();
   cin >> student;
   passes[STUDENT_PASS] -= student;
   cout << " Adult   Passes sold : ";
   int adult;
   cin >> adult;
   passes[ADULT_PASS] -= adult;
}

void Station::restock() {
   cout << stationName << "\n";
   cout << " Student Passes added : ";
   int student;
   cin >> student;
   passes[STUDENT_PASS] += student;

   cout << " Adult   Passes added : ";
   int adult;
   cin >> adult;
   passes[ADULT_PASS] += adult;
}

void Station::report() {
   /*cout.setf(ios::left);
   cout.width(22);
   cout << stationName;

   cout.width(6);
   cout << passes[STUDENT_PASS];

   cout.width(3);
   cout << passes[ADULT_PASS] << endl;*/

   /*cout << setfill(' ') << left << setw(20) << stationName;
   cout << right << setw(6) << fixed << passes[STUDENT_PASS];
   cout << right << setw(6) << fixed << passes[ADULT_PASS];
   cout << endl;*/

   cout << setw(17) << left << stationName  << setw(8) << right << passes[STUDENT_PASS]
        << setw(6) << right << passes[ADULT_PASS] << endl;
}

void Station::write(ostream& os) {
   os << stationName << ';' << passes[STUDENT_PASS] << ' ' << passes[ADULT_PASS] << endl;
}
