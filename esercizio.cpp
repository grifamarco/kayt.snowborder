/*!
\file main.cpp
\brief implementazione del file main
\author M.Grifa
\date 27/02/2023
*/


#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

/*!
\struc s_KaytSnowborder
\brief nella struttura ci andiamo a dichiarare le varie variabili
*/
struct s_KaytSnowborder
{
    int mat;//! \var mat \brief numero della matricola
    string cogn;//! \var cogn \brief cognome dell'atleta
    int x[30];//! \var x \brief coordinata(x)
    int y[30];//! \var y \brief coordinata(y)
    int kiloperc;//! \var kiloperc \brief kilometri percorsi dall'atleta
} KaytSnowborder, vet_KaytSnowborder[20];



/*!
\fn carica_vettore
\brief in questa funzione carico gli elementi del file nel vettore
*/
void carica_vettore()
{
    ifstream fin("atleti.txt",ios::in);
    while(!fin.eof())
    {
        for(int i=0; i<7; i++)
        {
            fin>>vet_KaytSnowborder[i].mat>>vet_KaytSnowborder[i].cogn;
            for(int j=0; j<30; j++)
            {
                 fin>>vet_KaytSnowborder[i].x[j]>>vet_KaytSnowborder[i].y[j];
            }
        }
    }
    fin.close();
}

/*!
\fn calcola
\brief in questa funzione vado a calcolare le distanze percorse dai vari atleti
*/

void calcola()
{
    carica_vettore();
    int k, ris, distanza;

     for(int i=0; i<7; i++)
    {
        ris=0;
        distanza=0;

        for(int j=0; j<28; j++)
        {
            k=j+1;
            ris=sqrt((pow(vet_KaytSnowborder[i].x[j]-vet_KaytSnowborder[i].x[k],2))+(pow(vet_KaytSnowborder[i].y[j]-vet_KaytSnowborder[i].y[k],2)));
            distanza=distanza+ris;
            k++;
        }
        vet_KaytSnowborder[i].kiloperc=distanza;
    }
}

/*!
\fn file_stampato
\brief in questa funzione stampo gli elementi del file
*/
void file_stampato()
{
    
    string s;
    ifstream fin("atleti.txt",ios::in);
    while(!fin.eof())
    {
        getline(fin,s);
        cout<<s<<endl;
    }    fin.close();
}

/*!
\fn podio
\brief in questa funzione mi vado a calcolare gli atleti che sono arrivati nelle prime 3 posizioni
*/

void podio()
{
    
    calcola();
    s_KaytSnowborder temp;
    s_KaytSnowborder *vet_ordinato=vet_KaytSnowborder;
    cout<<"PODIO:";

    for(int i=0;i<6;i++)
        for(int k=i+1;k<7;k++)
            if((vet_ordinato+i)->kiloperc<(vet_ordinato+k)->kiloperc)
            {
                temp=*(vet_ordinato+k);
                *(vet_ordinato+k)=*(vet_ordinato+i);
                *(vet_ordinato+i)=temp;
            }
    cout<<"\n Al primo posto si è classificato:"<<(vet_ordinato+0)->mat<<" "<<(vet_ordinato+0)->cogn
        <<" Kilometri percorsi dall'atleta"<<"(oro)"<<": "<<(vet_ordinato+0)->kiloperc<<"km";
    cout<<"\n Al secondo posto si è classificato:"<<(vet_ordinato+1)->mat<<" "<<(vet_ordinato+1)->cogn
        <<" Kilometri percorsi dall'atleta"<<"(argento)"<<": "<<(vet_ordinato+1)->kiloperc<<"km";
    cout<<"\n Al terzo posto si è classificato:"<<(vet_ordinato+2)->mat<<" "<<(vet_ordinato+2)->cogn
        <<" Kilometri percorsi dall'atleta"<<"(bronzo)"<<": "<<(vet_ordinato+2)->kiloperc<<"km"<<"\n";
    cout<<"Questi 3 sono gli atleti che sono saliti sul podio."<<endl;
}

/*!
\fn main
\brief in questa funzione vado a visualizzare le varie scelte che metteremo a disposizione dell'utente
*/
int main()
{
    int scelta;
        do
        {
            cout<<endl<<"\t-----\tMENU\t-----\t"<<endl;
            cout<<"1)Stampa degli atleti con le varie caratteristiche "<<endl;
            cout<<"2)Podio Vincente"<<endl;
            cout<<"3)USCITA "<<endl;
            cin>>scelta;
            switch(scelta){
                case 1:
                        file_stampato();
                        break;
                case 2:
                        podio();
                        break;
            }

        }while(scelta!=3);


    return 0;
}
