#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

void list_files(char *);

int file_size(char* ,struct stat*);

void list_files(char * d){
  int dirf_size = 0;
  int err;
  struct stat file;
  
  struct dirent *entptr;
  DIR* dirx = opendir(d);
  DIR* curr_dir = NULL;

  while (entptr  = readdir(dirx)){
    if(curr_dir = opendir(entptr->d_name)){
      printf("%s", entptr->d_name);
      printf(" is a directory\n");
      closedir(curr_dir);
    }
    else{
      err = stat(entptr->d_name, &file);
      dirf_size += file.st_size;
      printf("%s", entptr->d_name);
      printf(" is a regular file\n");
    }
  }
  
 
  printf("Total Directory Size: %d Bytes\n", dirf_size);
  closedir(dirx);

}




int main(){
  printf("Statistics for directory: anything\n");
  list_files("anything");
  printf("\n");
  printf("Statistics for currurent directory\n");
  list_files("./");
}
