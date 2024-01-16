#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char dosyaAdi[255];
    printf("Dosya adini giriniz: ");
    gets(dosyaAdi);
    char Komutlar[1000];
    int RAM[255];
    int p = 0;
    for (p = 0; p < 256; p++)
    {
        RAM[p] = -1;
    }
    int i = 0;
    int AX = 0, BX = 0, CX = 0, DX = 0;
    FILE *dosya = fopen(dosyaAdi, "r");
    printf("Kaynak Kod: \n");
    while (!feof(dosya))
    {
        fscanf(dosya, "%c", &Komutlar[i]);
        printf("%c", Komutlar[i]);
        i++;
    }
    fclose(dosya);
    int j = 0;
    while (j < i)
    {
        if (Komutlar[j] == 'A') // ATM
        {
            if (Komutlar[j + 4] == 'A')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    AX = AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    AX = BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    AX = CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    AX = DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        AX = RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        AX = RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        AX = RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {
                    AX = (int)Komutlar[j + 7] - 48;
                    if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                    {
                        AX = (AX * 10) + (int)Komutlar[j + 8] - 48;
                        if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                        {
                            AX = (AX * 10) + (int)Komutlar[j + 9] - 48;
                            j = j + 10;
                        }
                        else
                        {
                            j = j + 9;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'B')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    BX = AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    BX = BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    BX = CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    BX = DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        BX = RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        BX = RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        BX = RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {
                    BX = (int)Komutlar[j + 7] - 48;
                    if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                    {
                        BX = (BX * 10) + (int)Komutlar[j + 8] - 48;
                        if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                        {
                            BX = (BX * 10) + (int)Komutlar[j + 9] - 48;
                            j = j + 10;
                        }
                        else
                        {
                            j = j + 9;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'C')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    CX = AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    CX = BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    CX = CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    CX = DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        CX = RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        CX = RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        CX = RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {
                    CX = (int)Komutlar[j + 7] - 48;
                    if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                    {
                        CX = (CX * 10) + (int)Komutlar[j + 8] - 48;
                        if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                        {
                            CX = (CX * 10) + (int)Komutlar[j + 9] - 48;
                            j = j + 10;
                        }
                        else
                        {
                            j = j + 9;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'D')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    DX = AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    DX = BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    DX = CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    DX = DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        DX = RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        DX = RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        DX = RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {
                    DX = (int)Komutlar[j + 7] - 48;
                    if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                    {
                        DX = (DX * 10) + (int)Komutlar[j + 8] - 48;
                        if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                        {
                            DX = (DX * 10) + (int)Komutlar[j + 9] - 48;
                            j = j + 10;
                        }
                        else
                        {
                            j = j + 9;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == '[')
            {
                if (Komutlar[j + 6] == ']')
                {
                    if (Komutlar[j + 8] == 'A')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = AX;

                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'B')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = BX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'C')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = CX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'D')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = DX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == '[')
                    {
                        if (Komutlar[j + 10] == ']')
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 9] - 48];

                            j = j + 11;
                        }
                        else if (Komutlar[j + 11] == ']')
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[((int)Komutlar[j + 9] - 48) * 10 + (int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + (int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                    }
                    else
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = (int)Komutlar[j + 8] - 48;
                        if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] * 10 + ((int)Komutlar[j + 9] - 48);
                            if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                            {
                                RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] * 10 + ((int)Komutlar[j + 10] - 48);
                                j = j + 11;
                            }
                            else
                            {
                                j = j + 10;
                            }
                        }
                    }
                }
                else if (Komutlar[j + 7] == ']')
                {
                    if (Komutlar[j + 9] == 'A')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = AX;

                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'B')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = BX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'C')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = CX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'D')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = DX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == '[')
                    {
                        if (Komutlar[j + 11] == ']')
                        {
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[(int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else if (Komutlar[j + 12] == ']')
                        {
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 10] - 48) * 10 + (int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                        else
                        {
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + (int)Komutlar[j + 12] - 48];

                            j = j + 14;
                        }
                    }
                    else
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = (int)Komutlar[j + 9] - 48;

                        if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] * 10 + ((int)Komutlar[j + 10] - 48);

                            if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                            {
                                RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] * 10 + ((int)Komutlar[j + 11] - 48);
                                j = j + 12;
                            }
                            else
                            {
                                j = j + 11;
                            }
                        }
                    }
                }
                else // 3 boyutlu ram için ATM
                {

                    if (Komutlar[j + 10] == 'A')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = AX;

                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'B')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = BX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'C')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = CX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'D')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = DX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == '[')
                    {
                        if (Komutlar[j + 12] == ']')
                        {
                            RAM[(((int)Komutlar[j + 5] - 48)) * 100 + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                        else if (Komutlar[j + 13] == ']')
                        {
                            RAM[(((int)Komutlar[j + 5] - 48)) * 100 + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[((int)Komutlar[j + 11] - 48) * 10 + (int)Komutlar[j + 12] - 48];

                            j = j + 14;
                        }
                        else
                        {
                            RAM[(((int)Komutlar[j + 5] - 48)) * 100 + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 11] - 48) * 100) + (((int)Komutlar[j + 12] - 48) * 10) + (int)Komutlar[j + 13] - 48];

                            j = j + 15;
                        }
                    }
                    else
                    {
                        RAM[(((int)Komutlar[j + 5] - 48)) * 100 + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = (int)Komutlar[j + 10] - 48;

                        if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                        {
                            RAM[(((int)Komutlar[j + 5] - 48)) * 100 + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48)) * 100 + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] * 10 + ((int)Komutlar[j + 11] - 48);

                            if (Komutlar[j + 12] <= 57 && Komutlar[j + 12] >= 48)
                            {
                                RAM[(((int)Komutlar[j + 5] - 48)) * 100 + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48)) * 100 + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] * 10 + ((int)Komutlar[j + 12] - 48);

                                j = j + 13;
                            }
                            else
                            {
                                j = j + 12;
                            }
                        }
                    }
                }
            }
        }
        if (Komutlar[j] == 'T')
        {
            if (Komutlar[j + 4] == 'A')
            {

                if (Komutlar[j + 7] == 'A')
                {

                    AX = AX + AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {

                    AX = AX + BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    AX = AX + CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    AX = AX + DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        AX = AX + RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        AX = AX + RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        AX = AX + RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {
                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                AX = AX + ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                AX = AX + ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            AX = AX + (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'B')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    BX = BX + AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    BX = BX + BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    BX = BX + CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    BX = BX + DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        BX = BX + RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        BX = BX + RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        BX = BX + RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {
                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                BX = BX + ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                BX = BX + ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            BX = BX + (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'C')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    CX = CX + AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    CX = CX + BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    CX = CX + CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    CX = CX + DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        CX = CX + RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        CX = CX + RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        CX = CX + RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {
                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                CX = CX + ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                CX = CX + ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            CX = CX + (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'D')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    DX = DX + AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    DX = DX + BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    DX = DX + CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    DX = DX + DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        DX = DX + RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        DX = DX + RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        DX = DX + RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {
                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                DX = DX + ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                DX = DX + ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            DX = DX + (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == '[')
            {
                if (Komutlar[j + 6] == ']')
                {
                    if (Komutlar[j + 8] == 'A')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] + AX;

                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'B')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] + BX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'C')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] + CX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'D')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] + DX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == '[')
                    {
                        if (Komutlar[j + 10] == ']')
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] + RAM[(int)Komutlar[j + 9] - 48];

                            j = j + 11;
                        }
                        else if (Komutlar[j + 11] == ']')
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] + RAM[((int)Komutlar[j + 9] - 48) * 10 + (int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] + RAM[(((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + (int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {

                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                                {
                                    RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] + ((((int)Komutlar[j + 8] - 48) * 100) + (((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));

                                    j = j + 10;
                                }
                                else
                                {
                                    RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] + ((((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));

                                    j = j + 9;
                                }
                            }
                            else
                            {
                                RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] + (int)Komutlar[j + 8] - 48;
                                j = j + 8;
                            }
                        }
                    }
                }
                else if (Komutlar[j + 7] == ']')
                {
                    if (Komutlar[j + 9] == 'A')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] + AX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'B')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] + BX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'C')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] + CX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'D')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] + DX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == '[')
                    {
                        if (Komutlar[j + 11] == ']')
                        {

                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] + RAM[(int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else if (Komutlar[j + 12] == ']')
                        {
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] + RAM[((int)Komutlar[j + 10] - 48) * 10 + (int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                        else
                        {
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] + RAM[(((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + (int)Komutlar[j + 12] - 48];

                            j = j + 14;
                        }
                    }
                    else
                    {

                        if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                        {
                            if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                            {
                                if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] + ((((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));

                                    j = j + 11;
                                }
                                else
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] + ((((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));
                                    j = j + 10;
                                }
                            }
                            else
                            {
                                RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] + (int)Komutlar[j + 9] - 48;
                                j = j + 9;
                            }
                        }
                    }
                }
                else
                {
                    if (Komutlar[j + 10] == 'A')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] + AX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'B')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] + BX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'C')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] + CX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'D')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] + DX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == '[')
                    {
                        if (Komutlar[j + 12] == ']')
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] + RAM[(int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                        else if (Komutlar[j + 13] == ']')
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] + RAM[((int)Komutlar[j + 11] - 48) * 10 + (int)Komutlar[j + 12] - 48];

                            j = j + 14;
                        }
                        else
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] + RAM[(((int)Komutlar[j + 11] - 48) * 100) + (((int)Komutlar[j + 12] - 48) * 10) + (int)Komutlar[j + 13] - 48];

                            j = j + 15;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                        {
                            if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                            {
                                if (Komutlar[j + 12] <= 57 && Komutlar[j + 12] >= 48)
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] + ((((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + ((int)Komutlar[j + 12] - 48));

                                    j = j + 12;
                                }
                                else
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] + ((((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));

                                    j = j + 11;
                                }
                            }
                            else
                            {
                                RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] + (int)Komutlar[j + 10] - 48;

                                j = j + 10;
                            }
                        }
                    }
                }
            }
        }
        if (Komutlar[j] == 'C' && Komutlar[j + 1] == 'I')
        {

            if (Komutlar[j + 4] == 'A')
            {

                if (Komutlar[j + 7] == 'A')
                {

                    AX = AX - AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {

                    AX = AX - BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    AX = AX - CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    AX = AX - DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        AX = AX - RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        AX = AX - RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        AX = AX - RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {

                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                AX = AX - ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                AX = AX - ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            AX = AX - (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'B')
            {

                if (Komutlar[j + 7] == 'A')
                {
                    BX = BX - AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    BX = BX - BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    BX = BX - CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    BX = BX - DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        BX = BX - RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        BX = BX - RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        BX = BX - RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {

                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                BX = BX - ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                BX = BX - ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            BX = BX - (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'C')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    CX = CX - AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    CX = CX - BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    CX = CX - CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    CX = CX - DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        CX = CX - RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        CX = CX - RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        CX = CX - RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {

                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                CX = CX - ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                CX = CX - ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            CX = CX - (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'D')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    DX = DX - AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    DX = DX - BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    DX = DX - CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    DX = DX - DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        DX = DX - RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        DX = DX - RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        DX = DX - RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {

                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                DX = DX - ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                DX = DX - ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            DX = DX - (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == '[')
            {
                if (Komutlar[j + 6] == ']')
                {
                    if (Komutlar[j + 8] == 'A')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] - AX;

                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'B')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] - BX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'C')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] - CX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'D')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] - DX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == '[')
                    {
                        if (Komutlar[j + 10] == ']')
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] - RAM[(int)Komutlar[j + 9] - 48];

                            j = j + 11;
                        }
                        else if (Komutlar[j + 11] == ']')
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] - RAM[((int)Komutlar[j + 9] - 48) * 10 + (int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] - RAM[(((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + (int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {

                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                                {
                                    RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] - ((((int)Komutlar[j + 8] - 48) * 100) + (((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));

                                    j = j + 10;
                                }
                                else
                                {
                                    RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] - ((((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));

                                    j = j + 9;
                                }
                            }
                            else
                            {
                                RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] - (int)Komutlar[j + 8] - 48;
                                j = j + 8;
                            }
                        }
                    }
                }
                else if (Komutlar[j + 7] == ']')
                {
                    if (Komutlar[j + 9] == 'A')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] - AX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'B')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] - BX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'C')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] - CX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'D')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] - DX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == '[')
                    {
                        if (Komutlar[j + 11] == ']')
                        {

                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] - RAM[(int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else if (Komutlar[j + 12] == ']')
                        {
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] - RAM[((int)Komutlar[j + 10] - 48) * 10 + (int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                        else
                        {
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] - RAM[(((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + (int)Komutlar[j + 12] - 48];

                            j = j + 14;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                        {
                            if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                            {
                                if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] - ((((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));

                                    j = j + 11;
                                }
                                else
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] - ((((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));
                                    j = j + 10;
                                }
                            }
                            else
                            {
                                RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] - (int)Komutlar[j + 9] - 48;
                                j = j + 9;
                            }
                        }
                    }
                }
                else
                {
                    if (Komutlar[j + 10] == 'A')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] - AX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'B')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] - BX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'C')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] - CX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'D')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] - DX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == '[')
                    {
                        if (Komutlar[j + 12] == ']')
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] - RAM[(int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                        else if (Komutlar[j + 13] == ']')
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] - RAM[((int)Komutlar[j + 11] - 48) * 10 + (int)Komutlar[j + 12] - 48];

                            j = j + 14;
                        }
                        else
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] - RAM[(((int)Komutlar[j + 11] - 48) * 100) + (((int)Komutlar[j + 12] - 48) * 10) + (int)Komutlar[j + 13] - 48];

                            j = j + 15;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                        {
                            if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                            {
                                if (Komutlar[j + 12] <= 57 && Komutlar[j + 12] >= 48)
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] - ((((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + ((int)Komutlar[j + 12] - 48));

                                    j = j + 12;
                                }
                                else
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] - ((((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));

                                    j = j + 11;
                                }
                            }
                            else
                            {
                                RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] - (int)Komutlar[j + 10] - 48;

                                j = j + 10;
                            }
                        }
                    }
                }
            }
        }
        if (Komutlar[j] == 'C' && Komutlar[j + 1] == 'R')
        {

            if (Komutlar[j + 4] == 'A')
            {

                if (Komutlar[j + 7] == 'A')
                {

                    AX = AX * AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {

                    AX = AX * BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    AX = AX * CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    AX = AX * DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        AX = AX * RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        AX = AX * RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        AX = AX * RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {

                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                AX = AX * ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                AX = AX * ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            AX = AX * (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'B')
            {

                if (Komutlar[j + 7] == 'A')
                {
                    BX = BX * AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    BX = BX * BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    BX = BX * CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    BX = BX * DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        BX = BX * RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        BX = BX * RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        BX = BX * RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {

                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                BX = BX * ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                BX = BX * ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            BX = BX * (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'C')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    CX = CX * AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    CX = CX * BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    CX = CX * CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    CX = CX * DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        CX = CX * RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        CX = CX * RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        CX = CX * RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {

                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                CX = CX * ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                CX = CX * ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            CX = CX * (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'D')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    DX = DX * AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    DX = DX * BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    DX = DX * CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    DX = DX * DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        DX = DX * RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        DX = DX * RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        DX = DX * RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {

                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                DX = DX * ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                DX = DX * ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            DX = DX * (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == '[')
            {
                if (Komutlar[j + 6] == ']')
                {
                    if (Komutlar[j + 8] == 'A')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] * AX;

                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'B')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] * BX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'C')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] * CX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'D')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] * DX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == '[')
                    {
                        if (Komutlar[j + 10] == ']')
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] * RAM[(int)Komutlar[j + 9] - 48];

                            j = j + 11;
                        }
                        else if (Komutlar[j + 11] == ']')
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] * RAM[((int)Komutlar[j + 9] - 48) * 10 + (int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] * RAM[(((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + (int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {

                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                                {
                                    RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] * ((((int)Komutlar[j + 8] - 48) * 100) + (((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));

                                    j = j + 10;
                                }
                                else
                                {
                                    RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] * ((((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));

                                    j = j + 9;
                                }
                            }
                            else
                            {
                                RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] * (int)Komutlar[j + 8] - 48;
                                j = j + 8;
                            }
                        }
                    }
                }
                else if (Komutlar[j + 7] == ']')
                {
                    if (Komutlar[j + 9] == 'A')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] * AX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'B')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] * BX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'C')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] * CX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'D')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] * DX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == '[')
                    {
                        if (Komutlar[j + 11] == ']')
                        {

                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] * RAM[(int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else if (Komutlar[j + 12] == ']')
                        {
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] * RAM[((int)Komutlar[j + 10] - 48) * 10 + (int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                        else
                        {
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] * RAM[(((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + (int)Komutlar[j + 12] - 48];

                            j = j + 14;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                        {
                            if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                            {
                                if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] * ((((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));

                                    j = j + 11;
                                }
                                else
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] * ((((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));
                                    j = j + 10;
                                }
                            }
                            else
                            {
                                RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] * (int)Komutlar[j + 9] - 48;
                                j = j + 9;
                            }
                        }
                    }
                }
                else
                {
                    if (Komutlar[j + 10] == 'A')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] * AX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'B')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] * BX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'C')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] * CX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'D')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] * DX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == '[')
                    {
                        if (Komutlar[j + 12] == ']')
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] * RAM[(int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                        else if (Komutlar[j + 13] == ']')
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] * RAM[((int)Komutlar[j + 11] - 48) * 10 + (int)Komutlar[j + 12] - 48];

                            j = j + 14;
                        }
                        else
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] * RAM[(((int)Komutlar[j + 11] - 48) * 100) + (((int)Komutlar[j + 12] - 48) * 10) + (int)Komutlar[j + 13] - 48];

                            j = j + 15;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                        {
                            if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                            {
                                if (Komutlar[j + 12] <= 57 && Komutlar[j + 12] >= 48)
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] * ((((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + ((int)Komutlar[j + 12] - 48));

                                    j = j + 12;
                                }
                                else
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] * ((((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));

                                    j = j + 11;
                                }
                            }
                            else
                            {
                                RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] * (int)Komutlar[j + 10] - 48;

                                j = j + 10;
                            }
                        }
                    }
                }
            }
        }
        if (Komutlar[j] == 'V' && Komutlar[j + 1] == 'E')
        {

            if (Komutlar[j + 3] == 'A')
            {
                if (Komutlar[j + 6] == 'A')
                {
                    AX = AX & AX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == 'B')
                {
                    AX = AX & BX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == 'C')
                {
                    AX = AX & CX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == 'D')
                {
                    AX = AX & DX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == '[')
                {
                    if (Komutlar[j + 8] == ']')
                    {
                        AX = AX & RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 9;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        AX = AX & RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 10;
                    }
                    else
                    {
                        AX = AX & RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 11;
                    }
                }
                else
                {
                    if (Komutlar[j + 6] <= 57 && Komutlar[j + 6] >= 48)
                    {
                        if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                        {
                            if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                            {
                                AX = AX & ((((int)Komutlar[j + 6] - 48) * 100) + (((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                            else
                            {
                                AX = AX & ((((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48));
                                j = j + 8;
                            }
                        }
                        else
                        {
                            AX = AX & (int)Komutlar[j + 6] - 48;
                            j = j + 7;
                        }
                    }
                }
            }
            else if (Komutlar[j + 3] == 'B')
            {
                if (Komutlar[j + 6] == 'A')
                {
                    BX = BX & AX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == 'B')
                {
                    BX = BX & BX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == 'C')
                {
                    BX = BX & CX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == 'D')
                {
                    BX = BX & DX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == '[')
                {
                    if (Komutlar[j + 8] == ']')
                    {
                        BX = BX & RAM[(int)Komutlar[j + 7] - 48];
                        j = j + 9;
                    }
                    else if (Komutlar[j + 9] == ']')
                    {
                        BX = BX & RAM[((int)Komutlar[j + 7] - 48) * 10 + ((int)Komutlar[j + 8] - 48)];
                        j = j + 10;
                    }
                    else
                    {
                        BX = BX & RAM[((int)Komutlar[j + 7] - 48) * 100 + ((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                }
                else
                {
                    if (Komutlar[j + 6] <= 57 && Komutlar[j + 6] >= 48)
                    {
                        if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                        {
                            if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                            {
                                BX = BX & ((((int)Komutlar[j + 6] - 48) * 100) + (((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                            else
                            {
                                BX = BX & ((((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48));
                                j = j + 8;
                            }
                        }
                        else
                        {
                            BX = BX & (int)Komutlar[j + 6] - 48;
                            j = j + 7;
                        }
                    }
                }
            }
            else if (Komutlar[j + 3] == 'C')
            {
                if (Komutlar[j + 6] == 'A')
                {
                    CX = CX & AX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == 'B')
                {
                    CX = CX & BX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == 'C')
                {
                    CX = CX & CX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == 'D')
                {
                    CX = CX & DX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == '[')
                {
                    if (Komutlar[j + 8] == ']')
                    {
                        CX = CX & RAM[(int)Komutlar[j + 7] - 48];
                        j = j + 9;
                    }
                    else if (Komutlar[j + 9] == ']')
                    {
                        CX = CX & RAM[((int)Komutlar[j + 7] - 48) * 10 + ((int)Komutlar[j + 8] - 48)];
                        j = j + 10;
                    }
                    else
                    {
                        CX = CX & RAM[((int)Komutlar[j + 7] - 48) * 100 + ((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                }
                else
                {
                    if (Komutlar[j + 6] <= 57 && Komutlar[j + 6] >= 48)

                        if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                        {
                            if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                            {
                                CX = CX & ((((int)Komutlar[j + 6] - 48) * 100) + (((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                            else
                            {
                                CX = CX & ((((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48));
                                j = j + 8;
                            }
                        }
                        else
                        {
                            CX = CX & (int)Komutlar[j + 6] - 48;
                            j = j + 7;
                        }
                }
            }
            else if (Komutlar[j + 3] == 'D')
            {
                if (Komutlar[j + 6] == 'A')
                {
                    DX = DX & AX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == 'B')
                {
                    DX = DX & BX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == 'C')
                {
                    DX = DX & CX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == 'D')
                {
                    DX = DX & DX;
                    j = j + 8;
                }
                else if (Komutlar[j + 6] == '[')
                {
                    if (Komutlar[j + 8] == ']')
                    {
                        DX = DX & RAM[(int)Komutlar[j + 7] - 48];
                        j = j + 9;
                    }
                    else if (Komutlar[j + 9] == ']')
                    {
                        DX = DX & RAM[((int)Komutlar[j + 6] - 48) * 10 + ((int)Komutlar[j + 7] - 48)];
                        j = j + 10;
                    }
                    else
                    {
                        DX = DX & RAM[((int)Komutlar[j + 6] - 48) * 100 + ((int)Komutlar[j + 7] - 48) * 10 + ((int)Komutlar[j + 8] - 48)];
                        j = j + 11;
                    }
                }
                else
                {

                    if (Komutlar[j + 6] <= 57 && Komutlar[j + 6] >= 48)
                    {

                        if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                        {
                            if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                            {
                                DX = DX & ((((int)Komutlar[j + 6] - 48) * 100) + (((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                            else
                            {
                                DX = DX & ((((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48));
                                j = j + 8;
                            }
                        }
                        else
                        {
                            DX = DX & (int)Komutlar[j + 6] - 48;
                            j = j + 7;
                        }
                    }
                }
            }
            else if (Komutlar[j + 3] == '[')
            {
                if (Komutlar[j + 5] == ']')
                {
                    if (Komutlar[j + 7] == 'A')
                    {
                        RAM[(int)Komutlar[j + 4] - 48] = RAM[(int)Komutlar[j + 4] - 48] & AX;

                        j = j + 9;
                    }
                    else if (Komutlar[j + 7] == 'B')
                    {
                        RAM[(int)Komutlar[j + 4] - 48] = RAM[(int)Komutlar[j + 4] - 48] & BX;
                        j = j + 9;
                    }
                    else if (Komutlar[j + 7] == 'C')
                    {
                        RAM[(int)Komutlar[j + 4] - 48] = RAM[(int)Komutlar[j + 4] - 48] & CX;
                        j = j + 9;
                    }
                    else if (Komutlar[j + 7] == 'D')
                    {
                        RAM[(int)Komutlar[j + 4] - 48] = RAM[(int)Komutlar[j + 4] - 48] & DX;
                        j = j + 9;
                    }
                    else if (Komutlar[j + 7] == '[')
                    {
                        if (Komutlar[j + 9] == ']')
                        {
                            RAM[(int)Komutlar[j + 4] - 48] = RAM[(int)Komutlar[j + 4] - 48] & RAM[(int)Komutlar[j + 8] - 48];

                            j = j + 10;
                        }
                        else if (Komutlar[j + 10] == ']')
                        {
                            RAM[(int)Komutlar[j + 4] - 48] = RAM[(int)Komutlar[j + 4] - 48] & RAM[((int)Komutlar[j + 8] - 48) * 10 + (int)Komutlar[j + 9] - 48];

                            j = j + 11;
                        }
                        else
                        {
                            RAM[(int)Komutlar[j + 4] - 48] = RAM[(int)Komutlar[j + 4] - 48] & RAM[(((int)Komutlar[j + 8] - 48) * 100) + (((int)Komutlar[j + 9] - 48) * 10) + (int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                        {

                            if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                            {
                                if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                                {
                                    RAM[(int)Komutlar[j + 4] - 48] = RAM[(int)Komutlar[j + 4] - 48] & ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));

                                    j = j + 9;
                                }
                                else
                                {
                                    RAM[(int)Komutlar[j + 4] - 48] = RAM[(int)Komutlar[j + 4] - 48] & ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));

                                    j = j + 8;
                                }
                            }
                            else
                            {
                                RAM[(int)Komutlar[j + 4] - 48] = RAM[(int)Komutlar[j + 4] - 48] & (int)Komutlar[j + 7] - 48;
                                j = j + 7;
                            }
                        }
                    }
                }
                else if (Komutlar[j + 6] == ']')
                {
                    if (Komutlar[j + 8] == 'A')
                    {
                        RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] = RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] & AX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'B')
                    {
                        RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] = RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] & BX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'C')
                    {
                        RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] = RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] & CX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'D')
                    {
                        RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] = RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] & DX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == '[')
                    {
                        if (Komutlar[j + 10] == ']')
                        {

                            RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] = RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] & RAM[(int)Komutlar[j + 9] - 48];

                            j = j + 11;
                        }
                        else if (Komutlar[j + 11] == ']')
                        {
                            RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] = RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] & RAM[((int)Komutlar[j + 9] - 48) * 10 + (int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else
                        {
                            RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] = RAM[((int)Komutlar[j + 4] - 48) * 10 + ((int)Komutlar[j + 5] - 48)] & RAM[(((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + (int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                                {
                                    RAM[(((int)Komutlar[j + 4] - 48) * 10) + ((int)Komutlar[j + 5] - 48)] = RAM[(((int)Komutlar[j + 4] - 48) * 10) + ((int)Komutlar[j + 5] - 48)] & ((((int)Komutlar[j + 8] - 48) * 100) + (((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));

                                    j = j + 10;
                                }
                                else
                                {
                                    RAM[(((int)Komutlar[j + 4] - 48) * 10) + ((int)Komutlar[j + 5] - 48)] = RAM[(((int)Komutlar[j + 4] - 48) * 10) + ((int)Komutlar[j + 5] - 48)] & ((((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                    j = j + 9;
                                }
                            }
                            else
                            {
                                RAM[(((int)Komutlar[j + 4] - 48) * 10) + ((int)Komutlar[j + 5] - 48)] = RAM[(((int)Komutlar[j + 4] - 48) * 10) + ((int)Komutlar[j + 5] - 48)] & (int)Komutlar[j + 8] - 48;
                                j = j + 8;
                            }
                        }
                    }
                }
                else
                {
                    if (Komutlar[j + 9] == 'A')
                    {
                        RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] & AX;

                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'B')
                    {
                        RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] & BX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'C')
                    {
                        RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] & CX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'D')
                    {
                        RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] & DX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == '[')
                    {
                        if (Komutlar[j + 11] == ']')
                        {
                            RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] & RAM[(int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else if (Komutlar[j + 12] == ']')
                        {

                            j = j + 13;
                        }
                        else
                        {
                            RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] & RAM[(((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + (int)Komutlar[j + 13] - 48];

                            j = j + 14;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                        {
                            if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                            {
                                if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                                {
                                    RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] & ((((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));

                                    j = j + 11;
                                }
                                else
                                {
                                    RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] & ((((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));
                                    j = j + 10;
                                }
                            }
                            else
                            {
                                RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 4] - 48) * 100) + (((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] & (int)Komutlar[j + 9] - 48;
                                j = j + 9;
                            }
                        }
                    }
                }
            }
        }
        if (Komutlar[j] == 'V' && Komutlar[j + 1] == 'E' && Komutlar[j + 2] == 'Y')
        {
            if (Komutlar[j + 4] == 'A')
            {

                if (Komutlar[j + 7] == 'A')
                {

                    AX = AX | AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {

                    AX = AX | BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    AX = AX | CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    AX = AX | DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        AX = AX | RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        AX = AX | RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        AX = AX | RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {

                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                AX = AX | ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                AX = AX | ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            AX = AX | (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'B')
            {

                if (Komutlar[j + 7] == 'A')
                {
                    BX = BX | AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    BX = BX | BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    BX = BX | CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    BX = BX | DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        BX = BX | RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        BX = BX | RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        BX = BX | RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {

                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                BX = BX | ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                BX = BX | ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            BX = BX | (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'C')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    CX = CX | AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    CX = CX | BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    CX = CX | CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    CX = CX | DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        CX = CX | RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        CX = CX | RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        CX = CX | RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {
                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                CX = CX | ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                CX = CX | ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            CX = CX | (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'D')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    DX = DX | AX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    DX = DX | BX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    DX = DX | CX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'D')
                {
                    DX = DX | DX;
                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        DX = DX - RAM[(int)Komutlar[j + 8] - 48];
                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        DX = DX | RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        j = j + 11;
                    }
                    else
                    {
                        DX = DX | RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        j = j + 12;
                    }
                }
                else
                {
                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                DX = DX | ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                DX = DX | ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            DX = DX | (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == '[')
            {
                if (Komutlar[j + 6] == ']')
                {
                    if (Komutlar[j + 8] == 'A')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] | AX;

                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'B')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] | BX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'C')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] | CX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'D')
                    {
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] | DX;
                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == '[')
                    {
                        if (Komutlar[j + 10] == ']')
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] | RAM[(int)Komutlar[j + 9] - 48];

                            j = j + 11;
                        }
                        else if (Komutlar[j + 11] == ']')
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] | RAM[((int)Komutlar[j + 9] - 48) * 10 + (int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else
                        {
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] | RAM[(((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + (int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {

                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                                {
                                    RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] | ((((int)Komutlar[j + 8] - 48) * 100) + (((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));

                                    j = j + 10;
                                }
                                else
                                {
                                    RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] | ((((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));

                                    j = j + 9;
                                }
                            }
                            else
                            {
                                RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] | (int)Komutlar[j + 8] - 48;
                                j = j + 8;
                            }
                        }
                    }
                }
                else if (Komutlar[j + 7] == ']')
                {
                    if (Komutlar[j + 9] == 'A')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] | AX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'B')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] | BX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'C')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] | CX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'D')
                    {
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] | DX;
                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == '[')
                    {
                        if (Komutlar[j + 11] == ']')
                        {

                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] | RAM[(int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else if (Komutlar[j + 12] == ']')
                        {
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] | RAM[((int)Komutlar[j + 10] - 48) * 10 + (int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                        else
                        {
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] | RAM[(((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + (int)Komutlar[j + 12] - 48];

                            j = j + 14;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                        {
                            if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                            {
                                if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] | ((((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));

                                    j = j + 11;
                                }
                                else
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] | ((((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));
                                    j = j + 10;
                                }
                            }
                            else
                            {
                                RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] | (int)Komutlar[j + 9] - 48;
                                j = j + 9;
                            }
                        }
                    }
                }
                else
                {
                    if (Komutlar[j + 10] == 'A')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] | AX;

                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'B')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] | BX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'C')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] | CX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'D')
                    {
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] | DX;
                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == '[')
                    {
                        if (Komutlar[j + 12] == ']')
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] | RAM[(int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                        else if (Komutlar[j + 13] == ']')
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] | RAM[((int)Komutlar[j + 11] - 48) * 10 + (int)Komutlar[j + 12] - 48];

                            j = j + 14;
                        }
                        else
                        {
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] | RAM[(((int)Komutlar[j + 11] - 48) * 100) + (((int)Komutlar[j + 12] - 48) * 10) + (int)Komutlar[j + 13] - 48];

                            j = j + 15;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                        {
                            if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                            {
                                if (Komutlar[j + 12] <= 57 && Komutlar[j + 12] >= 48)
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] | ((((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + ((int)Komutlar[j + 12] - 48));

                                    j = j + 12;
                                }
                                else
                                {
                                    RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] | ((((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));

                                    j = j + 11;
                                }
                            }
                            else
                            {
                                RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] | (int)Komutlar[j + 10] - 48;

                                j = j + 10;
                            }
                        }
                    }
                }
            }
        }
        if (Komutlar[j] == 'B')
        {
            if (Komutlar[j + 4] == 'A')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    DX = AX % DX;
                    AX = AX / AX;

                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {

                    DX = AX % BX;
                    AX = AX / BX;

                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    DX = AX % CX;
                    AX = AX / CX;

                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        DX = AX % RAM[(int)Komutlar[j + 8] - 48];
                        AX = AX / RAM[(int)Komutlar[j + 8] - 48];

                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        DX = AX % RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        AX = AX / RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];

                        j = j + 11;
                    }
                    else
                    {
                        DX = AX % RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        AX = AX / RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];

                        j = j + 12;
                    }
                }
                else
                {

                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                DX = AX % ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                AX = AX / ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                DX = AX % ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                DX = AX / ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            DX = AX % (int)Komutlar[j + 7] - 48;
                            AX = AX / (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'B')
            {

                if (Komutlar[j + 7] == 'A')
                {
                    DX = BX % AX;
                    BX = BX / AX;

                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    DX = BX % BX;
                    BX = BX / BX;

                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    DX = BX % CX;
                    BX = BX + CX;

                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        DX = BX % RAM[(int)Komutlar[j + 8] - 48];
                        BX = BX / RAM[(int)Komutlar[j + 8] - 48];

                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        DX = BX % RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        BX = BX / RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];

                        j = j + 11;
                    }
                    else
                    {
                        DX = BX % RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        BX = BX / RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];

                        j = j + 12;
                    }
                }
                else
                {

                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                DX = BX % ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                BX = BX / ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                DX = BX % ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                BX = BX / ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            DX = BX % (int)Komutlar[j + 7] - 48;
                            BX = BX / (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == 'C')
            {
                if (Komutlar[j + 7] == 'A')
                {
                    DX = CX % AX;
                    CX = CX / AX;

                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'B')
                {
                    DX = CX % BX;
                    CX = CX / BX;

                    j = j + 9;
                }
                else if (Komutlar[j + 7] == 'C')
                {
                    DX = CX % CX;
                    CX = CX / CX;

                    j = j + 9;
                }
                else if (Komutlar[j + 7] == '[')
                {
                    if (Komutlar[j + 9] == ']')
                    {
                        DX = CX % RAM[(int)Komutlar[j + 8] - 48];
                        CX = CX / RAM[(int)Komutlar[j + 8] - 48];

                        j = j + 10;
                    }
                    else if (Komutlar[j + 10] == ']')
                    {
                        DX = CX % RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];
                        CX = CX / RAM[((int)Komutlar[j + 8] - 48) * 10 + ((int)Komutlar[j + 9] - 48)];

                        j = j + 11;
                    }
                    else
                    {
                        CX = CX % RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];
                        CX = CX / RAM[((int)Komutlar[j + 8] - 48) * 100 + ((int)Komutlar[j + 9] - 48) * 10 + ((int)Komutlar[j + 10] - 48)];

                        j = j + 12;
                    }
                }
                else
                {
                    if (Komutlar[j + 7] <= 57 && Komutlar[j + 7] >= 48)
                    {

                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {
                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                DX = CX % ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                CX = CX / ((((int)Komutlar[j + 7] - 48) * 100) + (((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                j = j + 10;
                            }
                            else
                            {
                                DX = CX % ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                CX = CX / ((((int)Komutlar[j + 7] - 48) * 10) + ((int)Komutlar[j + 8] - 48));
                                j = j + 9;
                            }
                        }
                        else
                        {
                            DX = CX % (int)Komutlar[j + 7] - 48;
                            CX = CX / (int)Komutlar[j + 7] - 48;
                            j = j + 8;
                        }
                    }
                }
            }
            else if (Komutlar[j + 4] == '[')
            {
                if (Komutlar[j + 6] == ']')
                {
                    if (Komutlar[j + 8] == 'A')
                    {
                        DX = RAM[(int)Komutlar[j + 5] - 48] % AX;
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] / AX;

                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'B')
                    {
                        DX = RAM[(int)Komutlar[j + 5] - 48] % BX;
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] / BX;

                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == 'C')
                    {
                        DX = RAM[(int)Komutlar[j + 5] - 48] % CX;
                        RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] / CX;

                        j = j + 10;
                    }
                    else if (Komutlar[j + 8] == '[')
                    {
                        if (Komutlar[j + 10] == ']')
                        {
                            DX = RAM[(int)Komutlar[j + 5] - 48] % RAM[(int)Komutlar[j + 9] - 48];
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] / RAM[(int)Komutlar[j + 9] - 48];

                            j = j + 11;
                        }
                        else if (Komutlar[j + 11] == ']')
                        {
                            DX = RAM[(int)Komutlar[j + 5] - 48] & RAM[((int)Komutlar[j + 9] - 48) * 10 + (int)Komutlar[j + 10] - 48];
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] / RAM[((int)Komutlar[j + 9] - 48) * 10 + (int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else
                        {
                            DX = RAM[(int)Komutlar[j + 5] - 48] % RAM[(((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + (int)Komutlar[j + 11] - 48];
                            RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] / RAM[(((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + (int)Komutlar[j + 11] - 48];
                            j = j + 13;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 8] <= 57 && Komutlar[j + 8] >= 48)
                        {

                            if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                            {
                                if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                                {
                                    DX = RAM[(int)Komutlar[j + 5] - 48] % ((((int)Komutlar[j + 8] - 48) * 100) + (((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));
                                    RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] / ((((int)Komutlar[j + 8] - 48) * 100) + (((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));

                                    j = j + 10;
                                }
                                else
                                {
                                    DX = RAM[(int)Komutlar[j + 5] - 48] % ((((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                    RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] / ((((int)Komutlar[j + 8] - 48) * 10) + ((int)Komutlar[j + 9] - 48));
                                    j = j + 9;
                                }
                            }
                            else
                            {
                                DX = RAM[(int)Komutlar[j + 5] - 48] % (int)Komutlar[j + 8] - 48;
                                RAM[(int)Komutlar[j + 5] - 48] = RAM[(int)Komutlar[j + 5] - 48] / (int)Komutlar[j + 8] - 48;
                                j = j + 8;
                            }
                        }
                    }
                }
                else if (Komutlar[j + 7] == ']')
                {
                    if (Komutlar[j + 9] == 'A')
                    {
                        DX = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] % AX;
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] / AX;

                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'B')
                    {
                        DX = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] % BX;
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] / BX;

                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == 'C')
                    {
                        DX = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] % CX;
                        RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] / CX;

                        j = j + 11;
                    }
                    else if (Komutlar[j + 9] == '[')
                    {
                        if (Komutlar[j + 11] == ']')
                        {
                            DX = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] % RAM[(int)Komutlar[j + 10] - 48];
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] / RAM[(int)Komutlar[j + 10] - 48];

                            j = j + 12;
                        }
                        else if (Komutlar[j + 12] == ']')
                        {
                            DX = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] % RAM[((int)Komutlar[j + 10] - 48) * 10 + (int)Komutlar[j + 11] - 48];
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] / RAM[((int)Komutlar[j + 10] - 48) * 10 + (int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                        else
                        {
                            DX = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] % RAM[(((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + (int)Komutlar[j + 12] - 48];
                            RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] = RAM[((int)Komutlar[j + 5] - 48) * 10 + ((int)Komutlar[j + 6] - 48)] / RAM[(((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + (int)Komutlar[j + 12] - 48];

                            j = j + 14;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 9] <= 57 && Komutlar[j + 9] >= 48)
                        {
                            if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                            {
                                if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                                {
                                    DX = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] % ((((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));
                                    RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] / ((((int)Komutlar[j + 9] - 48) * 100) + (((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));

                                    j = j + 11;
                                }
                                else
                                {
                                    DX = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] % ((((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));
                                    RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] % ((((int)Komutlar[j + 9] - 48) * 10) + ((int)Komutlar[j + 10] - 48));
                                    j = j + 10;
                                }
                            }
                            else
                            {
                                DX = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] % (int)Komutlar[j + 9] - 48;
                                RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 10) + ((int)Komutlar[j + 6] - 48)] % (int)Komutlar[j + 9] - 48;
                                j = j + 9;
                            }
                        }
                    }
                }
                else
                {
                    if (Komutlar[j + 10] == 'A')
                    {
                        DX = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] % AX;
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] / AX;

                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'B')
                    {
                        DX = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] % BX;
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] / BX;

                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == 'C')
                    {
                        DX = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] % CX;
                        RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] / CX;

                        j = j + 12;
                    }
                    else if (Komutlar[j + 10] == '[')
                    {
                        if (Komutlar[j + 12] == ']')
                        {
                            DX = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] % RAM[(int)Komutlar[j + 11] - 48];
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] / RAM[(int)Komutlar[j + 11] - 48];

                            j = j + 13;
                        }
                        else if (Komutlar[j + 13] == ']')
                        {
                            DX = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] % RAM[((int)Komutlar[j + 11] - 48) * 10 + (int)Komutlar[j + 12] - 48];
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] / RAM[((int)Komutlar[j + 11] - 48) * 10 + (int)Komutlar[j + 12] - 48];

                            j = j + 14;
                        }
                        else
                        {
                            DX = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] % RAM[(((int)Komutlar[j + 11] - 48) * 100) + (((int)Komutlar[j + 12] - 48) * 10) + (int)Komutlar[j + 13] - 48];
                            RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] / RAM[(((int)Komutlar[j + 11] - 48) * 100) + (((int)Komutlar[j + 12] - 48) * 10) + (int)Komutlar[j + 13] - 48];

                            j = j + 15;
                        }
                    }
                    else
                    {
                        if (Komutlar[j + 10] <= 57 && Komutlar[j + 10] >= 48)
                        {
                            if (Komutlar[j + 11] <= 57 && Komutlar[j + 11] >= 48)
                            {
                                if (Komutlar[j + 12] <= 57 && Komutlar[j + 12] >= 48)
                                {
                                    DX = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] % ((((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + ((int)Komutlar[j + 12] - 48));
                                    RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] % ((((int)Komutlar[j + 10] - 48) * 100) + (((int)Komutlar[j + 11] - 48) * 10) + ((int)Komutlar[j + 12] - 48));

                                    j = j + 12;
                                }
                                else
                                {
                                    DX = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] % ((((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));
                                    RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] % ((((int)Komutlar[j + 10] - 48) * 10) + ((int)Komutlar[j + 11] - 48));
                                    j = j + 11;
                                }
                            }
                            else
                            {
                                DX = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] % (int)Komutlar[j + 10] - 48;
                                RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] = RAM[(((int)Komutlar[j + 5] - 48) * 100) + (((int)Komutlar[j + 6] - 48) * 10) + ((int)Komutlar[j + 7] - 48)] / (int)Komutlar[j + 10] - 48;

                                j = j + 10;
                            }
                        }
                    }
                }
            }
        }
        j++;
    }
    printf("AX:%d\t\n", AX);
    printf("BX:%d\t\n", BX);
    printf("CX:%d\t\n", CX);
    printf("DX:%d\t\n", DX);
    int k = 0;
    while (k < 256)
    {
        if (RAM[k] != -1)
        {
            printf("\nRAM: %d\n", RAM[k]);
        }
        k++;
    }
}
