#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

void list_files(char * d){
  struct dirent *entptr;
  DIR* dirx = opendir(d);
  DIR* curr_dir = NULL;
  while (entptr  = readdir(dirx)){
    printf("%s\n", entptr->d_name);
    if(curr_dir = opendir(entptr->d_name)){
      printf(" is also a directory\n");
      close(curr_dir);
    }
  }
  closedir(dirx);

}

void scan(){
}

int main(){
  list_files("anything");
}
