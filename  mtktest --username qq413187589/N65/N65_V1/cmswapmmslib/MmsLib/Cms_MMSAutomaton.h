/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: cmsautomation.h

    $Revision:

    $vision:       1.00

    $Date:         07/21/2002

    $Author:       hulf

	$Declare: 
	This document contains information proprietary to MobileSoft  
 Technology (Nanjing),  Corp.    Transmittal, receipt, or possession 
 of this document does not express, license, or imply any rights to 
 use, sell, design, or manufacture from this information. No reproduction, 
 publication, or disclosure of this information, in whole or in part, 
 shall be made without prior written authorization from an officer of 
 MobileSoft Technology (NanJing), Corp.

 

Abstract:

 

Modified By:

 

Environment: 

 

Revision History:

 

=====================================================================*/

#ifndef AUTOMATON_H
#define AUTOMATON_H



/************************* Constants *************************/

static const b_sourceTransition b_sourceAutomaton[] =
{
   {0, '<', 1},
   {0, '&', 22},
   {0, '*', 0},	//text buf

   {1, '/', 3},
   {1, '!', 10},
   {1, '*', 2},  //ele

   {2, '>', 0},
   {2, 'S', 8},
   {2, '*', 2},    //ele

   {3, '>', 0},
   {3, '*', 3},

   {4, '=', 5},
   {4, 'S', 17},
   {4, '>', 0},
   {4, '*', 4},  //attr

   {5, '\"',6},
   {5, '\'',9},
   {5, 'S', 5},
   {5, '>', 0},
   {5, '*', 7},   //=sssss

   {6, '\"',8},
   {6, '*', 6},//="   "

   {7, '>', 0},
   {7, 'S', 8},
   {7, '*', 7},   //=sssss

   {8, '>', 0},
   {8, '/', 8},
   {8, 'S', 8},
   {8, '*', 4},//attr

   {9, '\'',8},
   {9, '*', 9},//='   '

   {10, '-', 11},
   {10, 'S', 10},
   {10, '*', 15},

   {11, '-', 12},//<!-- -->
   {11, '*', 15},//<!     >

   {12, '-', 13},
   {12, '*', 12},

   {13, '-', 14},
   {13, '>', 0},
   {13, '*', 12},

   {14, 'S', 14},
   {14, '>', 0},
   {14, '-', 14},
   {14, '*', 12},

   {15, '>', 0},
   {15, '*', 15},
   
   {16, '*', 16},

   {17, 'S', 17},
   {17, '=', 5},
   {17, '>', 0},
   {17, '*', 4},  //attr


   {18, '*', 18},

   {19, '*', 19},

   {20, '*', 20},

   {21, '*', 21},

   {22, '<', 1},			//�����ַ�ʵ��
   {22, 'a', 23},
   {22, 'b', 26},
   {22, 'c', 27},
   {22, 'd', 33},
   {22, 'e', 34},
   {22, 'f', 35},
   {22, 'g', 36},
   {22, 'i', 37},
   {22, 'l', 40},
   {22, 'm', 42},
   {22, 'n', 45},
   {22, 'o', 48},
   {22, 'p', 49},
   {22, 'q', 53},
   {22, 'r', 54},
   {22, 's', 57},
   {22, 't', 61},
   {22, 'u', 62},
   {22, 'y', 63},
   {22, '*', 0},
   	
   {23, 'm', 24},	
   {23, 'c', 25},
      
   {24, '<', 1},		//&amp;
   {24, 'p', 24},
   {24, '*', 0},
   
   {25, '<', 1},		//&acute;
   {25, 'u', 25},	
   {25, 't', 25},
   {25, 'e', 25},
   {25, '&', 22},
   {25, '*', 0},	
      
   {26, '<', 1},		//&brvbar;  &brkbar;
   {26, 'r', 26},
   {26, 'k', 26},
   {26, 'v', 26},
   {26, 'b', 26},
   {26, 'a', 26},
   {26, 'r', 26},
   {26, '&', 22},
   {26, '*', 0},

   {27, 'e', 28},
   {27, 'o', 31},
   {27, 'u', 32},
	
   {28, 'n', 29},
   {28, 'd', 30},

   {29, '<', 1},		//&cent;
   {29, 't', 29},
   {29, '&', 22},
   {29, '*', 0},

   {30, '<', 1},		//&cedil;
   {30, 'i', 30},	
   {30, 'l', 30},
   {30, '&', 22},
   {30, '*', 0},

   {31, '<', 1},		//&copy;
   {31, 'p', 31},
   {31, 'y', 31},
   {31, '&', 22},
   {31, '*', 0},

   {32, '<', 1},		//&current;
   {32, 'r', 32},	
   {32, 'e', 32},
   {32, 'n', 32},
   {32, 't', 32},	
   {32, '&', 22},
   {32, '*', 0},

   {33, '<', 1},		//&deg;
   {33, 'e', 33},	
   {33, 'g', 33},
   {33, '&', 22},
   {33, '*', 0},
   
   {34, '<', 1},		//&emsp;  &ensp;
   {34, 'm', 34},	
   {34, 'n', 34},
   {34, 's', 34},	
   {34, 'p', 34},			
   {34, '&', 22},
   {34, '*', 0},

   {35, '<', 1},	//&frace14;  &frace12;  &frace34;
   {35, 'r', 35},
   {35, 'a', 35},
   {35, 'c', 35},
   {35, 'e', 35},
   {35, '1', 35},
   {35, '2', 35},
   {35, '3', 35},
   {35, '4', 35},	
   {35, '&', 22},
   {35, '*', 0},

   {36, '<', 1},	//&gt;
   {36, 't', 36},	
   {36, '&', 22},
   {36, '*', 0},
   	
   {37, 'e', 38},
   {37, 'q', 39},
   
   {38, '<', 1},	//&iexcl;
   {38, 'x', 38},
   {38, 'c', 38},
   {38, 'l', 38},
   {38, '&', 22},
   {38, '*', 0},
   
   {39, '<', 1},	//&iquest;
   {39, 'u', 39},
   {39, 'e', 39},
   {39, 's', 39},
   {39, 't', 39},
   {39, '&', 22},
   {39, '*', 0},

   {40, '<', 1},	//&lt;
   {40, 't', 40},
   {40, 'a', 41},
   {40, '&', 22},
   {40, '*', 0},
   
   {41, '<', 1},	//&laquo;
   {41, 'q', 41},
   {41, 'u', 41},
   {41, 'o', 41},
   {41, '&', 22},
   {41, '*', 0},
   
   {42, 'i', 42},
   {42, 'c', 43},
   {42, 'd', 44},
   
   {43, '<', 1},	//&micro;
   {43, 'r', 43},
   {43, 'o', 43},
   {43, '&', 22},
   {43, '*', 0},
   
   {44, '<', 1},	//&middot;
   {44, 'd', 44},
   {44, 'o', 44},
   {44, 't', 44},
   {44, '&', 22},
   {44, '*', 0},
   
   {45, 'b', 46},
   {45, 'o', 47},
   
   {46, '<', 1},	//&nbsp;
   {46, 's', 46},
   {46, 'p', 46},
   {46, '&', 22},
   {46, '*', 0},
   
   {47, '<', 1},	//&not;
   {47, 't', 47},
   {47, '&', 22},
   {47, '*', 0},
   
   {48, '<', 1},	//&ordf;  &ordm;
   {48, 'r', 48},
   {48, 'd', 48},
   {48, 'f', 48},
   {48, 'm', 48},
   {48, '&', 22},
   {48, '*', 0},
   
   {49, 'a', 50},
   {49, 'l', 51},
   {49, 'o', 52},
   
   {50, '<', 1},	//&para;
   {50, 'r', 50},
   {50, 'a', 50},
   {50, '&', 22},
   {50, '*', 0},
   
   {51, '<', 1},	//&plusmn;
   {51, 'u', 51},
   {51, 's', 51},
   {51, 'm', 51},
   {51, 'n', 51},
   {51, '&', 22},
   {51, '*', 0},
   
   {52, '<', 1},	//&pound;
   {52, 'u', 52},
   {52, 'n', 52},
   {52, 'd', 52},
   {52, '&', 22},
   {52, '*', 0},
   
   {53, '<', 1},	//&quot;
   {53, 'u', 53},
   {53, 'o', 53},
   {53, 't', 53},
   {53, '&', 22},
   {53, '*', 0},
   
   {54, 'a', 55},
   {54, 'e', 56},
   
   {55, '<', 1},	//&raquo;
   {55, 'q', 55},
   {55, 'u', 55},
   {55, 'o', 55},
   {55, '&', 22},
   {55, '*', 0},
   
   {56, '<', 1},	//&reg;
   {56, 'g', 56},	
   {56, '&', 22},
   {56, '*', 0},

   {57, 'e', 58},
   {57, 'h', 59},
   {57, 'u', 60},
   
   {58, '<', 1},	//&sect;
   {58, 'c', 58},
   {58, 't', 58},
   {58, '&', 22},
   {58, '*', 0},
   
   {59, '<', 1},	//&shy;
   {59, 'y', 59},
   {59, '&', 22},
   {59, '*', 0},
   
   {60, '<', 1},	//&sup1;  &sup2;  &sup3;
   {60, 'p', 60},
   {60, '1', 60},
   {60, '2', 60},
   {60, '3', 60},
   {60, '&', 22},
   {60, '*', 0},
   
   {61, '<', 1},	//&trade;
   {61, 'r', 61},
   {61, 'a', 61},
   {61, 'd', 61},
   {61, 'e', 61},
   {61, '&', 22},
   {61, '*', 0},

   {62, '<', 1},	//&uml;
   {62, 'm', 62},
   {62, 'l', 62},
   {62, '&', 22},
   {62, '*', 0},
   
   {63, '<', 1},	//&yen;
   {63, 'e', 63},
   {63, 'n', 63},
   {63, '&', 22},
   {63, '*', 0},

   {255, '*',255}
};



#endif
