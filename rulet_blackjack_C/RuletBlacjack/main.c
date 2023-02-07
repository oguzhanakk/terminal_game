#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

int ruletOyunu (int GelenBakiye) {

    int harcananPara;
    int secenek;
    int gelenSayi;

    printf("Kac para oynayacaginizi yaziniz: ");
    scanf("%d",&harcananPara);

    while(1){
        if(harcananPara<5){
            printf("\nEn az 5 tl oynanmaktadir.\n");
            printf("Kac para oynayacaginizi yaziniz: ");
            scanf("%d",&harcananPara);
        }
        else {
            break;
        }
    }

    while(harcananPara>GelenBakiye || harcananPara<=0) {
        printf("\nBizi mi kopariyosun birader duzgun gir: ");
        scanf("%d",&harcananPara);
    }

    GelenBakiye = GelenBakiye - harcananPara;

    printf("\nSu an ki bakiyeniz : %d \n\n",GelenBakiye);

    printf("3 kati: 1-12(1) 13-24(2) 25-36(3) --- 2 kati: 1-18(4) 19-36(5) \n");
    printf("Yukarida seceneklerin numaralari ve oranlari verilmistir istediginiz sececegi yaziniz:");
    scanf("%d",&secenek);

    if(secenek<1 || secenek > 5) {
        return GelenBakiye;
    }

    printf("\nTop atiliyor lutfen bekleyiniz...\n");

    wait(3);

    srand(time(NULL));
    gelenSayi = 1 + rand() % 36;
    printf("\nGelen sayi : %d\n\n",gelenSayi);

   if(gelenSayi>0 && gelenSayi<13 && secenek == 1){
        GelenBakiye = GelenBakiye + (3*harcananPara);
   }
   if(gelenSayi>12 && gelenSayi<25 && secenek == 2) {
        GelenBakiye = GelenBakiye + (3*harcananPara);
   }
   if(gelenSayi>24 && gelenSayi<37 && secenek == 3){
        GelenBakiye = GelenBakiye + (3*harcananPara);
   }
   if(gelenSayi>0 && gelenSayi<19 && secenek == 4) {
         GelenBakiye = GelenBakiye + (2*harcananPara);
   }
   if(gelenSayi>18 && gelenSayi<37 && secenek == 5) {
         GelenBakiye = GelenBakiye + (2*harcananPara);
   }
   return GelenBakiye;
}

