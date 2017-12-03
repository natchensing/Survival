#include <iostream>
#include "lhd.h"


using namespace std;

#define MAX_ITEM  20

struct character
{
        string name;
        string gender;	//b or g
        string backpack[MAX_ITEM];
} you;

void entertc(void)
{
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
}

void setup(void)
{
        cout << "Before transporting you to the future, tell me your name: ";
        cin >> you.name;
        cout << "Are you a boy? Or are you a girl?\n";
        cout << "b for boy and g for girl: ";
        cin >> you.gender;
        while (you.gender != "b" && you.gender != "g")
        {
                cout << "Please enter b or g: ";
                cin >> you.gender;
        }
}

void printPara(string s) {
	string delimiter = "/";

	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
		entertc();
	    	token = s.substr(0, pos);
	    	cout << token << endl;
	    	s.erase(0, pos + delimiter.length());
	}
	entertc();
	cout << s << endl;
}

void intro(void)
{
        string s = "The year is 2202. /Mankind has exhausted almost all of Earth\'s natural resources, leading country after country into starvation and poverty. /Only the richest of the rich have the ability to live in comfort while the rest of us live as scavengers, scouring the cities and the suburbs for food and water. /It\'s every man for himself, and everyone can be an enemy. /In the small suburbs, a family of four lived in rare peace with its neighbours. ";
	printPara(s);
	cout << "The two heads of the household, James and Lily, go out during the day to hunt and gather necessities for their two children, " << you.name << " and their youngest, Annie. \n";
	s = "You are 16 this year, and Annie just turned 8. /Your family of four live in a run-down house--something the family can barely afford and struggle to make ends meet. /But even in times of struggle, there was still time for happiness and family. /You\'ve learned to cook and care for your sister at a young age, and know basic self-defense. /Life was very boring and routine-like for the most part. /However... ";
	printPara(s);
}

int next_case(int ans, int x, int y, int z) {
	if (ans == 1) {
		return x;
	} 
	else if (ans == 2) {
		return y;
	}
	else if (ans == 3) {
		return z;
	} 
	else {
		cout << "Please choose from 1, 2, or 3: ";
		cin >> ans;
		next_case(ans, x, y, z);
	}
	return 0;
}


void gameplay(int i) {
	string s;
	int answer;
    int next;

    // to clear settings
    answer = 0;
    next = 0;

	switch (i)
	{
		case 1:
			s = "One sunny morning, you wake up to sounds of your sister yelling and shouting at you: /Annie: \'Wake up sleepy head! Let\'s go outside today! Mom and Dad left early and it\'s sunny! We haven\'t had sun for so long!\' /You: \'Mmmmm... I\'m still sleeping. Did you have breakfast yet?\' /Annie: \'No, I\'m hungry! Can you make breakfast so we can go outside to play?\'";
	        	printPara(s);
			cout << "WHAT DO YOU DO? \nOPTIONS (choose 1, 2, or 3): \n1. \'No, go make your own breakfast.\' \n2. \'Fine... I\'ll be downstairs in a minute. What do you want for breakfast?\' \n3. \'Zzzzzz.\'\n";
			cin >> answer;
			next = next_case(answer,2,3,2);
			gameplay(next);
			break;
		case 2:
			s = "You snuggle up in the covers and go back to sleep. /Morning turns to noon and you finally get up, heading downstairs only to see Annie outside on the porch running around. /Not a blade of green is to be seen. /You haven\'t seen anything living aside from your family and the cockroaches under the broken sink. /You: \'Annie! Come back inside. I\'ll make you your breakfast.\' /Annie: \'Thanks! But I already ate! I had toast and jam!\'";
			printPara(s);
			gameplay(5);
			break;
		case 3:
			s = "You head downstairs and see Annie sitting eagerly at the kitchen table waiting for you. /Breakfast consisted of scrambled eggs and french toast and you both gobble it down. /Annie: \'Can we go outside now? I wanna play with Mr. Sunshine today!\'";
			printPara(s);
			cout << "WHAT DO YOU DO? \nOPTIONS (choose 1, 2, or 3): \n1. \'Sure, let\'s go!\' \n2. \'You go ahead, I\'ll watch from the porch.\' \n3. \'Alright, I\'ll be inside.\'\n";
			next = next_case(answer,1,1,4);
			gameplay(next);
			break;
		case 4:
			s = "You head to the living room, opening the broken blinds and making yourself comfortable on the couch.";
			gameplay(6);
			break;
		case 5: 
			s = "Shrugging, you enter the kitchen at the back of the house to make yourself breakfast. /Cracking the last egg into a frying pan you proceed to make some scrambled eggs and french toast.";
			printPara(s);
			gameplay(6);
			break;
		case 6:
			s = "Suddenly, you hear Annie\'s scream out in front. /You drop every in your hands and run towards the front of the house, grabbing your trusted rifle along the way. /Your eyes widen in horror as you see two young adults dragging Annie away who has a gag in her mouth and her hands tied behind her back, struggling.";
			cout << "WHAT DO YOU DO? \nOPTIONS (choose 1, 2, or 3): \n1. Run out and shout \'Let go of my sister!\'. \n2. Silently try to shoot one of the kidnappers. \n3. Calmly walk outside and try to talk with the kidnappers.\n";
			cin >> answer;
			next = next_case(answer,7,1,1);
			gameplay(next);
			break;
		case 7:
			s = "You run as fast as you can towards the trio. /However, one of them reacts fast enough to take out his gun and points it at you while the other grabs Annie and puts her in a choke hold. /\'Stop right there!\'' Kidnapper 1 says./You freeze, unsure of what to do. \'I don’t know who you think you are, but let go of my sister!\'";
			if (you.gender == "b") {
				gameplay(8);
			} else gameplay(9);
			break;
		case 8: 
			s = "\'Aw, look at the big boy who\'s coming to save his precious little sis.\' Kidnapper 1 says. /You point the gun to him. /\'Let go of my sister.\'' You say./\'Don\'t you point that big thing at me boy, shoot me and your sister\'s dead.\'' He says, pointing the gun at Annie./";
			cout << "WHAT DO YOU DO? \nOPTIONS (choose 1, 2, or 3): \n1. Lower your gun \n2. Shoot Kidnapper 1 who has Annie\n3.Shoot Kidnapper 2 who’s pointing the gun at you\n";
			cin >> answer;
			next = next_case(answer,10,1,1);
			gameplay(next);
			break;
		case 9:
		case 10:
			s = "\'Well, we have no use for a scrawny guy like you, so off you go.\'' Kidnapper 2 says. /You tense. He pulls the trigger and you collapse on the ground. /You drift off into darkness while you hear Annie screaming :";
			printPara(s);
			entertc();
			cout << "\'" << you.name  << "\'!"<< endl; 
			cout << "GAME OVER." << endl;
			break;
		default: cout << "Dev use: This is not a scenario of the game! \n";
		break;
	}
}


int main(int argc, char const *argv[])
{
	setup();
	intro();
	gameplay(1);
	return 0;
}


