#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i, resto, num, quoz;

void pIntera(int dim, int v[], int num){

    for(i=dim-1;i>=0;i--){
        v[i]=num%2;
        num=num/2;
    }
}

void printV(int dim, int v[]){

    for(i=0;i<dim;i++){
        printf("%d", v[i]);
	  }
}

void compA2(int di, int v[]){
    int r=0;
    for(i=0;i<di;i++){                                                        //comp A1
      if(v[i]==0)
        v[i]=1;
      else
        v[i]=0;
    }
    do{                                                                        //comp A2
      v[i]+=1;
      if(v[i]==2){
        v[i]=1;
        r=1;
      }
      else{
        r=0;
      }
      i--;
    }while(r==1);
}

int main()
{
    float n,n1=0;
    int c=2,s,conta=0, fl,exp, di=16, df=23,dif;

    printf("Inserisci il numero da convertire: ");
    scanf("%f", &n);

    if (n==(int)n){
        c=0;        // int

    }

    else
        c=1;        // float

    if(c==0){                                                                         //SENZA SEGNO
        int vet[di];
       if(n>=0){
            num=(int)n;
			pIntera(di, vet, num);
			printf("\nLa conversione in binario equvale a \n");
            printV(di, vet);
            printf("\n\nE' stata utilizzata la conversione senza segno ");
           }

        else{                                                                       //CON SEGNO
            num=(int)n*-1;
            pIntera(di, vet, num);
            vet[di]=1;
            compA2(di, vet);
            printf("\nLa conversione in binario equvale a \n");
            printV(di, vet);
            printf("\n\nE' stata utilizzata la conversione tramite complemento A2 ");
        }
    }
    else{                                                                          //FLOATING POINT 
        if(n>0){                                                                    //segno
            s=0;
            num=(int)n;
        }
        else{
            s=1;
            num=(int)n*-1;
        }
        do{                                                                         //conta
            num=num/2;
            conta++;
        }while(num>0);

        if(s==1){                                                                  //segno
            num=(int)n*-1;
            n1=n+num;
            n1*=-1;
        }
        else{
            num=(int)n;
            n1=n-num;
        }
        int m[df];
        for(i=0;i<df;i++){
            m[i]=0;
        }
        pIntera(conta, m, num);                                                    //parte intera
        int j;
        for(i=conta;i<df;i++){                                                    //parte decimale
            n1*=2;
            if(i==(df-1)){
                m[i]=0;
                //printf("\ni=15");
                break;
            }
            else{
                if(n1==1){
                    m[i]=1;
                    for(j=i+1;j<df;j++){
                        m[j]=0;
                    }
                    i=df;
                    // printf("\nnl=1");
                    break;
                }
                else{
                    if(n1>1){
                        m[i]=1;
                        n1-=1;
                        //printf("\nnl>1 n=1");
                    }
                    else{
                        m[i]=0;
                            //printf("\nnl<1 n=0");
                    }
                }
            }
        }
        dif=df-(conta);
        fl=conta;
        for(i=0;i<conta;i++){                                                       //esponente
            if(m[i]==1){
                exp=i;
            }
        }
        fl=fl-exp;
        //printf("\n%d     %d\n", fl,exp);
        for(i=0;i<dif;i++){                                                          //spostamento
            m[i]=m[fl+i];
        }

        exp+=127;
        int ex[8];
        pIntera(8, ex, exp);
        printf("\n%d", s);                    // Visual finale
        printf(" ");
        printV(8, ex);                      
        printf(" ");
        printV(df, m);                        //
        printf("\n\nE' stata utilizzata la conversione tramite floating point ");
    }
}
