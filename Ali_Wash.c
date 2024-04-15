#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>

FILE *datauser;
FILE *datauser2;
FILE *dataservice;
FILE *dataservice2;
FILE *dataservice3;
FILE *ruangan;
FILE *datapesanan;
FILE *datapesanan2;

char admin1[20], pwadmin[30], nama[50];

struct RuanganService{
    char ket;
}ruang;
struct DataService{
    char jeniskendaraan[30], jenisservice[20], jeniskendaraan2[20];
    float harga;
}daser;
struct DataPesanan{
    char jeniskendaraan[30], jenisservice[20], jeniskendaraan2[20];
    char nohp[60], alamat[70], email[40], nama[30];
    float harga;
    int status;
}dapes;
struct DataService2{
    char jeniskendaraan2[20];
}daser2;
struct DataPelanggan{
    char user[60], pass[60], nohp[60], alamat[70], email[40], nama[30], hewanfav[30], buahfav[20]; 
    int pin;
}dapel;

void bubbleSort(struct DataService arr[], int n);
void registrasiUser();
void looksavedatauser();
void PrintHedri(const char* label, const char* value, char formattingChar, int width);
void loading(int n);
void loginadmin(int n);
void menuadmin();
void loginuser(int n);
void menuuser(char a[50]);
void loginuser1();
void lupapassword();
void pesan();
void tambahharga();
void display(struct DataService daserr[], int n, char jenis[]);
void sort(struct DataService daserr[], int n);
void sortingdata();

