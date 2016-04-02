
.globl	nCr

	.type	nCr, @function
nCr:

	pushq	%rbp
	movq	%rsp, %rbp
	pushq	%rbx
	subq	$40, %rsp
	movl	%edi, -36(%rbp)
	movl	%esi, -40(%rbp)
	cmpl	$0, -40(%rbp)
	jne	.L5
	movl	$1, -24(%rbp)
	movl	-24(%rbp), %eax
	jmp	.L6
	
.L5: # calc bottom
	movl	-36(%rbp), %eax
	cmpl	-40(%rbp), %eax
	jne	.L7
	movl	$1, -24(%rbp)
	movl	-24(%rbp), %eax
	jmp	.L6
	
.L7: #calling factorial to find ncr
	movl	-40(%rbp), %eax
	leal	-1(%rax), %edx
	movl	-36(%rbp), %eax
	subl	$1, %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	nCr#Factorial
	movl	%eax, %ebx
	movl	-36(%rbp), %eax
	leal	-1(%rax), %edx
	movl	-40(%rbp), %eax
	movl	%eax, %esi
	movl	%edx, %edi
	call	nCr#Factorial
	addl	%ebx, %eax
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	
.L6:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	
	ret
	
	
.globl	Factorial
		.type	Factorial, @function
Factorial:

    
   	pushq	%rbp
	movq	%rsp, %rbp
	subq	$16, %rsp
 	movl	%edi, -4(%rbp)
 	cmpl	$1, -4(%rbp)
   	jne	.L2
 	movl	$1, %eax
	jmp	.L3
	
.L2: # Multiply n by factorial(n-1)
	movl	-4(%rbp), %eax
  	subl	$1, %eax
    movl	%eax, %edi
 	call	Factorial
	imull	-4(%rbp), %eax
	
.L3:
  	leave
    
     ret
  

