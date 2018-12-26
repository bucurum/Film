# Film Arsivi Berke Ucurum CENG 101 Proje

## Aciklama:
	arsiv.txt diye bir dosya olusturur. Arsiv bu dosyaya kaydedilir.

## Instructions:
	To Compile:
		gcc main.c -o arsiv
	To Execute:
		./arsiv

## Ekstralar:
	Birden cok filmi yilina gore listelemek
	Guncellemeden veya silmeden once filmin detaylari kullaniciya sunulur.
	Ayni isimde birden cok filmi silmeye calisirken, bulunan her filmi kullaniciya tek tek sorar.
	Film arama ayni kategoride (isim, basrol oyuncusu, yayinlanma yili, yonetmen, senarist) birden cok filmi bulup kullaniciya sunar.

## Bilinen Hatalar / Eksiklikler:
	Birden cok film ayni anda guncellenemez
	Herhangi bir ismin icinde bosluk olmamali

## Data:
	1964	titanic	berke	emre	ucurum
	1964	su_sisesi	sise	musluk	damla
	1679	kola	beyin	kol	ayna

## Menu:
	Film eklemek icin 1 e bas 
	Filmleri listelemek icin 2 ye bas 
	Filmleri guncellemek icin 3 e bas 
	Film silmek icin 4 e bas 
	Film aramak icin 5 e bas 
	cikis yapmak icin 0 a bas 

## Film Ekleme:
	Eklemek istediginiz Film adini giriniz: 
	birfilm
	Eklemek istediginiz filmin yayinlanma yilini giriniz: 
	1997
	Eklemek istediginiz filmin yonetmenini giriiniz: 
	perke
	Eklemek istediginiz filmin senaristini giriniz: 
	kucuruk
	Eklemek istediginiz filmin basrol oyuncu adini giriniz: 
	adam
	Film basarili bir sekilde eklenmistir 

## Filmleri Listele: (Yila gore artan)
	--------------------------------
	Film adi:	kola
	Yayinlanma Yil:	1679
	Yonetmen:	beyin
	Senarist:	kol
	Basrol oy.:	ayna

	--------------------------------
	Film adi:	su_sisesi
	Yayinlanma Yil:	1964
	Yonetmen:	sise
	Senarist:	musluk
	Basrol oy.:	damla

	--------------------------------
	Film adi:	titanic
	Yayinlanma Yil:	1987
	Yonetmen:	berke
	Senarist:	emre
	Basrol oy.:	ucurum

	--------------------------------
	Film adi:	birfilm
	Yayinlanma Yil:	1997
	Yonetmen:	perke
	Senarist:	kucuruk
	Basrol oy.:	adam

## Film Guncelle:
	Guncellemek istediginiz filmin adini giriniz:
	titanic
	Guncellenecek: 
	--------------------------------
	Film adi:	titanic
	Yayinlanma Yil:	1987
	Yonetmen:	berke
	Senarist:	emre
	Basrol oy.:	ucurum

	Guncellemek istediginize emin misiniz? [Y/N]
	Y
	Guncellemek istediginiz filmin yayinlanma yilini giriniz: 
	1987
	Guncellemek istediginiz filmin yonetmenini giriiniz: 
	berke
	Guncellemek istediginiz filmin senaristini giriniz: 
	emre
	Guncellemek istediginiz filmin basrol oyuncu adini giriniz: 
	gemi
	Film basarili bir sekilde guncellenmistir. 

## Film Silmek:
	Silmek istediginiz Film adini giriniz
	birfilm
	Silinecek: 
	--------------------------------
	Film adi:	birfilm
	Yayinlanma Yil:	1997
	Yonetmen:	perke
	Senarist:	kucuruk
	Basrol oy.:	adam

	Silmek istediginize emin misiniz? [Y/N]
	Y
	Film basarili bir sekilde silinmistir.

	###### Ayni isimli birden cok film silmek:
		Silmek istediginiz Film adini giriniz
		kola
		Silinecek: 
		--------------------------------
		Film adi:	kola
		Yayinlanma Yil:	1679
		Yonetmen:	beyin
		Senarist:	kol
		Basrol oy.:	ayna

		Silmek istediginize emin misiniz? [Y/N]
		N
		Silinecek: 
		--------------------------------
		Film adi:	kola
		Yayinlanma Yil:	1979
		Yonetmen:	bubirbeyin
		Senarist:	kol
		Basrol oy.:	ayna

		Silmek istediginize emin misiniz? [Y/N]
		Y
		Film basarili bir sekilde silinmistir.


## Film Aramak:
	Isme gore aramak icin 1 e bas: 
	Yila gore aramak icin 2 e bas: 
	Yonetmene gore aramak icin 3 e bas: 
	Senaristine gore aramak icin 4 e bas: 
	Basrol oyuncusuna gore aramak icin 5 e bas: 
	###### Isme Gore:
		Aramak istediginiz Film adini giriniz: 
		titanic
		--------------------------------
		Film adi:	titanic
		Yayinlanma Yil:	1964
		Yonetmen:	berke
		Senarist:	emre
		Basrol oy.:	gemi

	###### Yila Gore:
		Aramak istediginiz filmin yilini giriniz: 
		1964
		--------------------------------
		Film adi:	su_sisesi
		Yayinlanma Yil:	1964
		Yonetmen:	sise
		Senarist:	musluk
		Basrol oy.:	damla

		--------------------------------
		Film adi:	titanic
		Yayinlanma Yil:	1964
		Yonetmen:	berke
		Senarist:	emre
		Basrol oy.:	gemi

		--------------------------------
	
	###### Yonetmene Gore:
		Aramak istediginiz filmin yonetmenini giriniz: 
		berke
		--------------------------------
		Film adi:	titanic
		Yayinlanma Yil:	1964
		Yonetmen:	berke
		Senarist:	emre
		Basrol oy.:	gemi

		--------------------------------

	###### Senaristine Gore:
		Aramak istediginiz filmin senaristini giriniz: 
		musluk
		--------------------------------
		Film adi:	su_sisesi
		Yayinlanma Yil:	1964
		Yonetmen:	sise
		Senarist:	musluk
		Basrol oy.:	damla

		--------------------------------

	###### Basrol Oyuncusuna Gore:
		--------------------------------
		Film adi:	kola
		Yayinlanma Yil:	1679
		Yonetmen:	beyin
		Senarist:	kol
		Basrol oy.:	ayna

		--------------------------------

	###### Herhangi bir kriterde bulunamazsa:
		Aramak istediginiz Film adini giriniz: 
		ttyuii
		--------------------------------
		Film: ttyuii bulunamadi.
		--------------------------------

## Cikis Yapmak:
	Film eklemek icin 1 e bas 
	Filmleri listelemek icin 2 ye bas 
	Filmleri guncellemek icin 3 e bas 
	Film silmek icin 4 e bas 
	Film aramak icin 5 e bas 
	cikis yapmak icin 0 a bas 
	0
	cikis yaptiniz 
