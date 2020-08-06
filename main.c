#include <stdio.h>
#include <stdbool.h>
#include <string.h>

FILE *sFile;
FILE *nFile;

char words[1000][256];
char comands[1000][256];
char *fname;

bool isNewLineSymbol(char symbol);
bool isLetter(char symbol);
bool isSpecialSymbol(char symbol);
bool isSpace(char symbol);
bool isDigit(char symbol);
bool newLine;
bool createFile();
void help();
void print_words();
void stop(int i);
int open(int argc, char* argv[]);
int lexiclAn();
int translateCode();
int plus(int a);
int minus_(int a);
int times(int a);
int devide(int a);
int equal(int a);
int print(int a);

int main(int argc, char* argv[]){
   printf("Компилятор basic для Электроника МК 56.\n");
   if(open(argc,argv)==-1){help();return 0;}
   if(createFile()==false){printf("Ошибка создания файла\n");}
   if(lexiclAn()==-1){printf("Ошибка лексического анализатора.");}
   if(translateCode()==-1){printf("Ошибка компиляции.");}
   printf("Выход.");
   fcloseall();
   return 0;
   }

int open(int argc, char* argv[]){
    fname = argv[1];
    sFile = fopen(fname,"r");
	if(sFile == NULL){
		printf("Не удаётся открыть файл %s",fname);
		printf("\n");
		return -1;
		} else {
    printf("Чтение файла...\n");
		}
    return 1;
}

int lexiclAn(){
    register char symbol;
    int i=0;
    int ii=0;
    register int type_of_symbol=5; // 0-пробел 1-буквы 2-цифры 3-специальные символы 4-\n
    symbol=fgetc(sFile);
    while (symbol!= EOF){
        //if(isDigit(symbol)){printf("Digit:");printf("%c",symbol);printf("\n");}
        //if(isSpace(symbol)){printf("Space:");printf("%c",symbol);printf("\n");}
        //if(isSpecialSymbol(symbol)){printf("SpecialSymbol:");printf("%c",symbol);printf("\n");}
        //if(isLetter(symbol)){printf("Letter:");printf("%c",symbol);printf("\n");}

    if(isSpace(symbol)){
        if(type_of_symbol!=0){
            type_of_symbol=0;
            }
        }
    if(isLetter(symbol)){
        if(type_of_symbol!=1){
            type_of_symbol=1;
            ii=0;
            i++;
            //printf("^\n");
            }
        words[i][ii]=symbol;
        ii++;
        //printf("%c",symbol);
        //printf("\n");
        }
    if(isDigit(symbol)){
        if(type_of_symbol!=2){
            type_of_symbol=2;
            ii=0;
            i++;
            //printf("^\n");
            }
        words[i][ii]=symbol;
        ii++;
        //printf("%c",symbol);
        //printf("\n");
        }
    if(isSpecialSymbol(symbol)){
        if(type_of_symbol!=3){
            type_of_symbol=3;
            ii=0;
            i++;
            //printf("^\n");
            }
        words[i][ii]=symbol;
        ii++;
        //printf("%c",symbol);
        //printf("\n");
        }
    if(isNewLineSymbol(symbol)){
        if(type_of_symbol!=4){
            type_of_symbol=4;
            ii=0;
            i++;
                }
                words[i][ii]=13;
                ii++;
                }

    symbol=fgetc(sFile);
        }
   return 0;
}

void help(){
    printf("\n*****elcomp v0.1*****\n");
    printf("Применение:\n$ ./elcomp ИМЯ_ФАЙЛА\n");
    printf("*********************\n");
}

bool isDigit(char symbol){
    if(symbol=='0'){return true;}
    if(symbol=='1'){return true;}
    if(symbol=='2'){return true;}
    if(symbol=='3'){return true;}
    if(symbol=='4'){return true;}
    if(symbol=='5'){return true;}
    if(symbol=='6'){return true;}
    if(symbol=='7'){return true;}
    if(symbol=='8'){return true;}
    if(symbol=='9'){return true;}
    return false;
}

bool isSpace(char symbol){
    if(symbol==' '){return true;}
    return false;
}

bool isSpecialSymbol(char symbol){
    if(symbol=='"'){return true;}
    if(symbol=='('||symbol==')'){return true;}
    if(symbol=='<'||symbol=='>'){return true;}
    if(symbol=='='){return true;}
    if(symbol=='+'){return true;}
    if(symbol=='-'){return true;}
    if(symbol=='*'){return true;}
    if(symbol=='/'){return true;}
    if(symbol==';'){return true;}
    return false;
}

