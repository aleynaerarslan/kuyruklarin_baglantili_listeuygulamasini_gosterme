#include <stdio.h>
#include <stdlib.h>

//Aleyna ERARSLAN

struct node{   //struct(yapý) tanýmý yapýldý.
	int data;  //Bu yapý, her bir düðümün verisini (data) ve bir sonraki düðümün adresini (sonraki) tutmaktadýr.
	struct node*sonraki;  //pointer oluþturduk.
};
//düðümler
struct node*temp= NULL;  //temp geçici olarak kullanýlan bir iþaretçidir.
struct node*front= NULL; //kuyruktaki ilk düðümü tutar.
struct node*rear= NULL;  //kuyruktaki son düðümü tutar.

void elemanekle(int veri){
	struct node* eleman= (struct node*) malloc( sizeof (struct node));
	eleman ->data=veri;  //yeni eleman için dðüðüm oluþturulur ve deðeri atanýr.
	
	if(front==NULL){  //ilk düðüm boþ ise
		front=eleman;  //elemaný ilk düðüme atadýk
		front ->sonraki=front;  //elemaný sonrakine atadýk.
		rear=eleman;
		rear ->sonraki=NULL;
	}
	else if(front ->sonraki==front){ //kuyrukta tek düðüm var ise
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
	else{    //kuyruktan en üstekki elemaný çýkarmak için kullanýlýr.
		printf("%d elemani kuyruktan cikartildi",front ->data);
		temp=front ->sonraki;  //front iþaretçisi geçici bir iþaretçiye atanýr, front iþaretçisi için ayrýlan bellek alaný serbest býrakýlýr ve front iþaretçisi geçici iþaretçiye atanýr.
		free(front);
		front=temp;
	}
}

void yazdir(){
	system("cls");  // komutu, konsol ekranýný temizler ve yeni bir çýktý yazdýrmaya hazýr hale getirir.
	if(front==NULL)
	printf("kuyruk bostur\n");
	else{
		temp=front;  //ilk olarak geçici bir düðüm iþaretçisi olan temp, front iþaretçisine atanýr
		while(temp ->sonraki !=NULL)  //döngü temp düðümünün sonraki düðümü boþ olmadýðý sürece çalýþýr
		{
			printf("%d ",temp ->data);
			temp=temp ->sonraki; //her düðümün verisi ekrana yazdýrýlýr ve temp, sonraki düðüme hareket eder
		}
		printf("%d ",temp ->data);
	}
}


int main(int argc, char *argv[]) {
	
	int secim,sayi;
	while(1 )  //yapabileceði seçenekler kullanýcýya gösterilir.
	{
	printf("\nLutfen asagidaki islemlerden birini seciniz\n\n");
	printf("1-Ekleme\n");
	printf("2-Silme\n");
	printf("3-Goruntuleme\n");
	printf("2-Cikis\n\n");
	printf("Seciminiz:");
	scanf("%d",&secim);
	switch(secim)  //kullanýcýya seçim yapmasý için seçenekler sunulur.
	{
		case 1: 
		printf("Eklemek istediginiz degeri giriniz:");
		scanf("%d",&sayi);
		elemanekle(sayi); //eleman toplamak için yazýlan fonksiyonu çaðýrýr
		break;
		case 2:
		elemancikar(); //eleman çýkarmak için yazýlan fonksiyonu çaðýrýr
		break;
		case 3:
		yazdir();  //elemanlarý görüntülemek için yazýlan fonksiyonu çaðýrýr
		break;
		case 4: //çýkýþ
		return 0;
			
			
	}
	}
	
	
	return 0;
}
