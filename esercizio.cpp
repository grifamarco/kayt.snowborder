#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


struct s_KaytSnowborder
{
    int mat;
    string cogn;
    
    int x[30];
    int y[30];
    int kiloperc;
} KaytSnowborder, vet_KaytSnowborder[20];




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
