// search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

const int size = 7;
stack container;

int search(int, int, int, char[], char[][size]);

int main()
{
	char a[size][size] = {
		{ '$', '$', '$', '$', '$', '$', '$' },
		{ '$', '$', '$', '$', '$', '$', '$' },
		{ '$', '$', 'r', '$', '$', '$', '$' },
		{ '$', '$', '$', 'e', '$', '$', '$' },
		{ '$', '$', 'z', '$', '$', '$', '$' },
		{ '$', '$', '$', 'a', '$', '$', '$' },
		{ '$', '$', '$', '$', '$', '$', '$' },
	};

	string name;
	cout << "Enter Name You Want To Search\n";
	cin >> name;

	int k = 0;
	int tempi, tempj, temp_2i, temp_2j;

	for (int i = 1; i < size - 1; i++) {
		for (int j = 1; j < size - 1; j++) {
			if (a[i][j] == name[k]) {
				tempi = i;
				tempj = j;
				container.push(i, j);
				k++;

				while (k < name.length()) {
					if (a[i - 1][j - 1] == name[k]) {
						i--;
						j--;
						container.push(i, j);
						k++;
						temp_2i = i;
						temp_2j = j;
					}
					else if (a[i][j - 1] == name[k]) {
						j--;
						temp_2i = i;
						temp_2j = j;
						container.push(i, j);
						k++;
					}
					else if (a[i + 1][j - 1] == name[k]) {
						i++;
						j--;
						temp_2i = i;
						temp_2j = j;
						container.push(i, j);
						k++;
					}
					else if (a[i - 1][j] == name[k]) {
						i--;
						temp_2i = i;
						temp_2j = j;
						container.push(i, j);
						k++;
					}
					else if (a[i + 1][j] == name[k]) {
						i++;
						temp_2i = i;
						temp_2j = j;
						container.push(i, j);
						k++;
					}
					else if (a[i - 1][j + 1] == name[k]) {
						i--;
						j++;
						temp_2i = i;
						temp_2j = j;
						container.push(i, j);
						k++;
					}
					else if (a[i][j + 1] == name[k]) {
						j++;
						temp_2i = i;
						temp_2j = j;
						container.push(i, j);
						k++;
					}
					else if (a[i + 1][j + 1] == name[k]) {
						i++;
						j++;
						temp_2i = i;
						temp_2j = j;
						container.push(i, j);
						k++;
					}
					else {
						i = tempi;
						j = tempj;
						while (!container.isEmpty()) {
							container.pop();
						}
						k = 0;
					}
				}// end of while loop
			}//end of if 
		}//end of second for loop
	}//end of first for loop

	if (k == 0) {
		cout << "Word not found";
	}
	else {
		container.displayStack();
	}

	cin.get();
	cin.get();
}