.syntax		unified
.cpu		cortex-m3
.fpu		softvfp
.thumb

.section	.text.vector_table

.global		_vector_table
_vector_table:
	.word	_estack	// Initial SP value
	.word	_start	// Reset

.section	.text.start

.thumb_func
_start:
	bl 	main
	b	.
