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

//Default Constructor
sporKocu::sporKocu(){
	this->isim="default";
	this->soyisim="default";
	this->cinsiyet="default";
	this->yas=0;
	this->kilo=0;
	this->boy=0;
	this->kitle_endeksi=0;
	for(int i=0;i<5;i++)
		this->kiloAlmaEvde[i]="default";
	for(int i=0;i<5;i++)
		this->kiloAlmaSalonda[i]="default";
	for(int i=0;i<5;i++)
		this->kiloVermeEvde[i]="default";
	for(int i=0;i<5;i++)
		this->kiloVermeSalonda[i]="default";	
	for(int i=0;i<10;i++)
		this->muzikEnerjik[i]="default";
	for(int i=0;i<10;i++)
		this->muzikKarisik[i]="default";
	for(int i=0;i<10;i++)
		this->muzikSakin[i]="default";
}

//Constructor
sporKocu::sporKocu(string isim,string soyisim,string cinsiyet,int yas,double kilo,double boy){
	this->isim=isim;
	this->soyisim=soyisim;
	this->cinsiyet=cinsiyet;
	this->yas=yas;
	this->kilo=kilo;
	this->boy=boy;
}

//Destructor
sporKocu::~sporKocu(){
	cout<<"Hafiza Temizlendi..."<<endl;
}

//Kitle endeksi hesaplama fonksiyonu
double sporKocu::kitleEndeksiBul(double kilo, double boy) {
	this->kilo=kilo;
	this->boy=boy;
	this->kitle_endeksi=(kilo)/(boy*boy);
	return kitle_endeksi;
}

void sporKocu::hareketHafiza(string arr1[5],string arr2[5],string arr3[5],string arr4[5]){
	for(int i=0;i<5;i++){
		this->kiloAlmaEvde[i] = arr1[i];
		this->kiloAlmaSalonda[i] = arr2[i];
		this->kiloVermeEvde[i] = arr3[i];
	    this->kiloVermeSalonda[i ] = arr4[i];
	}
}

void sporKocu::muzikHafiza(string arr1[10],string arr2[10],string arr3[10]){
	for(int i=0;i<10;i++){
		this->muzikEnerjik[i] = arr1[i];
		this->muzikSakin[i] = arr2[i];
		this->muzikKarisik[i] = arr3[i];
	}
}

void sporKocu::besinHafiza(string arr1[5],string arr2[5],string arr3[5],string arr4[5],string arr5[5],string arr6[5]){
	for(int i=0;i<5;i++){
		this->besinKiloAlmaSabah[i] = arr1[i];
		this->besinKiloAlmaOgle[i] = arr2[i];
		this->besinKiloAlmaAksam[i] = arr3[i];
		this->besinKiloVermeSabah[i] = arr4[i];
		this->besinKiloVermeOgle[i] = arr5[i];
		this->besinKiloVermeAksam[i] = arr6[i];
	}
}
void sporKocu::tumBilgileriYazdir(){
	cout<<"Cinsiyetiniz : "<<this->cinsiyet<<endl;
	cout<<"Adiniz : "<<this->isim<<endl;
	cout<<"Soyadiniz : "<<this->soyisim<<endl;
	cout<<"Yasiniz : "<<this->yas<<endl;
	cout<<"Boyunuz : "<<this->boy<<endl;
	cout<<"Kilonuz : "<<this->kilo<<endl;
	cout<<"Vucut Kitle Endeksi : "<<this->kitle_endeksi<<endl;
}
void sporKocu::muzikleriYazdir(string arr1[10],string arr2[10],string arr3[10]){
	for(int i=0;i<10;i++){
		muzikEnerjik[i] = arr2[i];
		muzikKarisik[i] = arr3[i];
		muzikSakin[i]   = arr1[i];
	}
	int secim1,secim2;
	x:
	cout<<"Hangi Listedeki Muzikleri Gormek Istiyorsunuz Seciniz\n 1-Enerjik \n 2-Sakin \n 3-Karisik"<<endl;
	cout<<"Seciminiz :";
	cin>>secim1;  
    switch(secim1) {
    	case 1:
    	    cout<<"Enerjik Listesindeki Muzikler :"<<endl;
			for(int i=0;i<10;i++)
			cout<<i+1<<". Muzik : "<<muzikEnerjik[i]<<endl;
			break;
		case 2:
		  cout<<"Sakin Listesindeki Muzikler :"<<endl;
			for(int i=0;i<10;i++)
			cout<<i+1<<". Muzik : "<<muzikSakin[i]<<endl;
			break;
	    case 3:
	        cout<<"Karisik Listesindeki Muzikler :"<<endl;
			for(int i=0;i<10;i++)
			cout<<i+1<<". Muzik : "<<muzikKarisik[i]<<endl;
			break;
		default:
			cout<<"****Lutfen Gecerli bir secim yapiniz****"<<endl;
			goto x;
	}
	cout<<"\nTekrar bakmak ister misiniz ?\n 1-Evet \n 2-Hayir"<<endl;
	cout<<"Seciminiz :";
	cin>>secim2;
	if(secim2 == 1)
	goto x;
	else if(secim2 == 2)
	system("CLS");
}
	
