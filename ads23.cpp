#include <iostream>
#include <math.h>
#define PI 3.1415

using namespace std;

int faktorial(int);
double cosMaclaurin(double, int);
double fPangkat(double, int);


int main(){
	double derajat_sudut;
	int akurasi;
	
	cout << "Masukkan besar derajat sudut cosinus : ";
	cin >> derajat_sudut;
	derajat_sudut *= PI / 180;
	
	cout << "Masukkan akurasi derajat maclaurin : ";
	cin >> akurasi;
	
	cout << "\ncos(" << derajat_sudut/PI*180 << ")" << endl;
	cout << "Hasil menggunakan deret maclaurin = " << cosMaclaurin(derajat_sudut, akurasi) << endl;
	cout << "Hasil menggunakan function library = " << cos(derajat_sudut) << endl;
}

double cosMaclaurin(double angle, int acc){
	//Deret Taylor cos :
	//1 - x^2/2! + x^4/4! - x^6/6! .. dst
	
	double temp = 1;
	double jawaban = 1;
	int tanda = 1;
	
	for(int i = 1; i <= 2*acc; i += 2){
		tanda *= -1;
		temp = fPangkat(angle, i+1) / faktorial(i+1);
		if(tanda == -1){
			jawaban -= temp;
		}else{
			jawaban += temp;
		}
	}
	
	return jawaban;
}

int faktorial(int x){
	int hasil = 1;
	
	for(int i = x; i >= 1; i--){
		hasil *= i;
	}
	
	return hasil;
}

double fPangkat(double x, int pangkat){
	double hasil = 1;
	
	for(int i = 0; i < pangkat; i++){
		hasil *= x;
	}
	
	return hasil;
}
