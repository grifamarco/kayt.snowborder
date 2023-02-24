#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


struct s_KaytSnowborder
{
    int mat;//numero atleta.
    string cogn;//cognome atleta.
    int coordinate;//coordinate rilevate(x e y).
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

void carica_vettore(s_KaytSnowborder vet_KaytSnowborder[])
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

void file_stampato(s_KaytSnowborder vet_KaytSnowborder[])
{
    ofstream fout("ATLETI.txt");
    for(int i=0; i<2; i++)
    {
        fout<<endl<<vet_KaytSnowborder[i].mat<<" "<<vet_KaytSnowborder[i].cogn<<" ";
    }
    fout.close();
}

/*
void podio()
{
    ofstream fout("ATLETI.txt");
    
    cout<<"PODIO:";
    for(int i=0; i<3; i++)
    {
        
    }
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
                        file_stampato(vet_KaytSnowborder);
                        break;
                case 2:
                        //podio();
                        break;
            }

        }while(scelta!=3);
        

    return 0;
}