/* INF 212 - 2020 Bahar Donemi
   Proje-4 
   Proje Adi : Spor Kocu Pragrami
   Proje Amaci: Kullanicidan alinan verilere gore diyet listesi ve spor programi hazirlayan program
   Recep Said Dulger/171024045
*/
#include <iostream>
#include <string.h>
#ifndef SPORKOCU_H_
#define SPORKOCU_H_

using namespace std;

class sporKocu {
		private:
	        string isim, soyisim,cinsiyet;
			int yas;
			double kilo,boy,kitle_endeksi;
			string kiloAlmaEvde[5];
			string kiloAlmaSalonda[5]; 
			string kiloVermeEvde[5]; 
			string kiloVermeSalonda[5]; 
			string muzikEnerjik[10];
			string muzikKarisik[10];
			string muzikSakin[10];
			string besinKiloAlmaSabah[5];
			string besinKiloAlmaOgle[5];
			string besinKiloAlmaAksam[5];
			string besinKiloVermeSabah[5];
			string besinKiloVermeOgle[5];
			string besinKiloVermeAksam[5];
			public:
			sporKocu (); //default constructor
			sporKocu (string isim,string soyisim,string cinsiyet,int yas,double kilo,double boy); //constructor
			~sporKocu(); //destructor
			double kitleEndeksiBul (double kilo, double boy);
			void tumBilgileriYazdir();
			void hareketHafiza(string arr1[5],string arr2[5],string arr3[5],string arr4[5]);
			void muzikHafiza(string arr1[10],string arr2[10],string arr3[10]);
			void besinHafiza(string arr1[5],string arr2[5],string arr3[5],string arr4[5],string arr5[5],string arr6[5]);
			void hareketleriYazdir (string arr1[5],string arr2[5],string arr3[5],string arr4[5]);    
			void hareketYapilisiYazdir();
			void besinleriYazdir ();  
			void muzikleriYazdir (string arr1[10],string arr2[10],string arr3[10]);     
			void muzikOneri(int secim);
			void hareketOneri(int secim,int secim2);
			void besinOneri(int secim);   
	};
#endif