bool isLetter(char symbol){
    if(symbol=='a'){return true;}
    if(symbol=='b'){return true;}
    if(symbol=='c'){return true;}
    if(symbol=='d'){return true;}
    if(symbol=='e'){return true;}
    if(symbol=='f'){return true;}
    if(symbol=='g'){return true;}
    if(symbol=='h'){return true;}
    if(symbol=='i'){return true;}
    if(symbol=='j'){return true;}
    if(symbol=='k'){return true;}
    if(symbol=='l'){return true;}
    if(symbol=='m'){return true;}
    if(symbol=='n'){return true;}
    if(symbol=='o'){return true;}
    if(symbol=='p'){return true;}
    if(symbol=='q'){return true;}
    if(symbol=='r'){return true;}
    if(symbol=='s'){return true;}
    if(symbol=='t'){return true;}
    if(symbol=='u'){return true;}
    if(symbol=='v'){return true;}
    if(symbol=='w'){return true;}
    if(symbol=='x'){return true;}
    if(symbol=='y'){return true;}
    if(symbol=='z'){return true;}

    if(symbol=='A'){return true;}
    if(symbol=='B'){return true;}
    if(symbol=='C'){return true;}
    if(symbol=='D'){return true;}
    if(symbol=='E'){return true;}
    if(symbol=='F'){return true;}
    if(symbol=='G'){return true;}
    if(symbol=='H'){return true;}
    if(symbol=='I'){return true;}
    if(symbol=='J'){return true;}
    if(symbol=='K'){return true;}
    if(symbol=='L'){return true;}
    if(symbol=='M'){return true;}
    if(symbol=='N'){return true;}
    if(symbol=='O'){return true;}
    if(symbol=='P'){return true;}
    if(symbol=='Q'){return true;}
    if(symbol=='R'){return true;}
    if(symbol=='S'){return true;}
    if(symbol=='T'){return true;}
    if(symbol=='U'){return true;}
    if(symbol=='V'){return true;}
    if(symbol=='W'){return true;}
    if(symbol=='X'){return true;}
    if(symbol=='Y'){return true;}
    if(symbol=='z'){return true;}

    if(symbol=='$'){return true;} //Да, это не буква. Сделано ради удобства выделения переменных.
    return false;
}

bool isNewLineSymbol(char symbol){
if(symbol==10){
return true;
}
return false;
}

int translateCode(){
bool active=true;
bool activeNL=true;
int NLsymbol=0;
int LastNLsymbol=0;
int NLsymbol_=0;
char word[15];
int ii=0;
    printf("Writing code...:\n");
    while(active==true){
        while(words[NLsymbol][0]!=13 & activeNL==true){
            NLsymbol++;
            if(words[NLsymbol][0]==0){activeNL=false;active=false;}
            }
        NLsymbol_=NLsymbol;
            while(NLsymbol_>LastNLsymbol){

                while(words[NLsymbol_][ii]!=0){
                    word[ii]=words[NLsymbol_][ii];

                    ii++;
                }
                if(strcmp(word,"stop")==0){stop(NLsymbol_);}
                if(strcmp(word,"+")==0){plus(NLsymbol_);}
                if(strcmp(word,"-")==0){minus_(NLsymbol_);}
                if(strcmp(word,"*")==0){times(NLsymbol_);}
                if(strcmp(word,"/")==0){devide(NLsymbol_);}
                if(strcmp(word,"=")==0){equal(NLsymbol_);}
                if(strcmp(word,"print")==0){print(NLsymbol_);}
                memset(word, 0, sizeof word);
                NLsymbol_--;
                ii=0;
            }

        //if(strcmp(word,"stop")==0){stop(i);}
        //memset(word, 0, sizeof word);
        LastNLsymbol=NLsymbol;
        NLsymbol++;
    }
    return 0;
}

