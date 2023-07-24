#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_KISI_SAYISI 100
#define MAX_KITAP_SAYISI 100

typedef enum{
	
	ogrenci= 0,calisan= 1
	
}uyeYetkiSeviyesi;



typedef struct{
	
	char *uyeAdi;
	char *uyeSoyadi;
	int kutuphaneID;
	int sifre;
	uyeYetkiSeviyesi uyeYetkisi;
}kisiBilgileri;

typedef struct{
	
	char *kitapAdi;
	char *yazarAdi;
	char *yazarSoyadi;
	char *yayinEvi;
	int sayfaSayisi;
	int kitapDurumu;
	
}kitapBilgileri;

int kisiSorgula(kisiBilgileri *uyeListesi,int ID){
	int i;
	for(i=0;i<MAX_KISI_SAYISI;i++){
		if(uyeListesi[i].kutuphaneID == ID){
             return ID; // kullanýlmýþ ID.
   }
} 
    return -1; // kullanýlmamýþ ID.
}



int kayitOl(kisiBilgileri *uyeListesi){
	
	int i,kayitYapilacakIndex,ID;
	char uyeAdi[20],uyeSoyadi[20],ch;
	srand(time(NULL));
	
	for(i=0;i<MAX_KISI_SAYISI;i++){
		if(uyeListesi[i].kutuphaneID == 0){
			kayitYapilacakIndex=i;
			break;
		}
	}
	ID = rand()%1000+1;
	if(kisiSorgula(uyeListesi,ID)!=-1){
		printf("Bu ID daha once kullanilmistir...\n");
		exit(1);
	}
	printf("ID numaraniz %d olarak belirlenmistir...",ID);
	uyeListesi[kayitYapilacakIndex].kutuphaneID= ID;
	
	printf("Ad-Soyad bilgilerinizi giriniz:");
	scanf("%s %s",&uyeAdi,&uyeSoyadi);
	
	uyeListesi[kayitYapilacakIndex].uyeAdi=(char*)malloc(sizeof(char)*(strlen(uyeAdi)+1));
    uyeListesi[kayitYapilacakIndex].uyeSoyadi=(char*)malloc(sizeof(char)*(strlen(uyeSoyadi)+1));
	strcpy(uyeListesi[kayitYapilacakIndex].uyeAdi,uyeAdi);
	strcpy(uyeListesi[kayitYapilacakIndex].uyeSoyadi,uyeSoyadi);	
	
	printf("Ogrenciyseniz 'O' tuslayiniz\nCalisansaniz 'C' tuslayiniz\n");
	fflush(stdin);
	ch=getchar();
	if(ch == 'O'){
		uyeListesi[kayitYapilacakIndex].uyeYetkisi= ogrenci;
	}	
	else{
		uyeListesi[kayitYapilacakIndex].uyeYetkisi= calisan;
	}

printf("Lutfen sifrenizi giriniz:");
scanf("%d",&uyeListesi[kayitYapilacakIndex].sifre);

return uyeListesi[kayitYapilacakIndex].uyeYetkisi;

}

int girisYap(kisiBilgileri *uyeListesi){
	int ID,sifre,i;
	
	printf("ID:");
	scanf("%d",&ID);
	printf("Sifre:");
	scanf("%d",&sifre);
	
	for(i=0;MAX_KISI_SAYISI;i++){
		if(uyeListesi[i].kutuphaneID==ID){
			if(uyeListesi[i].sifre==sifre){
				printf("Giris basarili...\n");
				return uyeListesi[i].uyeYetkisi;
			}
		    return -1; // sifre yanlýþ.
			
		}
	}
	return -2; // ID deðeri hatalý.
	
	
}

void uyeleriGoruntule(kisiBilgileri *uyeListesi){
	
	int i=0;
	while(i<MAX_KISI_SAYISI && uyeListesi[i].kutuphaneID!=0){
		printf("Uye Adi-Soyadi:%s %s\n",uyeListesi[i].uyeAdi,uyeListesi[i].uyeSoyadi);
		printf("Uye ID:%d\n",uyeListesi[i].kutuphaneID);
		if(uyeListesi[i].uyeYetkisi==1){
			printf("Yetki seviyesi: Calisan\n");
		}
		else{
			printf("Yetki seviyesi: Ogrenci\n");
		}
	printf("-----------------------------------\n");
	i++;
	}	
}


