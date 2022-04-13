#include <iostream>
#include <conio.h>
using namespace std;

void inputBanyakMatkul(int *matkul){
	cout << "Masukkan banyak matkul : ";
	cin >> *matkul;
}

void inputBanyakMhs(int *mhs){
	cout << "Masukkan banyak mahasiswa : ";
	cin >> *mhs;
}


int main(){
	int banyakMhs;
	int banyakMatkul;
	int i, j;
	float total = 0;
	float temp;
	int metode;
	int maks;
	
	inputBanyakMatkul(&banyakMatkul);
	
	cout << endl;
	
	float nilai[banyakMatkul];
	
	string matkul[banyakMatkul];
	for(i = 0; i < banyakMatkul; i++){
		cout << "Nama matkul : ";
		getline(cin >> ws, matkul[i]);
	}
	
	cout << endl;
	cout << endl;
	
	inputBanyakMhs(&banyakMhs);
	
	cout << endl;
	
	float IPK[banyakMhs];
	
	string namaMhs[banyakMhs];
	for(i = 0; i < banyakMhs; i++){
		cout << "Masukkan nama mahasiswa ke-" << i + 1 << " : ";
		getline(cin >> ws, namaMhs[i]);
	}
	
	cout << endl;
	
	for(i = 0; i < banyakMhs; i++){
		cout << endl;
		cout << "----------------------------------" << endl;
		cout << "Nilai matkul " << namaMhs[i] << endl;
		cout << endl;
		for(j = 0; j < banyakMatkul; j++){
			cout << "Masukkan nilai " << matkul[j] << " : ";
			cin >> nilai[j];
			total += nilai[j];
		}
		IPK[i] = total / banyakMatkul;
		total = 0;
	}
	
	cout << endl;
	cout << endl;
	
	for(i = 0; i < banyakMhs; i++){
	cout << "IPK " << namaMhs[i] << " : " << IPK[i] << endl;
	}
	
	cout << endl;
	cout << endl;
	
	ulangmetode:
	cout << "Metode sorting [1]Bubble sort, [2]Selection sort, [3]Insertion sort " << endl;
	cout << endl;
	cout << "Pilih metode sorting 1,2,3 : ";
	cin >> metode;
	
	if(metode == 1){
	//Bubble sort
	for(i = 0; i < (banyakMhs-1); i++){
		for(j = 0; j < (banyakMhs-1); j++){
			if(IPK[j] < IPK[j+1]){
				temp = IPK[j];
				IPK[j] = IPK[j+1];
				IPK[j+1] = temp;
			}
		}
	}
	}else if(metode == 2){
	//Selection sort
	for(i = 0; i < banyakMhs; i++){
		maks = i;
		for(j = i + 1; j < banyakMhs; j++){
			if(IPK[maks] < IPK[j])
				maks = j;
		}
		if(IPK[i] != IPK[maks]){
			temp = IPK[i];
			IPK[i] = IPK[maks];
			IPK[maks] = temp;
		}
	}
	}else if(metode == 3){
	//Insertion sort
	int j;
	for(i = 0; i < banyakMhs; i++){
		temp = IPK[i];
		j = i-1;
		while(IPK[j] < temp && j >= 0){
			IPK[j+1] = IPK[j];
			j--;
		}
		IPK[j+1] = temp;
	}
	} else {
		cout << "Pilih antara 1, 2 atau 3!" << endl;
		goto ulangmetode;
	}
	
	cout << endl;
	cout << "IPK setelah diurutkan" << endl;
	cout << "========================" << endl;
	cout << endl;
	for(i = 0; i < banyakMhs; i++){
	cout << IPK[i] << endl;	
	}
	
	getch();
	return 0;
}