int plus(int a){
    int i=0;
    bool variable=false;
    while(words[a-1][i]!=0){
        if(words[a-1][i]=='$'){
            i++;
            if(words[a-1][i]=='a'){fprintf(nFile,"60");}
            if(words[a-1][i]=='b'){fprintf(nFile,"61");}
            if(words[a-1][i]=='c'){fprintf(nFile,"62");}
            if(words[a-1][i]=='d'){fprintf(nFile,"63");}
            if(words[a-1][i]=='e'){fprintf(nFile,"64");}
            if(words[a-1][i]=='f'){fprintf(nFile,"65");}
            if(words[a-1][i]=='g'){fprintf(nFile,"66");}
            if(words[a-1][i]=='h'){fprintf(nFile,"67");}
            if(words[a-1][i]=='i'){fprintf(nFile,"68");}
            if(words[a-1][i]=='j'){fprintf(nFile,"69");}
            if(words[a-1][i]=='k'){fprintf(nFile,"6a");}
            if(words[a-1][i]=='l'){fprintf(nFile,"6b");}
            if(words[a-1][i]=='m'){fprintf(nFile,"6c");}
            if(words[a-1][i]=='n'){fprintf(nFile,"6d");}
            if(words[a-1][i]=='o'){fprintf(nFile,"6e");}
            fprintf(nFile,",");
        } else {


        fprintf(nFile,"0");
        fprintf(nFile,"%c",words[a-1][i]);
        fprintf(nFile,",");
        }
        i++;
    }

    fprintf(nFile,"0E");
    fprintf(nFile,",");
    i=0;

    while(words[a+1][i]!=0){

                   if(words[a+1][i]=='$'){
            i++;
            if(words[a+1][i]=='a'){fprintf(nFile,"60");}
            if(words[a+1][i]=='b'){fprintf(nFile,"61");}
            if(words[a+1][i]=='c'){fprintf(nFile,"62");}
            if(words[a+1][i]=='d'){fprintf(nFile,"63");}
            if(words[a+1][i]=='e'){fprintf(nFile,"64");}
            if(words[a+1][i]=='f'){fprintf(nFile,"65");}
            if(words[a+1][i]=='g'){fprintf(nFile,"66");}
            if(words[a+1][i]=='h'){fprintf(nFile,"67");}
            if(words[a+1][i]=='i'){fprintf(nFile,"68");}
            if(words[a+1][i]=='j'){fprintf(nFile,"69");}
            if(words[a+1][i]=='k'){fprintf(nFile,"6a");}
            if(words[a+1][i]=='l'){fprintf(nFile,"6b");}
            if(words[a+1][i]=='m'){fprintf(nFile,"6c");}
            if(words[a+1][i]=='n'){fprintf(nFile,"6d");}
            if(words[a+1][i]=='o'){fprintf(nFile,"6e");}
            fprintf(nFile,",");
        } else {


        fprintf(nFile,"0");
        fprintf(nFile,"%c",words[a+1][i]);
        fprintf(nFile,",");
        }
        i++;
    }
    fprintf(nFile,"10\n");
    return 0;
}

int minus_(int a){
      int i=0;
    bool variable=false;
    while(words[a-1][i]!=0){
        if(words[a-1][i]=='$'){
            i++;
            if(words[a-1][i]=='a'){fprintf(nFile,"60");}
            if(words[a-1][i]=='b'){fprintf(nFile,"61");}
            if(words[a-1][i]=='c'){fprintf(nFile,"62");}
            if(words[a-1][i]=='d'){fprintf(nFile,"63");}
            if(words[a-1][i]=='e'){fprintf(nFile,"64");}
            if(words[a-1][i]=='f'){fprintf(nFile,"65");}
            if(words[a-1][i]=='g'){fprintf(nFile,"66");}
            if(words[a-1][i]=='h'){fprintf(nFile,"67");}
            if(words[a-1][i]=='i'){fprintf(nFile,"68");}
            if(words[a-1][i]=='j'){fprintf(nFile,"69");}
            if(words[a-1][i]=='k'){fprintf(nFile,"6a");}
            if(words[a-1][i]=='l'){fprintf(nFile,"6b");}
            if(words[a-1][i]=='m'){fprintf(nFile,"6c");}
            if(words[a-1][i]=='n'){fprintf(nFile,"6d");}
            if(words[a-1][i]=='o'){fprintf(nFile,"6e");}
            fprintf(nFile,",");
        } else {


        fprintf(nFile,"0");
        fprintf(nFile,"%c",words[a-1][i]);
        fprintf(nFile,",");
        }
        i++;
    }

    fprintf(nFile,"0E");
    fprintf(nFile,",");
    i=0;

    while(words[a+1][i]!=0){

                   if(words[a+1][i]=='$'){
            i++;
            if(words[a+1][i]=='a'){fprintf(nFile,"60");}
            if(words[a+1][i]=='b'){fprintf(nFile,"61");}
            if(words[a+1][i]=='c'){fprintf(nFile,"62");}
            if(words[a+1][i]=='d'){fprintf(nFile,"63");}
            if(words[a+1][i]=='e'){fprintf(nFile,"64");}
            if(words[a+1][i]=='f'){fprintf(nFile,"65");}
            if(words[a+1][i]=='g'){fprintf(nFile,"66");}
            if(words[a+1][i]=='h'){fprintf(nFile,"67");}
            if(words[a+1][i]=='i'){fprintf(nFile,"68");}
            if(words[a+1][i]=='j'){fprintf(nFile,"69");}
            if(words[a+1][i]=='k'){fprintf(nFile,"6a");}
            if(words[a+1][i]=='l'){fprintf(nFile,"6b");}
            if(words[a+1][i]=='m'){fprintf(nFile,"6c");}
            if(words[a+1][i]=='n'){fprintf(nFile,"6d");}
            if(words[a+1][i]=='o'){fprintf(nFile,"6e");}
            fprintf(nFile,",");
        } else {


        fprintf(nFile,"0");
        fprintf(nFile,"%c",words[a+1][i]);
        fprintf(nFile,",");
        }
        i++;
    }
    fprintf(nFile,"11\n");
    return 0;
}

