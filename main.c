#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SZ 300

char FileName[10] = "arsiv.txt"; 

typedef struct 
{
	char film_adi[30];
	int film_yayinlanma_yili;
	char film_yonetmeni[30];
	char film_senaristi[30];
	char film_basrol_oyuncusu[30];
}Film;

void FilmSil(char*);
int IsEmpty(Film);
void RemoveFromArray(Film* array, int index);
void AraIsim(void);
void AraYil(void);
void AraYonetmen(void);
void AraSenarist(void);
int CompareFilms(Film, Film);
void AraBasrol(void);
int *FilmBulYil(int yil);
int *FilmBulIsim(char*);
int *FilmBulSenarist(char *senarist);
int *FilmBulBasrol(char *basrol);
int *FilmBulYonetmen(char *yonetmen);
void Listele(void);
void KayitEkle(void);
void PrintFilm(Film);
void Menu_Ara(void);
void Menu_Guncelle(void);
int ArsivUzunlugu(void);
void ArsivYenile(void);
void FilmEkle(Film, FILE*);
void swap(Film*, Film*); 
void bubbleSort(Film[], int);
void Guncelle(Film);

Film arsiv[MAX_NAME_SZ];

void swap(Film *xp, Film *yp) 
{ 
    Film temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}

void bubbleSort(Film arr[], int n) 
{ 
	int i, j; 
	for (i = 0; i < n-1; i++)
		for (j = 0; j < n-i-1; j++)
			if (arr[j].film_yayinlanma_yili > arr[j+1].film_yayinlanma_yili) 
        		swap(&arr[j], &arr[j+1]); 
}
int main()
{
	while (1)
	{
		int input = -1;
		printf("Film eklemek icin 1 e bas \n");
		printf("Filmleri listelemek icin 2 ye bas \n");
		printf("Filmleri guncellemek icin 3 e bas \n");
		printf("Film silmek icin 4 e bas \n");
		printf("Film aramak icin 5 e bas \n");
		printf("cikis yapmak icin 0 a bas \n");

		scanf("%d", &input);
	    while ((getchar()) != '\n'); // Flushing the input buffer

		switch (input)
		{
		case 0:
			printf("cikis yaptiniz \n");
			exit(0);
		case 1:
			KayitEkle();
			break;
		case 2:
			Listele();
			break;
		case 3:
			Menu_Guncelle();
			break;
		case 4:
			printf("Silmek istediginiz Film adini giriniz\n");
			char film_adi[MAX_NAME_SZ];
			scanf("%s", film_adi);
			FilmSil(film_adi);
			break;
		case 5: 
			Menu_Ara();
			break;
		default:
			printf("%s\n", "Yanlis secenek\n");
			break;
		}
		printf("\n");
	}
	return 0;
}

void Menu_Guncelle()
{
	char film_adi[MAX_NAME_SZ];
	Film guncellenmis[MAX_NAME_SZ];
	printf("Guncellemek istediginiz filmin adini giriniz:\n");
	scanf("%s",film_adi);
	int* film_index;
	film_index = FilmBulIsim(film_adi);
	int bulundu = 0;
	int k = 0;
	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		//printf("%d\n", film_index[i]);
		if(film_index[i] == -1)
		{
			// BULUNAMADI
		}
		else
		{
			bulundu = 1;
			// BULUNDU
			ArsivYenile();
			Guncelle(arsiv[film_index[i]]);
		}
	}
	if(bulundu == 0)
	{ 
		printf("--------------------------------\n");
		printf("Film: %s bulunamadi.\n", film_adi);
		printf("--------------------------------\n");
	}
}

