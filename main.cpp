/*Melik KARACA 190757079 Bil.Müh.(Ý.Ö) C grubu 
Nesneye Yönelik Programlama BIM-104-50-50-C Bahar 2020
PROJESÝ 1 Dr. Öðr. Üyesi Gülþah TÜMÜKLÜ ÖZYER*/
#include <iostream>
#include <string>     //metin karakter kütüphanesi
#include <stdio.h> // STANDART GÝRDÝ ÇIKTI KÜTÜPANESÝ
#include <stdlib.h>  // RANDOM SAYI KULLANMAK ÝÇÝN
#include <time.h>    // RANDOMDA SÜREKLÝ AYNI SAYI GELMEMESÝ ÝÇÝN
using namespace std;
void array(int c);
void input(int a) //inputlar için alt fonksiyon
{
    if(a==1)
    cout<<"1 ile 5 arasi bir sayi giriniz:";//kullanýcý dan sayý isteme kodu
    if(a==2)
    cout<<"Geçersiz bir giriþ yaptýnýz.";   //kullanýcý yanlýþ deðer girdiðinde uyarý mesajý
    if(a==3)
    cout<<"Mayýn Patladý. Üzgünüm Maalesef Kaybettiniz!\n"; //kullanýcý oyunu kazanmadýðýn da mesaj
    if(a==4)
    cout<<"Tebrikler Kazandýnýz!\n"; //kullanýcý oyunu kazandýðýnda mesajý
}
void restart(int b)
{   char cevap;
	if(b==1)
	{
		cout<<"Yeniden oynamak ister misiniz? (Evet için e/E, Hayýr için h/H giriniz):";
		   cin>>cevap;
		   	if((cevap=='e')||(cevap=='E')){   //kullanýcý oyunu tekrar oynayýp oynamamak isteme durumunu kontrol etme
		        goto array();
		   }
	if(b==0){
		if((cevap=='h')||(cevap=='H')) //kullanýcý oyunu tekrar oynayýp oynamamak isteme durumunu kontrol etme
		return;
	}
  }
}
void array() //dizi,dizi üzerinde gezinde ve doldurma iþlemleri ve oyunu tekrar oynama durumu alt fonksiyonu
{
	  do //oyunu tekrar oynama ve diðer iþlemlerin tekrarý için do while döngüsü kullandým.
	  {
		srand(time(0));//dizinin her seferinde farklý deðer alma kodu
		char cevap,oyunMat[6][5]={}; //matris tanýmladým
		for(int k = 0; k<6; k++)
		{
			int j;
			for(int t = 0; t<5; t++)
			{
				oyunMat[k][t] = 'T';   //matrise 'T' karakteri yazma
			} 
			oyunMat[k][rand() % 5] = 'X';  //matrisin satýrýna bir 'X' karakteri yazma
		}
		
		    int win = 1;
		    int x;                                 //kullanýcýdýn girdiði sayý
		for(int i=0;i<6;i++)
		{
			do{                            // her seferinde satýr altlamak için do while döngüsünü kullandým.
			    input(1);                  //kullanýcý dan sayý istemek için input fonksiyonun da mesaj çaðýrma
			    cin>>x;
			   if((x<0,x>5))              //kullanýcý yanlýþ girdiðin de kullanýcý uyarma kodu
			    {  
			         input(2);            //kullanýcý yanlýþ deðer girdiðin de input fonksiyonun da mesaj çaðýrma
			    }
			}while(x<0,x>5);               //kullanýcý da sayý isteme döngüsü
			
			if(oyunMat[i][x-1]=='X')
				{
				input(3);                  //oyunu kazanmadýðýn da input fonksiyonun da mesaj çaðýrma
				oyunMat[i][x-1] = 'P';    //mayýn patladýðýn da "P" yazma
				win = 0;
				break;
				}
				else
				{    
				oyunMat[i][x-1] = 'O';     //kullanýcýnýn girdiði sayýya denk gelen sutüna O yazma komutu
				}
				   if(i+2>0&&i+2<7){          //alt satýra geçme kodu
				    cout<<i+2<<". satira gectiniz."<<endl;
				}
		   }
		if(win)
		        input(4);                 //oyunu kazandýðýn da input fonksiyonun da mesaj çaðýrma
		   for(int i=0;i<6;i++)
		    {
			for(int j=0;j<5;j++)
			{
			cout<<"\t"<<oyunMat[i][j];   //kazandýktan sonra yazýlan matris
			}
		    cout<<"\n";
		   }
		   restart(1);
	      else 
	      break;
	
	}while(true);
}                      //oyunu tekrar oynamak istediðin de ve diðer iþlemleri do while döngüsüyle kontrol ettim.

int main(int argc, char** argv)
{
setlocale(LC_ALL, "Turkish"); //Türkçe karakterleri yazma kodu 
   array();
    restart(1);            //function call
     return 0;           //programý sonlandýrma
}
