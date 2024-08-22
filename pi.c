#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void endPage();
void createPage(char *s);
char *stringg(int nbr);
char **str(int nbr,int nb);
void transPlus(char *str);
int transPoint(char *str1);
void classerIP(char *str);
//-----------------------------------------------------
int main()
{

    char *ligne;
    char *ligne1;
    int nbPoint=0;
    ligne=stringg(256);
    ligne1=stringg(256);
    ligne=getenv("QUERY_STRING");
    if(ligne==NULL)
    	printf("Aucune QUERY_STRING");

    else{ 
    //fgets(ligne1,256,stdin);
        sscanf(ligne,"ip=%s",ligne1);
        transPlus(ligne1);
        nbPoint=transPoint(ligne1);
        if(nbPoint!=4)
        {
            createPage("Verrification IP");
            printf("<CENTER>ENB point INVALID !!<br><br>\n");
            printf("Pour revenir au<a href='ip.html'><b> page d'acueil</b><a><br></CENTER>");
            endPage();
           // exit(1);
        }
        else{
           classerIP(ligne1); 
        }
        

}
return (EXIT_SUCCESS);
}
//-------------------------------------------

void createPage(char *s){
    printf ("Content-Type:text/html\n\n");
    printf ("<HTML>\n");
    printf ("<HEAD>\n");
    printf ("<TITLE>%s</TITLE>\n",s);
    printf ("</HEAD>\n");
    printf ("<BODY>\n");

}
void endPage(){
    printf ("</BODY>\n");
    printf ("</HTML>\n");
}

char *stringg(int nbr)
{
	char *tab=NULL;
	tab=(char*)malloc(nbr*sizeof(char));
	if(tab == NULL)
	{
		printf("Erreur d'allocation");
		exit(1);
	}
	return (tab);
}

char **str(int nbr,int nb)
{
	char **tab=NULL;

	tab=(char**)malloc(nbr*sizeof(char*));
    for(int i=0;i<nb;i++)
        tab[i]=(char*)malloc(nbr*sizeof(char));
	if(tab == NULL)
	{
        
		printf("Erreur d'allocation\n");
		//exit(1);
	}
	return (tab);
}

void transPlus(char *str1)
{     
    char **token;
    token=str(10,100); 
     
    char *subtoken=strtok(str1,"+");
    int i=0;
        while(subtoken!=NULL)
        {
            strcpy(token[i],subtoken);
            subtoken=strtok(NULL,"+");
            i++;
        }
    int n=i;
    for(i=1;i<n;i++)
    {
        strcat(str1," ");
        strcat(str1,token[i]);
    }
}

int transPoint(char *str1)
{     
    char **token;
    int nbPoint=0;
    int tab[4];
    token=str(10,100); 
    char *subtoken=strtok(str1,".");
        while(subtoken!=NULL)
        {
            strcpy(token[nbPoint],subtoken);
            subtoken=strtok(NULL,".");
            nbPoint++;
        }
    int n=nbPoint;

   char *endptr;
   int ipp;
   int ok=0;
    for(nbPoint=0;nbPoint<n;nbPoint++)
    {
        ipp=strtol(token[nbPoint],&endptr,10);
        if((endptr !=token[nbPoint] && *endptr =='\n') && ((ipp<0) || (ipp>255)))
        {
            ok=1;
        }
        else
        {
            strcat(str1,token[nbPoint]); 
        }
    }
if(ok==0)
{
    return nbPoint;
}
else
{
    createPage("Verrification IP");
    printf("<br><br><br><br><br>\n<hr><hr>\n");
    printf("<CENTER>ENombre maximale de Bits depassé<br>\n");
    printf("Pour revenir au<a href='ip.html'><b> page d'acueil</b><a><br></CENTER>");
    endPage();
   // exit(1);
}
}


void classerIP(char *str){
    // convertir l entre en entier
    char *endptr;
    int veriefie=0;
    int ip=strtol(str,&endptr,10);
/*     if(endptr !=str && *endptr =='\n' && ip>=0 )
        veriefie=1;

    if( veriefie==1)
    { */
        if (ip>=0 && ip<=127255255255)
        {

        createPage("Verrification IP");
        printf("<br><br><br><br><br>\n<hr><hr>\n");
        printf("<CENTER>Evotre IP est de classe A<br><br>\n");
        printf("Pour revenir au<a href='ip.html'><b> page d'acueil</b><a><br></CENTER>");
        printf("<br><br><br><br><br>\n<hr><hr>\n");
        endPage();}
       
     else if (ip>127255255255 && ip<=191255255255)
     {
     createPage("Verrification IP");
        printf("<br><br><br><br><br>\n<hr><hr>\n");
        printf("<CENTER>Evotre IP est de classe B<br><br>\n");
        printf("Pour revenir au<a href='ip.html'><b> page d'acueil</b><a><br></CENTER>");
        printf("<br><br><br><br><br>\n<hr><hr>\n");
        endPage();
        }
    else if (ip>191255255255 && ip<=223255255255)
    {
    createPage("Verrification IP");
         printf("<br><br><br><br><br>\n<hr><hr>\n");
        printf("<CENTER>Evotre IP est de classe C<br><br>\n");
        printf("<br><br><br><br><br>\n<hr><hr>\n");
    endPage();
    }
    else if (ip>223255255255 && ip<=239255255255)
    {
    createPage("Verrification IP");
        printf("<br><br><br><br><br>\n<hr><hr>\n");
        printf("<CENTER>Evotre IP est de classe D<br><br>\n");
        printf("Pour revenir au<a href='ip.html'><b> page d'acueil</b><a><br></CENTER>");
        printf("<br><br><br><br><br>\n<hr><hr>\n");
    endPage();
    }
    else if (ip>239255255255 && ip<=255255255255)
    {
        createPage("Verrification IP");
        printf("<br><br><br><br><br>\n<hr><hr>\n");
        printf("<CENTER>votre IP est de classe E<br><br>\n"); 
        printf("Pour revenir au<a href='ip.html'><b> page d'acueil</b><a><br></CENTER>");
        printf("<br><br><br><br><br>\n<hr><hr>\n");
        endPage();
   }
     else
    { 
        createPage("Verrification IP");
        printf("<br><br><br><br><br>\n<hr><hr>\n");
        printf("<CENTER>Eenter a valid Ip<br><br></CENTER>E");
         printf("Pour revenir au<a href='ip.html'><b> page d'acueil</b><a><br></CENTER>");
        printf("<br><br><br><br><br>\n<hr><hr>\n");
        endPage();
    }

}