int blackJackOyunu(int GelenBakiye) {

    int harcananPara;
    int cekilenKartlar[10];
    int kasaninKartlari[10];
    int cevaplar[10];
    int toplamBizim=0;
    int toplamKasanin=0;

    srand(time(0));

    printf("Kac para oynayacaginizi yaziniz: ");
    scanf("%d",&harcananPara);

    while(1){
        if(harcananPara<5){
            printf("\nEn az 5 tl oynanmaktadir.\n");
            printf("Kac para oynayacaginizi yaziniz: ");
            scanf("%d",&harcananPara);
        }
        else {
            break;
        }
    }

    while(harcananPara>GelenBakiye || harcananPara<=0) {
        printf("\nBizi mi kopariyosun birader duzgun gir: ");
        scanf("%d",&harcananPara);
    }

    GelenBakiye = GelenBakiye - harcananPara;

    printf("\nSu an ki bakiyeniz : %d \n\n",GelenBakiye);

     for (int i=0;i<2;i++) { // Formalite kismi... (2 kart bana 1 kart kasaya)

    if(i==0) {
        cekilenKartlar[i] = 1 + rand() % 11 ;
    }
    if(i==1) { //2. kartta 11 çekilemez.
        cekilenKartlar[i] = 1 + rand() % 10 ;
    }
    printf("%d. Kartiniz cekiliyor...\n",i+1);
    wait(3);
    printf("Cektiginiz %d. kart : %d\n\n",i+1,cekilenKartlar[i]);

    if(i==0) {
    kasaninKartlari[0] = 1 + rand() % 11;
    toplamKasanin += kasaninKartlari[i];
    printf("Kasa kendine %d. karti cekiyor...\n",i+1);
    wait(3);
    printf("Kasanin %d. cektigi kart : %d\n\n",i+1,kasaninKartlari[0]);
    }

    toplamBizim += cekilenKartlar[i];

    if(i==0) {
        continue;
    }
    printf("Elinizin Toplami : %d\n\n",toplamBizim);

    if(toplamBizim == 21) { //Eline blackjack gelirse 3 kati para veriyor. hadi iyisin.
        printf("Helal amq blackjack geldi.\n");
        return GelenBakiye + (3*harcananPara);
    }
     }

     int i=0;
     while(1) { // Oyun kismi
        printf("Yeni kart cekmek ister misiniz ? Evetse(1) Hayirsa(2)'ye basiniz: ");
        scanf("%d",&cevaplar[i]);

        if(cevaplar[i] == 2) { // kasanin oynadigi kisim.
            wait(3);
            system("CLS");
            printf("Elinizin toplami : %d",toplamBizim);
            printf("\n\nKasanin ilk cektigi kart : (%d) idi.",kasaninKartlari[0]);
            printf("\nKasa kart cekmeye basliyor...\n\n");

            int j=1;
            while(1) {
            kasaninKartlari[j] = 1 + rand() % 10;
            toplamKasanin += kasaninKartlari[j];
            printf("Kasa kendine %d. karti cekiyor...\n",j+1);
            wait(3);
            printf("Kasanin %d. cektigi kart : %d\n",j+1,kasaninKartlari[j]);
            printf("Kasanin eli toplami : %d\n\n",toplamKasanin);
            j++;

            if(toplamKasanin>=17 && toplamKasanin<=21) {
                break;
            }
            if(toplamKasanin>21) {
                wait(3);
                system("CLS");
                printf("Kasa batmistir tebrikler...\n\n\n");
                return GelenBakiye + (2*harcananPara);
                }
            }
            break;
        }

        if(cevaplar[i] == 1) { //Kisinin kart seçmeye devam ettigi kisim.
        cekilenKartlar[i+2] = 1 + rand() % 10;
        toplamBizim += cekilenKartlar[i+2];
        printf("\n%d. Kartiniz cekiliyor...\n",i+3);
        wait(3);
        printf("Cektiginiz %d. kart : %d\n",i+3,cekilenKartlar[i+2]);
        printf("Elinizin toplami : %d\n\n",toplamBizim);

        if(toplamBizim > 21) {
            wait(3);
            system("CLS");
            printf("Elinizin toplami : %d\n\n",toplamBizim);
            printf("Battiniz Gecmis olsun.\n");
            return GelenBakiye;
        }
        i = i+1;
        }
    }
    if(toplamBizim > toplamKasanin) {
        wait(4);
        system("CLS");
        printf("Tebrikler eliniz kasadan buyuk kazandiniz.\n");
        return GelenBakiye + (2*harcananPara);
    }
    if(toplamBizim < toplamKasanin) {
        wait(4);
        system("CLS");
        printf("Kasani eli daha buyuk yenildiniz.\n");
        return GelenBakiye;
    }
    if(toplamBizim == toplamKasanin) {
        wait(4);
        system("CLS");
        printf("Berabere bitmistir para iade edilecektir.\n");
        return GelenBakiye+harcananPara;
    }
}

