#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000

struct nodes{
  int number;
  int value;
}nodes[N];


void remember_nodes(int number, int value){
  int i = 0;
  for (i = 1; i <= number; i++) {
    if (nodes[i].value == value){
      break;} else {
    if (nodes[i].value == 0) {
      nodes[i].value = value;
      nodes[i].number = i;
      break;
    }
}
  }
}

int check_node(int number,int value){
  int i = 0;
  for (i = 1; i <= number; i++) {
    if (nodes[i].value == value){
      return 1;
      break;
    } else {      return 0;    }
  }
}


void print_nodes_and_values(int number){
  int i = 0;
  FILE *fp;


  fp = fopen("gr1.txt","a");
  for ( i = 1; i <= number; i++) {
  fprintf(fp, "node%d [label = \" %d \" ];\n",nodes[i].number,nodes[i].value );
  }

fclose(fp);
}


void print_connection(int count,int number1, int number2){
  int i = 0;
  int j = 0;
  FILE *fp;

  fp = fopen("gr1.txt","a");
  for (i = 1; i <= count; i++) {
    for (j = 1; j <= count; j++)
  if ((number1 == nodes[i].number)&&(number2 == nodes[j].number)){
    fprintf(fp, "node%d -- node%d; \n",nodes[i].number,nodes[j].number );
    number1 = nodes[i].value;
    number2 = nodes[j].value;
  } //else { printf("Error \n");}
  }
}

/*
void check_svaz(int number, int i){

  if (number > 0.5*((i - 2)*(i - 1))){
    printf("svaz\n");
  } else {
    printf("ne svaz \n");
  }

}
*/
/*
int find_value(int num1, int num2,int count){
  for (int i = 0; i < count; i++)
      for (int j = 0; j < count; j++)
    if ((num1 == nodes[i].number)&&(num2 == nodes[j].number)){
      num1 = nodes[i].value;
      num2 = nodes[j].value;
    }
}
*/
int main(void) {
  int value;
  int connection1 = 1;
  int i = 0;
  int a = 0;
  int connection2;
  int number;
  int k = 0;
  int same = 0;
  int* con1;
  int* con2;
  FILE *fp;
  FILE *cashe;


  fp = fopen("gr1.txt","w");
  fprintf(fp, "%s\n","graph G {" );
  fclose(fp);
  fp = fopen("gr1.txt","a");


  printf("Write number of nodes \n");

  scanf("%d",&number);

  con1 = (int*) calloc(pow(2,number),sizeof(int));
  con2 = (int*) calloc(pow(2,number),sizeof(int));



  printf("Write node's values: \n");
  while (k < number) {
    scanf("%d",&value);

    remember_nodes(number, value);

    if (check_node(number,value) == 0) {
      k++;
    }
}
k = 0;

    print_nodes_and_values(number);
    printf("\n Here Are you node's values: \n \n" );
    printf("|number|value| \n");
    for (i = 1; i <= number; i++) {
      printf("|  %d  |  %d  | \n",(nodes[i].number), nodes[i].value);
    }
i = 0;
printf("\n Write connections (write 0 to end)\n");
  while ((connection1 != 0)&&(connection2 != 0)){
  scanf("%d %d\n",&connection1,&connection2);
  print_connection(number,connection1,connection2);
  k++; if ((connection1 == 0)||(connection2 == 0)) {
  }else{
//  find_value(connection1, connection2,number);
for (int i = 0; i <= number; i++)
    for (int j = 0; j <= number; j++)
if ((connection1 == nodes[i].number)&&(connection2 == nodes[j].number)){
connection1 = nodes[i].value;
connection2 = nodes[j].value;
}

  con1[a] = connection1;
  con2[a] = connection2;
  a++;}
}

//check_svaz(number,i);



 fclose(fp);

 i = 0;
 cashe = fopen("cashe1.txt","w");
 while (con1[i]!=0) {
   fprintf(cashe,"%d %d \n",con1[i],con2[i]);
 i++;
 }
 fclose(cashe);

  // system("dot -Tpng gr1.txt -o gr1.png");
// system("xdg-open gr1.png");
  return 0;
}