void kitaplariGoruntule(kitapBilgileri *kitaplar){
	

	int i;
	for(i=0;i<MAX_KITAP_SAYISI;i++){
		if(kitaplar[i].sayfaSayisi!=0){
			printf("Kitap Adi:%s\n",kitaplar[i].kitapAdi);
			printf("Kitap Yazari:%s %s\n",kitaplar[i].yazarAdi,kitaplar[i].yazarSoyadi);
			printf("Kitap Yayinevi:%s\n",kitaplar[i].yayinEvi);
			printf("Kitap Sayfa Sayisi:%d\n",kitaplar[i].sayfaSayisi);
            if(kitaplar[i].kitapDurumu==0){
				printf("Bu kitap su an kutuphanede mevcut.\n");
			}
			else{
				printf("Bu kitap su an baskasi tarafindan alinmistir.\n");
			}
            printf("---------------------------------\n");
}
else{
	return;
}

}

}
	
void kitapAra(kitapBilgileri *kitaplar){
	
	int i=0;
	char kitapAdi[30];
	
	printf("Aramak istediginiz kitabin adini giriniz:");
	scanf("%s",&kitapAdi);
	
	while(i<MAX_KITAP_SAYISI && kitaplar[i].sayfaSayisi!=0){
		if(strcmp(kitaplar[i].kitapAdi,kitapAdi)==0){
			printf("Kitap Adi:%s\n",kitaplar[i].kitapAdi);
			printf("Kitap Yazari:%s %s\n",kitaplar[i].yazarAdi,kitaplar[i].yazarSoyadi);
			printf("Kitap Yayinevi:%s\n",kitaplar[i].yayinEvi);
			printf("Kitap Sayfa Sayisi:%d\n",kitaplar[i].sayfaSayisi);	
			return;	
		}
		i++;
	}
	printf("Maalesef aradiginiz kitap kutuphanemizde mevcut degil.\n");
	
	
}	
	
	
void kitapEkle(kitapBilgileri *kitaplar){
	int i,sayfaSayisi;
	char kitapAdi[30],yayinEvi[30],yazarAdi[30],yazarSoyadi[30];
	printf("Kitap adi ekleyiniz:");
	scanf("%s",&kitapAdi);
	printf("Kitap yayinevi bilgsini ekleyiniz:");
	scanf("%s",&yayinEvi);
	printf("kitabin yazar adini ve soyadini sirasiyla ekleyiniz:");
	scanf("%s %s",&yazarAdi,&yazarSoyadi);
	printf("Kitabin sayfa sayisini ekleyiniz:");
	scanf("%d",&sayfaSayisi);
	
	for(i=0;i<MAX_KITAP_SAYISI;i++){
		if(kitaplar[i].sayfaSayisi==0){
			kitaplar[i].kitapAdi=(char*)malloc(sizeof(char)*(strlen(kitapAdi)+1));
			kitaplar[i].yayinEvi=(char*)malloc(sizeof(char)*(strlen(yayinEvi)+1));
			kitaplar[i].yazarAdi=(char*)malloc(sizeof(char)*(strlen(yazarAdi)+1));
			kitaplar[i].yazarSoyadi=(char*)malloc(sizeof(char)*(strlen(yazarSoyadi)+1));
			strcpy(kitaplar[i].kitapAdi,kitapAdi);
			strcpy(kitaplar[i].yazarAdi,yazarAdi);
			strcpy(kitaplar[i].yazarSoyadi,yazarSoyadi);
			strcpy(kitaplar[i].yayinEvi,yayinEvi);
			kitaplar[i].sayfaSayisi=sayfaSayisi;
			break;
		}
	
	}

}	


