#include "mcc_generated_files/ext_int.h"
#include "Varient.h"
#include "rpmHole.h"

//カスタムハンドラ　ホール素子のフォールカウント
void INTCustumInterruptHandler(void){
    
    iMotorRotateCnt++;
    
}

//インタラプトハンドラのセット
void Hole_Initialize(void){
    
    EXT_INT_fallingEdgeSet();
    
    INT_SetInterruptHandler(INTCustumInterruptHandler);
    
}