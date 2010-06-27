;/*****************************************************************************
;*  Copyright Statement:
;*  --------------------
;*  This software is protected by Copyright and the information contained
;*  herein is confidential. The software may not be copied and the information
;*  contained herein may not be used or disclosed except with the written
;*  permission of MediaTek Inc. (C) 2005
;*
;*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
;*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
;*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
;*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
;*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
;*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
;*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
;*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
;*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
;*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
;*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
;*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
;*
;*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
;*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
;*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
;*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
;*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
;*
;*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
;*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
;*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
;*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
;*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
;*
;*****************************************************************************/
;
;/*******************************************************************************
; *
; * Filename:
; * ---------
; *	regioninit.s
; *
; * Project:
; * --------
; *   Bootloader
; *
; * Description:
; * ------------
; *   This Module defines the initialization of RW/ZI/RO data for each area..
; *
; * Author:
; * -------
; *	Shalyn Chua (mtk00576)
; *
; *============================================================================
; *             HISTORY
; * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *------------------------------------------------------------------------------
; * $Revision$
; * $Modtime$
; * $Log$
; *------------------------------------------------------------------------------
; * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
; *============================================================================
; ****************************************************************************/

;**************************************************************
;*     File: regioninit.s                                     *
;*  Purpose: Application Startup Code                         *
;**************************************************************
;
; This file contains the macro and supporting subroutines to
; copy RO code and RW data from ROM to RAM and zero-initialize
; the ZI data areas in RAM.

;  /* Added by Anthony Chin 10/28/2001. */
 CODE32
 
        AREA RegionInit, CODE, READONLY

        EXPORT InitRegions

; This macro:
; a) copies RO code and/or RW data from ROM at Load$$area$$Base
; to RAM at Image$$area$$Base, of length Image$$area$$Length bytes.
; b) fills with zero the ZI data in RAM at Image$$area$$ZI$$Base, 
; of length Image$$area$$ZI$$Length bytes.

        MACRO
        macro_RegionInit $areaname

        LCLS   namecp
        LCLS   copyloadsym
        LCLS   copybasesym
        LCLS   copylensym
        LCLS   zibasesym
        LCLS   zilensym

namecp SETS "$areaname"

copyloadsym SETS  "|Load$$$$":CC:namecp:CC:"$$$$Base|"
copybasesym SETS  "|Image$$$$":CC:namecp:CC:"$$$$Base|"
copylensym  SETS  "|Image$$$$":CC:namecp:CC:"$$$$Length|"
zibasesym   SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Base|"
zilensym    SETS  "|Image$$$$":CC:namecp:CC:"$$$$ZI$$$$Length|"

; The following symbols are generated by the linker.  They are imported 
; WEAKly because they may not all have defined values. Those which are
; undefined will take the value zero.

        IMPORT $copyloadsym, WEAK
        IMPORT $copybasesym, WEAK
        IMPORT $copylensym, WEAK
        IMPORT $zibasesym, WEAK
        IMPORT $zilensym, WEAK


        LDR     r0, =$copyloadsym       ; load address of region
        LDR     r1, =$copybasesym       ; execution address of region
        MOV     r2, r1                  ; copy execution address into r2
        LDR     r4, =$copylensym
        ADD     r2, r2, r4              ; add region length to execution address to...
                                        ; ...calculate address of word beyond end...
                                        ; ... of execution region
        BL      copy
        
        LDR     r2, =$zilensym          ; get length of ZI region
        LDR     r0, =$zibasesym         ; load base address of ZI region
        MOV     r1, r0                  ; copy base address of ZI region into r1
        ADD     r1, r1, r2              ; add region length to base address to...
                                        ; ...calculate address of word beyond end...
                                        ; ... of ZI region
        BL      zi_init

        MEND

; InitRegions is called from boot.s to initialize the specified execution regions.
; In this example, the regions are called 32bitRAM and 16bitRAM.
; These execution region names should match those given in the scatter description file.

InitRegions
;Modified by Anthony Chin: 
; Don't save lr to sp for that sp is not initialized at this point.
; Use the temp sp.

         mov   R7,lr
         macro_RegionInit READ_WRITE
         macro_RegionInit READ_WRITE_SYS_RAM
         mov   pc,R7

; --- copy and zi_init subroutines

; copy is a subroutine which copies a region, from an address given by 
; r0 to an address given by r1. The address of the word beyond the end
; of this region is held in r2. r3 is used to hold the word being copied. 
copy
        CMP     r1, r2          ; loop whilst r1 < r2
        LDRLO   r3, [r0], #4
        STRLO   r3, [r1], #4
        BLO     copy
        MOV     pc, lr          ; return from subroutine copy

; zi_init is a subroutine which zero-initialises a region,
; starting at the address in r0. The address of the word
; beyond the end of this region is held in r1.
zi_init
        MOV     r2, #0
        CMP     r0, r1          ; loop whilst r0 < r1
        STRLO   r2, [r0], #4
        BLO     zi_init 
        MOV     pc, lr          ; return from subroutine zi_init

        END
