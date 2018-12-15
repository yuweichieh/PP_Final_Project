/***************************************************
Test passing vector and array using send & receive
***************************************************/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <vector>
// struct LUL{
// 	int a;
// 	int b;
// 	char message[20];
// 	std::vector<char> c;

// }obj;

// subset ver of set reconciliation using mpich3.2.1
int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
   // MPI_Get_processor_name(processor_name, &name_len);

	// int len[4];
	// MPI_Aint base, disps[4];
	// MPI_Datatype oldtypes[4], obj_struct, obj_type;
	// MPI_Get_address(&obj, disps);
	// MPI_Get_address(&obj.a, disps+1);
	// MPI_Get_address(&obj.b, disps+2);
	// MPI_Get_address(&obj.message[0], disps+3);
	// MPI_Get_address(&obj.c, disps+4);
	// len[0] = 1; len[1] = 1; len[2] = 20; len[3] = 2000;
	// base = disps[0];
	// disps[0] = MPI_Aint_diff(disps[0], base);
	// disps[1] = MPI_Aint_diff(disps[1], base);
	// disps[2] = MPI_Aint_diff(disps[2], base);
	// disps[3] = MPI_Aint_diff(disps[3], base);
	// oldtypes[0] = MPI_INT;
	// oldtypes[1] = MPI_INT;
	// oldtypes[2] = MPI_CHAR;
	// oldtypes[3] = MPI_CHAR;
	// MPI_Type_create_struct(4, len, disps, oldtypes, &obj_struct);
	// MPI_Type_create_resized(obj_struct, 0, sizeof(struct LUL), &obj_type);
	// MPI_Type_commit(&obj_type);
    MPI_Status status;
	// printf("2\n");
    // Get the number of processes
    // Print off a hello world message
    std::vector<char> t, tt;
	t.reserve(20);
	tt.reserve(20);
    if(world_rank==1){
    t.push_back('T') ;
t.push_back('Q');
		// struct LUL send_obj;
		// sprintf(send_obj.message, "Hello from %d", world_rank);
		 int dest=0;
		// send_obj.a = 123;
		// send_obj.b = 3333;
		// send_obj.c.push_back('F');
		//MPI_Send(c, 2000, MPI_CHAR, dest, 0,MPI_COMM_WORLD);
		MPI_Send(&t[0], 2, MPI_CHAR, dest, 0,MPI_COMM_WORLD);
    }
    else{
		//struct LUL recv_obj;
//		char *tt=new char ;
		MPI_Recv(&tt[0], 2, MPI_CHAR, 1, 0, MPI_COMM_WORLD, &status);
		//printf("recv: %d, %c\n", recv_obj.a, recv_obj.c[0]);
//		printf("recv: %c\n", tt[0]) ;
		printf("recv: %c\n", tt[1]);
    }

    // Finalize the MPI environment.
    MPI_Finalize();
    return 0;
}



