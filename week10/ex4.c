#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>

#define N 10

int main(){
	FILE* fout = fopen("ex4.txt", "w");
	DIR * dirp = opendir("tmp");
	if (dirp == NULL) { return 1;}

	struct dirent* dp;
	struct dirent name[N]; //array for storing all files in directory tmp
	int i = 0;

	while ((dp = readdir(dirp)) != NULL) {
		name[i] = *dp;
		i++;
	}

	//checking equality of inode numbers
	for (int j = 0; j < i; ++j)
	{
		for (int k = j + 1; k < i && name[j].d_ino != 0; ++k)
		{
			//if we find equal inode numbers of 2 files, continue to 
			//search for files with same inode number
			//when the name of file is printed, then mark its inode number 
			//as visited, set inode to 0 with aim to not print it in the future again
			if(name[j].d_ino == name[k].d_ino){
				fprintf(fout, "%s ", name[j].d_name);
				for (;k < i; ++k)
				{
					if(name[j].d_ino == name[k].d_ino){
						fprintf(fout, "%s ", name[k].d_name);
						name[k].d_ino = 0;
					}
				}
				name[j].d_ino = 0;
				fprintf(fout, "\n");
				
			}
		}
	}
	return 0;
}