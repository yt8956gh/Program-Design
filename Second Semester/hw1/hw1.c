#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define off 0
#define on 1

int main(int argc,char **argv)
{
	int insen=off,all=off,i=0;
	char *tmpline=NULL,*ptr=NULL,*pattern=NULL,*target=NULL;
	tmpline=(char*)malloc(sizeof(*tmpline)*1000);
	
	
	if(argc==1)	{printf("Usage: substitute [options]... [pattern]\n");return 0;}
	
	for(i=1;i<argc;i++)
	{
		if(argv[i][0]=='-')
		{
			if (argv[i][1]=='i')
			{ insen=on;}
			
			else if (argv[i][1]=='a')
			{ all=on;}
			
			else 
			{ printf("Error: the option is illegal.\n");	return 0;}
		}
		
		else 
		{
			break;
		}
					
		
								
	}

	if((argc-i)!=2)// if the two iterms in last are not pattern
	{
		printf("Error: the command is illegal.\n");
		return 0;	 
	}

	pattern=argv[argc-2];
	target=argv[argc-1];

	while(fgets(tmpline,sizeof(*tmpline)*1000,stdin))
	{	
		
		if(insen==off)
		{
			while((ptr=strstr(tmpline,pattern)))
			{
				*ptr='\0'; 
				printf("%s",tmpline);
				printf("%s",target);
				tmpline=ptr+strlen(pattern);
				
				if(all==off)
				{
					break;
				}
			}
				
			while((ptr=strcasestr(tmpline,pattern)))
			{
				*ptr='\0';
        		        printf("%s",tmpline);
                	        printf("%s",target);
				tmpline=ptr+strlen(pattern);

                       		if(all==off)
                      		{
                     	 	       break;
                     		}
			}
		printf("%s",tmpline);
	}	
		
	free(tmpline);	
	return 0;	
}



		
