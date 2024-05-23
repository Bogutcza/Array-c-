
#include <iostream>
#define SIZE 10

#include "array.h"
using namespace std;


void menu() {

    using namespace std;

    cout << "Simple array" << endl ;

    cout << "1. Enter the values into the array"<< endl ;
    cout<<"2. Display the content of the array"<< endl ;
    cout<< "3. Determine the minimum value" << endl ;
    cout <<"4. Deterime the maximum value" << endl ;
    cout <<"5. Determine the average value" << endl ;
    cout <<"6. Saving data to the file" << endl ;
    cout <<"7. Restoring data from the file" << endl ;
    cout <<"0. EXIT" << endl ;
    cout <<"Select an option:" << endl ;
}


int main() {
    int array[SIZE] = {1, 2, 3, -4, 50, 6, 7, 8, 9, 10};


    int option = 0;
    int max = FindMaximumValue(array);
    int min = FindMinimumValue(array);
    float average = CalculateAverage(array);

    do {
        menu();
        cin>>option;
        switch (option) {
            case 0:
                break;
            case 1:
                cout << "Enter the values into the array" << endl ;
                enterDataIntoArray(array);
                break;
            case 2:
                cout <<"Display the content of the array" << endl ;
                displayArray(array);
                break;
            case 3:
                cout <<"Determine the minimum value" << endl ;
                cout << "Minimum value = " <<  FindMinimumValue(array) << endl << endl;
                break;
            case 4:
                cout <<"Deterime the maximum value" << endl ;
                cout << "Maximum value = " << FindMaximumValue(array) << endl << endl;
                break;
            case 5:
                cout << "Determine the average value" << endl ;
                cout << "Average value = " << CalculateAverage(array)<< endl << endl;
                break;
            case 6:
                cout <<"Saving data to the file" << endl ;
                if(!saveArrayToFile(array)){
                    cout <<"Array saved to the file" << endl ;
                }else{
                    cout <<"Something gone wrong" << endl ;
                }
                break;

            case 7:
                cout <<"Restoring data from the file" << endl ;
                if (!restoreArrayFromFile(array)) {
                    cout <<"Array restored from the file" << endl ;
                    cout <<"Array content after restoration:" << endl ;
                    displayArray(array);
                } else {
                    cout <<"Something gone wrong" << endl ;
                }
                break;


            default:
                cout <<"choose the right option" << endl ;




        }

    }
    while (option != 0);
    {
        printf("END\n");
    }
    return 0;


}
