/* Muzammil arshad
  2       1616513
  3          muzammil
  4             B1
  5                Ildar Akhmetov
  6                   H03
  7                      CMPUT 201 Student Submission License Version 2.0
  8                      Copyright 2021 <Muzammil Arshad>
  9                      Unauthorized redistribution is forbidden under all circumstances. Use of this software without explicit authorization from the author and the CMPUT 201 Instructor is prohibited.
 10                      This software was produced as a solution for an assignment or lab in the course CMPUT 201 - Practical Programming Methodology at the University of Alberta, Canada. This solution is confidential and remains confidential after it is submitted for grading. The course staff has the right to run plagiarism-detection too    ls on any code developed under this license, even beyond the duration of the course.
 11                      Copying any part of this solution without including this copyright notice is illegal.
 12                      If any portion of this software is included in a solution submitted for grading at an educational institution, the submitter will be subject to the plagiarism sanctions at that institution.
 13                      This software cannot be publicly posted under any circumstances, whether by the original student or by a third party. If this software is found in any public website or public repository, the person finding it is kindly requested to immediately report, including the URL or other repository locating information, to     the following email addresses:
 14                            nadi@ualberta.ca
 15                                  ildar@ualberta.ca */
 16
 17
 18
 19
 20 #include <stdio.h>
 21 #include <stdlib.h>
 22 #include <string.h>
 23 #include <stdbool.h>
 24 void encrypt(FILE *fp2,int input_file,int input_num,char plain[26],char cipher[26]);
 25 void decrypt(FILE *fp2,int input_file,int input_num,char plain[26],char cipher[26]);
 26 int main(int argc, char *argv[]) {
 27     int i;
 28     int j;
 29     int mapping;   //will be index for mapping csv file
 30     int input_file; //will be the index for the input_file argument
 31     int mode;//index for mode
 32     int line_count=0;
 33     int el;
 34 //  int a;
 35     int let_count_1=0;
 36     int let_count_2=0;
 37     FILE *fp1;
 38     FILE *fp2;
 39 //  char alphabet[26]={'a'};
 40     char plain[26]={'2'};
 41     char cipher[26]={'2'};
 42     // start of command line argument analysis
 43     if(argc>7 || argc<7){
 44         fprintf(stderr,"Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>");
 45         exit(7);
 46     }
 47     for (i=1;i<6;i=i+2)
 48     {
 49         if(strcmp(argv[i],"-t")==0){
 50             mapping=i+1;
 51             //gives length of total argument
 52             int size= strlen(argv[mapping]);
 53             /*const char is a mutable pointer, it allows us to point to the last 3
 54             characters of the arg, then compare */
 55             const char *ext= &argv[mapping][size-3];
 56             //checking if last 3 chars after . are csv
 57             if(strcmp(ext,"csv")!=0){
 58                 fprintf(stderr,"Usage: ./encrypt -t <mappingfile> -m <encryption mode> -i <inputfile>");
 59                 exit(7);
 60             }
 61
 62         }
 63         else if(strcmp(argv[i],"-i")==0){
 64             input_file=i+1;
 65             int len= strlen(argv[input_file]);
