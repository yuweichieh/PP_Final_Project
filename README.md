<<<<<<< HEAD
# PP_Final_Project
## Version note:
- 1223_2048.cpp: With bug-> recv_len = 0. 
- 1224_2048.cpp: Current one that fix 1223's bug with a poor way

### 20181224
- We notice that using MPI_Send and MPI_Recv to transmit a c++ vector will cause some bugs that receiver will receive the data, but it won't put them into its vector. So the ```vector.size()``` will be ```0```, and will cause ```update_episode``` segmant fault. Hence, we use array at receiver to receive data, and ```push_back()``` to its vector to solve the problem.

### 20181223
- The detail about our MPI_datatype of ```class state```:
```
// in state class:
board before, after ;
int opcode, score ;
float esti ;

// in our MPI_datatype:
uint64_t after, before ;
int opcode, score ;
double esti ;

/*
 *We found that we need to exchange before and after, esti need to use double as well, 
 *or there will be some bugs when send & receive.
 */
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
