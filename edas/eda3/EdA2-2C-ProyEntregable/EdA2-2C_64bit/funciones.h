/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER MODIFICACI�N QUE HAGA NO SER� TENIDA EN CUENTA.      *//**/
/**//**//*                                                                *//**/
/**//**//*     �No deber�a hacer ninguna modificaci�n en este archivo!    *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>

#include "que_hice.h"
#include "pila/pila.h"

/** funciones de servicio **/
int crearArchivos(const char *pAtxt,  const char *pBtxt,
                  const char *pAbin,  const char *pBbin,
                  const char *pAgru,  const char *pResu, const char *pagos,
                  const char *pOka,   const char *pBlk,  const char *pUnk,
                  const char *nomDir);

int mostrarArchTxt(const char *patNamArch, FILE *fpPantalla);

int mostrarArchBinTPed(const char *patNamBin, FILE *fpPantalla);

int mostrarArchBinTResu(const char *patNamBin, FILE *fpPantalla);



#define PAT_ARCH            ".\\datos\\"

#define PED_A               PAT_ARCH    "ped_A"
#define TIPO_A              { 1, 2, 3, 4, 0, 208, -4, 88, 99 } ///  Tipo_A

#define PED_B               PAT_ARCH    "ped_B"
#define TIPO_D              { 2, 3, 1, 4, 0, 888, 54, -6, 104 } /// Tipo_D

#define OTRO_TIPO           { 6, 7, 8, 9, 0,  10, 11, 12,  13 }

#define TXT                 ".txt"
#define BIN                 ".bin"

#define PED_A_BIN           PED_A   BIN
#define PED_B_BIN           PED_B   BIN

#define PED_AGRUP           PAT_ARCH    "ped_agrup.bin"
#define PED_RESUM           PAT_ARCH    "ped_resum.bin"

#define PAGOS_DAT           PAT_ARCH    "pagos.dat"

#define PED_OKA             PAT_ARCH    "pedidos_ok.dat"
#define PED_BLK             PAT_ARCH    "pedidos_blk.dat"
#define PED_UNK             PAT_ARCH    "pedidos_unk.dat"


typedef struct
{
    char    codClie[8],
            claProd[8];
    int     cantPed;
    double  precUni;
} tPedido;

typedef struct
{
    tPedido pedido;
    int     nroRegistro;
} tResumido;

typedef struct
{
    char    codClie[8];
    double  montoTransf;
} tPagos;

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/** para el PUNTO 1 a.- **/
int leerTxtGrabarBin(const char *nomSinExt, int campos[][9], int filaTope,
                     const char *txt, const char *bin);

int leerTxtGrabarBin_MIO(const char *nomSinExt, int campos[][9], int filaTope,
                         const char *txt, const char *bin);

/** para el PUNTO 1 b.- **/
int leerPedsYAgrupar(const char *nomSal,
                     const char *nomEnt1, const char *nomEnt2);

int leerPedsYAgrupar_MIO(const char *nomSal,
                         const char *nomEnt1, const char *nomEnt2);

/** para el PUNTO 1 c.- **/
int leerPedsYResumir(const char *nomSal, const char *nomEnt);

int leerPedsYResumir_MIO(const char *nomSal, const char *nomEnt);

/** para el PUNTO 1 d.- **/
int despacharPedidos(const char *nomOka, const char *nomBlk,
                     const char *nomUnk, const char *nomPagos,
                     const char *nomResu);

int despacharPedidos_MIO(const char *nomOka, const char *nomBlk,
                         const char *nomUnk, const char *nomPagos,
                         const char *nomResu);


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/


#endif

