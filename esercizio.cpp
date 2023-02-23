#include <iostream>
#include <cmath>
using namespace std;


struct s_KaytSnowborder
{
    int mat;//numero atleta
    string cogn;//cognome atleta
    int coordinate;//coordinate rilevate
} KaytSnowborder, vet_KaytSnowborder[20];;

int genera()
{
    srand(time(NULL));
    int x=0,y=0,distanza;
    int geff=30;
    int x1,y1;
    for(int c=0; c<geff; c++)
    {
        x=rand()%100;
        y=rand()%100;
        x1=x;
        y1=y;
        distanza=sqrt((pow(x,2)-pow(x1,2))+(pow(y,2)-pow(y1,2)));
    }
}

int main()
{
    
     
    
    int scelta;
        do
        {
            cout<<endl<<"===== MENU ====="<<endl;
            cout<<"1) "<<endl;
            cout<<"2)USCITA "<<endl;
            cin>>scelta;
            switch(scelta){
                case 1:
                        
                        break;
                case 2:
                        
                        break;
            }

        }while(scelta!=2);
        

    return 0;
}
