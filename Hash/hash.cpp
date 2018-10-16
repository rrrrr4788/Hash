#include"hash.h"

extern double loadFactor = 0;

void modXchain(int* stuff,int size) {
	int numCollisions = 0;
	/*while (loadFactor != 1) {

	}*/
}
void modXopen(int* stuff,int size) {
	int numCollisions = 0;
	int key = 0;
	int temp = 0;
	double load = 0;
	int i = 0;
	while (loadFactor != 1) {
		key = rand() % (3 * size);
		temp = key % size;
		if (stuff[temp] == -1) {
			stuff[temp] = key;
			load++;
		}
		else {
			bool flag = false;
			numCollisions++;
			if (temp == size - 1)
				temp = 0;
			else
				temp++;
			while (!flag) {
				if (stuff[temp] == -1) {//if unassigned, assign the key's value to it
					stuff[temp] = key;
					load++;
					flag = true;
				}
				else {//if not, then move to the next element
					if (temp == size - 1)//if the current position is at the end of the table, go to 0
						temp = 0;
					else
						temp++;
				}
			}
		}
		loadFactor = load / size;
		if (static_cast<int>(load)%(size/10) == 0) {//This happens when load factor is the multiple of 0.1
			cout << "Number of collisions when loadFactor = ";
			cout << loadFactor;
			cout<< " for modXopen of size " << size << ": " << numCollisions << endl;
			if(loadFactor!=1)
			cout << "c = " << (1 + 1 / (1 - loadFactor)) / 2 << endl;
		}
	}
	//cout << "c = " << (1 + 1 / (1 - loadFactor)) / 2 << endl;
	cout << endl;
	loadFactor = 0;
	cout <<endl;
}
void midSXchain(int* stuff,int size) {
	int numCollisions = 0;
	/*while (loadFactor != 1) {

	}*/
}
void midSXopen(int* stuff,int size) {
	int numCollisions = 0;
	int key = 0;
	int temp = 0;
	double load = 0;
	int i = 0;
	string tempString = "";
	while (loadFactor != 1) {
		key = rand() % (3 * size);
		temp = key*key;//square the key
		tempString = to_string(temp);
		if(tempString.length() < 2 * to_string(key).length()){
			tempString = '0' + tempString;//add a 0 to the beginning of the string if the square's digits are less than twice of the seed's
		}
		tempString = tempString.substr((tempString.length() - to_string(key).length()) / 2, to_string(key).length());//get the digits in the middle
		temp = stoi(tempString);//get the value after mid square
		temp = temp % size;
		if (stuff[temp] == -1) {
			stuff[temp] = key;
			load++;
		}
		else {
			bool flag = false;
			numCollisions++;
			if (temp == size - 1)
				temp = 0;
			else
				temp++;
			while (!flag) {
				if (stuff[temp] == -1) {//if unassigned, assign the key's value to it
					stuff[temp] = key;
					load++;
					flag = true;
				}
				else {//if not, then move to the next element
					if (temp == size - 1)//if the current position is at the end of the table, go to 0
						temp = 0;
					else
						temp++;
				}
			}
		}
		loadFactor = load / size;
		if (static_cast<int>(load) % (size / 10) == 0) {//This happens when load factor is the multiple of 0.1
			cout << "Number of collisions when loadFactor = ";
			cout << loadFactor;
			cout << " for midSXopen of size " << size << ": " << numCollisions << endl;
			if (loadFactor != 1)
			cout << "c = " << (1 + 1 / (1 - loadFactor)) / 2 << endl;
		}
	}
	cout << endl;
	loadFactor = 0;
	cout << endl;
}


int main() {

	int * size100 = new int[100];
	fill_n(size100, 100, -1);//-1 is the initial value so that whether an array element is "empty" can be identified
	int * size50 = new int[50];
	fill_n(size50, 50, -1);
	int * size10 = new int[10];
	fill_n(size10, 10, -1);

	node** sIze100 = new node*[100];
	node** sIze50 = new node*[50];
	node** sIze10 = new node*[10];

	int choice;
	cout << "input" << endl;
	cin >> choice;
	switch (choice) {
	case 1: {
			/*modXchain(sIze100, 100);
			modXchain(sIze50, 50);
			modXchain(sIze10, 10);
			break;*/
	}case 2: {
		modXopen(size100, 100);
		modXopen(size50, 50);
		modXopen(size10, 10);
		break;
	}case 3: {
		/*midSXchain(sIze100, 100);
		midSXchain(sIze50, 50);
		midSXchain(sIze10, 10);*/
		break;
	}case 4: {
		midSXopen(size100, 100);
		midSXopen(size50, 50);
		midSXopen(size10, 10);
		break;
	}
	}




	delete size100;
	delete size50;
	delete size10;
	system("pause");
	return 0;
}