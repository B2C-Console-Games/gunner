/*
 * Title: The annotated BASIC Listing
 *
 *  Listing of /home/alan/dev/BasicGames/source/base/gunner/basic/gunner.bas: 
 *
                   +---- Routine IDs (Empty field=Inaccessible code, A=Main program).
                   | +-- Target status (G-GOSUB, T-GOTO, B-Both GOSUB and GOTO)
        Program    | |
        Address    v v Original BASIC statement
    -------------- - - ------------------------------------------------------------------------------
    0x5570e57dcde0 ---------A   01000 PRINT "DATALINE SYSTEMS LIMITED  25-JULY-70"
    0x5570e57dcf70 ---------A   01010 PRINT "B A S I C  USER LIBRARY PROGRAM--GUNNER"
    0x5570e57dd110 ---------A   01020 PRINT"THIS TIME-SHARING DEMONSTRATION SIMULATES"
    0x5570e57dd270 ---------A   01030 PRINT"THE RESULTS OF FIRING A FIELD ARTILLERY WEAPON."
    0x5570e57dd310 ---------A   01040 PRINT
    0x5570e57dd4f0 ---------A   01050 PRINT"YOU ARE THE OFFICER-IN-CHARGE, GIVING ORDERS TO THE GUN"
    0x5570e57dd680 ---------A   01060 PRINT"CREW, TELLING THEM THE DEGREES OF ELEVATION YOU ESTIMATE"
    0x5570e57dd7f0 ---------A   01070 PRINT"WILL PLACE THE PROJECTILE ON TARGET. A HIT WITHIN 100"
    0x5570e57dd8e0 ---------A   01080 PRINT"YARDS OF THE TARGET WILL DESTROY IT."
    0x5570e57dd360 ---------A   01090 PRINT
    0x5570e57ddb10 ---------A   01100 PRINT"MAXIMUM RANGE OF YOUR GUN IS 46500 YARDS."
    0x5570e57ddb90 ---------A   01110 REM T=DISTANCE TO TARGET
    0x5570e57ddc20 ---------A   01120 REM I=DISTANCE OF SHOT
    0x5570e57e1f50 ---------A   01130 REM E=DISTANCE OVER(NEGATIVE), OR UNDER (POSITIVE) TARGET
    0x5570e57e2440 ---------A T 01140 LET T=43000-30000*RND(X)
    0x5570e57e2630 ---------A   01150 LET S=0
    0x5570e57e26c0 ---------A   01160 GOTO 1410
    0x5570e57e2900 ---------A T 01170 PRINT"MIN. ELEVTION OF GUN IS ONE DEGREE."
    0x5570e57e2990 ---------A   01180 GOTO 1430
    0x5570e57e2ac0 ---------A T 01190 PRINT"MAX. ELEVATION OF GUN IS 89 DEGREES."
    0x5570e57e2b50 ---------A   01200 GOTO 1430
    0x5570e57e2f30 ---------A T 01210 PRINT"OVER TARGET BY";ABS(E);"YARDS."
    0x5570e57e2fc0 ---------A   01220 GOTO 1430
    0x5570e57e32a0 ---------A T 01230 PRINT"SHORT OF TARGET BY";ABS(E);"YARDS."
    0x5570e57e3310 ---------A   01240 GOTO 1430
    0x5570e57e33a0 ---------A T 01250 GOTO 1260
    0x5570e57e3630 ---------A T 01260 PRINT"***TARGET DESTROYED***  ";S;"ROUNDS EXPENDED"
    0x5570e57e36a0 ---------A   01270 PRINT
    0x5570e57e3710 ---------A   01280 PRINT
    0x5570e57e3780 ---------A   01290 PRINT
    0x5570e57e37f0 ---------A   01300 PRINT
    0x5570e57e3860 ---------A   01310 PRINT
    0x5570e57e38d0 ---------A   01320 PRINT
    0x5570e57e3b50 ---------A   01330 PRINT
    0x5570e57e3bc0 ---------A   01340 PRINT
    0x5570e57e3c30 ---------A   01350 PRINT
    0x5570e57e3ca0 ---------A   01360 PRINT
    0x5570e57e3d10 ---------A   01370 PRINT
    0x5570e57e3db0 ---------A   01380 PRINT
    0x5570e57e3f00 ---------A   01390 PRINT"THE FORWARD OBSERVER HAS SIGHTED MORE ENEMY ACTIVITY."
    0x5570e57e3f90 ---------A   01400 GOTO 1140
    0x5570e57e4300 ---------A T 01410 PRINT"   DISTANCE TO THE TARGET IS";INT(T);"YARDS"
    0x5570e57e4370 ---------A   01420 PRINT
    0x5570e57e43e0 ---------A T 01430 PRINT
    0x5570e57e4530 ---------A   01440 PRINT"ELEVATION:";
    0x5570e57e4680 ---------A   01450 INPUT B!
    0x5570e57e4840 ---------A   01460 IF B!>89 THEN 1190
    0x5570e57e4a00 ---------A   01470 IF B!<1 THEN 1170
    0x5570e57e4c20 ---------A   01480 LET S=S+1
    0x5570e57e4fa0 ---------A   01490 LET B2=2*B!/57.3
    0x5570e57e5310 ---------A   01500 LET I=46500*SIN(B2)
    0x5570e57e54e0 ---------A   01510 LET X=T-I
    0x5570e57e5680 ---------A   01520 LET E=INT(X)
    0x5570e57e5890 ---------A   01530 IF ABS(E)<100 THEN 1250
    0x5570e57e5a60 ---------A   01540 IF E>100 THEN 1230
    0x5570e57e5c20 ---------A   01550 IF E<-100 THEN 1210
    0x5570e57e5c80 ---------A   01560 END
 */

