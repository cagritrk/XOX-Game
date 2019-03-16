//
//  main.cpp
//  XOX-Game
//
//  Created by Çağrı Türk on 16.03.2019.
//  Copyright © 2019 Çağrı Türk. All rights reserved.
//

#include <iostream>

using namespace std;
#define altSatir "\n"

char map[3][3];
char xKarakter = 'X';
char oKarakter = 'O';

int rakamdanXkordinat(int rakam)
{
    if(rakam>0 && rakam<4)
        return 0;
    else if (rakam>3 && rakam<7)
        return 1;
    else if (rakam>6 && rakam<10)
        return 2;
    else
        return 3;
}
int rakamdanYkordinat(int rakam)
{
    if(rakam==1 || rakam==4 || rakam==7)
        return 0;
    else if (rakam==2 || rakam==5 || rakam==8)
        return 1;
    else if (rakam==3 || rakam==6 || rakam==9)
        return 2;
    else
        return 3;
}


void oyna(int indisX,int indisY,char karakter)
{
    map[indisX][indisY] = karakter;
}

void oyunAlaniYazdir()
{
    cout<<endl;
    for (int x=0;x<3;x++)
    {
        for (int y=0;y<3;y++)
        {
            cout<<map[x][y]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void mapDoldur()
{
    int s = 49;
    for (int x=0;x<3;x++)
    {
        for (int y=0;y<3;y++)
        {
            map[x][y] = s++;
        }
    }
}

void xOyna()
{
    int rakam;
    cout<<"X oyuncusu\nLutfen alan secin :";
    cin>>rakam;
    oyna(rakamdanXkordinat(rakam), rakamdanYkordinat(rakam), xKarakter);
    oyunAlaniYazdir();
}
void oOyna()
{
    int rakam;
    cout<<"O oyuncusu\nLutfen alan secin :";
    cin>>rakam;
    oyna(rakamdanXkordinat(rakam), rakamdanYkordinat(rakam), oKarakter);
    oyunAlaniYazdir();
}
void kazandiMesaj(bool x)
{
    if (x==1)
    {
        cout<<"\nX kazandi\n\nTekrar Oyna!\n";
    }
    else
    {
        cout<<"\nO kazandi\n\nTekrar Oyna!\n";
    }
    mapDoldur();
    oyunAlaniYazdir();
}
void kontrolEt()
{
    //yatay kontrol
    for(int i=0;i<3;i++)
    {
        if(map[i][0] == xKarakter && map[i][1] == xKarakter && map[i][2] == xKarakter)
            kazandiMesaj(1);
        if(map[i][0] == oKarakter && map[i][1] == oKarakter && map[i][2] == oKarakter)
            kazandiMesaj(0);
    }
    
    //dikey kontrol
    for(int i=0;i<3;i++)
    {
        if(map[0][i] == xKarakter && map[1][i] == xKarakter && map[2][i] == xKarakter)
            kazandiMesaj(1);
        if(map[0][i] == oKarakter && map[1][i] == oKarakter && map[2][i] == oKarakter)
            kazandiMesaj(0);
    }
    
    //capraz kontrol
    
    if(map[0][0] == xKarakter && map[1][1] == xKarakter && map[2][2] == xKarakter){
        kazandiMesaj(1);
    }
    if(map[0][0] == oKarakter && map[1][1] == oKarakter && map[2][2] == oKarakter){
        kazandiMesaj(0);
    }
    
    if(map[0][2] == oKarakter && map[1][1] == oKarakter && map[2][0] == oKarakter){
        kazandiMesaj(0);
    }
    if(map[0][2] == xKarakter && map[1][1] == xKarakter && map[2][0] == xKarakter){
        kazandiMesaj(1);
    }
}


int main() {
    mapDoldur();
    oyunAlaniYazdir();
    while (true)
    {
        xOyna();
        kontrolEt();
        oOyna();
        kontrolEt();
    }
    
    cout<<altSatir<<altSatir<<altSatir<<altSatir;
    return 0;
}

