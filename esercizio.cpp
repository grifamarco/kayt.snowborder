#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


struct s_KaytSnowborder
{
    int mat;//numero atleta.
    string cogn;//cognome atleta.
    int coordinate;//coordinate rilevate(x e y).
    int kiloperc;//kilometri percorsi.
} KaytSnowborder, vet_KaytSnowborder[20];

int genera_coordinate()
{
    //geff=giri effettuati
    srand(time(NULL));
    int x=0,y=0,distanza;
    int geff=5;
    int x1,y1;
    for(int c=0; c<geff; c++)
    {
        x=rand()%101;
        y=rand()%101;
        x1=x;
        y1=y;
        distanza=sqrt((pow(x,2)-pow(x1,2))+(pow(y,2)-pow(y1,2)));
    }
    return distanza;
}

void carica_vettore()
{
    ifstream fin("ATLETI.txt",ios::in);
    string appoggio;
    while(!fin.eof())
    {
        getline(fin,appoggio);
        for(int i=0; i<7; i++)
        {
            fin>>vet_KaytSnowborder[i].mat>>vet_KaytSnowborder[i].cogn;
        }
    }
    fin.close();
}

void file_stampato()
{
    carica_vettore();
    ofstream fout("ATLETI.txt");
    for(int i=0; i<7; i++)
    {
        fout<<endl<<vet_KaytSnowborder[i].mat<<" "<<vet_KaytSnowborder[i].cogn<<" ";
    }
    fout.close();
}

/*
void podio()
{
    //ofstream fout("ATLETI.txt");
    int campione1=vet_KaytSnowborder[0].kiloperc;
    int campione2=0;
    int campione3=0;
    int primo=0;
    int secondo=0;
    int terzo=0;
    cout<<"PODIO:";
    for(int i=0; i<7; i++)
    {
        if(vet_KaytSnowborder[i].kiloperc>primo)
        {
            campione1=vet_KaytSnowborder[i].kiloperc;
            primo=i;
        }
    }
    cout<<"\n Al primo posto si è classificato:"<<vet_KaytSnowborder[primo].mat<<" "<<vet_KaytSnowborder[primo].cogn<<"Kilometri percorsi dall'atleta: "<<vet_KaytSnowborder[primo].kiloperc<<"km";
    
    for(int i=0; i<7; i++)
    {
        if(vet_KaytSnowborder[i].kiloperc<campione1)
        {
            campione2=vet_KaytSnowborder[i].kiloperc;
            for(int i=0; i<7; i++)
            {
                if(vet_KaytSnowborder[i].kiloperc>campione2 && vet_KaytSnowborder[i].kiloperc<campione1)
                {
                    campione2=vet_KaytSnowborder[i].kiloperc;
                    secondo=i;
                }
            }
            
        }
    }
    cout<<"\n Al secondo posto si è classificato:"<<vet_KaytSnowborder[secondo].mat<<" "<<vet_KaytSnowborder[secondo].cogn<<"Kilometri percorsi dall'atleta: "<<vet_KaytSnowborder[secondo].kiloperc<<"km";
    
    for(int i=0;i<7;i++)
    {
        if(vet_KaytSnowborder[i].kiloperc<campione2)
        {
            campione3=vet_KaytSnowborder[i].kiloperc;
            for(int i=0;i<7;i++)
            {
                if(vet_Snowborder[i].kiloperc>campione3 && vet_KaytSnowborder[i].kiloperc<campione2)
                {
                    campione3=vet_KaytSnowborder[i].kiloperc;
                    terzo=i;
                }
            }
        }
    }
    cout<<"\n Al terzo posto si è classificato:"<<vet_KaytSnowborder[terzo].mat<<" "<<vet_KaytSnowborder[terzo].cogn<<"Kilometri percorsi dall'atleta: "<<vet_KaytSnowborder[terzo].kiloperc<<"km"<<"\n";
    cout<<"Questi 3 sono gli atleti che sono saliti sul podio."<<endl;
}
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
                        //podio();
                        break;
            }

        }while(scelta!=3);
        

    return 0;
}