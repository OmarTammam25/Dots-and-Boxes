
            }
            else if(row1==33){
                if(plyers_num==1){
                    int comp_score=player2.score;
                    redo(&g_size,g_storage,&r_size,r_storage,2*num_row-1,2*num_col-1,gridArray,&turn,&player1.score,&player2.score);
                    redo(&g_size,g_storage,&r_size