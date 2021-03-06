#ifndef _PLAYER_H
#define _PLAYER_H

#include "../../console.h"
#define Nil NULL
 
typedef int ElType;
#define IdxMax 4
#define IdxMin 1
#define IdxUndef -999
 
typedef struct listSkillNode *address;
typedef struct listSkillNode {
    address nextskill;
    char skillName[25];
} lsNode;
 
typedef struct {
    address addrFirstSkill;
} Skill;
 
/* Player menggunakan array */
typedef struct {
    char uname[IdxMax+1][16];
    int Neff;
} pUserName;
 
typedef struct {
    ElType pos[IdxMax+1];
} pPosition;
 
typedef struct {
    boolean isTele[IdxMax+1];
} pIsTeleported;

/* array BUFF semua 4 typedef dibawah ini */
typedef struct {
    boolean isImun[IdxMax+1];
} pIsImune;
 
typedef struct {
    boolean isCermin[IdxMax+1];
} pIsCermin;
 
typedef struct {
    boolean isSenterBesar[IdxMax+1];
} pIsSenterBesar;
 
typedef struct {
    boolean isSenterKecil[IdxMax+1];
} pIsSenterKecil;
 
#define ADDR_HEADSKILL(p) (p).addrFirstSkill
#define NEXTSKILL(p) (p)->nextskill
#define SKILLNAME(p) (p)->skillName
 
void createEmptyPlayerList (pUserName *pU);
/*
    I.S. array pU sembarang
    F.S. array pU kosong
*/
void createEmptyPlayerSkillsList (Skill *S);
/*
    I.S Linked List S sembarang
    F.S Linked List S kosong
*/
address newSkillNode ();
/*
    Fungsi mereturn sebuah address dari lsNode (list skill node)
    Jika fungsi gagal mengalokasi lsNode maka akan mereturn Nil
*/
void preparationSkillList (Skill *pS1, Skill *pS2, Skill *pS3, Skill *pS4, int n);
/*
    I.S     sembarang
    F.S     semua list player skill kosong
*/
 
void printSkill (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP, int *nSkill);
 /*
    prosedur print semua skill yang dimiliki player dengan index idxP
 */
int banyaknyaSkill (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP);
/*
    fungsi untuk return banyaknya skill dari player dengan index idxP
*/
int returnIdxSkill (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP, char *skName);
/*
    fungsi return index dari skill dengan nama sama dengan skName di player dengan index idxP
*/
boolean isSkillExists (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP, char *skName);
/*
    fungsi untuk mengecek apakah skill skName ada di list Skill player dengan index idxP
*/
void deleteSkill (Skill *pS1, Skill *pS2, Skill *pS3, Skill *pS4, int idxP, int idxS);
/*
    menghapus skill dengan index skill idxS di list skill player dengan index idxP
*/
void summonPlayer(pUserName *pU, pIsTeleported *pT, pPosition *pP, pIsImune *pI, pIsCermin *pC,
pIsSenterBesar *pSB, pIsSenterKecil *pSK, int n);
/*
    Prosedur untuk membuat list pemain sebanyak n pemain
    I.S array pU, pT, pP, pI, pC, pSB, pSK kosong
    F.S array pU, pT, pP, pI, pC, pSB, pSK terisi informasi kondisi awal permainan sebanyak n
        pU.uname[ indexPlayer ] terisi inputan
*/
int getIdxOfPlayer (pUserName pU, char *name);
/*
    Fungsi mereturn index player dalam array pU dengan username parameter input uname
    Jika tidak ditemukan player uname di dalam array pU, maka akan meretrun IdxUndef
*/
void insertVSkill (Skill *pS, char *skname);
/*
    Prosedur menambahkan skill skname ke linked list pS
    I.S linked list sembarang
    F.S jika linked list < 10 akan ditambahkan skill
        Jika penuh Skill  akan tetap
*/
boolean isEmptyList (Skill pS);
/*
    Mereturn True jika pS kosong
*/
boolean getTeleportedConditionOfPlayer (pIsTeleported pT, int idx);
/*
    Fungsi untuk mendapatkan informasi kondisi pemain dengan index idx, apakah
    sebelumnya terkena portal (teleported) atau tidak
*/
boolean getImmunityConditionOfPlayer (pIsImune pI, int idx);
/*
    Fungsi untuk mendapatkan informasi kondisi pemain dengan index idx, apakah
    Sedang imune terhadap efek apapun atau tidak
*/
 
boolean getCerminConditionOfPlayer (pIsCermin pC, int idx);
/*
    Fungsi untuk mendapatkan informasi kondisi pemain dengan index idx, apakah
    Sedang memiliki buff cermin ganda atau tidak
*/
 
boolean getSenterBesarConditionOfPlayer (pIsSenterBesar pSB, int idx);
/*
    Fungsi untuk mendapatkan informasi kondisi pemain dengan index idx, apakah
    Sedang memiliki buff senter pembesar atau tidak
*/
 
boolean getSenterKecilConditionOfPlayer (pIsSenterKecil pSK, int idx);
/*
    Fungsi untuk mendapatkan informasi kondisi pemain dengan index idx, apakah
    Sedang memiliki buff senter pengecil atau tidak
*/
 
 
int getPositionOfPlayer (pPosition pP, int idx);
/*
    Fungsi untuk mendapatkan informasi posisi terakhir dari pemain dengan index idx
    uname;
*/
 
void randomSkillGenerator(char *skname);
/*
    prosedur untuk merandom SKILL dan menyimpannya di skname sesuai dengan chance
    masing-masing skill.
*/

void copySkillName (Skill pS1, Skill pS2, Skill pS3, Skill pS4, int idxP, int idxSkill, char *skname);
/*
    menyalin skill index idxSkill pada player dengan index idxP, dan menyimpannya di skname
*/

int randomInt99();
/*
    fungsi return random integer [0..99]
*/
#endif