/*
 * Line reference table:
 *

    Target
   Line Num.    Referencing line number (Reference is T-GOTO or G-GOSUB).
   ---------    -------------------------------------------------------------------
     01140      01400T
     01170      01470T
     01190      01460T
     01210      01550T
     01230      01540T
     01250      01530T
     01260      01250T
     01410      01160T
     01430      01180T, 01200T, 01220T, 01240T

 */

/* 
 * Routine Start, Target, Return and End Program Addresses 
 * 

  Rtn      Start           Target           Return             End    
  --- --------------   --------------   --------------   -------------- 
   A) 0x5570e57dcde0   0x5570e57dcde0   0x5570e57e5c80   0x5570e57e5c80 


 */



/*
 * Free line number map.
 *
     Start    End    # Lines in Gap
     -----   -----   ------------------
     00000 - 00990     100 
     01570 - 10000    8440 

 */



/*
 *  Symbol Table Listing for '/home/alan/dev/BasicGames/source/base/gunner/basic/gunner.bas'
 *
    ABS   Function Integer     args=1, int   
    B!             Float   
    B2             Float   
    E              Integer 
    I              Integer 
    INT   Function Integer     args=1, float 
    RND   Function Integer     args=1, int   
    S              Integer 
    SIN   Function Integer     args=1, float 
    T              Integer 
    X              Integer 

 */


