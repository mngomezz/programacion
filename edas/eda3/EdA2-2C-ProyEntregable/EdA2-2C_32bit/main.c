/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ NO DEBE HACER NINGUNA MODIFICACIÓN                         *//**/
/**//**//*      SÓLO PARA SUS PRUEBAS CON LOS DISTINTOS                   *//**/
/**//**//*      LOTES E INVOCAR A SUS FUNCIONES                           *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

#include "main.h"


int main()
{
    FILE   *fpPantalla;
#ifdef CODIGO_ALUMNO
    fpPantalla = fopen("pantalla.txt", "wt");
#else
    fpPantalla = fopen("pantallaBIEN.txt", "wt");
#endif
    if(fpPantalla == NULL)
        fpPantalla = stdout;

    crearArchivos(PED_A TXT, PED_B TXT, PED_A_BIN, PED_B_BIN,
                  PED_AGRUP, PED_RESUM, PAGOS_DAT,
                  PED_OKA,   PED_BLK,   PED_UNK, PAT_ARCH);


    punto_1_a(fpPantalla);

    punto_1_b(fpPantalla);

    punto_1_c(fpPantalla);


    fclose(fpPantalla);
#ifdef CODIGO_ALUMNO
    system("start Notepad pantalla.txt");
#else
    system("start Notepad pantallaBIEN.txt");
#endif

    return 0;
}


/**
 **
 **/
void punto_1_a(FILE *fpPantalla)
{
    int     nrosDeCampos[7][9] = {
                    TIPO_A ,
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },  /// para sus pruebas
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },  /// para sus pruebas
                    TIPO_D ,
                    OTRO_TIPO,                      /// para sus pruebas
                    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },  /// para sus pruebas
                    OTRO_TIPO       };              /// para sus pruebas

    fprintf(fpPantalla,
            "******************************************** \n"
            "*    PUNTO 1 a.-: comienza a ejecutarse.   * \n"
            "******************************************** \n");

    mostrarArchTxt(PED_A  TXT, fpPantalla);
#ifdef PUNTO_1_A
    leerTxtGrabarBin_MIO(PED_A, nrosDeCampos, 7, TXT, BIN);
#else
    leerTxtGrabarBin(PED_A, nrosDeCampos, 7, TXT, BIN);
#endif
    mostrarArchBinTPed(PED_A_BIN, fpPantalla);
///////////
    mostrarArchTxt(PED_B  TXT, fpPantalla);
#ifdef PUNTO_1_A
    leerTxtGrabarBin_MIO(PED_B, nrosDeCampos, 7, TXT, BIN);
#else
    leerTxtGrabarBin(PED_B, nrosDeCampos, 7, TXT, BIN);
#endif
    mostrarArchBinTPed(PED_B_BIN, fpPantalla);
    fprintf(fpPantalla,
            "******************************************** \n"
            "*         Fin ejecución PUNTO 1 a.-        * \n"
            "******************************************** \n\n");
}

/**
 **
 **/
void punto_1_b(FILE *fpPantalla)
{
    fprintf(fpPantalla,
            "******************************************** \n"
            "*    PUNTO 1 b.-: comienza a ejecutarse.   * \n"
            "******************************************** \n");

    mostrarArchBinTPed(PED_A_BIN, fpPantalla);
    mostrarArchBinTPed(PED_B_BIN, fpPantalla);
#ifdef PUNTO_1_B
    leerPedsYAgrupar_MIO(PED_AGRUP, PED_A_BIN, PED_B_BIN);
#else
    leerPedsYAgrupar(PED_AGRUP, PED_A_BIN, PED_B_BIN);
#endif
    mostrarArchBinTPed(PED_AGRUP, fpPantalla);

    fprintf(fpPantalla,
            "******************************************** \n"
            "*         Fin ejecución PUNTO 1 b.-        * \n"
            "******************************************** \n\n");
}

/**
 **
 **/
void punto_1_c(FILE *fpPantalla)
{
    fprintf(fpPantalla,
            "******************************************** \n"
            "*    PUNTO 1 c.-: comienza a ejecutarse.   * \n"
            "******************************************** \n");

    mostrarArchBinTPed(PED_AGRUP, fpPantalla);
#ifdef PUNTO_1_C
    leerPedsYResumir_MIO(PED_RESUM, PED_AGRUP);
#else
    leerPedsYResumir(PED_RESUM, PED_AGRUP);
#endif
    mostrarArchBinTResu(PED_RESUM, fpPantalla);
    fprintf(fpPantalla,
            "******************************************** \n"
            "*         Fin ejecución PUNTO 1 c.-        * \n"
            "******************************************** \n\n");
}

