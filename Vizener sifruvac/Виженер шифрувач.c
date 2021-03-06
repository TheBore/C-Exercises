#include<stdio.h>

/*
Ваша задача е да го имплементирате Виженер (Vigenère) шифрувачот за енкрипција на текст. 
Виженер шифрувачот функционира на следниов начин:
Имаме една порака (низа од знаци) која ни го претставува оригиналниот текст. Имаме еден клуч (низа од позитивни цели броеви и 0) со должина N, кој ни служи за шифрирање на оригиналната порака. Оригиналната порака се дели на блокови од знаци со должина N и секој од знаците се поместува за онолку позиции нанапред, колку што изнесува вредноста на соодветната позиција во клучот. Пример: 

блок: (a, b, c) -> клуч: (2, 1, 5) -> шифрирана порака: (c, c, h) 

Од стандарден влез се внесува еден позитивен цел број N кој ја означува должината на клучот. Потоа се внесуваат сите елементи од клучот. 
Во наредната линија се внесува еден позитивен цел број M кој ја означува должината на пораката, а потоа се внесуваат сите карактери кои ја сочинуваат пораката. 

ASCII: a = 97, z = 122 
Сите пораки се составени само од мали букви. 
На излез да се отпечати шифрираната порака.
*/

#define MAX 100

int main (void){
     int cipher[MAX];
     char text[MAX];

     int cipher_length;
     int text_length;
     int i;

     scanf("%d", &cipher_length);

     for (i=0;i<cipher_length; ++i){
         scanf("%d", &cipher[i]);
     }

     scanf("%d\n", &text_length);

     for (i=0;i<text_length; ++i){
         scanf("%c", &text[i]);
     }

     char c;
	 
     text[text_length]='\0';
    
     for (i=0;i<text_length; ++i){
         c = text[i] - 'a';
         c+= cipher[i%cipher_length];
         text[i]= c%26 + 'a';
     }


     puts(text);
}
