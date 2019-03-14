/*O objetivo é receder um certo ano e exibir se esse ano é bissexto ou não, a data em que a pascoa cai e o calendário complto desse ano*/
/*  Y-ano
    G-n°aureo
    C século
    E nº de dias para transformar lunar em solar
*/


#include<stdio.h>
int main(){
int ano,g,c,x,z,e,n,y,d,sn,pascoa,d1,i,m[6][7][12],lin,col,mes,qtddias=0,dia=0,anon[12],anob[12],qtdd;

anon[0]=31;
anon[1]=28;
anon[2]=31;
anon[3]=30;
anon[4]=31;
anon[5]=30;
anon[6]=31;
anon[7]=31;
anon[8]=30;
anon[9]=31;
anon[10]=30;
anon[11]=31;

anob[0]=31;
anob[1]=29;
anob[2]=31;
anob[3]=30;
anob[4]=31;
anob[5]=30;
anob[6]=31;
anob[7]=31;
anob[8]=30;
anob[9]=31;
anob[10]=30;
anob[11]=31;
scanf("%d",&y);
	g=(y%19)+1;
	c=(y/100)+1;
	x=((3*c)/4)-12;
	z=(((8*c)+5)/25)-5;
	e=((11*g)+20+z-x)%30;

if((e==25)||(g>11)||(e==24)) e++;
	
	n=44-e;
if(n<21) n=n+30;
	
	d=((5*y)/4)-(x+10);
	n=(n+7)-((d+n)%7);

	if(n>31)
		pascoa=n-31;
	else 
		pascoa=n;
ano=y;
if((ano%100)==0)
	ano=ano/100;
if((ano%4)==0)
	sn=1;
else
	sn=0;

		if(sn==1){//ano bissexto
			if(n>31){//abril
				i=pascoa+29+62;
				if((i%7)==0) 	d1=1; //segunda
				else if((i%7)==1)d1=0; //domingo
				else if((i%7)==2)d1=6; //sabado
				else if((i%7)==3)d1=5; //sexta
				else if((i%7)==4)d1=4; //quinta
				else if((i%7)==5)d1=3; //quarta
				else if((i%7)==6)d1=2; //terça
				}
				
			else{//março	
				i=pascoa+29+31;
				if((i%7)==0) 	d1=1; //segunda
				else if((i%7)==1)d1=0; //domingo
				else if((i%7)==2)d1=6; //sabado
				else if((i%7)==3)d1=5; //sexta
				else if((i%7)==4)d1=4; //quinta
				else if((i%7)==5)d1=3; //quarta
				else if((i%7)==6)d1=2; //terça
				}


		for(mes=0;mes<12;mes++){

			qtddias=anob[mes];
			dia=1;
			for(col=0;col<7;col++){
				if(col< d1){
					 m[0][col][mes]=0;
					
				}	
				else{
					m[0][col][mes]=dia;
					dia++;
				}
			}
			for(lin=1;lin<6;lin++){
				for(col=0;col<7;col++){
					if(dia<=qtddias){
						m[lin][col][mes]=dia;
						dia++;
					}
					else m[lin][col][mes]=0;
				}
			}
qtdd = d1 + qtddias;
d1 = qtdd % 7;	
		}

printf("Calendario do ano %d\n",y);	
for(mes=0;mes<12;mes++){
printf("|-----------------------------|\n");
switch (mes){
	case 0:printf("|Janeiro                      |\n");break;
	case 1:printf("|Fevereiro                    |\n");break;
	case 2:printf("|Março                        |\n");break;
	case 3:printf("|Abril                        |\n");break;
	case 4:printf("|Maio                         |\n");break;
	case 5:printf("|Junho                        |\n");break;
	case 6:printf("|Julho                        |\n");break;
	case 7:printf("|Agosto                       |\n");break;
	case 8:printf("|Setembro                     |\n");break;
	case 9:printf("|Outubro                      |\n");break;
	case 10:printf("|Novembro                     |\n");break;
	case 11:printf("|Dezembro                     |\n"); break;
}

printf("|-----------------------------|\n");
printf("| dom seg ter qua qui sex sab |\n");

	for(lin=0;lin<6;lin++){
printf("| ");
		for(col=0;col<7;col++){
			if(m[lin][col][mes]==0)
				printf(" -- ");
			else
			printf(" %02d ",m[lin][col][mes]);
}
printf("|");
printf("\n");
	}

}
printf("|-----------------------------|\n");



			   }
		else if(sn==0){//ano NÃo bissexto
			if(n>31){//abril
				i=pascoa+28+62;
				if((i%7)==0) 	d1=1; //segunda
				else if((i%7)==1)d1=0; //domingo
				else if((i%7)==2)d1=6; //sabado
				else if((i%7)==3)d1=5; //sexta
				else if((i%7)==4)d1=4; //quinta
				else if((i%7)==5)d1=3; //quarta
				else if((i%7)==6)d1=2; //terça
				}
			else{//março	
				i=pascoa+28+31;
				if((i%7)==0) 	d1=1; //segunda
				else if((i%7)==1)d1=0; //domingo
				else if((i%7)==2)d1=6; //sabado
				else if((i%7)==3)d1=5; //sexta
				else if((i%7)==4)d1=4; //quinta
				else if((i%7)==5)d1=3; //quarta
				else if((i%7)==6)d1=2; //terça
			    }
		for(mes=0;mes<12;mes++){
			qtddias=anon[mes];
			dia=1;
			for(col=0;col<7;col++){
				if(col<d1){ 
					m[0][col][mes]=0;
					
				}						
				else{
					m[0][col][mes]=dia;
					dia++;
				}
			}
			for(lin=1;lin<6;lin++){
				for(col=0;col<7;col++){
					if(dia<=qtddias){
						m[lin][col][mes]=dia;
						dia++;
					}
					else m[lin][col][mes]=0;
				}
			}	
qtdd = d1 + qtddias;
d1 = qtdd % 7;		
		}

printf("Calendario do ano %d\n",y);	
for(mes=0;mes<12;mes++){
printf("|-----------------------------|\n");
switch (mes){
	case 0:printf("|Janeiro                      |\n");break;
	case 1:printf("|Fevereiro                    |\n");break;
	case 2:printf("|Março                        |\n");break;
	case 3:printf("|Abril                        |\n");break;
	case 4:printf("|Maio                         |\n");break;
	case 5:printf("|Junho                        |\n");break;
	case 6:printf("|Julho                        |\n");break;
	case 7:printf("|Agosto                       |\n");break;
	case 8:printf("|Setembro                     |\n");break;
	case 9:printf("|Outubro                      |\n");break;
	case 10:printf("|Novembro                     |\n");break;
	case 11:printf("|Dezembro                     |\n"); break;
}

printf("|-----------------------------|\n");
printf("| dom seg ter qua qui sex sab |\n");
	for(lin=0;lin<6;lin++){
printf("| ");
		for(col=0;col<7;col++){
			if(m[lin][col][mes]==0)
				printf(" -- ");
			else
			printf(" %02d ",m[lin][col][mes]);

}
printf("|");
printf("\n");
	}


}
printf("|-----------------------------|\n");
			  }			
return 0;
}		
	






	
