#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

struct LUL{
	int a;
	int b;
	char message[20];
}obj;
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

	int len[3];
	MPI_Aint base, disps[3];
	MPI_Datatype oldtypes[3], obj_struct, obj_type;
	MPI_Get_address(&obj, disps);
	MPI_Get_address(&obj.a, disps+1);
	MPI_Get_address(&obj.b, disps+2);
	MPI_Get_address(&obj.message[0], disps+3);
	len[0] = 1; len[1] = 1; len[2] = 20;
	base = disps[0];
	disps[0] = MPI_Aint_diff(disps[0], base);
	disps[1] = MPI_Aint_diff(disps[1], base);
	disps[2] = MPI_Aint_diff(disps[2], base);
	oldtypes[0] = MPI_INT;
	oldtypes[1] = MPI_INT;
	oldtypes[2] = MPI_CHAR;
	MPI_Type_create_struct(3, len, disps, oldtypes, &obj_struct);
	MPI_Type_create_resized(obj_struct, 0, sizeof(struct LUL), &obj_type);
	MPI_Type_commit(&obj_type);
    MPI_Status status;
	printf("2\n");
    // Get the number of processes
    // Print off a hello world message
    if(world_rank==1){
	struct LUL send_obj;
	sprintf(send_obj.message, "Hello from %d", world_rank);
	int dest=0;
	send_obj.a = 123;
	send_obj.b = 3333;
	MPI_Send(&send_obj, 1, obj_type, dest, 0,MPI_COMM_WORLD);
    }
    else{
	struct LUL recv_obj;
	MPI_Recv(&recv_obj, 1, obj_type, 1, 0, MPI_COMM_WORLD, &status);
	printf("recv: %d\n", recv_obj.a);
    }

    // Finalize the MPI environment.
    MPI_Finalize();
    return 0;
}