void sporKocu::hareketleriYazdir(string arr1[5],string arr2[5],string arr3[5],string arr4[5]) {
	for(int i=0;i<5;i++){
	kiloAlmaEvde[i]    = arr1[i];
	kiloAlmaSalonda[i] = arr2[i];
	kiloVermeEvde[i]   = arr3[i];
	kiloVermeSalonda[i]= arr4 [i];
}
int secim1,secim2,secim3,secim4;
	t:
    cout<<"Hangi Amacla Yapilan Hareketleri Gormek Istiyorsunuz Seciniz\n1-Kilo Alma\t(NOT : Kilo almanin anlami vucuttaki kas oranini arttirmaktir)"<<endl;
	cout<<"2-Kilo Verme\t(NOT : Kilo vermenin anlami vucuttaki yag oranini azaltmaktir)"<<endl;
	cout<<"Seciminiz :";
	cin>>secim1;
	switch(secim1) {
		case 1:
			cout<<"Kilo alma hareketlerini sectiniz. Evde yapilan hareketleri mi gormek istersiniz yoksa spor salonunda yapilan hareketleri mi gormek istersiniz ?"<<endl;
			cout<<"1-Ev ortaminda yapilabilen spor hareketleri"<<endl;
			cout<<"2-Spor salonunda yapilabilen spor hareketleri"<<endl;
			y:
			cout<<"Seciminiz :";
			cin>>secim2;
			if(secim2 == 1) {
				cout<<"Kilo alma amaci ile ev ortaminda yapilabilen spor hareketleri :"<<endl;
				for(int i=0;i<5;i++){
					cout<<i+1<<". Hareket : "<<kiloAlmaEvde[i]<<endl;
				}
			}
			else if(secim2 == 2){
				cout<<"Kilo alma amaci ile spor salununda yapilabilen spor hareketleri :"<<endl;
				for(int i=0;i<5;i++){
					cout<<i+1<<". Hareket : "<<kiloAlmaSalonda[i]<<endl;
				}
			}
			else if(secim2 != 1 || secim2 != 2){
				cout<<"Lutfen gecerli bir sayi giriniz..."<<endl;
				goto y;
			}
			break;
		case 2:
			cout<<"Kilo verme hareketlerini sectiniz. Evde yapilan hareketleri mi gormek istersiniz yoksa spor salonunda yapilan hareketleri mi gormek istersiniz ?"<<endl;
			cout<<"1-Ev ortaminda yapilabilen spor hareketleri"<<endl;
			cout<<"2-Spor salonunda yapilabilen spor hareketleri"<<endl;
			z:
			cout<<"Seciminiz :";
			cin>>secim3;
			if(secim3 == 1){
				cout<<"Kilo verme amaci ile ev ortaminda yapilabilen spor hareketleri :"<<endl;
				for(int i=0;i<5;i++){
					cout<<i+1<<". Hareket : "<<kiloVermeEvde[i]<<endl;
				}				
			}
			else if(secim3 == 2){
				cout<<"Kilo verme amaci ile spor salonunda yapilabilen spor hareketleri :"<<endl;
				for(int i=0;i<5;i++){
					cout<<i+1<<". Hareket : "<<kiloVermeSalonda[i]<<endl;
				}
			}
			else if(secim3 != 1 || secim3 != 2) {
				cout<<"Lutfen gecerli bir sayi giriniz..."<<endl;
				goto z;
			}
			break;
		default:
			cout<<"****Lutfen Gecerli bir secim yapiniz****"<<endl;
			goto t;
	}
	cout<<"\nTekrar bakmak ister misiniz ?\n 1-Evet \n 2-Hayir"<<endl;
	cout<<"Seciminiz :";
	cin>>secim4;
	if(secim4 == 1)
	goto t;
	else if(secim2 == 2)
	system("CLS");
}

