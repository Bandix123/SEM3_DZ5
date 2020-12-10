#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define MAX(a, b) (a >= b) ? a : b

struct cashe{
  int number1;
  int number2;
  int number3;
  int number4;
}cashe[N];

int main(void){
FILE *fp;
FILE *cashe1;
FILE *cashe2;
int i = 0;
int j = 0;
int count = 0;
int count1 = 0;
int count2 = 0;



printf("First graph: \n");
system("./graph1");
printf("Second graph \n");
system("./graph2");

FILE *fip;
fip = fopen("gr1.txt","a");
fprintf(fip,"\n } \n");
fclose(fip);

fip = fopen("gr2.txt","a");
fprintf(fip,"\n } \n");
fclose(fip);


i = 0;
cashe1 = fopen("cashe1.txt","r");
while(fscanf(cashe1,"%d %d \n",&cashe[i].number1,&cashe[i].number2)!=EOF){
  i++;
}
count1 = i;
i = 0;
cashe2 = fopen("cashe2.txt","r");
while(fscanf(cashe2,"%d %d \n",&cashe[i].number3,&cashe[i].number4)!=EOF){
  i++;
}
count2 = i;

count = MAX(count1,count2);

fp = fopen("finalgraph.txt","w");
fprintf(fp, "%s\n","graph G {" );
fclose(fp);
fp = fopen("finalgraph.txt","a");

for (int i = 0; i < count; i++)
  for (int j = 0; j < count; j++){
    if ((cashe[i].number1 == cashe[j].number3)&&(cashe[i].number2 == cashe[j].number4)) {
//      fprintf(fp, "%d -- %d ;\n",cashe[i].number1,cashe[i].number2);
  break;
  //    printf("%d -- %d \n",cashe[i].number1,cashe[i].number2);
}else if ((cashe[i].number1 != cashe[j].number3)&&(cashe[i].number2 != cashe[j].number4)) {
  if ((cashe[i].number1 != 0)&&(cashe[i].number2 != 0))
    fprintf(fp, "%d -- %d ;\n",cashe[i].number1,cashe[i].number2);
    break;
}
}
//fprintf(fp, "\n___0____________0____ \n" );
for (int i = 0; i < count; i++)
  for (int j = 0; j < count; j++){
    if ((cashe[i].number3 != cashe[j].number1)&&(cashe[i].number4 != cashe[j].number2)) {
//  fprintf(fp, "%d -- %d ;\n",cashe[i].number1,cashe[i].number2);
//    printf("%d -- %d \n",cashe[i].number1,cashe[i].number2);
  if ((cashe[i].number3 != 0)&&(cashe[i].number4 != 0))
    fprintf(fp, "%d -- %d ;\n",cashe[i].number3,cashe[i].number4);
    break;
}
}
 fprintf(fp, "\n }" );
 fclose(fp);

system("dot -Tpng gr1.txt -o gr1.png");
system("dot -Tpng gr2.txt -o gr2.png");
system("dot -Tpng finalgraph.txt -o finalgraph.png");


system("xdg-open gr1.png ");
system("xdg-open gr2.png ");
system("xdg-open finalgraph.png ");

system("rm cashe1.txt");
system("rm cashe2.txt");
}