/*
 * Title: Display of final 'clean' BASIC listing.
 *
 *  Listing of /home/alan/dev/BasicGames/source/base/gunner/basic/gunner.bas: 
 *
                   +---- Routine IDs (Empty field=Inaccessible code, A=Main program).
                   | +-- Target status (G-GOSUB, T-GOTO, B-Both GOSUB and GOTO)
        Program    | |
        Address    v v Original BASIC statement
    -------------- - - ------------------------------------------------------------------------------
    0x5570e57dcde0 ---------A   01000 PRINT "DATALINE SYSTEMS LIMITED  25-JULY-70"
    0x5570e57dcf70 ---------A   01010 PRINT "B A S I C  USER LIBRARY PROGRAM--GUNNER"
    0x5570e57dd110 ---------A   01020 PRINT"THIS TIME-SHARING DEMONSTRATION SIMULATES"
    0x5570e57dd270 ---------A   01030 PRINT"THE RESULTS OF FIRING A FIELD ARTILLERY WEAPON."
    0x5570e57dd310 ---------A   01040 PRINT
    0x5570e57dd4f0 ---------A   01050 PRINT"YOU ARE THE OFFICER-IN-CHARGE, GIVING ORDERS TO THE GUN"
    0x5570e57dd680 ---------A   01060 PRINT"CREW, TELLING THEM THE DEGREES OF ELEVATION YOU ESTIMATE"
    0x5570e57dd7f0 ---------A   01070 PRINT"WILL PLACE THE PROJECTILE ON TARGET. A HIT WITHIN 100"
    0x5570e57dd8e0 ---------A   01080 PRINT"YARDS OF THE TARGET WILL DESTROY IT."
    0x5570e57dd360 ---------A   01090 PRINT
    0x5570e57ddb10 ---------A   01100 PRINT"MAXIMUM RANGE OF YOUR GUN IS 46500 YARDS."
    0x5570e57ddb90 ---------A   01110 REM T=DISTANCE TO TARGET
    0x5570e57ddc20 ---------A   01120 REM I=DISTANCE OF SHOT
    0x5570e57e1f50 ---------A   01130 REM E=DISTANCE OVER(NEGATIVE), OR UNDER (POSITIVE) TARGET
    0x5570e57e2440 ---------A T 01140 LET T=43000-30000*RND(X)
    0x5570e57e2630 ---------A   01150 LET S=0
    0x5570e57e26c0 ---------A   01160 GOTO 1410
    0x5570e57e2900 ---------A T 01170 PRINT"MIN. ELEVTION OF GUN IS ONE DEGREE."
    0x5570e57e2990 ---------A   01180 GOTO 1430
    0x5570e57e2ac0 ---------A T 01190 PRINT"MAX. ELEVATION OF GUN IS 89 DEGREES."
    0x5570e57e2b50 ---------A   01200 GOTO 1430
    0x5570e57e2f30 ---------A T 01210 PRINT"OVER TARGET BY";ABS(E);"YARDS."
    0x5570e57e2fc0 ---------A   01220 GOTO 1430
    0x5570e57e32a0 ---------A T 01230 PRINT"SHORT OF TARGET BY";ABS(E);"YARDS."
    0x5570e57e3310 ---------A   01240 GOTO 1430
    0x5570e57e33a0 ---------A T 01250 GOTO 1260
    0x5570e57e3630 ---------A T 01260 PRINT"***TARGET DESTROYED***  ";S;"ROUNDS EXPENDED"
    0x5570e57e36a0 ---------A   01270 PRINT
    0x5570e57e3710 ---------A   01280 PRINT
    0x5570e57e3780 ---------A   01290 PRINT
    0x5570e57e37f0 ---------A   01300 PRINT
    0x5570e57e3860 ---------A   01310 PRINT
    0x5570e57e38d0 ---------A   01320 PRINT
    0x5570e57e3b50 ---------A   01330 PRINT
    0x5570e57e3bc0 ---------A   01340 PRINT
    0x5570e57e3c30 ---------A   01350 PRINT
    0x5570e57e3ca0 ---------A   01360 PRINT
    0x5570e57e3d10 ---------A   01370 PRINT
    0x5570e57e3db0 ---------A   01380 PRINT
    0x5570e57e3f00 ---------A   01390 PRINT"THE FORWARD OBSERVER HAS SIGHTED MORE ENEMY ACTIVITY."
    0x5570e57e3f90 ---------A   01400 GOTO 1140
    0x5570e57e4300 ---------A T 01410 PRINT"   DISTANCE TO THE TARGET IS";INT(T);"YARDS"
    0x5570e57e4370 ---------A   01420 PRINT
    0x5570e57e43e0 ---------A T 01430 PRINT
    0x5570e57e4530 ---------A   01440 PRINT"ELEVATION:";
    0x5570e57e4680 ---------A   01450 INPUT B!
    0x5570e57e4840 ---------A   01460 IF B!>89 THEN 1190
    0x5570e57e4a00 ---------A   01470 IF B!<1 THEN 1170
    0x5570e57e4c20 ---------A   01480 LET S=S+1
    0x5570e57e4fa0 ---------A   01490 LET B2=2*B!/57.3
    0x5570e57e5310 ---------A   01500 LET I=46500*SIN(B2)
    0x5570e57e54e0 ---------A   01510 LET X=T-I
    0x5570e57e5680 ---------A   01520 LET E=INT(X)
    0x5570e57e5890 ---------A   01530 IF ABS(E)<100 THEN 1250
    0x5570e57e5a60 ---------A   01540 IF E>100 THEN 1230
    0x5570e57e5c20 ---------A   01550 IF E<-100 THEN 1210
    0x5570e57e5c80 ---------A   01560 END
 */