void sporKocu::hareketYapilisiYazdir(){
	setlocale(LC_ALL,"Turkish");
	cout<<"\t\t***KILO ALMAK ICIN EVDEKI SPOR HAREKETLERI YAPILISI***"<<endl;
	cout<<"---PUSH UP (SINAV) : ��nav egzersizi spor yapan her insan�n yapabilmesi gereken hareketlerden biridir.\n"
	                    "Y�z�st� yere yat�n. Ayaklar�n�z� uzatarak parmak u�lar�n�z� yere sabitleyin ve\n"
	                    "ellerinizi de g�g�s�n hemen yan�nda yere sabitleyin. T�m v�cudunuzu yerden kald�r�n.\n"
					    "V�cudunuz topuktan ba�a kadar gergin ve tek bir �izgi �zerinde olmal�. Beliniz de\n" 
					    "kesinlikle hiper lordoz(i�e do�ru �ukur gibi d���nebilirsiniz) olmamal�.\n"
						"Dirsekler 90 derecelik bir a��ya ula��ncaya kadar g�vdeyi yere indirin. Daha fazla\n"
						"diren� i�in dirseklerinizi v�cudunuza yak�n tutun. Ba��n� a�a��ya do�ru b�rakma ve yere\n"
						"bakmaya �zen g�ster. V�cudunuzu d�z �izgi �zerin de tutun, kalcan�z� d���rmeyin ve\n"
						"kalcanizin havada as�l� kalmas�na izin vermeyin. V�cudunuzu m�mk�n oldu�unca d�z tutmak\n"
						"�nemlidir. Kendini indirirken nefes almay� unutma.\n"<<endl;
	cout<<"---SQUAT : Squat hareketi ayakta ba�lar. Ayaklar omuz hizas�nda a��kt�r. Eller �nce iki yanda durur,\n" 
                      "yere ��melirken resimdeki gibi birle�ir. Ba��n dik ve bak��lar�n ileri do�ru olmal�.\n" 
					  "G��s�n� yukar�da tut. Ayaktayken nefes al�p, ��melirken verebilirsin. Tersini de deneyebilirsin.\n" 
					  "Kendin i�in en uygun nefesi ke�fet. Belini d�z tutmak i�in enerji harcama, do�al k�vr�m�nda kals�n.\n" 
					  "Kendi g�c�ne g�re kal�a ve basenler yere paralel veya inebildi�in kadar a�a��da olabilir.\n" 
					  "Topuklar�n�n �zerine oturmadan tabii. Dizlerin ayak u�lar�n�n �n�ne ge�memesi hareketin genel b�t�nl���\n"
					  "a��s�ndan �nemli. Ayak tabanlar�n yere d�z bass�n, a��rl���n� topuklar�na ver. Biraz daha zorla�s�n\n"
					  "istersen ayak parmaklar�n� kald�rmay� dene.\n"<<endl;
	cout<<"---PULL UP (BARFIKS) : Bir Pullup bar'� omuz geni�li�inden biraz daha geni� bir �ekilde overhand grip\n" 
	                             "ile kavray�n. Ba�larken kollar�n�z�n d�md�z olmas�na ve ayaklar�n�z�n yere de�memesine\n"
								 "dikkat edin. Bu ba�lang�� pozisyonunuzdur. �eneniz bar'� ge�ene kadar kendinizi yukar�\n" 
								 "�ekin. Dirseklerinizden �ekerek s�rt�n�z� s�kt���n�zdan emin olun. Ayn� zamanda\n" 
								 "ba��n�z dik ve g�zleriniz ileri baks�n. En tepede 1 saniye durduktan sonra kendinizi\n" 
								 "yava��a geri ba�lang�� pozisyonuna do�ru indirin.\n"<<endl;
	cout<<"---DIPS : Avu� i�lerinizi herhangi bir banka ya da �zel spor masas�na dayamak suretiyle ayaklar�n�z� uzat�n.\n" 
	                 "Daha sonra derin nefes alarak sonra vermek suretiyle yukar� do�ru kendinizi ittirin. Ayn� �ekilde\n" 
					 "yine a�a�� do�ru orta h�zda inin. Di�er harekette triceps b�lgesi i�in belinize a��rl�k takmak\n" 
					 "suretiyle �al��ma yapabilirsiniz.  �ki taraf�n�zda duran bar k�s�mlar�n� tutmak suretiyle kendinizi\n" 
					 "yukar� ve a�a�� do�ru hareket ettirerek bu i�lemi ger�ekle�tirebilirsiniz.\n"<<endl;
	cout<<"---HIP BR�DGE (KOPRU) : Ba�lang��ta  V�cudun ba�, s�rt ve kal�a b�lgeleri yerde olmal�.\n" 
	                               "�ki aya��n�z�da dizler b�k�l� yere koyun. Sonras�nda s�rt�n�z yerde\n"
								   "olacak �ekilde, ayak tabanlarinizdan destek alarak kal�an�z� yukar�\n" 
								   "kald�r�n ve ba�lang�� pozisyonuna geri d�n�n.\n"<<endl;
	cout<<"\t\t***KILO ALMAK ICIN SALONDAKI SPOR HAREKETLERI YAPILISI***"<<endl;
	cout<<"---FRONT SQUAT : squat sehpas�nda bar� �n omuzunuza gelecek �ekilde oturtun her iki elinizle\n" 
	                        "bar� v�cudunuza sabitleyin. Ayaklar�n�z� omuz geni�li�iniz kadar a��n. Parmak\n"
							"u�lar�n�z kar��ya bakmal�. Nefes alarak ��melmeye ba�lay�n. �st baca��n�z\n" 
							"(diz ve kal�a aras�) yere paralel oluncaya kadar ��melin. (Bknz: ilk resim sa�)\n" 
							"��melme an�n� yava� yaparsan�z hamstrings yani arka bacak kaslar� daha etkin �ekilde\n" 
							"�al��acakt�r. H�zl� yaparsan�z bir geli�me sa�layamazs�n�z. Son noktaya geldi�iniz de\n"
							"nefes vererek orta h�zda kontroll� bir �ekilde y�kselmeye ba�lay�n. Tepe noktaya\n" 
							"geldi�inizde bekleme yapmadan nefes alarak tekrar ini�e ge�in. Tekrar say�s� kadar\n" 
							"yap�p setinizi tamamlay�n. Bu egzersiz i�in 4 set 10 tekrar uygun olacakt�r.\n" 
							"Front squat yaparken �ne do�ru e�ilmemelisiniz. S�rt�n�z� daima dik tutmal�s�n�z.\n"
							"Dengenizi daha stabil hale getirmek ve daha �ok �n bacak  adalelerini �al��t�rmak i�in\n" 
							"topuklar�n�z�n alt�na bir takoz koyabilirsiniz.\n"<<endl;
	cout<<"---DEADLIFT : Kald�rabilece�iniz a��rl�klar� takt�ktan sonra barbell'i ayaklar�n�z�n dibine kadar getirmelisiniz.\n" 
	                     "Daha sonra ayaklar�n�z� omuz hizas�nda a�arak parmak u�lar�n�z kar��ya bakmal�d�r. Barbell m�mk�n\n"  
						 "oldu�u kadar kaval kemi�ine de�ecek noktaya yak�n olmas� �nemlidir.Bu �ekilde bacaklar�n�z� diz\n"  
						 "kapaklar�ndan hafif�e k�rarak e�ilmeniz gerekiyor.E�ilirken v�cudunuz m�mk�n oldu�u kadar dik olmal�d�r.\n"  
						 "Daha sonra dirseklerinizi k�rmadan Barbell'li kavramam�z gerekir. Kollar�n�z omuz hizas�nda a��k �ekilde\n"  
						 "olmal�d�r. Ard�ndan derin bir nefes almak suretiyle orta h�zda barbell'i nefes vermek suretiyle kald�r�n.\n"  
						 "Son noktaya ula�t���n� zaman v�cudunuz dik bir pozisyonda olmal�d�r. Ard�ndan yeniden nefes almak suretiyle\n"  
						 "verirken a��rl��� yere b�rak�n.\n"<<endl;
	cout<<"---INCLINE BENCHPRESS : Hareketi yapmak i�in 45-60 derecelik incline sehpaya s�rt �st� uzan�n. Ayaklar�n�z yere tam bass�n\n"
	                               "ve parmak u�lar�n�z kar��ya baks�n. Eller aras� mesafe ayar� i�in iki y�ntem vard�r. Birincisi bar�n\n" 
								   "�st�ndeki �izgileri kullanmakt�r. Ki�inin omuz geni�li�ine g�re bir ka� santim i�eriden ya da bir ka�\n" 
								   "santim d��ar�dan tutulabilir. �kinci y�ntem ise �st kollar�n (dirsek - el aras�) yere tam dik olmas�d�r.\n" 
								   "Bu iki y�ntem sayesinde d�zg�n formu yapm�� olursunuz. Do�ru �ekilde konumland�ktan sonra, nefes alarak\n" 
								   "bar� g���se (g���s u�lar� hizas�na) do�ru yava��a indirin.Yava��a indirmek triceps kaslar�n�n da etkin\n" 
								   "�ekilde �al��mas�n� sa�lar. Bar�n g���se de�mesine bir santim kala, nefes vererek t�m g�c�n�zle bar� yukar�\n" 
								   "do�ru itin. Tepe noktaya ula�t���n�zda beklemeden, nefes alarak bar� tekrar g���s u�lar�n�za do�ru indirin.\n" 
								   "Tekrar say�s� kadar yap�p setinizi tamamlay�n. Bu egzersiz i�in 4 set 10 tekrar uygun olacakt�r.\n"<<endl;
	cout<<"---ARNOLD BENCHPRESS : Arkas� ayarlanabilir bench sehpahas�n� dik konuma getirip, s�rt�n�z� iyice yaslayarak oturun. Ayaklar�n�z\n"  
	                              "a��k ve kar��ya bakar konumda olursa y�ksek a��rl�klarda dengenizi sa�laman�za yard�mc� olur.�stten tutu�la\n"  
								  "her iki elinize birer dumbbell al�n. �st kollar�n�z birbirine paralel, yere dik ve avu� i�leriniz v�cudunuza\n"  
								  "bakar �ekilde olmal�. Nefes al�n ve ard�ndan nefes vererek, fleksiyon yaparak yani avu� i�lerinizi d��ar�\n"  
								  "do�ru �evirerek , dumbbell'lar� yukar� birbirlerine de�mesine bir ka� santim mesafe kalana kadar kald�r�n.\n"  
								  "Tepe noktas�nda 0,5-1 saniye kadar bekledikten sonra, nefes alarak, kald�r�� h�z�n�za oranla daha d���k bir\n"  
								  "h�zda yine fleksiyon yaparak yani avu� i�lerinizi v�cudunuza �evirerek dumbell'lar� a�a�� indirip ba�lang��\n"  
								  "pozisyonunuza gelin. Tekrar say�s� kadar yap�p setinizi tamamlay�n. Bu egzersiz i�in 4 set 10 tekrar uygun olacakt�r.\n"<<endl;
   cout<<"---CABLE BICEP CURL : Makinenin �n�nde durup �ok a��r olmayan bir kilo tak�n. Uygun bir a��rl�k se�in ve kollar�n�z� a�a�� sark�t�p ba�lang��\n" 
                                "pozisyonunuza ge�in. Elleriniz aras�ndaki bo�luk omuz geni�li�iniz kadar olsun. Bu �ekilde biceps long ve short head e�it\n" 
								"�al���r. Ayak duru�unu da iki �ekilde yapabilirsiniz. Ayaklar yan yana olursa; daha fazla y�ke girebilirsiniz ama bel\n" 
								"problemi varsa zorlanabilir. Ayaklardan biri �nde biri arkada olursa; bel korunur fakat kald�raca��n�z a��rl�k miktar�\n" 
								"azal�r. Her ikisini de deneyip karar�n�z� verin. Nefes al�n ve ard�ndan nefesinizi vererek 1 - 1,5 saniye aral���nda bar�\n" 
								"�enenize de�mesine bir ka� santim kalana kadar �ekin. Tepe noktada 1 saniye kadar bekleyin ve ard�ndan nefes alarak 1,5 - 2\n" 
								"saniye aral���nda bar� salarak kollar�n�z� tamamen a��n. Kolu tamamen a�mak ve maksimum kapatmak bu harekette olduk�a �nemli.\n" 
								"Kas �eki� an�nda son noktaya kadar k�sal�p, sal�� an�nda ise sonuna kadar uzamal�. �eki� an�nda v�cudunuzu sallay�p momentum\n" 
								"kazanmay�n. M�mk�n mertebe sadece �n kollar�n�z hareket etsin. Tekrar say�s� kadar yap�p setinizi tamamlay�n. 4 set 10 tekrar\n"
								 "ve ek olarak pump ama�l� d���k a��rl�kl� 1 set maksimum tekrar yap�labilir.\n"<<endl;
}