//---------------------------------------Mainnnn ustu gereksiz
int main()
{
    int r=0; // r=1 1. kullanici girdi demek. r=2 2.kullanici demek Parayi hangi kullaniciya eklicegimizi anlamak icin.

    int kullaniciBirParasi=0,kullaniciIkiParasi=0,kullaniciUcParasi=0;

    int a;
    int asilBakiye;
    int oyunSonrasiBakiyeler[20];
    int kullaniciCevaplari[20];
    char kullaniciIsmi[20];

    char alinanKullanici[50][20];
    char alinanSifre[50][20];
    int alinanPara[50];

    char KullaniciDeneme[50];
    char SifreDeneme[50];

    //------------------------------------- kullanici kismi

    FILE *dosya;

    int secim;

    while (1) {

    printf("Uyelik mi olusturucaksiniz(1) , Giris mi yapicaksiniz(2) ,Cikmak icin (3)'e basiniz :\n");
    scanf("%d",&secim);

    int i=0;
//----------------------
    if(secim == 1) { // Hesap olusturma

    dosya = fopen("Kullanici Bilgileri.txt","a");

    char KullaniciAdi[50][50];
    char Sifre[50][50];

    printf("\nKullanici adinizi giriniz: ");
    scanf("%s",KullaniciAdi[i]);

    while(1) {
    if(strlen(KullaniciAdi) < 7) {
        printf("Kullanici adiniz 7 karakterden kisadir lutfen tekrar giriniz.\n\n");
         printf("Kullanici adinizi tekrar giriniz: ");
         scanf("%s",KullaniciAdi[i]);
    }
    else {
        break;
    }
    }
     int BaslangicParasi;

    printf("Sifrenizi giriniz: ");
    scanf("%s",Sifre[i]);

    printf("Baslangicta yatirmak istediginiz parayi giriniz: ");
    scanf("%d",&BaslangicParasi);
    printf("\n");

    fprintf(dosya,"%s\n",KullaniciAdi[i]);
    fprintf(dosya,"%s\n\n",Sifre[i]);
    fclose(dosya);

    FILE *Dosya2;

    Dosya2 = fopen("Para bilgileri.txt","a");

    fprintf(Dosya2,"%d\n",BaslangicParasi);

    exit(0);
    i++;
    }
//---------------------
   if(secim == 2) { // Hesap Giris yapmaaaa

    dosya = fopen("Kullanici Bilgileri.txt","r");

    int a=0;
    int j=0;

    while(!feof(dosya)) {
    fscanf(dosya,"%s %s",alinanKullanici[a],alinanSifre[a]);
    a++;  // arttirmana gerek yok çünkü 0'i alinca zaten kendisi 1'e geçiyor.
    }

    for(int i=0;i<a-1;i++) { // kullanici adi sifreleri bastirma
        printf("\nKullanici Adi: %s\nSifre: %s\n",alinanKullanici[i],alinanSifre[i]);
    }

    printf("\nkullanici adinizi tekrar giriniz: ");
    scanf("%s",KullaniciDeneme);

    printf("sifrenizi tekrar giriniz: ");
    scanf("%s",SifreDeneme);

    for (j;j<30;j++) {
    if((strcmp(alinanKullanici[j],KullaniciDeneme) == 0 ) && (strcmp(alinanSifre[j],SifreDeneme) == 0)){
        printf("\nHosgeldiniz %s.\n",KullaniciDeneme);

        if(strcmp(KullaniciDeneme,"Oguzhanakk10") == 0) { //artislik kismi
            printf("\nKral baya ozlettin kendini...\n");
        }
        break;
    }
  }
if (j>29) { //30'a kadar j cikar dogruyu bulamazsa demekki j>30 olucak.
    printf("Kullanici adi veya sifrenizi yanlis girdiniz. Tekrar deneyiniz.\n\n");
}

if (j<29) {
    break;
}
}

if (secim == 3) {
    exit(0);
}

if (secim > 3 || secim < 1) {
    printf("\nKomik misin kanka.\n\n");
    getch();
}
    }
    fclose(dosya);

    wait(3);
    system("CLS");

 //--------------------------------------------------------------------------------------- ust taraf kullanici adi kismi
    int alinanParaBakiyeIcin[50];

    FILE *Dosya2;

        int secenek,eklenicekPara=0; //--- Kayitli hesaba para ekleme

    printf("Hesaba para eklicekseniz (1) yaziniz: ");
    scanf("%d",&secenek);

    if(secenek == 1) {
        printf("\nKac para ekliceginizi giriniz: ");
        scanf("%d",&eklenicekPara);
    }

      if(strcmp(KullaniciDeneme,alinanKullanici[0]) == 0) { // 1. kullanici girdiyse

            Dosya2 = fopen("Para bilgileri.txt","r");  //ilk parayi alma
            fscanf(Dosya2,"%d",&alinanParaBakiyeIcin[0]);
            asilBakiye = alinanParaBakiyeIcin[0];
            asilBakiye += eklenicekPara;
            printf("\nBakiyeniz : %d\n",asilBakiye);

            r=1;
        }

        if(strcmp(KullaniciDeneme,alinanKullanici[1]) == 0) { // 2. kullanici girdiyse

            Dosya2 = fopen("Para bilgileri.txt","r");
            fscanf(Dosya2,"%d",&alinanParaBakiyeIcin[0]);
            fscanf(Dosya2,"%d",&alinanParaBakiyeIcin[1]);
            asilBakiye = alinanParaBakiyeIcin[1];
            asilBakiye += eklenicekPara;
            printf("\nBakiyeniz : %d\n",asilBakiye);

            r=2;
        }

         if(strcmp(KullaniciDeneme,alinanKullanici[2]) == 0) { // 3. kullanici girdiyse

            Dosya2 = fopen("Para bilgileri.txt","r");
            fscanf(Dosya2,"%d",&alinanParaBakiyeIcin[0]);
            fscanf(Dosya2,"%d",&alinanParaBakiyeIcin[1]);
            fscanf(Dosya2,"%d",&alinanParaBakiyeIcin[2]);
            asilBakiye = alinanParaBakiyeIcin[2];
            asilBakiye += eklenicekPara;
            printf("\n2Bakiyeniz : %d\n",asilBakiye);

            r=3;
        }

    for(int i=1;i<100;i++) { //For dongusu

    printf("\nRulet mi oynicaksiniz , BlackJack mi oynicaksiniz ? Ruletse (1) BlackJack'se (2)(Cikmak Icin(3)): ");
    scanf("%d",&a);

    if(a==3)  { //oynamak istemezse
        printf("\nYine bekleriz...\n\n");
        break;
    }

    if(a<1 || a>2 && a!=3) { //dalga gecerse
        printf("\nBirader isimiz gucumuz var git baska yerde eglen...\n\n\n");
        return;
    }
    wait(3);
    system("CLS");

    //-------------------------------------------------Rulet kismi

    if(a==1) { // Rulet isterse oto kisim
        oyunSonrasiBakiyeler[0] = asilBakiye;

        oyunSonrasiBakiyeler[i] = ruletOyunu(oyunSonrasiBakiyeler[i-1]);
        printf("Yeni Bakiyeniz : %d\n\n",oyunSonrasiBakiyeler[i]);

        if(oyunSonrasiBakiyeler[i] == 0) {
        wait(2);
        printf("Paraniz bitmistir , lutfen siteyi bastan acip bir daha yukleme yapiniz\n\n\n\n\n\n");
    }

    if(r==1) { //1. kullanici oyundaysa onun parasini degistirmen digerlerini sabitlemen lazim.

        Dosya2 = fopen("Para bilgileri.txt","r");
        fscanf(Dosya2,"%d %d %d",&kullaniciBirParasi,&kullaniciIkiParasi,&kullaniciUcParasi);
        fclose(Dosya2);

        Dosya2 = fopen("Para bilgileri.txt","w");
        fprintf(Dosya2,"%d\n%d\n%d",oyunSonrasiBakiyeler[i],kullaniciIkiParasi,kullaniciUcParasi);
        fclose(Dosya2);

        if(oyunSonrasiBakiyeler[i] == 0)
            return;
    }

    if(r==2) { //2. kullanici oyundaysa onun parasini degistirmen digerlerini sabitlemen lazim.

        Dosya2 = fopen("Para bilgileri.txt","r");
        fscanf(Dosya2,"%d %d %d",&kullaniciBirParasi,&kullaniciIkiParasi,&kullaniciUcParasi);
        fclose(Dosya2);

        Dosya2 = fopen("Para bilgileri.txt","w");
        fprintf(Dosya2,"%d\n%d\n%d",kullaniciBirParasi,oyunSonrasiBakiyeler[i],kullaniciUcParasi);
        fclose(Dosya2);

        if(oyunSonrasiBakiyeler[i] == 0)
            return;
    }

    if(r==3) { //3. kullanici oyundaysa onun parasini degistirmen digerlerini sabitlemen lazim.

        Dosya2 = fopen("Para bilgileri.txt","r");
        fscanf(Dosya2,"%d %d %d",&kullaniciBirParasi,&kullaniciIkiParasi,&kullaniciUcParasi);
        fclose(Dosya2);

        Dosya2 = fopen("Para bilgileri.txt","w");
        fprintf(Dosya2,"%d\n%d\n%d",kullaniciBirParasi,kullaniciIkiParasi,oyunSonrasiBakiyeler[i]);
        fclose(Dosya2);

        if(oyunSonrasiBakiyeler[i] == 0)
            return;
    }

        continue;
    }

    //----------------------------------------- Blackjack kismi

    if(a==2) { // BlackJack isterse oto kisim
        oyunSonrasiBakiyeler[0] = asilBakiye;

        oyunSonrasiBakiyeler[i] = blackJackOyunu(oyunSonrasiBakiyeler[i-1]);
        printf("Yeni Bakiyeniz : %d\n\n",oyunSonrasiBakiyeler[i]);

        if(oyunSonrasiBakiyeler[i] == 0) {
        wait(2);
        printf("Paraniz bitmistir , lutfen siteyi bastan acip bir daha yukleme yapiniz\n\n\n\n\n\n");
    }

      if(r==1) { //1. kullanici oyundaysa onun parasini degistirmen digerlerini sabitlemen lazim.

        Dosya2 = fopen("Para bilgileri.txt","r+");

        fprintf(Dosya2,"%d",oyunSonrasiBakiyeler[i]);

        if(oyunSonrasiBakiyeler[i] == 0)
            return;
    }

    if(r==2) { //2. kullanici oyundaysa onun parasini degistirmen digerlerini sabitlemen lazim.

        Dosya2 = fopen("Para bilgileri.txt","r");
        fscanf(Dosya2,"%d",&kullaniciBirParasi);
        fclose(Dosya2);

        Dosya2 = fopen("Para bilgileri.txt","w");
        fprintf(Dosya2,"%d\n%d",kullaniciBirParasi,oyunSonrasiBakiyeler[i]);
        fclose(Dosya2);

        if(oyunSonrasiBakiyeler[i] == 0)
            return;
    }

    if(r==3) { //3. kullanici oyundaysa onun parasini degistirmen digerlerini sabitlemen lazim.

        Dosya2 = fopen("Para bilgileri.txt","r");
        fscanf(Dosya2,"%d %d",&kullaniciBirParasi,&kullaniciIkiParasi);
        fclose(Dosya2);

        Dosya2 = fopen("Para bilgileri.txt","w");
        fprintf(Dosya2,"%d\n%d\n%d",kullaniciBirParasi,kullaniciIkiParasi,oyunSonrasiBakiyeler[i]);
        fclose(Dosya2);

        if(oyunSonrasiBakiyeler[i] == 0)
            return;
    }


    continue;
    }

  }
}
