





#include <cstdlib>
#include <fstream>
#include <iostream> 
#include <string> 
#include <locale.h>
#include<iomanip>
#include<chrono>	
#include<ctime>
#include<cstring>
#include<stdio.h> 






using namespace std;
const int kullanciSayi = 100;



int main(int argc, char* argv[])
{



	//kullanci.txt
	string kullanciAdi;
	string sifre;
	string username;
	string password;

	//okuyucu.txt
	string TCno;
	string	ad;
	string soyad;
	int uyeNo;
	int tel;
	string dogumT;
	string gorev;
	int kitapSayisi;

	//kitap.txt
	string isbn;
	string kitapIsmi;
	string yazarAd;
	string yazarSoyad;
	string kitapKonu;
	string kitapturu;
	int sayfaSayisi;

	//odunc.txt
	string TC;
	string isbnO;
	string oduncT;
	string donusT;



	int secim;
	char cevap;


	do {





		ifstream dosyaOku("kullancillar.txt");


		cout << "Kullanci adiyi gir: " << endl; cin >> kullanciAdi;
		cout << "Sifreyi gir: " << endl; cin >> sifre;

		bool kTest = false;
		while (!dosyaOku.eof()) {

			dosyaOku >> username >> password;
			if (kullanciAdi == username && sifre == password)
			{
				cout << endl;
				kTest = true;

				break;
			}
		}
		dosyaOku.close();
		if (kTest)
		{
			do {

				cout << "1) Okuyucu kaydi" << endl;
				cout << "2) Okuyucu kaydi guncelleme" << endl;
				cout << "3) Okuyucu silme" << endl;
				cout << "4) Okuyucu uzerindeki kitaplar listesi" << endl;
				cout << "5) Okuyucu kitap odunc alma" << endl;
				cout << "6) Okuyucu kitap geri dondurme" << endl;
				cout << "7) Kitap ekleme" << endl;
				cout << "8) Kitap silme" << endl;
				cout << "9) Kitap duzeltme" << endl;

				cin >> secim;




				if (secim == 1)

				{
					ofstream dosyaYaz("okuyucu.txt", ios::app);
					do
					{
						cout << "\n Okuyucu TC :"; cin >> TCno;
						cout << "\n Okuyucu adi :"; cin >> ad;
						cout << "\n Okuyucu soyadi :"; cin >> soyad;
						cout << "\n Okuyucu telefon numarasi :"; cin >> tel;
						cout << "\n Okuyucu dogum tarihi :"; cin >> dogumT;
						cout << "\n Okuyucu gorevi :"; cin >> gorev;

						kitapSayisi = 0;

						srand(time(0));
						do {

							uyeNo = rand() % (100000);

						} while (uyeNo < 10000);


						cout << "\n Uye numarasi :" << uyeNo << endl;

						dosyaYaz << "\n" << TCno << " " << ad << " " << soyad << " " << uyeNo << " " << tel << " " << dogumT << " " << gorev << " " << kitapSayisi;

						cout << "\n baska kayit yapacak misin?(e/h) "; cin >> cevap;

					} while (!(cevap == 'h'));

					dosyaYaz.close();

					cout << endl << "dosyaya yazim tamamlandi. " << endl;


				}


				if (secim == 2)

				{


					string ArananString;

					cout << " aranacak kisi TC numarasi :"; cin >> ArananString;


					ifstream dosyaOku("okuyucu.txt");

					ofstream dosyaYaz("okuyucu.tmp");


					while (!dosyaOku.eof())

					{
						dosyaOku >> TCno >> ad >> soyad >> uyeNo >> tel >> dogumT >> gorev >> kitapSayisi;

						if (ArananString == TCno)
						{
							cout << "\n dosyadaki kayit \n";
							cout << TCno << endl;
							cout << ad << endl;
							cout << soyad << endl;
							cout << uyeNo << endl;
							cout << tel << endl;
							cout << dogumT << endl;
							cout << gorev << endl;
							cout << kitapSayisi << endl;

							cout << "\n Kayit icin yeni degerler girisi \n";

							cout << "\n Okuyucu TC :"; cin >> TCno;
							cout << "\n Okuyucu adi :"; cin >> ad;
							cout << "\n Okuyucu soyadi :"; cin >> soyad;
							cout << "\n Okuyucu telefon numarasi :"; cin >> tel;
							cout << "\n Okuyucu dogum tarihi :"; cin >> dogumT;
							cout << "\n Okuyucu gorevi :"; cin >> gorev;
							cout << "\n Okuyucu kitap sayisi :"; cin >> kitapSayisi;
							//uye numarasi degismeyecek

							dosyaYaz << "\n" << TCno << " " << ad << " " << soyad << " " << uyeNo << " " << tel << " " << dogumT << " " << gorev << " " << kitapSayisi;

						}
						else
						{

							dosyaYaz << "\n" << TCno << " " << ad << " " << soyad << " " << uyeNo << " " << tel << " " << dogumT << " " << gorev << " " << kitapSayisi;

						}

					}

					dosyaYaz.close();
					dosyaOku.close();

					remove("okuyucu.txt");

					rename("okuyucu.tmp", "okuyucu.txt");

				}

				if (secim == 3)
				{
					string ArananString;

					cout << " silinecek kisi TC numarasi :"; cin >> ArananString;

					ifstream dosyaOku("okuyucu.txt");
					ofstream dosyaYaz("okuyucu.tmp");

					while (!dosyaOku.eof())
					{


						dosyaOku >> TCno >> ad >> soyad >> uyeNo >> tel >> dogumT >> gorev >> kitapSayisi;


						if (ArananString == TCno)
						{

							if (kitapSayisi == 0)
							{

								cout << "\n dosyadaki kayit \n";
								cout << TCno << endl;
								cout << ad << endl;
								cout << soyad << endl;
								cout << uyeNo << endl;
								cout << tel << endl;
								cout << dogumT << endl;
								cout << gorev << endl;
								cout << kitapSayisi << endl;
							}
							else
							{
								cout << "okuyucunun oduncleri geri donmelidir" << endl;
							}
						}

						else
						{
							dosyaYaz << "\n" << TCno << " " << ad << " " << soyad << " " << uyeNo << " " << tel << " " << dogumT << " " << gorev << " " << kitapSayisi;

						}
					}

					dosyaYaz.close();
					dosyaOku.close();

					remove("okuyucu.txt");

					rename("okuyucu.tmp", "okuyucu.txt");
				}

				if (secim == 4)
				{
					string ArananString;
					int i = 1;

					cout << "\n Okuyucu TC numarasi :"; cin >> ArananString;

					ifstream dosyaOku("kitaplar.txt");

					while (!dosyaOku.eof())
					{
						dosyaOku >> isbn >> kitapIsmi >> yazarAd >> yazarSoyad >> kitapKonu >> kitapturu >> sayfaSayisi;

						if (ArananString == TCno)
						{
							cout << "\n Okuyucu uzerindeki " << i << ". kitap\n";

							cout << "ISBN :" << isbn << endl;
							cout << "Kitap isimi :" << kitapIsmi << endl;
							cout << "Yazar adi :" << yazarAd << endl;
							cout << "Yazar soyadi :" << yazarSoyad << endl;
							cout << "Kitap konusu :" << kitapKonu << endl;
							cout << "Kitap turu :" << kitapturu << endl;
							cout << "Kitap sayfa sayisi :" << sayfaSayisi << endl;

							i++;

						}
						else
						{
							cout << "\nOkuyucu bulunmadi.\n";

						}

					}
					dosyaOku.close();
				}

				if (secim == 5)
				{
					ifstream dosyaOku("okuyucu.txt");

					ofstream dosyaYaz1("odunc.txt", ios::app);
					ofstream dosyaYaz2("okuyucu.tmp");





					do
					{
						cout << "\nISBN :"; cin >> isbnO;
						cout << "\nTC numarasi :"; cin >> TC;
						cout << "\nOdunc tarihi :"; cin >> oduncT;
						cout << "\nDonus Tarihi :"; cin >> donusT;









						while (!dosyaOku.eof())
						{
							dosyaOku >> TCno >> ad >> soyad >> uyeNo >> tel >> dogumT >> gorev >> kitapSayisi;

							if (TC == TCno)
							{
								kitapSayisi++;

								cout << "\n Okuyucu kitap sayisi :" << kitapSayisi;

								dosyaYaz2 << "\n" << TCno << " " << ad << " " << soyad << " " << uyeNo << " " << tel << " " << dogumT << " " << gorev << " " << kitapSayisi;
								dosyaYaz1 << "\n" << isbnO << " " << TCno << " " << oduncT << " " << donusT;
							}
							else
							{

								dosyaYaz2 << "\n" << TCno << " " << ad << " " << soyad << " " << uyeNo << " " << tel << " " << dogumT << " " << gorev << " " << kitapSayisi;

							}
						}





						cout << "\n baska kitap odunc almak isiyor musun?(e/h) "; cin >> cevap;

					} while (!(cevap == 'h'));

					dosyaOku.close();
					dosyaYaz1.close();
					dosyaYaz2.close();

					remove("okuyucu.txt");

					rename("okuyucu.tmp", "okuyucu.txt");



				}




				if (secim == 6)
				{

					ifstream dosyaOku1("okuyucu.txt");
					ifstream dosyaOku2("odunc.txt");

					ofstream dosyaYaz1("okuyucu.tmp");
					ofstream dosyaYaz2("odunc.tmp");




					do
					{
						cout << "\nISBN :"; cin >> isbnO;
						cout << "\nTC numarasi :"; cin >> TC;
						cout << "\nOdunc tarihi :"; cin >> oduncT;
						cout << "\nDonus Tarihi :"; cin >> donusT;









						while (!(dosyaOku2.eof()) && !(dosyaOku1.eof()))
						{
							dosyaOku1 >> TCno >> ad >> soyad >> uyeNo >> tel >> dogumT >> gorev >> kitapSayisi;

							if (TC == TCno)
							{
								kitapSayisi--;

								cout << "\n Okuyucu kitap sayisi :" << kitapSayisi;

								dosyaYaz2 << "\n" << TCno << " " << ad << " " << soyad << " " << uyeNo << " " << tel << " " << dogumT << " " << gorev << " " << kitapSayisi;

								dosyaOku2 >> isbnO >> TCno >> oduncT >> donusT;
							}
							else
							{

								dosyaYaz2 << "\n" << TCno << " " << ad << " " << soyad << " " << uyeNo << " " << tel << " " << dogumT << " " << gorev << " " << kitapSayisi;

							}
						}





						cout << "\n baska kitap odunc almak isiyor musun?(e/h) "; cin >> cevap;

					} while (!(cevap == 'h'));

					dosyaOku1.close();
					dosyaOku2.close();
					dosyaYaz1.close();
					dosyaYaz2.close();

					remove("okuyucu.txt");
					remove("odunc.txt");

					rename("okuyucu.tmp", "okuyucu.txt");
					rename("odunc.tmp", "odunc.txt");


				}



				if (secim == 7)
				{
					ofstream dosyaYaz("kitaplar.txt", ios::app);

					do
					{
						cout << "\n ISBN :"; cin >> isbn;
						cout << "\n Kitap Ismi :"; cin >> kitapIsmi;
						cout << "\n Yazar adi :"; cin >> yazarAd;
						cout << "\n Yazar soyadı :"; cin >> yazarSoyad;
						cout << "\n Kitap Konusu :"; cin >> kitapKonu;
						cout << "\n Kitap turu :"; cin >> kitapturu;
						cout << "\n Kitap sayfasayisi :"; cin >> sayfaSayisi;


						dosyaYaz << "\n" << isbn << " " << kitapIsmi << " " << yazarAd << " " << yazarSoyad << " " << kitapKonu << " " << kitapturu << " " << sayfaSayisi;


						cout << "\n baska kitap ekleyecek misin?(e/h) "; cin >> cevap;


					} while (!(cevap == 'h'));
					dosyaYaz.close();

					cout << "Kitap ekleme tamamlandi. ";

				}

				if (secim == 8)
				{

					string ArananString;

					cout << "silenecek kitap ISBN :"; cin >> ArananString;

					ifstream dosyaOku("kitaplar.txt");
					ofstream dosyaYaz("kitaplar.tmp");

					while (!dosyaOku.eof())
					{

						dosyaOku >> isbn >> kitapIsmi >> yazarAd >> yazarSoyad >> kitapKonu >> kitapturu >> sayfaSayisi;

						if (ArananString == isbn)
						{

							cout << "silenecek kitap bilgileri :" << endl;
							cout << "\nISBN :" << isbn;
							cout << "\nKitap ismi :" << kitapIsmi;
							cout << "\nYazar adi :" << yazarAd;
							cout << "\nYazar soyadi :" << yazarSoyad;
							cout << "\nKitap konusu :" << kitapKonu;
							cout << "\nLitap turu :" << kitapturu;
							cout << "\nKita[ sayfasayisi :" << sayfaSayisi;


						}
						else
						{
							dosyaYaz << "\n" << isbn << " " << kitapIsmi << " " << yazarAd << " " << yazarSoyad << " " << kitapKonu << " " << kitapturu << " " << sayfaSayisi;
						}
					}

					dosyaYaz.close();
					dosyaOku.close();

					remove("kitaplar.txt");

					rename("kitaplar.tmp", "kitaplar.txt");

				}


				if (secim == 9)
				{
					string ArananString;


					cout << "duzelecek kitapin ISBN :"; cin >> isbn;

					ifstream dosyaOku("kitaplar.txt");
					ofstream dosyaYaz("kitaplar.tmp");


					while (!dosyaOku.eof())
					{



						if (ArananString == isbn) {
							cout << "\n dosyadaki kayit \n";
							cout << isbn << endl;
							cout << kitapIsmi << endl;
							cout << yazarAd << endl;
							cout << yazarSoyad << endl;
							cout << kitapKonu << endl;
							cout << kitapturu << endl;
							cout << sayfaSayisi << endl;


							cout << "\n Kayit icin yeni degerler girisi \n";

							cout << "\nISBN :" << isbn;
							cout << "\nKitap ismi :" << kitapIsmi;
							cout << "\nYazar adi :" << yazarAd;
							cout << "\nYazar soyadi :" << yazarSoyad;
							cout << "\nKitap konusu :" << kitapKonu;
							cout << "\nLitap turu :" << kitapturu;
							cout << "\nKita[ sayfasayisi :" << sayfaSayisi;

							dosyaYaz << "\n" << isbn << " " << kitapIsmi << " " << yazarAd << " " << yazarSoyad << " " << kitapKonu << " " << kitapturu << " " << sayfaSayisi;

						}
						else
						{
							dosyaYaz << "\n" << isbn << " " << kitapIsmi << " " << yazarAd << " " << yazarSoyad << " " << kitapKonu << " " << kitapturu << " " << sayfaSayisi;

						}
					}

					dosyaYaz.close();
					dosyaOku.close();

					remove("kitaplar.txt");

					rename("kitaplar.tmp", "kitaplar.txt");


				}

				cout << "\nBaska islem yapmak istiyor musun? :(e/h)"; cin >> cevap;



				cout << endl << endl;

			} while (!(cevap == 'h') || secim != 1 && secim != 2 && secim != 3 && secim != 4 && secim != 5 && secim != 6 && secim != 7 && secim != 8 && secim != 9);
		}
		else
			cout << "\ngirdiginiz kullanci adi veya sifre yanlistir" << endl << endl;




		cout << endl << endl;

	} while (kullanciAdi != username && sifre != password);


	system("PAUSE");

	return EXIT_SUCCESS;
}