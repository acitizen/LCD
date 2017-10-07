
void setSegments(){
  int count = 0; 
  boolean d1[3][9] = {0};
  boolean d2[3][9] = {0};
  boolean d3[3][9] = {0};
  boolean d4[3][9] = {0};

//-------------------------------digit 1

    count = 0;
    for(int j=0; j < 3; ++j){
      for(int i = 0; i < 9; ++i){
       
         if (digits[0] == 0) d1[j][i]  = d1_0[count];
         if (digits[0] == 1) d1[j][i]  = d1_1[count];
         if (digits[0] == 2) d1[j][i]  = d1_2[count];
         ++count;
      }      
    }
//-------------------------------digit 2

    count = 0;
    for(int j=0; j <3; ++j){
      for(int i = 0; i < 9; ++i){
        if (digits[1] == 0) d2[j][i] = d2_0[count];
        if (digits[1] == 1) d2[j][i] = d2_1[count];
        if (digits[1] == 2) d2[j][i] = d2_2[count];
        if (digits[1] == 3) d2[j][i] = d2_3[count];
        if (digits[1] == 4) d2[j][i] = d2_4[count];
        if (digits[1] == 5) d2[j][i] = d2_5[count];
        if (digits[1] == 6) d2[j][i] = d2_6[count];
        if (digits[1] == 7) d2[j][i] = d2_7[count];
        if (digits[1] == 8) d2[j][i] = d2_8[count];
        if (digits[1] == 9) d2[j][i] = d2_9[count];
        count++;
      }     
    }
//------------------------------- digits 3
    count = 0;
    for(int j= 0; j <3; ++j){
      for(int i = 0; i < 9; ++i){
        if (digits[2] ==  0) d3[j][i]  = d3_0[count];
        if (digits[2] ==  1) d3[j][i]  = d3_1[count];
        if (digits[2] ==  2) d3[j][i]  = d3_2[count];
        if (digits[2] ==  3) d3[j][i]  = d3_3[count];
        if (digits[2] ==  4) d3[j][i]  = d3_4[count];
        if (digits[2] ==  5) d3[j][i]  = d3_5[count];
        count++;
      }
     }
//------------------------------- digits 4

    count = 0;
    for(int j= 0; j <3; ++j){
      for(int i = 0; i < 9; ++i){
        if (digits[3] ==  0) d4[j][i] = d4_0[count];
        if (digits[3] ==  1) d4[j][i] = d4_1[count];
        if (digits[3] ==  2) d4[j][i] = d4_2[count];
        if (digits[3] ==  3) d4[j][i] = d4_3[count];
        if (digits[3] ==  4) d4[j][i] = d4_4[count];
        if (digits[3] ==  5) d4[j][i] = d4_5[count];
        if (digits[3] ==  6) d4[j][i] = d4_6[count];
        if (digits[3] ==  7) d4[j][i] = d4_7[count];
        if (digits[3] ==  8) d4[j][i] = d4_8[count];
        if (digits[3] ==  9) d4[j][i] = d4_9[count];
        count++;
      }
    }
//------------------------------- merge digit data      
  for (int j = 0; j < 3; ++j){
      for (int i = 0; i < 9; ++i){
        if(d1[j][i]|| d2[j][i]|| d3[j][i]|| d4[j][i])
            segments[j][i] = 1;
           else 
            segments[j][i] = 0;
       }
  }
}

//------------------------------- TURN OFF ALL DIGITS
void setSegmentsBlank(){
  for (int j = 0; j < 3; ++j){
      for (int i = 0; i < 9; ++i){
            segments[j][i] = 0;
           }
      }
      segments[0][4] = 1;
}

  
