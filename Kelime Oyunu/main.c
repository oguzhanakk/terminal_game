#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

int main()
{
    int toplamSure=240;
    int Puan=6400;

   char cevap[20]="hazirim";
   char hazirMisin[20];
   char alinanCevaplar[50];
   char dogruCevaplar[30][30]={"ates","yazi","motel","kasko","taksit","evvela","madenci","dortkose","beyazesya","kabirazabi"};
   int secenek[20];
   int cevaplamaSuresi1;

   printf("Kelime Oyunu yarismamiza hosgeldiniz...\n\n");
   printf("10 sorumuz vardir. 4 harfli cevaplarla baslicaz 10 harflilerle bitiricez.\n4 dakika sureniz vardir.\n harf almak icin (1) yaziniz, cevap vermek icin (2) yaziniz.");
   wait(3);

   printf("\n\n(hazirim) yazmaniz ile yarisma baslicaktir..\n");
   scanf("%s",hazirMisin);
   if(strcmp(cevap,hazirMisin)==0) {
    system("CLS");
    printf("basliyoruz...\n\n");
   }
   else {
    printf("baslama amq cocugu.\n\n");
    return;
   }
    //1.soru baslangici
   printf("ilk sorumuz geliyor...\n\n");
   wait(2);
   printf("Tum insanlik icin yemek,barinma,korunma,isinma gibi konularda cigir acan bir kesif.\n");
   for(int i=0;i<4;i++) {
   printf("*"); }

    time_t start,end;
    time (&start);

    for(int i=0;i<4;i++) { // 1. soruuuuuu kismi

    printf("\n");
    scanf("%d",&secenek[i]);

   if(secenek[i] == 1){
    if(i==0)
    printf("**e*");

    if(i==1)
    printf("a*e*");

    if(i==2)
    printf("a*es");

    if(i==3) {
    printf("ates\n");
    printf("Ilk soruda hic puan kazanamadiniz.\n");
    Puan -= 100;
    printf("Puaniniz : %d\n",Puan);
    time (&end);
    printf ("\n%.0lf saniyeniz kaldi.\n",toplamSure-difftime(end,start));
    break;
    }

    Puan -= 100;
    continue;
   }

   if(secenek[i] == 2){
    time (&end);
    printf ("\n%.0lf saniyede sureyi durdurdunuz\n",toplamSure-difftime(end,start));
    printf("Cevabinizi alabilir miyim?\t");
    scanf("%s",alinanCevaplar);


        if(strcmp(alinanCevaplar,dogruCevaplar[0])==0) {
        printf("Tebrikler dogru bildiniz.\n2.soruya gecebiliriz.\n");
        printf("Puaniniz : %d\n",Puan);
        break;
    }
        if(strcmp(alinanCevaplar,dogruCevaplar[0])!=0) {
            printf("Yanlis bildiniz.\n\n");
            Puan -= 400;
            break;
        }
   }
}
    wait(3);

    //2.soru baslangici
    system("CLS");
    printf("Puaniniz : %d\n",Puan);
     printf("ikinci sorumuz geliyor...\n\n");
   wait(2);
   printf("Ilahi idarenin cizdigine inanilan yol.\n");
   for(int i=0;i<4;i++) {
   printf("*"); }

    time_t start2,end2;
    time (&start2);

  for(int i=0;i<4;i++) {  // 2. soruuuuuu kismi

    printf("\n");
    scanf("%d",&secenek[i]);

    if(secenek[i] == 1) {

    if(i==0)
    printf("***i");

    if(i==1)
    printf("**zi");

    if(i==2)
    printf("y*zi");

    if(i==3) {
    printf("yazi\n");
    printf("Ikinci soruda hic puan kazanamadiniz.");
    Puan -= 100;
    time (&end2);
    printf ("\n%.0lf saniyeniz kaldi.\n",toplamSure-difftime(end2,start2)-difftime(end,start));
    break;
    }

   Puan -= 100;
    continue;
   }

   if(secenek[i] == 2){
    time (&end2);
    printf ("\n%.0lf saniyede sureyi durdurdunuz\n",toplamSure-difftime(end2,start2)-difftime(end,start));
    printf("Cevabinizi alabilir miyim?\t");
    scanf("%s",alinanCevaplar);

        if(strcmp(alinanCevaplar,dogruCevaplar[1])==0) {
        printf("Tebrikler dogru bildiniz.\n3.soruya gecebiliriz.\n");
        break;
    }
        if(strcmp(alinanCevaplar,dogruCevaplar[1])!=0) {
            printf("Yanlis bildiniz.\n\n");
            break;
        }
   }
}

    wait(3);
 //3.soru baslangici
    system("CLS");
    printf("Puaniniz : %d\n",Puan);
     printf("Ucuncu sorumuz geliyor...\n\n");
   wait(2);
   printf("Ilk olarak kara yollarindaki konaklama tesisleri icin kullanilirken zamanla anlami genisleyen bir soz.\n");
   for(int i=0;i<5;i++) {
   printf("*"); }

    time_t start3,end3;
    time (&start3);

  for(int i=0;i<5;i++) {  // 3. soruuuuuu kismi

    printf("\n");
    scanf("%d",&secenek[i]);

   if(secenek[i] == 1){

   if(i==0)
    printf("m****");

   if(i==1)
    printf("m***l");

   if(i==2)
    printf("m*t*l");

   if(i==3)
    printf("mot*l");

    if(i==4) {
    printf("motel\n");
    printf("Ucuncu soruda hic puan kazanamadiniz.");
    Puan -= 100;
    time (&end3);
    printf ("\n%.0lf saniyeniz kaldi.\n",toplamSure-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    break;
    }

   Puan -= 100;
    continue;
   }

   if(secenek[i] == 2){
    time (&end3);
    printf ("\n%.0lf saniyede sureyi durdurdunuz\n",toplamSure-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    printf("Cevabinizi alabilir miyim?\t");
    scanf("%s",alinanCevaplar);

        if(strcmp(alinanCevaplar,dogruCevaplar[2])==0) {
        printf("Tebrikler dogru bildiniz.\n4.soruya gecebiliriz.\n");
        break;
    }
        if(strcmp(alinanCevaplar,dogruCevaplar[2])!=0) {
            printf("Yanlis bildiniz.\n\n");
            break;
        }
   }
}
wait(3);

//4.soru baslangici
    system("CLS");
    printf("Puaniniz : %d\n",Puan);
     printf("Dorduncu sorumuz geliyor...\n\n");
   wait(2);
   printf("Tasit sigortasi.\n");
   for(int i=0;i<5;i++) {
   printf("*"); }

    time_t start4,end4;
    time (&start4);

  for(int i=0;i<5;i++) {  // 4. soruuuuuu kismi

    printf("\n");
    scanf("%d",&secenek[i]);

   if(secenek[i] == 1){

    if(i==0)
    printf("**s**");

    if(i==1)
    printf("*as**");

    if(i==2)
    printf("*as*o");

    if(i==3)
    printf("*asko");

    if(i==4) {
    printf("kasko\n");
    printf("Dorduncu soruda hic puan kazanamadiniz.");
    Puan -= 100;
    time (&end4);
    printf ("\n%.0lf saniyeniz kaldi.\n",toplamSure-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    break;
    }

    Puan -= 100;
    continue;
   }

   if(secenek[i] == 2){
    time (&end4);
    printf ("\n%.0lf saniyede sureyi durdurdunuz\n",toplamSure-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    printf("Cevabinizi alabilir miyim?\t");
    scanf("%s",alinanCevaplar);

        if(strcmp(alinanCevaplar,dogruCevaplar[3])==0) {
        printf("Tebrikler dogru bildiniz.\n5.soruya gecebiliriz.\n");
        break;
    }
        if(strcmp(alinanCevaplar,dogruCevaplar[3])!=0) {
            printf("Yanlis bildiniz.\n\n");
            break;
        }
   }
}
wait(3);

//5.soru baslangici
    system("CLS");
    printf("Puaniniz : %d\n",Puan);
     printf("Besinci sorumuz geliyor...\n\n");
   wait(2);
   printf("Odence periyotlarindan her biri.\n");
   for(int i=0;i<6;i++) {
   printf("*"); }

    time_t start5,end5;
    time (&start5);

  for(int i=0;i<6;i++) {  // 5. soruuuuuu kismi

    printf("\n");
    scanf("%d",&secenek[i]);

   if(secenek[i] == 1) {

    if(i==0)
    printf("****i*");

    if(i==1)
    printf("t***i*");

    if(i==2)
    printf("t**si*");

    if(i==3)
    printf("ta*si*");

    if(i==4)
    printf("ta*sit");

    if(i==5) {
    printf("taksit\n");
    printf("Besinci soruda hic puan kazanamadiniz.");
    Puan -= 100;
    time (&end5);
    printf ("\n%.0lf saniyeniz kaldi.\n",toplamSure-difftime(end5,start5)-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    break;
    }

    Puan -= 100;
    continue;
   }

   if(secenek[i] == 2){
    time (&end5);
    printf ("\n%.0lf saniyede sureyi durdurdunuz\n",toplamSure-difftime(end5,start5)-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    printf("Cevabinizi alabilir miyim?\t");
    scanf("%s",alinanCevaplar);

        if(strcmp(alinanCevaplar,dogruCevaplar[4])==0) {
        printf("Tebrikler dogru bildiniz.\n6.soruya gecebiliriz.\n");
        break;
    }
        if(strcmp(alinanCevaplar,dogruCevaplar[4])!=0) {
            printf("Yanlis bildiniz.\n\n");
            break;
        }
   }
}
wait(3);

//6.soru baslangici
    system("CLS");
    printf("Puaniniz : %d\n",Puan);
     printf("Altinci sorumuz geliyor...\n\n");
   wait(2);
   printf("Her seyden once,ilkin anlamindaki sozcuk.\n");
   for(int i=0;i<6;i++) {
   printf("*"); }

    time_t start6,end6;
    time (&start6);

  for(int i=0;i<6;i++) {  // 6. soruuuuuu kismi

    printf("\n");
    scanf("%d",&secenek[i]);

    if(secenek[i] == 1){

    if(i==0)
    printf("*v****");

    if(i==1)
    printf("*vv***");

    if(i==2)
    printf("*vv**a");

    if(i==3)
    printf("*vve*a");

    if(i==4)
    printf("evve*a");

    if(i==5) {
    printf("evvela\n");
    printf("Altinci soruda hic puan kazanamadiniz.");
    Puan -= 100;
    time (&end6);
    printf ("\n%.0lf saniyeniz kaldi.\n",toplamSure-difftime(end6,start6)-difftime(end5,start5)-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    break;
    }

    Puan -= 100;
    continue;
   }

   if(secenek[i] == 2){
    time (&end6);
    printf ("\n%.0lf saniyede sureyi durdurdunuz\n",toplamSure-difftime(end6,start6)-difftime(end5,start5)-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    printf("Cevabinizi alabilir miyim?\t");
    scanf("%s",alinanCevaplar);

        if(strcmp(alinanCevaplar,dogruCevaplar[5])==0) {
        printf("Tebrikler dogru bildiniz.\n7.soruya gecebiliriz.\n");
        break;
    }
        if(strcmp(alinanCevaplar,dogruCevaplar[5])!=0) {
            printf("Yanlis bildiniz.\n\n");
            break;
        }
   }
}
wait(3);

//7.soru baslangici
    system("CLS");
    printf("Puaniniz : %d\n",Puan);
     printf("Yedinci sorumuz geliyor...\n\n");
   wait(2);
   printf("Yer alti ocaklarinda ve isletmelerinde calisan kisi.\n");
   for(int i=0;i<7;i++) {
   printf("*"); }

    time_t start7,end7;
    time (&start7);

  for(int i=0;i<7;i++) {  // 7. soruuuuuu kismi

    printf("\n");
    scanf("%d",&secenek[i]);

   if(secenek[i] == 1){

    if(i==0)
    printf("****n**");

    if(i==1)
    printf("*a**n**");

    if(i==2)
    printf("*a**nc*");

    if(i==3)
    printf("*a*enc*");

    if(i==4)
    printf("*a*enci");

    if(i==5)
    printf("ma*enci");

    if(i==6) {
    printf("madenci\n");
    printf("Yedinci soruda hic puan kazanamadiniz.");
    Puan -= 100;
    time (&end7);
    printf ("\n%.0lf saniyeniz kaldi.\n",toplamSure-difftime(end7,start7)-difftime(end6,start6)-difftime(end5,start5)-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    break;
    }

    Puan -= 100;
    continue;
   }

   if(secenek[i] == 2){
    time (&end7);
    printf ("\n%.0lf saniyede sureyi durdurdunuz\n",toplamSure-difftime(end7,start7)-difftime(end6,start6)-difftime(end5,start5)-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    printf("Cevabinizi alabilir miyim?\t");
    scanf("%s",alinanCevaplar);

        if(strcmp(alinanCevaplar,dogruCevaplar[6])==0) {
        printf("Tebrikler dogru bildiniz.\n8.soruya gecebiliriz.\n");
        break;
    }
        if(strcmp(alinanCevaplar,dogruCevaplar[6])!=0) {
            printf("Yanlis bildiniz.\n\n");
            break;
        }
   }
}
wait(3);

//8.soru baslangici
    system("CLS");
    printf("Puaniniz : %d\n",Puan);
     printf("Sekizinci sorumuz geliyor...\n\n");
   wait(2);
   printf("Kare biciminde olan.\n");
   for(int i=0;i<8;i++) {
   printf("*"); }

    time_t start8,end8;
    time (&start8);

  for(int i=0;i<8;i++) {  // 8. soruuuuuu kismi

    printf("\n");
    scanf("%d",&secenek[i]);

   if(secenek[i] == 1){

    if(i==0)
    printf("*******e");

    if(i==1)
    printf("******se");

    if(i==2)
    printf("*o****se");

    if(i==3)
    printf("*o*t**se");

    if(i==4)
    printf("*o*tk*se");

    if(i==5)
    printf("do*tk*se");

    if(i==6)
    printf("do*tkose");

    if(i==7) {
    printf("dortkose\n");
    printf("Sekizinci soruda hic puan kazanamadiniz.");
    Puan -= 100;
    time (&end8);
    printf ("\n%.0lf saniyeniz kaldi.\n",toplamSure-difftime(end8,start8)-difftime(end7,start7)-difftime(end6,start6)-difftime(end5,start5)-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    break;
   }

    Puan -= 100;
    continue;
   }

   if(secenek[i] == 2){
    time (&end8);
    printf ("\n%.0lf saniyede sureyi durdurdunuz\n",toplamSure-difftime(end8,start8)-difftime(end7,start7)-difftime(end6,start6)-difftime(end5,start5)-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    printf("Cevabinizi alabilir miyim?\t");
    scanf("%s",alinanCevaplar);

        if(strcmp(alinanCevaplar,dogruCevaplar[7])==0) {
        printf("Tebrikler dogru bildiniz.\n9.soruya gecebiliriz.\n");
        break;
    }
        if(strcmp(alinanCevaplar,dogruCevaplar[7])!=0) {
            printf("Yanlis bildiniz.\n\n");
            break;
        }
   }
}
wait(3);

//9.soru baslangici
    system("CLS");
    printf("Puaniniz : %d\n",Puan);
     printf("Dokuzuncu sorumuz geliyor...\n\n");
   wait(2);
   printf("Mutfak ve banyoda kullanilan bazi ev aletlerinin genel adi.\n");
   for(int i=0;i<9;i++) {
   printf("*"); }

    time_t start9,end9;
    time (&start9);

  for(int i=0;i<9;i++) {  // 9. soruuuuuu kismi

    printf("\n");
    scanf("%d",&secenek[i]);

   if(secenek[i] == 1){

    if(i==0)
    printf("********a");

    if(i==1)
    printf("*e******a");

    if(i==2)
    printf("*e****s*a");

    if(i==3)
    printf("*e*a**s*a");

    if(i==4)
    printf("*eya**s*a");

    if(i==5)
    printf("*eya*es*a");

    if(i==6)
    printf("beya*es*a");

    if(i==7)
    printf("beya*esya");

    if(i==8) {
    printf("beyazesya\n");
    printf("Dokuzuncu soruda hic puan kazanamadiniz.");
    Puan -= 100;
    time (&end9);
    printf ("\n%.0lf saniyeniz kaldi.\n",toplamSure-difftime(end9,start9)-difftime(end8,start8)-difftime(end7,start7)-difftime(end6,start6)-difftime(end5,start5)-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    break;
   }

    Puan -= 100;
    continue;
   }

   if(secenek[i] == 2){
    time (&end9);
    printf ("\n%.0lf saniyede sureyi durdurdunuz\n",toplamSure-difftime(end9,start9)-difftime(end8,start8)-difftime(end7,start7)-difftime(end6,start6)-difftime(end5,start5)-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    printf("Cevabinizi alabilir miyim?\t");
    scanf("%s",alinanCevaplar);

        if(strcmp(alinanCevaplar,dogruCevaplar[8])==0) {
        printf("Tebrikler dogru bildiniz.\nson soruya gecebiliriz.\n");
        break;
    }
        if(strcmp(alinanCevaplar,dogruCevaplar[8])!=0) {
            printf("Yanlis bildiniz.\n\n");
            break;
        }
   }
}
wait(3);

//10.soru baslangici
    system("CLS");
    printf("Puaniniz : %d\n",Puan);
     printf("Son sorumuz geliyor...\n\n");
   wait(2);
   printf("Isilam inancina gore oldukten sonra mezarda cekilicek eziyet.\n");
   for(int i=0;i<10;i++) {
   printf("*"); }

    time_t start10,end10;
    time (&start10);

  for(int i=0;i<10;i++) {  // 10. soruuuuuu kismi

    printf("\n");
    scanf("%d",&secenek[i]);

    if(secenek[i] == 1){

    if(i==0)
    printf("*a********");

    if(i==1)
    printf("*a*******i");

    if(i==2)
    printf("*a**r****i");

    if(i==3)
    printf("*a**r*z**i");

    if(i==4)
    printf("*a**r*z*bi");

    if(i==5)
    printf("*ab*r*z*bi");

    if(i==6)
    printf("*ab*raz*bi");

    if(i==7)
    printf("*ab*razabi");

    if(i==8)
    printf("*abirazabi");

    if(i==9) {
    printf("kabirazabi\n");
    printf("Son soruda hic puan kazanamadiniz.");
    Puan -= 100;
    time (&end10);
    printf ("\n%.0lf saniyeniz kaldi.\n",toplamSure-difftime(end10,start10)-difftime(end9,start9)-difftime(end8,start8)-difftime(end7,start7)-difftime(end6,start6)-difftime(end5,start5)-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    break;
   }

    Puan -= 100;
    continue;
   }

   if(secenek[i] == 2){
    time (&end10);
    printf ("\n%.0lf saniyede sureyi durdurdunuz\n",toplamSure-difftime(end10,start10)-difftime(end9,start9)-difftime(end8,start8)-difftime(end7,start7)-difftime(end6,start6)-difftime(end5,start5)-difftime(end4,start4)-difftime(end3,start3)-difftime(end2,start2)-difftime(end,start));
    printf("Cevabinizi alabilir miyim?\t");
    scanf("%s",alinanCevaplar);

        if(strcmp(alinanCevaplar,dogruCevaplar[9])==0) {
        printf("Tebrikler dogru bildiniz.\nyarisma bitmistir.\n");
        break;
    }
        if(strcmp(alinanCevaplar,dogruCevaplar[9])!=0) {
            printf("Yanlis bildiniz.\n\n");
            break;
        }
   }
}
wait(3);
system("CLS");
printf("Yarismayi %d puanla bitirdiniz..\n\n\n",Puan);
}
