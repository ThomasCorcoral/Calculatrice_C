#include "calclib.h"

void printString(char *s){
    while(*s!=(char)0){
        putchar(*s);
        s++;
    }
    putchar(' ');
}
void readString(char *res){
    char c;
    do{
        c=getchar();
        *res=c;
        res++;
    }while(c!='\n');
    *(res-1)=(char)0;
}

char forDigit(int nombre,int base){
    if(base <= 16 && 2 <= base && nombre < base)
    {
        if(nombre >=0 && nombre <=9 ){
            return (char)(nombre) +'0';
        }
        else if(nombre >=10 && nombre <=15){
			return (char)(nombre-10) +'A';
        }
    }
    return '\0';
}		

int digit(char caractere,int base){
    
    int retour =0xFFFFFFFF;
    if(base <= 16 && 2 <= base)
    {
        if(caractere >= '0' && caractere <= '9'){
            retour = (int)(caractere) - '0';
        }
        else if(caractere >= 'A' && caractere <= 'F'){
            retour = (int)(caractere) -'A' +10;
        }
        else if(caractere >= 'a' && caractere <= 'f'){
            retour = (int)(caractere) -'a' +10;
        }
        if( retour >= base)
        {
            return 0xFFFFFFFF;
        }
    }
    return retour;
}

int toInt(int nombre,int base,char *res){
	
	if(base < 2 || base >16 || res == (char)0 ){	return 1;}
	
    int nombre1;
	int neg=1;
	if((nombre>>31)==0){
		nombre1 = nombre;
		nombre=-nombre;
		neg=0;
	}else{
		nombre1=-nombre;
		res++;
	}

	do{
		nombre1 = nombre1/base;
		res++;
	}while (nombre1!=0);
	
	*res='\0';
	
	do{
		res--;
		*res=forDigit(-(nombre%base),base);
		nombre = (nombre/base);
	}while(nombre!=0);
	if(neg==1){
		res--;
		*res='-';
	}
	return 0;
	
}
int parseInt(char *ch,int base,int *resultat){
    
	if(base < 2 || base >16 || resultat == (char)0 || ch == (char)0)
    {
        return 1;
    }
	
	long res=0;
	_Bool nega=0;
	if(*ch=='-'){
		ch++;
		nega =1;
	}
	if(*ch=='+'){ ch++;}
	
	while(*ch!='\0'){
		int verifDigit = digit(*ch,base);
		if (verifDigit ==-1){return 1;}
		res=res*base+verifDigit;
		if(res > 2147483648 || res< -2147483647){ return 1;}
		ch++;
	}
    
	
	*resultat=(int)res;
	if(nega){*resultat=-(*resultat);}
    return 0;
}
int inverse8bits(int nbr)
{
    int res = 0;
    do
    {
        res = res << 8;
        res += nbr & 0xFF;
        nbr = nbr >> 8;
    }while(nbr != 0);
    return res;
}
int inverse16bits(int nbr)
{
    int res = 0;
    do
    {
        res = res << 16;
        res += nbr & 0xFFFF;
        nbr = nbr >> 16;
    }while(nbr != 0);
    return res;
}
int rotationGauche(int nbr){
    return ((nbr<<1)| ((unsigned)nbr >> 31));
}
int rotationDroite(int nbr){
    return (((unsigned)nbr>>1)| (nbr << 31));
}
int operation(char op)
{
    switch(op)
    {
        case '+' : return 1;
        case '-' : return 2;
        case '*' : return 3;
        case '/' : return 4;
        case '%' : return 5;
        case '&' : return 6;
        case '|' : return 7;
        case '^' : return 8;
        case '~' : return 9;
        case 'i' : return 10;
        case 'I' : return 10;
        case '<' : return 11;
        case '>' : return 12;
        case 'a' : return 13;
        case 'A' : return 13;
        case 'h' : return 14;
        case 'H' : return 14;
        case 's' : return 15;
        case 'S' : return 15;
        case 'l' : return 16;
        case 'L' : return 16;
        case 'r' : return 17;
        case 'R' : return 17;
        case '1' : return 18;
        case '2' : return 19;
        case 'b' : return 20;
        case 'B' : return 20;
        case 'q' : return 21;
        case 'Q' : return 21;
        default : return 0;
    }

}
int calcul(int n1,int n2,int *resultat,int operation)
{
    if(resultat != (char)0 )
    {
        switch(operation)
        {
            case 1 : *resultat = n1 + n2; break;
            case 2 : *resultat = n1 - n2; break;
            case 3 : *resultat = n1 * n2; break;
            case 4 : *resultat = n1 / n2; break;
            case 5 : *resultat = n1 % n2; break;
            case 6 : *resultat = n1 & n2; break;
            case 7 : *resultat = n1 | n2; break;
            case 8 : *resultat = n1 ^ n2; break;
            case 9 : *resultat = ~n1 ; break;
            case 10 : *resultat = ~(n1)+1; break; 
            case 11 : *resultat = n1 << 1; break;
            case 12 : *resultat = (unsigned)n1>>1; break;
            case 13 : *resultat = n1 >> 1; break;
            case 14 : *resultat = inverse8bits(n1); break;
            case 15 : *resultat = inverse16bits(n1); break;
            case 16 : *resultat = rotationGauche(n1) ; break;
            case 17 : *resultat = rotationDroite(n1); break;
            default : return 1;
        }
        return 0;
    }
    return 1;
}
void calculatrice(int n1,int n2,int resultat,int base)
{
    char ope[20];
    for( ; ;)
    {

        printString("n1 - n2 - base - résultat\n");

        char prnt[20];

        toInt(n1,base,prnt);
        printString(prnt);
        toInt(n2,base,prnt);
        printString(prnt);
        toInt(base,10,prnt);
        printString(prnt);
        toInt(resultat,base,prnt);
        printString(prnt);
        printString("\nOperation addition +, soustraction - ......\n");
        printString("Entrez une operation\n");

        readString(ope);

        int i_ope = operation(ope[0]);

        if(i_ope < 18)
        {
            calcul(n1,n2,&resultat,i_ope);
        }
        else
        {
            char new[20];
            switch(i_ope)
            {
                case 18 : readString(new); 
                            while(parseInt(new, base, &n1) == 1)
                            {
                                printString("Nombre incorrecte \n"); 
                                readString(new);
                            }; break;
                case 19 : readString(new); parseInt(new, base, &n2) ;
                            while(parseInt(new, base, &n1) == 1)
                            {
                                printString("Nombre incorrecte \n");
                                readString(new); 
                            }; break;
                case 20 : readString(new); parseInt(new, 10, &base); 
                          while(base > 15 || base < 2)
                          {
                            printString("\nBase incorrecte ! \n");
                            readString(new); 
                            parseInt(new, 10, &base);  
                          } ; break;
                case 21 : return ;
                default : return ;
            }
        }
    }
}