void uyeleriAktar(kisiBilgileri *uyeListesi){
	FILE *uyeKayitlari;
	int i;
	char ad[20],soyad[20];
	
	uyeKayitlari=fopen("uyeListesi.txt","r");
	if(uyeKayitlari==NULL){
		fprintf(stderr,"Uye listesinde hata olustu.\n");
		exit(1);
	}
	
	while(!feof(uyeKayitlari)){
		for(i=0;i<MAX_KISI_SAYISI;i++){
			if(uyeListesi[i].kutuphaneID==0){
				fscanf(uyeKayitlari,"%s\t%s\t%d\t%d\t%d\n",ad,soyad,&uyeListesi[i].uyeYetkisi,&uyeListesi[i].kutuphaneID,&uyeListesi[i].sifre);
				uyeListesi[i].uyeAdi=(char*)malloc(sizeof(char)*(strlen(ad)+1));
				uyeListesi[i].uyeSoyadi=(char*)malloc(sizeof(char)*(strlen(soyad)+1));
				strcpy(uyeListesi[i].uyeAdi,ad);
				strcpy(uyeListesi[i].uyeSoyadi,soyad);
				break;	
			}
			
		}
	}
	fclose(uyeKayitlari);
}

void kitaplariAktar(kitapBilgileri *kitaplar){
	char kitapAdi[30],yazarAdi[30],yayinEvi[30],yazarSoyadi[30];
	FILE *kitapKayitlari;
	int i;
	
	kitapKayitlari=fopen("kitapListesi.txt","r");
	if(kitapKayitlari==NULL){
		fprintf(stderr,"Kitap listesine hata olustu.\n");
		exit(1);
	}
	
	while(!feof(kitapKayitlari)){
		for(i=0;i<MAX_KITAP_SAYISI;i++){
			if(kitaplar[i].sayfaSayisi==0){
				fscanf(kitapKayitlari,"%s\t%s\t%s\t%s\t%d\t%d\n",kitapAdi,yayinEvi,yazarAdi,yazarSoyadi,&kitaplar[i].kitapDurumu,&kitaplar[i].sayfaSayisi);
				kitaplar[i].kitapAdi=(char*)malloc(sizeof(char)*(strlen(kitapAdi)+1));
				kitaplar[i].yazarAdi=(char*)malloc(sizeof(char)*(strlen(yazarAdi)+1));
				kitaplar[i].yazarSoyadi=(char*)malloc(sizeof(char)*(strlen(yazarSoyadi)+1));
				kitaplar[i].yayinEvi=(char*)malloc(sizeof(char)*(strlen(yayinEvi)+1));
				strcpy(kitaplar[i].kitapAdi,kitapAdi);
				strcpy(kitaplar[i].yazarAdi,yazarAdi);
				strcpy(kitaplar[i].yazarSoyadi,yazarSoyadi);
				strcpy(kitaplar[i].yazarSoyadi,yayinEvi);
				break;
	
			}
		}	
	}
	fclose(kitapKayitlari);
}

void kitaplariKaydet(kitapBilgileri *kitaplar){
	FILE *kitapKayitlari;
	int i=0;
	
	kitapKayitlari= fopen("kitapListesi.txt","w");
	if(kitapKayitlari==NULL){
		fprintf(stderr,"Kitap listesine hata olustu.\n");
		exit(1);
	}
	
	while(i<MAX_KITAP_SAYISI && kitaplar[i].sayfaSayisi!=0){
		fprintf(kitapKayitlari,"%s\t%s\t%s\t%s\t%d\t%d\n",kitaplar[i].kitapAdi,kitaplar[i].yayinEvi,kitaplar[i].yazarAdi,kitaplar[i].yazarSoyadi,kitaplar[i].kitapDurumu,kitaplar[i].sayfaSayisi);
		i++;
	}
	fclose(kitapKayitlari);
}

