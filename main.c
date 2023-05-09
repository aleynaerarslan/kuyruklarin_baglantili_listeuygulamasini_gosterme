#include <stdio.h>
#include <stdlib.h>

//Aleyna ERARSLAN

struct node{   //struct(yap�) tan�m� yap�ld�.
	int data;  //Bu yap�, her bir d���m�n verisini (data) ve bir sonraki d���m�n adresini (sonraki) tutmaktad�r.
	struct node*sonraki;  //pointer olu�turduk.
};
//d���mler
struct node*temp= NULL;  //temp ge�ici olarak kullan�lan bir i�aret�idir.
struct node*front= NULL; //kuyruktaki ilk d���m� tutar.
struct node*rear= NULL;  //kuyruktaki son d���m� tutar.

void elemanekle(int veri){
	struct node* eleman= (struct node*) malloc( sizeof (struct node));
	eleman ->data=veri;  //yeni eleman i�in d����m olu�turulur ve de�eri atan�r.
	
	if(front==NULL){  //ilk d���m bo� ise
		front=eleman;  //eleman� ilk d���me atad�k
		front ->sonraki=front;  //eleman� sonrakine atad�k.
		rear=eleman;
		rear ->sonraki=NULL;
	}
	else if(front ->sonraki==front){ //kuyrukta tek d���m var ise
		rear ->sonraki=eleman;
		rear=eleman;
		rear ->sonraki=NULL;
		front ->sonraki=rear;
	}
	else{
		rear ->sonraki=eleman;
		rear=eleman;
		rear ->sonraki=NULL;
	}
}

void elemancikar(){
	if(front==NULL)
	printf("kuyruk bostur\n");
	else{    //kuyruktan en �stekki eleman� ��karmak i�in kullan�l�r.
		printf("%d elemani kuyruktan cikartildi",front ->data);
		temp=front ->sonraki;  //front i�aret�isi ge�ici bir i�aret�iye atan�r, front i�aret�isi i�in ayr�lan bellek alan� serbest b�rak�l�r ve front i�aret�isi ge�ici i�aret�iye atan�r.
		free(front);
		front=temp;
	}
}

void yazdir(){
	system("cls");  // komutu, konsol ekran�n� temizler ve yeni bir ��kt� yazd�rmaya haz�r hale getirir.
	if(front==NULL)
	printf("kuyruk bostur\n");
	else{
		temp=front;  //ilk olarak ge�ici bir d���m i�aret�isi olan temp, front i�aret�isine atan�r
		while(temp ->sonraki !=NULL)  //d�ng� temp d���m�n�n sonraki d���m� bo� olmad��� s�rece �al���r
		{
			printf("%d ",temp ->data);
			temp=temp ->sonraki; //her d���m�n verisi ekrana yazd�r�l�r ve temp, sonraki d���me hareket eder
		}
		printf("%d ",temp ->data);
	}
}


int main(int argc, char *argv[]) {
	
	int secim,sayi;
	while(1 )  //yapabilece�i se�enekler kullan�c�ya g�sterilir.
	{
	printf("\nLutfen asagidaki islemlerden birini seciniz\n\n");
	printf("1-Ekleme\n");
	printf("2-Silme\n");
	printf("3-Goruntuleme\n");
	printf("2-Cikis\n\n");
	printf("Seciminiz:");
	scanf("%d",&secim);
	switch(secim)  //kullan�c�ya se�im yapmas� i�in se�enekler sunulur.
	{
		case 1: 
		printf("Eklemek istediginiz degeri giriniz:");
		scanf("%d",&sayi);
		elemanekle(sayi); //eleman toplamak i�in yaz�lan fonksiyonu �a��r�r
		break;
		case 2:
		elemancikar(); //eleman ��karmak i�in yaz�lan fonksiyonu �a��r�r
		break;
		case 3:
		yazdir();  //elemanlar� g�r�nt�lemek i�in yaz�lan fonksiyonu �a��r�r
		break;
		case 4: //��k��
		return 0;
			
			
	}
	}
	
	
	return 0;
}
