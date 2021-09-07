#include <stdio.h>
#include <string.h>
struct Makanan{
    char name[254];
};

void tambahMakanan(){
    struct Makanan mkn;
    scanf("%s", mkn.name);
    FILE *fp = fopen("makanan.txt", "a");
    fprintf(fp, "%s\n", mkn.name);
    fclose(fp);
}

void lihatMakanan(){
    FILE *fp = fopen("./makanan.txt", "r");
    struct Makanan mkn;
    while(fscanf(fp, "%[^#]\n", 
            mkn.name) != EOF){
        printf("Name: %s\n", mkn.name);
    }
}

struct Makanan cariMakanan(){
    char nama[100];
    scanf("%s", nama);
    FILE *fp = fopen("./makanan.txt", "r");
    struct Makanan mkn;
    while(fscanf(fp, "%[^#]\n", 
            mkn.name) != EOF){
        if(strcmp(nama, mkn.name) == 0){
            return mkn;
        }
    }
    struct Makanan temp;
    return temp;
}

int main(){
    int choice;
    do{
        puts("1. Cari Makanan");
        puts("2. Input Makanan");
        puts("3. Random Generator Makanan");
        puts("4. Lihat Semua Makanan");
        puts("5. Exit");
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                struct Makanan temp = cariMakanan();
                printf("%s dicari\n", temp.name);
                break;
            }
            case 2:{
                tambahMakanan();
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                lihatMakanan();
                break;
            }
        }
    }while(choice != 5);
    return 0;
}
