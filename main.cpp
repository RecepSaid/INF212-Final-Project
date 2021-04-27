/* INF 212 - 2020 Bahar Donemi
   Proje-4
   Proje Adi : Spor Kocu Pragrami
   Proje Amaci: Kullanicidan alinan verilere gore diyet listesi ve spor programi hazirlayan program
   Recep Said Dulger/171024045                     
*/
#include "sporKocu.h"
#include <iostream>
#include <string.h>

using namespace std;

int main () {
	string muzikSakin[10] =  {"Marconi Union - Weightless","Airstream - Electra","DJ Shah - Mellomaniac","Enya - Watermark","Coldplay - Strawberry Swing","Barcelona - Please Don't Go","All Saints - Pure Shores","Adele - Someone Like You","Mozart - Canzonetta Sull'aria","Cafe Del Mar - We Can Fly"};
	string muzikEnerjik[10] =  {"Eminem - Venom","Kanye West - Stronger","Eminem - Lose Yourself","Macklemore - Can't Hold Us","Bon Jovi - It's My Life","Green Day - St. Jimmy","OneRepublic - Love Runs Out","Metallica - Seek and Destroy","Survivor - Eye of The Tiger","Kongos - Come With Me Now"};
	string muzikKarisik[10] =  {"Airstream - Electra","Eminem - Lose Yourself","Enya - Watermark","Coldplay - Strawberry Swing","Bon Jovi - It's My Life","Green Day - St. Jimmy","Barcelona - Please Don't Go","Metallica - Seek and Destroy","All Saints - Pure Shores","Kongos - Come With Me Now"};
    string kiloAlmaEvde [5] = {"Push Up(Sinav)","Squat","Pull Up(Barfiks)","Dips","Hip Bridge(Kopru)"};
	string kiloAlmaSalonda [5] = {"Front Squat","Deadlift","Incline Benchpress","Arnold Press","Cable Bicep Curl"};
	string kiloVermeEvde [5] = {"Jog(Kosu)","Butt Kick","Knee Up","Crunch","Jumping Jack"};
	string kiloVermeSalonda [5] = {"Bench Press","Deadlift","Ham Curl","Angled Side Raise","Cable Pull"};
	string besinKiloAlmaSabah[5] = {"3 Yumurta","Bir Dilim Keci Peyniri","1 Bardak Sekersiz Cay","8 Zeytin","1 Dilim Ekmek"};
	string besinKiloAlmaOgle[5] = {"1 Kase Corba","Izgara Tavuk veya Balik","Yarim Tabak Buharda Pismis Sebze","1 Bardak Meyve Suyu","1 Dilim Ekmek"};
	string besinKiloAlmaAksam[5] = {"1 Adet Mevsim Meyvesi","Pismis Tavuk Gogsu","1 Tabak Mevsim Salata","1 Tabak Bulgur Pilavi","15 Badem veya 4 Tam Ceviz"};
	string besinKiloVermeSabah[5] = {"2 Yumurta","Yarim Dilim Beyaz Peynir","Yarim Tabak Yesillik","5 Zeytin","1 Yemek Kasigi Bal"};
	string besinKiloVermeOgle[5] = {"1 Tabak Haslanmis Sebze Yemegi","150 Gr. Ton Baligi","1 Adet Mevsim Meyvesi","Mevsim Salata","1 Dilim Ekmek"};
	string besinKiloVermeAksam[5] = {"1 Tabak Kurubaklagil","1 Tabak Bulgur Pilavi","Mevsim Salata","1 Kase Yogurt","1 Bardak Meyve Suyu"};
	int secim1,secim3,secim4,secim5;
	char secim2,secim6;
	string isim,soyisim,cinsiyet;
	int yas;
	double boy,kilo,kitle_endeksi;
	sporKocu sporcu1;
	x:
	try {   //Exception Handlings
	cout<<"******Spor Kocu Programina Hosgeldiniz*******"<<endl;
	cout<<"Oncelikle size uygun spor hareketleri, diyet listesi, muzik önerisi sunabilmemiz icin bilgilerinizi giriniz :"<<endl;
	cout<<"Cinsiyetiniz (Erkek/Kadin) : ";
	cin>>cinsiyet;
	if(cinsiyet != "Erkek" && cinsiyet != "erkek" && cinsiyet != "Kadin" && cinsiyet != "kadin" ) //Operator Overloading 
	throw cinsiyet;
	cout<<"Adinizi Giriniz : ";
	cin>>isim;
	cout<<"Soyadinizi Giriniz : ";
	cin>>soyisim;
	cout<<"Yasinizi Giriniz : ";
	cin>>yas;
	if(yas<0)
	throw yas;
	cout<<"Boyunuzu Giriniz : ";
	cin>>boy;
	if(boy<0)
	throw boy;
	cout<<"Kilonuzu Giriniz : ";
	cin>>kilo;
	if(kilo<0)
	throw kilo;
	}
	catch(string s){
		cout<<"Cinsiyeti yanlis girdiniz lutfen tekrar deneyiniz..."<<endl;
		cout<<"Bilgilerinizi en bastan dikkatlice giriniz  !"<<endl;
		goto x;
	}
	catch(int x){
		cout<<"Yas sifirdan kucuk olamaz lutfen tekrar giriniz..."<<endl;
		cout<<"Bilgilerinizi en bastan dikkatlice giriniz  !"<<endl;
		goto x;
	}
	catch(double d) {
		cout<<"Boy ve kilo degerleri sifirdan kucuk olamaz lutfen tekrar giriniz..."<<endl;
		cout<<"Bilgilerinizi en bastan dikkatlice giriniz  !"<<endl;
		goto x;
	}

	sporKocu(isim,soyisim,cinsiyet,yas,kilo,boy);
	sporcu1.besinHafiza(besinKiloAlmaSabah,besinKiloAlmaOgle,besinKiloAlmaAksam,besinKiloVermeSabah,besinKiloVermeOgle,besinKiloVermeAksam);
	sporcu1.hareketHafiza(kiloAlmaEvde,kiloAlmaSalonda,kiloVermeEvde,kiloVermeSalonda);
	sporcu1.muzikHafiza(muzikEnerjik,muzikSakin,muzikKarisik);
	kitle_endeksi=sporcu1.kitleEndeksiBul(kilo,boy);
	
	cout<<"Girdiginiz bilgiler icin tesekkurler sayin "<<isim<<" "<<soyisim<<endl;
	cout<<"Girdiginiz bilgiler sonucunda vucut kitle endeksiniz "<<kitle_endeksi<<" olarak hesaplanmistir"<<endl;
	if(kitle_endeksi>=0 && kitle_endeksi<18.5)
		cout<<"Bu degere gore zayif sinifina girmektesiniz"<<endl;
	else if(kitle_endeksi>=18.5 && kitle_endeksi<24.9)
		cout<<"Bu degere gore normal kilolu sinifina girmektesiniz"<<endl;
	else if(kitle_endeksi>=24.9 && kitle_endeksi<29.9)
		cout<<"Bu degere gore fazla kilolu sinifina girmektesiniz"<<endl;
	else if(kitle_endeksi>=29.9 && kitle_endeksi<34.9)
		cout<<"Bu degere gore 1.derece obez sinifina girmektesiniz"<<endl;
	else if(kitle_endeksi>=34.9 && kitle_endeksi<39.9)
		cout<<"Bu degere gore 2.derece obez sinifina girmektesiniz"<<endl;
	else if(kitle_endeksi>=39.9 && kitle_endeksi<=40)
		cout<<"Bu degere gore 3.derece obez sinifina girmektesiniz"<<endl;
	
	cout<<"Bu bilgilere dayanarak spor yapma amacinizi secmeniz gerekmektedir. Bu secimize gore size uygun bir program hazirlanacaktir."<<endl;
	cout<<"Spora baslama amaciniz : \n1-Kilo Vermek (Vucuttaki yag oranini azaltirken kas oranini korumak)"<<endl;
	cout<<"2-Kilo Almak (Saglikli bir sekilde vucuttaki kas hacmini arttirmak)\nSeciminiz :";
	cin>>secim3;
	cout<<"Son olarak size uygun bir spor pragrami hazirlamamiz icin evde mi spor yapacaginizi\n"
		  "yoksa spor salonunda mi sapor yapacaginizi seciniz\n1-Evde\n2-Spor Salonunda\nSeciminiz :";
	cin>>secim4;
	cout<<"Ayrica size muzik onerisi yapmamiz icin spor esnasinda ne tur muzik dinlediginizi giriniz\n1-Enerjik\n2-Sakin\n3-Karisik\nSeciminiz :";
	cin>>secim5;
	system("CLS");
	sporcu1.besinOneri(secim3);
	cout<<"\n";
	sporcu1.hareketOneri(secim3,secim4);
	cout<<"\n";
	sporcu1.muzikOneri(secim5);
	cout<<"\n";
	cout<<"Ana Menuye gitmek ister misiniz ? (E/H)"<<endl;
	cout<<"Seciminiz :";
	cin>>secim6;
	if(secim6=='e' || secim6=='E')
	goto y;
	else if(secim6=='h' || secim6=='H')
	return 0;
	y:
	system("CLS");
	cout<<"******Spor Kocu Programi Menusune Hosgeldiniz*******"<<endl;
	cout<<"Ne yapmak istersiniz, menuden seciniz"<<endl;
	cout<<"\t-=-MENU-=-"<<endl;
	cout<<"\t1-Kayitli Tum Muziklere Bak"<<endl;
	cout<<"\t2-Kayitli Tum Spor Hareketlerine Bak"<<endl;
	cout<<"\t3-Kayitli Tum Spor Hareketleri Yapilislarina Bak"<<endl;
	cout<<"\t4-Kayitli Tum Besinlere Bak"<<endl;
	cout<<"\t5-Girdiginiz Bilgilerinizi Gorun"<<endl;
	cout<<"\t6-Sizin Icin Hazirladigimiz Programi Gorun"<<endl;
	cout<<"Seciminiz :";
	cin>>secim1;
	switch(secim1){
		case 1:
			sporcu1.muzikleriYazdir(muzikSakin,muzikEnerjik,muzikKarisik);
			break;
		case 2:
			sporcu1.hareketleriYazdir(kiloAlmaEvde,kiloAlmaSalonda,kiloVermeEvde,kiloVermeSalonda);
			break;
		case 3:
			sporcu1.hareketYapilisiYazdir();
			break;
		case 4:
			sporcu1.besinleriYazdir();
			break;
		case 5:
			sporcu1.tumBilgileriYazdir();
			break;
		case 6:
			sporcu1.besinOneri(secim3);
		 	sporcu1.hareketOneri(secim3,secim4);
			sporcu1.muzikOneri(secim5);
		default :
			cout<<"Lutfen gecerli bir secim yapiniz..."<<endl;
			goto y;
			break;
	}
	z:
	cout<<"Ana Menuye Donmek Ister Misiniz ? \nEVET (E)\nHAYIR (H)"<<endl;
	cout<<"Seciminiz :";
	cin>>secim2;
	if(secim2 == 'e' || secim2 == 'E') {
		system("CLS");
		goto y;
	}
	else if(secim2 == 'h' || secim2 == 'H')
		system("CLS");
	else if(secim2 != 'e' || secim2 != 'E' || secim2 != 'h' || secim2 != 'H'){
		cout<<"Lutfen gecerli bir harf giriniz ! (E,e,H,h gibi...)";
		goto z;
	}
	return 0;
}