int main(){
    int choice = 1;
    int choice2 = 1, choice3 = 1;
    char ayang, lihat[20],lihat2[30], username[60], password[70];

    do{
    system("cls");
    // refresh();
    printf("========== Menu ==========\n");
    printf("1. Admin %s \n", (choice == 1) ? "<=" : " ");
    printf("2. User %s \n", (choice == 2) ? "<=" : " ");
    printf("3. HelpDesk %s \n", (choice == 3) ? "<=" : " ");
    printf("4. Keluar %s \n", (choice == 4) ? "<=" : " ");

    ayang = getch();


    switch(ayang){
        case 72 :
        if(choice>1){
            choice--;
        }
        break;
        case 80 :
        if(choice<4){
            choice++;
        }
        break;
    }

    } while (ayang!=13);


    switch(choice){
    case 1: //Menu ADMIN
    loginadmin(3);
    break;
    case 2: //Menu USER
    loginuser1();
    break;
    case 3:
    printf("Menu %d\n", choice);

    break;
    case 4:
    do{
    system("cls");
    printf("You're LogOut : \n");
    printf("Sure ?\n");
    printf("Yes %s\n", (choice2==1) ? "<=" : " ");
    printf("No %s\n", (choice2==2) ? "<=" : " ");
    ayang = getch();
    if(ayang==80){
        if(choice2<2)
        choice2++;
    }
    else if(ayang==72){
        if(choice2>1){
            choice2--;
        }
    }
    }while(ayang!=13);
    switch(choice2){
        case 1 : 
        printf("Shutdown !!\n");
        break;
        case 2 : 
        printf("Nice Choice !!\n");
        main();
        break;
    }

    break;

    default : main(); 
    }
    return 0;
}
void loginadmin(int n){
 printf("===LOGIN Admin===\nPlease Login Before Continue !!\n\n");
    printf("Username : ");
    gets(admin1);
    printf("Password : ");
    gets(pwadmin);
    loading(2);
    if(n>0)
    {
    if(strcmp(admin1, "admin")==0 && strcmp(pwadmin, "123")==0){
        menuadmin();
    }
    else if(strcmp(admin1, "admin")!=0 && strcmp(pwadmin, "123")==0){
        printf("Please check Your Username !!\n");
        loading(3);
        loginadmin(n-1);
    }
    else if(strcmp(admin1, "admin")==0 && strcmp(pwadmin, "123")!=0){
        printf("Please check Your Password !! \n");
        loading(3);
        loginadmin(n-1);
    }
    else {
        printf("Please check Your Username and Your Password !! \n");
        loginadmin(n-1);
    }

    } else main();
}
void loginuser1(){
    int choice3=1;
    char ayang;
    do{
        system("cls");
    printf("Menu User\n");
    printf("1. Login %s \n", (choice3==1) ? "<-" : " ");
    printf("2. Regist %s \n", (choice3==2) ? "<-" : " ");
    printf("3. Lupa Password %s \n", (choice3==3) ? "<-" : " ");
    printf("4. Kembali %s \n", (choice3==4) ? "<-" : " ");

    ayang = getch();
    if(ayang==80){
        if(choice3<4)
        choice3++;
    }
    else if(ayang==72){
        if(choice3>1){
            choice3--;
        }
    }
    }while(ayang!=13);

    switch(choice3){
        case 1 : 
        loginuser(3);
        break;
        case 2 : 
        registrasiUser();
        break;
        case 3 :
        lupapassword();
        break;
        case 4 :
        main();
        break;
    }
}
void loginuser(int n){
    char username[30], password[40];
    int x=0;

    printf("===LOGIN USER===\nPlease Login Before Continue !!\n");
    // system("pause");
    printf("Username : ");
    gets(username);
    printf("Password : ");
    gets(password);
    loading(3);

    datauser = fopen("datauser.dat", "rb"); // Open Data User
    if(x==0)
    {
    if(n>0)
    {
    while(fread(&dapel, sizeof(dapel),1, datauser)==1){
    if(strcmp(username, dapel.user)==0)
    {
        if(strcmp(username, dapel.user)==0 && strcmp(password, dapel.pass)==0){
          fclose(datauser); strcpy(nama, dapel.nama); return menuuser(nama);
        }
        else if(strcmp(username, dapel.user)==0 && strcmp(password, dapel.pass)!=0){
        printf("Please check Your Password !! \n");
        loading(3);
        fclose(datauser);
        loginuser(n-1);
        }
        
    }
    else if(strcmp(password, dapel.pass)==0){
        printf("Please check Your Username!! \n");
        loading(3);
        fclose(datauser);
        loginuser(n-1);
    } else x=1;
    }

    } else { printf("Akses di Tolak\n"); loading(3); fclose(datauser); loginuser1(); }
    }
    if(x==1){
        printf("Please check Your Username and Your Password !! \n");
        fclose(datauser);
        loginuser(n-1);
    }
    fclose(datauser);
}
void lupapassword(){
char hewan[20], buah[30], user[40], pw[20];
int x=1,w;
printf("Harap Jawab Pertanyaan Berikut untuk Mengubah Password Anda !\n");
system("pause");
printf("Hewan Favorit : ");
gets(hewan);
printf("Buah Peliharaan : ");
gets(buah);
printf("PIN : ");
scanf("%d", &w); getchar();

datauser = fopen("datauser.dat","rb");
datauser2 = fopen("datause2r.dat","wb");
while(fread(&dapel, sizeof(dapel),1, datauser)==1){
if(strcmp(dapel.hewanfav,hewan)==0 && strcmp(dapel.buahfav,buah)==0 && dapel.pin==w){
    printf("Silahkan Ubah Username dan Password !!\n");
    printf("Username : "); gets(user);
    printf("Password : "); gets(pw);
    strcpy(dapel.user, user);
    strcpy(dapel.pass, pw);
    x=0;
}
fwrite(&dapel, sizeof(dapel),1, datauser2);
}

if(x==1){
    printf("Data yang anda Masukkan Salah\n");
    loginuser1();
}

fclose(datauser);
fclose(datauser2);

remove("datauser.dat");
rename("datauser2.dat", "datauser.dat");
printf("Data Berhasil di ubah !!\n Jangan Lupa Lagi ya :)\n");
loading(3);
loginuser1();

}
void menuadmin()
{
    int yoice=10,n,dat = 1,dag = 1, pos = 0,r, ij=1,al=0,ay=0,alo;
    float har;
    char jenken[20], jen[30], pilih[20],pilih2[30],ubahpo[30],po[2],ubahpo2[30];
    printf("=== Welcome Boss ===\n");
    printf("1. Add Jenis Kendaraan\n2. Lihat Jenis Kendaraan dan Add Harga dan Jenis Servise\n");
    printf("3. Lihat Harga dan Jenis Service\n4. Add Ruangan Service\n5. Lihat Ruangan\n");
    printf("6. Lihat Data Pesanan\n7. Lihat dan Ubah Progress\n8. Lihat data User\n9. Kembali\n10. Keluar\n");
    printf("Masukkan Pilihan : ");
    scanf("%d", &yoice); getchar();

    switch(yoice)
    {
        case 1 : 
            printf("Tambahkan Jenis Kendaraan\n");
            dataservice3 = fopen("dataservice2.dat", "ab");
            printf("Berapa Jumlah Kendaraan ? : ");
            scanf("%d", &n);
            getchar();
            for(int i=1; i<=n;i++){
                printf("Jenis Kendaraan %d : ", i);
                fflush(stdin);
                gets(daser2.jeniskendaraan2);
                fwrite(&daser2, sizeof(daser2),1, dataservice3);
            }
            loading(3);
            printf("Sukses Menambahkan Jenis Kendaraan !!\n");
            fclose(dataservice3);
            menuadmin();
            break;
        case 2 : 
        tambahharga();
        break;
        case 3 : 
        dataservice = fopen("dataservice.dat", "rb");
        while(fread(&daser, sizeof(daser),1,dataservice)==1){
            printf("Data %d\n", dag);
            PrintHedri("Jenis Kendaraan", daser.jeniskendaraan, ' ', 18);
            PrintHedri("Jenis Service", daser.jenisservice, ' ', 18);
            printf("Harga : %.3f \n", daser.harga);
            printf("\n");
             ++dag;
        }
           
        fclose(dataservice);
        menuadmin();
            break;
        case 4 : 
        printf("Jumlah Ruangan yang ingin di Tambahkan : ");
        scanf("%d", &r); getchar();

        ruangan = fopen("ruangan.dat", "ab");
        for(int a=1;a<=r;a++){
            ruang.ket = 'X';
            fwrite(&ruang, sizeof(ruang),1, ruangan);
        }

        fclose(ruangan);
        printf("Data SuccesFully Add\n");
        menuadmin();
        break;
        case 5 : 
        ruangan = fopen("ruangan.dat", "rb");
        while(fread(&ruang,sizeof(ruang),1, ruangan)==1){
            printf("=========\n");
            printf("=       =\n");
            printf("=   %c   =\n", ruang.ket);
            printf("=       =\n");
            printf("=========\n\n");
        }
        fclose(ruangan);
        menuadmin();
        break;
        case 6 :
            datapesanan=fopen("datapesanan.dat","rb");
        while(fread(&dapes, sizeof(dapes),1,datapesanan)==1){
            printf("Data %d \n", ij);
            printf("Nama : %s \n", dapes.nama);
            printf("No HP : %s \n", dapes.nohp);
            printf("Email : %s \n", dapes.email);
            printf("Alamat : %s \n", dapes.alamat);
            printf("Jenis Kendaraan : %s \n", dapes.jeniskendaraan);
            printf("Jenis Service : %s \n", dapes.jenisservice);
            printf("Harga : %.0f \n", dapes.harga);
            printf("Status (0=belum, 1= progres, 2=selesai) : %d \n\n", dapes.status);
            ij++;
            al=1;
        }
        fclose(datapesanan);
        if(al=0){
            printf("Data tidak di temukan\n");
            menuadmin();
        } 
        menuadmin();
        break;
        case 7 : 
        datapesanan=fopen("datapesanan.dat","rb");
        while(fread(&dapes, sizeof(dapes),1,datapesanan)==1){
            printf("Data %d \n", ij);
            printf("Nama : %s \n", dapes.nama);
            printf("No HP : %s \n", dapes.nohp);
            printf("Email : %s \n", dapes.email);
            printf("Alamat : %s \n", dapes.alamat);
            printf("Jenis Kendaraan : %s \n", dapes.jeniskendaraan);
            printf("Jenis Service : %s \n", dapes.jenisservice);
            printf("Harga : %.0f \n", dapes.harga);
            printf("Status (0=belum, 1= progres, 2=selesai) : %d \n\n", dapes.status);
            ij++;
            al=1;
        }
        fclose(datapesanan);
        if(al=0){
            printf("Data tidak di temukan\n");
            menuadmin();
        } 
        else {
            printf("Apakah anda ingin mengubah Progres ? (y/n) : ");
            fflush(stdin); gets(po);
            if(strcmp(po,"Y")==0 || strcmp(po,"y")==0){
                printf("Masukkan Nama Pelanggan : "); gets(ubahpo);
                printf("Masukkan Jenis Service : "); gets(ubahpo2);
                datapesanan=fopen("datapesanan.dat","rb");
                datapesanan2=fopen("datapesanan2.dat","wb");
                while(fread(&dapes, sizeof(dapes),1,datapesanan)==1){
                    if(strcmp(ubahpo,dapes.nama)==0 && strcmp(ubahpo2,dapes.jenisservice)==0){
                    printf("Ubah Status ke : \n0. belum\n1. progres\n2. selesai\n pilih : "); scanf("%d", &alo); getchar();
                    ay=1;
                    dapes.status=alo;
                    }
                    fwrite(&dapes,sizeof(dapes),1,datapesanan2);
                }
                fclose(datapesanan);
                fclose(datapesanan2);
                remove("datapesanan.dat");
                rename("datapesanan2.dat","datapesanan.dat");

                if(ay==0){
                    printf("Data tidak di temukan\n");
                    menuadmin();
                } else {
                    printf("Data progress berhasil di ubah !\n");
                    menuadmin();
                }

            }
            else menuadmin();
        }
        menuadmin();
        break;
        case 8 : 
        looksavedatauser();
        break;
        case 9 :
        main();
        break;
        case 10 :
        break;
        default : menuadmin();

    }
}
void tambahharga(){
    int pos=0, dat;
    dat = 1;
    float har;
    char pilih[15], jen[20], jenken[30];
            dataservice3 = fopen("dataservice2.dat", "rb");
        while(fread(&daser2, sizeof(daser2),1,dataservice3)==1){
            printf("Data %d\n", dat);
            PrintHedri("Jenis Kendaraan", daser2.jeniskendaraan2, ' ', 18);
            printf("\n");
            ++dat; 
        }
        fclose(dataservice3);
        printf("Masukkkan Jenis Kendaraan yang akan di tambahkan harga dan jenis service : ");
        fflush(stdin); gets(jenken);
        dataservice3 = fopen("dataservice2.dat", "rb");
        while(fread(&daser2, sizeof(daser2),1,dataservice3)==1){
            if(strcmp(jenken,daser2.jeniskendaraan2)==0){
                pos=1;
            }
        }
        fclose(dataservice3);
        if(pos==0){
            printf("Pilihan Tidak Tersedia\n");
            menuadmin();
        } 
        else 
        {
        dataservice = fopen("dataservice.dat", "ab");
        strcpy(daser.jeniskendaraan,jenken);
        printf("Jenis Service : ");
        gets(daser.jenisservice);
        printf("Harga Service : ");
        scanf("%f", &daser.harga); getchar();
        fwrite(&daser, sizeof(daser),1,dataservice);
        fclose(dataservice);
        printf("Apakah anda ingin menambahkan Jenis dan harga Lagi ? (y/t) ");
        gets(pilih);
        if(strcmp(pilih, "y")==0 || strcmp(pilih, "Y")==0){
            tambahharga();
        } else loading(3);printf("Data Succes to add\n"); menuadmin();
        menuadmin();
        }
    
}
void menuuser(char a[50]){
    int yoice=7,n=0,m=1,v=0,z=0;
    float total=0,bayarwoi=0;
    char pilih[30];
// - Registrasi akun user (E-mail, nama lengkap, no. telepon, alamat, username, password)
// - Login User *maksimum 3 kali (username dan password)
// - Lupa password menggunakan keyword tertentu (contoh: nama kucing, nama ibu), mengubah password jika  pertanyaan dijawab benar.
// - Melakukan pemesanan dengan tampilan urutan berdasarkan harga paling murah, dengan mengisi data pesanan dan dapat melihat serta memilih ruangan yang kosong.
// - Melihat status progres cucian sudah selesai atau belum, dengan mengecek data pesanan
// - Melakukan pembayaran ketika pelayanan sudah selesai dan menunggu verifikasi dari admin
// - Dapat melihat helpdesk
// - log out
    printf("=== Welcome %s ===\n", a);
    printf("1. Pesan Service/Pelayanan\n2. Lihat Status Pelayanan\n");
    printf("3. Bayar\n4. Lihat Harga Pelayanan\n");
    printf("5. Help Desk\n6. Kembali\n7. Keluar\n");
    printf("Masukkan Pilihan : ");
    scanf("%d", &yoice); getchar();

    switch(yoice)
    {
        case 1:
        pesan();
        break;
        case 2:
        datapesanan=fopen("datapesanan.dat","rb");
        while(fread(&dapes, sizeof(dapes),1,datapesanan)==1){
            if(strcmp(dapes.nama,nama)==0){
                if(dapes.status==0){
                    printf("\nJenis Layanan : %s untuk Kendaraan anda sedang dalam antrian\nMohon bersabar\n", dapes.jenisservice);
                    v=1;
                }
                else if(dapes.status==1){
                    printf("\nJenis Layanan : %s untuk Kendaraan anda sedang dalam proses layanan\nMohon bersabar\n", dapes.jenisservice);
                    v=2;
                }
                else if(dapes.status==2){
                    printf("\nProses layanan : %s untuk kendaraan anda telah selesai\nMohon Segera Lakukan pembayaran\n", dapes.jenisservice);
                    v=3;
                }
            }
        }
        if(v==0){
            printf("Data tidak tersedia\n");
            fclose(datapesanan);
            menuuser(nama);
        } else {
            fclose(datapesanan);
            menuuser(nama);
        }
        fclose(datapesanan);
        break;
        case 3:
        datapesanan=fopen("datapesanan.dat","rb");
        while(fread(&dapes, sizeof(dapes),1,datapesanan)==1){
            if(strcmp(dapes.nama,nama)==0){
               if(dapes.status==2){
                    printf("\nProses layanan : %s untuk kendaraan anda telah selesai\nMohon Segera Lakukan pembayaran\n", dapes.jenisservice);
                    printf("Harga Layanan : Rp. %.0f,00\n", dapes.harga);
                    z=3;
                    total+=dapes.harga;
                }
                v=1;
            }
        }
        if(v==0){
            printf("Data tidak tersedia\n");
            fclose(datapesanan);
            menuuser(nama);
        } else {
            if(z==3) {
            printf("\nTotal Pesanan Anda : ");
            printf("Rp. %.0f,00\n", total);
            printf("===========Bayar========\nMasukkan Jumlah Pembayaran Anda : "); scanf("%f", &bayarwoi); getchar();
            fclose(datapesanan);
                if(bayarwoi>=total){
                    printf("Pembayaran Berhasil\nKembalian Anda : %.0f\n", bayarwoi-total);
                    printf("Terima Kasih sudah menggunakan Layanan Kami\n");
                    system("pause");
                    datapesanan=fopen("datapesanan.dat","rb");
                    datapesanan2=fopen("datapesanan2.dat","wb");
                    while(fread(&dapes,sizeof(dapes),1,datapesanan)==1){
                        if(dapes.status!=2){
                            fwrite(&dapes,sizeof(dapes),1,datapesanan2);
                        }
                    }
                    fclose(datapesanan);
                    fclose(datapesanan2);
                    remove("datapesanan.dat");
                    rename("datapesanan2.dat","datapesanan.dat");
                    menuuser(nama);
                } else {
                    printf("Pembayaran Gagal\n Uang anda Kurang Rp. %.0f,00\nSilahkan Lakukan Pembayaran Ulang\n", total-bayarwoi);
                    menuuser(nama); 
                }
            menuuser(nama); 
            }
            else {
                fclose(datapesanan);
                menuuser(nama); 
            }
        }
        break;
        case 4: 
            dataservice3 = fopen("dataservice2.dat", "rb");
            while(fread(&daser2,sizeof(daser2),1,dataservice3)==1){
                printf("%d. %s \n",m, daser2.jeniskendaraan2);m++;
            }
            fclose(dataservice3);
            printf("Pilih Jenis Kendaraan Anda : "); fflush(stdin); gets(pilih);
            dataservice3 = fopen("dataservice2.dat", "rb");
            while(fread(&daser2,sizeof(daser2),1,dataservice3)==1){
                if(strcmp(pilih,daser2.jeniskendaraan2)==0){
                    n=1;
                } 
            }
            fclose(dataservice3);
            if(n==0){
                printf("Pilihan tidak Tersedia\n");
                system("pause");
                menuuser(nama);
            }
            else {
                sortingdata(pilih);
                system("pause");
                menuuser(nama);
            }
            break;
        case 5:
        printf("==========Help Desk==========\n");
        //Tolong isi Help Desk di sini
        case 6:
        main();
        break;
        case 7:
        break;
        default : menuuser(nama);
    }
}

