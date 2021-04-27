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
	cout<<"---PUSH UP (SINAV) : Þýnav egzersizi spor yapan her insanýn yapabilmesi gereken hareketlerden biridir.\n"
	                    "Yüzüstü yere yatýn. Ayaklarýnýzý uzatarak parmak uçlarýnýzý yere sabitleyin ve\n"
	                    "ellerinizi de gögüsün hemen yanýnda yere sabitleyin. Tüm vücudunuzu yerden kaldýrýn.\n"
					    "Vücudunuz topuktan baþa kadar gergin ve tek bir çizgi üzerinde olmalý. Beliniz de\n" 
					    "kesinlikle hiper lordoz(içe doðru çukur gibi düþünebilirsiniz) olmamalý.\n"
						"Dirsekler 90 derecelik bir açýya ulaþýncaya kadar gövdeyi yere indirin. Daha fazla\n"
						"direnç için dirseklerinizi vücudunuza yakýn tutun. Baþýný aþaðýya doðru býrakma ve yere\n"
						"bakmaya özen göster. Vücudunuzu düz çizgi üzerin de tutun, kalcanýzý düþürmeyin ve\n"
						"kalcanizin havada asýlý kalmasýna izin vermeyin. Vücudunuzu mümkün olduðunca düz tutmak\n"
						"önemlidir. Kendini indirirken nefes almayý unutma.\n"<<endl;
	cout<<"---SQUAT : Squat hareketi ayakta baþlar. Ayaklar omuz hizasýnda açýktýr. Eller önce iki yanda durur,\n" 
                      "yere çömelirken resimdeki gibi birleþir. Baþýn dik ve bakýþlarýn ileri doðru olmalý.\n" 
					  "Göðsünü yukarýda tut. Ayaktayken nefes alýp, çömelirken verebilirsin. Tersini de deneyebilirsin.\n" 
					  "Kendin için en uygun nefesi keþfet. Belini düz tutmak için enerji harcama, doðal kývrýmýnda kalsýn.\n" 
					  "Kendi gücüne göre kalça ve basenler yere paralel veya inebildiðin kadar aþaðýda olabilir.\n" 
					  "Topuklarýnýn üzerine oturmadan tabii. Dizlerin ayak uçlarýnýn önüne geçmemesi hareketin genel bütünlüðü\n"
					  "açýsýndan önemli. Ayak tabanlarýn yere düz bassýn, aðýrlýðýný topuklarýna ver. Biraz daha zorlaþsýn\n"
					  "istersen ayak parmaklarýný kaldýrmayý dene.\n"<<endl;
	cout<<"---PULL UP (BARFIKS) : Bir Pullup bar'ý omuz geniþliðinden biraz daha geniþ bir þekilde overhand grip\n" 
	                             "ile kavrayýn. Baþlarken kollarýnýzýn dümdüz olmasýna ve ayaklarýnýzýn yere deðmemesine\n"
								 "dikkat edin. Bu baþlangýç pozisyonunuzdur. Çeneniz bar'ý geçene kadar kendinizi yukarý\n" 
								 "çekin. Dirseklerinizden çekerek sýrtýnýzý sýktýðýnýzdan emin olun. Ayný zamanda\n" 
								 "baþýnýz dik ve gözleriniz ileri baksýn. En tepede 1 saniye durduktan sonra kendinizi\n" 
								 "yavaþça geri baþlangýç pozisyonuna doðru indirin.\n"<<endl;
	cout<<"---DIPS : Avuç iþlerinizi herhangi bir banka ya da özel spor masasýna dayamak suretiyle ayaklarýnýzý uzatýn.\n" 
	                 "Daha sonra derin nefes alarak sonra vermek suretiyle yukarý doðru kendinizi ittirin. Ayný þekilde\n" 
					 "yine aþaðý doðru orta hýzda inin. Diðer harekette triceps bölgesi için belinize aðýrlýk takmak\n" 
					 "suretiyle çalýþma yapabilirsiniz.  Ýki tarafýnýzda duran bar kýsýmlarýný tutmak suretiyle kendinizi\n" 
					 "yukarý ve aþaðý doðru hareket ettirerek bu iþlemi gerçekleþtirebilirsiniz.\n"<<endl;
	cout<<"---HIP BRÝDGE (KOPRU) : Baþlangýçta  Vücudun baþ, sýrt ve kalça bölgeleri yerde olmalý.\n" 
	                               "Ýki ayaðýnýzýda dizler bükülü yere koyun. Sonrasýnda sýrtýnýz yerde\n"
								   "olacak þekilde, ayak tabanlarinizdan destek alarak kalçanýzý yukarý\n" 
								   "kaldýrýn ve baþlangýç pozisyonuna geri dönün.\n"<<endl;
	cout<<"\t\t***KILO ALMAK ICIN SALONDAKI SPOR HAREKETLERI YAPILISI***"<<endl;
	cout<<"---FRONT SQUAT : squat sehpasýnda barý ön omuzunuza gelecek þekilde oturtun her iki elinizle\n" 
	                        "barý vücudunuza sabitleyin. Ayaklarýnýzý omuz geniþliðiniz kadar açýn. Parmak\n"
							"uçlarýnýz karþýya bakmalý. Nefes alarak çömelmeye baþlayýn. Üst bacaðýnýz\n" 
							"(diz ve kalça arasý) yere paralel oluncaya kadar çömelin. (Bknz: ilk resim sað)\n" 
							"Çömelme anýný yavaþ yaparsanýz hamstrings yani arka bacak kaslarý daha etkin þekilde\n" 
							"çalýþacaktýr. Hýzlý yaparsanýz bir geliþme saðlayamazsýnýz. Son noktaya geldiðiniz de\n"
							"nefes vererek orta hýzda kontrollü bir þekilde yükselmeye baþlayýn. Tepe noktaya\n" 
							"geldiðinizde bekleme yapmadan nefes alarak tekrar iniþe geçin. Tekrar sayýsý kadar\n" 
							"yapýp setinizi tamamlayýn. Bu egzersiz için 4 set 10 tekrar uygun olacaktýr.\n" 
							"Front squat yaparken öne doðru eðilmemelisiniz. Sýrtýnýzý daima dik tutmalýsýnýz.\n"
							"Dengenizi daha stabil hale getirmek ve daha çok ön bacak  adalelerini çalýþtýrmak için\n" 
							"topuklarýnýzýn altýna bir takoz koyabilirsiniz.\n"<<endl;
	cout<<"---DEADLIFT : Kaldýrabileceðiniz aðýrlýklarý taktýktan sonra barbell'i ayaklarýnýzýn dibine kadar getirmelisiniz.\n" 
	                     "Daha sonra ayaklarýnýzý omuz hizasýnda açarak parmak uçlarýnýz karþýya bakmalýdýr. Barbell mümkün\n"  
						 "olduðu kadar kaval kemiðine deðecek noktaya yakýn olmasý önemlidir.Bu þekilde bacaklarýnýzý diz\n"  
						 "kapaklarýndan hafifçe kýrarak eðilmeniz gerekiyor.Eðilirken vücudunuz mümkün olduðu kadar dik olmalýdýr.\n"  
						 "Daha sonra dirseklerinizi kýrmadan Barbell'li kavramamýz gerekir. Kollarýnýz omuz hizasýnda açýk þekilde\n"  
						 "olmalýdýr. Ardýndan derin bir nefes almak suretiyle orta hýzda barbell'i nefes vermek suretiyle kaldýrýn.\n"  
						 "Son noktaya ulaþtýðýný zaman vücudunuz dik bir pozisyonda olmalýdýr. Ardýndan yeniden nefes almak suretiyle\n"  
						 "verirken aðýrlýðý yere býrakýn.\n"<<endl;
	cout<<"---INCLINE BENCHPRESS : Hareketi yapmak için 45-60 derecelik incline sehpaya sýrt üstü uzanýn. Ayaklarýnýz yere tam bassýn\n"
	                               "ve parmak uçlarýnýz karþýya baksýn. Eller arasý mesafe ayarý için iki yöntem vardýr. Birincisi barýn\n" 
								   "üstündeki çizgileri kullanmaktýr. Kiþinin omuz geniþliðine göre bir kaç santim içeriden ya da bir kaç\n" 
								   "santim dýþarýdan tutulabilir. Ýkinci yöntem ise üst kollarýn (dirsek - el arasý) yere tam dik olmasýdýr.\n" 
								   "Bu iki yöntem sayesinde düzgün formu yapmýþ olursunuz. Doðru þekilde konumlandýktan sonra, nefes alarak\n" 
								   "barý göðüse (göðüs uçlarý hizasýna) doðru yavaþça indirin.Yavaþça indirmek triceps kaslarýnýn da etkin\n" 
								   "þekilde çalýþmasýný saðlar. Barýn göðüse deðmesine bir santim kala, nefes vererek tüm gücünüzle barý yukarý\n" 
								   "doðru itin. Tepe noktaya ulaþtýðýnýzda beklemeden, nefes alarak barý tekrar göðüs uçlarýnýza doðru indirin.\n" 
								   "Tekrar sayýsý kadar yapýp setinizi tamamlayýn. Bu egzersiz için 4 set 10 tekrar uygun olacaktýr.\n"<<endl;
	cout<<"---ARNOLD BENCHPRESS : Arkasý ayarlanabilir bench sehpahasýný dik konuma getirip, sýrtýnýzý iyice yaslayarak oturun. Ayaklarýnýz\n"  
	                              "açýk ve karþýya bakar konumda olursa yüksek aðýrlýklarda dengenizi saðlamanýza yardýmcý olur.Üstten tutuþla\n"  
								  "her iki elinize birer dumbbell alýn. Üst kollarýnýz birbirine paralel, yere dik ve avuç içleriniz vücudunuza\n"  
								  "bakar þekilde olmalý. Nefes alýn ve ardýndan nefes vererek, fleksiyon yaparak yani avuç içlerinizi dýþarý\n"  
								  "doðru çevirerek , dumbbell'larý yukarý birbirlerine deðmesine bir kaç santim mesafe kalana kadar kaldýrýn.\n"  
								  "Tepe noktasýnda 0,5-1 saniye kadar bekledikten sonra, nefes alarak, kaldýrýþ hýzýnýza oranla daha düþük bir\n"  
								  "hýzda yine fleksiyon yaparak yani avuç içlerinizi vücudunuza çevirerek dumbell'larý aþaðý indirip baþlangýç\n"  
								  "pozisyonunuza gelin. Tekrar sayýsý kadar yapýp setinizi tamamlayýn. Bu egzersiz için 4 set 10 tekrar uygun olacaktýr.\n"<<endl;
   cout<<"---CABLE BICEP CURL : Makinenin önünde durup çok aðýr olmayan bir kilo takýn. Uygun bir aðýrlýk seçin ve kollarýnýzý aþaðý sarkýtýp baþlangýç\n" 
                                "pozisyonunuza geçin. Elleriniz arasýndaki boþluk omuz geniþliðiniz kadar olsun. Bu þekilde biceps long ve short head eþit\n" 
								"çalýþýr. Ayak duruþunu da iki þekilde yapabilirsiniz. Ayaklar yan yana olursa; daha fazla yüke girebilirsiniz ama bel\n" 
								"problemi varsa zorlanabilir. Ayaklardan biri önde biri arkada olursa; bel korunur fakat kaldýracaðýnýz aðýrlýk miktarý\n" 
								"azalýr. Her ikisini de deneyip kararýnýzý verin. Nefes alýn ve ardýndan nefesinizi vererek 1 - 1,5 saniye aralýðýnda barý\n" 
								"çenenize deðmesine bir kaç santim kalana kadar çekin. Tepe noktada 1 saniye kadar bekleyin ve ardýndan nefes alarak 1,5 - 2\n" 
								"saniye aralýðýnda barý salarak kollarýnýzý tamamen açýn. Kolu tamamen açmak ve maksimum kapatmak bu harekette oldukça önemli.\n" 
								"Kas çekiþ anýnda son noktaya kadar kýsalýp, salýþ anýnda ise sonuna kadar uzamalý. Çekiþ anýnda vücudunuzu sallayýp momentum\n" 
								"kazanmayýn. Mümkün mertebe sadece ön kollarýnýz hareket etsin. Tekrar sayýsý kadar yapýp setinizi tamamlayýn. 4 set 10 tekrar\n"
								 "ve ek olarak pump amaçlý düþük aðýrlýklý 1 set maksimum tekrar yapýlabilir.\n"<<endl;
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

