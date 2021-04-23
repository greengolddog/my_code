	.file	"tg23.cpp"
	.text
	.section	.text._ZSt3absd,"axG",@progbits,_ZSt3absd,comdat
	.weak	_ZSt3absd
	.type	_ZSt3absd, @function
_ZSt3absd:
.LFB26:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	movq	.LC0(%rip), %xmm1
	andpd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE26:
	.size	_ZSt3absd, .-_ZSt3absd
	.section	.text._ZSt5isnand,"axG",@progbits,_ZSt5isnand,comdat
	.weak	_ZSt5isnand
	.type	_ZSt5isnand, @function
_ZSt5isnand:
.LFB109:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	ucomisd	-8(%rbp), %xmm0
	setp	%al
	movzbl	%al, %eax
	testl	%eax, %eax
	setne	%al
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE109:
	.size	_ZSt5isnand, .-_ZSt5isnand
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.type	_ZStL13allocator_arg, @object
	.size	_ZStL13allocator_arg, 1
_ZStL13allocator_arg:
	.zero	1
	.type	_ZStL6ignore, @object
	.size	_ZStL6ignore, 1
_ZStL6ignore:
	.zero	1
	.section	.text._ZSt12setprecisioni,"axG",@progbits,_ZSt12setprecisioni,comdat
	.weak	_ZSt12setprecisioni
	.type	_ZSt12setprecisioni, @function
_ZSt12setprecisioni:
.LFB3625:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3625:
	.size	_ZSt12setprecisioni, .-_ZSt12setprecisioni
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata
	.align 4
	.type	_ZN9__gnu_cxxL21__default_lock_policyE, @object
	.size	_ZN9__gnu_cxxL21__default_lock_policyE, 4
_ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
	.type	_ZStL10defer_lock, @object
	.size	_ZStL10defer_lock, 1
_ZStL10defer_lock:
	.zero	1
	.type	_ZStL11try_to_lock, @object
	.size	_ZStL11try_to_lock, 1
_ZStL11try_to_lock:
	.zero	1
	.type	_ZStL10adopt_lock, @object
	.size	_ZStL10adopt_lock, 1
_ZStL10adopt_lock:
	.zero	1
	.align 4
	.type	_ZNSt15regex_constantsL5icaseE, @object
	.size	_ZNSt15regex_constantsL5icaseE, 4
_ZNSt15regex_constantsL5icaseE:
	.long	1
	.align 4
	.type	_ZNSt15regex_constantsL6nosubsE, @object
	.size	_ZNSt15regex_constantsL6nosubsE, 4
_ZNSt15regex_constantsL6nosubsE:
	.long	2
	.align 4
	.type	_ZNSt15regex_constantsL8optimizeE, @object
	.size	_ZNSt15regex_constantsL8optimizeE, 4
_ZNSt15regex_constantsL8optimizeE:
	.long	4
	.align 4
	.type	_ZNSt15regex_constantsL7collateE, @object
	.size	_ZNSt15regex_constantsL7collateE, 4
_ZNSt15regex_constantsL7collateE:
	.long	8
	.align 4
	.type	_ZNSt15regex_constantsL10ECMAScriptE, @object
	.size	_ZNSt15regex_constantsL10ECMAScriptE, 4
_ZNSt15regex_constantsL10ECMAScriptE:
	.long	16
	.align 4
	.type	_ZNSt15regex_constantsL5basicE, @object
	.size	_ZNSt15regex_constantsL5basicE, 4
_ZNSt15regex_constantsL5basicE:
	.long	32
	.align 4
	.type	_ZNSt15regex_constantsL8extendedE, @object
	.size	_ZNSt15regex_constantsL8extendedE, 4
_ZNSt15regex_constantsL8extendedE:
	.long	64
	.align 4
	.type	_ZNSt15regex_constantsL3awkE, @object
	.size	_ZNSt15regex_constantsL3awkE, 4
_ZNSt15regex_constantsL3awkE:
	.long	128
	.align 4
	.type	_ZNSt15regex_constantsL4grepE, @object
	.size	_ZNSt15regex_constantsL4grepE, 4
_ZNSt15regex_constantsL4grepE:
	.long	256
	.align 4
	.type	_ZNSt15regex_constantsL5egrepE, @object
	.size	_ZNSt15regex_constantsL5egrepE, 4
_ZNSt15regex_constantsL5egrepE:
	.long	512
	.align 4
	.type	_ZNSt15regex_constantsL12__polynomialE, @object
	.size	_ZNSt15regex_constantsL12__polynomialE, 4
_ZNSt15regex_constantsL12__polynomialE:
	.long	1024
	.align 4
	.type	_ZNSt15regex_constantsL13match_defaultE, @object
	.size	_ZNSt15regex_constantsL13match_defaultE, 4
_ZNSt15regex_constantsL13match_defaultE:
	.zero	4
	.align 4
	.type	_ZNSt15regex_constantsL13match_not_bolE, @object
	.size	_ZNSt15regex_constantsL13match_not_bolE, 4
_ZNSt15regex_constantsL13match_not_bolE:
	.long	1
	.align 4
	.type	_ZNSt15regex_constantsL13match_not_eolE, @object
	.size	_ZNSt15regex_constantsL13match_not_eolE, 4
_ZNSt15regex_constantsL13match_not_eolE:
	.long	2
	.align 4
	.type	_ZNSt15regex_constantsL13match_not_bowE, @object
	.size	_ZNSt15regex_constantsL13match_not_bowE, 4
_ZNSt15regex_constantsL13match_not_bowE:
	.long	4
	.align 4
	.type	_ZNSt15regex_constantsL13match_not_eowE, @object
	.size	_ZNSt15regex_constantsL13match_not_eowE, 4
_ZNSt15regex_constantsL13match_not_eowE:
	.long	8
	.align 4
	.type	_ZNSt15regex_constantsL9match_anyE, @object
	.size	_ZNSt15regex_constantsL9match_anyE, 4
_ZNSt15regex_constantsL9match_anyE:
	.long	16
	.align 4
	.type	_ZNSt15regex_constantsL14match_not_nullE, @object
	.size	_ZNSt15regex_constantsL14match_not_nullE, 4