int times(int a){
  int i=0;
    bool variable=false;
    while(words[a-1][i]!=0){
        if(words[a-1][i]=='$'){
            i++;
            if(words[a-1][i]=='a'){fprintf(nFile,"60");}
            if(words[a-1][i]=='b'){fprintf(nFile,"61");}
            if(words[a-1][i]=='c'){fprintf(nFile,"62");}
            if(words[a-1][i]=='d'){fprintf(nFile,"63");}
            if(words[a-1][i]=='e'){fprintf(nFile,"64");}
            if(words[a-1][i]=='f'){fprintf(nFile,"65");}
            if(words[a-1][i]=='g'){fprintf(nFile,"66");}
            if(words[a-1][i]=='h'){fprintf(nFile,"67");}
            if(words[a-1][i]=='i'){fprintf(nFile,"68");}
            if(words[a-1][i]=='j'){fprintf(nFile,"69");}
            if(words[a-1][i]=='k'){fprintf(nFile,"6a");}
            if(words[a-1][i]=='l'){fprintf(nFile,"6b");}
            if(words[a-1][i]=='m'){fprintf(nFile,"6c");}
            if(words[a-1][i]=='n'){fprintf(nFile,"6d");}
            if(words[a-1][i]=='o'){fprintf(nFile,"6e");}
            fprintf(nFile,",");
        } else {


        fprintf(nFile,"0");
        fprintf(nFile,"%c",words[a-1][i]);
        fprintf(nFile,",");
        }
        i++;
    }

    fprintf(nFile,"0E");
    fprintf(nFile,",");
    i=0;

    while(words[a+1][i]!=0){

                   if(words[a+1][i]=='$'){
            i++;
            if(words[a+1][i]=='a'){fprintf(nFile,"60");}
            if(words[a+1][i]=='b'){fprintf(nFile,"61");}
            if(words[a+1][i]=='c'){fprintf(nFile,"62");}
            if(words[a+1][i]=='d'){fprintf(nFile,"63");}
            if(words[a+1][i]=='e'){fprintf(nFile,"64");}
            if(words[a+1][i]=='f'){fprintf(nFile,"65");}
            if(words[a+1][i]=='g'){fprintf(nFile,"66");}
            if(words[a+1][i]=='h'){fprintf(nFile,"67");}
            if(words[a+1][i]=='i'){fprintf(nFile,"68");}
            if(words[a+1][i]=='j'){fprintf(nFile,"69");}
            if(words[a+1][i]=='k'){fprintf(nFile,"6a");}
            if(words[a+1][i]=='l'){fprintf(nFile,"6b");}
            if(words[a+1][i]=='m'){fprintf(nFile,"6c");}
            if(words[a+1][i]=='n'){fprintf(nFile,"6d");}
            if(words[a+1][i]=='o'){fprintf(nFile,"6e");}
            fprintf(nFile,",");
        } else {


        fprintf(nFile,"0");
        fprintf(nFile,"%c",words[a+1][i]);
        fprintf(nFile,",");
        }
        i++;
    }
    fprintf(nFile,"12\n");
    return 0;
}