void Guncelle(Film f)
{
	char input[1];
	FILE *sptr;
	int *film_index;
	film_index = FilmBulIsim(f.film_adi);
	Film silinecek[MAX_NAME_SZ], silinmeyecek[MAX_NAME_SZ];

	int j = 0;
	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		silinmeyecek[i] = arsiv[i];
		if(film_index[i] != -1)
		{
			silinecek[j] = arsiv[film_index[i]];
			j++;
		}
	}
	int guncellendi = 0;

	sptr = fopen(FileName, "w+");
	for(int i = 0; i < j; i++)
	{
		printf("Guncellenecek: \n");
		PrintFilm(silinecek[i]);
		printf("Guncellemek istediginize emin misiniz? [Y/N]\n");
		scanf("%s", input);
		if(!strcmp(input, "Y") || !strcmp(input, "y"))
		{
			guncellendi = 1;
		}
		else if(!strcmp(input, "N") || !strcmp(input, "n"))
		{
			FilmEkle(silinecek[i], sptr);
		}
		else
		{
			i--;
		}
	}
	for(int i = 0; i < j; i++)
	{
		for(int c = 0; c < MAX_NAME_SZ; c++)
		{
			if(CompareFilms(arsiv[c], silinecek[i]) == 1 && IsEmpty(arsiv[c]) == 0)
			{
				Film f;
				silinmeyecek[c] = f;
			}
		}
	}

	for(int i = 0; i < MAX_NAME_SZ; i++)
	{
		if(!IsEmpty(silinmeyecek[i]))
		{
			FilmEkle(silinmeyecek[i],sptr);
		}
		arsiv[i] = silinmeyecek[i];
	}
	fclose(sptr);
	if(!guncellendi) return;
	FILE *eptr;
	eptr = (fopen(FileName, "a"));
	printf("Guncellemek istediginiz filmin yayinlanma yilini giriniz: \n");
	scanf("%d", &f.film_yayinlanma_yili);
	printf("Guncellemek istediginiz filmin yonetmenini giriiniz: \n");
	scanf("%s", f.film_yonetmeni);
	printf("Guncellemek istediginiz filmin senaristini giriniz: \n");
	scanf("%s", f.film_senaristi);
	printf("Guncellemek istediginiz filmin basrol oyuncu adini giriniz: \n");
	scanf("%s", f.film_basrol_oyuncusu);
	fprintf(eptr, "%d\t%s\t%s\t%s\t%s\n", f.film_yayinlanma_yili, f.film_adi, f.film_yonetmeni, f.film_senaristi, f.film_basrol_oyuncusu);
	fclose(eptr);
	printf("Film basarili bir sekilde guncellenmistir. \n");

	ArsivYenile();
}

void Menu_Ara() // BITTI
{   
	ArsivYenile();
	int input;
	printf("Isme gore aramak icin 1 e bas: \n");
	printf("Yila gore aramak icin 2 e bas: \n");
	printf("Yonetmene gore aramak icin 3 e bas: \n");
	printf("Senaristine gore aramak icin 4 e bas: \n");
	printf("Basrol oyuncusuna gore aramak icin 5 e bas: \n");
	scanf("%d", &input);
	switch(input){
		case 1 : 
			AraIsim();
			break ;
		case 2 :
			AraYil();
			break ;
		case 3 :
			AraYonetmen();
			break ;
		case 4 :
			AraSenarist();
			break;
		case 5 :
			AraBasrol();
			break;
	}
		
}

void AraIsim()
{
	char isim[MAX_NAME_SZ];
	printf("Aramak istediginiz Film adini giriniz: \n");
	scanf("%s", isim);
	int* film_index;
	film_index = FilmBulIsim(isim);

	int bulundu = 0;
	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		//printf("%d\n", film_index[i]);
		if(film_index[i] == -1)
		{
			// BULUNAMADI
		}
		else
		{
			bulundu = 1;
			// BULUNDU
			PrintFilm(arsiv[film_index[i]]);
		}
	}
	if(bulundu == 0)
	{ 
		printf("--------------------------------\n");
		printf("Film: %s bulunamadi.\n", isim);
		printf("--------------------------------\n");
	}
}

 void AraYil()
{
	int film_yayinlanma_yili;
	printf("Aramak istediginiz filmin yilini giriniz: \n");
	scanf("%d", &film_yayinlanma_yili);
	int* film_index;
	film_index = FilmBulYil(film_yayinlanma_yili);

	int bulundu = 0;
	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		//printf("%d\n", film_index[i]);
		if(film_index[i] == -1)
		{
			// BULUNAMADI
		}
		else
		{
			bulundu = 1;
			// BULUNDU
			PrintFilm(arsiv[film_index[i]]);
		}
	}
	if(bulundu == 0)
	{   
		printf("--------------------------------\n");
		printf("Aradiginiz yilda Film bulunamadi.\n");
	}	printf("--------------------------------\n");
}

 void AraYonetmen()
{
	char yonetmen[MAX_NAME_SZ];
	printf("Aramak istediginiz filmin yonetmenini giriniz: \n");
	scanf("%s", yonetmen);
	int* film_index;
	film_index = FilmBulYonetmen(yonetmen);

	int bulundu = 0;
	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		//printf("%d\n", film_index[i]);
		if(film_index[i] == -1)
		{
			// BULUNAMADI
		}
		else
		{
			bulundu = 1;
			// BULUNDU
			PrintFilm(arsiv[film_index[i]]);
		}
	}
	if(bulundu == 0)
	{
		printf("--------------------------------\n");
		printf("Yonetmeni: %s olan Film bulunamadi.\n", yonetmen);
	}	printf("--------------------------------\n");
}

  void AraSenarist()
{
	char senarist[MAX_NAME_SZ];
	printf("Aramak istediginiz filmin senaristini giriniz: \n");
	scanf("%s", senarist);
	int* film_index;
	film_index = FilmBulSenarist(senarist);

	int bulundu = 0;
	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		//printf("%d\n", film_index[i]);
		if(film_index[i] == -1)
		{
			// BULUNAMADI
		}
		else
		{
			bulundu = 1;
			// BULUNDU
			PrintFilm(arsiv[film_index[i]]);
		}
	}
	if(bulundu == 0)
	{
		printf("--------------------------------\n");
		printf("Senaristi: %s olan Film bulunamadi.\n", senarist);
	}	printf("--------------------------------\n");
}

   void AraBasrol()
{
	char basrol[MAX_NAME_SZ];
	printf("Aramak istediginiz filmin basrol oyuncusunun adini giriniz: \n");
	scanf("%s", basrol);
	int* film_index;
	film_index = FilmBulBasrol(basrol);

	int bulundu = 0;
	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		if(film_index[i] == -1)
		{
			// BULUNAMADI
		}
		else
		{
			bulundu = 1;
			// BULUNDU
			PrintFilm(arsiv[film_index[i]]);
		}
	}
	if(bulundu == 0)
	{
		printf("--------------------------------\n");
		printf("Basrol oyuncusu: %s olan Film bulunamadi.\n", basrol);
	}
		printf("--------------------------------\n");
}