void pesan(){
     int m=1,n=0, h=0;
     char pilih[30], pilih2[20];
     char pilih4[30],pilih5[30],pilih6[30],pilih7[30];
   
dataservice3 = fopen("dataservice2.dat", "rb");

while(fread(&daser2,sizeof(daser2),1,dataservice3)==1){
    printf("%d. %s \n",m, daser2.jeniskendaraan2);m++;
}
fclose(dataservice3);
 printf("Pilih Jenis Kendaraan Anda : "); fflush(stdin); gets(pilih);

 dataservice3 = fopen("dataservice2.dat", "rb");

while(fread(&daser2,sizeof(daser2),1,dataservice3)==1){
    if(strcmp(pilih,daser2.jeniskendaraan2)==0){
        n=1;
    } 
}
fclose(dataservice3);
if(n==0){
    printf("Pilihan tidak Tersedia\n");
    system("pause");
    menuuser(nama);
}
else {
    sortingdata(pilih);
    printf("\nPilih Jenis Service yang anda ingin pesan : ");
    gets(pilih2);
    dataservice = fopen("dataservice.dat", "rb");
    while(fread(&daser,sizeof(daser),1,dataservice)==1){
        if(strcmp(daser.jenisservice,pilih2)==0){
            h=1;
            }
    }
    fclose(dataservice);
    if(h==0){
        printf("Pilihan tidak tersedia\n");
        menuuser(nama);
    } else {

    datauser = fopen("datauser.dat", "rb");
    while(fread(&dapel,sizeof(dapel),1,datauser)==1){
        if(strcmp(dapel.nama,nama)==0){ 
            strcpy(pilih4, dapel.nama);
            strcpy(pilih5, dapel.alamat);
            strcpy(pilih6, dapel.email);
            strcpy(pilih7, dapel.nohp);
            }
    }
    fclose(datauser);

    dataservice = fopen("dataservice.dat", "rb");
    datapesanan = fopen("datapesanan.dat", "ab");
    while(fread(&daser,sizeof(daser),1,dataservice)==1){
        if(strcmp(daser.jenisservice,pilih2)==0){
            strcpy(dapes.jeniskendaraan, daser.jeniskendaraan);
            strcpy(pilih2, daser.jenisservice);
            strcpy(dapes.jenisservice, daser.jenisservice);
            dapes.harga=daser.harga;
            dapes.status=0;
            strcpy(dapes.nama,pilih4);
            strcpy(dapes.alamat,pilih5);
            strcpy(dapes.email,pilih6);
            strcpy(dapes.nohp,pilih7);
            fwrite(&dapes,sizeof(dapes),1,datapesanan);
            }
    }
    fclose(dataservice);
    fclose(datapesanan);


    loading(2);
        printf("Pesanan anda telah tercatat, silahkan menunggu :)\n\n");
    }

    return menuuser(nama);
}


}
void registrasiUser(){
    system("cls");
    datauser = fopen("datauser.dat", "ab");
    printf("============ Welcome to D'WASH ============== \n=> Please Input Your Data !!\n");
    printf("Nama\t\t: "); gets(dapel.nama);
    printf("NO Hp\t\t: "); gets(dapel.nohp);
    printf("Alamat\t\t: "); gets(dapel.alamat);
    printf("Email\t\t: "); gets(dapel.email);
    printf("Username\t: "); gets(dapel.user);
    printf("Password\t: "); gets(dapel.pass);
    printf("Pin (6 Digit)\t: "); scanf("%d", &dapel.pin); getchar();
    printf("Buah Fav\t: "); gets(dapel.buahfav);
    printf("Hewan Fav\t: "); gets(dapel.hewanfav);
    fwrite(&dapel, sizeof(dapel),1, datauser);
    fclose(datauser);

    printf("You're Data Succes to Save\n");
    printf("Please Enter to Continue\n");
    system("Pause");
     loginuser1();
}
void looksavedatauser(){
    int jak=1;
    datauser = fopen("datauser.dat", "rb");
    while(fread(&dapel, sizeof(dapel),1,datauser) == 1){
        // printf("Data %d ", jak);
        // printf("\nNama\t\t: %s", dapel.nama);
        // printf("\nPassword\t: %s", dapel.pass);
        // printf("\nAlamat\t\t: %s", dapel.alamat);
        // printf("\nEmail\t\t: %s", dapel.email);
        // printf("\nNoHp\t\t: %s", dapel.nohp);
        // printf("\nUsername\t: %s\n\n", dapel.user);
    PrintHedri("Nama", dapel.nama, ' ', 10);
    PrintHedri("Alamat", dapel.alamat, ' ', 10);
    PrintHedri("Email", dapel.email, ' ', 10);
    PrintHedri("NoHp", dapel.nohp, ' ', 10);
    PrintHedri("Username", dapel.user, ' ', 10);
    PrintHedri("Password", dapel.pass, ' ', 10);
    printf("\n");
    jak++;
    }
    fclose(datauser);
    menuadmin();
}
void PrintHedri(const char* label, const char* value, char formattingChar, int width) {
    printf("\n%s %c", label, formattingChar);

    for (int i = 0; i < width - strlen(label) - 1; i++) {
        putchar(formattingChar);
    }

    printf(": %s\n", value);
}
void loading(int n){
    printf("\nLoading");
    for(int m=0; m<n;m++){
        printf(".");
        fflush(stdout);
        usleep(500 * 1000);

    }
    printf("\n");
}

void sortingdata(char soleh[30]){

    struct DataService daserr[50]; 
    int count = 0;
    dataservice=fopen("dataservice.dat","rb");
    
    while(fread(&daserr[count],sizeof(struct DataService),1, dataservice)==1){
        count++;
    }
    fclose(dataservice);
    sort(daserr, count);
    display(daserr, count, soleh);

}
void sort(struct DataService daserr[], int n) {
    int i, j;
    struct DataService temp;

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (daserr[i].harga > daserr[j].harga) {
                temp = daserr[i];
                daserr[i] = daserr[j];
                daserr[j] = temp;
            }
        }
    }
}

void display(struct DataService daserr[], int n, char jenis[]) {
    int i,x=1;
    printf("Data untuk kendaraan %s : \n", jenis);
    for (i = 0; i < n; i++) {
        if (strcmp(daserr[i].jeniskendaraan, jenis) == 0) {
            printf("%d. Jenis Service :  %s\n   Harga Service : Rp. %.0f,00\n", x, daserr[i].jenisservice, daserr[i].harga);
        x++;
        }
    }
}