int devide(int a){
    int i=0;
    bool variable=false;
    while(words[a-1][i]!=0){
        if(words[a-1][i]=='$'){
            i++;
            if(words[a-1][i]=='a'){fprintf(nFile,"60");}
            if(words[a-1][i]=='b'){fprintf(nFile,"61");}
            if(words[a-1][i]=='c'){fprintf(nFile,"62");}
            if(words[a-1][i]=='d'){fprintf(nFile,"63");}
            if(words[a-1][i]=='e'){fprintf(nFile,"64");}
            if(words[a-1][i]=='f'){fprintf(nFile,"65");}
            if(words[a-1][i]=='g'){fprintf(nFile,"66");}
            if(words[a-1][i]=='h'){fprintf(nFile,"67");}
            if(words[a-1][i]=='i'){fprintf(nFile,"68");}
            if(words[a-1][i]=='j'){fprintf(nFile,"69");}
            if(words[a-1][i]=='k'){fprintf(nFile,"6a");}
            if(words[a-1][i]=='l'){fprintf(nFile,"6b");}
            if(words[a-1][i]=='m'){fprintf(nFile,"6c");}
            if(words[a-1][i]=='n'){fprintf(nFile,"6d");}
            if(words[a-1][i]=='o'){fprintf(nFile,"6e");}
            fprintf(nFile,",");
        } else {


        fprintf(nFile,"0");
        fprintf(nFile,"%c",words[a-1][i]);
        fprintf(nFile,",");
        }
        i++;
    }

    fprintf(nFile,"0E");
    fprintf(nFile,",");
    i=0;

    while(words[a+1][i]!=0){

                   if(words[a+1][i]=='$'){
            i++;
            if(words[a+1][i]=='a'){fprintf(nFile,"60");}
            if(words[a+1][i]=='b'){fprintf(nFile,"61");}
            if(words[a+1][i]=='c'){fprintf(nFile,"62");}
            if(words[a+1][i]=='d'){fprintf(nFile,"63");}
            if(words[a+1][i]=='e'){fprintf(nFile,"64");}
            if(words[a+1][i]=='f'){fprintf(nFile,"65");}
            if(words[a+1][i]=='g'){fprintf(nFile,"66");}
            if(words[a+1][i]=='h'){fprintf(nFile,"67");}
            if(words[a+1][i]=='i'){fprintf(nFile,"68");}
            if(words[a+1][i]=='j'){fprintf(nFile,"69");}
            if(words[a+1][i]=='k'){fprintf(nFile,"6a");}
            if(words[a+1][i]=='l'){fprintf(nFile,"6b");}
            if(words[a+1][i]=='m'){fprintf(nFile,"6c");}
            if(words[a+1][i]=='n'){fprintf(nFile,"6d");}
            if(words[a+1][i]=='o'){fprintf(nFile,"6e");}
            fprintf(nFile,",");
        } else {


        fprintf(nFile,"0");
        fprintf(nFile,"%c",words[a+1][i]);
        fprintf(nFile,",");
        }
        i++;
    }
    fprintf(nFile,"13\n");
    return 0;
}

void print_words(){

    printf("Some code:\n");
      printf("%c",words[4][0]);
      printf("%c",words[4][1]);
      printf("%c",words[4][2]);
      printf("\n");
     // printf("%c",words[1][4]);
    //int i=0;
    //while(i<strlen(words)){
    //i++;
    //}
}
void stop(int i){
    fprintf(nFile,"50\n");
    i++;
}
bool createFile(){
//fname=fname+".mkp";
nFile = fopen("program.opc","w");
	if(nFile == NULL){
		//printf("Не удаётся создать файл для записи программы.\n");
		//printf("\n");
		return false;
		} else{
    printf("Создание файла для записи...\n");
        return true;
		}
}

