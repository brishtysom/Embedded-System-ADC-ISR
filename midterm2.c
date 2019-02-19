//Midterm 2 - Question 4 - bxs151130

#include <midterm2.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <openssl/sha.h>
#include <string.h>

void signal_handler();

double step_voltage =0;
const int ADC_BITS = 12;
const int REFERENCE_VOLT = 9;
const int MAX_COUNT= 4096;  //2^(bits of resolution = 12)
float voltage = 0;
 char *netid = "bxs151130";
int interrupt =0;

int main() {



  int a = 0;
 a = cloud_ADC_init(netid);

 printf("%d\n", a);

 if (!a){ printf("ADC initialized\n"); }
 else { printf("not initialized\n"); }

while(!interrupt){ 
printf("waiting\n");
signal(SIGINT, signal_handler);
   sleep(10);
 }



 return 0;
}


void signal_handler(){

interrupt =1;
  int count = 0;
  count = get_ADC_data();

  if (count!= 0){
 
    step_voltage = 9.0/(4096-1);
    printf("%f\n", step_voltage);

printf("%.2f\n",(float) count);


 
 voltage = count * (float)step_voltage;
 printf("%f\n", voltage);

 char buff[25];
 sprintf(buff, "%s%d%d%d%.2f", netid, ADC_BITS, REFERENCE_VOLT, count, voltage);
 printf("Count received: %d\n", count);
 printf("Calculated voltage: %.2f\n", voltage);
 printf("Max count: %d\n", (MAX_COUNT-1));
 printf("Step Voltage: %f\n", step_voltage);
 printf("Before SHA1 funct: %s\n", buff);
 printf("Formatted SHA1: ");
  
 unsigned char hash[SHA_DIGEST_LENGTH];
 SHA1(buff,strlen(buff),hash);


 int i;
 for(i=0; i< strlen(hash); i++){
   if(i%4 == 0 && i != 0){
     printf("-");
   }
   printf("%02x",hash[i]);

   }
printf("\n");

}


}