void uyeleriKaydet(kisiBilgileri *uyeListesi){
	FILE *uyeKayitlari;
	int i=0;
	
	uyeKayitlari = fopen("uyeListesi.txt","w");
	if(uyeKayitlari==NULL){
		fprintf(stderr,"Uye listesinde hata olustu.\n");
		exit(1);
	}
	
	while(i<MAX_KISI_SAYISI && uyeListesi[i].kutuphaneID!=0){
		fprintf(uyeKayitlari,"%s\t%s\t%d\t%d\t%d\n",uyeListesi[i].uyeAdi,uyeListesi[i].uyeSoyadi,uyeListesi[i].uyeYetkisi,uyeListesi[i].kutuphaneID,uyeListesi[i].sifre);
		i++;
	}
	fclose(uyeKayitlari);	
}
	
		



// --------------- MAÝN --------------- //

int main(void){
	
	char ch;
	int giris;
	
	kitapBilgileri *kitaplar;
	kisiBilgileri *uyeListesi;
	uyeYetkiSeviyesi uyeYetkisi;
	kitaplar=(kitapBilgileri*)calloc(MAX_KITAP_SAYISI,sizeof(kitapBilgileri));
	uyeListesi=(kisiBilgileri*)calloc(MAX_KISI_SAYISI,sizeof(kisiBilgileri));
	
	
	
	// KAYIT OL / GÝRÝS YAP BÖLÜMÜ
	
	printf("\t\tKütüphane Sistemimize Hosgeldiniz\n");
	printf("1. Kayit olmak istiyorsaniz 'K'\n2. Giris yapmak istiyorsaniz 'G' 'yi tuslayiniz.");
	fflush(stdin);
	ch=getchar();
	
	if(ch=='K' || ch=='k'){
		
		giris = kayitOl(uyeListesi);
	}
	else if(ch=='G' || ch=='g'){
		
		giris = girisYap(uyeListesi);
		if(giris == -1){
			printf("Sifre Hatali...\n");
			exit(1);
		}
		else if(giris == -2){
			printf("Kullanici Bulunamadi...\n");
			exit(1);
		}
	}
	else{
		printf("Yanlis bir tuslama yaptiniz...Sistemden cikiliyor...\n");
		exit(1);
	}
	
	// UYE YETKÝ SEVÝYESÝ BELÝRLEME
	
	if(giris == 1){
		uyeYetkisi = calisan;
	}
	else{
		uyeYetkisi = ogrenci;
	}
	
	if(uyeYetkisi == ogrenci){
		do{
			printf("1.Kitaplari goruntulemek icin 'G' tusuna tiklayiniz.\n2.Kitap aramak icin 'A' tusuna tiklayiniz.\n3.Cikis yapmak icin 'Q' tusuna tiklayiniz:");
		    fflush(stdin);
		    ch = getchar();
		    switch(ch){
		    	case 'G':
		    	case 'g':
		    		kitaplariGoruntule(kitaplar);
		    		break;
		    	
				case 'A':
				case 'a':
				    kitapAra(kitaplar);
					break;
				case 'Q':
				case 'q':
				    kitaplariKaydet(kitaplar);
				    uyeleriKaydet(uyeListesi);
					printf("Sistemden cikis yapiliyor...");
					break;
				default:
				printf("Hatali bir tuslama yaptiniz...");
				break;			
			}
			
		}while(ch!='Q');
	}
	
	else{
		do{
			printf("1.Kitap eklemek icin 'E' tusuna basiniz.\n2.Uyeleri goruntulemek icin 'U' tusuna basiniz.\n3.Cikis yapmak icin 'Q' tusuna basiniz:");
			fflush(stdin);
		    ch = getchar();
			
			switch(ch){
				case 'E':
		    	case 'e':
		    		kitapEkle(kitaplar);
		    		break;
		    		
		    	case 'U':
		    	case 'u':
		    		uyeleriGoruntule(uyeListesi);
		    		break;	
		    	
				case 'Q':
		    	case 'q':
		    		kitaplariKaydet(kitaplar);
				    uyeleriKaydet(uyeListesi);
				    printf("Sistemden cikis yapiliyor...");
		    		break;	
		    	
			    default:
				printf("Hatali bir tuslama yaptiniz...\n");	
			}
			
			
		}while(ch != 'Q');
	}
	
	
	return 0;
}