void KayitEkle() // BITTI
{
	Film f;

	FILE *eptr;
	eptr = (fopen(FileName, "a"));
	printf("Eklemek istediginiz Film adini giriniz: \n");
	scanf("%s", f.film_adi);
	printf("Eklemek istediginiz filmin yayinlanma yilini giriniz: \n");
	scanf("%d", &f.film_yayinlanma_yili);
	printf("Eklemek istediginiz filmin yonetmenini giriiniz: \n");
	scanf("%s", f.film_yonetmeni);
	printf("Eklemek istediginiz filmin senaristini giriniz: \n");
	scanf("%s", f.film_senaristi);
	printf("Eklemek istediginiz filmin basrol oyuncu adini giriniz: \n");
	scanf("%s", f.film_basrol_oyuncusu);
	fprintf(eptr, "%d\t%s\t%s\t%s\t%s\n", f.film_yayinlanma_yili, f.film_adi, f.film_yonetmeni, f.film_senaristi, f.film_basrol_oyuncusu);
	fclose(eptr);
	printf("Film basarili bir sekilde eklenmistir \n");
}

void FilmEkle(Film f, FILE *eptr)
{	
	fprintf(eptr, "%d\t%s\t%s\t%s\t%s\n", f.film_yayinlanma_yili, f.film_adi, f.film_yonetmeni, f.film_senaristi, f.film_basrol_oyuncusu);
}

void Listele() // Bitti
{
	ArsivYenile();
	int n = ArsivUzunlugu();
    bubbleSort(arsiv, n);
	for(int i = 0; i < ArsivUzunlugu(); i++)
	{
		if(!IsEmpty(arsiv[i]))
			PrintFilm(arsiv[i]);
	}
}

int *FilmBulIsim(char *isim) // Bitti
{
	ArsivYenile();

	static int bulunan[MAX_NAME_SZ];

	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		bulunan[i] = -1;
	}
	for(int i = 0; i < ArsivUzunlugu(); i++)
	{
		if(!strcmp(isim, arsiv[i].film_adi))
		{
			bulunan[i] = i;
		}
	}

	return bulunan;
}

int *FilmBulYil(int yil) // Bitti
{
	ArsivYenile();

	static int bulunan[MAX_NAME_SZ];

	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		bulunan[i] = -1;
	}
	for(int i = 0; i < ArsivUzunlugu(); i++)
	{
		if(yil == arsiv[i].film_yayinlanma_yili)
		{
			bulunan[i] = i;
		}
	}

	return bulunan;
}

 int *FilmBulYonetmen(char *yonetmen) // Bitti
{
	ArsivYenile();

	static int bulunan[MAX_NAME_SZ];

	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		bulunan[i] = -1;
	}
	for(int i = 0; i < ArsivUzunlugu(); i++)
	{
		if(!strcmp(yonetmen, arsiv[i].film_yonetmeni))
		{
			bulunan[i] = i;
		}
	}

	return bulunan;
}

int *FilmBulBasrol(char *basrol) // Bitti
{
	ArsivYenile();

	static int bulunan[MAX_NAME_SZ];

	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		bulunan[i] = -1;
	}
	for(int i = 0; i < ArsivUzunlugu(); i++)
	{
		if(!strcmp(basrol, arsiv[i].film_basrol_oyuncusu))
		{
			bulunan[i] = i;
		}
	}

	return bulunan;
}

