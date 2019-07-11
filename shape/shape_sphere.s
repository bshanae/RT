	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2
LCPI0_0:
	.long	1082130432              ## float 4
LCPI0_1:
	.long	1073741824              ## float 2
LCPI0_2:
	.long	1065353216              ## float 1
LCPI0_3:
	.long	981668463               ## float 0.00100000005
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__Z22shape_intersect_sphereP7s_shapeP14s_intersection
	.p2align	4, 0x90
__Z22shape_intersect_sphereP7s_shapeP14s_intersection: ## @_Z22shape_intersect_sphereP7s_shapeP14s_intersection
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$192, %rsp
	leaq	-72(%rbp), %rax
	movss	LCPI0_2(%rip), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	%rcx, -8(%rbp)
	movq	%rdi, -32(%rbp)
	movq	%rsi, -40(%rbp)
	movq	-32(%rbp), %rcx
	movq	%rcx, -48(%rbp)
	movq	-40(%rbp), %rcx
	addq	$12, %rcx
	movq	-48(%rbp), %rsi
	movq	%rcx, %rdi
	movss	%xmm0, -172(%rbp)       ## 4-byte Spill
	movq	%rax, -184(%rbp)        ## 8-byte Spill
	callq	__Z15vector3_sub_refPK9s_vector3S1_
	movss	%xmm1, -96(%rbp)
	movlps	%xmm0, -104(%rbp)
	movq	-104(%rbp), %rax
	movq	%rax, -88(%rbp)
	movl	-96(%rbp), %edx
	movl	%edx, -80(%rbp)
	movq	-88(%rbp), %rax
	movq	%rax, -72(%rbp)
	movl	-80(%rbp), %edx
	movl	%edx, -64(%rbp)
	movss	-172(%rbp), %xmm0       ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, -20(%rbp)
	movq	-40(%rbp), %rsi
	movq	-184(%rbp), %rdi        ## 8-byte Reload
	callq	__ZL17vector3_dot_ref_sPK9s_vector3S1_
	leaq	-72(%rbp), %rax
	movss	LCPI0_1(%rip), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movss	%xmm1, -16(%rbp)
	movq	%rax, %rdi
	movq	%rax, %rsi
	callq	__Z15vector3_dot_refPK9s_vector3S1_
	xorps	%xmm1, %xmm1
	movss	LCPI0_0(%rip), %xmm2    ## xmm2 = mem[0],zero,zero,zero
	movq	-48(%rbp), %rax
	movss	12(%rax), %xmm3         ## xmm3 = mem[0],zero,zero,zero
	movq	-48(%rbp), %rax
	mulss	12(%rax), %xmm3
	subss	%xmm3, %xmm0
	movss	%xmm0, -12(%rbp)
	movss	-16(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	mulss	-16(%rbp), %xmm0
	mulss	-20(%rbp), %xmm2
	mulss	-12(%rbp), %xmm2
	subss	%xmm2, %xmm0
	movss	%xmm0, -56(%rbp)
	cvtss2sd	-56(%rbp), %xmm0
	ucomisd	%xmm0, %xmm1
	jbe	LBB0_2
## BB#1:
	movl	$0, -24(%rbp)
	jmp	LBB0_6
LBB0_2:
	movss	LCPI0_3(%rip), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movss	LCPI0_1(%rip), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	movss	-16(%rbp), %xmm2        ## xmm2 = mem[0],zero,zero,zero
	movd	%xmm2, %eax
	xorl	$2147483648, %eax       ## imm = 0x80000000
	movd	%eax, %xmm2
	movss	-56(%rbp), %xmm3        ## xmm3 = mem[0],zero,zero,zero
	sqrtss	%xmm3, %xmm3
	subss	%xmm3, %xmm2
	divss	%xmm1, %xmm2
	movss	%xmm2, -52(%rbp)
	ucomiss	-52(%rbp), %xmm0
	jae	LBB0_4
## BB#3:
	movss	-52(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-40(%rbp), %rax
	ucomiss	24(%rax), %xmm0
	jb	LBB0_5
LBB0_4:
	movl	$0, -24(%rbp)
	jmp	LBB0_6
LBB0_5:
	movss	-52(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-40(%rbp), %rax
	movss	%xmm0, 24(%rax)
	movq	-40(%rbp), %rdi
	callq	__Z22intersection_calculateP14s_intersection
	movss	%xmm1, -128(%rbp)
	movlps	%xmm0, -136(%rbp)
	movl	-128(%rbp), %ecx
	movl	%ecx, -112(%rbp)
	movq	-136(%rbp), %rax
	movq	%rax, -120(%rbp)
	movl	-112(%rbp), %ecx
	movl	%ecx, -64(%rbp)
	movq	-120(%rbp), %rax
	movq	%rax, -72(%rbp)
	movq	-48(%rbp), %rsi
	leaq	-72(%rbp), %rdi
	callq	__Z15vector3_sub_refPK9s_vector3S1_
	movss	%xmm1, -160(%rbp)
	movlps	%xmm0, -168(%rbp)
	movq	-168(%rbp), %rax
	movq	%rax, -152(%rbp)
	movl	-160(%rbp), %ecx
	movl	%ecx, -144(%rbp)
	movq	-40(%rbp), %rax
	movq	-152(%rbp), %rsi
	movq	%rsi, 40(%rax)
	movl	-144(%rbp), %ecx
	movl	%ecx, 48(%rax)
	movq	-40(%rbp), %rax
	addq	$40, %rax
	movq	%rax, %rdi
	callq	__Z17vector3_normalizeP9s_vector3
	movq	-40(%rbp), %rax
	movq	-72(%rbp), %rsi
	movq	%rsi, 28(%rax)
	movl	-64(%rbp), %ecx
	movl	%ecx, 36(%rax)
	movq	-32(%rbp), %rax
	movq	-40(%rbp), %rsi
	movq	68(%rax), %rdi
	movq	%rdi, 52(%rsi)
	movq	76(%rax), %rdi
	movq	%rdi, 60(%rsi)
	movq	84(%rax), %rax
	movq	%rax, 68(%rsi)
	movl	$1, -24(%rbp)
LBB0_6:
	movl	-24(%rbp), %eax
	movq	___stack_chk_guard@GOTPCREL(%rip), %rcx
	movq	(%rcx), %rcx
	movq	-8(%rbp), %rdx
	cmpq	%rdx, %rcx
	movl	%eax, -188(%rbp)        ## 4-byte Spill
	jne	LBB0_8
## BB#7:
	movl	-188(%rbp), %eax        ## 4-byte Reload
	addq	$192, %rsp
	popq	%rbp
	retq
LBB0_8:
	callq	___stack_chk_fail
	.cfi_endproc

	.p2align	4, 0x90
__ZL17vector3_dot_ref_sPK9s_vector3S1_: ## @_ZL17vector3_dot_ref_sPK9s_vector3S1_
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$0, -20(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -20(%rbp)
	jge	LBB1_4
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_3
LBB1_3:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB1_1
LBB1_4:
	movq	-8(%rbp), %rax
	movss	(%rax), %xmm0           ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	mulss	(%rax), %xmm0
	movq	-8(%rbp), %rax
	movss	4(%rax), %xmm1          ## xmm1 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	mulss	4(%rax), %xmm1
	addss	%xmm1, %xmm0
	movq	-8(%rbp), %rax
	movss	8(%rax), %xmm1          ## xmm1 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	mulss	8(%rax), %xmm1
	addss	%xmm1, %xmm0
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__literal8,8byte_literals
	.p2align	3
LCPI2_0:
	.quad	4614256656552045848     ## double 3.1415926535897931
LCPI2_1:
	.quad	4607092346807469998     ## double 0.98999999999999999
	.section	__TEXT,__text,regular,pure_instructions
	.globl	__Z19shape_random_sphereP7s_shape
	.p2align	4, 0x90
__Z19shape_random_sphereP7s_shape:      ## @_Z19shape_random_sphereP7s_shape
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	subq	$112, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rdi
	movq	%rdi, -32(%rbp)
	callq	_drand48
	movsd	LCPI2_0(%rip), %xmm1    ## xmm1 = mem[0],zero
	mulsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -36(%rbp)
	movsd	%xmm1, -64(%rbp)        ## 8-byte Spill
	callq	_drand48
	addsd	%xmm0, %xmm0
	movsd	-64(%rbp), %xmm1        ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	mulsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -40(%rbp)
	movq	-32(%rbp), %rdi
	movss	12(%rdi), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	cvtss2sd	%xmm0, %xmm0
	movsd	LCPI2_1(%rip), %xmm2    ## xmm2 = mem[0],zero
	mulsd	%xmm2, %xmm0
	movss	-36(%rbp), %xmm3        ## xmm3 = mem[0],zero,zero,zero
	movsd	%xmm0, -72(%rbp)        ## 8-byte Spill
	movaps	%xmm3, %xmm0
	movsd	%xmm2, -80(%rbp)        ## 8-byte Spill
	callq	_sinf
	cvtss2sd	%xmm0, %xmm0
	movsd	-72(%rbp), %xmm1        ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	mulsd	%xmm0, %xmm1
	movss	-40(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movsd	%xmm1, -88(%rbp)        ## 8-byte Spill
	callq	_cosf
	cvtss2sd	%xmm0, %xmm0
	movsd	-88(%rbp), %xmm1        ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	mulsd	%xmm0, %xmm1
	cvtsd2ss	%xmm1, %xmm0
	movss	%xmm0, -16(%rbp)
	movq	-32(%rbp), %rdi
	movss	12(%rdi), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	cvtss2sd	%xmm0, %xmm0
	movsd	-80(%rbp), %xmm1        ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	mulsd	%xmm1, %xmm0
	movss	-36(%rbp), %xmm2        ## xmm2 = mem[0],zero,zero,zero
	movsd	%xmm0, -96(%rbp)        ## 8-byte Spill
	movaps	%xmm2, %xmm0
	callq	_sinf
	cvtss2sd	%xmm0, %xmm0
	movsd	-96(%rbp), %xmm1        ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	mulsd	%xmm0, %xmm1
	movss	-40(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movsd	%xmm1, -104(%rbp)       ## 8-byte Spill
	callq	_sinf
	cvtss2sd	%xmm0, %xmm0
	movsd	-104(%rbp), %xmm1       ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	mulsd	%xmm0, %xmm1
	cvtsd2ss	%xmm1, %xmm0
	movss	%xmm0, -12(%rbp)
	movq	-32(%rbp), %rdi
	movss	12(%rdi), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	cvtss2sd	%xmm0, %xmm0
	movsd	-80(%rbp), %xmm1        ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	mulsd	%xmm1, %xmm0
	movss	-36(%rbp), %xmm2        ## xmm2 = mem[0],zero,zero,zero
	movsd	%xmm0, -112(%rbp)       ## 8-byte Spill
	movaps	%xmm2, %xmm0
	callq	_cosf
	cvtss2sd	%xmm0, %xmm0
	movsd	-112(%rbp), %xmm1       ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	mulsd	%xmm0, %xmm1
	cvtsd2ss	%xmm1, %xmm0
	movss	%xmm0, -8(%rbp)
	movq	-32(%rbp), %rsi
	leaq	-16(%rbp), %rdi
	callq	__Z18vector3_add_eq_refP9s_vector3PKS_
	movl	-8(%rbp), %eax
	movl	%eax, -48(%rbp)
	movq	-16(%rbp), %rsi
	movq	%rsi, -56(%rbp)
	movq	-56(%rbp), %xmm0        ## xmm0 = mem[0],zero
	movss	-48(%rbp), %xmm1        ## xmm1 = mem[0],zero,zero,zero
	addq	$112, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Z12shape_sphere9s_vector3f10s_material
	.p2align	4, 0x90
__Z12shape_sphere9s_vector3f10s_material: ## @_Z12shape_sphere9s_vector3f10s_material
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi9:
	.cfi_def_cfa_offset 16
Lcfi10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi11:
	.cfi_def_cfa_register %rbp
	movq	%rdi, %rax
	leaq	16(%rbp), %rcx
	movlps	%xmm0, -32(%rbp)
	movss	%xmm1, -24(%rbp)
	movq	-32(%rbp), %rdx
	movq	%rdx, -16(%rbp)
	movl	-24(%rbp), %esi
	movl	%esi, -8(%rbp)
	movss	%xmm2, -36(%rbp)
	movq	%rdi, %rdx
	movq	%rdx, -48(%rbp)
	movss	-36(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-48(%rbp), %rdx
	movss	%xmm0, 12(%rdx)
	movq	-48(%rbp), %rdx
	movq	-16(%rbp), %r8
	movq	%r8, (%rdx)
	movl	-8(%rbp), %esi
	movl	%esi, 8(%rdx)
	movl	$0, 64(%rdi)
	movq	(%rcx), %rdx
	movq	%rdx, 68(%rdi)
	movq	8(%rcx), %rdx
	movq	%rdx, 76(%rdi)
	movq	16(%rcx), %rcx
	movq	%rcx, 84(%rdi)
	popq	%rbp
	retq
	.cfi_endproc


.subsections_via_symbols