void sporKocu::muzikOneri(int secim){
	if(secim==1){
		cout<<"Sizin icin hazirlanan oneri muzik listemiz :"<<endl;
		for(int i=0;i<10;i++)
		cout<<i+1<<" . Muzik : "<<this->muzikEnerjik[i]<<endl;
	}
	else if(secim==2){
		cout<<"Sizin icin hazirlanan oneri muzik listemiz :"<<endl;
		for(int i=0;i<10;i++)
		cout<<i+1<<" . Muzik : "<<this->muzikSakin[i]<<endl;
	}
	else if(secim==3){
		cout<<"Sizin icin hazirlanan oneri muzik listemiz :"<<endl;
		for(int i=0;i<10;i++)
		cout<<i+1<<" . Muzik : "<<this->muzikKarisik[i]<<endl;
	}	
}

void sporKocu::besinOneri(int secim){
	if(secim==1) {
		cout<<"Sizin icin hazirlanan oneri diyet listemiz :"<<endl;
		cout<<"---SABAH---"<<endl;
		for(int i=0;i<5;i++){
			cout<<i+1<<" . Besin : "<<this->besinKiloVermeSabah[i]<<endl;
		}
		cout<<"---OGLE---"<<endl;
		for(int i=0;i<5;i++){
			cout<<i+1<<" . Besin : "<<this->besinKiloVermeOgle[i]<<endl;
		}
		cout<<"---AKSAM---"<<endl;
		for(int i=0;i<5;i++){
			cout<<i+1<<" . Besin : "<<this->besinKiloVermeAksam[i]<<endl;
		}	
	}
	else if(secim==2) {
		cout<<"Sizin icin hazirlanan oneri diyet listemiz :"<<endl;
		cout<<"---SABAH---"<<endl;
		for(int i=0;i<5;i++){
			cout<<i+1<<" . Besin : "<<this->besinKiloAlmaSabah[i]<<endl;
		}
		cout<<"---OGLE---"<<endl;
		for(int i=0;i<5;i++){
			cout<<i+1<<" . Besin : "<<this->besinKiloAlmaOgle[i]<<endl;
		}
		cout<<"---AKSAM---"<<endl;
		for(int i=0;i<5;i++){
			cout<<i+1<<" . Besin : "<<this->besinKiloAlmaAksam[i]<<endl;
		}
	}
}

