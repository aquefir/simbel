/*****************************************************************************\
 *                                  Simbel.                                  *
 *                                                                           *
 *                        Copyright (C) 2022 Aquefir.                        *
 *                  Released under Artisan Software Licence                  *
\*****************************************************************************/

#ifndef INC_API__SIMBEL_H
#define INC_API__SIMBEL_H

#include <uni/decl.h>
#include <uni/types/int.h>

#define SIMBEL_TOKEN_DATA(T) \
	((u8*)((T) & ~(ptri)1))
#define SIMBEL_TOKEN_TYPE(T) \
	((T) & 1 ? SIMBEL_SUBST : SIMBEL_LITERAL)

enum
{
	SIMBEL_LITERAL = 0,
	SIMBEL_SUBST = 1
};

enum
{
	SIMBEL_RETVAL_OK = 0
};

typedef ptri simbel_token_t;
typedef u32 simbel_retval_t;

simbel_retval_t simbel_lex_sz( u8 *, ptri * );
simbel_retval_t simbel_lex( u8 *, simbel_token_t * );

#endif /* INC_API__SIMBEL_H */
