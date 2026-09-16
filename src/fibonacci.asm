li $1, 1  
li $2, 0 
li $3, 0 
li $4, 0
li $5, 1 
li $6, 10 
li $7, 0 
out $1
add $3, $1, $2 
add $2, $1, $4 
add $1, $3, $4 
add $7, $5, $7 
beq $6, $7, 1
j 6