void sporKocu::hareketOneri(int secim,int secim2){
	if(secim==1 && secim2==1){
		cout<<"Sizin icin hazirlanan oneri spor hareketleri listemiz :"<<endl;
		for(int i=0;i<5;i++)
		cout<<i+1<<" . Hareket : "<<this->kiloVermeEvde[i]<<endl;
	}
	else if(secim==1 && secim2==2){
		cout<<"Sizin icin hazirlanan oneri spor hareketleri listemiz :"<<endl;
		for(int i=0;i<5;i++)
		cout<<i+1<<" . Hareket : "<<this->kiloVermeSalonda[i]<<endl;
	}
	else if(secim==2 && secim2==1){
		cout<<"Sizin icin hazirlanan oneri spor hareketleri listemiz :"<<endl;
		for(int i=0;i<5;i++)
		cout<<i+1<<" . Hareket : "<<this->kiloAlmaEvde[i]<<endl;
	}
	else if(secim==2 && secim2==2){
		cout<<"Sizin icin hazirlanan oneri spor hareketleri listemiz :"<<endl;
		for(int i=0;i<5;i++)
		cout<<i+1<<" . Hareket : "<<this->kiloAlmaSalonda[i]<<endl;
	}
}

void sporKocu::besinleriYazdir(){
	cout<<"***KILO VERME DIYET LISTESI***"<<endl;
	cout<<"---SABAH---"<<endl;
		for(int i=0;i<5;i++){
			cout<<i+1<<" . Besin : "<<this->besinKiloVermeSabah[i]<<endl;
		}
		cout<<"---OGLE---"<<endl;
		for(int i=0;i<5;i++){
			cout<<i+1<<" . Besin : "<<this->besinKiloVermeOgle[i]<<endl;
		}
		cout<<"---AKSAM---"<<endl;
		for(int i=0;i<5;i++){
			cout<<i+1<<" . Besin : "<<this->besinKiloVermeAksam[i]<<endl;
		}	
		cout<<"***KILO ALMA DIYET LISTESI***"<<endl;
		cout<<"---SABAH---"<<endl;
		for(int i=0;i<5;i++){
			cout<<i+1<<" . Besin : "<<this->besinKiloAlmaSabah[i]<<endl;
		}
		cout<<"---OGLE---"<<endl;
		for(int i=0;i<5;i++){
			cout<<i+1<<" . Besin : "<<this->besinKiloAlmaOgle[i]<<endl;
		}
		cout<<"---AKSAM---"<<endl;
		for(int i=0;i<5;i++){
			cout<<i+1<<" . Besin : "<<this->besinKiloAlmaAksam[i]<<endl;
		}
}