_ZNSt15regex_constantsL14match_not_nullE:
	.long	32
	.align 4
	.type	_ZNSt15regex_constantsL16match_continuousE, @object
	.size	_ZNSt15regex_constantsL16match_continuousE, 4
_ZNSt15regex_constantsL16match_continuousE:
	.long	64
	.align 4
	.type	_ZNSt15regex_constantsL16match_prev_availE, @object
	.size	_ZNSt15regex_constantsL16match_prev_availE, 4
_ZNSt15regex_constantsL16match_prev_availE:
	.long	128
	.align 4
	.type	_ZNSt15regex_constantsL14format_defaultE, @object
	.size	_ZNSt15regex_constantsL14format_defaultE, 4
_ZNSt15regex_constantsL14format_defaultE:
	.zero	4
	.align 4
	.type	_ZNSt15regex_constantsL10format_sedE, @object
	.size	_ZNSt15regex_constantsL10format_sedE, 4
_ZNSt15regex_constantsL10format_sedE:
	.long	256
	.align 4
	.type	_ZNSt15regex_constantsL14format_no_copyE, @object
	.size	_ZNSt15regex_constantsL14format_no_copyE, 4
_ZNSt15regex_constantsL14format_no_copyE:
	.long	512
	.align 4
	.type	_ZNSt15regex_constantsL17format_first_onlyE, @object
	.size	_ZNSt15regex_constantsL17format_first_onlyE, 4
_ZNSt15regex_constantsL17format_first_onlyE:
	.long	1024
	.align 4
	.type	_ZNSt15regex_constantsL13error_collateE, @object
	.size	_ZNSt15regex_constantsL13error_collateE, 4
_ZNSt15regex_constantsL13error_collateE:
	.zero	4
	.align 4
	.type	_ZNSt15regex_constantsL11error_ctypeE, @object
	.size	_ZNSt15regex_constantsL11error_ctypeE, 4
_ZNSt15regex_constantsL11error_ctypeE:
	.long	1
	.align 4
	.type	_ZNSt15regex_constantsL12error_escapeE, @object
	.size	_ZNSt15regex_constantsL12error_escapeE, 4
_ZNSt15regex_constantsL12error_escapeE:
	.long	2
	.align 4
	.type	_ZNSt15regex_constantsL13error_backrefE, @object
	.size	_ZNSt15regex_constantsL13error_backrefE, 4
_ZNSt15regex_constantsL13error_backrefE:
	.long	3
	.align 4
	.type	_ZNSt15regex_constantsL11error_brackE, @object
	.size	_ZNSt15regex_constantsL11error_brackE, 4
_ZNSt15regex_constantsL11error_brackE:
	.long	4
	.align 4
	.type	_ZNSt15regex_constantsL11error_parenE, @object
	.size	_ZNSt15regex_constantsL11error_parenE, 4
_ZNSt15regex_constantsL11error_parenE:
	.long	5
	.align 4
	.type	_ZNSt15regex_constantsL11error_braceE, @object
	.size	_ZNSt15regex_constantsL11error_braceE, 4
_ZNSt15regex_constantsL11error_braceE:
	.long	6
	.align 4
	.type	_ZNSt15regex_constantsL14error_badbraceE, @object
	.size	_ZNSt15regex_constantsL14error_badbraceE, 4
_ZNSt15regex_constantsL14error_badbraceE:
	.long	7
	.align 4
	.type	_ZNSt15regex_constantsL11error_rangeE, @object
	.size	_ZNSt15regex_constantsL11error_rangeE, 4
_ZNSt15regex_constantsL11error_rangeE:
	.long	8
	.align 4
	.type	_ZNSt15regex_constantsL11error_spaceE, @object
	.size	_ZNSt15regex_constantsL11error_spaceE, 4
_ZNSt15regex_constantsL11error_spaceE:
	.long	9
	.align 4
	.type	_ZNSt15regex_constantsL15error_badrepeatE, @object
	.size	_ZNSt15regex_constantsL15error_badrepeatE, 4
_ZNSt15regex_constantsL15error_badrepeatE:
	.long	10
	.align 4
	.type	_ZNSt15regex_constantsL16error_complexityE, @object
	.size	_ZNSt15regex_constantsL16error_complexityE, 4
_ZNSt15regex_constantsL16error_complexityE:
	.long	11
	.align 4
	.type	_ZNSt15regex_constantsL11error_stackE, @object
	.size	_ZNSt15regex_constantsL11error_stackE, 4
_ZNSt15regex_constantsL11error_stackE:
	.long	12
	.align 8
	.type	_ZNSt8__detailL19_S_invalid_state_idE, @object
	.size	_ZNSt8__detailL19_S_invalid_state_idE, 8
_ZNSt8__detailL19_S_invalid_state_idE:
	.quad	-1
	.local	_ZL4nan2
	.comm	_ZL4nan2,8,8
	.align 8
	.type	_ZL2pi, @object
	.size	_ZL2pi, 8
_ZL2pi:
	.long	1413754136
	.long	1074340347
	.text
	.globl	_Z3roud
	.type	_Z3roud, @function
