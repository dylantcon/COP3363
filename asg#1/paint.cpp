
#include <iostream>
using namespace std;

int main() {

	double base, wallHeight, wallRoofHeight, windowW, windowH, area;                                            //declaration of reqd. variables
	cout << "\nWelcome to Paint Calculator 2023!!\n\nHow wide is the wall (in feet)? ", cin >> base;            //user inputs width of base
	cout << "and how high is the wall to the bottom of the roof? ", cin >> wallHeight;                          //user inputs height of wall only
	cout << "and how high is the wall to the top of the roof? ", cin >> wallRoofHeight;                         //user inputs height of wall + roof
	cout << "How wide is the window (in feet)? ", cin >> windowW;                                               //user inputs width of window
	cout << "and what is the window\'s height? ", cin >> windowH;                                               //user inputs height of window

	area = ((( wallRoofHeight - wallHeight ) * ( base * 0.5 ))) + ( base * wallHeight );                        //calculation of total surface area of side of house
	double paintableArea = area - ( windowW * windowH );                                                        //declares paintableArea variable, calculated from house area minus window area

  cout << "\nA side wall that is\n   " << base << "\' wide and\n   " << wallHeight << "\' tall to the roof bottom and\n   ";  //recounts user input to user for clarity
	cout << wallRoofHeight << "\' tall to the roof top,\ncontaining a window that is\n   " << windowW << "\' wide and\n   ";
	cout << windowH << "\' tall,\nhas ";

	cout.setf(ios::fixed);                                                                                      //specifying fixed point notation so that we can
	cout.setf(ios::showpoint);                                                                                  //use cout.precision(int n) to fix decimal places

  cout.precision(1), cout << paintableArea << " square feet of paintable wall\nand would require ";                      //limits double paintableArea to tenths
	cout.precision(2), cout << paintableArea / 400.00 << " cans of paint\n(assuming that each can will cover 400 square "; //limits ( double paintableArea / 400.00 ) to hundreths
	cout << "feet of wall).\n\nThanks for using Paint Calculator 2023. Goodbye!!\n" << endl;

}
