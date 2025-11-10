#include <stdio.h>

int main(){
  int c;
  long nc, nl;
  nc=0;
  nl=0;

  while((c=getchar()) != EOF){
    if(c == '\n'){
      ++nl;
      printf("Number of Lines: %ld\n", nl);
    } else {
      ++nc;
      printf("Number of Characters: %ld\n", nc);
      
    }
  }
  

  return 0;
}