_Z3roud:
.LFB8383:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm1
	movsd	.LC1(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, %xmm0
	call	round@PLT
	movq	%xmm0, %rax
	movsd	.LC1(%rip), %xmm0
	movq	%rax, %xmm1
	divsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8383:
	.size	_Z3roud, .-_Z3roud
	.globl	_Z6to_radd
	.type	_Z6to_radd, @function
_Z6to_radd:
.LFB8384:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm1
	movsd	.LC2(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8384:
	.size	_Z6to_radd, .-_Z6to_radd
	.globl	_Z8from_radd
	.type	_Z8from_radd, @function
_Z8from_radd:
.LFB8385:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm1
	movsd	.LC3(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8385:
	.size	_Z8from_radd, .-_Z8from_radd
	.section	.text._ZN5pointC2Edd,"axG",@progbits,_ZN5pointC5Edd,comdat
	.align 2
	.weak	_ZN5pointC2Edd
	.type	_ZN5pointC2Edd, @function
_ZN5pointC2Edd:
.LFB8387:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movq	-8(%rbp), %rax
	movsd	-16(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movq	-8(%rbp), %rax
	movsd	-24(%rbp), %xmm0
	movsd	%xmm0, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8387:
	.size	_ZN5pointC2Edd, .-_ZN5pointC2Edd
	.weak	_ZN5pointC1Edd
	.set	_ZN5pointC1Edd,_ZN5pointC2Edd
	.section	.text._ZN5pointmiES_,"axG",@progbits,_ZN5pointmiES_,comdat
	.align 2
	.weak	_ZN5pointmiES_
	.type	_ZN5pointmiES_, @function
_ZN5pointmiES_:
.LFB8389:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, -80(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rax
	movsd	8(%rax), %xmm0
	movsd	-72(%rbp), %xmm1
	movapd	%xmm0, %xmm2
	subsd	%xmm1, %xmm2
	movq	-56(%rbp), %rax
	movsd	(%rax), %xmm0
	movsd	-80(%rbp), %xmm1
	subsd	%xmm1, %xmm0
	movq	%xmm0, %rdx
	leaq	-48(%rbp), %rax
	movapd	%xmm2, %xmm1
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rax
	movq	%rbx, %xmm1
	movq	-24(%rbp), %rbx
	subq	%fs:40, %rbx
	je	.L16
	call	__stack_chk_fail@PLT
.L16:
	movq	%rax, %xmm0
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8389:
	.size	_ZN5pointmiES_, .-_ZN5pointmiES_
	.section	.text._ZN5pointeqES_,"axG",@progbits,_ZN5pointeqES_,comdat
	.align 2
	.weak	_ZN5pointeqES_
	.type	_ZN5pointeqES_, @function
_ZN5pointeqES_:
.LFB8390:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %xmm0
	call	_Z3roud
	movq	%xmm0, %rbx
	movq	-48(%rbp), %rax
	movq	%rax, %xmm0
	call	_Z3roud
	movq	%rbx, %xmm2
	ucomisd	%xmm0, %xmm2
	jp	.L18
	movq	%rbx, %xmm3
	ucomisd	%xmm0, %xmm3
	jne	.L18
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, %xmm0
	call	_Z3roud
	movq	%xmm0, %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %xmm0
	call	_Z3roud
	movq	%rbx, %xmm4
	ucomisd	%xmm0, %xmm4
	jp	.L18
	movq	%rbx, %xmm5
	ucomisd	%xmm0, %xmm5
	jne	.L18
	movl	$1, %eax
	jmp	.L21
.L18:
	movl	$0, %eax
.L21:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8390:
	.size	_ZN5pointeqES_, .-_ZN5pointeqES_
	.section	.text._ZN5point2toEd,"axG",@progbits,_ZN5point2toEd,comdat
	.align 2
	.weak	_ZN5point2toEd
	.type	_ZN5point2toEd, @function
_ZN5point2toEd:
.LFB8392:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movsd	%xmm0, -64(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN5pointcoEv
	movq	%xmm0, %rax
	movq	-56(%rbp), %rdx
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	_ZN5pointdvEd
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	movq	-64(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointmlEd
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rax
	movq	%rbx, %xmm1
	movq	-24(%rbp), %rbx
	subq	%fs:40, %rbx
	je	.L27
	call	__stack_chk_fail@PLT
.L27:
	movq	%rax, %xmm0
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8392:
	.size	_ZN5point2toEd, .-_ZN5point2toEd
	.section	.text._ZN5pointmlEd,"axG",@progbits,_ZN5pointmlEd,comdat
	.align 2
	.weak	_ZN5pointmlEd
	.type	_ZN5pointmlEd, @function
_ZN5pointmlEd:
.LFB8393:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movsd	%xmm0, -64(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rax
	movsd	8(%rax), %xmm0
	movapd	%xmm0, %xmm1
	mulsd	-64(%rbp), %xmm1
	movq	-56(%rbp), %rax
	movsd	(%rax), %xmm0
	mulsd	-64(%rbp), %xmm0
	movq	%xmm0, %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rax
	movq	%rbx, %xmm1
	movq	-24(%rbp), %rbx
	subq	%fs:40, %rbx
	je	.L30
	call	__stack_chk_fail@PLT
.L30:
	movq	%rax, %xmm0
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8393:
	.size	_ZN5pointmlEd, .-_ZN5pointmlEd
	.section	.text._ZN5pointplES_,"axG",@progbits,_ZN5pointplES_,comdat
	.align 2
	.weak	_ZN5pointplES_
	.type	_ZN5pointplES_, @function
_ZN5pointplES_:
.LFB8394:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, -80(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movsd	-72(%rbp), %xmm1
	movq	-56(%rbp), %rax
	movsd	8(%rax), %xmm0
	movapd	%xmm1, %xmm2
	addsd	%xmm0, %xmm2
	movsd	-80(%rbp), %xmm1
	movq	-56(%rbp), %rax
	movsd	(%rax), %xmm0
	addsd	%xmm0, %xmm1
	movq	%xmm1, %rdx
	leaq	-48(%rbp), %rax
	movapd	%xmm2, %xmm1
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rax
	movq	%rbx, %xmm1
	movq	-24(%rbp), %rbx
	subq	%fs:40, %rbx
	je	.L33
	call	__stack_chk_fail@PLT
.L33:
	movq	%rax, %xmm0
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8394:
	.size	_ZN5pointplES_, .-_ZN5pointplES_
	.section	.text._ZN5pointdvEd,"axG",@progbits,_ZN5pointdvEd,comdat
	.align 2
	.weak	_ZN5pointdvEd
	.type	_ZN5pointdvEd, @function
_ZN5pointdvEd:
.LFB8395:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movsd	%xmm0, -64(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-56(%rbp), %rax
	movsd	8(%rax), %xmm0
	movapd	%xmm0, %xmm1
	divsd	-64(%rbp), %xmm1
	movq	-56(%rbp), %rax
	movsd	(%rax), %xmm0
	divsd	-64(%rbp), %xmm0
	movq	%xmm0, %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rax
	movq	%rbx, %xmm1
	movq	-24(%rbp), %rbx
	subq	%fs:40, %rbx
	je	.L36
	call	__stack_chk_fail@PLT
.L36:
	movq	%rax, %xmm0
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8395:
	.size	_ZN5pointdvEd, .-_ZN5pointdvEd
	.section	.text._ZN5pointcoEv,"axG",@progbits,_ZN5pointcoEv,comdat
	.align 2
	.weak	_ZN5pointcoEv
	.type	_ZN5pointcoEv, @function
_ZN5pointcoEv:
.LFB8396:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm1
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm0
	mulsd	%xmm0, %xmm1
	movq	-8(%rbp), %rax
	movsd	8(%rax), %xmm2
	movq	-8(%rbp), %rax
	movsd	8(%rax), %xmm0
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, %xmm0
	call	sqrt@PLT
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8396:
	.size	_ZN5pointcoEv, .-_ZN5pointcoEv
	.text
	.globl	_ZlsRSo5point
	.type	_ZlsRSo5point, @function
_ZlsRSo5point:
.LFB8399:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movl	$20, %edi
	call	_ZSt12setprecisioni
	movl	%eax, %edx
	movq	-24(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St13_Setprecision@PLT
	movq	%rax, %rdx
	movq	-48(%rbp), %rax
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movl	$32, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c@PLT
	movq	%rax, %rbx
	movl	$20, %edi
	call	_ZSt12setprecisioni
	movl	%eax, %esi
	movq	%rbx, %rdi
	call	_ZStlsIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_St13_Setprecision@PLT
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8399:
	.size	_ZlsRSo5point, .-_ZlsRSo5point
	.globl	_ZrsRSiR5point
	.type	_ZrsRSiR5point, @function
_ZrsRSiR5point:
.LFB8400:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSirsERd@PLT
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSirsERd@PLT
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8400:
	.size	_ZrsRSiR5point, .-_ZrsRSiR5point
	.section	.text._ZN3vctC2E5pointS0_,"axG",@progbits,_ZN3vctC5E5pointS0_,comdat
	.align 2
	.weak	_ZN3vctC2E5pointS0_
	.type	_ZN3vctC2E5pointS0_, @function
_ZN3vctC2E5pointS0_:
.LFB8402:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movapd	%xmm2, %xmm1
	movapd	%xmm3, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%xmm1, %rax
	movq	%xmm0, %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-24(%rbp), %rax
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movq	-24(%rbp), %rbx
	movq	-64(%rbp), %rdx
	movsd	-56(%rbp), %xmm1
	leaq	-48(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointmiES_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, (%rbx)
	movsd	%xmm0, 8(%rbx)
	nop
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8402:
	.size	_ZN3vctC2E5pointS0_, .-_ZN3vctC2E5pointS0_
	.weak	_ZN3vctC1E5pointS0_
	.set	_ZN3vctC1E5pointS0_,_ZN3vctC2E5pointS0_
	.section	.text._ZN3vct3revEv,"axG",@progbits,_ZN3vct3revEv,comdat
	.align 2
	.weak	_ZN3vct3revEv
	.type	_ZN3vct3revEv, @function
_ZN3vct3revEv:
.LFB8404:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -88(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movq	-88(%rbp), %rax
	movsd	8(%rax), %xmm0
	movq	.LC5(%rip), %xmm1
	movapd	%xmm0, %xmm2
	xorpd	%xmm1, %xmm2
	movq	-88(%rbp), %rax
	movsd	(%rax), %xmm0
	movq	.LC5(%rip), %xmm1
	xorpd	%xmm1, %xmm0
	movq	%xmm0, %rdx
	leaq	-80(%rbp), %rax
	movapd	%xmm2, %xmm1
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movsd	-64(%rbp), %xmm2
	movsd	-56(%rbp), %xmm0
	movq	-80(%rbp), %rdx
	movsd	-72(%rbp), %xmm1
	leaq	-48(%rbp), %rax
	movapd	%xmm0, %xmm3
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN3vctC1E5pointS0_
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rax
	movq	%rbx, %xmm1
	movq	-24(%rbp), %rbx
	subq	%fs:40, %rbx
	je	.L46
	call	__stack_chk_fail@PLT
.L46:
	movq	%rax, %xmm0
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8404:
	.size	_ZN3vct3revEv, .-_ZN3vct3revEv
	.section	.text._ZN3vctplEd,"axG",@progbits,_ZN3vctplEd,comdat
	.align 2
	.weak	_ZN3vctplEd
	.type	_ZN3vctplEd, @function
_ZN3vctplEd:
.LFB8408:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$120, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -88(%rbp)
	movsd	%xmm0, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movq	-88(%rbp), %rax
	movsd	(%rax), %xmm7
	movsd	%xmm7, -104(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %xmm0
	call	sin@PLT
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	_Z3roud
	mulsd	-104(%rbp), %xmm0
	movsd	%xmm0, -104(%rbp)
	movq	-88(%rbp), %rax
	movsd	8(%rax), %xmm3
	movsd	%xmm3, -112(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %xmm0
	call	cos@PLT
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	_Z3roud
	mulsd	-112(%rbp), %xmm0
	movapd	%xmm0, %xmm6
	addsd	-104(%rbp), %xmm6
	movsd	%xmm6, -104(%rbp)
	movq	-88(%rbp), %rax
	movsd	(%rax), %xmm5
	movsd	%xmm5, -112(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %xmm0
	call	cos@PLT
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	_Z3roud
	mulsd	-112(%rbp), %xmm0
	movsd	%xmm0, -112(%rbp)
	movq	-88(%rbp), %rax
	movsd	8(%rax), %xmm2
	movsd	%xmm2, -120(%rbp)
	movq	-96(%rbp), %rax
	movq	%rax, %xmm0
	call	sin@PLT
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	_Z3roud
	mulsd	-120(%rbp), %xmm0
	movsd	-112(%rbp), %xmm4
	subsd	%xmm0, %xmm4
	movq	%xmm4, %rdx
	leaq	-80(%rbp), %rax
	movsd	-104(%rbp), %xmm1
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movsd	-64(%rbp), %xmm2
	movsd	-56(%rbp), %xmm0
	movq	-80(%rbp), %rdx
	movsd	-72(%rbp), %xmm1
	leaq	-48(%rbp), %rax
	movapd	%xmm0, %xmm3
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN3vctC1E5pointS0_
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rax
	movq	%rbx, %xmm1
	movq	-24(%rbp), %rbx
	subq	%fs:40, %rbx
	je	.L49
	call	__stack_chk_fail@PLT
.L49:
	movq	%rax, %xmm0
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8408:
	.size	_ZN3vctplEd, .-_ZN3vctplEd
	.section	.text._ZN3vct8to_pointEv,"axG",@progbits,_ZN3vct8to_pointEv,comdat
	.align 2
	.weak	_ZN3vct8to_pointEv
	.type	_ZN3vct8to_pointEv, @function
_ZN3vct8to_pointEv:
.LFB8415:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	.cfi_offset 3, -24
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rax
	movq	%rbx, %xmm1
	movq	%rax, %xmm0
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8415:
	.size	_ZN3vct8to_pointEv, .-_ZN3vct8to_pointEv
	.section	.text._ZN3vct2toEd,"axG",@progbits,_ZN3vct2toEd,comdat
	.align 2
	.weak	_ZN3vct2toEd
	.type	_ZN3vct2toEd, @function
_ZN3vct2toEd:
.LFB8416:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movsd	%xmm0, -80(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movq	-72(%rbp), %rax
	movq	-80(%rbp), %rdx
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5point2toEd
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movsd	-64(%rbp), %xmm1
	movsd	-56(%rbp), %xmm0
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rdx
	movq	%rbx, %xmm4
	leaq	-48(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm3
	movq	%rdx, %xmm0
	movapd	%xmm4, %xmm1
	movq	%rax, %rdi
	call	_ZN3vctC1E5pointS0_
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rax
	movq	%rbx, %xmm1
	movq	-24(%rbp), %rbx
	subq	%fs:40, %rbx
	je	.L54
	call	__stack_chk_fail@PLT
.L54:
	movq	%rax, %xmm0
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8416:
	.size	_ZN3vct2toEd, .-_ZN3vct2toEd
	.text
	.globl	_ZrsRSiR3vct
	.type	_ZrsRSiR3vct, @function
_ZrsRSiR3vct:
.LFB8418:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZrsRSiR5point
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8418:
	.size	_ZrsRSiR3vct, .-_ZrsRSiR3vct
	.globl	_ZrsRSiR7segment
	.type	_ZrsRSiR7segment, @function
_ZrsRSiR7segment:
.LFB8429:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZrsRSiR5point
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZrsRSiR5point
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8429:
	.size	_ZrsRSiR7segment, .-_ZrsRSiR7segment
	.section	.text._ZN4lineC2Eddd,"axG",@progbits,_ZN4lineC5Eddd,comdat
	.align 2
	.weak	_ZN4lineC2Eddd
	.type	_ZN4lineC2Eddd, @function
_ZN4lineC2Eddd:
.LFB8436:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movsd	%xmm0, -16(%rbp)
	movsd	%xmm1, -24(%rbp)
	movsd	%xmm2, -32(%rbp)
	movq	-8(%rbp), %rax
	movsd	-16(%rbp), %xmm0
	movsd	%xmm0, (%rax)
	movq	-8(%rbp), %rax
	movsd	-24(%rbp), %xmm0
	movsd	%xmm0, 8(%rax)
	movq	-8(%rbp), %rax
	movsd	-32(%rbp), %xmm0
	movsd	%xmm0, 16(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8436:
	.size	_ZN4lineC2Eddd, .-_ZN4lineC2Eddd
	.weak	_ZN4lineC1Eddd
	.set	_ZN4lineC1Eddd,_ZN4lineC2Eddd
	.section	.text._ZN4line4normEv,"axG",@progbits,_ZN4line4normEv,comdat
	.align 2
	.weak	_ZN4line4normEv
	.type	_ZN4line4normEv, @function
_ZN4line4normEv:
.LFB8443:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -88(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-64(%rbp), %rax
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movq	-88(%rbp), %rax
	movsd	8(%rax), %xmm0
	movq	-88(%rbp), %rax
	movq	(%rax), %rdx
	leaq	-80(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movsd	-64(%rbp), %xmm2
	movsd	-56(%rbp), %xmm0
	movq	-80(%rbp), %rdx
	movsd	-72(%rbp), %xmm1
	leaq	-48(%rbp), %rax
	movapd	%xmm0, %xmm3
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN3vctC1E5pointS0_
	movq	.LC6(%rip), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN3vct2toEd
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rax
	movq	%rbx, %xmm1
	movq	-24(%rbp), %rbx
	subq	%fs:40, %rbx
	je	.L62
	call	__stack_chk_fail@PLT
.L62:
	movq	%rax, %xmm0
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8443:
	.size	_ZN4line4normEv, .-_ZN4line4normEv
	.section	.text._ZN4line7projectE5point,"axG",@progbits,_ZN4line7projectE5point,comdat
	.align 2
	.weak	_ZN4line7projectE5point
	.type	_ZN4line7projectE5point, @function
_ZN4line7projectE5point:
.LFB8445:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$104, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -88(%rbp)
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, -112(%rbp)
	movq	%rdx, -104(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4line4normEv
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -64(%rbp)
	movsd	%xmm0, -56(%rbp)
	movq	-112(%rbp), %rdx
	movsd	-104(%rbp), %xmm1
	movq	-88(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN4line4distE5point
	movq	%xmm0, %rax
	leaq	-64(%rbp), %rdx
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	_ZN3vct2toEd
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3vct8to_pointEv
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rdx
	movq	%rbx, %xmm1
	leaq	-112(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointplES_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rdx
	movq	%rbx, %xmm1
	movq	-88(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN4line8point_inE5point
	testb	%al, %al
	je	.L64
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4line4normEv
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -64(%rbp)
	movsd	%xmm0, -56(%rbp)
	movq	-112(%rbp), %rdx
	movsd	-104(%rbp), %xmm1
	movq	-88(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN4line4distE5point
	movq	%xmm0, %rax
	leaq	-64(%rbp), %rdx
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	_ZN3vct2toEd
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3vct8to_pointEv
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rdx
	movq	%rbx, %xmm1
	leaq	-112(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointplES_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	jmp	.L65
.L64:
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4line4normEv
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -80(%rbp)
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3vct3revEv
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -64(%rbp)
	movsd	%xmm0, -56(%rbp)
	movq	-112(%rbp), %rdx
	movsd	-104(%rbp), %xmm1
	movq	-88(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN4line4distE5point
	movq	%xmm0, %rax
	leaq	-64(%rbp), %rdx
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	_ZN3vct2toEd
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3vct8to_pointEv
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rdx
	movq	%rbx, %xmm1
	leaq	-112(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointplES_
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
.L65:
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%rax, %rcx
	movq	%rdx, %rbx
	movq	%rsi, %rax
	movq	%rbx, %xmm1
	movq	-24(%rbp), %rbx
	subq	%fs:40, %rbx
	je	.L66
	call	__stack_chk_fail@PLT
.L66:
	movq	%rax, %xmm0
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8445:
	.size	_ZN4line7projectE5point, .-_ZN4line7projectE5point
	.section	.text._ZN4line4distE5point,"axG",@progbits,_ZN4line4distE5point,comdat
	.align 2
	.weak	_ZN4line4distE5point
	.type	_ZN4line4distE5point, @function
_ZN4line4distE5point:
.LFB8446:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm1
	movsd	-32(%rbp), %xmm0
	mulsd	%xmm0, %xmm1
	movq	-8(%rbp), %rax
	movsd	8(%rax), %xmm2
	movsd	-24(%rbp), %xmm0
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	movq	-8(%rbp), %rax
	movsd	16(%rax), %xmm0
	addsd	%xmm0, %xmm1
	movsd	%xmm1, -16(%rbp)
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm1
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm0
	mulsd	%xmm0, %xmm1
	movq	-8(%rbp), %rax
	movsd	8(%rax), %xmm2
	movq	-8(%rbp), %rax
	movsd	8(%rax), %xmm0
	mulsd	%xmm2, %xmm0
	movapd	%xmm1, %xmm3
	addsd	%xmm0, %xmm3
	movq	%xmm3, %rax
	movq	%rax, %xmm0
	call	sqrt@PLT
	movsd	-16(%rbp), %xmm1
	divsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8446:
	.size	_ZN4line4distE5point, .-_ZN4line4distE5point
	.section	.text._ZN4line8point_inE5point,"axG",@progbits,_ZN4line8point_inE5point,comdat
	.align 2
	.weak	_ZN4line8point_inE5point
	.type	_ZN4line8point_inE5point, @function
_ZN4line8point_inE5point:
.LFB8451:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movsd	-32(%rbp), %xmm1
	movq	-8(%rbp), %rax
	movsd	(%rax), %xmm0
	mulsd	%xmm0, %xmm1
	movsd	-24(%rbp), %xmm2
	movq	-8(%rbp), %rax
	movsd	8(%rax), %xmm0
	mulsd	%xmm2, %xmm0
	addsd	%xmm0, %xmm1
	movq	-8(%rbp), %rax
	movsd	16(%rax), %xmm0
	addsd	%xmm1, %xmm0
	pxor	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	setnp	%al
	movl	$0, %edx
	pxor	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	cmovne	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8451:
	.size	_ZN4line8point_inE5point, .-_ZN4line8point_inE5point
	.text
	.globl	_ZrsRSiR4line
	.type	_ZrsRSiR4line, @function
_ZrsRSiR4line:
.LFB8452:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSirsERd@PLT
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSirsERd@PLT
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSirsERd@PLT
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8452:
	.size	_ZrsRSiR4line, .-_ZrsRSiR4line
	.section	.text._ZN6circleC2E5pointd,"axG",@progbits,_ZN6circleC5E5pointd,comdat
	.align 2
	.weak	_ZN6circleC2E5pointd
	.type	_ZN6circleC2E5pointd, @function
_ZN6circleC2E5pointd:
.LFB8470:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	%rax, -32(%rbp)
	movq	%rdx, -24(%rbp)
	movsd	%xmm2, -16(%rbp)
	movq	-8(%rbp), %rcx
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-8(%rbp), %rax
	movsd	-16(%rbp), %xmm0
	movsd	%xmm0, 16(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8470:
	.size	_ZN6circleC2E5pointd, .-_ZN6circleC2E5pointd
	.weak	_ZN6circleC1E5pointd
	.set	_ZN6circleC1E5pointd,_ZN6circleC2E5pointd
	.section	.text._ZN6circlemlE4line,"axG",@progbits,_ZN6circlemlE4line,comdat
	.align 2
	.weak	_ZN6circlemlE4line
	.type	_ZN6circlemlE4line, @function
_ZN6circlemlE4line:
.LFB8535:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$216, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -200(%rbp)
	movq	%rsi, -208(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-208(%rbp), %rax
	movq	(%rax), %rdx
	movsd	8(%rax), %xmm1
	movq	%rdx, %xmm0
	leaq	16(%rbp), %rdi
	call	_ZN4line4distE5point
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	_Z3roud
	movq	%xmm0, %rax
	movq	-208(%rbp), %rdx
	movsd	16(%rdx), %xmm0
	movq	%rax, %xmm6
	comisd	%xmm0, %xmm6
	seta	%al
	testb	%al, %al
	je	.L75
	movsd	_ZL4nan2(%rip), %xmm0
	movq	_ZL4nan2(%rip), %rdx
	leaq	-64(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movsd	_ZL4nan2(%rip), %xmm0
	movq	_ZL4nan2(%rip), %rdx
	leaq	-48(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	leaq	-48(%rbp), %rdx
	leaq	-64(%rbp), %rcx
	movq	-200(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairI5pointS0_EC1IS0_S0_Lb1EEEOT_OT0_
	jmp	.L74
.L75:
	movq	-208(%rbp), %rax
	movq	(%rax), %rdx
	movsd	8(%rax), %xmm1
	movq	%rdx, %xmm0
	leaq	16(%rbp), %rdi
	call	_ZN4line4distE5point
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	_ZSt3absd
	movq	%xmm0, %rbx
	movq	-208(%rbp), %rax
	movsd	16(%rax), %xmm1
	movq	-208(%rbp), %rax
	movsd	16(%rax), %xmm0
	mulsd	%xmm0, %xmm1
	movsd	%xmm1, -216(%rbp)
	movq	-208(%rbp), %rax
	movq	(%rax), %rdx
	movsd	8(%rax), %xmm1
	movq	%rdx, %xmm0
	leaq	16(%rbp), %rdi
	call	_ZN4line4distE5point
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	_ZSt3absd
	movsd	%xmm0, -224(%rbp)
	movq	-208(%rbp), %rax
	movq	(%rax), %rdx
	movsd	8(%rax), %xmm1
	movq	%rdx, %xmm0
	leaq	16(%rbp), %rdi
	call	_ZN4line4distE5point
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	_ZSt3absd
	mulsd	-224(%rbp), %xmm0
	movsd	-216(%rbp), %xmm1
	subsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, %xmm0
	call	sqrt@PLT
	movq	%xmm0, %rax
	movq	%rbx, %xmm1
	movq	%rax, %xmm0
	call	atan2@PLT
	movq	%xmm0, %rbx
	movq	-208(%rbp), %rax
	movq	(%rax), %rdx
	movsd	8(%rax), %xmm1
	movq	%rdx, %xmm0
	leaq	16(%rbp), %rdi
	call	_ZN4line7projectE5point
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-208(%rbp), %rcx
	movsd	(%rcx), %xmm1
	movsd	8(%rcx), %xmm0
	movq	%rax, %r8
	movq	%rdx, %r9
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%r8, %rdx
	movq	%rdi, %xmm4
	leaq	-192(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm3
	movq	%rdx, %xmm0
	movapd	%xmm4, %xmm1
	movq	%rax, %rdi
	call	_ZN3vctC1E5pointS0_
	leaq	-192(%rbp), %rax
	movq	%rbx, %xmm0
	movq	%rax, %rdi
	call	_ZN3vctplEd
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -176(%rbp)
	movsd	%xmm0, -168(%rbp)
	movq	-208(%rbp), %rax
	movq	16(%rax), %rdx
	leaq	-176(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN3vct2toEd
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -160(%rbp)
	movsd	%xmm0, -152(%rbp)
	leaq	-160(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3vct8to_pointEv
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -144(%rbp)
	movsd	%xmm0, -136(%rbp)
	movq	-208(%rbp), %rax
	movq	(%rax), %rdx
	movsd	8(%rax), %xmm1
	leaq	-144(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointplES_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -128(%rbp)
	movsd	%xmm0, -120(%rbp)
	movq	-208(%rbp), %rax
	movq	(%rax), %rdx
	movsd	8(%rax), %xmm1
	movq	%rdx, %xmm0
	leaq	16(%rbp), %rdi
	call	_ZN4line4distE5point
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	_ZSt3absd
	movq	%xmm0, %rbx
	movq	-208(%rbp), %rax
	movsd	16(%rax), %xmm1
	movq	-208(%rbp), %rax
	movsd	16(%rax), %xmm0
	mulsd	%xmm0, %xmm1
	movsd	%xmm1, -216(%rbp)
	movq	-208(%rbp), %rax
	movq	(%rax), %rdx
	movsd	8(%rax), %xmm1
	movq	%rdx, %xmm0
	leaq	16(%rbp), %rdi
	call	_ZN4line4distE5point
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	_ZSt3absd
	movsd	%xmm0, -224(%rbp)
	movq	-208(%rbp), %rax
	movq	(%rax), %rdx
	movsd	8(%rax), %xmm1
	movq	%rdx, %xmm0
	leaq	16(%rbp), %rdi
	call	_ZN4line4distE5point
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	call	_ZSt3absd
	mulsd	-224(%rbp), %xmm0
	movsd	-216(%rbp), %xmm1
	subsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, %xmm0
	call	sqrt@PLT
	movq	%xmm0, %rax
	movq	%rbx, %xmm1
	movq	%rax, %xmm0
	call	atan2@PLT
	movq	%xmm0, %rax
	movq	.LC5(%rip), %xmm0
	movq	%rax, %xmm5
	xorpd	%xmm0, %xmm5
	movq	%xmm5, %rbx
	movq	-208(%rbp), %rax
	movq	(%rax), %rdx
	movsd	8(%rax), %xmm1
	movq	%rdx, %xmm0
	leaq	16(%rbp), %rdi
	call	_ZN4line7projectE5point
	movq	%xmm0, %rcx
	movapd	%xmm1, %xmm0
	movl	$0, %eax
	movl	$0, %edx
	movq	%rcx, %rax
	movq	%xmm0, %rdx
	movq	-208(%rbp), %rcx
	movsd	(%rcx), %xmm1
	movsd	8(%rcx), %xmm0
	movq	%rax, %r8
	movq	%rdx, %r9
	movq	%rax, %rsi
	movq	%rdx, %rdi
	movq	%r8, %rdx
	movq	%rdi, %xmm4
	leaq	-112(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm3
	movq	%rdx, %xmm0
	movapd	%xmm4, %xmm1
	movq	%rax, %rdi
	call	_ZN3vctC1E5pointS0_
	leaq	-112(%rbp), %rax
	movq	%rbx, %xmm0
	movq	%rax, %rdi
	call	_ZN3vctplEd
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -96(%rbp)
	movsd	%xmm0, -88(%rbp)
	movq	-208(%rbp), %rax
	movq	16(%rax), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN3vct2toEd
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -80(%rbp)
	movsd	%xmm0, -72(%rbp)
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN3vct8to_pointEv
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -64(%rbp)
	movsd	%xmm0, -56(%rbp)
	movq	-208(%rbp), %rax
	movq	(%rax), %rdx
	movsd	8(%rax), %xmm1
	leaq	-64(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointplES_
	movq	%xmm0, %rax
	movapd	%xmm1, %xmm0
	movq	%rax, -48(%rbp)
	movsd	%xmm0, -40(%rbp)
	leaq	-48(%rbp), %rdx
	leaq	-128(%rbp), %rcx
	movq	-200(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt4pairI5pointS0_EC1IS0_S0_Lb1EEEOT_OT0_
.L74:
	movq	-24(%rbp), %rax
	subq	%fs:40, %rax
	je	.L77
	call	__stack_chk_fail@PLT
.L77:
	movq	-200(%rbp), %rax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8535:
	.size	_ZN6circlemlE4line, .-_ZN6circlemlE4line
	.text
	.globl	_ZrsRSiR6circle
	.type	_ZrsRSiR6circle, @function
_ZrsRSiR6circle:
.LFB8536:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZrsRSiR5point
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSirsERd@PLT
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8536:
	.size	_ZrsRSiR6circle, .-_ZrsRSiR6circle
	.globl	_ZrsRSiR8triangle
	.type	_ZrsRSiR8triangle, @function
_ZrsRSiR8triangle:
.LFB8545:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZrsRSiR5point
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	$16, %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZrsRSiR5point
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZrsRSiR5point
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8545:
	.size	_ZrsRSiR8triangle, .-_ZrsRSiR8triangle
	.section	.rodata
.LC7:
	.string	"\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8546:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %edi
	call	_ZNSt8ios_base15sync_with_stdioEb@PLT
	movl	$0, %esi
	leaq	16+_ZSt3cin(%rip), %rdi
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE3tieEPSo@PLT
	movl	$0, %esi
	leaq	8+_ZSt4cout(%rip), %rdi
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE3tieEPSo@PLT
	leaq	-48(%rbp), %rax
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointC1Edd
	movq	-48(%rbp), %rdx
	movsd	-40(%rbp), %xmm1
	leaq	-112(%rbp), %rax
	pxor	%xmm2, %xmm2
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN6circleC1E5pointd
	leaq	-80(%rbp), %rax
	pxor	%xmm2, %xmm2
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	movq	%rax, %rdi
	call	_ZN4lineC1Eddd
	leaq	-112(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZrsRSiR6circle
	movq	%rax, %rdx
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZrsRSiR4line
	leaq	-48(%rbp), %rax
	leaq	-112(%rbp), %rdx
	subq	$8, %rsp
	pushq	-64(%rbp)
	pushq	-72(%rbp)
	pushq	-80(%rbp)
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN6circlemlE4line
	addq	$32, %rsp
	movq	-48(%rbp), %rax
	movq	%rax, %xmm0
	call	_ZSt5isnand
	testb	%al, %al
	je	.L83
	movl	$0, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	movl	$0, %eax
	jmp	.L86
.L83:
	movq	-32(%rbp), %rdx
	movsd	-24(%rbp), %xmm1
	leaq	-48(%rbp), %rax
	movq	%rdx, %xmm0
	movq	%rax, %rdi
	call	_ZN5pointeqES_
	testb	%al, %al
	je	.L85
	movl	$1, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC7(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-48(%rbp), %rax
	movsd	-40(%rbp), %xmm1
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	_ZlsRSo5point
	movl	$0, %eax
	jmp	.L86
.L85:
	movl	$2, %esi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC7(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-48(%rbp), %rax
	movsd	-40(%rbp), %xmm1
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	_ZlsRSo5point
	leaq	.LC7(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	movsd	-24(%rbp), %xmm1
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	_ZlsRSo5point
	movl	$0, %eax
.L86:
	movq	-8(%rbp), %rcx
	subq	%fs:40, %rcx
	je	.L87
	call	__stack_chk_fail@PLT
.L87:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8546:
	.size	main, .-main
	.section	.text._ZNSt4pairI5pointS0_EC2IS0_S0_Lb1EEEOT_OT0_,"axG",@progbits,_ZNSt4pairI5pointS0_EC5IS0_S0_Lb1EEEOT_OT0_,comdat
	.align 2
	.weak	_ZNSt4pairI5pointS0_EC2IS0_S0_Lb1EEEOT_OT0_
	.type	_ZNSt4pairI5pointS0_EC2IS0_S0_Lb1EEEOT_OT0_, @function
_ZNSt4pairI5pointS0_EC2IS0_S0_Lb1EEEOT_OT0_:
.LFB9121:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardI5pointEOT_RNSt16remove_referenceIS1_E4typeE
	movq	-8(%rbp), %rcx
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt7forwardI5pointEOT_RNSt16remove_referenceIS1_E4typeE
	movq	-8(%rbp), %rcx
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, 16(%rcx)
	movq	%rdx, 24(%rcx)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9121:
	.size	_ZNSt4pairI5pointS0_EC2IS0_S0_Lb1EEEOT_OT0_, .-_ZNSt4pairI5pointS0_EC2IS0_S0_Lb1EEEOT_OT0_
	.weak	_ZNSt4pairI5pointS0_EC1IS0_S0_Lb1EEEOT_OT0_
	.set	_ZNSt4pairI5pointS0_EC1IS0_S0_Lb1EEEOT_OT0_,_ZNSt4pairI5pointS0_EC2IS0_S0_Lb1EEEOT_OT0_
	.section	.text._ZSt7forwardI5pointEOT_RNSt16remove_referenceIS1_E4typeE,"axG",@progbits,_ZSt7forwardI5pointEOT_RNSt16remove_referenceIS1_E4typeE,comdat
	.weak	_ZSt7forwardI5pointEOT_RNSt16remove_referenceIS1_E4typeE
	.type	_ZSt7forwardI5pointEOT_RNSt16remove_referenceIS1_E4typeE, @function
_ZSt7forwardI5pointEOT_RNSt16remove_referenceIS1_E4typeE:
.LFB9407:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9407:
	.size	_ZSt7forwardI5pointEOT_RNSt16remove_referenceIS1_E4typeE, .-_ZSt7forwardI5pointEOT_RNSt16remove_referenceIS1_E4typeE
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB9913:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L93
	cmpl	$65535, -8(%rbp)
	jne	.L93
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
	pxor	%xmm0, %xmm0
	divsd	%xmm0, %xmm0
	movsd	%xmm0, _ZL4nan2(%rip)
.L93:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9913:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__Z3roud, @function
_GLOBAL__sub_I__Z3roud:
.LFB9934:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9934:
	.size	_GLOBAL__sub_I__Z3roud, .-_GLOBAL__sub_I__Z3roud
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z3roud
	.section	.rodata
	.align 16
.LC0:
	.long	-1
	.long	2147483647
	.long	0
	.long	0
	.align 8
.LC1:
	.long	536870912
	.long	1107468383
	.align 8
.LC2:
	.long	-1571644103
	.long	1066524486
	.align 8
.LC3:
	.long	442745336
	.long	1078765020
	.align 16
.LC5:
	.long	0
	.long	-2147483648
	.long	0
	.long	0
	.align 8
.LC6:
	.long	0
	.long	1072693248
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 10.2.0"
	.section	.note.GNU-stack,"",@progbits
