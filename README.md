# PP_Final_Project
### 20181223
- The detail about our MPI_datatype of ```class state```:
```
## in state class:
board before, after ;
int opcode, score ;
float esti ;

## in our MPI_datatype:
uint64_t after, before ;
int opcode, score ;
double esti ;
```
### 20181219
- Upload 300k games output file
	- 300k.out : Raw output
	- 300k_game.out : Only with gaming average (each line means an avg. of 1000games)
	- 300k_update.out : Only with updating average (each line means an avg. of 1000games)
### 20181215
- MPI_Datatype testfile test.c upload WCYu
- MPI vector&array testing pass test.cpp CHYu
	- using mpicxx to compile
- Update original 2048.cpp
	- use timer to calculate average time cost by gaming and updating network
	![](https://i.imgur.com/No4K2kg.png)
### 20181210
- MPI standard structure added WCYu