int *FilmBulSenarist(char *senarist) // Bitti
{
	ArsivYenile();

	static int bulunan[MAX_NAME_SZ];

	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		bulunan[i] = -1;
	}
	for(int i = 0; i < ArsivUzunlugu(); i++)
	{
		if(!strcmp(senarist, arsiv[i].film_senaristi))
		{
			bulunan[i] = i;
		}
	}

	return bulunan;
}

void ArsivYenile() // Bitti
{
	FILE *eptr;
	int i = 0;
	eptr = (fopen(FileName, "r+"));

	while(1) 
	{
    	if( feof(eptr) ) 
        	break ;
		fscanf(eptr, "%d\t%s\t%s\t%s\t%s", &arsiv[i].film_yayinlanma_yili, arsiv[i].film_adi, arsiv[i].film_yonetmeni, arsiv[i].film_senaristi, arsiv[i].film_basrol_oyuncusu);
		i++;
   }
	fclose(eptr);
}

int ArsivUzunlugu()
{
	Film f;
	int num = 0;
	for(int i = 0; i < (sizeof(arsiv) / sizeof(f)); i++)
	{
		if(!IsEmpty(arsiv[i]))
			num++;
	}

	return num;
}

void PrintFilm(Film film_to_print)
{
	printf("--------------------------------\n");
	printf("Film adi:\t%s\n", film_to_print.film_adi);
	printf("Yayinlanma Yil:\t%d\n", film_to_print.film_yayinlanma_yili);
	printf("Yonetmen:\t%s\n", film_to_print.film_yonetmeni);
	printf("Senarist:\t%s\n", film_to_print.film_senaristi);
	printf("Basrol oy.:\t%s\n\n", film_to_print.film_basrol_oyuncusu);
}

int CompareFilms(Film f1, Film f2)
{
	int toReturn = 0;

	if(
		!strcmp(f1.film_adi, f2.film_adi)
		&&
		!strcmp(f1.film_basrol_oyuncusu, f2.film_basrol_oyuncusu)
		&&
		!strcmp(f1.film_yonetmeni, f2.film_yonetmeni)
		&&
		!strcmp(f1.film_senaristi, f2.film_senaristi)
		&&
		f1.film_yayinlanma_yili == f2.film_yayinlanma_yili
		)
	{
		toReturn = 1;
	}
	return toReturn;
}

void FilmSil(char* film_adi) 
{
	char input[1];
	FILE *sptr;
	int *film_index;
	film_index = FilmBulIsim(film_adi);
	int bulundu = 0;
	Film silinecek[MAX_NAME_SZ], silinmeyecek[MAX_NAME_SZ];

	int j = 0;
	for (int i = 0; i < MAX_NAME_SZ; i++)
	{
		silinmeyecek[i] = arsiv[i];
		if(film_index[i] != -1)
		{
			silinecek[j] = arsiv[film_index[i]];
			bulundu = 1;
			j++;
		}
	}
	if(bulundu == 0)
	{
		printf("--------------------------------\n");
		printf("Film: %s bulunamadi.\n", film_adi);
		printf("--------------------------------\n");
		return;
	}
	sptr = fopen(FileName, "w+");
	for(int i = 0; i < j; i++)
	{
		printf("Silinecek: \n");
		PrintFilm(silinecek[i]);
		printf("Silmek istediginize emin misiniz? [Y/N]\n");
		scanf("%s", input);
		if(!strcmp(input, "Y") || !strcmp(input, "y"))
		{
			printf("Film basarili bir sekilde silinmistir.\n");
		}
		else if(!strcmp(input, "N") || !strcmp(input, "n"))
		{
			FilmEkle(silinecek[i], sptr);
		}
		else
		{
			i--;
		}
	}
	for(int i = 0; i < j; i++)
	{
		for(int c = 0; c < MAX_NAME_SZ; c++)
		{
			if(CompareFilms(arsiv[c], silinecek[i]) == 1 && IsEmpty(arsiv[c]) == 0)
			{
				Film f;
				silinmeyecek[c] = f;
			}
		}
	}

	for(int i = 0; i < MAX_NAME_SZ; i++)
	{
		if(!IsEmpty(silinmeyecek[i]))
		{
			FilmEkle(silinmeyecek[i],sptr);
		}
		arsiv[i] = silinmeyecek[i];
	}
	fclose(sptr);
	ArsivYenile();
}

int IsEmpty(Film f)
{
	int toReturn = 0;
	if(f.film_yayinlanma_yili == 0
		&&
		!strcmp(f.film_adi, "")
		&&
		!strcmp(f.film_senaristi, "")
		&&
		!strcmp(f.film_basrol_oyuncusu, "")
		&&
		!strcmp(f.film_yonetmeni, "")
		)
	{
		toReturn = 1;
	}
	return toReturn;
}