#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>


void list_files(char *);
int file_size(char *, struct stat *);
void print_size(off_t);

int main(){
  /*
  printf("Statistics for directory: anything\n");
  list_files("anything");
  printf("\n");
  */
  
  printf("Statistics for current directory\n");
  list_files("./");
  printf("\n");
  
  /*
  printf("Testing statistics for invalid directory\n");
  list_files("test");
  */

  return 0;
}

void list_files(char *d){  
  DIR *dirx = NULL, *curr_dir = NULL;
  off_t dir_size = 0;
  
  struct stat file;
  struct dirent *entry = NULL;
  
  if(dirx = opendir(d)){
    while(entry  = readdir(dirx)){
      if(curr_dir = opendir(entry->d_name)){	
	printf("Directory: %s\n", entry->d_name);	
	closedir(curr_dir);
      } else {
	stat(entry->d_name, &file);
	dir_size += file.st_size;
	printf("Reg file: %s\n", entry->d_name);
      }
    }
    
    print_size(dir_size);
    closedir(dirx);
  } else {
    printf("Error: %s\n", strerror(errno));
  }
}

void print_size(off_t size){
  char *units[5] = {"B", "KB", "MB", "GB", "TB"};
  int count = 0, remainder = 0;
  
  while(size / 1000){
    remainder = size % 1000;
    size /=  1000;
    count++;
  }  

  if((remainder / 100) >= 5){
    size++;
  }

  printf("Total directory size: %d%s\n", (int) size, units[count]);
}