int equal(int a){
    int i=0;
if(words[a+2][i]=='+' ||words[a+2][i]=='-'||words[a+2][i]=='*'||words[a+2][i]=='/'){
if(words[a-1][i]=='$'){
            i++;
            if(words[a-1][i]=='a'){fprintf(nFile,"40");}
            if(words[a-1][i]=='b'){fprintf(nFile,"41");}
            if(words[a-1][i]=='c'){fprintf(nFile,"42");}
            if(words[a-1][i]=='d'){fprintf(nFile,"43");}
            if(words[a-1][i]=='e'){fprintf(nFile,"44");}
            if(words[a-1][i]=='f'){fprintf(nFile,"45");}
            if(words[a-1][i]=='g'){fprintf(nFile,"46");}
            if(words[a-1][i]=='h'){fprintf(nFile,"47");}
            if(words[a-1][i]=='i'){fprintf(nFile,"48");}
            if(words[a-1][i]=='j'){fprintf(nFile,"49");}
            if(words[a-1][i]=='k'){fprintf(nFile,"4a");}
            if(words[a-1][i]=='l'){fprintf(nFile,"4b");}
            if(words[a-1][i]=='m'){fprintf(nFile,"4c");}
            if(words[a-1][i]=='n'){fprintf(nFile,"4d");}
            if(words[a-1][i]=='o'){fprintf(nFile,"4e");}
            fprintf(nFile,"\n");
            return 0;
}
        } else {

     i=0;

    while(words[a+1][i]!=0){
        fprintf(nFile,"0");
        fprintf(nFile,"%c",words[a+1][i]);
        fprintf(nFile,",");
        i++;
    }

    i=0;

    if(words[a-1][i]=='$'){
            i++;
            if(words[a-1][i]=='a'){fprintf(nFile,"40");}
            if(words[a-1][i]=='b'){fprintf(nFile,"41");}
            if(words[a-1][i]=='c'){fprintf(nFile,"42");}
            if(words[a-1][i]=='d'){fprintf(nFile,"43");}
            if(words[a-1][i]=='e'){fprintf(nFile,"44");}
            if(words[a-1][i]=='f'){fprintf(nFile,"45");}
            if(words[a-1][i]=='g'){fprintf(nFile,"46");}
            if(words[a-1][i]=='h'){fprintf(nFile,"47");}
            if(words[a-1][i]=='i'){fprintf(nFile,"48");}
            if(words[a-1][i]=='j'){fprintf(nFile,"49");}
            if(words[a-1][i]=='k'){fprintf(nFile,"4a");}
            if(words[a-1][i]=='l'){fprintf(nFile,"4b");}
            if(words[a-1][i]=='m'){fprintf(nFile,"4c");}
            if(words[a-1][i]=='n'){fprintf(nFile,"4d");}
            if(words[a-1][i]=='o'){fprintf(nFile,"4e");}
            fprintf(nFile,"\n");
            return 0;
        }




    }
}

int print(int a){
    int i=0;
    fprintf(nFile,"0d,");
if(words[a+1][i]=='$'){
            i++;
            if(words[a+1][i]=='a'){fprintf(nFile,"60");}
            if(words[a+1][i]=='b'){fprintf(nFile,"61");}
            if(words[a+1][i]=='c'){fprintf(nFile,"62");}
            if(words[a+1][i]=='d'){fprintf(nFile,"63");}
            if(words[a+1][i]=='e'){fprintf(nFile,"64");}
            if(words[a+1][i]=='f'){fprintf(nFile,"65");}
            if(words[a+1][i]=='g'){fprintf(nFile,"66");}
            if(words[a+1][i]=='h'){fprintf(nFile,"67");}
            if(words[a+1][i]=='i'){fprintf(nFile,"68");}
            if(words[a+1][i]=='j'){fprintf(nFile,"69");}
            if(words[a+1][i]=='k'){fprintf(nFile,"6a");}
            if(words[a+1][i]=='l'){fprintf(nFile,"6b");}
            if(words[a+1][i]=='m'){fprintf(nFile,"6c");}
            if(words[a+1][i]=='n'){fprintf(nFile,"6d");}
            if(words[a+1][i]=='o'){fprintf(nFile,"6e");}
            fprintf(nFile,",");
            fprintf(nFile,"50\n");
            fprintf(nFile,"\n");
            return 0;
} else {
if(words[a+1][i]!=13){
        while(words[a+1][i]!=0){
    fprintf(nFile,"0");
        fprintf(nFile,"%c",words[a+1][i]);
        fprintf(nFile,",");
        i++;
        }
        fprintf(nFile,"50\n");
        fprintf(nFile,"\n");
}
}

}