//---------------------------------------------------------------------------
// $Header$ 
//
// NOTE: This program has been automatically tranlated by b2c
//
// $Log$ 
// 
//---------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//---------------------------------------------------------------------------
// Global data area.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------




typedef enum {TYPE_None,TYPE_Integer,TYPE_Float,TYPE_String}t_type;
typedef struct{
    int    LineNum;
    int    Size;
    char** SData;
}t_data;
t_data ProgramData[] = {
    {    0,  0,nullptr       }
};

#include "intrinsics.h"


//---------------------------------------------------------------------------
// Global variable area.
//
// NOTE: Variable names are long to allow for easy editing.
//---------------------------------------------------------------------------
float B_flt;        // Comments?
float B2_flt;       // Comments?
int   E_int;        // Comments?
int   I_int;        // Comments?
int   S_int;        // Comments?
int   T_int;        // Comments?
int   X_int;        // Comments?
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char* GLBpStr=nullptr;
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Subroutine Prototypes.
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Program Functions.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// Program Subroutines.
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// Main Program.
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc,char *argv[])
{
    // 01000 PRINT "DATALINE SYSTEMS LIMITED  25-JULY-70"
    b2c_fprintf(stdout,"DATALINE SYSTEMS LIMITED  25-JULY-70"); b2c_fprintf(stdout,"\n");
    // 01010 PRINT "B A S I C  USER LIBRARY PROGRAM--GUNNER"
    b2c_fprintf(stdout,"B A S I C  USER LIBRARY PROGRAM--GUNNER"); b2c_fprintf(stdout,"\n");
    // 01020 PRINT"THIS TIME-SHARING DEMONSTRATION SIMULATES"
    b2c_fprintf(stdout,"THIS TIME-SHARING DEMONSTRATION SIMULATES"); b2c_fprintf(stdout,"\n");
    // 01030 PRINT"THE RESULTS OF FIRING A FIELD ARTILLERY WEAPON."
    b2c_fprintf(stdout,"THE RESULTS OF FIRING A FIELD ARTILLERY WEAPON."); b2c_fprintf(stdout,"\n");
    // 01040 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01050 PRINT"YOU ARE THE OFFICER-IN-CHARGE, GIVING ORDERS TO THE GUN"
    b2c_fprintf(stdout,"YOU ARE THE OFFICER-IN-CHARGE, GIVING ORDERS TO THE GUN"); b2c_fprintf(stdout,"\n");
    // 01060 PRINT"CREW, TELLING THEM THE DEGREES OF ELEVATION YOU ESTIMATE"
    b2c_fprintf(stdout,"CREW, TELLING THEM THE DEGREES OF ELEVATION YOU ESTIMATE"); b2c_fprintf(stdout,"\n");
    // 01070 PRINT"WILL PLACE THE PROJECTILE ON TARGET. A HIT WITHIN 100"
    b2c_fprintf(stdout,"WILL PLACE THE PROJECTILE ON TARGET. A HIT WITHIN 100"); b2c_fprintf(stdout,"\n");
    // 01080 PRINT"YARDS OF THE TARGET WILL DESTROY IT."
    b2c_fprintf(stdout,"YARDS OF THE TARGET WILL DESTROY IT."); b2c_fprintf(stdout,"\n");
    // 01090 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01100 PRINT"MAXIMUM RANGE OF YOUR GUN IS 46500 YARDS."
    b2c_fprintf(stdout,"MAXIMUM RANGE OF YOUR GUN IS 46500 YARDS."); b2c_fprintf(stdout,"\n");
    // 01110 REM T=DISTANCE TO TARGET
    // 01120 REM I=DISTANCE OF SHOT
    // 01130 REM E=DISTANCE OVER(NEGATIVE), OR UNDER (POSITIVE) TARGET

  Lbl_01140:
    // 01140 LET T=43000-30000*RND(X)
    T_int = 43000-30000*RND(X_int);
    // 01150 LET S=0
    S_int = 0;
    // 01160 GOTO 1410
    goto Lbl_01410;

  Lbl_01170:
    // 01170 PRINT"MIN. ELEVTION OF GUN IS ONE DEGREE."
    b2c_fprintf(stdout,"MIN. ELEVTION OF GUN IS ONE DEGREE."); b2c_fprintf(stdout,"\n");
    // 01180 GOTO 1430
    goto Lbl_01430;

  Lbl_01190:
    // 01190 PRINT"MAX. ELEVATION OF GUN IS 89 DEGREES."
    b2c_fprintf(stdout,"MAX. ELEVATION OF GUN IS 89 DEGREES."); b2c_fprintf(stdout,"\n");
    // 01200 GOTO 1430
    goto Lbl_01430;

  Lbl_01210:
    // 01210 PRINT"OVER TARGET BY";ABS(E);"YARDS."
    b2c_fprintf(stdout,"OVER TARGET BY %d YARDS.",ABS(E_int)); b2c_fprintf(stdout,"\n");
    // 01220 GOTO 1430
    goto Lbl_01430;

  Lbl_01230:
    // 01230 PRINT"SHORT OF TARGET BY";ABS(E);"YARDS."
    b2c_fprintf(stdout,"SHORT OF TARGET BY %d YARDS.",ABS(E_int)); b2c_fprintf(stdout,"\n");
    // 01240 GOTO 1430
    goto Lbl_01430;

  Lbl_01250:
    // 01250 GOTO 1260
    goto Lbl_01260;

  Lbl_01260:
    // 01260 PRINT"***TARGET DESTROYED***  ";S;"ROUNDS EXPENDED"
    b2c_fprintf(stdout,"***TARGET DESTROYED***   %d ROUNDS EXPENDED",S_int); b2c_fprintf(stdout,"\n");
    // 01270 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01280 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01290 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01300 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01310 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01320 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01330 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01340 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01350 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01360 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01370 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01380 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01390 PRINT"THE FORWARD OBSERVER HAS SIGHTED MORE ENEMY ACTIVITY."
    b2c_fprintf(stdout,"THE FORWARD OBSERVER HAS SIGHTED MORE ENEMY ACTIVITY."); b2c_fprintf(stdout,"\n");
    // 01400 GOTO 1140
    goto Lbl_01140;

  Lbl_01410:
    // 01410 PRINT"   DISTANCE TO THE TARGET IS";INT(T);"YARDS"
    b2c_fprintf(stdout,"   DISTANCE TO THE TARGET IS %d YARDS",INT(T_int)); b2c_fprintf(stdout,"\n");
    // 01420 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");

  Lbl_01430:
    // 01430 PRINT
    b2c_fprintf(stdout,""); b2c_fprintf(stdout,"\n");
    // 01440 PRINT"ELEVATION:";
    b2c_fprintf(stdout,"ELEVATION:"); 
    // 01450 INPUT B!
    // Start of Basic INPUT statement 01450
    printf(" ? ");
    char inpbuf_01450[100];
    if(fgets(inpbuf_01450,100,stdin)==nullptr){
        fprintf(stderr,"ERROR: End of file on input.\n");
        exit(2);
    }else{
        char *ps_01450=strtok(inpbuf_01450," ,\t\n");
        // This may cause problems if BASIC programmer expected
        // input strings to be copied instead of just pointing
        // to the input buffer (ie. strings can be over written).
        if(ps_01450==nullptr){
            B_flt = 0.00;
        }else{
            B_flt = atof(ps_01450);
        };
    }; // End of Basic INPUT statement 01450
    // 01460 IF B!>89 THEN 1190
    if(B_flt>89)goto Lbl_01190;
    // 01470 IF B!<1 THEN 1170
    if(B_flt<1)goto Lbl_01170;
    // 01480 LET S=S+1
    S_int = S_int+1;
    // 01490 LET B2=2*B!/57.3
    B2_flt = 2*B_flt/57.299999;
    // 01500 LET I=46500*SIN(B2)
    I_int = 46500*SIN(B2_flt);
    // 01510 LET X=T-I
    X_int = T_int-I_int;
    // 01520 LET E=INT(X)
    E_int = INT(X_int);
    // 01530 IF ABS(E)<100 THEN 1250
    if(ABS(E_int)<100)goto Lbl_01250;
    // 01540 IF E>100 THEN 1230
    if(E_int>100)goto Lbl_01230;
    // 01550 IF E<-100 THEN 1210
    if(E_int<-100)goto Lbl_01210;
    // 01560 END
   return(0);
};

//---------------------------------------------------------------------------
// End of $RCSfile$ 
//---------------------------------------------------------------------------
