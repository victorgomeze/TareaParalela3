#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


using namespace std;

void Inicializacion(int tablero[][3], int vector[]) // funcion para llenar de ceros
{
   for(int i=0;i<3;i++){ // inicializacion vector usados
                vector[i]=0;
    }
    for(int i=0;i<3;i++) // inicializacion tablero, llenado de ceros
    {
        for(int j=0;j<3;j++)
        {
            tablero[i][j]=0;
        }

    }
}

int compDatos(char *Argumentos) // aqui verificamos si los argumentos estan bien escritos
{
    int aux=1,arg,arg2=0,num[3],cont=-1;
    char s;
    string cadena=Argumentos;
    for(int i=0;i<cadena.length();i++)
     {
         s=cadena[i];
         arg=s;
         if(arg>47 && arg<58 || arg==91 || arg==93 || arg==59)
         {
            if((arg2>47 && arg2<58) && (arg>47 && arg<58))
            {
                i=cadena.length();
                aux=0;
            }
            arg2=arg;
         }
         else
         {
            i=cadena.length();
            aux=0;
         }
     
     }

     if(aux==1)
     {
        for(int i=0;i<cadena.length();i++)
        {
             s=cadena[i];
             arg=s;
             if(arg>47 && arg<58)
             {
                 num[++cont]=arg-48;
             }
             if(cont==2)
             {
                 cont=-1;
                 if(num[0]>-1 && num[0]<9 && num[1]>-1 && num[1]<9 && num[2]>0 && num[2]<10)
                 {

                 }
                 else
                 {
                    i=cadena.length();
                    aux=0;
                 }
             }
     
        }
     }
     return aux;
}

bool NoExiste(int vector[],int n){
    int i=0;
    while(i<9){
        if(n==vector[i]){
            return false;
        }
        i++;
    }
    return true;

    
}

void mostrar(int tablero[][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<tablero[i][j]<<" ";

        }
        cout<<endl;
    }
}


int main(int argc, char* argv[])
{

    int  matriz[3][3];
    if(argc<2) // en caso de no ingresar argumentos
    {
        cout<<"Ingresa los datos"<<endl;
    }
    else
    {
        if(compDatos(argv[1])==1) // comprobamos que el argumento esten bien ingresados
        {
            int arg, num[3],usados[9],contUsa=0,x=1,cont=-1; // variables necesarias
            string cadena=argv[1];
            char s;
            Inicializacion(matriz, usados); // inicializamos el vector y matriz
              
    
            for(int i=0;i<cadena.length();i++) // guardado de numeros ingresados por usuario
            {
                s=cadena[i];
                arg=s;
                if(arg>47 && arg<58)
                {
                    num[++cont]=arg-48;
                }
                if(cont==2)
                {
                    matriz[num[0]][num[1]]=num[2]; // agregamos el valor a la matriz
                    cont=-1;
                    usados[contUsa]=num[2]; // lo guardamos para no volver a usarlo
                    contUsa++;
                    
                }
     
            }
            
            for(int i=0; i<3;i++){ // proceso de llenado de los numeros faltantes
                for(int j=0;j<3;j++){
                    
                    if(matriz[i][j]==0){
                        if(NoExiste(usados,x)==true){
                            matriz[i][j]=x;                            
                            usados[contUsa++]=x;
                            i=0;
                            j=0; // las volvemos a dejar en cero para iniciar desde el principio la busqueda
                        }		  // para no repetir numeros
                        x++;
                        
                    }
                }
            }

            mostrar(matriz); 

            

        }
        else
        {
            cout<<"Datos ingresados erroneos"<<endl;
        }
    }
    return 0;
}