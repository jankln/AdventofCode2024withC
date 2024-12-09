#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

bool ist_sicher(int report[],int laenge){
    bool steigende_pegel=true,fallende_pegel=true,passende_differenzen=true;
    for(int i=0;i<laenge-1;i++){
        int diff=abs(report[i]-report[i+1]);
        if(diff<1||diff>3) passende_differenzen=false;
        if(report[i]>=report[i+1]) steigende_pegel=false;
        if(report[i]<=report[i+1]) fallende_pegel=false;
    }
    return (steigende_pegel||fallende_pegel)&&passende_differenzen;
}

int parse_zeile(char *zeile,int report[]){
    int index=0;
    char *token=strtok(zeile," ");
    while(token!=NULL){
        report[index++]=atoi(token);
        token=strtok(NULL," ");
    }
    return index;
}

int main(){
    FILE *datei=fopen("Berichte.txt","r");
    if(datei==NULL) return 1;
    char zeile[256];
    int report[100],anzahl_sicher=0;
    while(fgets(zeile,sizeof(zeile),datei)){
        zeile[strcspn(zeile,"\n")]='\0';
        if(ist_sicher(report,parse_zeile(zeile,report))) anzahl_sicher++;
    }
    fclose(datei);
    printf("Anzahl der sicheren Berichte:%d\n",anzahl_sicher);
    return 0;
}
