#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

void fileSizer(long bytes){
	printf("File Size: ");
	long workbytes = bytes;
	if (bytes > 1024 * 1024 * 1024){
		printf("%li gigabytes, ", workbytes>>30);
		workbytes = workbytes%1024;
	}
	if (bytes > 1024 * 1024){
		printf("%li megabytes, ", workbytes>>20);
		workbytes = workbytes%1024;
	}
	if (bytes > 1024){
		printf("%li kilobytes, ", workbytes>>10);
		workbytes = workbytes%1024;
	}
	printf("%li bytes\n", workbytes);
}

void printPerms(int octal){
	int user = (octal>>6) &111;
	int group = ((octal>>3) &100111);
	int public = octal &111;
	printf("User Permissions: %#o\n", user);
	printf("User Permissions: %#o\n", group);
	printf("User Permissions: %#o\n", public);


}

void printStat(char *path){
	struct stat buffer;
	int debug = stat(path, &buffer);

	//printf("Debug: %i\n", debug);

	struct tm tm = *localtime(&buffer.st_atime);
	

	fileSizer(buffer.st_size);
	printPerms(buffer.st_mode);
	//printf("Permissions: %#o\n", buffer.st_mode);
	printf("Last Access: %d-%d-%d %d:%d:%d\n", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

}



int main(){
	char file[30] = "stat.c";
	printStat(file);

}

// If you want to include text "as is" like the one you are just reading
// all you need to is use the PRE tag. This will allow you to display
// text exactly as you type it.  It will give you a line break wherever
// you press Enter, like here....
// This is very useful for pre-formatted text like tables, etc. For example:

// STUDENT ID    NAME                RECITATION SECTION
// ----------    -----------------   ------------------
// eb48          Evelyn Barry                 A
// josee         Alberto Espinosa             B
// sh6f          Se-Joon Hong                 C

//       \|||/
//       (o o)
// --ooO--(_)--Ooo--
 
// You signal the end of the pre-formatted text with the /PRE tag.
// If you want to include text "as is" like the one you are just reading
// all you need to is use the PRE tag. This will allow you to display
// text exactly as you type it.  It will give you a line break wherever
// you press Enter, like here....
// This is very useful for pre-formatted text like tables, etc. For example:

// STUDENT ID    NAME                RECITATION SECTION
// ----------    -----------------   ------------------
// eb48          Evelyn Barry                 A
// josee         Alberto Espinosa             B
// sh6f          Se-Joon Hong                 C

//       \|||/
//       (o o)
// --ooO--(_)--Ooo--
 
// You signal the end of the pre-formatted text with the /PRE tag.
// If you want to include text "as is" like the one you are just reading
// all you need to is use the PRE tag. This will allow you to display
// text exactly as you type it.  It will give you a line break wherever
// you press Enter, like here....
// This is very useful for pre-formatted text like tables, etc. For example:

// STUDENT ID    NAME                RECITATION SECTION
// ----------    -----------------   ------------------
// eb48          Evelyn Barry                 A
// josee         Alberto Espinosa             B
// sh6f          Se-Joon Hong                 C

//       \|||/
//       (o o)
// --ooO--(_)--Ooo--
 
// You signal the end of the pre-formatted text with the /PRE tag.
// If you want to include text "as is" like the one you are just reading
// all you need to is use the PRE tag. This will allow you to display
// text exactly as you type it.  It will give you a line break wherever
// you press Enter, like here....
// This is very useful for pre-formatted text like tables, etc. For example:

// STUDENT ID    NAME                RECITATION SECTION
// ----------    -----------------   ------------------
// eb48          Evelyn Barry                 A
// josee         Alberto Espinosa             B
// sh6f          Se-Joon Hong                 C

//       \|||/
//       (o o)
// --ooO--(_)--Ooo--
 
// You signal the end of the pre-formatted text with the /PRE tag.