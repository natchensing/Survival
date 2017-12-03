#ifndef __lhd_h__
#define __lhd_h__

using namespace std;

struct character;			// character has a name, gender, and a backpack

void entertc	();			
void setup		();			
void printPara	(string s);	// prints paragraph is our format
void intro		();			
int next_case	(int ans, int x, int y, int z);
void gameplay	(int i);	

#endif 