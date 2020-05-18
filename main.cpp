/*Melik KARACA 190757079 Bil.M�h.(�.�) C grubu 
Nesneye Y�nelik Programlama BIM-104-50-50-C Bahar 2020
PROJES� 1 Dr. ��r. �yesi G�l�ah T�M�KL� �ZYER*/
#include <iostream>
#include <string>     //metin karakter k�t�phanesi
#include <stdio.h> // STANDART G�RD� �IKTI K�T�PANES�
#include <stdlib.h>  // RANDOM SAYI KULLANMAK ���N
#include <time.h>    // RANDOMDA S�REKL� AYNI SAYI GELMEMES� ���N
using namespace std;
void array(int c);
void input(int a) //inputlar i�in alt fonksiyon
{
    if(a==1)
    cout<<"1 ile 5 arasi bir sayi giriniz:";//kullan�c� dan say� isteme kodu
    if(a==2)
    cout<<"Ge�ersiz bir giri� yapt�n�z.";   //kullan�c� yanl�� de�er girdi�inde uyar� mesaj�
    if(a==3)
    cout<<"May�n Patlad�. �zg�n�m Maalesef Kaybettiniz!\n"; //kullan�c� oyunu kazanmad���n da mesaj
    if(a==4)
    cout<<"Tebrikler Kazand�n�z!\n"; //kullan�c� oyunu kazand���nda mesaj�
}
void restart(int b)
{   char cevap;
	if(b==1)
	{
		cout<<"Yeniden oynamak ister misiniz? (Evet i�in e/E, Hay�r i�in h/H giriniz):";
		   cin>>cevap;
		   	if((cevap=='e')||(cevap=='E')){   //kullan�c� oyunu tekrar oynay�p oynamamak isteme durumunu kontrol etme
		        goto array();
		   }
	if(b==0){
		if((cevap=='h')||(cevap=='H')) //kullan�c� oyunu tekrar oynay�p oynamamak isteme durumunu kontrol etme
		return;
	}
  }
}
void array() //dizi,dizi �zerinde gezinde ve doldurma i�lemleri ve oyunu tekrar oynama durumu alt fonksiyonu
{
	  do //oyunu tekrar oynama ve di�er i�lemlerin tekrar� i�in do while d�ng�s� kulland�m.
	  {
		srand(time(0));//dizinin her seferinde farkl� de�er alma kodu
		char cevap,oyunMat[6][5]={}; //matris tan�mlad�m
		for(int k = 0; k<6; k++)
		{
			int j;
			for(int t = 0; t<5; t++)
			{
				oyunMat[k][t] = 'T';   //matrise 'T' karakteri yazma
			} 
			oyunMat[k][rand() % 5] = 'X';  //matrisin sat�r�na bir 'X' karakteri yazma
		}
		
		    int win = 1;
		    int x;                                 //kullan�c�d�n girdi�i say�
		for(int i=0;i<6;i++)
		{
			do{                            // her seferinde sat�r altlamak i�in do while d�ng�s�n� kulland�m.
			    input(1);                  //kullan�c� dan say� istemek i�in input fonksiyonun da mesaj �a��rma
			    cin>>x;
			   if((x<0,x>5))              //kullan�c� yanl�� girdi�in de kullan�c� uyarma kodu
			    {  
			         input(2);            //kullan�c� yanl�� de�er girdi�in de input fonksiyonun da mesaj �a��rma
			    }
			}while(x<0,x>5);               //kullan�c� da say� isteme d�ng�s�
			
			if(oyunMat[i][x-1]=='X')
				{
				input(3);                  //oyunu kazanmad���n da input fonksiyonun da mesaj �a��rma
				oyunMat[i][x-1] = 'P';    //may�n patlad���n da "P" yazma
				win = 0;
				break;
				}
				else
				{    
				oyunMat[i][x-1] = 'O';     //kullan�c�n�n girdi�i say�ya denk gelen sut�na O yazma komutu
				}
				   if(i+2>0&&i+2<7){          //alt sat�ra ge�me kodu
				    cout<<i+2<<". satira gectiniz."<<endl;
				}
		   }
		if(win)
		        input(4);                 //oyunu kazand���n da input fonksiyonun da mesaj �a��rma
		   for(int i=0;i<6;i++)
		    {
			for(int j=0;j<5;j++)
			{
			cout<<"\t"<<oyunMat[i][j];   //kazand�ktan sonra yaz�lan matris
			}
		    cout<<"\n";
		   }
		   restart(1);
	      else 
	      break;
	
	}while(true);
}                      //oyunu tekrar oynamak istedi�in de ve di�er i�lemleri do while d�ng�s�yle kontrol ettim.

int main(int argc, char** argv)
{
setlocale(LC_ALL, "Turkish"); //T�rk�e karakterleri yazma kodu 
   array();
    restart(1);            //function call
     return 0;           //program� sonland�rma
}
