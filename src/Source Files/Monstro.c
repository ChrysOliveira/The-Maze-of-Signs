#include <stdlib.h>
#include <stdio.h>
#include "../Header Files/mapa.h"
#include <allegro5/allegro.h>
#include "../Header Files/mapa.h"
#include "../Header Files/Monstro.h"

int quantidadeMonstros(Mapa * mapa)
{
    int quantidadeDeMonstro = 0;

    for (int i = 0; i < mapa->qntLinhas; i++)
    {
        for (int j = 0; j < mapa->qntColunas; j++)
        {
            if (mapa->matriz[i][j] == MONSTRO)
            {
                quantidadeDeMonstro++;
            }   
        }
    }

    return quantidadeDeMonstro;
}

void alocaMonstros(Monstro * monstros, int qntMonstros)
{
    monstros = (Monstro * )malloc(sizeof(Monstro) *  qntMonstros);
    
}

void localizaMonstros(Mapa * mapa, Monstro * monstros, int qntMonstros)
{
    int contLoop = 0;

    while (contLoop < qntMonstros)
    {
        for (int i = 0; i < mapa->qntLinhas; i++)
        {
            for (int j = 0; j < mapa->qntColunas; j++)
            {
                if (mapa->matriz[i][j] == MONSTRO)
                {
                    monstros[contLoop].posicaoX = j*40;
                    monstros[contLoop].posicaoY =  i*40;
                    monstros[contLoop].direcao = rand() % 5;
                    monstros[contLoop].monstroBitmap = al_load_bitmap("../../assets/bitmaps/fantasma.png");
                    contLoop++;
                }
            }
        }
    }
}

void desenhaMonstros(Monstro * monstros, int qntMonstros)
{
    for (int i = 0; i < qntMonstros; i++)
    {
        al_draw_scaled_bitmap(monstros[i].monstroBitmap, 0, 0, 40, 40, monstros[i].posicaoX, monstros[i].posicaoY, 40, 40, 0);
    }
}

void desalocaMonstros(Monstro * monstros)
{
    free(monstros);
}

void movimentaMonstros(Mapa * mapa, Monstro * monstros, int qntMonstros)
{

    for (int i = 0; i < qntMonstros; i++)
    {        
        switch (monstros[i].direcao)
        {
        case 1:
                if (!ehParede(mapa, monstros[i].posicaoX, monstros[i].posicaoY - 1)) {
                    monstros[i].posicaoY -= 10;
                  
                } else
                {
                    monstros[i].direcao = rand() % 5;
                }
                break;
        case 2:
                if (!ehParede(mapa, monstros[i].posicaoX, monstros[i].posicaoY + 41)) {
                    monstros[i].posicaoY += 10;
                 
                } else
                {
                    monstros[i].direcao = rand() % 5;
                }
                break;
        case 3:
                if (!ehParede(mapa, monstros[i].posicaoX-1, monstros[i].posicaoY)) {
                    monstros[i].posicaoX -= 10;
                 
                } else
                {
                    monstros[i].direcao = rand() % 5;
                }
                break;
        case 4:
                if (!ehParede(mapa, monstros[i].posicaoX + 41, monstros[i].posicaoY)) {
                    monstros[i].posicaoX += 10;
                  
                } else
                {
                    monstros[i].direcao = rand() % 5;
                }
            break;
        default:
            monstros[i].direcao = rand() % 5;
            break;
        }
    }
        desenhaMonstros(monstros, qntMonstros);
}