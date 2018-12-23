#DEFINE SET_OF_GAMES 10	// just an example
#DEFINE TOTAL_GAMES_NEEDED 1000

main(){
	MPI_Init~
    tasks = total_processes;    // MPI function call
    rank = rank_of_world;   // MPI_function call
	...
	
	if( rank==0 ){	// master process
        game_count = 0;
		MPI_broadcast (init_parameter); // tdl
		do{
			MPI_recv(from x, resulting path);   // in order to update
			update_statics();
            update_global_parameter_by_recved();
			MPI_send(to x, updated_global_parameter);
            game_count++;
		}while(game_count < total_games);
	}
	
	else{	// slave process
			
        for(i=rank; i<=TOTAL_GAMES_NEEDED; i+=(tasks-1){
			if(i!=rank)
                MPI_recv( wait for master processs returning parameter );	// blocking wait as I remember
			play_one_round(with_local_parameter);
			MPI_send( send game_path to process_rank_0 );         
			else
				break;
		}
	}

}
